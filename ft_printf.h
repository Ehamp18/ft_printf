/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:52:49 by elhampto          #+#    #+#             */
/*   Updated: 2019/05/02 22:59:38 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H__
# define __FT_PRINTF_H__

# include "libft/libft.h"
# include <stdarg.h>

/*
** Create a macro for error messages

# define ERR_MESS 
*/

/*
** typedef	conver_check
** {
** 		
** };			conver
*/

int				ft_printf(const char *format, ...);
int				con_d(int d);

#endif
