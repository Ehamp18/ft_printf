/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:52:49 by elhampto          #+#    #+#             */
/*   Updated: 2019/05/08 13:45:00 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H__
# define __FT_PRINTF_H__

# include "libft/libft.h"
# include <stdarg.h>

typedef		void(*Charat)(char *conversions);

typedef	struct	g_conver_check[] =
{
	{'d', &con_d},
	{'i', &con_i},
	{'c', &con_c},
	{'s', &con_s}
	{'x', &con_x},
	{'X', &con_X},
	{'p', &con_p},
	{'o', &con_o},
	{'u', &con_u}
};

int				ft_printf(const char *format, ...);
int				con_d(int d);

#endif
