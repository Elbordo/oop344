#include "Autoshop.h"
#include "Car.h"
#define _CRT_SECURE_NO_WARNINGS
namespace sdds
{
	Autoshop& Autoshop::operator +=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);
		return *this;
	}
	void Autoshop::display(std::ostream& out) const {
		out << "--------------------------------" << std::endl;
		out << "| Cars in the autoshop! |" << std::endl;
		out << "--------------------------------" << std::endl;
		for (auto i = m_vehicles.begin(); i < m_vehicles.end(); i++) {
			(*i)->display(out); 
				out << std::endl;
		}
		out << "--------------------------------" << std::endl;
	}
	Autoshop::~Autoshop() {
		for (auto& car : m_vehicles)
			delete car;
	}
}