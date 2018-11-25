#ifndef MAPRESTO_H
#define MAPRESTO_H

#include "matriks.h"
#include "graph.h"
#include <stdio.h>

#define MARK '.'
/* State Mesin */
extern char CC;
extern boolean EOP;

typedef struct{
    int px; //ngasihtau player ada di baris berapa di ruangan
    int py;//ngasihtau player ada di kolom berapa di ruangan
    int room;//ngasihtau player ada di ruangan mana
}player;

#define X(P) (P).px
#define Y(P) (P).py
#define Room(P) (P).room

void STARTRESTO(FILE *fp);
void ADVRESTO();
void FileToMap(FILE *fp, MATRIKS *room);
void InitMap(MATRIKS *room1, MATRIKS *room2, MATRIKS *room3, MATRIKS *kitchen);
void moveplayer(player *p, MATRIKS room, char cmd, Graph G, adrNode *currLoc);
void NearestCust(player p, MATRIKS room, int *ordable);
void ChangeRoom(Graph G, adrNode *currLoc, player *P);
boolean AvailOrder(player P, MATRIKS room);


#endif
