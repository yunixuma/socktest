// https://tora-k.com/2019/08/27/socket-c/#toc2

#include "sock_client.h"

int	main(int argc, char *argv[]) {
	int	port_num;
	std::stringstream	ss;

	if (argc < 2)
		port_num = PORT_NUM;
	ss << argv[1]
	ss >> port_num;
	std::cout << port_num << std::endl;

	//ソケットの生成
	int sockfd = socket(AF_INET, SOCK_STREAM, 0); //アドレスドメイン, ソケットタイプ, プロトコル
	if(sockfd < 0){ //エラー処理

		std::cout << "Error socket:" << std::strerror(errno); //標準出力
		exit(1); //異常終了
	}

	//アドレスの生成
	struct sockaddr_in addr; //接続先の情報用の構造体(ipv4)
	memset(&addr, 0, sizeof(struct sockaddr_in)); //memsetで初期化
	addr.sin_family = AF_INET; //アドレスファミリ(ipv4)
	addr.sin_port = htons(1234); //ポート番号,htons()関数は16bitホストバイトオーダーをネットワークバイトオーダーに変換
	addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //IPアドレス,inet_addr()関数はアドレスの翻訳

	//ソケット接続要求
	connect(sockfd, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)); //ソケット, アドレスポインタ, アドレスサイズ

	//データ送信
	char s_str[] = "HelloWorld!"; //送信データ格納用
	send(sockfd, s_str, 12, 0); //送信
	std::cout << s_str << std::endl;

	//データ受信
	char r_str[12]; //受信データ格納用
	recv(sockfd, r_str, 12, 0); //受信
	std::cout << r_str << std::endl; //標準出力

	//ソケットクローズ
	close(sockfd);

	return 0;
}
