/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:59:44 by tbabou            #+#    #+#             */
/*   Updated: 2024/09/05 17:07:01 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (set_value(&table, ac, av) == -1)
		return (printf("%s[ERROR] -> Invalid values.%s", RED, RESET), -1);
	if (set_table(&table) == -1)
		return (printf("%s[ERROR] -> Could not set table.%s", RED, RESET), -1);
	set_forks(&table);
	start_dine(&table);
	clean_table(&table);
	return (0);
}
