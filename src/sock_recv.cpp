// https://tora-k.com/2019/08/27/socket-c/#toc3

#include <sock_server.h>

void	sock_recv(int fd_conn) {
	//受信
	size_t len_msg = LENGTH_MSG;
	char msg[len_msg];	//受信用データ格納用
	int	i = 0;
	while (i++ < NUM_CYCLE) {
		recv(fd_conn, msg, len_msg, 0);	//受信
		std::cout << msg << std::endl;	//標準出力
	}
}
