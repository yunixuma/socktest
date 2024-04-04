// Cited from https://qiita.com/gu-chi/items/1e2ba4e19902f9e39b5e
//  on 2024-04-05

#ifndef SERVER_HPP
# define SERVER_HPP

# include <unistd.h>
# include <fcntl.h>
# include <sys/socket.h>
# include <arpa/inet.h>

# include <cstring>
# include <cstdlib>
# include <cstdio>
# include <iostream>

# define RECV_BUF_SIZE 32

class Server {
	private:
		int			socketFd_;
		const int	maxPending_;

	public:
		explicit Server(unsigned short port);
		~Server();

		void	startServer();
};

#endif  // SERVER_HPP
