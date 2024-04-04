// Cited from https://qiita.com/gu-chi/items/1e2ba4e19902f9e39b5e
//  on 2024-04-05

#ifndef CLIENT_HPP
# define CLIENT_HPP

# include <unistd.h>
# include <sys/socket.h>
# include <arpa/inet.h>

# include <string>
# include <cstring>
# include <cstdlib>
# include <cstdio>
# include <iostream>

# define RCVBUFSIZE 32

class Client {
	private:
		int					socket_;
		struct sockaddr_in	serverAddr_;

	public:
		Client(const std::string& serverIP, unsigned short serverPort);
		~Client();

		void	connectToServer();
		void	sendMessage(const std::string& message);
		void	receiveMessage();
};

#endif  // CLIENT_HPP
