/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:46:06 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/11/28 14:40:11 by tbeaudoi         ###   ########.fr       */
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

typedef struct s_forks{
	int				left;
	int				right;
}	t_forks;

typedef struct s_philo{
	pthread_t		philo_td;
	int				id;
	t_forks			forks;
	struct t_rules	*rules;
}	t_philo;

typedef struct s_rules{
	int				nb_philo;
	int				tm_to_die;
	int				tm_to_eat;
	int				tm_to_sleep;
	int				nb_of_eat;
	time_t			start_time;
	pthread_mutex_t	*mute_forks;
	pthread_mutex_t	mute_write;
	t_philo			*philo;
}	t_rules;

typedef enum e_bool{
	false,
	true,
}t_bool;

//utils
long	ft_atol(const char *str);
t_bool	ft_isdigit(int c);

//parsing
void	check_errors(t_rules *rules, int argc, char **argv);
void	error_quit(int code, t_rules *rules);
t_bool	check_digits(char *str);
t_bool	check_len(char *str);

//initialize
void	init_rules(t_rules *rules, int argc, char **argv);
void	init_philo(t_rules *rules);
time_t	init_time(void);

#endif
