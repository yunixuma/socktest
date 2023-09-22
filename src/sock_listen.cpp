// https://tora-k.com/2019/08/27/socket-c/#toc3

#include <sock_server.h>

void	sock_listen(int fd_sock) {
	//受信待ち
	int	ret_code = listen(fd_sock, SOMAXCONN);
	Debug::print("sl1\tlisten\tret_code", ret_code);
	if (ret_code < 0) {	//ソケット, キューの最大長 //エラー処理
		Print::error("Error listen: ", errno);
		close(fd_sock);	//ソケットクローズ
		exit(1);	//異常終了
	}
}
