/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sock_common.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/09/07 18:33:34 by ykosaka          ###   ########.fr       */
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
# include <stdlib.h>

# define PORT_NUM		1234

typedef struct sigaction	t_sa;

#endif
