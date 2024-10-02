#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXROWS 100

int improvedBubbleSort(int *arr, int n)
{
	int bound = n - 1;
	int i, j, k, t, comps=0;
	do
	{
		k = 0;
		for (j = 0; j < bound; j++)
		{
			comps++;
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

	return comps;
}

int insertionSort(int *arr, int n)
{
	int i, j, k, comps=0;
	for (i = 1; i < n; i++)
	{
		k = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > k)
		{
			comps++;
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = k;
	}

	return comps;
}

int selectionSort(int *arr, int n)
{
	int i, j, k, t, comps=0;
	for (i = 0; i < n - 1; i++)
	{
		j = i;
		for (k = i + 1; k < n; k++)
		{
			comps++;
			if (arr[k] < arr[j])
				j = k;
		}
		t = arr[j];
		arr[j] = arr[i];
		arr[i] = t;
	}

	return comps;
}

int cocktailShakerSort(int *arr, int n)
{
	int swapped = 1; // To track if a swap happened
	int start = 0;
	int end = n - 1;
	int i, temp, comps=0;

	while (swapped)
	{
		swapped = 0;

		// Forward pass: move the largest element to the end
		for (i = start; i < end; i++)
		{
			comps++;
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
			comps++;
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

	return comps;
}

void maxHeapify(int *arr, int i, int size, int *comps)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int max, t;

	// Compare left child with current node
	(*comps)++;
	if (l < size && arr[l] > arr[i])
		max = l;
	else
		max = i;

	// Compare right child with max of current and left child
	(*comps)++;
	if (r < size && arr[r] > arr[max])
		max = r;

	// If the current node is not the largest, swap with the largest child
	if (max != i)
	{
		t = arr[i];
		arr[i] = arr[max];
		arr[max] = t;
		maxHeapify(arr, max, size, comps); // Heapify the affected subtree
	}
}

void buildMaxHeap(int *arr, int size, int *comps)
{
	int i;
	// Start from the last non-leaf node and heapify down to the root
	for (i = size / 2 - 1; i >= 0; i--)
	{
		maxHeapify(arr, i, size, comps);
	}
}

int heapSort(int *arr, int n)
{
	int comps = 0;  // Initialize the comparison counter
	buildMaxHeap(arr, n, &comps); // Build a max heap, passing the address of comps
	int i, t;

	// Extract elements one by one from the heap
	for (i = n - 1; i >= 1; i--)
	{
		// Move the root of the max heap (largest element) to the end
		t = arr[0];
		arr[0] = arr[i];
		arr[i] = t;

		n--;						 // Reduce heap size
		maxHeapify(arr, 0, n, &comps); // Heapify the reduced heap
	}

	return comps;  // Return the total number of comparisons
}

int maxCalc(int *arr, int n) {
	int i, max=arr[0];
	for(i=0; i<n; i++) {
		if(arr[i] > max)
			max = arr[i];
	}

	return max;
}

void countingSort(int *arr, int n) {
	int k = maxCalc(arr, n);
	int *B = (int*)malloc(n * sizeof(int));
	int *C = (int*)malloc((k + 1) * sizeof(int));

	int i, j;

	// Initializing the count array C
	for(i = 0; i <= k; i++) {
		C[i] = 0;
	}

	// Storing the count of each element in C
	for(j = 0; j < n; j++) {
		C[arr[j]]++;
	}

	// Cumulative sum in C to determine the position of elements in sorted order
	for(i = 1; i <= k; i++) {
		C[i] += C[i - 1];  // Cumulative adding
	}

	// Placing elements in the correct position in the output array B
	for(j = n - 1; j >= 0; j--) {
		B[C[arr[j]] - 1] = arr[j];  // Placing at correct position
		C[arr[j]]--;  // Decrement count
	}

	for(i = 0; i < n; i++) {
		arr[i] = B[i];
	}

	// Free allocated memory
	free(B);
	free(C);
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
	int i, *arr, *res, n, ch, comps;
	FILE *f1;
	f1 = fopen("C:\\Users\\Tamojit\\Desktop\\DSA\\sorting\\input.txt", "r");
	if (f1 != NULL)
	{
		fscanf(f1, "%d\n", &n); // extracting the first line from input.txt which stores the size of the arr, in "n"
		arr = (int *)malloc(n * sizeof(int));
		while (!feof(f1))
		{ // checking if the char != f, ie, size of the array, until the end of file
			fscanf(f1, "%d\n", &arr[i]);
			i++;
		}

		printf("The Array\n");
		printArr(arr, n);
	}
	else
	{
		printf("Error in reading the Input file\n");
		exit(0);
	}

	res = (int *)malloc(n * sizeof(int));
	FILE *f2;
	f2=fopen("C:\\Users\\Tamojit\\Desktop\\DSA\\sorting\\output.txt", "w");

	while (1)
	{
		printf("Enter\n 1. Improved Bubble Sort\n 2. Insertion Sort\n 3. Selection Sort\n 4. Cocktail Shaker Sort\n 5. Heap Sort\n 6. Counting Sort\n 7. Exit\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			for(i=0; i<n; i++)
				res[i]=arr[i];
			
			comps = improvedBubbleSort(res, n);
			printArr(res, n);
			printf("No. of Comparisons = %d\n", comps);

			if(f2!=NULL) {
				fprintf(f2, "Improved Bubble Sort\nNo. of Comparison = %d\n", comps);
				for(i=0; i<n; i++)
				{
					fprintf(f2, "%d ", res[i]);
				}
				fprintf(f2, "\n\n");
			}
			break;
		case 2:
			for(i=0; i<n; i++)
				res[i]=arr[i];
			
			comps = insertionSort(res, n);
			printArr(res, n);
			printf("No. of Comparisons = %d\n", comps);

			if(f2!=NULL) {
				fprintf(f2, "Insertion Sort\nNo. of Comparison = %d\n", comps);
				for(i=0; i<n; i++)
				{
					fprintf(f2, "%d ", res[i]);
				}
				fprintf(f2, "\n\n");
			}
			break;
		case 3:
			for(i=0; i<n; i++)
				res[i]=arr[i];
			
			comps = selectionSort(res, n);
			printArr(res, n);
			printf("No. of Comparisons = %d\n", comps);

			if(f2!=NULL) {
				fprintf(f2, "Selection Sort\nNo. of Comparison = %d\n", comps);
				for(i=0; i<n; i++)
				{
					fprintf(f2, "%d ", res[i]);
				}
				fprintf(f2, "\n\n");
			}
			break;
		case 4:
			for(i=0; i<n; i++)
				res[i]=arr[i];
			
			comps = cocktailShakerSort(res, n);
			printArr(res, n);
			printf("No. of Comparisons = %d\n", comps);

			if(f2!=NULL) {
				fprintf(f2, "Cocktail Shaker Sort\nNo. of Comparison = %d\n", comps);
				for(i=0; i<n; i++)
				{
					fprintf(f2, "%d ", res[i]);
				}
				fprintf(f2, "\n\n");
			}
			break;
		case 5:
			for(i=0; i<n; i++)
				res[i]=arr[i];
			
			comps = heapSort(res, n);
			printArr(res, n);
			printf("No. of Comparisons = %d\n", comps);

			if(f2!=NULL) {
				fprintf(f2, "Heap Sort\nNo. of Comparison = %d\n", comps);
				for(i=0; i<n; i++)
				{
					fprintf(f2, "%d ", res[i]);
				}
				fprintf(f2, "\n\n");
			}
			break;
		case 6:
			for(i=0; i<n; i++)
				res[i]=arr[i];
			
			countingSort(res, n);
			printArr(res, n);
			printf("No. of Comparisons = 0\n");

			if(f2!=NULL) {
				fprintf(f2, "Counting Sort\nNo. of Comparison = 0\n");
				for(i=0; i<n; i++)
				{
					fprintf(f2, "%d ", res[i]);
				}
				fprintf(f2, "\n\n");
			}
			break;
		case 7:
			printf("EOP\n");
			exit(0);
		default:
			printf("Wrong choice!\n");
		}
	}

	fclose(f1);
	fclose(f2);

	return 0;
}