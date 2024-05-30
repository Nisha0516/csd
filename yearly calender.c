#include <stdio.h>
int main() {
    int year, month, day, daysInMonth, weekDay = 0, startingDay;
    int isLeapYear, daysInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char *monthNames[] = {"January", "February", "March", "April", "May", "June", 
                          "July", "August", "September", "October", "November", "December"};
    printf("Enter the year: ");
    scanf("%d", &year);
    isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    if (isLeapYear) {
        daysInMonths[1] = 29; // Adjust February days for leap year
    }
    int q = 1;
    int m = 13;
    int K = (year - 1) % 100;
    int J = (year - 1) / 100;
    startingDay = (q + 13*(m+1)/5 + K + K/4 + J/4 + 5*J) % 7;
    startingDay = (startingDay + 6) % 7;
    for (month = 0; month < 12; month++) {
        daysInMonth = daysInMonths[month];
        printf("\n  %s %d\n", monthNames[month], year);
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
        for (weekDay = 0; weekDay < startingDay; weekDay++) {
            printf("     ");
        }
        // Print the days of the month
        for (day = 1; day <= daysInMonth; day++) {
            printf("%5d", day);
            if (++startingDay > 6) {
                startingDay = 0;
                printf("\n");
            }
        }
        if (startingDay != 0) {
            printf("\n");
        }
    }
    return 0;
}
