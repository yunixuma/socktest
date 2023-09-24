// https://www.ibm.com/docs/ja/i/7.2?topic=designs-using-poll-instead-select

#include <noblk.h>

// int main(int argc, char *argv[])
int main(void) {
	int	on = 1;
	int	fd_sock = NUM_INVALID;
//   int	desc_ready;
	unsigned	flag = 0x0;

	struct pollfd fds[FDS_POLL];
	int	nfds = 1;

	fd_sock = noblk_socket();
	if (fd_sock < 0)
		noblk_exit_error("socket() failed", NUM_INVALID);
	if (noblk_setopt(fd_sock, &on) < 0)
		noblk_exit_error("setsockopt() failed", fd_sock);
	if (noblk_ioctl(fd_sock, &on) < 0)
		noblk_exit_error("ioctl() failed", fd_sock);
	if (noblk_bind(fd_sock))
		noblk_exit_error("bind() failed", fd_sock);
	if (noblk_listen(fd_sock) < 0)
		noblk_exit_error("listen() failed", fd_sock);
	printf("fds\t:[%p]\n", fds);
//	memset(fds, 0 , sizeof(fds));
	noblk_init_pollfd(fds, fd_sock);

	/*************************************************************/
	/* Loop waiting for incoming connects or for incoming data   */
	/* on any of the connected sockets.                          */
	/*************************************************************/
	while (!(flag)) { /* End of serving running.    */
		if (noblk_poll(fds, nfds) < 0)
			break ;
		flag = noblk_sequential(fds, &nfds, fd_sock, &on);
		if (flag & FLAG_COMPRESS)
			noblk_compress_array(fds, &nfds);
		flag &= FLAG_END;
	}

	printf("flag\t:%u\n", flag);
	noblk_clean(fds, nfds);
	return (flag - FLAG_END);
}
