// https://www.ibm.com/docs/ja/i/7.2?topic=designs-using-poll-instead-select

#include <noblk.h>

// int main(int argc, char *argv[])
void	noblk_clean(struct pollfd fds[], int nfds) {
	/*************************************************************/
	/* Clean up all of the sockets that are open                 */
	/*************************************************************/
	for (int i = 0; i < nfds; i++)
	{
		if(fds[i].fd >= 0)
			close(fds[i].fd);
	}
}
