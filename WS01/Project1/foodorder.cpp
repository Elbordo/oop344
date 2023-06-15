/* ------------------------------------------------------
Workshop 1 part 2
Author	Maksym Sorokan
ID 106544208
Date 24.05.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <stdio.h>
#include "foodorder.h"
using namespace std;
double g_taxrate;
double g_dailydiscount;
namespace sdds {

	void FoodOrder::setEmpty() {
		m_name[0] = '\0';
		m_desc = nullptr;
		m_price = -1;
		m_flag = false;
	}
	void FoodOrder::set(const char* name, const char* desc, const double price, const char flag) {
		strcpy(m_name, name);
		m_desc = new char[strlen(desc) + 1];
		strcpy(m_desc, desc);
		m_price = price;
		if (flag == 'Y')m_flag = true;
		else m_flag = false;
	}
	FoodOrder::FoodOrder() {
		setEmpty();
	}
	FoodOrder::~FoodOrder() {
		delete[] m_desc;
	}
	void FoodOrder::read(istream& istr) {
			setEmpty();
			char name[10];
			string desc;
			double price = 0;
			char flag;
			istr.get(name, 10, ',');
			istr.ignore();
			getline(istr, desc, ',');
			istr >> price;
			istr.ignore();	
			istr >> flag;
			if (!istr.fail())this->set(name, desc.c_str(), price, flag);
	}
	static int COUNTER = 0;
	void FoodOrder::display() {
		if (m_name[0]=='\0') cout << left << setw(2) << ++COUNTER << ". " << "No Order" << endl;
		else {
			double taxedFoodPrice = m_price+(m_price * g_taxrate);
			double discountedTaxedFoodPrice = taxedFoodPrice - g_dailydiscount;
			cout << left << setw(2) << ++COUNTER << ". "
				<< left << setw(10) << m_name << "|"
				<< left << setw(25) << m_desc << "|"
				<< left << setw(12) << fixed << setprecision(2) << taxedFoodPrice << "|";
			if (m_flag) cout << right << setw(13) << discountedTaxedFoodPrice;
			cout << endl;
		}
	}
}