// https://tora-k.com/2019/08/27/socket-c/#toc2

#include <sock_common.h>

static int	sock_init_fd(void) {
	//ソケットの生成
	int fd_sock = socket(AF_INET, SOCK_STREAM, 0); //アドレスドメイン, ソケットタイプ, プロトコル
	if (fd_sock < 0) { //エラー処理
		Print::error("Error socket: ", errno);
		exit(1); //異常終了
	}
	Debug::print("si2\tfd_sock", fd_sock);

	return (fd_sock);
}

static void	sock_init_addr(t_addrin *addr, int port_num) {
	//アドレスの生成
	memset(addr, 0, sizeof(t_addrin)); //memsetで初期化
	addr->sin_family = AF_INET; //アドレスファミリ(ipv4)
	addr->sin_addr.s_addr = inet_addr(IP_LOCAL); //IPアドレス,inet_addr()関数はアドレスの翻訳
	addr->sin_port = htons(port_num); //ポート番号,htons()関数は16bitホストバイトオーダーをネットワークバイトオーダーに変換
	Debug::print("si4\taddr", addr);
}

int	sock_init(t_addrin *addr, int port_num) {
	Debug::print("si0	addr", addr);

	//ソケットの生成
	int fd_sock = sock_init_fd();

	//アドレスの生成
	sock_init_addr(addr, port_num);

	return (fd_sock);
}
