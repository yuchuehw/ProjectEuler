#include <stdio.h>
#include <time.h>

int main() {
    int counter = 0;

    for (int year = 1901; year <= 2000; year++) {
        for (int month = 1; month <= 12; month++) {
            struct tm time_struct;
            char date_str[20];

            sprintf(date_str, "%d/1/%d", month, year);

            if (strptime(date_str, "%m/%d/%Y", &time_struct) != NULL &&
                time_struct.tm_wday == 6) {
                counter++;
            }
        }
    }

    printf("%d\n", counter);

    return 0;
}
