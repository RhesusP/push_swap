/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:10:01 by cbernot           #+#    #+#             */
/*   Updated: 2023/01/02 09:38:58 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

/**
 * @brief Checks if a stack is sorted.
 * 
 * @param stack The stack to check.
 * @return 1 if it is sorted. 0 if not.
 */
int	ft_stack_is_sorted(t_stack **stack)
{
	t_stack	*current;
	int		prev_value;

	if (!*stack)
		return (1);
	current = *stack;
	prev_value = current->content;
	while (current)
	{
		if (current->content < prev_value)
			return (0);
		prev_value = current->content;
		current = current->next;
	}
	return (1);
}

/**
 * @brief Initialize (malloc) a stack with a string array given as parameter.
 * 
 * @param argc String array size.
 * @param argv String array.
 * @param is_reorganize Used to know if argv what reorganized.
 * @return t_stack** A stack filled with all the elements of the string array or 
 * NULL if there was a problem during memory allocation.
 */
t_stack	**ft_initialize_stack(int argc, char **argv, int is_reorganize)
{
	int		i;
	t_stack	**res;
	t_stack	*elmt;

	i = 0;
	res = malloc(sizeof(t_stack *));
	if (!res)
		return (0);
	while (++i < argc)
	{
		if (ft_arg_nbr_err(argv[i]) || ft_int_limit_error(argv[i]))
		{
			ft_free(&res, &argv, argc, is_reorganize);
			return (0);
		}
		ft_stack_push(res, ft_create_stack_elmt(ft_atoi(argv[i])));
	}
	if (ft_stack_duplicate_err(res))
	{
		ft_free(&res, &argv, argc, is_reorganize);
		return (0);
	}
	return (res);
}

/**
 * @brief Returns the smallest element bigger than the number given as parameter.
 * 
 * @param stack The stack where to find the element.
 * @param limit The lower limit.
 * @return t_stack* The smallest element bigger than the limit.
 */
t_stack	*ft_get_min(t_stack **stack, long limit)
{
	t_stack	*current;
	t_stack	*min_elmt;
	int		min_found;

	if (!*stack)
		return (0);
	current = *stack;
	min_found = 2147483647;
	min_elmt = *stack;
	while (current)
	{
		if (current->content > limit && current->content <= min_found)
		{
			min_found = current->content;
			min_elmt = current;
		}
		current = current->next;
	}
	return (min_elmt);
}

/**
 * @brief Gives an increasing index in range [0 ; size - 1] to each element 
 * of the stack given in parameter.
 * 
 * @param stack The stack to simplify.
 * @param size The size of the stack.
 */
void	ft_give_index(t_stack **stack, int size)
{
	int		i;
	long	min_found;
	t_stack	*min_elmt;

	min_found = -2147483649;
	i = 0;
	while (i < size)
	{
		min_elmt = ft_get_min(stack, min_found);
		min_elmt->index = i;
		min_found = min_elmt->content;
		i++;
	}
}

/**
 * @brief Frees the memory allocated for the elements given as parameters.
 * 
 * @param stack Address of the stack to free.
 * @param argv Address of the strings array to free.
 * @param argc argv size.
 * @param is_reorganize Boolean used to know if argv was reorganised or not.
 */
void	ft_free(t_stack ***stack, char ***argv, int argc, int is_reorganize)
{
	t_stack	*current;
	t_stack	*next;
	int		i;

	if (*stack)
	{
		current = *(*stack);
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
		free(*stack);
	}
	i = 0;
	if (is_reorganize && argv)
	{
		while (i < argc)
		{
			free((*argv)[i]);
			i++;
		}
		free(*argv);
	}
}
