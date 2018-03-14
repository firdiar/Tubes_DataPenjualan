#ifndef BARANG_H_INCLUDED
#define BARANG_H_INCLUDED
#include "LibraryHandler.h"
#include "DataManager.h"
void InsertFirst_DataB(List_DataB &L , adr_B &P);
void InsertLast_DataB(List_DataB &L , adr_B &P);
void Delete_DataB(List_DataB &L , List_DataManagerHandler &L2 , adr_B &P);
void DealocateB(adr_B &P);
adr_B FindByNameB(List_DataB L , string Nama);

#endif // BARANG_H_INCLUDED
