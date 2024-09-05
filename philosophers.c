/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:59:44 by tbabou            #+#    #+#             */
/*   Updated: 2024/09/05 16:04:34 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	clean_table(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_table	table;

	if (set_value(&table, ac, av) == -1)
		return (printf("%s[ERROR] -> Invalid values.%s", RED, RESET), -1);
	if (set_table(&table) == -1)
		return (printf("%s[ERROR] -> Could not set table.%s", RED, RESET), -1);
	start_dine(&table);
	clean_table(&table);
	return (0);
}
