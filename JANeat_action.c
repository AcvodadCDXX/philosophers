/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JANeat_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbogdano <bbogdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:38:30 by jsteinka          #+#    #+#             */
/*   Updated: 2025/02/22 15:27:39 by bbogdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "JANphilo.h"

// Gangster war hier :3
void	select_chopsticks(t_philo *philo, \
					pthread_mutex_t **first, pthread_mutex_t **second)
{
	if (philo->id == 1)
	{
		*first = philo->r_chopstick;
		*second = philo->l_chopstick;
	}
	else if (philo->id % 2 == 0)
	{
		*first = philo->r_chopstick;
		*second = philo->l_chopstick;
	}
	else if (philo->id % 2 == 1 && philo->num_of_philos % 2 == 0)
	{
		*first = philo->l_chopstick;
		*second = philo->r_chopstick;
	}
	else
	{
		*first = philo->r_chopstick;
		*second = philo->l_chopstick;
	}
}

void	take_chopsticks(t_philo *philo, \
					pthread_mutex_t *first, pthread_mutex_t *second)
{
	pthread_mutex_lock(first);
	display_status("has taken a chopstick", philo, philo->id);
	pthread_mutex_lock(second);
	display_status("has taken a chopstick", philo, philo->id);
}

void	start_eating(t_philo *philo)
{
	philo->eating = 1;
	display_status("is eating", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	custom_sleep(philo->time_to_eat);
	philo->eating = 0;
}

void	release_chopsticks(pthread_mutex_t *first, pthread_mutex_t *second)
{
	pthread_mutex_unlock(second);
	pthread_mutex_unlock(first);
}
