/* ------------------------------------------------------
Workshop 9 part 2
Author	Maksym Sorokan
ID 106544208
Date 30.07.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_W9_PROCESSDATA_H
#define SDDS_W9_PROCESSDATA_H

#include<iostream>
#include<string>
#include<fstream>
#include<functional>
#include<vector>
#include<thread>

namespace sdds_ws9 {
	void computeAvgFactor(const int*, int, int, double&);
	void computeVarFactor(const int*, int, int, double, double&);
	class ProcessData {
		int total_items{};
		int* data{};
		// Following parameters are included to be used for managing multi-threaded 
		//  computation in the operator() function. 
		int num_threads{ 0 }; // to hold number of threads 
		double* averages{ nullptr }; // to hold average factors 
		double* variances{ nullptr }; // to hold variance factors
		int* p_indices{ nullptr }; // to hold partitioning indices
	public:
		ProcessData(std::string, int n_threads);
		ProcessData(const ProcessData&) = delete;
		ProcessData& operator=(const ProcessData&) = delete;
		~ProcessData();
		operator bool() const;
		int operator()(std::string, double&, double&);
	};
	
	
}



#endif 