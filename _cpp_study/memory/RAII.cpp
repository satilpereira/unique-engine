#include <iostream>

class IntArray
{
  int *array;

public:
  IntArray(size_t size)
      : array(new int[size])
  {
  }

  ~IntArray()
  {
    delete[] array;
  }
  int &operator[](size_t i)
  {
    return array[i];
  }
};

int main(int argc, char *argv[])
{
  // Allocating array on the stack, so when it goes out of scope, memory is freed
  IntArray arr(10);
  arr[5] = 42;
  std::cout << arr[5] << '\n';

  return EXIT_SUCCESS;
}