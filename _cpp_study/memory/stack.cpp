#include <iostream>

int main()
{
  // Allocate memory on the stack
  int i = 42;                               // Allocate an integer on the stack and initialize it to 42
  std::cout << "Value: " << i << std::endl; // Output the value
  return EXIT_SUCCESS;
}