#include "sort.h"

/**
 * swap - swithces two elements in array
 * @a: an element to be swapped
 * @b: other element to be swapped
 * Return: none
 */

void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * heapify - making binary heap
 * @arr: array
 * @n: size of array (as int)
 * @i: size of subarray
 * @size: size of array (size_t)
 * Return: none
 */

void heapify(int arr[], int n, int i, size_t size)
{
	int max = i;
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;

	if (leftChild < n && arr[leftChild] > arr[max])
		max = leftChild;

	if (rightChild < n && arr[rightChild] > arr[max])
		max = rightChild;

	if (max != i)
	{
		swap(&arr[i], &arr[max]);
		print_array(arr, size);
		heapify(arr, n, max, size);
	}
}


/**
 * heap_sort - heap sort
 * @array: array to be sorted
 * @size: size of array
 * Return: none
 */

void heap_sort(int *array, size_t size)
{
	int i, n = size;

	for (i = n / 2 - 1; i >= 0; i--)
		heapify(array, n, i, size);

	for (i = n - 1; i >= 0; i--)
	{
		if (i != 0)
		{
			swap(&array[0], &array[i]);
			print_array(array, size);
			heapify(array, i, 0, size);
		}
	}
}
