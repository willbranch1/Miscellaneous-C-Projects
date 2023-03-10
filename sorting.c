/*
Program reads integers into an array and uses a sorting method to sort them from smallest to largest. 
Demonstrates knowledge of array manipulation and sorting algorithms.
*/

#include <stdio.h>
#include <stdlib.h>

//my_sort method initialization
void my_sort(int *array, int capacity);

int main() {
  //scan in the length of the array as the first digit entered by the user
  int length;
  printf("input: ");
  scanf("%d", &length);
  
  //check to make sure the first number entered is not a negative number
  //if the length is zero, however, print a new line and end the program
  if (length < 0) {
    fprintf(stderr, "Cannot accept negative integer as array size.\n");
    return 1;
  } else if (length == 0) {
    printf("\n");
    return 0;
  }
  
  //create a pointer for the array
  int *arr = malloc(length * sizeof(int));
  
  //cycle through the rest of the integers that were inputted
  int i;
  for (i = 0; i < length; i++) {
    scanf("%d", &arr[i]);
  }
  
  //call the sorting algorithm to sort the array
  my_sort(arr, length);
  
  //cycle through the array and print each of the elements
  printf ("output: ");
  for (i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  
  //release the memory that was acquired with malloc()
  free(arr);
  
  //necessary return statement
  return 0;
}

void my_sort(int *array, int capacity) {
  //variables used for keeping track of the loops
  int i, j, start;
  //use a for loop to cycle through each element in the array
  for (i = 1; i < capacity; i++) {
    start = array[i];
    j = i - 1;
    //use a while loop to compare the current element to all previous elements
    while (j >= 0 && array[j] > start) {
      array[j + 1] = array[j];
      j = j - 1;
    }
    array[j + 1] = start;
  }
}
