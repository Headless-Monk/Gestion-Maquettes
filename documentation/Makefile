SRC=src/
CXX=g++
CFLAGS=-std=c++0x -Wall -pedantic

all: GestionMaquette

GestionMaquette: main.o afficheur.o afficheur_txt.o ecue.o formation.o interface.o maquette.o ue.o UEchoix.o UEcomposee.o UEseule.o
	$(CXX) $(CFLAGS) -o GestionMaquette.out main.o afficheur.o afficheur_txt.o ecue.o formation.o interface.o maquette.o ue.o UEchoix.o UEcomposee.o UEseule.o	

main.o: $(SRC)main.cpp
	$(CXX) $(CFLAGS) -o main.o -c $(SRC)main.cpp	

afficheur.o: $(SRC)afficheur.cpp $(SRC)afficheur.h
	$(CXX) $(CFLAGS) -o afficheur.o -c $(SRC)afficheur.cpp

afficheur_txt.o: $(SRC)afficheur_txt.cpp $(SRC)afficheur_txt.h
	$(CXX) $(CFLAGS) -o afficheur_txt.o -c $(SRC)afficheur_txt.cpp

ecue.o: $(SRC)ecue.cpp $(SRC)ecue.h
	$(CXX) $(CFLAGS) -o ecue.o -c $(SRC)ecue.cpp

formation.o: $(SRC)formation.cpp $(SRC)formation.h
	$(CXX) $(CFLAGS) -o formation.o -c $(SRC)formation.cpp

interface.o: $(SRC)interface.cpp $(SRC)interface.h
	$(CXX) $(CFLAGS) -o interface.o -c $(SRC)interface.cpp

maquette.o: $(SRC)maquette.cpp $(SRC)maquette.h
	$(CXX) $(CFLAGS) -o maquette.o -c $(SRC)maquette.cpp

ue.o: $(SRC)ue.cpp $(SRC)ue.h
	$(CXX) $(CFLAGS) -o ue.o -c $(SRC)ue.cpp

UEchoix.o: $(SRC)UEchoix.cpp $(SRC)UEchoix.h
	$(CXX) $(CFLAGS) -o UEchoix.o -c $(SRC)UEchoix.cpp

UEcomposee.o: $(SRC)UEcomposee.cpp $(SRC)UEcomposee.h
	$(CXX) $(CFLAGS) -o UEcomposee.o -c $(SRC)UEcomposee.cpp

UEseule.o: $(SRC)UEseule.cpp $(SRC)UEseule.h
	$(CXX) $(CFLAGS) -o UEseule.o -c $(SRC)UEseule.cpp

clean:
	@rm -f *.o
