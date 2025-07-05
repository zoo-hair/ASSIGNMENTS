//
// Created by Zuhair on 7/4/2025.
//
/*
 *  Hospital management system
 */
#include <stdio.h>
#include <string.h>

#define MAX_PATIENTS 100
#define LIMIT 50

struct Patient {
    char name[MAX_PATIENTS];
    int age;
    char gender;
    long id;
    char condition[LIMIT];
};

void add_patients (struct Patient list_of_patients[], int* num_of_patients);
void search_by_id (struct Patient list_of_patients[],int num_of_patients, long input_id);
void update_conditions (struct Patient list_of_patients[], int num_of_patients, long input_id);
void display_patients (struct Patient list_of_patients[], int num_of_patients);


int main (void)
{
    struct Patient list_of_patients[MAX_PATIENTS];
    int num_of_patients = 0;
    int choice;
    long id, search;

    printf("Hospital Patient Management System: \n");
    printf("1. Add a new patient\n");
    printf("2. Search for a patient\n");
    printf("3. Update a patient's condition\n");
    printf("4. Display all patients\n");
    printf("5. Exit\n");

    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1:
            {
                add_patients(list_of_patients, &num_of_patients);
                break;
            }

            case 2:
            {

                printf("Enter patient ID to search: ");
                scanf("%ld", &search);

                search_by_id(list_of_patients, num_of_patients, search);
                break;
            }

            case 3:
            {
                printf("Enter patient ID to update: ");
                scanf("%ld", &search);

                update_conditions(list_of_patients, num_of_patients, search);
                break;
            }

            case 4:
            {
                display_patients(list_of_patients, num_of_patients);
                break;
            }

            case 5:
            {
                printf("Thanks for using my software\n");

                return 0;
            }

                default:
                printf("Wrong choice.\n");

        }
    }
    return 0;
}

void add_patients (struct Patient list_of_patients[], int* num_of_patients)
{
    if (*num_of_patients >= MAX_PATIENTS)
    {
        printf("Cannot add more patients. Maximum limit reached.\n");

        return;
    }

    struct Patient new_patient;
    printf("Enter patient name: ");
    gets(new_patient.name);

    printf("Enter age: ");
    scanf("%d", &new_patient.age);
    getchar();

    printf("Enter gender (M/F): ");
    scanf("%c", &new_patient.gender);
    getchar();

    printf("Enter ID: ");
    scanf("%ld", &new_patient.id);
    getchar();

    printf("Enter condition: ");
    gets(new_patient.condition);

    list_of_patients[*num_of_patients] = new_patient;
    (*num_of_patients)++;

    printf("The Patient added successfully.\n");
}

void search_by_id (struct Patient list_of_patients[],int num_of_patients, long input_id)
{
    if (num_of_patients == 0)
    {
        printf("No patients are registered as of now\n");
        return;
    }

    int found = 0;

    for (int i = 0; i < num_of_patients; i++)
    {
        if (input_id == list_of_patients[i].id)
        {
            printf("Patient Records: \n");
            printf("ID: %ld, Name: %s, Age: %d, Gender: %c, Condition: %s\n", list_of_patients[i].id, list_of_patients[i].name, list_of_patients[i].age, list_of_patients[i].gender, list_of_patients[i].condition);
            found ++;
            break;
        }
    }

    if (found == 0)
    {
        printf("No patient found with ID : %ld\n", input_id);
    }
}

void update_conditions (struct Patient list_of_patients[], int num_of_patients, long input_id)
{
    if (num_of_patients == 0)
    {
        printf("There are no existing Data to update.\n");
        return;
    }

    int found = 0;

    for (int i = 0; i < num_of_patients; i++)
    {
        if (input_id == list_of_patients[i].id)
        {
            getchar();
            printf("Enter new condition: ");
            gets(list_of_patients[i].condition);
            printf("Condition updated successfully.\n");
            found++;
            break;
        }
    }

    if (found == 0)
    {
        printf("No patient found with ID: %ld\n", input_id);
    }
}

void display_patients (struct Patient list_of_patients[], int num_of_patients)
{
    if (num_of_patients == 0)
    {
        printf("No Available patients\n");
        return;
    }

    printf("\nPatient records:\n");

    for (int i = 0; i < num_of_patients; i++)
    {
        printf("ID : %ld, ",list_of_patients[i].id);
        printf("Name : %s, ",list_of_patients[i].name);
        printf("Age : %d, ",list_of_patients[i].age);
        printf("Gender: %c, ",list_of_patients[i].gender);
        printf("Condition : %s, ",list_of_patients[i].condition);
        printf("\n\n");
    }
}
