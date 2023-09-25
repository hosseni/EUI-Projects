#include "APP/Inc/AutonomousCar/AutonomousCar.h"

int main(int argc, char **argv) {


    /* Initialize the autonomous car's hardware components and peripherals. */
    autonomous_car_init();

    /* Create tasks with their respective priorities and delays. */
   create_task(0, 1, start_stop_condition,  0);        /* Task 0: start_stop_condition with priority 1 and no initial delay. */
   create_task(1, 3, avoid_obstacles,       0);        /* Task 1: avoid_obstacles with priority 3 and an initial delay of 5 system ticks. */
   create_task(2, 3, ldr_swing_car,         0);        /* Task 2: ldr_swing_car with priority 3 and an initial delay of 7 system ticks. */
   create_task(3, 5, get_temp,              0);        /* Task 3: get_temp      with priority 5 and an initial delay of 9 system ticks. */
   create_task(4, 5, lcd_display,           0);        /* Task 4: lcd_display with priority 5 and an initial delay of 9 system ticks. */

   tasks_scheduler();    /* Start the task scheduler to manage task execution. */


    /** Infinite Loop */
    while (1)
    {
        /** The main function enters an infinite loop, as task management is now handled by the scheduler. */
    }
}
