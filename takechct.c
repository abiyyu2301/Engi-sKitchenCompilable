#include "takechct.h"


void Take (Stack *Hand, ElType M)
{
    /* Kamus */
    infotypeStack benda;
    /* Algoritma */
    if (M=='A') {
       // benda="Piring";
    }
    else if (M=='B') {
        //benda="Sendok";
    }
    else if (M=='C') {
        //benda="Garpu";
    }
    else if (M=='D') {
        //benda="Es Krim";
    }
    else if (M=='E') {
        //benda="Nasi";
    }
    else if (M=='F') {
        //benda="Roti";
    }
    else if (M=='G') {
        //benda="Spaghetti";
    }
    else if (M=='H') {
        //benda="Pisang";
    }
    else if (M=='I') {
        //benda="Stroberi";
    }
    else if (M=='J') {
        //benda="Stroberi";
    }
    else if (M=='K') {
        //benda="Telur";
    }
    else if (M=='L') {
        //benda="Ayam Goreng";
    }
    else if (M=='M') {
        //benda="Patty";
    }
    else if (M=='N') {
        //benda="Sosis";
    }
    else if (M=='O') {
        //benda="Bolognese";
    }
    else if (M=='P') {
        //benda="Carbonara";
    }
    else if (M=='Q') {
        //benda="Keju";
    }
    Push(Hand, benda);
}

void Ch (Stack *Hand, infotypeStack *Sampah)
{
    /* Kamus */
    
    /* Algoritma */
    while (!(StackIsEmpty(*Hand))) {
        Pop(Hand, Sampah);
    }
}

void Ct (Stack *Tray, infotypeStack *Sampah)
{
    /* Kamus */
    
    /* Algoritma */
    while (!(StackIsEmpty(*Tray))) {
        Pop(Tray, Sampah);
    }
}
