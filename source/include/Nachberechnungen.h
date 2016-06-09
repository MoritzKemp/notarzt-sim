#ifndef NACHBERECHNUNGEN_H
#define NACHBERECHNUNGEN_H

#include <ctime>
#include <cstdint>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/exponential_distribution.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "Zufall.h"
#include <vector>
#include <math.h>
#include "StateStorage.h"
using namespace std;

class Nachberechnungen
{

public:
	Nachberechnungen();
	~Nachberechnungen();

	void init(StateStorage* dSource);
	void readData();
	void readData2(int cut);
	void DataCutOff(int i);
	double getMittelwert(vector<int>);
	double getMittelwert(vector<double>);
	vector<vector<int>> teileInXTeile(int x);
	vector<double> getMittelwerte(vector<vector<int>> teile);
	double getVarianz(vector<int>);
	double getVarianz(vector<double>);
	double getKovarianz(vector<double> Mittelwerte, double Mittelwert);
	double getStrichprobenvarianz(vector<double> Mittelwerte, double Mittelwert);
	double getAutoKorrelation(vector<int> Daten, int AnzahlBloecke);
	void konfidenzIntervall(
		double* LinkteSchranke, 
		double* RechteSchranke, 
		int anzahlMesswerte, 
		double Mittelwert, 
		double Varianz, 
		int Prozent
	);
	void konfidenzIntervallBatches(
		double* LinkeSchranke, 
		double* RechteSchranke,
		vector<int> daten, 
		int anzahlBatches, 
		int Prozent
	);
	int lawAndCarson(double Schranke);

	vector<int> Daten;
	vector<int> Daten2;
	vector<int> prio;
	StateStorage* dataSource;
	int Hinfahrt;
	int Rueckfahrt;
	int Home;
	int Behandlung;

};



#endif
