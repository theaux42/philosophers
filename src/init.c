/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:30:49 by tbabou            #+#    #+#             */
/*   Updated: 2024/08/25 18:50:25 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

t_philo init_philosophers(char **av, const int id, t_table *table)
{
    t_philo philo;

    philo.id = id;
    philo.time_to_die = ft_atoi(av[2]);
    philo.time_to_eat = ft_atoi(av[3]);
    philo.time_to_sleep = ft_atoi(av[4]);
    philo.nb_meals = 0;
    philo.is_eating = 0;
    philo.is_sleeping = 0;
    philo.is_thinking = 0;
    philo.is_dead = 0;
    philo.thread = 0;
    philo.start = timestamp();
    philo.last_meal = timestamp();
    philo.table = table;
    return (philo);
}

int check_args(int ac, char **av)
{
    if (ac != 5 && ac != 6)	
        return (printf("Error: wrong number of arguments\n"), 0);
    if (ft_atoi(av[1]) > 200)
        return (printf("Error: too many philosophers\n"), 0);
    if (ft_atoi(av[2]) < 0 || ft_atoi(av[3]) < 0 || ft_atoi(av[4]) < 0)
        return (printf("Error: Nothing can be negative\n"), 0);
    return (1);
}

t_fork init_fork(int id)
{
    t_fork fork;

    fork.id = id;
    fork.is_taken = 0;
    pthread_mutex_init(&fork.mutex, NULL);
    return (fork);
}

t_table init_table(char **av)
{
    t_table table;

    table = init_malloc(av);
    table.nb_philo = ft_atoi(av[1]);
    table.max_meals = 0;
    for (int i = 0; i < ft_atoi(av[1]); i++)
    {
        table.philo[i] = init_philosophers(av, i + 1, &table);
        table.meals[i] = 0;
        table.last_meal[i] = 0;
        table.alive[i] = 1;
    }
    for (int i = 0; i < ft_atoi(av[1]); i++)
        table.forks[i] = init_fork(i);
    return (table);
}
