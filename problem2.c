//
// Created by Zuhair on 7/3/2025.
//
// SET A
// SPRING 2024 Problem 2
#include <stdio.h>
#include <string.h>

#define MAX_TRAINS 100
struct Train {
    char name[50];
    int totalTickets;
    float ratings;
};

void addTrain(struct Train list_of_trains[], int* num_of_trains);
void mostPopularTrain(struct Train list_of_trains[], int num_of_trains);
void displayAllTrains(struct Train list_of_trains[], int num_of_trains);

int main (void)
{
    struct Train list_of_trains[MAX_TRAINS];
    int num_of_trains = 0;
    int choice;

    while (1)
    {
        printf("1. Add Train\n");
        printf("2. Find most popular train\n");
        printf("3. Display all trains\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                addTrain(list_of_trains, &num_of_trains);
                break;
            }
            case 2:
            {
                mostPopularTrain(list_of_trains, num_of_trains);
                break;
            }
            case 3:
            {
                displayAllTrains(list_of_trains, num_of_trains);
                break;
            }
            case 4:
            {
                printf("Exiting the program. Goodbye!\n");
                return 0;
            }
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void addTrain (struct Train list_of_Trains[], int* num_of_trains)
{
    if (*num_of_trains >= MAX_TRAINS)
    {
        printf("Cannot add more trains. Maximum limit reached.\n");

        return;
    }
    struct Train new_train;
    printf("Enter train name: ");
    scanf("%s", new_train.name);

    printf("Enter total tickets: ");
    scanf("%d", &new_train.totalTickets);

    printf(("Enter ratings: "));
    scanf("%f", &new_train.ratings);

    list_of_Trains[*num_of_trains] = new_train;
    (*num_of_trains)++;

    printf("Train added successfully!\n");
}

void mostPopularTrain(struct Train list_of_trains[], int num_of_trains)
{
    if (num_of_trains == 0)
    {
        printf("No trains available to analyze.\n");
        return;
    }

    int max_tickets = list_of_trains[0].totalTickets;
    int index = 0;

    for (int i = 1; i < num_of_trains; i++)
    {
        if (list_of_trains[i].totalTickets > max_tickets)
        {
            max_tickets = list_of_trains[i].totalTickets;
            index = i;
        }
    }
    printf("The Most Popular Train: %s\n", list_of_trains[index].name);
}

void displayAllTrains(struct Train list_of_trains[], int num_of_trains)
{
    if (num_of_trains == 0)
    {
        printf("No trains available to display.\n");
        return;
    }

    printf("\nList of Trains\n");

    for (int i = 0; i <num_of_trains; i++)
    {
        printf("Train : %d\n", i + 1);
        printf("Name : %s\n", list_of_trains[i].name);
        printf("Total Tickets : %d\n", list_of_trains[i].totalTickets);
        printf("Ratings : %.2f\n\n", list_of_trains[i].ratings);
    }
}
