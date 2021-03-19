#include <stdio.h>
#include <stdlib.h>

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r, int c)
{
    int i, j, k, n1 = m - l + 1, n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (c == 1)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
        }
        if (c == 2)
        {
            if (L[i] >= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r, int c)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
        // left to middle
        mergeSort(arr, l, m, c);
        // middle to right
        mergeSort(arr, m + 1, r, c);

        merge(arr, l, m, r, c);
    }
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArr(int A[], int size)
{
    FILE *myFile;
    myFile = fopen("output.txt", "w");
    for (int i = 0; i < size; i++)
        fprintf(myFile, "%d ", A[i]);
    printf("\n");
    fclose(myFile);
}

void main()
{
    int arr[1000], c = 0, n = 0, num;
    FILE *myFile;
    myFile = fopen("input.txt", "r");
    while (fscanf(myFile, "%d", &num) == 1)
    {
        arr[n] = num;
        n++;
    }
    fclose(myFile);
    char ch;
    system("cls");
start:
    printf("Merge Sort Program\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("3. Exit\n");
    printf("================================\n");
    printf("Enter your choice : \t");
    scanf("%d", &c);

    switch (c)
    {
    case 1:
        mergeSort(arr, 0, n - 1, c);
        printf("Sorted array in output.txt");
        printArr(arr, n);
        break;
    case 2:
        mergeSort(arr, 0, n - 1, c);
        printf("Sorted array in output.txt");
        printArr(arr, n);
        break;
    case 3:
        exit(1);
    default:
        printf("\nWrong Choice");
        break;
    }
    printf("\nDo you wish to continue?(y/n) : ");
    fflush(stdin);
    scanf("%c", &ch);
    if (ch == 'y' || ch == 'Y')
        goto start;
}