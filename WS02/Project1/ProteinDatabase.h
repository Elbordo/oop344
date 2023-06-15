/* ------------------------------------------------------
Workshop 2 part 2
Author	Maksym Sorokan
ID 106544208
Date 29.05.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_PROTEINDATABASE_H
#define SDDS_PROTEINDATABASE_H
#include <iostream>
#include<string>
using namespace std;
namespace sdds {
	class ProteinDatabase {
		std::string* m_arr{};
		unsigned int m_stored;
	public:
		ProteinDatabase();
		ProteinDatabase(const ProteinDatabase& p);
		ProteinDatabase& operator=(const ProteinDatabase& p);
		~ProteinDatabase();
		ProteinDatabase(ProteinDatabase&& p) noexcept;
		ProteinDatabase& operator=(ProteinDatabase&& p) noexcept;
		ProteinDatabase(const char* name);
		std::size_t size();
		std::string operator[](size_t t);
	};
}

#endif
