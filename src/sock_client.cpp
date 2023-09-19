// https://tora-k.com/2019/08/27/socket-c/#toc2

#include <sock_client.h>

int	main(int argc, char *argv[]) {
	int	port_num = sock_setport(argc, argv);	//ポート番号

	t_addrin	addr_to;	//接続先の情報用の構造体(ipv4)
	int			fd_sock;	//ソケット番号
	fd_sock = sock_init(&addr_to, port_num);	//ソケット, アドレスの生成
	sock_connect(fd_sock, (t_addr *)&addr_to);	//ソケット接続要求
	sock_send(fd_sock);	//データ送信

	//データ受信
	//recv(fd_sock, msg, len_msg, 0);	//受信
	//std::cout << msg << std::endl;	//標準出力

	//ソケットクローズ
	close(fd_sock);
	return 0;
}
