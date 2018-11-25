#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

adrNode AlokNode(int X)
{
    adrNode P;
    
    P = (adrNode) malloc (sizeof(Node));
    
    if(P != Nil)
    {
        Id(P) = X;
        NPred(P) = 0;
        Trail(P) = Nil;
        Next(P) = Nil;
        return P;
    }
    else
    {
        return Nil;
    }
}

adrSuccNode AlokSuccNode(adrNode Pn)
{
    adrSuccNode Pt;
    
    Pt = (adrSuccNode) malloc (sizeof(SuccNode));
    
    if(Pt != Nil)
    {
        Succ(Pt) = Pn;
        Next(Pt) = Nil;
        return Pt;
    }
    else
    {
        return Nil;
    }
}

void InsertNode(Graph *G, int X, adrNode *Pn)
{
    *Pn = AlokNode(X);
    adrNode N = *Pn;
    //insert first
    if(*Pn != Nil){
        Next(N) = First(*G);
        First(*G) = *Pn;
    }
}

void InsertEdge(Graph *G, int prec, int succ)
{
    adrNode APrec,  ASucc;
    adrSuccNode PSucc;
    
    APrec = SearchNode(*G, prec);
    ASucc = SearchNode(*G, succ);
    
    PSucc = AlokSuccNode(ASucc);
    NextS(PSucc) = Trail(APrec);
    Trail(APrec) = PSucc;
    
}

adrNode SearchNode(Graph G, int X)
{
    adrNode P = First(G);
    while(Id(P) != X)
    {
        P = Next(P);
    }
    return P;
}

adrSuccNode SearchEdge(Graph G, int prec, int succ)
{
    adrNode APrec;
    
    APrec = SearchNode(G, prec);
    
    adrSuccNode P = Trail(APrec);
    while(Id(Succ(P)) != succ)
    {
        P = Next(P);
    }
    return P;
}

void InitGraph(Graph *G)
{
    int i;
    adrNode P;
    
    for (i = 4; i >= 1; i--)
    {
        InsertNode(G, i, &P);
    }
    
    InsertEdge(G, 1, 2);
    InsertEdge(G, 1, 4);
    
    InsertEdge(G, 2, 1);
    InsertEdge(G, 2, 3);
    
    InsertEdge(G, 3, 2);
    InsertEdge(G, 3, 4);
    
    InsertEdge(G, 4, 1);
    InsertEdge(G, 4, 3);
}
