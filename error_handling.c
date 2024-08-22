/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneiva-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:06:58 by aneiva-d          #+#    #+#             */
/*   Updated: 2024/08/22 12:51:13 by aneiva-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_input_error(int	argc, char **argv)
{
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		exit(1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	return (argv);
}
