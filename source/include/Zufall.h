#ifndef ZUFALL_H
#define ZUFALL_H

#include <ctime>
#include <cstdint>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/exponential_distribution.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;
class Zufall
{
public:
	Zufall();
	~Zufall();
	void getRandomExpNotruf(int Zeitraum, vector<int>* vec, int* size);
	int getPrio();
	int versorgungszeit(int Prio);
	int getStadtbezirk();
	int Fahrzeit(int Bezirk1, int Bezirk2);

	static int Bevoelkerung[];
	static int BevArraySize;
	static std::time_t now;
	static boost::random::mt19937 gen;



};

#endif
