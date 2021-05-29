#include "Vector.h"
#include <exception>
#include <chrono>
#include <vector>
#include <iostream>
#include <string>


class Timer {
private:
	using hrClock = std::chrono::high_resolution_clock; //Auksto tikslumo laikrodi
	using durationDouble = std::chrono::duration<long double>; //Double trukmes skaiciavimas
	std::chrono::time_point<hrClock> start;
public:
	Timer() : start{ hrClock::now() } {} 	//laiko skaiciavimo pradþziai
	void reset() { //laiko nusinulimui
		start = hrClock::now();}
	long double elapsed() const {   //apskaiciuoja skirtuma
		return durationDouble(hrClock::now() - start).count();
	}
};


void Timeit(int sz, Timer start) {
	std::cout << "\tSize: " << sz << std::endl;

	start.reset();
	std::vector<int> v1;
	for (int i = 1; i <= sz; ++i)
		v1.push_back(i);
	std::cout << "std::vector\t" << start.elapsed() << " s" << std::endl;
	v1.clear();

	start.reset();
	vector<int> v2;
	for (int i = 1; i <= sz; ++i)
		v2.push_back(i);
	std::cout << "Custom_Vector\t" << start.elapsed() << " s" << std::endl;
	v2.clear();
}

template<typename T>
int realocation(int sz, T& vec) {
	int realoc = 0;
	for (int i = 1; i <= sz; ++i) {
		vec.push_back(i);
		if (vec.capacity() == vec.size()) {
			++realoc;
		}
	}
	vec.clear();
	return realoc;
}


int main() {
	int sz = 100000000 ;
	std::vector<int> v1;
	vector<int> v2; //custom vector


	try {

		std::cout << "capacity()==size() for std::vector: " << realocation(sz, v1) << std::endl;
		std::cout << "capacity()==size() for Custom_vector: " << realocation(sz, v2) << std::endl;

		Timer start;
		Timeit(10000, start);
		Timeit(100000, start);
		Timeit(1000000, start);
		Timeit(10000000, start); //throws bad_alloc error x86
		Timeit(100000000, start); //throws bad_alloc error
	}
	catch (const std::runtime_error & e) {
		std::cout << e.what() << std::endl;
		exit(0);
	}
}