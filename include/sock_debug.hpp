/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sock_debug.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/09/19 15:01:29 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCK_DEBUG_HPP
# define SOCK_DEBUG_HPP

# include <arpa/inet.h>	//バイトオーダの変換に利用
# include <netinet/in.h>	//sockaddr_in型, in_addr型に利用
# include <sys/socket.h>	//アドレスドメイン

# include <iostream>	//標準入出力
// # include <iomanip>	//std::setw()に利用
// # include "sock_common.h"
# include "ft.h"

typedef struct sockaddr_in	t_addrin;

class Debug
{
private:
	Debug();
	~Debug();
public:
	static void	print(const char *name, int val);
	static void	print(const char *name, t_addrin *val);
};

#endif
