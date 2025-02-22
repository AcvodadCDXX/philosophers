#include "philo.h"

long get_time_in_ms() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void precise_usleep(long usec)
{
    long start = get_time_in_ms(); // Get current time
    long elapsed = 0;

    // Sleep for most of the time using `usleep`
    if (usec > 1000)
        usleep(usec - 1000);

    // Busy-wait for the last few microseconds to improve precision
    while ((elapsed = get_time_in_ms() - start) < usec)
        ;
}

void safe_print(t_table *table, char *message, int id)
{
    pthread_mutex_lock(&table->print_mutex);
    printf("[%ld] Philosopher %d %s\n", get_time_in_ms(), id, message);
    fflush(stdout);  // Ensure immediate output
    pthread_mutex_unlock(&table->print_mutex);
}

void set_long(pthread_mutex_t *mutex, long *dest, long value) {
    pthread_mutex_lock(mutex);
    *dest = value;
    pthread_mutex_unlock(mutex);
}
