BIN = executable

OBJECTS = main.o traitement.o entree_sortie.o

CC = gcc

all : $(BIN)
$(BIN) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BIN)

main.o : main.c
	$(CC) -c main.c

traitement.o : traitement.c traitement.h
	$(CC) -c traitement.c

entree_sortie.o : entree_sortie.c entree_sortie.h
	$(CC) -c entree_sortie.c

clean :
	rm $(OBJECTS) $(BIN)
