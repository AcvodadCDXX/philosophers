/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JANphilo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbogdano <bbogdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:14:55 by jsteinka          #+#    #+#             */
/*   Updated: 2025/02/22 15:27:24 by bbogdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "JANphilo.h"

void	single_philosopher(char **argv)
{
	long long	start_time;

	start_time = get_time();
	printf("%lld 1 was born\n", get_time() - start_time);
	usleep(ft_atoi(argv[2]) * 1000);
	printf("%lld 1 fking died. Like ... how?? Why so weak?\n", \
	get_time() - start_time);
}

int	argv_num_char(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	input_check(char **argv)
{
	if (ft_atoi(argv[1]) > PHILO_MAX || ft_atoi(argv[1]) <= 0
		|| argv_num_char(argv[1]) == 1)
		return (write(2, "Invalid number of philosophers\n", 29), 1);
	if (ft_atoi(argv[2]) <= 0 || argv_num_char(argv[2]) == 1)
		return (write(2, "time to die is invalid\n", 21), 1);
	if (ft_atoi(argv[3]) <= 0 || argv_num_char(argv[3]) == 1)
		return (write(2, "time to eat is invalid\n", 21), 1);
	if (ft_atoi(argv[4]) <= 0 || argv_num_char(argv[4]) == 1)
		return (write(2, "time to sleep is invalid\n", 23), 1);
	if (argv[5] && (ft_atoi(argv[5]) < 0 || argv_num_char(argv[5]) == 1))
		return (write(2, "nbr of times philosopher must eat is invalid\n", 46));
	return (0);
}

int	main(int argc, char **argv)
{
	t_program		program;
	t_philo			philos[PHILO_MAX];
	pthread_mutex_t	chopsticks[PHILO_MAX];

	program.chopsticks = chopsticks;
	if (argc != 5 && argc != 6)
		return (write(2, "Please enter valid parameters UwU\n", 34), 1);
	if (input_check(argv) == 1)
		return (1);
	if (ft_atoi(argv[1]) == 1)
	{
		single_philosopher(argv);
		return (0);
	}
	init_simulation(&program, philos);
	init_chopsticks(chopsticks, ft_atoi(argv[1]));
	init_philosophers(philos, &program, chopsticks, argv);
	create_threads(&program, chopsticks);
	quitter(NULL, &program, chopsticks);
	return (0);
}
