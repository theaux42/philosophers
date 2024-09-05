/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 23:46:18 by tbabou            #+#    #+#             */
/*   Updated: 2024/09/05 16:19:53 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	p_dine(t_philo *philo)
{
	pthread_t	death_t;
	int			result;

	pthread_create(&death_t, NULL, (void *)p_death, philo);
	if (philo->id % 2 != 0)
		ft_usleep(philo->table->time_to_eat);
	while (1)
	{
		if (philo->table->death_flag == 1)
			break ;
		if (!philo->is_eating)
		{
			result = p_eat(philo);
			if (!result)
				break ;
			p_sleep(philo);
			p_think(philo);
		}
		if (philo->table->max_meals != -1
			&& philo->nb_meals >= philo->table->max_meals)
			break ;
	}
	pthread_join(death_t, NULL);
}

int	p_eat(t_philo *philo)
{
	if (philo->table->death_flag == 1)
		return (0);
	if (timestamp() - philo->last_meal < philo->table->time_to_eat)
	{
		ft_usleep(philo->table->time_to_eat);
		return (0);
	}
	pthread_mutex_lock(&philo->table->forks[philo->id]);
	print_action(philo, "has taken a fork", 0);
	pthread_mutex_lock(&philo->table->forks[(philo->id + 1)
		% philo->table->nb_philo]);
	print_action(philo, "has taken a fork", 0);
	philo->nb_meals++;
	print_action(philo, "is eating", 0);
	philo->last_meal = timestamp();
	ft_usleep(philo->table->time_to_eat);
	pthread_mutex_unlock(&philo->table->forks[philo->id]);
	pthread_mutex_unlock(&philo->table->forks[(philo->id + 1)
		% philo->table->nb_philo]);
	return (1);
}
void	p_sleep(t_philo *philo)
{
	philo->is_sleeping = 1;
	print_action(philo, "is sleeping", 0);
	ft_usleep(philo->table->time_to_sleep);
	philo->is_sleeping = 0;
}

void	p_think(t_philo *philo)
{
	philo->is_thinking = 1;
	print_action(philo, "is thinking", 0);
	philo->is_thinking = 0;
}

void	p_death(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		if (philo->table->max_meals != -1
			&& philo->nb_meals >= philo->table->max_meals)
			break ;
		if (philo->table->death_flag == 1)
			break ;
		pthread_mutex_lock(&philo->table->death);
		if (timestamp() - philo->last_meal > philo->table->time_to_die)
		{
			print_action(philo, "died", 1);
			philo->table->death_flag = 1;
			pthread_mutex_unlock(&philo->table->death);
			exit(0);
			break ;
		}
		pthread_mutex_unlock(&philo->table->death);
	}
}
