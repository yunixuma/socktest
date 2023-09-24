// https://www.ibm.com/docs/ja/i/7.2?topic=designs-using-poll-instead-select

#include <noblk.h>

void	noblk_compress_array(struct pollfd fds[], int *nfds) {
	/***********************************************************/
	/* If the flag_compress_array flag was turned on, we need  */
	/* to squeeze together the array and decrement the number  */
	/* of file descriptors. We do not need to move back the    */
	/* events and revents fields because the events will always*/
	/* be POLLIN in this case, and revents is output.          */
	/***********************************************************/
	for (int i = 0; i < *nfds; i++) {
		if (fds[i].fd == -1) {
			for(int j = i; j < *nfds; j++) {
				fds[j].fd = fds[j + 1].fd;
			}
			i--;
			(*nfds)--;
		}
	}
}
