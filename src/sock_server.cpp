// https://tora-k.com/2019/08/27/socket-c/#toc3

#include <sock_server.h>

static int	sock_setport(int argc, char *argv[]) {
	int	port_num = NUM_INVALID;
	if (argc > 1)
		port_num = ft_stoi(argv[1]);
	if (port_num == NUM_INVALID)
		port_num = PORT_NUM;
	return (port_num);
}

static void	sock_bind(int fd_sock, t_addr *addr_from) {
	//ソケット, アドレスポインタ, アドレスサイズ
	if(bind(fd_sock, addr_from, sizeof(t_addr)) < 0){	//エラー処理
		std::cout << "Error bind:" << std::strerror(errno);	//標準出力
		exit(1);	//異常終了
	}
}

static void	sock_listen(int fd_sock) {
	//受信待ち
	int	status_listen = listen(fd_sock, SOMAXCONN);
	if (status_listen < 0) {	//ソケット, キューの最大長 //エラー処理
		std::cerr << COLOR_RED << "Error listen: " \
			<< std::strerror(errno) << std::endl;	//標準エラー出力
		close(fd_sock);	//ソケットクローズ
		exit(1);	//異常終了
	}
}

static int	sock_accept(int fd_sock) {
	t_addrin addr_to;	//接続相手のソケットアドレス
	socklen_t len_addr = sizeof(t_addrin);	//接続相手のアドレスサイズ
	Debug::print("sa1\taddr_to", &addr_to);
	Debug::print("sa41\tlen_addr", len_addr);
	//接続待ちソケット, 接続相手のソケットアドレスポインタ, 接続相手のアドレスサイズ
	int	fd_conn = accept(fd_sock, (sockaddr *)&addr_to, &len_addr);
	Debug::print("sm41\tfd_conn", fd_conn);
	if (fd_conn < 0) {	//エラー処理
		std::cerr << COLOR_RED << "Error accept: " << std::strerror(errno) << std::endl;	//標準エラー出力
		exit(1);	//異常終了
	}
	std::clog << COLOR_GREEN << "connected" << std::endl;	//標準エラー出力
	return (fd_conn);
}

static void	sock_recv(int fd_conn) {
	//受信
	size_t len_msg = LENGTH_MSG;
	char msg[len_msg];	//受信用データ格納用
	int	i = 0;
	while (i++ < NUM_CYCLE) {
		recv(fd_conn, msg, len_msg, 0);	//受信
		std::cout << msg << std::endl;	//標準出力
	}
}

int	main(int argc, char *argv[]) {
	int	port_num = sock_setport(argc, argv);	//ポート番号

	t_addrin	addr_from;	//接続先の情報用の構造体(ipv4)
	int			fd_sock;	//ソケット番号
	fd_sock = sock_init(&addr_from, port_num);	//ソケット, アドレスの生成
	sock_bind(fd_sock, (t_addr *)&addr_from);	//ソケット登録
	sock_listen(fd_sock);	//受信待ち
	int	fd_conn = sock_accept(fd_sock);	//接続待ち

	//受信
	sock_recv(fd_conn);

	//送信
	//send(fd_conn, msg, len_msg, 0);	//送信
	//std::cout << msg << std::endl;	//標準出力

	//ソケットクローズ
	close(fd_conn);
	close(fd_sock);
	return 0;
}
