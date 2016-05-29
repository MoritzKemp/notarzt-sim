#include <ctime>
#include <cstdint>
#include <boost/random.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "Zufall.h"
#include <vector>
#include <math.h>

	std::time_t Zufall::now = std::time(0);
	boost::random::mt19937 Zufall::gen = boost::random::mt19937(static_cast<uint32_t>(now));
	int Zufall::Bevoelkerung[] = {10000,30000,50000,31000,50000,10000,66000,15000,4000,1000};
	int Zufall::BevArraySize = 10;

Zufall::Zufall()
{
}



void Zufall::getRandomExpNotruf(int Zeitraum, vector<int>* vec, int* size){
	boost::random::exponential_distribution<> dist(1.0/50);
	int zeit = 0;
	int zahl = static_cast<int>(dist(gen)+0.5);
	
	while(zeit+zahl < Zeitraum){
		zeit += zahl;
		vec->push_back(zeit);
		zahl = static_cast<int>(dist(gen)+0.5);
    }
	(*size) = vec->size();
	
}


//gibt 0 oder 1 zurück
int Zufall::getPrio(){
	boost::uniform_int<> zero_or_one(0,1);
	return zero_or_one(gen);
}

int Zufall::versorgungszeit(int Prio){
	boost::uniform_int<> gleichver;
	if(Prio == 0){
		gleichver = boost::uniform_int<>(10,20);
	}else{
		gleichver = boost::uniform_int<>(30,90);
	}
		return gleichver(gen);
}

int Zufall::getStadtbezirk(){
	int count = 0;
	for(int i = 0; i < BevArraySize; i++){
		count += Bevoelkerung[i];
	}
	boost::uniform_int<> gleichver(1,count);
	int zufall = gleichver(gen);

	count = 0;
	for(int i = 0; i < BevArraySize; i++){
		count += Bevoelkerung[i];
		if(zufall <= count){
			return i;
		}
	}
	return 0;
}

int Zufall::Fahrzeit(int Bezirk1, int Bezirk2){
	//int Mittelwert = array[Bezirk1][Bezirk2];
	//dummy
	int Mittelwert = 8;
	int linkeSchranke = Mittelwert - Mittelwert/2;
	int rechteSchranke = Mittelwert + Mittelwert/2;
	boost::uniform_int<> gleichver(linkeSchranke,rechteSchranke);
	return gleichver(gen);
}




Zufall::~Zufall()
{
}
