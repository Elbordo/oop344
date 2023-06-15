#include <iostream>
#include <string>
#include <vector>
#include "Header.h"
using namespace std;

std::string college_names[3]{
	"Seneca",
"Sheridan",
"Gerogian",
};
int main() {
	Student st[]{
	{"Mia","Yang",2638,"Sheridan"},
	{"Peter","Jone",2756,"Seneca"},
	{"Marty","Ado",2564,"Gerogian"},
	{"Tyler","Mathew",3256,"Centenial"}
	};








	College c1(college_names);

	College c2(college_names, 3);

	try {
		(((c1 += st[0]) += st[1]) += st[2]);
	}


	catch (std::string& msg) {
		cout << msg << endl;
	}

	c1.print();
}