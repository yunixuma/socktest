// https://tora-k.com/2019/08/27/socket-c/#toc2

#include <sock_client.h>

void	sock_send(int fd_sock) {
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
