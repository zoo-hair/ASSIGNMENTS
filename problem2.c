//
// Created by Zuhair on 7/4/2025.
//
/*
 * spell sentence determiner
 */
#include <stdio.h>

#define  LENGTH 100

int number_of_words (char str[]);
int nth_word_length (char str[], int n);
int is_prime (int number);
int is_spell (char str[]);

int main (void)
{
    char string[LENGTH];
    int res;
    printf("Enter a string: ");
    gets(string);
    res = is_spell(string);
    printf("%d\n", res);

    if (res == 1)
    {
        printf("Yes\n");
        return 1;
    }
    else
    {
        printf("No\n");
        return 0;
    }

}

int number_of_words (char str[])
{
    int i = 0, count = 0;

    while (str[i] != '\n')
    {
        if (str[i] == ' ' || str[i] == '.' || str[i] == ',' || str[i] == '!' || str[i] == '?' || str[i] =='\n')
            count++;
        i++;
    }

    return count;
}

int nth_word_length (char str[], int n)
{
    int i = 0, word_count = 0;

    while (str[i] != '\n')
    {
        if (str[i] == ' ' || str[i] == '.' || str[i] == ',' || str[i] == '!' || str[i] == '?' || str[i] =='\n')
            word_count++;

        if (word_count == n)
        {
            int length = 0;

            while (str[i] != ' ' || str[i] != '.' || str[i] != ',' || str[i] != '!' || str[i] != '?' || str[i] !='\n')
            {
                length++;
                i++;
            }
            return length;
        }
        i++;
    }
    return 1;
}

int is_prime (int number)
{
    int count = 0;
    if (number <= 1)
    {
        return 0;
    }

    for (int i = 1; i <= number; i++)
    {
        if (number % i == 0)
        {
            count++;
        }
    }

    if (count == 2)
    {
        return 1;
    }
    else
        return 0;
}

int is_spell (char str[])
{
    int number = 0;
    int prime = 0;
    int words_num = number_of_words(str[LENGTH]);
    int length[words_num];
    for (int i = 0; i < words_num; i++)
    {
        length[i] = nth_word_length(str[words_num],i);
    }

    for (int i = 0; i < words_num; i++)
    {
        number =  number * 10 + length[i];
    }
    prime = is_prime(number);

    if (prime == 1)
    {
        return 1;
    }
    else
        return 0;
}
