#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct Array {
  /* 16 bytes for this array? */
  int capacity;  // How many elements can this array hold?
  int count;  // How many states does the array currently hold?
  /* pointer is eight bytes*/
  char **elements;  // The string elements contained in the array
} Array;


/************************************
 *
 *   CREATE, DESTROY, RESIZE FUNCTIONS
 *
 ************************************/
/* char hello[5]; */
/*****
 * Allocate memory for a new array
 *****/
Array *create_array (int capacity) {
  Array *newArray = malloc(sizeof(Array));
  newArray->capacity = capacity;
  newArray->count = 0;
  /* newArray->elements = elements[capacity]; */
  newArray->elements = malloc(capacity * sizeof(newArray->elements));

  return newArray;
  // Allocate memory for the Array struct

  // Set initial values for capacity and count

  // Allocate memory for elements

}


/*****
 * Free memory for an array and all of its stored elements
 *****/
void destroy_array(Array *arr) {
  for(int i =0; i<arr->count; i++) {
    free(arr->elements[i]);
  }
  free(arr->elements);
  free(arr);
  /* might need a loop here? */
  // Free all elements

  // Free array

}

/*****
 * Create a new elements array with double capacity and copy elements
 * from old to new
 *****/
void resize_array(Array *arr) {



  // Create a new element storage with double capacity

  // Copy elements into the new storage

  // Free the old elements array (but NOT the strings they point to)

  // Update the elements and capacity to new values

}



/************************************
 *
 *   ARRAY FUNCTIONS
 *
 ************************************/

/*****
 * Return the element in the array at the given index.
 *
 * Throw an error if the index is out of range.
 *****/
char *arr_read(Array *arr, int index) {
  if (index >= arr->count) {
    printf("Error: index out of range");
    return NULL;
  }

  return arr->elements[index];

  // Throw an error if the index is greater or equal to than the current count

  // Otherwise, return the element at the given index
}


/*****
 * Insert an element to the array at the given index
 *****/
void arr_insert(Array *arr, char *element, int index) {
  if(index > arr->capacity) {
    printf("Error: index out of range\n");
  } else if(arr->count +1 > arr->capacity) {

  } else {
    for(int i = index; i < arr->count + 1 ; i++) {
      arr->elements[i + 1] = arr->elements[i]
    }
    char *new_element strdup(element);
    arr->elements[index] = new_element;
    arr->count++;
    for(int i = index; arr->count; i++) {
      /* start the index. */
    /* printf("should be a new element"); */

    arr->count++;
    printf("new count %d\n", arr->count);
  }
  /* copy all the elements to a temp array */
  /* if the old capacity is less than the capacity of the capacity with the new elements, then resize the array. */
  /* Move every element after the insert index to the right one position. */
  /* copy the element and add it to the array */
  /* increment the count by one. */

}

  // Throw an error if the index is greater than the current count

  // Resize the array if the number of elements is over capacity

  // Move every element after the insert index to the right one position

  // Copy the element and add it to the array

  // Increment count by 1

}

/*****
 * Append an element to the end of the array
 *****/
void arr_append(Array *arr, char *element) {
  /* To append. Take the pointer pointer and write in the new element. */
  if(arr->capacity < arr->count + 1) {
    fprintf(stderr, "appending failed. Resize not implemented yet.");
  } else {
    char *new_element = malloc(strlen(element) * sizeof(char));
    int length = strlen(element) + 1;
    for( int i = 0; i<length; i ++ ) {
      new_element[i] = element[i];
    }
    arr->elements[arr->count] = new_element;
    arr->count++;
  }

  /* how to find the length of a pointer */

    arr->count++;
    /* I think we have to put the element at the end of the memory block in the arr? */
  }
  // Resize the array if the number of elements is over capacity
  // or throw an error if resize isn't implemented yet.
  // Copy the element and add it to the end of the array

  // Increment count by 1



/*****
 * Remove the first occurence of the given element from the array,
 * then shift every element after that occurence to the left one slot.
 *
 * Throw an error if the value is not found.
 *****/
void arr_remove(Array *arr, char *element) {

  // Search for the first occurence of the element and remove it.
  // Don't forget to free its memory!

  // Shift over every element after the removed element to the left one position

  // Decrement count by 1

}


/*****
 * Utility function to print an array.
 *****/
void arr_print(Array *arr) {

  for (int i = 0 ; i < arr->count ; i++) {
    printf("%s", arr->elements[i]);
    if (i != arr->count - 1) {
      printf(",");
    }
  }
  printf("]\n");
}


#ifndef TESTING
int main(void)
{

  Array *arr = create_array(1);

  arr_insert(arr, "STRING1", 0);
  arr_append(arr, "STRING4");
  arr_insert(arr, "STRING2", 0);
  arr_insert(arr, "STRING3", 1);
  arr_print(arr);
  arr_remove(arr, "STRING3");
  arr_print(arr);

  destroy_array(arr);

  return 0;
}
#endif
