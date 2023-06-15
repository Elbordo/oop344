/* ------------------------------------------------------
Workshop 2 part 2
Author	Maksym Sorokan
ID 106544208
Date 29.05.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include"ProteinDatabase.h"
using namespace std;
namespace sdds {

	ProteinDatabase::ProteinDatabase() {
		m_stored = 0;
	}

	ProteinDatabase::ProteinDatabase(const ProteinDatabase& p) {
		if (p.m_arr != nullptr) {
			m_arr = new string[p.m_stored];
			for (unsigned int i = 0; i < p.m_stored; i++) m_arr[i] = p.m_arr[i];
			m_stored = p.m_stored;
		}
	}

	ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& p) {
		if (this != &p) {
			m_arr = new string[p.m_stored];
			for (unsigned int i = 0; i < p.m_stored; i++) m_arr[i] = p.m_arr[i];
			m_stored = p.m_stored;
		}
		return *this;
	}

	ProteinDatabase::~ProteinDatabase() {
		delete[] m_arr;
	}

	ProteinDatabase::ProteinDatabase(ProteinDatabase&& p) noexcept {
		*this = move(p);
	}

	ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& p) noexcept {
		if (this != &p) {
			delete m_arr;
			m_arr = p.m_arr;
			p.m_arr = nullptr;
			m_stored = p.m_stored;
			p.m_stored = 0;
		}
		return (*this);
	}

	ProteinDatabase::ProteinDatabase(const char* name) {
		string line;
		ifstream f(name);
		unsigned int count = 0,i = 0;
		if (f) {
			while (getline(f, line)){
				if (line[0] == '>') count++;
			}
			m_stored = count;
			f.close();
		}
		m_arr = new string[m_stored + 1];
		f.open(name);
		if (f) {
			while (getline(f, line) && i < m_stored){
				if (line[0] != '>') m_arr[i] += line;
				else if (line[0] == '>' && !m_arr[i].empty()) i++;
			}
			f.close();
		}
	}

	std::size_t ProteinDatabase::size() {
		return m_stored;
	}

	std::string ProteinDatabase::operator[](size_t t) {
		if ( t < 0 || t > m_stored - 1 || m_stored <= 0) return "";
		return m_arr[t];
	}
}