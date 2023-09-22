// https://www.ibm.com/docs/ja/i/7.2?topic=designs-using-poll-instead-select

#include <noblk.h>

int	noblk_listen(int fd_sock) {
	/*************************************************************/
	/* Set the listen back log                                   */
	/*************************************************************/
	int	ret_code = listen(fd_sock, 32);
	return (ret_code);
}
