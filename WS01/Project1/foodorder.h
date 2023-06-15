/* ------------------------------------------------------
Workshop 1 part 2
Author	Maksym Sorokan
ID 106544208
Date 24.05.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_FOODORDER_H
#define SDDS_FOODORDER_H
extern double g_taxrate;
extern double g_dailydiscount;
using namespace std;
namespace sdds {
	class DentistPatient {
		char* m_name[10]{};
		TreatmentType t_type;
		t_type=Cleaning
	public:
		DentistPatient() {}
		~FoodOrder() {
			delete[] m_name;
		}
		DentistPatient(TreatmentType type = Cleaning, const char* name) {
			if (name[0] != ' ') {
				delete[] m_name;
				m_name = new char[strlen(name) + 1];
				strcpy(m_name, name);
				if (type = Cleaning) m_type = Filling;
				else m_type = type;
			}
		}
		double treatmentEstimate() {
			short x = -1;
			try {
				if (*this != nullptr) {
					double cost = 0;
					if (m_type = Extraction) cost = 500 * 13 / 100 + 500;
					if (m_type = Crown)cost = 800 * 13 / 100 + 800;
					if (m_type = Filling)cost = 357 * 13 / 100 + 357;
					if (m_type = RootCanal)cost = 1500 * 13 / 100 + 1500;
					if (m_type = Cleaning)cost = 250 * 13 / 100 + 250;
				}
			}
			catch (short x) throw x;
		}
		int totalNoOfPatients() {
			
		}
	};
	class FoodOrder {
		char m_name[10];
		char* m_desc;
		double m_price;
		bool m_flag;
	private:
		void setEmpty();
	public:
		void set(const char* name, const char* desc, const double price, const char flag);
		FoodOrder();
		~FoodOrder();
		void read(istream& istr);
		void display();
	};
	

}

#endif
