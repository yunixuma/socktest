/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sock_common.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/09/19 14:50:23 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCK_COMMON_H
# define SOCK_COMMON_H

# include <unistd.h>	//close()に利用
# include <stdlib.h>	//exit()に利用
# include <sys/socket.h>	//ソケットに利用
# include <sys/types.h> //ソケットタイプ

# include <cstring> //strlen()に利用
// # include <string>	//string型
# include <iostream>	//標準入出力
# include <cerrno>	//errnoに利用

# include "ft.h"
# include "sock_print.hpp"
# include "sock_debug.hpp"

# define NUM_INVALID	-1
# define LENGTH_MSG		12
# define IP_LOCAL		"127.0.0.1"

typedef struct sockaddr		t_addr;
typedef struct sockaddr_in	t_addrin;

int	main(int argc, char *argv[]);
int	ft_stoi(char *arg);
int	sock_setport(int argc, char *argv[]);
int	sock_init(t_addrin *addr, int port_num);

#endif
