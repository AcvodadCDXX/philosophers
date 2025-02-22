/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JANphilo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbogdano <bbogdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:14:30 by jsteinka          #+#    #+#             */
/*   Updated: 2025/02/22 12:02:26 by bbogdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣤⣤⣤⣤⣤⣤⣤⣤⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⠶⠟⠛⠛⠉⠉⠉⠁⠀⠀⠈⠉⠉⠙⠛⠿⢶⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⣠⠖⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⢷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⢠⡾⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢷⣄⠀⠀⠀⠀⠀⢀⣀⠀⠀⠀⠀
// ⠀⠀⠀⣠⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⠀⠀⠀⠹⣧⡀⠀⠀⠀⡏⠉⠙⠋⢹⡆
// ⠀⠀⢠⡿⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠚⠉⠉⠛⠿⣦⡀⠀⠸⣷⡀⠀⠀⠹⣄⠀⠠⡹⠃
// ⠀⢀⣿⠃⠀⠀⠀⠀⣠⣶⠾⠟⠛⠉⠉⠛⠿⣶⣄⠀⠀⠀⠀⣰⠃⢀⣠⣤⣄⠀⠈⢻⣦⠀⢻⣧⠀⠀⠀⠈⠓⠋⠀⠀
// ⠀⢸⣿⠀⠀⠀⣠⣾⠋⠁⠀⠀⢀⣠⣤⣤⣤⣈⠙⣷⣄⠀⢠⣏⣶⣿⣿⣿⣿⣿⣦⠀⢻⣧⠘⣿⢀⢸⡛⠛⢲⠀⠀⠀
// ⠀⣾⡇⠀⠀⢠⡿⠁⠀⠀⣠⣾⡿⢿⣿⣿⣿⣿⣷⣌⢿⣆⢸⣿⡋⠉⢉⣿⣿⣿⣿⣧⠈⣿⠀⣿⣿⠀⠹⠶⠋⠀⠀⠀
// ⠈⡟⣿⠀⠀⢸⠇⠀⢀⣼⣄⠈⠀⣸⣿⣿⣿⣿⣿⣿⡎⣿⣿⣿⣿⣶⣿⣻⣿⣿⣿⣿⣤⣿⢀⣿⣿⠀⠀⠀⠀⠀⠀⠀
// ⠀⢷⢹⡆⠀⢸⡄⠀⣾⣿⣿⣿⣿⣿⣩⣿⣿⣿⣿⣿⣇⣿⢹⣿⣿⣿⣿⣿⣿⣿⣟⣿⣿⠏⣸⢧⠏⠀⠀⠀⠀⠀⠀⠀
// ⠀⠈⣇⢳⡀⠈⢧⠐⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⠏⢠⢁⡞⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠈⢎⠃⠀⠈⠳⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣾⠟⠁⠀⠀⠈⠻⣿⣿⣿⣿⡿⠟⠁⠀⣠⠎⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠈⠳⣄⠀⠀⠈⠙⡻⠿⢿⣿⡿⠿⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠈⠉⠃⣀⡀⣰⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⣀⡤⠬⣷⣄⡲⣤⣈⠀⠈⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⡴⢛⡵⠚⠁⠀⢀⣠⣤⣀⡀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠸⣇⠀⠀⠀⢻⣿⠒⠭⣟⣷⢶⣤⣤⣤⣤⣤⣤⣤⣤⣶⢾⣟⠯⠗⠊⠁⠀⠀⠀⣾⠟⠁⠀⢘⣿⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⢹⣧⠀⠀⠈⣿⡄⠀⠀⠈⠉⠛⠛⠛⠛⠛⠒⠋⠛⠉⠉⠀⠀⠀⠀⠀⠀⠀⢸⡿⠀⠀⢠⣿⠏⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⣠⣿⠇⠀⠀⠙⠛⠛⠒⠒⠛⠛⠛⠻⠿⢷⡢⣤⣔⡶⠿⠟⠛⠛⠛⠻⠿⠽⠟⠁⠀⠀⢺⡿⡄⠀⠀⠀⠀⠀⠀
// ⠀⠀⢰⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣾⡁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⡀⠀⠀⠀⠀⠀
// ⠀⠀⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠙⠛⠻⢿⣿⠒⠲⠛⠙⠲⠦⢼⣿⡿⠟⠛⠃⠀⠀⠀⠀⠀⠀⠀⢸⣇⡇⠀⠀⠀⠀⠀
// ⠀⠀⠹⠿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠇⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡾⡻⠃⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠈⠻⢦⣀⠀⠀⠀⠀⠀⠀⢀⡾⡿⠀⠀⠀⠀⠀⠀⠘⣿⣆⠀⠀⠀⠀⠀⠀⢀⣠⣴⢯⠞⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠉⠛⠳⠶⠶⠶⣖⡿⠚⠁⠀⠀⠀⠀⠀⠀⠀⠘⠮⣷⣶⡤⡤⠴⠾⠟⠋⠚⠁⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define PHILO_MAX 201

typedef struct s_philo	t_philo;

typedef struct s_program
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
	pthread_mutex_t	*chopsticks;
}					t_program;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_chopstick;
	pthread_mutex_t	*l_chopstick;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	t_program		*program;
}					t_philo;

int					argv_num_char(char *arg);
int					input_check(char **argv);
void				quitter(char *str, t_program *program,
						pthread_mutex_t *chopsticks);
void				init_simulation(t_program *program, t_philo *philos);
void				init_chopsticks(pthread_mutex_t *chopsticks, int philo_num);
void				init_philosophers(t_philo *philos, t_program *program,
						pthread_mutex_t *chopsticks, char **argv);
void				parse_input(t_philo *philo, char **argv);
int					create_threads(t_program *program, \
					pthread_mutex_t *chopsticks);
void				*monitor(void *pointer);
void				*le_routine(void *pointer);
void				eat(t_philo *philo);
void				sleep_action(t_philo *philo);
void				think(t_philo *philo);
int					death_lock(t_philo *philo);
int					meal_manager(t_philo *philos);
int					reaper_monitor(t_philo *philos);
int					death_checker(t_philo *philo, size_t time_to_die);
int					ft_atoi(char *str);
int					custom_sleep(size_t microseconds);
int					ft_strlen(char *str);
void				display_status(char *str, t_philo *philo, int id);
size_t				get_time(void);
void				release_chopsticks(pthread_mutex_t *first, \
						pthread_mutex_t *second);
void				start_eating(t_philo *philo);
void				take_chopsticks(t_philo *philo, \
						pthread_mutex_t *first, pthread_mutex_t *second);
void				select_chopsticks(t_philo *philo, \
						pthread_mutex_t **first, pthread_mutex_t **second);

#endif
