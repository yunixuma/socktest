/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sock_client.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/09/18 19:08:30 by ykosaka          ###   ########.fr       */
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

#endif
