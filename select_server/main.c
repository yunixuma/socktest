// Cited from: https://github.com/josephcheel/42-Exam-Rank-06/blob/main/mini_serv.c
// on 2024-10-28
// Refer to https://qiita.com/Michinosuke/items/0778a5344bdf81488114
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>
#include <arpa/inet.h>

// global variables
typedef struct s_client {
	int		id;
	char	msg[65520];
}	t_client;
t_client	clients[1024];
char		buf_snd[65536];
char		buf_rcv[65520]; // some bytes for msg header
int			maxid = 0;
int			maxfd = 0;
fd_set		readfds;
fd_set		writefds;
fd_set		currentfds;

// flag to print
int mode = 0;

void	ft_putstr(int fd, char *str) {
	write(fd, str, strlen(str));
}

void	ft_err(char *msg, int mode) {
	if (!msg || !mode)
		ft_putstr(2, "Fatal error\n");
	else
		ft_putstr(2, msg);
	exit(1);
}

void	ft_print(char *msg, int mode) {
	if (msg && mode)
		ft_putstr(2, msg);
}

void	ft_broadcast(int sender)
{
	for (int fd = 0; fd <= maxfd; fd++) {
		if (FD_ISSET(fd, &writefds) && fd != sender) { // check if the fd is available in writefds
			if (send(fd, buf_snd, strlen(buf_snd), 0) == -1)
				ft_err("sending failed\n", mode);
			else
				ft_print("msg sent\n", mode);
		}
	}
}

int main(int argc, char *argv[]) {
	// verify arguments
	if (argc != 2)
		ft_err("Wrong number of arguments\n", 1);

	// initialize variables (this snippet is partly given by attachment)
	int sockfd, connfd;
	struct sockaddr_in servaddr, cliaddr;
	bzero(&servaddr, sizeof(servaddr));
	socklen_t addrlen = sizeof(cliaddr);

	// create and verify socket (this snippet is given by attachment)
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
		ft_err("socket failed\n", mode);
	else
		ft_print("socket created\n", mode);

	// initialize descripter set
	FD_ZERO(&currentfds); // clear currentfds
	FD_SET(sockfd, &currentfds); // add to currentfds
	maxfd = sockfd;

	// assign IP, PORT (this snippet is given by attachment)
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1]));
 
	// bind newly created socket to given IP and verification (this snippet is given by attachment)
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		ft_err("bind failed\n", mode);
	else
		ft_print("binding..\n", mode);
    // listen for backlog number of clients (this snippet is given by attachment)
	if (listen(sockfd, 100) != 0)
		ft_err("listen failed\n", mode);
	else
		ft_print("listening..\n", mode);

    // server loop
	while (1)
	{
		readfds = writefds = currentfds;
		if (select(maxfd + 1, &readfds, &writefds, NULL, NULL) == -1) // neither exceptfds nor timeout required
			ft_err("select failed\n", mode);
		else
			ft_print("-selected\033[2G", mode);
		for (int fd = 0; fd <= maxfd; fd++) { // check for all descripters in use
			if (FD_ISSET(fd, &readfds)) { // check if the fd is available in readfds
				if (fd == sockfd) { // check if new client is coming
					bzero(&cliaddr, sizeof(cliaddr)); // clear cliaddr
					connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &addrlen); // given by attachment
					if (connfd < 0)
						ft_err("accept failed\n", mode);
					else
						ft_print("accepted\n", mode);
					if (connfd > maxfd)
						maxfd = connfd;
					clients[connfd].id = maxid; // cluent id begins from 0
					maxid++;
					FD_SET(connfd, &currentfds); // add to currentfds
					sprintf(buf_snd, "server: client %d just arrived\n", clients[connfd].id); // the format given by subject
					ft_broadcast(connfd);
				} else { // check if the client is sending msg
					int ret = recv(fd, buf_rcv, 65520, 0); // receive msg from client
					if (ret <= 0) { // client disconnected
						if (ret == 0)
							ft_print("client disconnected\n", mode);
						else
							ft_print("recv failed\n", mode);
						sprintf(buf_snd, "server: client %d just left\n", clients[fd].id); // the format given by subject
						ft_broadcast(fd);
						FD_CLR(fd, &currentfds); // remove from currentfds
						close(fd);
					} else {
						for (int i = 0, j = strlen(clients[fd].msg); i < ret; i++, j++) { // split msg by '\n'
							clients[fd].msg[j] = buf_rcv[i];
							if (clients[fd].msg[j] == '\n') {
								clients[fd].msg[j] = '\0';
								sprintf(buf_snd, "client %d: %s\n", clients[fd].id, clients[fd].msg); // the format given by subject
								ft_broadcast(fd);
								bzero(clients[fd].msg, strlen(clients[fd].msg)); // clear the buffer
								j = -1;
							}
						}
					}
				}
			}
		}
	}
}
