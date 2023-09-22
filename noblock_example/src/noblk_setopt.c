// https://www.ibm.com/docs/ja/i/7.2?topic=designs-using-poll-instead-select

#include <noblk.h>

int	noblk_setopt(int fd_sock, int *on) {
	/*************************************************************/
	/* Allow socket descriptor to be reuseable                   */
	/*************************************************************/
	int	ret_code = setsockopt(fd_sock, SOL_SOCKET, SO_REUSEADDR, \
								  (char *)on, sizeof(*on));
	return (ret_code);
}
