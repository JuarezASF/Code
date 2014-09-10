#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
#include "read_data.h"


typedef enum { false, true } bool;

int *merge(int *left, int size_left, int *right, int size_right);
int *my_merge_sort(int *input_array, int num);
void print_array(int *array, int size);
bool compare(int a, int b);

/* 
 * Takes a file name as input from command line
 * which contains array of integers. These are
 * sorted either in ascending order or descending
 * order. The array is printed out both pre- and 
 * post-sort.
 *
 * DO NOT EDIT THIS MAIN FUNCTION 
 */
int main(int argc, char **argv)
{
	int i;
    int num;
	int to_sort_array[MAX_NUM];
	int sorted_array[MAX_NUM];
	
	if (argc != 2) {
		perror("Input arguments are not correct.\n");
		return 1;
	}

	/* Fill the input array */
	num = fillInput(to_sort_array, argv[1]);
	if (num <= 0) {
		perror("Data initilization error.\n");
		return 1;
	}

	/* Print input and sort */
	printf("Unsorted array:\t");
	for (i = 0; i < num; i++) {
		printf("%d ",to_sort_array[i]);
	}

	printf("\n");

	merge_sort(to_sort_array, sorted_array, num);

#ifdef DSC
	printf("Sorted (descending) array: ");
#elif ASC
	printf("Sorted (ascending) array: ");
#endif
	for (i = 0; i < num; i++) {//num is the size of the array
		printf("%d ",sorted_array[i]);
	}
	printf("\n");
	return 0;
}

/*
 * merge_sort:
 *		organizes the vector in the defined order. input_array and
 output_array must both be already allocated. In order to gain more
 freedom when dealing with vector, I convert the input into a dynamically
 allocated array and then pass the input to the function that really 
 does the ordering. 
 */
void  merge_sort(int input_array[], int output_array[], int num)
{
	int i;
	int *my_input, *my_output;

	my_input = (int *)malloc(num*sizeof(int));//malloc 1

	for(i =0; i < num; i++)
		my_input[i] = input_array[i];
	
	//do the actual ordering
	my_output = my_merge_sort(my_input, num);

	//copy the results to the required output
	for(i =0; i < num; i++)
		output_array[i] = my_output[i];

	free(my_input);//free malloc 1
	free(my_output);//free malloc 5

}

//Function used on debug stage
void print_array(int *array, int size){
	int i;
	for(i=0; i < size; i++)
		printf("%d\t", array[i]);

	printf("\n");
}

//do the actual sorting
int *my_merge_sort(int *input_array, int num)
{
	int *output_array;
	if(num == 1){//check for trivial case
		output_array = (int *)malloc(1*sizeof(int));//malloc 2
		output_array[0] = input_array[0];
		return output_array;
	}
	int *left, *right, *sorted_left, *sorted_right;
	int size_left, size_right, middle, i;

	//calculate sizes to be used
	middle = (int)(num/2.0 + 0.5); //round up the left size(my choice)
	size_left = middle;
	size_right = num - size_left;

	//allocate left and right sub-vectors
	left  = (int *)malloc(size_left*sizeof(int));//malloc 3
	right = (int *)malloc(size_right*sizeof(int));//malloc 4

	//define left and right sub-vectors
	for(i = 0; i<size_left; i++)
		left[i] = input_array[i];
	for(i = size_left; i<num; i++)
		right[i - size_left] = input_array[i];

	//sorte each sub-vector
	sorted_left = my_merge_sort(left, size_left);
	sorted_right = my_merge_sort(right, size_right);

	output_array = merge(sorted_left, size_left, sorted_right, size_right);

	free(left);//free malloc 2,3
	free(right);//free malloc 2,4
	free(sorted_left);//free malloc 5
	free(sorted_right);//free malloc 5

	return output_array;
}

// merge the two vectors according to the sorting rule 
int * merge(int *left, int size_left, int *right, int size_right){
	int *result = (int *)malloc((size_left+size_right)*sizeof(int));//malloc 5
	int right_index, left_index, result_index;

	left_index = right_index = result_index = 0;

	while(size_left>0 || size_right>0){
		if(size_left>0 && size_right>0){
			if(compare(left[left_index],right[right_index]))
			{
				result[result_index] = left[left_index];
				result_index++;
				left_index++;
				size_left--;
			}
			else
			{
				result[result_index] = right[right_index];
				result_index++;
				right_index++;
				size_right--;
			}
		}else if(size_left > 0)
			{
			result[result_index] = left[left_index];
			result_index++;
			left_index++;
			size_left--;
			}
		else if(size_right > 0){
			result[result_index] = right[right_index];
			result_index++;
			right_index++;
			size_right--;
		}
	}

	return result;
}

#ifdef DSC
	bool compare(int a, int b){
		return (a<=b)? true:false;
	}
#elif ASC
	bool compare(int a, int b){
		return (a>=b)? true:false;
	}
#else
	bool compare(int a, int b){
		return (a<=b)? true:false;
	}
#endif
