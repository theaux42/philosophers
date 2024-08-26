/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:16:06 by tbabou            #+#    #+#             */
/*   Updated: 2024/08/25 19:04:10 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void start_life(t_philo *philo)
{
    pthread_t death_thread;

    pthread_create(&death_thread, NULL, (void *)get_death, philo);
    if (philo->id % 2 == 0)
        ft_usleep(philo->time_to_eat);

    printf("Philosopher %d is alive\n", philo->id);
    while (1)
    {
        if (philo->is_dead)
            break;
        if (!philo->is_eating)
        {
            p_eat(philo);
            p_sleep(philo);
            p_think(philo);
        }
    }
    pthread_join(death_thread, NULL);
}

void start_dining(t_table table)
{
    int i;

    i = 0;
    while (i < table.nb_philo)
    {
        pthread_create(&table.philo[i].thread, NULL, (void *)start_life, &table.philo[i]);
        i++;
    }
    i = 0;
    while (i < table.nb_philo)
    {
        pthread_join(table.philo[i].thread, NULL);
        i++;
    }
}