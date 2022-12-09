/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:46:06 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/12/09 18:15:36 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include<stdio.h>
# include<stdlib.h>
# include<pthread.h>
# include<time.h>
# include<sys/time.h>
# include<unistd.h>
# include<limits.h>

# define RF "took right fork"
# define LF "took left fork"
# define EAT "is eating"
# define SLP "is sleeping"
# define THK "is thinking"
# define DTH "is dead"

typedef enum e_bool{
	false,
	true,
}t_bool;

typedef struct s_forks{
	int				left;
	int				right;
}	t_forks;

typedef struct s_philo{
	pthread_t		p_t;
	int				id;
	int				nb_eat;
	time_t			last_eat;
	t_forks			forks;
	struct s_rules	*rules;
}	t_philo;

typedef struct s_rules{
	int				nb_t;
	int				nb_philo;
	int				tm_to_die;
	int				tm_to_eat;
	int				tm_to_sleep;
	int				nb_of_eat;
	t_bool			dth_flag;
	pthread_t		death_watch[200];
	time_t			start_time;
	pthread_mutex_t	mute_forks[200];
	pthread_mutex_t	mute_write;
	pthread_mutex_t	mute_death;
	t_philo			philo[200];
}	t_rules;

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
void	init_wait_time(t_rules *rules, int wait);

//routine
void	*routine(void *arg);
void	reaping(t_rules *rules);
t_bool	feasting(t_rules *rules);
t_bool	eat(t_rules *rules, int i);
t_bool	fucking_sleep(t_rules *rules, int i);
t_bool	think(t_rules *rules, int i);
t_bool	print_output(t_rules *rules, int i, char *str);
t_bool	am_i_dead(t_rules *rules, int i);

//The End
void	close_threads(t_rules *rules);

#endif
