/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 23:50:53 by cbernot           #+#    #+#             */
/*   Updated: 2023/01/02 09:46:57 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

/**
 * @brief Sub-sorting function used to sort the first 3 elements of the stack 
 * given as parameter.
 * 
 * @param stack_a 
 */
static void	ft_sort_three(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->content;
	second = (*stack)->next->content;
	third = (*stack)->next->next->content;
	if (first > second && second < third && first < third)
		ft_swap(stack, 'a');
	else if (first > second && second > third && first > third)
	{
		ft_swap(stack, 'a');
		ft_reverse_rotate(stack, 'a');
	}
	else if (first > second && second < third && first > third)
		ft_rotate(stack, 'a');
	else if (first < second && second > third && first < third)
	{
		ft_swap(stack, 'a');
		ft_rotate(stack, 'a');
	}
	else if (first < second && second > third && first > third)
		ft_reverse_rotate(stack, 'a');
}

/**
 * @brief Sub-sorting function used to sort the stack A by finding 
 * the minimums and sending 
 * them to the stack b.
 * 
 * @param stack_a Stack A (to sort)
 * @param stack_b Stack B
 * @param size Size of stack A
 */
static void	ft_sort_by_smallest(t_stack **stack_a, t_stack **stack_b, int size)
{
	while (size > 3)
	{
		while ((*stack_a)->index > ft_get_min(stack_a, -2147483649)->index)
			ft_rotate(stack_a, 'a');
		ft_push(stack_a, stack_b, 'b');
		size--;
	}
	ft_sort_three(stack_a);
	while (*stack_b)
		ft_push(stack_a, stack_b, 'a');
}

/**
 * @brief Sub-sorting function used to sort the stack A by finding the 
 * maximums and sending 
 * them to the stack b.
 * 
 * @param stack_a Stack A (to sort)
 * @param stack_b Stack B
 * @param size Size of stack A
 */
static void	ft_sort_by_greatest(t_stack **stack_a, t_stack **stack_b, int size)
{
	while (size > 3)
	{
		while ((*stack_a)->index < ft_get_max(stack_a)->index)
			ft_rotate(stack_a, 'a');
		ft_push(stack_a, stack_b, 'b');
		size--;
	}
	ft_sort_three(stack_a);
	while (*stack_b)
	{
		ft_push(stack_a, stack_b, 'a');
		ft_rotate(stack_a, 'a');
	}
}

/**
 * @brief Sub-sorting function used to check for the method with the 
 * least amount of movement to choose.
 * 
 * @param stack_a Stack A.
 * @param stack_b Stack B.
 * @param size Size of stack A.
 */
static void	ft_choose_shortest(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		index;
	t_stack	*current;

	current = *stack_a;
	index = 0;
	while (current->index < ft_get_max(stack_a)->index)
	{
		index++;
		current = current->next;
	}
	if (index < size / 2)
		ft_sort_by_greatest(stack_a, stack_b, size);
	else
		ft_sort_by_smallest(stack_a, stack_b, size);
}

/**
 * @brief Sorts stack A.
 * 
 * @param stack_a Stack A.
 * @param stack_b Stack B.
 * @param size Size of stack A.
 */
void	ft_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (ft_stack_is_sorted(stack_a))
		return ;
	ft_give_index(stack_a, size);
	if (size <= 5)
	{
		if (size == 2)
			ft_swap(stack_a, 'a');
		else if (size == 3)
			ft_sort_three(stack_a);
		else
			ft_choose_shortest(stack_a, stack_b, size);
	}
	else
		ft_radix_sort(stack_a, stack_b, size);
}
