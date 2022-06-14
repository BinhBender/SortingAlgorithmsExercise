#pragma once
#include <string>
#include <fstream>
#include <ctime>
#include "Utilities.h"
#include <array>
#include <vector>

class bubbleSort : StartFileRand {

	void BubbleSorter() {

		for (int b = 0; b < v.size() - 1; b++)
		{
			for (int i = 0; i < v.size() - 1; i++)
			{
				int next = i + 1;
				if (v[i] > v[next]) {
					Utilities::NumberSwapRef(v[i], v[next]);
				}
			}
		}

	}
	
	void placeSortedInFile(){
		std::ofstream infile;
		infile.open(sortTo);

		for (int i = 0; i < v.size(); i++)
		{
			infile << v[i] << "\n";
		}
	}


public:

	bubbleSort(std::string a, std::string b) : StartFileRand(a, b) {
		fileInit();

		BubbleSorter();

		placeSortedInFile();
	}
};