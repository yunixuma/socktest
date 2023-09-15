/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sock_common.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/09/15 17:50:42 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCK_COMMON_H
# define SOCK_COMMON_H

# include <iostream> //標準入出力
# include <sys/socket.h> //アドレスドメイン
# include <sys/types.h> //ソケットタイプ
# include <arpa/inet.h> //バイトオーダの変換に利用
# include <unistd.h> //close()に利用
# include <string> //string型
# include <sstream> //stringstream型
# include <stdio.h> //sprintf()に利用
# include "ft.h"

# define NUM_INVALID	-1
# define LENGTH_MSG		12
# define IP_LOCAL		"127.0.0.1"
# define MSG_HELLO		"._Hello_World!_"

typedef struct sockaddr		t_addr;
typedef struct sockaddr_in	t_addrin;

int	main(int argc, char *argv[]);
int	ft_stoi(char *arg);
int	sock_init(t_addrin *addr, int port_num);

#endif
