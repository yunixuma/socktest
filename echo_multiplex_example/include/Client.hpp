// Cited from https://qiita.com/gu-chi/items/57d9ba6d6e797dfc8967
//  on 2024-04-05

#ifndef CLIENT_HPP
# define CLIENT_HPP

# include <unistd.h>
# include <fcntl.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <poll.h>

# include <string>
# include <cstring>
# include <cstdlib>
# include <cstdio>
# include <iostream>
# include <cerrno>

class Client {
	private:
		int					socketFd_;
		struct sockaddr_in	serverSocketAddress_;

	public:
		Client(const std::string& serverIP, unsigned short serverPort);
		~Client();

		void	connectToServer();
		ssize_t	sendMessage(const std::string& message);
		ssize_t	receiveMessage();
};

#endif  // CLIENT_HPP
