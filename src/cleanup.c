#include "philo.h"

void cleanup(t_table *table) {
    for (int i = 0; i < table->num_philosophers; i++) {
        pthread_mutex_destroy(&table->forks[i].mutex);
    }
    pthread_mutex_destroy(&table->print_mutex);
    pthread_mutex_destroy(&table->sim_mutex);

    free(table->philosophers);
    free(table->forks);
}
