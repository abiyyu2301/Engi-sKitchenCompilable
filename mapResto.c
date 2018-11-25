#include <stdio.h>
#include "mapResto.h"

char C;
boolean eop;

static FILE * pita;
static int retval;

void STARTRESTO(FILE *fp) {
    /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
     Karakter pertama yang ada pada pita posisinya adalah pada jendela.
     I.S. : sembarang
     F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
     Jika CC = MARK maka EOP akan menyala (true) */
    
    /* Algoritma */
    pita = fp;
    ADVRESTO();
}

void ADVRESTO() {
    /* Pita dimajukan satu karakter.
     I.S. : Karakter pada jendela =
     CC, CC != MARK
     F.S. : CC adalah karakter berikutnya dari CC yang lama,
     CC mungkin = MARK.
     Jika  CC = MARK maka EOP akan menyala (true) */
    
    /* Algoritma */
    retval = fscanf(pita,"%c",&C);
    eop = (C == MARK);
    if (eop) {
        fclose(pita);
    }
}


void FileToMap(FILE *fp, MATRIKS *room)
{
    indeks i, j;
    
    MakeMATRIKS(8, 8, room);
    
    STARTRESTO(fp);
    for (i = 1; i <= NBrsEff(*room); i++)
    {
        for (j = 1; j <= NKolEff(*room); j++)
        {
            Elmt(*room, i, j) = C;
            ADVRESTO();
            //printf("%d", Elmt(room1, i, j));
        }
        ADVRESTO();
        //printf("\n");
    }
}

void InitMap(MATRIKS *room1, MATRIKS *room2, MATRIKS *room3, MATRIKS *kitchen)
{
    FILE *fp;
    
    fp = fopen("room1.txt", "r");
    FileToMap(fp, room1);
    fp = fopen("room2.txt", "r");
    FileToMap(fp, room2);
    fp = fopen("room3.txt", "r");
    FileToMap(fp, room3);
    fp = fopen("kitchen.txt", "r");
    FileToMap(fp, kitchen);
}

void moveplayer(player *p, MATRIKS room, char cmd, Graph G, adrNode *currLoc)
{
    if(cmd == 'w'){
        if( (Elmt(room, (p->py)-1, p->px) == 'X' ) || (Elmt(room, (p->py)-1, p->px) == 'Y' ) || (Elmt(room, (p->py)-1, p->px) == 'Z' ) || ((Elmt(room, (p->py)-1, p->px) - '1' >= 0) && (Elmt(room, (p->py)-1, p->px) - '1' <= 8)) || (p->py-1 < 0)){ //kondisi dia gabisa gerak
            printf("gabisa gerak kesitu\n");
        }
        else{
            p->py--;
        }
        
    }
    
    if(cmd == 'a'){
        if(( Elmt(room, p->py, p->px-1) == 'X' ) || ( Elmt(room, p->py, p->px-1) == 'Y' ) || ( Elmt(room, p->py, p->px-1) == 'Z' ) || ((Elmt(room, p->py, p->px-1) - '1' >= 0) && (Elmt(room, p->py, p->px-1) - '1' <= 8)) || (p->px-1 < 0)){ //kondisi dia gabisa gerak
            printf("gabisa gerak kesitu\n");
        }
        else{
            p->px--;
        }
    }
    
    if(cmd == 'd'){
        if(( Elmt(room, p->py, p->px+1) == 'X' ) || (Elmt(room, p->py, p->px+1) == 'Y' ) || (Elmt(room, p->py, p->px+1) == 'Z' ) || ((Elmt(room, p->py, p->px+1) - '1' >= 0) && (Elmt(room, p->py, p->px+1) - '1' <= 8)) || (p->px+1 > NKolEff(room))){ //kondisi dia gabisa gerak
            printf("gabisa gerak kesitu\n");
        }
        else{     }
        p->px++;
    }


if(cmd == 's')
{
    if(( Elmt(room, p->py+1, p->px) == 'X' ) || (Elmt(room, p->py+1, p->px) == 'Y' ) || (Elmt(room, p->py+1, p->px) == 'Z' )|| ((Elmt(room, p->py+1, p->px) - '1' >= 0) && (Elmt(room, p->py+1, p->px) - '1' <= 8)) || (p->py+1 > NBrsEff(room)))
    { //kondisi dia gabisa gerak
        printf("gabisa gerak kesitu\n");
    }
    else{
        p->py++;
    }
    
    
}

ChangeRoom(G, currLoc, p);
}

void NearestCust(player p, MATRIKS room, int *ordable){
    char up, down, right, left;
    
    *ordable = Elmt(room, p.py, p.px) - '`';
    
    if((*ordable > 9) || (*ordable < 0)){
        *ordable = -999;
    }
}

void ChangeRoom(Graph G, adrNode *currLoc, player *P)
{
    adrSuccNode Pn;
    
    if (X(*P) == 5 && Y(*P) == 9 && Room(*P) == 1)
    {
        X(*P) = 2;
        Y(*P) = 1;
        Room(*P) = 2;
        Pn = SearchEdge(G, 1, 2);
        *currLoc = Succ(Pn);
    }
    else if (X(*P) == 9 && Y(*P) == 5 && Room(*P) == 2)
    {
        X(*P) = 1;
        Y(*P) = 5;
        Room(*P) = 3;
        Pn = SearchEdge(G, 2, 3);
        *currLoc = Succ(Pn);
    }
    else if (X(*P) == 2 && Y(*P) == 0 && Room(*P) == 3)
    {
        X(*P) = 5;
        Y(*P) = 8;
        Room(*P) = 4;
        Pn = SearchEdge(G, 3, 4);
        *currLoc = Succ(Pn);
    }
    else if (X(*P) == 0 && Y(*P) == 5 && Room(*P) == 4)
    {
        X(*P) = 8;
        Y(*P) = 5;
        Room(*P) = 1;
        Pn = SearchEdge(G, 4, 1);
        *currLoc = Succ(Pn);
    }
    else if (X(*P) == 9 && Y(*P) == 5 && Room(*P) == 1)
    {
        X(*P) = 1;
        Y(*P) = 5;
        Room(*P) = 4;
        Pn = SearchEdge(G, 1, 4);
        *currLoc = Succ(Pn);
    }
    else if (X(*P) == 5 && Y(*P) == 9 && Room(*P) == 4)
    {
        X(*P) = 2;
        Y(*P) = 1;
        Room(*P) = 3;
        Pn = SearchEdge(G, 4, 3);
        *currLoc = Succ(Pn);
    }
    else if (X(*P) == 0 && Y(*P) == 5 && Room(*P) == 3)
    {
        X(*P) = 8;
        Y(*P) = 5;
        Room(*P) = 3;
        Pn = SearchEdge(G, 3, 2);
        *currLoc = Succ(Pn);
    }
    else if (X(*P) == 2 && Y(*P) == 0 && Room(*P) == 2)
    {
        X(*P) = 5;
        Y(*P) = 8;
        Room(*P) = 1;
        Pn = SearchEdge(G, 2, 1);
        *currLoc = Succ(Pn);
    }
    
}

void PrintMap(player P)
{
    
}

boolean AvailOrder(player P, MATRIKS room)
{
    if (Elmt(room, X(P), Y(P)) >= 'a' && Elmt(room, X(P), Y(P)) <= 'j')
    {
        return true;
    }
    else
    {
        return false;
    }
}
