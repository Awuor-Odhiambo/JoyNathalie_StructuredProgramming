                                  ASSIGNMENT
      1.	Difference between a normal variable and a pointer
 A variable stores a value and points to nothing while a pointer stores memory address and points to a variable.
To access the memory of a variable, the compiler goes directly to the memory location of the variable while for a pointer the compiler reads the address of the pointer, goes to the address and reads the value there, this is called dereferencing.
In reading a normal variable, the value is copied directly while a pointer, the value stored at the address is read and this value is still linked to original value.
Modifying a normal variable, the value of the variable is the only thing that changes by giving it another value while to modify a pointer, it goes to address stored in the pointer and modifies the value that was initially stored.

       2.	Difference between variable and pointer declaration and definition
Variable declaration and definition
int x;
At this point both declaration and definition takes place. a variable named x is declared since memory allocation also takes place at this point definition takes place
Pointer declaration
int *p;
p is declared as a pointer to an integer and memory is allocated to the pointer.
Pointer definition
int x = 10;
int *p;
p = &x;
Now p points to a real value, p stores the address of x

     3.	DEREFRENCING
Dereferencing means using a pointer to access the value stored at the memory address it holds.
Storing a value in a pointer.
int x = 10;
int *p = &x;
Accessing the value using dereferencing
printf("%d", *p);
  The address stored in p was read, then the compiler goes to that memory location and reads the value there.
Modifying
int x = 10;
int *p = &x;
*p = 20;
Now x equals 20.

     4.	POINTERS OVER VARIABLES
A. When a function must modify the original variable.
•	Normal variables are passed by value (copy)
•	Changes inside a function do not affect the original variable
•	Pointers allow the function to modify the original data
Example: when swapping two numbers.
void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}
The original values remain unchanged
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
swap(&x, &y);
 the original values are modified.
B. When working with large data for efficiency & memory
• Passing large arrays or structures by value is slow
• Pointers avoid copying data
• Only the address is passed
Example: Processing an array
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}
printArray(array, 5);
No copying, fast, memory-efficient
C. When dynamic memory is required
•	Normal variables need fixed size at compile time
•	Pointers allow memory allocation at runtime 
 uses
1.Linked lists
2.Trees
D. When sharing data between multiple functions
•	Multiple functions can work on the same memory
•	Avoids redundant copies
•	Enables global-like behavior safely

     5.Limitations

1.A pointer that is declared but not assigned an address points to random memory and could cause program crashes, data corruption.
2. A pointer continues to point to memory that has been freed or gone out of scope leading to risks such as accessing invalid memory and hard-to-find bugs.
3. Allocated memory is not released due to memory leaks and the risks are wasted memory and program slows or crashes over time.
4. Null pointer dereferencing and the risk is immediate run time errors.
5. Pointer-heavy code is less readable and risks are, logic errors, difficult debugging, more maintenance effort.

         6. Comparing call by value and call by reference
Call by value
The function receives a copy of the value.
Changes inside the function do not affect the original variable.
Example
#include <stdio.h>

void increment(int x) {
    x = x + 1;
}

int main() {
    int a = 5;
    increment(a);
    printf("%d\n", a);
    return 0;
}
The output is 5. a is copied into x, the function works on the copy so the original a remains unchanged
Call by reference
The function receives the address of the variable.
Changes inside the function affect the original variable.
Example
#include <stdio.h>

void increment(int *x) {
    *x = *x + 1;
}

int main() {
    int a = 5;
    increment(&a);
    printf("%d\n", a);
    return 0;
}
The output is 6. The Address of a is passed, pointer x points to a and dereferencing *x changes a.

     7. Practical scenarios
Call by value is preferred when
1.	Data must not change
2.	 Data size is small
3.	 Safety > performance 
4.	No side effects are desired
advantages
•	Prevents accidental modification
•	Function works on a copy
Call by referencing is preferred when
1.Original data must change
2. Data is large 
3. Multiple outputs are needed
4.  Performance matters










                         

