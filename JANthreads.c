/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JANthreads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbogdano <bbogdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:08:11 by jsteinka          #+#    #+#             */
/*   Updated: 2025/02/22 15:28:04 by bbogdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "JANphilo.h"

int	death_lock(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	*le_routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
		custom_sleep(5);
	if (philo->id == 1 && philo->num_of_philos % 2 == 1)
		custom_sleep(6);
	while (!death_lock(philo))
	{
		think(philo);
		eat(philo);
		sleep_action(philo);
	}
	return (pointer);
}

int	create_threads(t_program *program, pthread_mutex_t *chopsticks)
{
	pthread_t	observer;
	int			i;

	if (pthread_create(&observer, NULL, &monitor, program->philos) != 0)
		quitter("Thread creation error", program, chopsticks);
	i = 0;
	while (i < program->philos[0].num_of_philos)
	{
		if (pthread_create(&program->philos[i].thread, NULL, &le_routine,
				&program->philos[i]) != 0)
			quitter("Thread creation error", program, chopsticks);
		i++;
	}
	i = 0;
	if (pthread_join(observer, NULL) != 0)
		quitter("Thread join error", program, chopsticks);
	while (i < program->philos[0].num_of_philos)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			quitter("Thread join error", program, chopsticks);
		i++;
	}
	return (0);
}
