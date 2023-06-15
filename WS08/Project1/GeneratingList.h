/* ------------------------------------------------------
Workshop 8 part 2
Author	Maksym Sorokan
ID 106544208
Date 24.07.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
	template<typename T>
	class GeneratingList {

		std::vector<T> list;
	public:

		GeneratingList(){}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		//TODO: Implement the Luhn Algorithm to check the 
		//      valadity of SIN No's
		bool checkLuhn(const std::string& cardNo)
		{
			int num = cardNo.length();
			int sum = 0, second = false;
			for (int i = num - 1; i >= 0; i--) {
				int d = cardNo[i] - '0';
				if (second == true)
					d = d * 2;
				sum += d / 10;
				sum += d % 10;
				second = !second;
			}
			return (sum % 10 == 0);
		}

		//TODO: Overload the += operator with a smart pointer
		// as a second operand.
		void operator+=(const  std::shared_ptr<T> ew)
		{
			list.push_back(*ew);
		}
		

		//TODO: Overload the += operator with a raw pointer
		// as a second operand.
		void operator+=(const T& rhs)
		{
			list.push_back(rhs);
		}
		
		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H
