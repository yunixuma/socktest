// https://www.ibm.com/docs/ja/i/7.2?topic=designs-using-poll-instead-select

#include <noblk.h>

int noblk_sequential(struct pollfd *fds, int *n_fds, int fd_sock) {
	int	flag = 0x0;
	/***********************************************************/
	/* One or more descriptors are readable.  Need to          */
	/* determine which ones they are.                          */
	/***********************************************************/
	int	current_size = *n_fds;
	for (int i = 0; i < current_size; i++) {
		/*********************************************************/
		/* Loop through to find the descriptors that returned    */
		/* POLLIN and determine whether it's the listening       */
		/* or the active connection.                             */
		/*********************************************************/
		if(fds[i].revents == 0)
			continue;

		/*********************************************************/
		/* If revents is not POLLIN, it's an unexpected result,  */
		/* log and end the server.                               */
		/*********************************************************/
		if(fds[i].revents != POLLIN) {
			printf("  Error! revents = %d\n", fds[i].revents);
			return (flag | FLAG_END);
		}
		if (fds[i].fd == fd_sock) {
			/*******************************************************/
			/* Listening descriptor is readable.                   */
			/*******************************************************/
			printf("  Listening socket is readable\n");
			flag |= noblk_accept(fds, n_fds, fd_sock) * FLAG_END;
		}

		/*********************************************************/
		/* This is not the listening socket, therefore an        */
		/* existing connection must be readable                  */
		/*********************************************************/

		else {
			printf("  Descriptor %d is readable\n", fds[i].fd);
			// flag_close = false;

			/*******************************************************/
			/* Receive all incoming data on this socket            */
			/* before we loop back and call poll again.            */
			/*******************************************************/
			flag |= noblk_comm(&fds[i]) * FLAG_CLOSE;

			/*******************************************************/
			/* If the flag_close flag was turned on, we need       */
			/* to clean up this active connection. This            */
			/* clean up process includes removing the              */
			/* descriptor.                                         */
			/*******************************************************/
			if (flag & FLAG_CLOSE) {
				close(fds[i].fd);
				fds[i].fd = NUM_INVALID;
				flag &= ~FLAG_CLOSE;
				flag |= FLAG_COMPRESS;
			}

		}  /* End of existing connection is readable             */
	} /* End of loop through pollable descriptors              */
	return (flag);
}
