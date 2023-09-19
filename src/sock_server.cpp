// https://tora-k.com/2019/08/27/socket-c/#toc3

#include <sock_server.h>

int	main(int argc, char *argv[]) {
	int	port_num = sock_setport(argc, argv);	//ポート番号

	t_addrin	addr_from;	//接続先の情報用の構造体(ipv4)
	int			fd_sock;	//ソケット番号
	fd_sock = sock_init(&addr_from, port_num);	//ソケット, アドレスの生成
	sock_bind(fd_sock, (t_addr *)&addr_from);	//ソケット登録
	sock_listen(fd_sock);	//受信待ち

	// fcntl(fd_sock, F_SETFL, O_NONBLOCK);

	int	fd_conn = sock_accept(fd_sock);	//接続待ち
	sock_recv(fd_conn);	//データ受信

	//送信
	//send(fd_conn, msg, len_msg, 0);	//送信
	//std::cout << msg << std::endl;	//標準出力

	//ソケットクローズ
	close(fd_conn);
	close(fd_sock);
	return 0;
}
