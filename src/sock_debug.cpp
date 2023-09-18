#include <sock_debug.hpp>

void	Debug::print(const char *name, int val) {
	std::clog << name << ":\t" << val << std::endl;
}

void	Debug::print(const char *name, t_addrin *val) {
	std::clog << name << ":\t" \
		<< "<" << val->sin_family << ">\t" << "[" \
		<< inet_ntoa(val->sin_addr) \
		<< "\t:" << val->sin_port << "]" \
		<< std::endl;
}
