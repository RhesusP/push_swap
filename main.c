/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:29:37 by cbernot           #+#    #+#             */
/*   Updated: 2023/01/02 09:07:57 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

char	**ft_normalize_argv(char **argv)
{
	char	**res;
	char	*str;

	str = ft_strjoin("lol ", argv[1]);
	if (!str)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	res = ft_split(str, ' ');
	free(str);
	if (!res)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (res);
}

int	ft_get_argv_len(char **argv)
{
	int	len;

	len = 0;
	while (argv[len])
		len++;
	return (len);
}

void	ft_handle_single_arg(int *argc, char ***argv, int *is_reorganize)
{
	*argv = ft_normalize_argv(*argv);
	*argc = ft_get_argv_len(*argv);
	*is_reorganize = 1;
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	int		is_reorganize;

	is_reorganize = 0;
	if (argc == 2)
	{
		ft_handle_single_arg(&argc, &argv, &is_reorganize);
		if (!argv)
			return (0);
	}
	stack_a = ft_initialize_stack(argc, argv, is_reorganize);
	stack_b = ft_initialize_stack(0, argv, is_reorganize);
	if (!stack_a || !stack_b)
	{
		ft_putstr_fd("Error\n", 2);
		ft_free(&stack_a, &argv, argc, is_reorganize);
		ft_free(&stack_b, &argv, argc, is_reorganize);
		return (0);
	}
	ft_sort(stack_a, stack_b, argc - 1);
	ft_free(&stack_a, &argv, argc, is_reorganize);
	ft_free(&stack_b, 0, 0, is_reorganize);
	return (0);
}
