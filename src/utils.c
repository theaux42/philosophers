/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:57:44 by tbabou            #+#    #+#             */
/*   Updated: 2024/09/05 17:16:33 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	print_action(t_philo *philo, char *action, int i)
{
	if (!i)
		i = 0;
	pthread_mutex_lock(&philo->table->print);
	if (i)
		printf("%s%lld %d %s%s\n", RED, timestamp() - philo->start, philo->id
			+ 1, action, RESET);
	else
		printf("%lld %d %s\n", timestamp() - philo->start, philo->id + 1,
			action);
	if (!i)
		pthread_mutex_unlock(&philo->table->print);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	i;
	int	neg;

	num = 0;
	neg = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * neg);
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

void	clean_table(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
		pthread_detach(table->philo[i++].thread);
	i = 0;
	while (i < table->nb_philo)
		pthread_detach(table->philo[i++].death_t);
	i = 0;
	while (i < table->nb_philo)
		pthread_mutex_destroy(&table->forks[i++]);
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->death);
	exit(0);
}
