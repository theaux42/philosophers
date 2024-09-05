/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 23:46:37 by tbabou            #+#    #+#             */
/*   Updated: 2024/09/05 19:45:05 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	check_value(char *str)
{
	int	value;

	value = ft_atoi(str);
	if (value > 0 && value < INT_MAX)
		return (value);
	return (-1);
}

int	set_value(t_table *table, int ac, char **av)
{
	table->nb_philo = check_value(av[1]);
	if (table->nb_philo == -1)
		return (-1);
	table->time_to_die = check_value(av[2]);
	if (table->time_to_die == -1)
		return (-1);
	table->time_to_eat = check_value(av[3]);
	if (table->time_to_eat == -1)
		return (-1);
	table->time_to_sleep = check_value(av[4]);
	table->max_meals = -1;
	if (ac == 6)
		table->max_meals = check_value(av[5]);
	table->death_flag = 0;
	return (0);
}

void	set_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&table->print, NULL);
	pthread_mutex_init(&table->death, NULL);
}

int	set_table(t_table *table)
{
	int				i;
	long long int	start;

	i = 0;
	start = timestamp();
	while (i <= table->nb_philo)
	{
		table->philo[i].id = i;
		table->philo[i].nb_meals = 0;
		table->philo[i].last_meal = start;
		table->philo[i].is_eating = 0;
		table->philo[i].is_sleeping = 0;
		table->philo[i].is_thinking = 0;
		table->philo[i].start = start;
		table->philo[i].table = table;
		i++;
	}
	return (0);
}

void	start_dine(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		pthread_create(&table->philo[i].thread, NULL, (void *)p_dine,
			&table->philo[i]);
		i++;
	}
	i = 0;
	while (i < table->nb_philo)
	{
		pthread_join(table->philo[i].thread, NULL);
		i++;
	}
}
