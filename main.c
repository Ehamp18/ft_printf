/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by y elhampto        #+#    #+#             */
/*   Updated: 2019/05/16 18:15:37 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			main(void)
{
	printf("real d: %d aadaf\n", 999999999);
	printf("real i: %i aadaf\n", 999999999);
	printf("real c: %c aadaf\n", 'a');
	printf("real s: %s aadaf\n", "This is Interesting");
	printf("real x: %x aadaf\n", 15);
	ft_printf("mine d: %d aadaf\n", 999999999);
	ft_printf("mine i: %i aadaf\n", 999999999);
	ft_printf("mine c: %c aadaf\n", 'a');
	ft_printf("mine s: %s aadaf\n", "This is Interesting");
	return (0);
}
