// https://www.ibm.com/docs/ja/i/7.2?topic=designs-using-poll-instead-select

#include <noblk.h>

int	noblk_socket(void) {
	/*************************************************************/
	/* Create an AF_INET6 stream socket to receive incoming      */
	/* connections on                                            */
	/*************************************************************/
	int	fd_sock = socket(AF_INET6, SOCK_STREAM, 0);
	return (fd_sock);
}
