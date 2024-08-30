#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char input[100];
    printf("\n Enter the string:\n");
    scanf("%s",input);
    int strlength = strlen(input);
    int substrlength;
    printf("\n Enter the substring length:\n");
    scanf("%d",&substrlength);
    int substrcount = strlength - substrlength + 1;
    printf("\nThere are %d possible substrings of size %d: ", substrcount, substrlength);
    for(int i=0;i<strlength-(substrlength-1);i++)
    {
        char substr[substrlength];
        for(int j=0;j<substrlength;j++)
        {
            substr[j] = input[i+j];
        }
        printf("%s ",substr);
    }
}