// https://tora-k.com/2019/08/27/socket-c/#toc2

#include <ft.h>
#include <sock_debug.hpp>

int	ft_stoi(char *arg) {
	int	num;
	std::stringstream	ss;

	ss << arg;
	ss >> num;
	Debug::print("stoi", num);
	if (!ss.fail() && ss.eof())
		return (num);
	else
		return (NUM_INVALID);
}
