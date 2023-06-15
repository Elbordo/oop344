/* ------------------------------------------------------
Workshop 8 part 2
Author	Maksym Sorokan
ID 106544208
Date 24.07.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using raw pointers
		for (size_t i = 0; i < emp.size(); i++) {
			for (size_t j = 0; j < sal.size(); j++)
			{
				if (emp[i].id == sal[j].id)
				{
					EmployeeWage e(emp[i].name, sal[j].salary);
					e.rangeValidator();
					if (activeEmp.checkLuhn(emp[i].id))
						activeEmp += e;
					else
						throw "*** Employees salaray id is not valid";
				}
			}
		}
		return activeEmp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using smart pointers
		for (size_t i = 0; i < emp.size(); i++) {
			for (size_t j = 0; j < sal.size(); j++)
			{
				if (emp[i].id == sal[j].id)
				{
					std::shared_ptr<EmployeeWage> e(new EmployeeWage(emp[i].name, sal[j].salary));
					e->rangeValidator();
					if (activeEmp.checkLuhn(emp[i].id))
						activeEmp += e;
					else
						throw "*** Employees salaray id is not valid";
				}
			}
		}
		return activeEmp;
	}
}