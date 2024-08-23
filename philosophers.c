/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:42:18 by tbabou            #+#    #+#             */
/*   Updated: 2024/08/23 12:14:33 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac, char **av)
{
	int	i;

	i = 0;
    if (ac != 5 && ac != 6)
        return (printf("Error: wrong number of arguments\n"), 1);
	printf("Number of philosophers: %d\n", ft_atoi(i));
}
