/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:43:01 by tbabou            #+#    #+#             */
/*   Updated: 2024/08/23 12:14:56 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
    int				id;
    int				nb_philo;
    int				time_to_die;
    int				time_to_eat;
    int				time_to_sleep;
    int				nb_meals;
    int				*forks;
    int				*meals;
    pthread_mutex_t	*mutex;
    pthread_mutex_t	*print;
    pthread_mutex_t	*death;
    struct timeval	start;
}					t_philo;

typedef struct s_


int		ft_atoi(const char *str);

# endif