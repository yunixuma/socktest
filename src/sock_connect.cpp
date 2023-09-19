// https://tora-k.com/2019/08/27/socket-c/#toc2

#include <sock_client.h>

void	sock_connect(int fd_sock, t_addr * addr_to) {
	int	status = connect(fd_sock, addr_to, sizeof(t_addr));	//ソケット, アドレスポインタ, アドレスサイズ
	Debug::print("sc1\tconnect\tstatus", status);
	if (status < 0) { //エラー処理
		Print::error("Error connect: ", errno);
		exit(1);	//異常終了
	}
	Print::error("connected");
}
