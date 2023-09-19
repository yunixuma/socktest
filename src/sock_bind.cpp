// https://tora-k.com/2019/08/27/socket-c/#toc3

#include <sock_server.h>

void	sock_bind(int fd_sock, t_addr *addr_from) {
	//ソケット, アドレスポインタ, アドレスサイズ
	int	status = bind(fd_sock, addr_from, sizeof(t_addr));
	Debug::print("sb1\tbind\tstatus", status);
	if (status < 0) {	//エラー処理
		Print::error("Error bind: ", errno);
		exit(1);	//異常終了
	}
}
