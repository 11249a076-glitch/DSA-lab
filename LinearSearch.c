//Aim:To find required element using linear search
#include<stdio.h>

int main()
{
    int n, key, i, found = 0;

    // Ask user for number of elements in the array
    printf("enter how many elements do you want to store:\n");
    scanf("%d", &n);

    // Declare an array of size n
    int a[n];

    // Input array elements
    printf("\n enter the %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Ask user for the key value to search
    printf("\n enter the key value to search:\n");
    scanf("%d", &key);

    // Linear search: check each element
    for(i = 0; i < n; i++)
    {
        // If the key matches the current element
        if(key == a[i])
        {
            printf("\nkey found at index %d\n", i);
            found = 1;  // Mark that key is found
        }
    }

    // If key was never found
    if(found == 0)
    {
        printf("\nkey not found");
    }
}
