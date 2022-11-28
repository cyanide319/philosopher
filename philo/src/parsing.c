/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:52:11 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/11/24 14:46:06 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	error_quit(int code, t_rules *rules)
{
	if (code == 1)
		printf("Bad input.\n");
	if (code == 2)
		printf("4 args + 1 optional.\n");
	if (code == 3)
	{
		free (rules->philo);
		printf("Problem occured with philos maloc.\n");
	}
	if (code == 4)
	{
		free (rules->philo);
		printf("Problem occured with mutex creation.\n");
	}
	write (2, "Error\n", 6);
	exit (0);
}

t_bool	check_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

t_bool	check_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 4)
			return (false);
		i++;
	}
	return (true);
}

t_bool	check_range(long input)
{
	if (input < 1)
		return (false);
	return (true);
}

void	check_errors(t_rules *rules, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (check_digits(argv[i]) == false
			|| check_len(argv[i]) == false
			|| check_range(ft_atol(argv[i])) == false)
			error_quit(1, rules);
		i++;
	}
	init_rules(rules, argc, argv);
}
