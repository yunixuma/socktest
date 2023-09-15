// https://tora-k.com/2019/08/27/socket-c/#toc3

#include <sock_server.h>

int	main(int argc, char *argv[]) {
	int	port_num = NUM_INVALID;
	if (argc > 1)
		port_num = ft_stoi(argv[1]);
	if (port_num == NUM_INVALID)
		port_num = PORT_NUM;

	t_addrin	addr_from; //接続先の情報用の構造体(ipv4)
	int			sockfd; //ソケット番号

	//ソケット, アドレスの生成
	sockfd = sock_init(&addr_from, port_num);

	//受信待ち
	if (listen(sockfd, SOMAXCONN) < 0) { //ソケット, キューの最大長 //エラー処理
		std::cerr << COLOR_RED << "Error listen: " << std::strerror(errno); //標準出力
		close(sockfd); //ソケットクローズ
		exit(1); //異常終了
	}

	//接続待ち
	struct sockaddr_in addr_to; //接続相手のソケットアドレス
	socklen_t len = sizeof(t_addrin); //接続相手のアドレスサイズ
	int conn;
	conn = accept(sockfd, (t_addr *)&addr_to, &len); //接続待ちソケット, 接続相手のソケットアドレスポインタ, 接続相手のアドレスサイズ

	if (conn < 0) { //エラー処理
		std::cerr << COLOR_RED << "Error accept: " << std::strerror(errno); //標準出力
		exit(1); //異常終了
	}
	std::clog << COLOR_GREEN << "connected" << std::endl; //標準出力

	//受信
	size_t len_msg = LENGTH_MSG;
	char msg[len_msg]; //受信用データ格納用
	int	i = 0;
	while (i++ < NUM_CYCLE) {
		recv(conn, msg, len_msg, 0); //受信
		std::cout << msg << std::endl; //標準出力
	}

	//送信
	send(conn, msg, len_msg, 0); //送信
	std::cout << msg << std::endl; //標準出力

	//ソケットクローズ
	close(conn);
	close(sockfd);

	return 0;
}
