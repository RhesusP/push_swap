/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:20:07 by cbernot           #+#    #+#             */
/*   Updated: 2023/01/02 09:35:41 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

/**
 * @brief Swap the first 2 elements at the top of a stack.
 * 
 * @param stack The stack to swap.
 * @param id The name of the stack (to display the correct operation).
 */
void	ft_swap(t_stack **stack, char id)
{
	t_stack	*first;
	t_stack	*second;

	if (id == 'a' || id == 'b')
		ft_printf("s%c\n", id);
	if (*stack && (*stack)->next)
	{
		first = *stack;
		second = (*stack)->next;
		first->next = second->next;
		second->next = first;
		*stack = second;
		return ;
	}
}

/**
 * @brief Do a swap on the two stacks given as parameters.
 * 
 * @param stack_a 
 * @param stack_b 
 */
void	ft_swapswap(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("ss\n");
	ft_swap(stack_a, 0);
	ft_swap(stack_b, 0);
}

/**
 * @brief  Take the first element at the top of a stack and put it at 
 * the top of the other stack.
 * 
 * @param stack_a The first stack.
 * @param stack_b The second stack.
 * @param id The name of the stack (here 'a' or 'b'). If 'a', it will 
 * push on stack_a. If 'b', it will push on stack_b.
 */
void	ft_push(t_stack **stack_a, t_stack **stack_b, char id)
{
	t_stack	*first_b;
	t_stack	*first_a;

	if (id == 'b')
	{
		ft_printf("pb\n");
		if (*stack_a)
		{
			first_a = *stack_a;
			*stack_a = first_a->next;
			first_a->next = *stack_b;
			*stack_b = first_a;
		}
	}
	else if (id == 'a')
	{
		ft_printf("pa\n");
		if (*stack_b)
		{
			first_b = *stack_b;
			*stack_b = first_b->next;
			first_b->next = *stack_a;
			*stack_a = first_b;
		}
	}
}

/**
 * @brief Shift up all elements of the stack given in parameter by 1 
 * (the first element becomes the last one).
 * 
 * @param stack 
 * @param id The name of the stack (to display the correct operation).
 */
void	ft_rotate(t_stack **stack, char id)
{
	t_stack	*last;

	if (id == 'a' || id == 'b')
		ft_printf("r%c\n", id);
	if (!*stack)
		return ;
	last = ft_stack_get_last(stack);
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = 0;
}

/**
 * @brief Shift up all elements of the two stacks given as parameters by 1 
 * (the first element becomes the last one).
 * 
 * @param stack_a 
 * @param stack_b 
 */
void	ft_rotaterotate(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("rr\n");
	ft_rotate(stack_a, 0);
	ft_rotate(stack_b, 0);
}
