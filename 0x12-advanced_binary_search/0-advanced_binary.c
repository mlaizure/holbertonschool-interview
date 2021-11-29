#include "search_algos.h"

int bin_search(int *array, int value, size_t left, size_t right);
void print_array(int *array, size_t left, size_t right);
/**
 * advanced_binary - searches array of ints with binary search
 * @array: pointer to array to search
 * @size: number of elements in array
 * @value: value to search for
 * Return: first index where value is located or -1 on failure
 */

int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size <= 0)
		return (-1);
	return (bin_search(array, value, 0, size - 1));
}


/**
 * bin_search - recursive binary search
 * @array: pointer to array to search
 * @value: value to search for
 * @left: low index of array to search
 * @right: high index of array to search
 * Return: first index where value is located or -1 on failure
 */

int bin_search(int *array, int value, size_t left, size_t right)
{
	size_t mid = (left + right) / 2;

	if (left <= right)
	{
		if (array[mid] == value)
		{
			print_array(array, left, right);
			if (mid != 0)
				if (array[mid - 1] == value)
					return (bin_search(array, value,
							   left, mid));
			return (mid);
		}
		if (array[mid] < value)
		{
			print_array(array, left, right);
			return (bin_search(array, value, mid + 1, right));
		}
		else
		{
			print_array(array, left, right);
			return (bin_search(array, value, left, mid));
		}
	}
	return (-1);
}


/**
 * print_array - prints an array
 * @array: array to print
 * @left: low index of array to print
 * @right: high index of array to print
 * Return: none
 */

void print_array(int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");

	for (i = left; i <= right; ++i)
	{
		if (i < right)
			printf("%d, ", array[i]);
		else
			printf("%d\n", array[i]);
	}
}
