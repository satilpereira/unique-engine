#include <iostream>

int main()
{
  // Dynamically allocate memory on the heap
  int *ptr = new int(42);                      // Dynamically allocate an integer and initialize it to 42
  std::cout << "Value: " << *ptr << std::endl; // Output the value
  delete ptr;                                  // Free the allocated memory
  return EXIT_SUCCESS;
}