#include "APP/Autonomous_Car/autonomous_car.h"

int main(int argc, char **argv)
{
    // Initialize the system
    autonomousCarInit();

    while(1)
    {
        // Run the system
        autonomousCarRun();
    }
}
