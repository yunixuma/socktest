// https://www.ibm.com/docs/ja/i/7.2?topic=designs-using-poll-instead-select

#include <noblk.h>

static bool	noblk_comm_recv(struct pollfd *pd, char buffer[], ssize_t *len) {
	/*****************************************************/
	/* Receive data on this connection until the         */
	/* recv fails with EWOULDBLOCK. If any other         */
	/* failure occurs, we will close the                 */
	/* connection.                                       */
	/*****************************************************/
	*len = recv(pd->fd, buffer, BUFFER_SIZE, 0);

	if (*len < 0)
	{
		if (errno != EWOULDBLOCK)
		{
			perror("  recv() failed");
			return (true);
		}
		else
			perror("  recv() EWOULDBLOCK");
	}

	/*****************************************************/
	/* Check to see if the connection has been           */
	/* closed by the client                              */
	/*****************************************************/
	if (*len == 0)
	{
		printf("  Connection closed by the client\n");
		return (true);
	}

	/*****************************************************/
	/* Data was received                                 */
	/*****************************************************/
	if (*len > 0)
		printf("  fd\t%d\t%zd bytes received\n", pd->fd, *len);
	return (false);
}

bool	noblk_comm(struct pollfd *pd) {
	char	buffer[BUFFER_SIZE];
	bool	flag_close;
	ssize_t	len;

	while (true) {
		flag_close = noblk_comm_recv(pd, buffer, &len);
		if (len <= 0)
			return (flag_close);

		/*****************************************************/
		/* Echo the data back to the client                  */
		/*****************************************************/
		len = send(pd->fd, buffer, len, 0);
		if (len < 0) {
			perror("  send() failed");
			return (true);
		}

	}
}
