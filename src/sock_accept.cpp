// https://tora-k.com/2019/08/27/socket-c/#toc3

#include <sock_server.h>

int	sock_accept(int fd_sock) {
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
