#include "philo.h"

void start_simulation(t_table *table) {
    printf("Starting simulation...\n");  // ✅ Debug

    for (int i = 0; i < table->num_philosophers; i++) {
        printf("Creating thread for philosopher %d\n", i);  // ✅ Debug
        pthread_create(&table->philosophers[i].thread, NULL, philosopher_routine, &table->philosophers[i]);
    }

    // Start the monitor thread
    printf("Creating monitor thread...\n");  // ✅ Debug
    pthread_t monitor;
    pthread_create(&monitor, NULL, monitor_dinner, table);

    for (int i = 0; i < table->num_philosophers; i++) {
        pthread_join(table->philosophers[i].thread, NULL);
    }

    pthread_join(monitor, NULL);
    printf("Simulation ended.\n");  // ✅ Debug
}
