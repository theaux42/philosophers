/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:43:01 by tbabou            #+#    #+#             */
/*   Updated: 2024/09/05 15:28:31 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_table	t_table;

typedef struct s_philo
{
	int					id;
	int					nb_meals;
	long long int		last_meal;
	long long int		start;
	int					is_eating;
	int					is_sleeping;
	int					is_thinking;
	t_table				*table;
	pthread_t			thread;
}						t_philo;

typedef struct s_table
{
	int					nb_philo;
	int					max_meals;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					death_flag;
	pthread_mutex_t		print;
	pthread_mutex_t		death;
	pthread_mutex_t		meal;
	pthread_mutex_t		forks[200];
	t_philo				philo[200];
}						t_table;

// functions in src/actions.c
void					p_dine(t_philo *philo);
int						p_eat(t_philo *philo);
void					p_sleep(t_philo *philo);
void					p_think(t_philo *philo);
void					p_death(void *data);

// functions in src/inits.c
int						check_value(char *str);
int						set_value(t_table *table, int ac, char **av);
int						set_table(t_table *table);
void					start_dine(t_table *table);

// functions in src/utils.c
void					print_action(t_philo *philo, char *action, int i);
long long				timestamp(void);
void					ft_usleep(int ms);
int						ft_atoi(const char *str);

# define BLACK "\e[0;30m"
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[0;33m"
# define BLUE "\e[0;34m"
# define MAGENTA "\e[0;35m"
# define CYAN "\e[0;36m"
# define WHITE "\e[0;37m"

# define BLACKBG "\e[0;100m"
# define REDBG "\e[0;101m"
# define GREENNBG "\e[0;102m"
# define YELLOWBG "\e[0;103m"
# define BLUEBG "\e[0;104m"
# define MAGENTABG "\e[0;105m"
# define CYANBG "\e[0;106m"
# define WHITEBG "\e[0;107m"

# define RESET "\e[0m"

#endif