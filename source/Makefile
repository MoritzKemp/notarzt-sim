INCLUDE_DIR = include
LIB_DIR = -Ilibs
SRC_DIR = src
OBJ_DIR = obj_1

_OBJ = 	AnkunftPatientRoutine.o EndeBehandlungRoutine.o EndRoutine.o EventRoutine.o \
		Event.o EventList.o HinfahrtPatientRoutine.o NeuerNotrufRoutine.o \
		Notarzt.o Notfall.o NotfallWarteschlange.o \
		SimObject.o SimulationManager.o StateStorage.o Zufall.o RueckfahrtRoutine.o AnkunftZentraleRoutine.o Nachberechnungen.o

OBJ = $(patsubst %, $(OBJ_DIR)/%,$(_OBJ))

ENUMS = $(INCLUDE_DIR)/EventType.h $(INCLUDE_DIR)/NotarztPlace.h \
			$(INCLUDE_DIR)/NotarztStates.h

_SRC = $(_OBJ:%.o=%.cpp)
SRC = $(patsubst %, $(SRC_DIR)/%,$(_SRC)) main.cpp

_HDR = $(_OBJ:%.o=%.h)
HDR = $(patsubst %, $(INCLUDE_DIR)/%,$(_HDR))

CC=g++
CFLAGS=-I$(INCLUDE_DIR) $(LIB_DIR) -std=c++11 -Wall -g

eventSim: $(HDR) $(SRC)
	$(CC) $(CFLAGS) -o eventSim $(HDR) $(SRC) $$(mysql_config --libs) $$(mysql_config --cflags)

#Target to create object files (NOT USED CURRENTLY)
#%.o: ../$(INCLUDE_DIR)/%.h ../$(SRC_DIR)/%.cpp $(ENUMS)
#	$(CC) $(CFLAGS) -c $< -o $@
	
