#pragma once
#pragma once
#include <chrono>
#include <iostream>
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
