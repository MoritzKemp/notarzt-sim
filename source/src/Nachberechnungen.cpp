#include <ctime>
#include <cstdint>
#include "boost/random.hpp"
#include "boost/generator_iterator.hpp"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <math.h>  
#include "Nachberechnungen.h"
#include "StateStorage.h"


Nachberechnungen::Nachberechnungen()
{
}


//Auslesen und auswerten der Daten aus der Datenbank 
void Nachberechnungen::init(StateStorage dSource){
	Nachberechnungen::dataSource = dSource;
	readData();
	DataCutOff(dSource.max_idNotarzt()/5);

	double* links = new double();
	double* rechts = new double();
	int anZahlBatches = lawAndCarson(0.05);
	cout << "Anzahl Batches nach Law And Carson: " << anZahlBatches << endl;
	cout << "Zu Erwartende Wartezeit für nicht lebensbedrohlich erkrankte Patienten" << endl;
	konfidenzIntervallBatches(links, rechts, Daten, anZahlBatches, 95);
	cout << "95%iges-Konfidenzintervall: " << *links << " - " << *rechts << " Size: " << *rechts - *links <<endl; 
	konfidenzIntervallBatches(links, rechts, Daten, anZahlBatches, 98);
	cout << "98%iges-Konfidenzintervall: " << *links << " - " << *rechts << " Size: " << *rechts - *links <<endl; 
	konfidenzIntervallBatches(links, rechts, Daten, anZahlBatches, 90);
	cout << "90%iges-Konfidenzintervall: " << *links << " - " << *rechts << " Size: " << *rechts - *links <<endl;  

	readData2(dSource.max_idNotfall()/5);
}
	
	



	void Nachberechnungen::readData(){
		int* time1 = new int();
		int* time2 = new int();
		int* prio = new int();
		for(int i = 1; i <= dataSource.max_idNotfall(); i++){
			dataSource.getNotfall(i,time2,time1,prio);
			if(*prio == 0){
			Nachberechnungen::Daten2.push_back(*time1-*time2);
			}
		}
	}

	void Nachberechnungen::DataCutOff(int i){
		vector<int> help = vector<int>();
		for (i; i < Daten2.size(); i++){
			help.push_back(Daten2.at(i));
		}
		Daten = help;
		return;
	}



	void Nachberechnungen::readData2(int cut){
		if(cut <= 0) {cut = 1;}
		const int unterwegsZentrale = 2;
		const int unterwegsPatient = 1;
		const int wartend = 0;
		const int beh = 3;
		int Hinfahrt = 0;
		int Rueckfahrt = 0;
		int Home = 0;
		int Behandlung = 0;
		int* time = new int();
		int* art = new int();
		int oldArt = 0;
		int oldTime = 0;
		if(cut > 1){ dataSource.getNotarzt(cut - 1, time, art); oldArt = *art; oldTime = *time;}
		for(int i = cut; i <= dataSource.max_idNotarzt(); i++){
			dataSource.getNotarzt(i, time, art);
			int timeDiff = *time - oldTime;
			if (oldArt == unterwegsZentrale){Rueckfahrt += timeDiff;}
			else{if (oldArt == unterwegsPatient){Hinfahrt += timeDiff;}
			else{if (oldArt == wartend){Home += timeDiff;}
			else{if (oldArt == beh){Behandlung += timeDiff;}
			}}}
			oldArt = *art;
			oldTime = *time;
		}
		cout << "Auslastung Arzt: " << (Hinfahrt + Behandlung)*1.0 / (Hinfahrt + Rueckfahrt + Home + Behandlung) << endl;
		cout << "Zeitanteil Arzt in Zentrale: " << (Home)*1.0/ (Hinfahrt + Rueckfahrt + Home + Behandlung) << endl;
	}


	double Nachberechnungen::getMittelwert(vector<int> vec){
		int size = vec.size();
		double mittelwert = 0;
		for (int i = 0; i < size; i++){
			mittelwert += (double) vec.at(i);
		}
		return mittelwert/size;
	}
	
	double Nachberechnungen::getMittelwert(vector<double> vec){
		int size = vec.size();
		double mittelwert = 0;
		for (int i = 0; i < size; i++){
			mittelwert += (double) vec.at(i);
		}
		return mittelwert/size;
	}



	vector<vector<int>> Nachberechnungen::teileInXTeile(int k){
		int size = Daten.size();
		int kSize = size/k;
		if(size % k != 0){kSize ++;}
		vector<vector<int>> geteilteDaten = vector<vector<int>>();
		int counter = 0;
		for ( int i = 0; i < k; i++){
			vector<int> help = vector<int>();
			for (int i2 = 0; i2 < kSize && counter < size; i2++){
				help.push_back(Daten.at(counter));
				counter++;
			}
			geteilteDaten.push_back(help);
		}
		
		return geteilteDaten;

	}


			double  Nachberechnungen::getVarianz(vector<int> vec){
			double Mittelwert = getMittelwert(vec);
			double help = 0;
			for (int i = 0; i < vec.size(); i++){
				help += (vec.at(i) - Mittelwert) * (vec.at(i) - Mittelwert);
			}
			return sqrt(help/(vec.size() - 1));
		}


		double  Nachberechnungen::getVarianz(vector<double> vec){
			double Mittelwert = getMittelwert(vec);
			double help = 0;
			for (int i = 0; i < vec.size(); i++){
				help += (vec.at(i) - Mittelwert) * (vec.at(i) - Mittelwert);
			}
			return sqrt(help/(vec.size() - 1));
		}



	vector<double> Nachberechnungen::getMittelwerte(vector<vector<int>> teile){
		vector<double> result = vector<double>();
		for (int i = 0; i < teile.size(); i++){
			result.push_back(getMittelwert(teile.at(i)));
		}
		return result;
	}


	double Nachberechnungen::getKovarianz(vector<double> Mittelwerte, double Mittelwert){
		double help = 0;
		for (int i = 0; i < Mittelwerte.size()-1; i++){
			help += (Mittelwerte.at(i) - Mittelwert) * (Mittelwerte.at(i+1) - Mittelwert);
		}
		return help/(Mittelwerte.size()-1);
	}

	double Nachberechnungen::getStrichprobenvarianz(vector<double> Mittelwerte, double Mittelwert){
		double help = 0;
		for (int i = 0; i < Mittelwerte.size()-1; i++){
			help += (Mittelwerte.at(i) - Mittelwert) * (Mittelwerte.at(i) - Mittelwert);
		}
		return help/(Mittelwerte.size()-1);
	}

	double Nachberechnungen::getAutoKorrelation(vector<int> Data, int AnzahlBloecke){
		vector<vector<int>> DatenTeile = teileInXTeile(AnzahlBloecke);
		vector<double> Mittelwerte = getMittelwerte(DatenTeile);
		double Mittelwert = getMittelwert(Mittelwerte);
		double s2= getVarianz(Mittelwerte) * getVarianz(Mittelwerte);

		double help = 0;
		for (int i = 0; i < Mittelwerte.size()-1; i++){
			help += (Mittelwerte.at(i) - Mittelwert) * (Mittelwerte.at(i+1) - Mittelwert) / s2;
		}
		return help/(Mittelwerte.size()-1);
	}

	void Nachberechnungen::konfidenzIntervall(double* LinkteSchranke, double* RechteSchranke, int anzahlMesswerte, double Mittelwert, double Varianz ,int Prozent){
		double epsilon = 0;		
		switch ( Prozent )
      {
         case 90:
            epsilon = 1.645;
            break;
         case 95:
            epsilon = 1.96;
            break;
		 case 98:
            epsilon = 2.327;
            break;
         default:
             epsilon = 1.96;
      }
		
		double help = epsilon * sqrt(Varianz)/sqrt(anzahlMesswerte*1.0);
		(*LinkteSchranke) = Mittelwert - help;
		(*RechteSchranke) = Mittelwert + help;
		return;
	}


	void Nachberechnungen::konfidenzIntervallBatches(double* LinkeSchranke, double* RechteSchranke,vector<int> daten, int anzahlBatches, int Prozent){
		vector<vector<int>> parts = teileInXTeile(anzahlBatches);
		vector<double> Mittelwerte =  getMittelwerte(parts);
		double Mittelwert = getMittelwert(Mittelwerte);
		double Varianz = getVarianz(Mittelwerte);
		konfidenzIntervall(LinkeSchranke, RechteSchranke, Mittelwerte.size(), Mittelwert, Varianz, Prozent);
	}

	int Nachberechnungen::lawAndCarson(double Schranke){
		int q = Daten.size()/2;
		int qTop = 0;
		int zaehler = 0;
		int tiefe = 2;

		while(q >= 1){
			double autocorr = getAutoKorrelation(Daten, q);
			if(autocorr <= Schranke){
				if(zaehler == 0){
					qTop = q;
				}
				zaehler++;
			}
			if(zaehler > 0 && autocorr > Schranke){
				zaehler = 0;
			}
			if(zaehler >= tiefe){
				return qTop;
			}

			q = q/2;
		}
		return 1;
	}







Nachberechnungen::~Nachberechnungen(void)
{
}
