// https://www.ibm.com/docs/ja/i/7.2?topic=designs-using-poll-instead-select

#include <noblk.h>

void	noblk_init_pollfd(struct pollfd fds[], int fd_sock) {
	/*************************************************************/
	/* Initialize the pollfd structure                           */
	/*************************************************************/
	memset(fds, 0 , sizeof(struct pollfd) * FDS_POLL);

	/*************************************************************/
	/* Set up the initial listening socket                        */
	/*************************************************************/
	fds[0].fd = fd_sock;
	fds[0].events = POLLIN;
}
