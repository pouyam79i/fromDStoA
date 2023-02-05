/**
  An array is a collection of items stored at contiguous memory locations. 
  The idea is to store multiple items of the same type together. 
  This makes it easier to calculate the position of each element by simply adding an offset to a base value, i.e., 
  the memory location of the first element of the array (generally denoted by the name of the array).

  Advantages:
    Code Optimization:  we can retrieve or sort the data efficiently.
    Random access: We can get any data located at an index position.
 
  Disadvantages:
    Size Limit: We can store only the fixed size of elements in the array. It doesn’t grow its size at runtime. 

*/


#include <stdio.h>

// Initializing an array with a fixed size of 100
int myArray[100];

int main(void) {
  printf("Hello World!");

  // Setting value for all entities!
  for(int i = 0; i < 100; i++)
    myArray[i] = i;

  // updating one entity
  myArray[19] = 20;

  for(int i = 0; i < 100; i++)
    printf("This is %d index with value: %d\n", i, myArray[i]);

  return 0;
}
