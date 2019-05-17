/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by y elhampto        #+#    #+#             */
/*   Updated: 2019/05/16 20:11:00 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			main(void)
{
	printf("real d: %d aadaf\n", 999999999);
	ft_printf("mine d: %d aadaf\n", 999999999);
	
	ft_putchar('\n');
	
	printf("real i: %i aadaf\n", 999999999);
	ft_printf("mine i: %i aadaf\n", 999999999);
	
	ft_putchar('\n');
	
	printf("real c: %c aadaf\n", 'a');
	ft_printf("mine c: %c aadaf\n", 'a');
	
	ft_putchar('\n');
	
	printf("real s: %s aadaf\n", "This is Interesting");
	ft_printf("mine s: %s aadaf\n", "This is Interesting");
	
	ft_putchar('\n');
	
	printf("real x: %x aadaf\n", 99999999);
	ft_printf("mine x: %x aadaf\n", 99999999);

	ft_putchar('\n');

	printf("real X: %X aadaf\n", 156);
	ft_printf("mine X: %X aadaf\n", 156);

	ft_putchar('\n');

	printf("real p: %p aadaf\n", "564");
	ft_printf("mine p: %p aadaf\n", "564");

	ft_putchar('\n');

	printf("real o: %o aadaf\n", 15);
	ft_printf("mine o: %o aadaf\n", 15);

	ft_putchar('\n');

	printf("real u: %u aadaf\n", 156);
	ft_printf("mine u: %u aadaf\n", 156);
	return (0);
}
