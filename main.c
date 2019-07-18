/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:15:42 by elhampto          #+#    #+#             */
/*   Updated: 2019/07/17 21:35:08 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inclu/ft_printf.h"
#include <stdio.h>

int				main(void)
{
	ft_printf("%s\n", "342");
	ft_printf("%.5s\n", "342");
	// ft_printf("%5s\n", "342");
	// ft_printf("%04s\n", "342");
	// ft_printf("%-5s\n", "342");
	// ft_printf("%#s\n", "342");
	// ft_printf("% s\n", "342");
	// ft_printf("%ls\n", "342");
	// ft_printf("%lls\n", "342");
	// ft_printf("%hs\n", "342");
	// ft_printf("%hhs\n", "342");
	system("leaks test");
	return (0);
}
 