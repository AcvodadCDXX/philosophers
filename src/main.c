#include "philo.h"

void init_table(t_table *table, int argc, char **argv) {
    if (argc != 5 && argc != 6) {  // Allow both cases
        printf("Usage: ./philo num_philos time_to_die time_to_eat time_to_sleep [meal_limit]\n");
        exit(1);
    }

    table->num_philosophers = atoi(argv[1]);
    table->time_to_die = atol(argv[2]);
    table->time_to_eat = atol(argv[3]);
    table->time_to_sleep = atol(argv[4]);

    // Handle optional meal limit (argc == 6)
    if (argc == 6)
        table->meal_limit = atoi(argv[5]);
    else
        table->meal_limit = -1;  // No meal limit

    table->simulation_running = true;

    // Allocate memory for philosophers and forks
    table->philosophers = malloc(sizeof(t_philosopher) * table->num_philosophers);
    table->forks = malloc(sizeof(t_fork) * table->num_philosophers);
    if (!table->philosophers || !table->forks) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Initialize forks and mutexes
    // In init_table(), assign forks correctly
    for (int i = 0; i < table->num_philosophers; i++) {
    if (i % 2 == 0) {  // Even philosophers grab left fork first
        table->philosophers[i].left_fork = &table->forks[i];
        table->philosophers[i].right_fork = &table->forks[(i + 1) % table->num_philosophers];
    } else {  // Odd philosophers grab right fork first
        table->philosophers[i].right_fork = &table->forks[i];
        table->philosophers[i].left_fork = &table->forks[(i + 1) % table->num_philosophers];
    }
}


    // Initialize philosophers
    for (int i = 0; i < table->num_philosophers; i++) {
        table->philosophers[i].id = i;
        table->philosophers[i].last_meal_time = get_time_in_ms();
        table->philosophers[i].meals_eaten = 0;
        table->philosophers[i].is_full = false;
        table->philosophers[i].left_fork = &table->forks[i];
        table->philosophers[i].right_fork = &table->forks[(i + 1) % table->num_philosophers];
        table->philosophers[i].table = table;
    }
}

int main(int argc, char **argv) {
    t_table table;

    init_table(&table, argc, argv);
    start_simulation(&table);
    cleanup(&table);

    return 0;
}
