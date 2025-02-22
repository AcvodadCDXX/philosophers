/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JANactions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbogdano <bbogdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:14:40 by jsteinka          #+#    #+#             */
/*   Updated: 2025/02/22 15:27:35 by bbogdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "JANphilo.h"

void	think(t_philo *philo)
{
	display_status("is thinking", philo, philo->id);
}

void	sleep_action(t_philo *philo)
{
	display_status("is sleeping", philo, philo->id);
	custom_sleep(philo->time_to_sleep);
}

void	eat(t_philo *philo)
{
	pthread_mutex_t	*first_chopstick;
	pthread_mutex_t	*second_chopstick;

	select_chopsticks(philo, &first_chopstick, &second_chopstick);
	take_chopsticks(philo, first_chopstick, second_chopstick);
	start_eating(philo);
	release_chopsticks(first_chopstick, second_chopstick);
}
