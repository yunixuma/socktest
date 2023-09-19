/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sock_print.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/09/19 15:55:04 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCK_PRINT_HPP
# define SOCK_PRINT_HPP

# include <iostream>	//標準入出力
# include <cerrno>	//errnoに利用
# include <cstring>	//strerror()に利用
# include "ft.h"

class Print
{
private:
	Print();
	~Print();
public:
	static void	error(const char *msg, int errnum = errno);
};

#endif
