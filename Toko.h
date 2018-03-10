#ifndef TOKO_H_INCLUDED
#define TOKO_H_INCLUDED
#include"LibraryHandler.h"

void InsertFirst_DataT(List_DataT &L , adr_T P);
void InsertLast_DataT(List_DataT &L , adr_T P);
void Delete_DataT(List_DataT &L , List_DataManagerHandler &L2, adr_T &P);
void DealocateT(adr_T &P);
adr_T FindByNameT(List_DataT L , string Nama);

#endif // TOKO_H_INCLUDED
