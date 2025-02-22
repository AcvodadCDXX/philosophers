/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JANphilo_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbogdano <bbogdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:15:00 by jsteinka          #+#    #+#             */
/*   Updated: 2025/02/22 15:27:49 by bbogdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "JANphilo.h"

void	parse_input(t_philo *philo, char **argv)
{
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->num_of_philos = ft_atoi(argv[1]);
	if (argv[5])
		philo->num_times_to_eat = ft_atoi(argv[5]);
	else
		philo->num_times_to_eat = -1;
}

void	init_philosophers(t_philo *philos, t_program *program, \
			pthread_mutex_t *chopsticks, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philos[i].id = i + 1;
		philos[i].program = program;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		parse_input(&philos[i], argv);
		philos[i].start_time = get_time();
		philos[i].last_meal = get_time();
		philos[i].write_lock = &program->write_lock;
		philos[i].dead_lock = &program->dead_lock;
		philos[i].meal_lock = &program->meal_lock;
		philos[i].dead = &program->dead_flag;
		philos[i].l_chopstick = &chopsticks[i];
		if (i == 0)
			philos[i].r_chopstick = &chopsticks[philos[i].num_of_philos - 1];
		else
			philos[i].r_chopstick = &chopsticks[i - 1];
		i++;
	}
}

void	init_chopsticks(pthread_mutex_t *chopsticks, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		pthread_mutex_init(&chopsticks[i], NULL);
		i++;
	}
}

void	init_simulation(t_program *program, t_philo *philos)
{
	program->dead_flag = 0;
	program->philos = philos;
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
}
