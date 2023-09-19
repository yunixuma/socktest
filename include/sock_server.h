/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sock_server.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/09/19 16:23:18 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCK_SERVER_H
# define SOCK_SERVER_H

# include "sock_common.h"
// # include <sys/ioctl.h>

# define PORT_NUM	50000
# define NUM_CYCLE	100

void	sock_bind(int fd_sock, t_addr *addr_from);
void	sock_listen(int fd_sock);
int		sock_accept(int fd_sock);
void	sock_recv(int fd_conn);

#endif
