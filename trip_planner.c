#include <stdio.h>
#include <string.h>

// Function to get the destination
void getDestination(char *destination) {
    printf("Enter your destination: ");
    scanf("%s", destination);
}

// Function to get trip dates
void getDates(char *startDate, char *endDate) {
    printf("Enter the start date (YYYY-MM-DD): ");
    scanf("%s", startDate);
    printf("Enter the end date (YYYY-MM-DD): ");
    scanf("%s", endDate);
}

// Function to get trip activities
void getActivities(char activities[5][100]) {
    printf("Enter your trip activities (max 5 activities):\n");
    for (int i = 0; i < 5; i++) {
        printf("Activity %d: ", i + 1);
        scanf(" %[^\n]%*c", activities[i]);
        if (i < 4) {
            printf("Do you want to add another activity? (yes/no): ");
            char choice[3];
            scanf("%s", choice);
            if (strcmp(choice, "no") == 0) {
                break;
            }
        }
    }
}

// Function to print the trip itinerary
void printItinerary(char *destination, char *startDate, char *endDate, char activities[5][100]) {
    printf("\n--- Trip Itinerary ---\n");
    printf("Destination: %s\n", destination);
    printf("Trip Dates: %s to %s\n", startDate, endDate);
    printf("Activities:\n");
    for (int i = 0; i < 5; i++) {
        if (strlen(activities[i]) > 0) {
            printf("- %s\n", activities[i]);
        }
    }
}

int main() {
    char destination[100];
    char startDate[11], endDate[11];
    char activities[5][100] = {0};

    // Get trip details
    getDestination(destination);
    getDates(startDate, endDate);
    getActivities(activities);

    // Print the itinerary
    printItinerary(destination, startDate, endDate, activities);

    return 0;
}
