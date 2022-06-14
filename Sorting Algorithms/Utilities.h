#pragma once

#include <chrono>
#include <iostream>
#include <string>
#include <array>
#include <fstream>

#define SIZE 1000
class Utilities
{
	public:
	static void NumberSwapRef(int& a, int& b) {
		int c = 0;
		c = a;
		a = b;
		b = c;
	}



};
class StartFileRand {
	//all the other sorter needs is to access the "toSort" file
protected:
	const static int size = SIZE;
	std::array<int, SIZE> v;

	std::string toSort;
	std::string sortTo;

	void fileInit() {
		//randomize and place in tosort file

		numberRandomizer();

		fileRead();

	}


private:
	void fileRead() {
		std::string data;

		std::ifstream infile(toSort);
		int a = 0;
		//opens the toSort file

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
		outfile.open(toSort);
		// fills array with 0s (why)
		v.fill(0);

		srand(std::time(0));
		for (int i = 0; i < size; i++)
		{
			int randomNum = std::rand() % size + 1;
			outfile << randomNum << "\n"; //gives the number from 1 - 1000 and "injects" it into the file
		}

	}
public:
	StartFileRand() {
		toSort = "file.txt";
		sortTo = "file2.txt";
	}
	StartFileRand(std::string a, std::string b) {
		toSort = a;
		sortTo = b;
	}

};

class Timer {
	private:
		
		std::chrono::steady_clock::time_point start;
		std::chrono::steady_clock::time_point end;
	public:

		Timer()
		{
			start = std::chrono::high_resolution_clock::now();
		}


		~Timer() {// deconstructor- acts at the end of a scope
			end = std::chrono::high_resolution_clock::now();

			std::chrono::duration<float> duration = (end - start);
			std::cout << duration.count() << "s" << std::endl;
		}


	};
