#pragma once
#include <string>
#include <fstream>
#include <ctime>
#include "Utilities.h"
#include <array>

#define SIZE 1000
class bubbleSort {

	std::array<int, SIZE> v;

	void Sorter() {

		std::ofstream infile;
		infile.open("sorted.txt");

		//
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
		for (int i = 0; i < v.size(); i++)
		{
			infile << v[i] << "\n";
		}

	}

	void fileRead() {
		std::string data;
		std::ifstream infile;
		int a = 0;
		//opens the toSort file
		infile.open("toSort.txt");

		if (infile.is_open()) {
			while (infile >> data)// WHILE IT IS READING THE FILE IT INSERTS THE DATA INTO THE V[A] ARRAY
			{
				v[a] = stoi(data);// converts the data in the file to integers and putting it in the v[a] array
				a++;
			}
		}
		infile.close();
	}

	void numberRandomizer() {
		//goes first, makes file and fills it from the beginning of the array to the end with 0s and then for every space in the thing fill it with a random number from 0 to the size of the arary
		std::ofstream outfile;
		outfile.open("toSort.txt");
		// fills array (why)
		std::fill(v.begin(), v.end(), 0);

		srand(std::time(0));
		for (int i = 0; i < SIZE; i++)
		{
			outfile << std::rand() % SIZE + 1 << "\n"; //gives the number from 1 - 1000 and "injects" it into the file
		}

	}

public:

	void init() {

		numberRandomizer();

		fileRead();

		Sorter();

	}
};