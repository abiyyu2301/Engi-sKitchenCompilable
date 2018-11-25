//
//  Place.c
//  CobaResep
//
//  Created by Abiyyu Ismunandar on 11/25/18.
//  Copyright © 2018 Abiyyu Ismunandar. All rights reserved.
//

#include "Place.h"


//random belum coba
void mengantri(Queue *Q){
    infoqueue X;
    time_t t;
    int i;
    if (rand()%20==7){    //merandom waktu bertambahnya antrian dengan peluang 1/20
        i=rand()%2;
        X.orang=2+i*2; //acak jumlah orang 2/4 orang
        X.kesabaran=30; //kesabaran 30
        Add(Q,X);
    }
}
void Place(Queue *Q,TabMeja *T,MATRIKS *M){
    infoqueue X,Sampah;
    time_t t;
    int i,dua=-1,empat=-1,until;
    boolean found=false,sudah;
    i=0;
    srand((unsigned) time(&t));
    while (!found&&i<=9){            //mencari posisi meja yang tepat
        if (dua!=-1&&empat!=-1){    //jika sudah menemukan posisi meja 2/4
            found=true;
        }else if(!Elmtterisi(*T,i)){    //jika meja sudah terisi
            if (Elmtisi(*T,i)==2){
                dua=i;            //jika ada meja isi 2 yang belum terisi dua berisi indeks mejanya
            }else{
                empat=i;    //jika ada meja isi 4 yang belum terisi empat berisi indeks mejanya
            }
        }
        i++;
    }
    i=Head(*Q);
    if ((InfoOrang(*Q,i)==4)&&(empat!=-1)){    //jika butuh 4 kursi dan ada meja 4 kursi yang kosong
        isimeja(T,M,empat,4,(rand()%25+25));    //isi meja dengan kesabaran random dari 25-49
        Del(Q,&Sampah);
    }else if ((InfoOrang(*Q,i)==2)&&(dua!=-1)){ //jika butuh 2 kursi dan ada meja 2 kursi yang kosong
        isimeja(T,M,dua,2,(rand()%25+25)); //isi meja dengan kesabaran random dari 25-49
        Del(Q,&Sampah);
    }else if ((InfoOrang(*Q,i)==2)&&(empat!=-1)){ //jika butuh 2 kursi dan ada meja 4 kursi yang kosong
        isimeja(T,M,empat,2,(rand()%25+25)); //isi meja dengan kesabaran random dari 25-49
        Del(Q,&Sampah);
    }else if ((InfoOrang(*Q,i)==4)&&(dua!=-1)){ //jika butuh 4 kursi dan ada meja 2 kursi yang kosong
        if (i>Tail(*Q)){                        //ubah agar traversal berjalan karena menggunakan Queue circular
            until=Tail(*Q)+MaxEl(*Q);
        }else{
            until=Tail(*Q);
        }
        i++;
        sudah=false;
        while (until>=i&&!sudah){    //mencari antrian yang butuh 2 kursi saja
            if (InfoOrang(*Q,(i-1)%MaxEl(*Q)+1)==2){
                isimeja(T,M,dua,2,(rand()%25+25)); //isi meja dengan kesabaran random dari 25-49
                sudah=true;
                Deli(Q,(i-1)%MaxEl(*Q)+1,&Sampah);
            }else{
                i++;
            }
        }
        if (!sudah){    //jika tidak ada yang hanya butuh 2 kursi maka tidak ada yang kosong
            printf("Tidak ada tempat kosong, mohon bersabar\n");
        }
    }else{         //jika meja penuh
        printf("Tidak ada tempat kosong, mohon bersabar\n");
    }
}
