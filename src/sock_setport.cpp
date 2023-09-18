#include <sock_common.h>

int	sock_setport(int argc, char *arg, int port_default) {
	int	port_num = NUM_INVALID;
	if (argc > 1)
		port_num = ft_stoi(argv[1]);
	if (port_num == NUM_INVALID)
		port_num = PORT_NUM;
	return (port_num);
}
