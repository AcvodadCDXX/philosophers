#include "philo.h"

void *philosopher_routine(void *arg) {
    t_philosopher *philo = (t_philosopher *)arg;

    printf("Philosopher %d started\n", philo->id);  // ✅ Debug

    while (philo->table->simulation_running) {
        printf("Philosopher %d trying to take left fork\n", philo->id);  // ✅ Debug
        pthread_mutex_lock(&philo->left_fork->mutex);
        printf("Philosopher %d took left fork\n", philo->id);  // ✅ Debug

        pthread_mutex_lock(&philo->right_fork->mutex);
        printf("Philosopher %d took right fork\n", philo->id);  // ✅ Debug

        safe_print(philo->table, "is eating", philo->id);
        precise_usleep(philo->table->time_to_eat);

        pthread_mutex_unlock(&philo->left_fork->mutex);
        pthread_mutex_unlock(&philo->right_fork->mutex);
        printf("Philosopher %d released forks\n", philo->id);  // ✅ Debug
    }
    return NULL;
}
