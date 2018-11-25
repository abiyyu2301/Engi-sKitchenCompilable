#ifndef GRAPH_H
#define GRAPH_H

#include "boolean.h"
#include <stdio.h>
#include <stddef.h>

#define Nil NULL

typedef struct tNode *adrNode;
typedef struct tSuccNode *adrSuccNode;
typedef struct tNode{
    int Id;
    int NPred;
    adrSuccNode Trail;
    adrNode Next;
} Node;
typedef struct tSuccNode {
    adrNode Succ;
    adrSuccNode Next;
} SuccNode;
typedef struct {
    adrNode First;
} Graph;

#define First(G) (G).First
#define Id(Pn) Pn->Id
#define NPred(Pn) Pn->NPred
#define Trail(Pn) Pn->Trail
#define Next(Pn) Pn->Next
#define Succ(Pt) Pt->Succ
#define NextS(Pt) Pt->Next

/* { *** Manajemen Memory List Simpul (Leader) *** } */
adrNode AlokNode(int X);

adrSuccNode AlokSuccNode(adrNode Pn);

void InsertNode(Graph *G, int X, adrNode *Pn);

void InsertEdge(Graph *G, int prec, int succ);

adrNode SearchNode(Graph G, int X);

adrSuccNode SearchEdge(Graph G, int prec, int succ);

#endif
