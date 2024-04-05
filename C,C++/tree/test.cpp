#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "exptree.h"
int main()
{
    char exp[100];
    printf("\n Enter the expression");
	scanf("%s",exp);
    constructexpressiontree(exp);
}