// https://tora-k.com/2019/08/27/socket-c/#toc2

#include <sock_client.h>

static void	sock_connect(int fd_sock, t_addr * addr_to) {
	int	status = connect(fd_sock, addr_to, sizeof(t_addr));	//ソケット, アドレスポインタ, アドレスサイズ
	Debug::print("sc1\tconnect\tstatus", status);
	if (status < 0) { //エラー処理
		Print::error("Error connect: ", errno);
		exit(1);	//異常終了
	}
	Print::error("connected");
}

static void	sock_send(int fd_sock) {
	char	msg[] = MSG_HELLO;	//送信データ格納用
	char	i_str[4];
	size_t	len_msg = strlen(msg);
	int i = 0;
	while (i++ < NUM_CYCLE) {
		send(fd_sock, msg, len_msg, 0);	//送信
		std::cout << msg << std::endl;
		sprintf(i_str, "%d", i);
		send(fd_sock, i_str, 4, 0);	//送信
		std::cout << i << std::endl;
	}
}

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
