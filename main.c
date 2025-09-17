#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> // for Sleep() on Windows

int main() {
    srand(time(NULL)); // seed random numbers

    for (int cycle = 1; cycle <= 5; cycle++) {
        // open log file in append mode
        FILE *log = fopen("safety_log.txt", "a");
        if (!log) {
            printf("Error: Could not open log file.\n");
            return 1;
        }

        // get current time
        time_t now = time(NULL);
        struct tm *t = localtime(&now);

        printf("\nCycle %d\n", cycle);
        printf("Mine Safety Sensor Monitor\n");
        fprintf(log, "[%02d-%02d-%04d %02d:%02d:%02d] (Cycle %d)\n",
                t->tm_mday, t->tm_mon + 1, t->tm_year + 1900,
                t->tm_hour, t->tm_min, t->tm_sec, cycle);

        // Temperature sensor (0–60 C)
        int temperature = rand() % 61;
        printf("Temperature reading: %d C\n", temperature);
        if (temperature > 40) {
            printf("ALERT: Temperature too high!\n");
            fprintf(log, "Temperature: %d C -> ALERT: Too high!\n", temperature);
        } else {
            printf("STATUS: Temperature OK\n");
            fprintf(log, "Temperature: %d C -> OK\n", temperature);
        }

        // Methane sensor (0.0–5.0 %)
        float methane = (rand() % 501) / 100.0;
        printf("Methane reading: %.2f %%\n", methane);
        if (methane > 1.0) {
            printf("ALERT: Methane level unsafe!\n");
            fprintf(log, "Methane: %.2f %% -> ALERT: Unsafe\n", methane);
        } else {
            printf("STATUS: Methane level safe\n");
            fprintf(log, "Methane: %.2f %% -> Safe\n", methane);
        }

        // Equipment Load sensor (0–100 %)
        int load = rand() % 101;
        printf("Equipment Load: %d %%\n", load);
        if (load > 85) {
            printf("ALERT: Equipment overload risk!\n");
            fprintf(log, "Load: %d %% -> ALERT: Overload risk\n", load);
        } else {
            printf("STATUS: Load within safe range\n");
            fprintf(log, "Load: %d %% -> Safe\n", load);
        }

        fprintf(log, "--------------------------\n");
        fclose(log);

        // wait 2 seconds before next cycle
        Sleep(2000);
    }

    return 0;
}
