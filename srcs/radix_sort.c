/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:52:01 by cbernot           #+#    #+#             */
/*   Updated: 2023/01/02 09:35:29 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

/**
 * @brief Sort stack_a thanks to the radix method (digit by digit sort).
 * 
 * @param stack_a The stack to sort.
 * @param stack_b The secondary stack (used as "storage")
 * @param size The size of stack_a.
 */
void	ft_radix_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	unsigned int	i;
	unsigned int	bit;
	t_stack			*current;

	bit = 0;
	while (bit < 32)
	{
		i = 0;
		current = *stack_a;
		while (i < size)
		{
			if ((1 & (current->index >> bit)) == 0)
				ft_push(stack_a, stack_b, 'b');
			else
				ft_rotate(stack_a, 'a');
			current = *stack_a;
			i++;
		}
		current = *stack_b;
		while (*stack_b)
			ft_push(stack_a, stack_b, 'a');
		bit++;
		if (ft_stack_is_sorted(stack_a))
			return ;
	}
}
