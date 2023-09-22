// https://www.ibm.com/docs/ja/i/7.2?topic=designs-using-poll-instead-select

#include <noblk.h>

int	noblk_ioctl(int fd_sock, int *on) {
	/*************************************************************/
	/* Set socket to be nonblocking. All of the sockets for      */
	/* the incoming connections will also be nonblocking since   */
	/* they will inherit that state from the listening socket.   */
	/*************************************************************/
	int	ret_code = ioctl(fd_sock, FIONBIO, (char *)on);
	return (ret_code);
}
