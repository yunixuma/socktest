// https://www.ibm.com/docs/ja/i/7.2?topic=designs-using-poll-instead-select

#include <noblk.h>

int	noblk_exit_error(char *msg, int fd_sock) {
	perror(msg);
	if (fd_sock >= 0)
		close(fd_sock);
	dprintf(STDERR_FILENO, "errno\t:%d", errno);
	if (errno)
		exit(errno);
	exit(-1);
	return (errno);
}
