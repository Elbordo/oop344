#ifndef STUDENT_H
#define STUDENT_H
#include<string>
#include<vector>

extern td::string college_names[3];
const int SIZE = 3;

struct Student {
	std::string f_name{};
	std::string l_name{};
	int student1D;
	std::string col_name{};
};

class College {
	std::vector<int > ratings;
	std::vector<Student> students;
	std::string names[SIZE];
	std::vector<std::string> cnames();
	bool add{ false };
public:
	College(std::string names[]);
    std::vector<Student> m_name;
	College& operator+=(const Student& st);
	void operator==(const std::vector<Student>& st);
	void print();
	void scanstudentForCollege();
};

#endif // !STUDENT_H

