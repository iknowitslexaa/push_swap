/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneiva-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:46:18 by aneiva-d          #+#    #+#             */
/*   Updated: 2024/08/21 16:43:44 by aneiva-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//this function's purpuse is to initialize he a stack.
//In order to do that, it begins by checking if there's
//any syntax errors, then uses a function similar to atoi
//that is able to create a long intenger. After that, it
//checkes if there's any intenger overflow or duplicates.
//after that it appends the node (number) to the stack;

void	create_list_a(argc, argv)
{
	long n;
	int i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		n = atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (dup_error(*a, (int)n))
			free_errors(a);
		append_node(a, (int)n);
		i++;
	}
}

static void append_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	//we check if the stack is empty before we append
	//a new node.
	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	//if the stack was empty, the head of the stack will
	//be the new node. Since it's the first, the prev pointer
	//needs to be set to  NULL.
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	//if it isn't empty tho, we will need to find which
	//node is the last one (find_last);
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}
