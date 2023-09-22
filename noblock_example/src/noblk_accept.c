// https://www.ibm.com/docs/ja/i/7.2?topic=designs-using-poll-instead-select

#include <noblk.h>

bool	noblk_accept(struct pollfd fds[], int *n_fds, int fd_sock) {
	int	new_sd = 0;
	/*******************************************************/
	/* Accept all incoming connections that are            */
	/* queued up on the listening socket before we         */
	/* loop back and call poll again.                      */
	/*******************************************************/
	while (new_sd != -1)
	{
		/*****************************************************/
		/* Accept each incoming connection. If               */
		/* accept fails with EWOULDBLOCK, then we            */
		/* have accepted all of them. Any other              */
		/* failure on accept will cause us to end the        */
		/* server.                                           */
		/*****************************************************/
		new_sd = accept(fd_sock, NULL, NULL);
		if (new_sd < 0)
		{
			if (errno != EWOULDBLOCK)
			{
				perror("  accept() failed");
				return (true);
			}
			break ;
		}

		/*****************************************************/
		/* Add the new incoming connection to the            */
		/* pollfd structure                                  */
		/*****************************************************/
		printf("  New incoming connection - %d\n", new_sd);
		fds[*n_fds].fd = new_sd;
		fds[*n_fds].events = POLLIN;
		(*n_fds)++;

		/*****************************************************/
		/* Loop back up and accept another incoming          */
		/* connection                                        */
		/*****************************************************/
	}
	return (false);
}
