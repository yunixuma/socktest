// https://tora-k.com/2019/08/27/socket-c/#toc2

#include <sock_client.h>

int	main(int argc, char *argv[]) {
	int	port_num = NUM_INVALID;
	if (argc > 1)
		port_num = ft_stoi(argv[1]);
	if (port_num == NUM_INVALID)
		port_num = PORT_NUM;

	t_addrin	addr_to; //接続先の情報用の構造体(ipv4)
	int			sockfd; //ソケット番号

	//ソケット, アドレスの生成
	sockfd = sock_init(&addr_to, port_num);

	//ソケット接続要求
	int	conn = connect(sockfd, (t_addr *)&addr_to, sizeof(t_addrin)); //ソケット, アドレスポインタ, アドレスサイズ
	std::clog << conn << std::endl; 
	if (conn < 0) { //エラー処理
		std::cerr << "Error connect:" << std::strerror(errno); //標準出力
		exit(1); //異常終了
	}
	std::clog << "\033[33mconnected" << std::endl; //標準出力

	//データ送信
	char	msg[] = "._Hello_World!_"; //送信データ格納用
	char	i_str[4];
	size_t	len = strlen(msg);
	int i = 0;
	while (i++ < NUM_CYCLE) {
		send(sockfd, msg, len, 0); //送信
		std::cout << msg << std::endl;
		sprintf(i_str, "%d", i);
		send(sockfd, i_str, 4, 0); //送信
		std::cout << i << std::endl;
	}

	//データ受信
	char	r_str[len]; //受信データ格納用
	recv(sockfd, r_str, len, 0); //受信
	std::cout << r_str << std::endl; //標準出力

	//ソケットクローズ
	close(sockfd);

	return 0;
}
