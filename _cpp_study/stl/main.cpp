#include "library.h"

Student s1; // Default constructor
Student s2("John", "Doe", 1, 9.5f);
const Student s3("Jane", "Doe", 2, 8.5f);

int main()
{
  // vector
  std::cout << "C++ version: " << __cplusplus << "\n";

  std::vector<float> vect;

  vect.push_back(42.2f);
  vect.push_back(7.3f);

  std::cout << "vect[0]: " << vect[0] << "\n";
  std::cout << "vect[1]: " << vect[1] << "\n";

  /**
   * ---------- Iterate over a vector ----------
   */

  for (size_t i = 0; i < vect.size(); i++)
  {
    std::cout << vect[i] << "\n";
  }

  // We use the reference to avoid copying, useful for large objects
  for (const auto &v : vect)
  {
    std::cout << v << "\n";
  }

  /**
   * Seeing Student class in action
   */

  // s1.print();
  // s2.print();
  // s3.print();

  Course c("C++ Programming");
  c.load_from_file("students.csv");
  c.print();
  // c.add_student(s1);
  // c.add_student(s2);
  // c.add_student(s3);
  // c.print();

  return EXIT_SUCCESS;
}
