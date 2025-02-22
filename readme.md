# **Philosophers Project - Full Control Flow Summary**

## **1. Overview**
This project simulates the classic **Dining Philosophers** problem using **threads and mutexes**. Each philosopher is a separate thread that cycles through **thinking, eating, and sleeping** while competing for shared resources (forks). A monitoring system ensures no philosopher starves, and the simulation stops when a philosopher dies or all have eaten a required number of meals.

---

## **2. File Breakdown and Responsibilities**

### **`JANphilo.c` (Main Entry Point)**
- Parses **command-line arguments**.
- Initializes the **simulation and philosophers**.
- Handles the **single philosopher special case** (they die immediately).
- Calls **`create_threads()`** to launch the philosopher threads and monitor.

### **`JANphilo_init.c` (Initialization & Memory Allocation)**
- Allocates and initializes **philosopher structures (`t_philo`)**.
- Initializes **mutexes for forks and shared resources**.
- Passes **simulation parameters** to each philosopher.

### **`JANphilo.h` (Header File & Struct Definitions)**
- Defines:
  - `t_program`: **Holds shared resources (mutexes, philosophers, death flag).**
  - `t_philo`: **Stores individual philosopher state.**
- Declares **all function prototypes** for the program.
- Defines the **maximum number of philosophers** (`PHILO_MAX`).

### **`JANthreads.c` (Thread Creation & Execution Control)**
- Launches the **monitor thread** (`monitor()`).
- Creates **one thread per philosopher**, running `le_routine()`.
- Waits for all threads to **finish execution** before exiting.

### **`JANactions.c` (Philosopher Actions)**
- Defines:
  - `think()` → Logs thinking state.
  - `sleep_action()` → Logs sleeping state and sleeps.
  - `eat()` → Handles eating (locks forks, updates last meal time, unlocks forks).

### **`JANeat_action.c` (Fork Management & Eating Mechanics)**
- **Determines fork order** using `select_chopsticks()` (prevents deadlocks).
- **Locks forks** (`take_chopsticks()`).
- **Updates eating state** and **tracks meal timestamps** (`start_eating()`).
- **Releases forks** (`release_chopsticks()`).

### **`JANmonitor.c` (Monitoring System & Death Detection)**
- **`monitor()`**: Runs in a separate thread to track philosopher starvation.
- **`reaper_monitor()`**: Checks if any philosopher has died.
- **`death_checker()`**: Determines starvation using timestamps.
- **`meal_manager()`**: Stops simulation if all philosophers have eaten the required number of times.

### **`JANutils.c` (Utility Functions)**
- **String handling** (`ft_strlen`, `ft_atoi`).
- **Timing functions** (`get_time`, `custom_sleep`).
- **Simulation cleanup** (`quitter` destroys mutexes before exit).

---

## **3. Full Control Flow**
### **Step 1: Program Starts (`JANphilo.c`)**
1. Parses **command-line arguments**.
2. Calls `init_simulation()` to initialize program state.
3. Calls `create_threads()` to start philosophers and monitoring.

### **Step 2: Initialization (`JANphilo_init.c`)**
1. Allocates **philosopher structures (`t_philo`)**.
2. Initializes **mutexes for forks and shared resources**.
3. Passes **simulation parameters** to each philosopher.

### **Step 3: Threads Start (`JANthreads.c`)**
1. **Creates a monitoring thread** running `monitor()`.
2. **Creates one philosopher thread per philosopher**, executing `le_routine()`.

### **Step 4: Philosopher Behavior (`JANactions.c`, `JANeat_action.c`)**
1. **Think** → Logs status.
2. **Eat**:
   - Picks forks (`select_chopsticks()`).
   - Locks forks (`take_chopsticks()`).
   - Logs eating.
   - Updates **meal timestamp**.
   - Sleeps for `time_to_eat`.
   - Unlocks forks (`release_chopsticks()`).
3. **Sleep** → Logs status and sleeps for `time_to_sleep`.

### **Step 5: Monitoring (`JANmonitor.c`)**
1. **Monitors for starvation (`reaper_monitor()`).**
2. **Monitors if all philosophers have eaten (`meal_manager()`).**
3. **If a philosopher dies, `monitor()` stops the simulation.**

### **Step 6: Cleanup (`JANutils.c`)**
1. **Destroys all mutexes (`quitter()`).**
2. **Joins all threads (`pthread_join`).**
3. **Program exits.**

---

## **4. Key Synchronization & Deadlock Prevention**
- **Mutexes ensure safe access to shared variables** (forks, logs, meal timestamps).
- **Philosopher start times are staggered (`custom_sleep()`) to prevent deadlocks.**
- **Fork pickup order (`select_chopsticks()`) prevents circular waiting.**

---

## **Final Notes**
This file remains **unchanged** until the project is completed. It serves as the **official control flow documentation** for reference and debugging.

