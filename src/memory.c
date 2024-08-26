/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:50:19 by tbabou            #+#    #+#             */
/*   Updated: 2024/08/24 13:50:57 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

t_table init_malloc(char **av)
{
    t_table table;

    table.philo = malloc(sizeof(t_philo) * ft_atoi(av[1]));
    table.forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));
    table.meals = malloc(sizeof(int) * ft_atoi(av[1]));
    table.last_meal = malloc(sizeof(int) * ft_atoi(av[1]));
    table.alive = malloc(sizeof(int) * ft_atoi(av[1]));
    return (table);
}

void free_table(t_table table)
{
    free(table.philo);
    free(table.forks);
    free(table.meals);
    free(table.last_meal);
    free(table.alive);
    for (int i = 0; i < table.nb_philo; i++)
        pthread_mutex_destroy(&table.forks[i].mutex);
    free(table.forks);
}