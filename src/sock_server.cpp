// https://tora-k.com/2019/08/27/socket-c/#toc3

#include <sock_server.h>

static void	sock_bind(int fd_sock, t_addr *addr_from) {
	//ソケット, アドレスポインタ, アドレスサイズ
	int	status = bind(fd_sock, addr_from, sizeof(t_addr));
	Debug::print("sb1\tbind\tstatus", status);
	if (status < 0) {	//エラー処理
		Print::error("Error bind: ", errno);
		exit(1);	//異常終了
	}
}

static void	sock_listen(int fd_sock) {
	//受信待ち
	int	status = listen(fd_sock, SOMAXCONN);
	Debug::print("sl1\tlisten\tstatus", status);
	if (status < 0) {	//ソケット, キューの最大長 //エラー処理
		Print::error("Error listen: ", errno);
		close(fd_sock);	//ソケットクローズ
		exit(1);	//異常終了
	}
}

static int	sock_accept(int fd_sock) {
	t_addrin addr_to;	//接続相手のソケットアドレス
	socklen_t len_addr = sizeof(t_addrin);	//接続相手のアドレスサイズ
	Debug::print("sa1\taddr_to", &addr_to);
	Debug::print("sa1\tlen_addr", len_addr);
	//接続待ちソケット, 接続相手のソケットアドレスポインタ, 接続相手のアドレスサイズ
	int	fd_conn = accept(fd_sock, (sockaddr *)&addr_to, &len_addr);
	Debug::print("sa2\tfd_conn", fd_conn);
	if (fd_conn < 0) {	//エラー処理
		Print::error("Error accept: ", errno);
		close(fd_sock);	//ソケットクローズ
		exit(1);	//異常終了
	}
	Print::error("connected");
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
