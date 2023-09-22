// https://www.ibm.com/docs/ja/i/7.2?topic=designs-using-poll-instead-select

#include <noblk.h>

int	noblk_bind(int fd_sock) {
	struct sockaddr_in6	addr;
	/*************************************************************/
	/* Bind the socket                                           */
	/*************************************************************/
	memset(&addr, 0, sizeof(addr));
	addr.sin6_family      = AF_INET6;
	memcpy(&addr.sin6_addr, &in6addr_any, sizeof(in6addr_any));
	addr.sin6_port        = htons(SERVER_PORT);
	int	ret_code = bind(fd_sock,
						(struct sockaddr *)&addr, sizeof(addr));
	return (ret_code);
}
