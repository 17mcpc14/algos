#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

char * one_digits[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
char * two_digits[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "ninteen"};
char * tens_digits[] = { "", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninty"};
char * multiplier_digits[] = { "hundred", "thousand", "lakh", "crore"};
long multiplier_nums[] = { 100, 1000, 100000, 10000000};

long find_digits(char * word)
{
    int i =0;
    for(i=0; i<10;i++)
    {
        if(strcmp(word, one_digits[i]) == 0)
        {
            return i;
        }
        else if(strcmp(word, two_digits[i]) == 0)
        {
            return 10+i;
        }
        else if(strcmp(word, tens_digits[i]) == 0)
        {
            return 10*i;
        }
    }
    return -1;
}

long find_multiplier(char * word)
{
    int i =0;
    for(i=0; i<4;i++)
    {
        if(strcmp(word, multiplier_digits[i]) == 0)
        {
            return multiplier_nums[i];
        }
    }
    return -1;
}

int main(int argc, char *argv[])
{
     char * num[10];
     char * input;
     printf("Please input a number in words: ");
     fgets(input, 100, stdin);
     printf("\nInput:%s",input);

     int length= strlen(input);
     int j, last = 0, words_count = -1;
     for (j=0; j<length; j++)
     {
        if (input[j] == ' ' & j!=last)
        {
           char * sub = (char *)malloc(j-last);

           memcpy(sub, &input[last], j-last);
           words_count++;
           num[words_count] = sub;
           last = j+1;

        }
     }
     if(last!=j)
     {
        char * sub = (char *)malloc(j-last-1);
        memcpy(sub, &input[last], j-last-1);
        words_count++;
        num[words_count] = sub;
     }

    if( words_count < 0)
    {
        printf("\n Invalid input!");
        return 0;
    }
    else if( words_count >  9)
    {
        printf("\n Invalid input! Program currently accepts at the max 10 words and can handle maximum input up to (214,74,83,647)");
        return 0;
    }

    long result = 0;
    long temp_result = 0;
    int i;
    for(i=0; i<=words_count;i++)
    {
        long found = find_digits(num[i]);

        if(found != -1)
        {
            temp_result = temp_result + found;
        }
        else{
            found = find_multiplier(num[i]);

            if(found==-1)
            {
                printf("\n Invalid input!Word not recoginized!");
                return 0;
            }
            result = result + (temp_result*found);
            temp_result = 0;
        }
    }
    result = result + temp_result;

    printf("\nResult:%ld",result);
    return 0;
}