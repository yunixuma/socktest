/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sock_client.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/09/19 16:18:58 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCK_CLIENT_H
# define SOCK_CLIENT_H

# include "sock_common.h"
# include <stdio.h> //sprintf()に利用
# include "sock_debug.hpp"

# define PORT_NUM	50000
# define NUM_CYCLE	20
# define MSG_HELLO	"._Hello_World!_"

void	sock_connect(int fd_sock, t_addr * addr_to);
void	sock_send(int fd_sock);

#endif
