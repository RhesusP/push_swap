/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:55:39 by cbernot           #+#    #+#             */
/*   Updated: 2023/01/02 09:35:16 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

/**
 * @brief Checks if a string contains only digits (or '-').
 * 
 * @param s 
 * @return 0 if there is no error or 1 if a non-digit char is detected.
 */
int	ft_arg_nbr_err(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' && s[i + 1] == '\0')
		return (1);
	while (s[i] != '\0')
	{
		if (!((s[i] >= 48 && s[i] <= 57) || s[i] == 45))
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief Checks if the element given as parameter have a duplicate in the stack 
 * given in parameter.
 * 
 * @param stack 
 * @param elmt 
 * @return 0 if there is no duplicate or 1 if there is one.
 */
static int	ft_elmt_is_duplicate(t_stack **stack, t_stack *elmt)
{
	t_stack	*current;

	if (!*stack)
		return (0);
	current = *stack;
	while (current && current != elmt)
	{
		if (current->content == elmt->content)
			return (1);
		current = current->next;
	}
	return (0);
}

/**
 * @brief Checks if the stack givien as parameter contains duplicate elements.
 * 
 * @param stack 
 * @return 0 if there is no duplicate or 1 if there is one.
 */
int	ft_stack_duplicate_err(t_stack **stack)
{
	t_stack	*current;

	if (!*stack)
		return (0);
	current = *stack;
	while (current)
	{
		if (ft_elmt_is_duplicate(stack, current))
			return (1);
		current = current->next;
	}
	return (0);
}

/**
 * @brief Calculates the length of the number given as parameter.
 * 
 * @param nbr 
 * @return The length of the number.
 */
static int	ft_get_neg_int_len(int nbr)
{
	int	len_nbr;

	len_nbr = 0;
	while (nbr < 0)
	{
		nbr /= 10;
		len_nbr++;
	}
	return (len_nbr + 1);
}

/**
 * @brief Checks for integer underflow and overflow in a string representation.
 * 
 * @param str The string containing a number (in ascii).
 * @return 1 if the representating number is the limits of an integer. Else 0.
 */
int	ft_int_limit_error(char *str)
{
	int	len_str;
	int	len_nbr;
	int	nbr;

	len_str = ft_strlen(str);
	nbr = ft_atoi(str);
	len_nbr = 0;
	if (nbr <= 0)
		len_nbr = ft_get_neg_int_len(nbr);
	else
	{
		while (nbr > 0)
		{
			nbr /= 10;
			len_nbr++;
		}
	}
	if (len_nbr != len_str)
		return (1);
	return (0);
}
