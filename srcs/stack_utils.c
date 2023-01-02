/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:49:24 by cbernot           #+#    #+#             */
/*   Updated: 2023/01/02 09:35:48 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

/**
 * @brief Returns the last element of a stack.
 * 
 * @param stack 
 * @return t_stack* The last element.
 */
t_stack	*ft_stack_get_last(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	if (stack == 0)
		return (0);
	while (current->next)
		current = current->next;
	return (current);
}

/**
 * @brief Returns the last to one element of a stack.
 * 
 * @param stack 
 * @return t_stack* The last to one element.
 */
t_stack	*ft_stack_get_last_to_one(t_stack **stack)
{
	t_stack	*current;
	t_stack	*previous;

	current = *stack;
	if (stack == 0)
		return (0);
	while (current->next)
	{
		previous = current;
		current = current->next;
	}
	return (previous);
}

/**
 * @brief Creates (malloc) an element of the stack.
 * 
 * @param nb Content of the element.
 * @return t_stack* The element created or NULL if there was a problem 
 * during memory allocation.
 */
t_stack	*ft_create_stack_elmt(int nb)
{
	t_stack	*res;

	res = malloc(sizeof(t_stack));
	if (!res)
		return (0);
	res->content = nb;
	res->index = 0;
	res->next = 0;
	return (res);
}

/**
 * @brief Add an element at the end of the stack.
 * 
 * @param stack Where to add the element.
 * @param new The element to add.
 */
void	ft_stack_push(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = ft_stack_get_last(stack);
	last->next = new;
	return ;
}

/**
 * @brief Returns the element with the greatest value in the stack.
 * 
 * @param stack 
 * @return t_stack* The element with the greatest value or NULL if 
 * the stack is empty.
 */
t_stack	*ft_get_max(t_stack **stack)
{
	t_stack	*current;
	t_stack	*max_elmt;

	if (!*stack)
		return (0);
	current = *stack;
	max_elmt = *stack;
	while (current)
	{
		if (current->index > max_elmt->index)
			max_elmt = current;
		current = current->next;
	}
	return (max_elmt);
}
