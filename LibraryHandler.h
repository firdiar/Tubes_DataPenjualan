#ifndef LIBRARYHANDLER_H_INCLUDED
#define LIBRARYHANDLER_H_INCLUDED
#define Info(A) A->Info
#define Next(A) A->Next
#define Prev(A) A->Prev

#define Barang(A) A->Barang
#define Toko(A) A->Toko
#define First(A) A.First
#define Last(A) A.Last


#include <iostream>

using namespace std;

typedef struct DataT *adr_T;
typedef struct DataB *adr_B;
typedef struct DataManagerHandler *adr_Data;

/// Semua Struct Data

///InfoType nya
struct InfoToko{
    string Nama;
};

struct InfoBarang{
    string Nama;
    int Harga;
};

///elmListnya
  ///DoubleList
struct DataT{
    InfoToko Info;
    adr_T Next;
    adr_T Prev;
};
    ///SinggleList
struct DataManagerHandler{
    adr_T Toko;
    adr_B Barang;
    adr_Data Next;
};
 ///Singgle CircularList + Last
struct DataB{
    InfoBarang Info;
    int Harga;
    adr_B Next;
};

///Listnya
struct List_DataB{
    adr_B First;
    adr_B Last;
};
struct List_DataT{
    adr_T First;
    adr_T Last;
};
struct List_DataManagerHandler{
    adr_Data First;
};


/// <End Semua Struct>


///Function
void Allocate_DataT(adr_T &p , string nama);

void Allocate_DataB(adr_B &p , string nama , int harga);

void Allocate_DataManager(adr_Data &p , adr_T TokoAdr , adr_B BarangAdr);

adr_T Allocate_DataT(string nama);

adr_B Allocate_DataB(string nama , int harga);

adr_Data Allocate_DataManager(adr_T TokoAdr , adr_B BarangAdr);



List_DataT CreateList_DataT();

List_DataB CreateList_DataB();

List_DataManagerHandler CreateList_DataManager();



void Print_DataT(List_DataT L);

void Print_DataB(List_DataB L);

void Print_BarangInToko(List_DataManagerHandler L , adr_T p);

void Print_BarangSellInToko(List_DataManagerHandler L , adr_B B);

void Print_AllBarangInToko(List_DataT L , List_DataManagerHandler L2);

void Print_AllBarangSellInToko(List_DataB L , List_DataManagerHandler L2);
#endif // LIBRARYHANDLER_H_INCLUDED
