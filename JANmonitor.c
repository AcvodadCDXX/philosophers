/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JANmonitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbogdano <bbogdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:14:46 by jsteinka          #+#    #+#             */
/*   Updated: 2025/02/22 15:27:45 by bbogdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "JANphilo.h"

void	display_status(char *str, t_philo *philo, int id)
{
	size_t		time;
	static int	printed_died = 0;

	pthread_mutex_lock(philo->write_lock);
	time = get_time() - philo->start_time;
	if (!death_lock(philo) && printed_died != 1)
		printf("%zu %d %s\n", time, id, str);
	else
	{
		printed_died = 1;
		quitter(NULL, philo->program, philo->program->chopsticks);
	}
	pthread_mutex_unlock(philo->write_lock);
}

int	death_checker(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_time() - philo->last_meal >= time_to_die
		&& philo->eating == 0)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

// I am the Reaper, I only bring death
// I don't even know what else you'd ever expect of me
int	reaper_monitor(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].num_of_philos)
	{
		if (death_checker(&philos[i], philos[i].time_to_die))
		{
			display_status("\033[31mdied\033[0m", &philos[i], philos[i].id);
			pthread_mutex_lock(philos[0].dead_lock);
			*philos->dead = 1;
			pthread_mutex_unlock(philos[0].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

// Checks if all the philos ate the num_of_meals

int	meal_manager(t_philo *philos)
{
	int	i;
	int	meals_eaten;

	i = 0;
	meals_eaten = 0;
	if (philos[0].num_times_to_eat == -1)
		return (0);
	while (i < philos[0].num_of_philos)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].meals_eaten >= philos[i].num_times_to_eat)
			meals_eaten++;
		pthread_mutex_unlock(philos[i].meal_lock);
		i++;
	}
	if (meals_eaten == philos[0].num_of_philos)
	{
		pthread_mutex_lock(philos[0].dead_lock);
		*philos->dead = 1;
		pthread_mutex_unlock(philos[0].dead_lock);
		return (1);
	}
	return (0);
}

// Monitor thread routine

void	*monitor(void *ptr)
{
	t_philo	*philos;

	philos = (t_philo *)ptr;
	while (1)
		if (reaper_monitor(philos) == 1 || meal_manager(philos) == 1)
			break ;
	return (ptr);
}
