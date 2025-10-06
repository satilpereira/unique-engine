#include <iostream>
#include <memory>
int main(int argc, char *argv[])
{
  std::unique_ptr<int> ptr = std::make_unique<int>(42);

  return EXIT_SUCCESS;
}