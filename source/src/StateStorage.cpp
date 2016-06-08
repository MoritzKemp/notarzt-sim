#include "StateStorage.h"
#include "NotarztStates.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
//#include <cstring>
//#include <cstdio>

using namespace std;

StateStorage::StateStorage()
{
	conn = mysql_init(NULL);
	dbconnect();
}

StateStorage::~StateStorage()
{
    //dtor
}

void StateStorage::saveState(int simulationszeit)
{
    cout << "Current State at " << simulationszeit <<":" << endl;

	//Handle registered emergencies
    list<Notfall*>::iterator iterNotfall = observedEmergencies.begin();
    Notfall* currentNotfall;
    while(iterNotfall != observedEmergencies.end())
    {
        currentNotfall = *iterNotfall;

		// Print to console
		cout << "Notfall: time of receipt: " << currentNotfall->getCallTime(); 
		cout << ", priority: " << currentNotfall->isUrgent();
		cout << ", treatment duration: " << currentNotfall->getTreatmentDuration();
		cout << ", place: " << currentNotfall->getPlace() << endl;

		//Persist in database
		storeNotfall(currentNotfall, simulationszeit);

        iterNotfall++;
    }

	// Handle registered doctors
    list<Notarzt*>::iterator iterNotarzt = observedDoctors.begin();
    Notarzt* currentNotarzt;
    while(iterNotarzt != observedDoctors.end())
    {
        currentNotarzt = *iterNotarzt;

		// Print to console
		cout << "Notarzt: timestamp: " << currentNotarzt->getTimestamp(); 
		cout << ", priority: " << (int) currentNotarzt->getNotarztState();
		cout << ", place: " << currentNotarzt->getNotarztPlace() << endl;

		//Persist in database
		storeNotarzt(currentNotarzt, simulationszeit);

        iterNotarzt++;
    }
}

void StateStorage::registerNotfall(Notfall *notfall)
{
    observedEmergencies.push_front( notfall );
}

void StateStorage::registerNotarzt(Notarzt* notarzt)
{
	observedDoctors.push_front( notarzt );
}

void StateStorage::unregisterNotfall(Notfall *notfall)
{
    observedEmergencies.remove( notfall );
}

void StateStorage::unregisterNotarzt(Notarzt *notarzt)
{
    observedDoctors.remove( notarzt );
}

void StateStorage::check_error()  
{
	if (mysql_errno(conn) != 0) 
	{
		fprintf(stderr, "Fehler: %s\n", mysql_error(conn));
		exit(EXIT_FAILURE);
	}
}

void StateStorage::dbconnect()  
{
	printf("Verbingung zur Datenbank herstellen... ");
	conn = mysql_init(conn);
	check_error();
	mysql_real_connect(conn, "localhost", "root", "", "simulation", 0, NULL, 0);
	check_error();
	printf("done\n");
}

void StateStorage::dbdisconnect()  
{
	printf("\nVerbingung zur Datenbank trennen... ");
	mysql_close(conn);
	printf("done\n");
}

void StateStorage::dbtest()
{
	MYSQL_RES *result;
	MYSQL_ROW row;
	int num_fields;
	int i;

	conn = mysql_init(NULL);
	dbconnect();	

	mysql_query(conn, "SELECT * FROM notfall");
	result = mysql_store_result(conn);

	num_fields = mysql_num_fields(result);

	while ((row = mysql_fetch_row(result)))
	{
		for(i = 0; i < num_fields; i++)
		{
			printf("%s ", row[i] ? row[i] : "NULL");
		}
		printf("\n");
	}

	mysql_free_result(result);
	dbconnect();

}

int StateStorage:: max_idNotarzt()
{
	int max = 0;
	MYSQL_ROW  row;
	MYSQL_RES  *mysql_res;

	string query = "SELECT MAX(idNotarzt) FROM notarzt";

	/* jetzt die Anfrage an den Datenbankserver */
	char * buffer = new char[query.length()+1];
	strcpy(buffer, query.c_str());
	mysql_real_query(conn, buffer, strlen(buffer));

	/* Daten der Anfrage abholen */
	mysql_res = mysql_store_result(conn);

	row = mysql_fetch_row (mysql_res);
	max = atoi(row[0]);

	/* Speicherplatz wieder freigeben */
	mysql_free_result(mysql_res);
	free(buffer);

	return max;
}
	
int StateStorage:: max_idNotfall()
{
	int max = 0;
	MYSQL_ROW  row;
	MYSQL_RES  *mysql_res;
	
	string query = "SELECT MAX(idNotfall) FROM notfall";

	/* jetzt die Anfrage an den Datenbankserver */
	char * buffer = new char[query.length()+1];
	strcpy(buffer, query.c_str());

	mysql_real_query(conn, buffer, strlen(buffer));	

	/* Daten der Anfrage abholen */
	mysql_res = mysql_store_result(conn);	

	row = mysql_fetch_row (mysql_res);
	max = atoi(row[0]);
	
	/* Speicherplatz wieder freigeben */
	mysql_free_result(mysql_res);
	free(buffer);

	return max;
}
	
void StateStorage::storeNotarzt(Notarzt* notarzt, int simulationszeit)
{
	//neues Element der Datenbank hinzufuegen
	int max = max_idNotarzt();
	
	string nZustand;

	if(notarzt->getNotarztState() == NotarztStates::WARTEND)
	{
		nZustand = "wartend";
	}
	if(notarzt->getNotarztState() == NotarztStates::UNTERWEGS_PATIENT)
	{	
	 nZustand = "unterwegsPatient";
	}

	if(notarzt->getNotarztState() == NotarztStates::UNTERWEGS_ZENTRALE)
	{
		nZustand = "unterwegsZentrale";
	}
	if(notarzt->getNotarztState() == NotarztStates::BEHANDLUNG) 
	{
		nZustand = "behandlung";
	}

	string select = "INSERT INTO `simulation`.`notarzt` VALUES ('";
	select += to_string(max+1);
	select += "', '";
	select += to_string(notarzt->getTimestamp()); 
	select += "', '";
	select += nZustand;
	select += "', '";
	select += to_string(simulationszeit);
	select += "')";
	string query = select;

	// jetzt die Anfrage an den Datenbankserver
	char * buffer = new char[query.length()+1];
	strcpy(buffer, query.c_str());
	mysql_real_query(conn, buffer, strlen(buffer));

	//check_error();

	// Speicherplatz wieder freigeben 
	
	free(buffer);
}
	
void StateStorage::storeNotfall(Notfall* notfall, int simulationszeit)
{
	//neues Element der Datenbank hinzufuegen
	int max = max_idNotfall();

	string select = "INSERT INTO `simulation`.`notfall` VALUES ('";
	select += to_string(max+1);
	select += "', '";
	select += to_string(notfall->getCallTime());
	select += "', '";
	select += to_string(notfall->isUrgent());
	select += "', '";
	select += to_string(notfall->getTreatmentDuration());
	select += "', '";
	select += to_string(notfall->inTreatment());
	select += "', '";
	select += to_string(notfall->getTreatmentStart());
	select += "', '";
	select += to_string(simulationszeit);
	select += "')";
	string query = select;

	// jetzt die Anfrage an den Datenbankserver 
	char * buffer = new char[query.length()+1];
	strcpy(buffer, query.c_str());
	mysql_real_query(conn, buffer, strlen(buffer));

	// Speicherplatz wieder freigeben 
	free(buffer);
	
}

