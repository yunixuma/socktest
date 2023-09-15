// https://tora-k.com/2019/08/27/socket-c/#toc2

#include <sock_common.h>

int	sock_init(t_addrin *addr, int port_num) {
	//ソケットの生成
	int sockfd = socket(AF_INET, SOCK_STREAM, 0); //アドレスドメイン, ソケットタイプ, プロトコル
	if (sockfd < 0) { //エラー処理

		std::clog << "Error socket:" << std::strerror(errno); //標準出力
		exit(1); //異常終了
	}

	//アドレスの生成
	memset(addr, 0, sizeof(t_addrin)); //memsetで初期化
	addr->sin_family = AF_INET; //アドレスファミリ(ipv4)
	addr->sin_port = htons(port_num); //ポート番号,htons()関数は16bitホストバイトオーダーをネットワークバイトオーダーに変換
	addr->sin_addr.s_addr = inet_addr(IP_LOCAL); //IPアドレス,inet_addr()関数はアドレスの翻訳

	return (sockfd);
}
