/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:46:06 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/11/22 12:25:47 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include<stdio.h>
# include<stdlib.h>
# include<pthread.h>
# include<time.h>
# include<unistd.h>
# include<limits.h>

typedef struct s_philo{
	int	nb_philo;
	int	tm_to_die;
	int	tm_to_eat;
	int	tm_to_sleep;
	int	nb_of_eat;
}	t_philo;

typedef enum e_bool{
	false,
	true,
}t_bool;

//utils
int		ft_atoi(const char *str);
t_bool	ft_isdigit(int c);

//parsing
void	check_errors(t_philo *rules, int argc, char **argv);
void	error_quit(int code);
t_bool	check_digits(char *str);
t_bool	check_len(char *str);

#endif
