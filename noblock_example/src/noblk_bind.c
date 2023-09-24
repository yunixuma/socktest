// https://www.ibm.com/docs/ja/i/7.2?topic=designs-using-poll-instead-select

#include <noblk.h>

int	noblk_bind(int fd_sock) {
//	struct sockaddr_in6	addr;
	struct sockaddr_in	addr;
	/*************************************************************/
	/* Bind the socket                                           */
	/*************************************************************/
	memset(&addr, 0, sizeof(addr));
//	addr.sin6_family = AF_INET6;
	addr.sin_family = AF_INET;
//	memcpy(&addr.sin6_addr, &in6addr_any, sizeof(in6addr_any));
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
//	addr.sin6_port = htons(SERVER_PORT);
	addr.sin_port = htons(SERVER_PORT);

	int	ret_code = bind(fd_sock,
						(struct sockaddr *)&addr, sizeof(addr));
	return (ret_code);
}
