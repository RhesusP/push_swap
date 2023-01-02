/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:08:31 by cbernot           #+#    #+#             */
/*   Updated: 2022/12/30 23:02:35 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

/**
 * @brief Shift down all elements of the stack given in parameter by 1 
 * (the last element becomes the first one).
 * 
 * @param stack 
 * @param id The name of the stack (to display the correct operation).
 */
void	ft_reverse_rotate(t_stack **stack, char id)
{
	t_stack	*last_to_one;
	t_stack	*last;

	if (id == 'a' || id == 'b')
		ft_printf("rr%c\n", id);
	if (!*stack)
		return ;
	last_to_one = ft_stack_get_last_to_one(stack);
	last = last_to_one->next;
	last->next = *stack;
	*stack = last;
	last_to_one->next = 0;
	return ;
}

/**
 * @brief Shift down all elements of the two stacks given as parameters by 1 
 * (the last element becomes the first one).
 * 
 * @param stack_a 
 * @param stack_b 
 */
void	ft_rr_rotate(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("rrr\n");
	ft_reverse_rotate(stack_a, 0);
	ft_reverse_rotate(stack_b, 0);
}
