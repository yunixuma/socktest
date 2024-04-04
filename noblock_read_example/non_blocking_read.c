// Cited from https://qiita.com/gu-chi/items/1fbc8c05b1ef5a3ac5aa
//  on 2024-04-05

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int	main(void) {
	// ファイルディスクリプタをノンブロッキングに設定
	int	flags = 0;

	if ((flags = fcntl(STDIN_FILENO, F_GETFL)) == -1) {
		perror("fcntl");
		exit(EXIT_FAILURE);
	}
	flags |= O_NONBLOCK;
	if (fcntl(STDIN_FILENO, F_SETFL, flags) == -1) {
		perror("fcntl");
		exit(EXIT_FAILURE);
	}
	while (1) {
		sleep(3);

		// char	buffer[1024] = {0};
		char	buffer[4] = {0};
		ssize_t	bytes_read = 0;

		errno = 0;

		// ノンブロッキングなファイルディスクリプタからデータを読み取る
		bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer));

		if (bytes_read == -1) {
			perror("read");
			if (errno == EAGAIN || errno == EWOULDBLOCK) {
				continue ;
			} else {
				exit(EXIT_FAILURE);
			}
		} else if (bytes_read > 0) {
			// データが読み取られた場合
			printf("Read %zd bytes: %s", bytes_read, buffer);
		} else {
			// データがない場合
			printf("No data available.\n");
			break ;
		}
	}
	return (0);
}
