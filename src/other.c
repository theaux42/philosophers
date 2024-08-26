/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 12:06:18 by tbabou            #+#    #+#             */
/*   Updated: 2024/08/25 17:14:23 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void display_table(t_table table)
{
    for (int i = 0; i < table.nb_philo; i++)
    {
        t_philo philo = table.philo[i];
        printf("Philosopher %d:\n", philo.id);
        printf("  Time to die: %d\n", philo.time_to_die);
        printf("  Time to eat: %d\n", philo.time_to_eat);
        printf("  Time to sleep: %d\n", philo.time_to_sleep);
        printf("  Number of meals: %d\n", philo.nb_meals);
        printf("  Is eating: %d\n", philo.is_eating);
        printf("  Is sleeping: %d\n", philo.is_sleeping);
        printf("  Is thinking: %d\n", philo.is_thinking);
        printf("  Is dead: %d\n", philo.is_dead);

        int fork_index = philo.id - 1;
        t_fork fork = table.forks[fork_index];
        if (fork.is_taken)
        {
            printf("  Fork %d: Locked\n", fork_index);
        }
        else
        {
            printf("  Fork %d: Unlocked\n", fork_index);
        }
    }
}

