#ifndef STATESTORAGE_H
#define STATESTORAGE_H

#include <list>
#include "SimObject.h"
#include <mysql.h>
#include <my_global.h>
#include <Notfall.h>
#include <Notarzt.h>

class StateStorage
{
    public:
        StateStorage();
        virtual ~StateStorage();
        void saveState();
        void registerNotfall(Notfall* notfall);
        void unregisterNotfall(Notfall* notfall);
        void registerNotarzt(Notarzt* notarzt);
        void unregisterNotarzt(Notarzt* notarzt);
		void check_error();
		void dbconnect();
		void dbdisconnect();
		void dbtest();
		int max_idNotarzt();
		int max_idNotfall();
		void storeNotarzt(Notarzt* notarzt);
		void storeNotfall(Notfall* notfall);

    private:
		MYSQL *conn;
        std::list<Notfall*> observedEmergencies;
		std::list<Notarzt*> observedDoctors;
};

#endif // STATESTORAGE_H
