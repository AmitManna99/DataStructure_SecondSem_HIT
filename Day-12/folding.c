#include<stdio.h>
#include "separate_chain.c"

int calHash(Node**, int, int);

int main()
{
    int tab_size,i;
    long int key;
    Node **tab;
    printf("\nEnter the table size : ");
    scanf("%d",&tab_size);

    printf("\nEnter the Hash-Key : ");
    scanf("%d",&key);

    tab = (Node**)malloc(tab_size * sizeof(Node*));

    for(i = 0; i<tab_size; i++)
        *(tab+i) = NULL;
    
    printf("\nThe Hashed Index is %d\n",calHash(tab,tab_size,key));

    return 0;
}

int calHash(Node **tab, int n, int key)
{
    int iHash=0, blockSize = 2;

    while(key!=0)
    {
        iHash += key %10;
        key/=10;
    }

    if(iHash>=n)
        iHash = iHash%n;
    
    *(tab+iHash) = create(*(tab+iHash), iHash);

    return iHash;
}


/*
================ OUTPUT ================

Enter the table size : 50

Enter the Hash-Key : 12546587

The Hashed Index is 38

** Explaination : 1+2+5+4+6+5+8+7 = 38 **
*/