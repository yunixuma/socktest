#if MODE == 0
# include <sock_client.h>
#else
# include <sock_server.h>
#endif

int	sock_setport(int argc, char *argv[]) {
	int	port_num = NUM_INVALID;
	if (argc > 1)
		port_num = ft_stoi(argv[1]);
	if (port_num == NUM_INVALID)
		port_num = PORT_NUM;
	Debug::print("ssp3\tport_num", port_num);
	return (port_num);
}
