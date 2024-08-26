/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:17:22 by tbabou            #+#    #+#             */
/*   Updated: 2024/08/25 19:03:06 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void p_eat(t_philo *philo)
{
    printf("Philosopher %d is eating\n", philo->id);
    philo->is_eating = 1;
    philo->nb_meals++;
    // printf("Before last meal = %lld\n", philo->last_meal);
    ft_usleep(philo->time_to_eat);
    philo->last_meal = timestamp();
    // printf("After last meal = %lld\n", philo->last_meal);
    philo->is_eating = 0;
}

void p_sleep(t_philo *philo)
{
    philo->is_sleeping = 1;
    printf("Philosopher %d is sleeping\n", philo->id);
    ft_usleep(philo->time_to_sleep);
    philo->is_sleeping = 0;
}

void p_think(t_philo *philo)
{
    philo->is_thinking = 1;
    printf("Philosopher %d is thinking\n", philo->id);
    philo->is_thinking = 0;
}

long long	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(int ms)
{
	long int	time;

	time = timestamp();
	while (timestamp() - time < ms)
		usleep(ms / 10);
}

void get_death(void *data)
{
    t_philo *philo = (t_philo *)data;

    while (1)
    {
        if (philo->is_dead)
            break;
        if (timestamp() - philo->last_meal > philo->time_to_die)
        {
            philo->is_dead = 1;
            printf("%lld Philosopher %d is dead\n",timestamp() - philo->start, philo->id);
            // printf("Last meal = %lld\n", philo->last_meal);
        }
        // printf("Start time = %lld\ntimestamp = %lld\nTime to die = %i\n", philo->start, timestamp(), philo->time_to_die);
        // printf("%lld Philosopher %d is alive\n",timestamp() - philo->start, philo->id);
        // printf("Last meal = %lld\n", philo->last_meal);
    }

}