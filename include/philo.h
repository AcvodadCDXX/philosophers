#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdbool.h>
#include <stddef.h>

// Structures
typedef struct s_fork {
    pthread_mutex_t mutex;
    int fork_id;
} t_fork;

typedef struct s_table t_table;

typedef struct s_philosopher {
    int id;
    long last_meal_time;
    int meals_eaten;
    bool is_full;
    pthread_t thread;
    t_fork *left_fork;
    t_fork *right_fork;
    t_table *table;
    pthread_mutex_t meal_mutex;
} t_philosopher;

struct s_table {
    int num_philosophers;
    long time_to_die;
    long time_to_eat;
    long time_to_sleep;
    int meal_limit;
    bool simulation_running;
    pthread_mutex_t print_mutex;
    pthread_mutex_t sim_mutex;
    t_fork *forks;
    t_philosopher *philosophers;
};

// Function Declarations
void start_simulation(t_table *table);
void *philosopher_routine(void *arg);
void *monitor_dinner(void *arg);  // <-- Add this line
void cleanup(t_table *table);
void safe_print(t_table *table, char *message, int id);
long get_time_in_ms();
void precise_usleep(long time);
void set_long(pthread_mutex_t *mutex, long *dest, long value);

#endif
