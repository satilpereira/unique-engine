#ifndef _LIBRARY_H
#define _LIBRARY_H

#if __cplusplus < 202002L
#error This project requires C++20 or higher.
#endif

#include <iostream>
#include <vector>
#include <fstream>

class Student
{
  std::string m_first = "First";
  std::string m_last = "Last";
  int m_id = 0;
  float m_avg = 0.0f;

public:
  Student() = default; // Default constructor, same as Student() {}
  Student(const std::string &first, const std::string &last, int id, float avg)
      : m_first(first),
        m_last(last),
        m_id(id),
        m_avg(avg)
  {
  }

  float get_avg() const
  {
    return m_avg;
  }

  int get_ID() const
  {
    return m_id;
  }

  std::string get_first() const
  {
    return m_first;
  }

  std::string get_last() const
  {
    return m_last;
  }

  void print() const
  {
    std::cout << m_first << " " << m_last << ", ID: " << m_id << ", Average: " << m_avg << "\n";
  }
};

class Course
{
  std::string m_name;
  std::vector<Student> m_students;

public:
  Course(const std::string &name)
      : m_name(name)
  {
  }

  void add_student(const Student &s)
  {
    m_students.push_back(s);
  }

  const std::vector<Student> &get_students() const
  {
    return m_students;
  }

  void load_from_file(const std::string &filename)
  {
    std::ifstream fin(filename);
    std::string tmp_row;

    // Skip the header row
    std::getline(fin, tmp_row);
    while (std::getline(fin, tmp_row))
    {
      std::string first, last;
      int id;
      float avg;

      char first_buf[128] = {0}, last_buf[128] = {0};
      if (std::sscanf(tmp_row.c_str(), "%127[^,],%127[^,],%d,%f",
                      first_buf, last_buf, &id, &avg) != 4)
        continue;
      first = first_buf;
      last = last_buf;
      m_students.emplace_back(first, last, id, avg);
    }
    fin.close();
  }

  void print() const
  {
    std::cout << "Course: " << m_name << "\n";
    for (const auto &student : m_students)
    {
      student.print();
    }
  }
};

#endif // _LIBRARY_H
