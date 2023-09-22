/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noblk.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/09/22 13:48:07 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOBLK_H
# define NOBLK_H

# include <unistd.h>	//close()に利用
# include <stdio.h>
# include <stdlib.h>	//exit()に利用
# include <sys/ioctl.h>
# include <sys/socket.h>	//ソケットに利用
# include <sys/types.h> //ソケットタイプ
# include <sys/poll.h>
# include <sys/time.h>
# include <netinet/in.h>	//
// #include <cstring>
# include <errno.h>
# include <stdbool.h>
# include <string.h>	//string型

// # include <cstring> //strlen()に利用
// # include <iostream>	//標準入出力
// # include <cerrno>	//errnoに利用

// # include "ft.h"
// # include "sock_print.hpp"
// # include "sock_debug.hpp"

# define NUM_INVALID	-1
# define LENGTH_MSG		12
# define IP_LOCAL		"127.0.0.1"

#define SERVER_PORT		50000
#define FDS_POLL		200
#define BUFFER_SIZE		56
#define TIMEOUT			3 * 60 * 1000
#define FLAG_END		1
#define FLAG_COMPRESS	2
#define FLAG_CLOSE		4

int		main(void);
int		noblk_socket(void);
int		noblk_setopt(int fd_sock, int *on);
int		noblk_ioctl(int fd_sock, int *on);
int		noblk_bind(int fd_sock);
int		noblk_listen(int fd_sock);
void	noblk_init_pollfd(struct pollfd fds[], int fd_sock);
int		noblk_poll(struct pollfd fds[], int n_fds);
int		noblk_sequential(struct pollfd *fds, int *n_fds, int fd_sock);
bool	noblk_accept(struct pollfd fds[], int *n_fds, int fd_sock);
bool	noblk_comm(struct pollfd *pd);
void	noblk_compress_array(struct pollfd fds[], int *n_fds);
int		noblk_exit_error(char *msg, int fd_sock);
void	noblk_clean(struct pollfd fds[], int n_fds);

#endif
