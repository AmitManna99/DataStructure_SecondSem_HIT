#include <stdio.h>
#include <math.h>
#include "separate_chain.c"

int calHash(Node **, int, int);
int calDigit(int);

int main()
{
    int tab_size, i;
    long int key;
    Node **tab;
    printf("\nEnter the table size : ");
    scanf("%d", &tab_size);

    printf("\nEnter the Hash-Key : ");
    scanf("%d", &key);

    tab = (Node **)malloc(tab_size * sizeof(Node *));

    for (i = 0; i < tab_size; i++)
        *(tab + i) = NULL;

    printf("\nThe Hashed Index is %d\n", calHash(tab, tab_size, key));

    return 0;
}

int calHash(Node **tab, int n, int key)
{
    int iHash = 0, i = 0, blockSize = 2;
    int arr[100];

    int key_len = calDigit(key);
    int len = abs(key_len - calDigit(n));

    while (key != 0)
    {
        arr[i] = key % 10;
        key /= 10;
        i++;
    }

    for (i = (i - ceil(len / 2) - 1); i >= floor(len / 2); i--)
        iHash = iHash * 10 + arr[i];

    if (iHash >= n)
        iHash = iHash % n;

    *(tab + iHash) = create(*(tab + iHash), iHash);

    return iHash;
}

int calDigit(int num)
{
    int i = 0;
    while (num != 0)
    {
        num /= 10;
        i++;
    }

    return i;
}

/*
================ OUTPUT ================

Enter the table size : 50

Enter the Hash-Key : 134564

The Hashed Index is 45
*/