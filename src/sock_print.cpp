#include <sock_print.hpp>

void	Print::error(const char *msg, int errnum) {
	if (errnum) {
		std::cerr << TEXT_RED << msg << std::strerror(errnum) \
			<< TEXT_RESET << std::endl;	//標準出力
	}
	else {
		std::clog << TEXT_GREEN << msg \
			<< TEXT_RESET << std::endl;	//標準出力
	}
}
