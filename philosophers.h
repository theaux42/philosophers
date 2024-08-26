/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:43:01 by tbabou            #+#    #+#             */
/*   Updated: 2024/08/25 18:46:14 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_table t_table;

typedef struct s_fork {
    int             id;
    int             is_taken;
    pthread_mutex_t mutex;
}                   t_fork; 

typedef struct s_philo
{
	int				id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meals;
	long long int	last_meal;
	long long int	start;
	int				is_eating;
	int				is_sleeping;
	int				is_thinking;
	int				is_dead;
	t_table			*table;
	pthread_t		thread;
}					t_philo;

typedef struct s_table
{
	t_philo			*philo;
    t_fork			*forks;
    int             nb_philo;
	int				*meals;
    int             max_meals;
	long long int	*last_meal;
	int				*alive;
}					t_table;


int					ft_atoi(const char *str);
int					check_args(int ac, char **av);
t_table             init_table(char **av);
t_philo				init_philosophers(char **av, const int id, t_table *table);
void				display_table(t_table table);
void                free_table(t_table table);
t_table             init_malloc(char **av);

void 				start_dining(t_table table);
long long	timestamp(void);

void				ft_usleep(int ms);
// Actions that the philosophers can do
void				p_eat(t_philo *philo);
void				p_sleep(t_philo *philo);
void				p_think(t_philo *philo);
void				get_death(void *data);
void				start_life(t_philo *philo);

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