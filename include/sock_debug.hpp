/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sock_debug.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/09/18 05:04:00 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCK_DEBUG_HPP
# define SOCK_DEBUG_HPP

# include <iostream>
# include <iomanip>
# include <sock_common.h>

class Debug
{
private:
	Debug();
	~Debug();
public:
	static void	print(const char *name, int val);
	static void	print(const char *name, struct sockaddr_in *val);
};

#endif
