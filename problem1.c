//
// Created by Zuhair on 7/3/2025.
//
#include <stdio.h>
// SET A
// SPRING 2024 Problem 1
#define SIZE 256
void removeSpecialCharacters (char str[]);
char changeAlphabet (char alphabet);
void encoder (char* p);

int main (void)
{
    char input[SIZE];
    printf("Enter the string: ");
    fgets(input, SIZE, stdin);

    encoder(input);
    printf("Encoded String: %s\n", input);

    return 0;
}

void removeSpecialCharacters (char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!(str[i] >= 'A' && str[i] <= 'Z') && !(str[i] >= 'a' && str[i] <= 'z'))
        {
            str[i] = ' ';
        }
    }
}

char changeAlphabet (char alphabet)
{
    if (alphabet >= 'A' && alphabet <= 'Z')
    {
        return 'Z' -  (alphabet - 'A');
    }

    else if (alphabet >= 'a' && alphabet <= 'z')
    {
        return 'z' -  (alphabet - 'a');
    }

    else
        return alphabet;
}

void encoder (char* p)
{
    removeSpecialCharacters(p);
    for (int i = 0; p[i] != '\0'; i++)
    {
        p[i] = changeAlphabet(p[i]);
    }
}