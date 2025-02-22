#include "philo.h"

void *monitor_dinner(void *arg) {
    t_table *table = (t_table *)arg;
    while (table->simulation_running) {
        for (int i = 0; i < table->num_philosophers; i++) {
            pthread_mutex_lock(&table->sim_mutex);
            long elapsed = get_time_in_ms() - table->philosophers[i].last_meal_time;
            if (elapsed > table->time_to_die) {
                table->simulation_running = false;
                safe_print(table, "died", table->philosophers[i].id);
            }
            pthread_mutex_unlock(&table->sim_mutex);
        }
        usleep(500); // Reduce CPU load
    }
    return NULL;
}
