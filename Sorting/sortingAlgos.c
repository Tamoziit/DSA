#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXROWS 100

int *improvedBubbleSort(int *arr, int n)
{
	int bound = n - 1;
	int i, j, k, t;
	do
	{
		k = 0;
		for (j = 0; j < bound; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
				k = j;
			}
		}
		bound = k;
	} while (k > 0);

	return arr;
}

int *insertionSort(int *arr, int n)
{
	int i, j, k;
	for (i = 1; i < n; i++)
	{
		k = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > k)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = k;
	}

	return arr;
}

int *selectionSort(int *arr, int n)
{
	int i, j, k, t;
	for (i = 0; i < n - 1; i++)
	{
		j = i;
		for (k = i + 1; k < n; k++)
		{
			if (arr[k] < arr[j])
				j = k;
		}
		t = arr[j];
		arr[j] = arr[i];
		arr[i] = t;
	}

	return arr;
}

int *cocktailShakerSort(int *arr, int n)
{
    int swapped = 1; // To track if a swap happened
    int start = 0;
    int end = n - 1;
	int i, temp;

    while (swapped)
    {
        swapped = 0;

        // Forward pass: move the largest element to the end
        for (i = start; i < end; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }

        // If no elements were swapped, the array is sorted
        if (!swapped)
            break;

        // Reset the swapped flag for the backward pass
        swapped = 0;

        // Move the end pointer one element back, as the last element is in place
        end--;

        // Backward pass: move the smallest element to the start
        for (i = end - 1; i >= start; i--)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }

        // Move the start pointer one element forward, as the first element is in place
        start++;
    }

	return arr;
}

int *maxHeapify(int *arr, int i, int size)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int max, t;

	// Compare left child with current node
	if (l < size && arr[l] > arr[i])
		max = l;
	else
		max = i;

	// Compare right child with max of current and left child
	if (r < size && arr[r] > arr[max])
		max = r;

	// If the current node is not the largest, swap with the largest child
	if (max != i)
	{
		t = arr[i];
		arr[i] = arr[max];
		arr[max] = t;
		maxHeapify(arr, max, size); // Heapify the affected subtree
	}

	return arr;
}

int *buildMaxHeap(int *arr, int size)
{
	int i;
	// Start from the last non-leaf node and heapify down to the root
	for (i = size / 2 - 1; i >= 0; i--)
	{
		arr = maxHeapify(arr, i, size);
	}

	return arr;
}

int *heapSort(int *arr, int n)
{
	arr = buildMaxHeap(arr, n); // Build a max heap
	int i, t;

	// Extract elements one by one from the heap
	for (i = n - 1; i >= 1; i--)
	{
		// Move the root of the max heap (largest element) to the end
		t = arr[0];
		arr[0] = arr[i];
		arr[i] = t;

		n--;						 // Reduce heap size
		arr = maxHeapify(arr, 0, n); // Heapify the reduced heap
	}

	return arr;
}

void printArr(int *arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int *arr = (int *)malloc(MAXROWS * sizeof(int));
	int ele, ch, x = 0;
	printf("Enter the elements of the array. Press -1 to stop.\n");
	while (1)
	{
		scanf("%d", &ele);
		arr[x++] = ele;
		printf("Continue? ");
		scanf("%d", &ch);
		if (ch == -1)
			break;
	}

	printf("The Array\n");
	printArr(arr, x);

	printf("Enter\n 1. Improved Bubble Sort\n 2. Insertion Sort\n 3. Selection Sort\n 4. Cocktail Shaker Sort\n 5. Heap Sort\n 6. Count Sort\n 7. Exit\n");
	scanf("%d", &ch);
	switch (ch)
	{
	case 1:
		printf("Sorted Array:\n");
		arr = improvedBubbleSort(arr, x);
		printArr(arr, x);
		break;
	case 2:
		printf("Sorted Array:\n");
		arr = insertionSort(arr, x);
		printArr(arr, x);
		break;
	case 3:
		printf("Sorted Array:\n");
		arr = selectionSort(arr, x);
		printArr(arr, x);
		break;
	case 4:
		printf("Sorted Array:\n");
		arr = cocktailShakerSort(arr, x);
		printArr(arr, x);
		break;	
	case 5:
		printf("Sorted Array:\n");
		arr = heapSort(arr, x);
		printArr(arr, x);
		break;
	case 7:
		printf("EOP\n");
		exit(0);
	default:
		printf("Wrong choice!\n");
	}

	return 0;
}