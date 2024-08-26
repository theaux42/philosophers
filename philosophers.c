/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:42:18 by tbabou            #+#    #+#             */
/*   Updated: 2024/08/25 17:15:33 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac, char **av)
{
    t_table table;
	if (!check_args(ac, av))
        return (1);
    table = init_table(av);
    display_table(table);
    
    start_dining(table);

    // free_table(table);
}
