// https://www.ibm.com/docs/ja/i/7.2?topic=designs-using-poll-instead-select

#include <noblk.h>

int	noblk_poll(struct pollfd fds[], int nfds) {
	/*************************************************************/
	/* Initialize the timeout to 3 minutes. If no                */
	/* activity after 3 minutes this program will end.           */
	/* timeout value is based on milliseconds.                   */
	/*************************************************************/

	/***********************************************************/
	/* Call poll() and wait 3 minutes for it to complete.      */
	/***********************************************************/
	printf("Waiting on poll()...\n");
	int	ret_code = poll(fds, nfds, TIMEOUT);

	/***********************************************************/
	/* Check to see if the poll call failed.                   */
	/***********************************************************/
	if (ret_code < 0)
		perror("  poll() failed");

	/***********************************************************/
	/* Check to see if the 3 minute time out expired.          */
	/***********************************************************/
	if (ret_code == 0)
		printf("  poll() timed out.  End program.\n");

	return (ret_code);
}
