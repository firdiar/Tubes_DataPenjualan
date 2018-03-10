#ifndef DATAMANAGER_H_INCLUDED
#define DATAMANAGER_H_INCLUDED
#include "LibraryHandler.h"

void InsertFirst_DataM(List_DataManagerHandler &L , adr_Data P);
void InsertLast_DataM(List_DataManagerHandler &L , adr_Data P);
void InsertAfter_DataM(List_DataManagerHandler &L , adr_Data prec , adr_Data P);
void Delete_DataM(List_DataManagerHandler &L , adr_Data P);
void DealocateB(adr_Data &P);

adr_Data FindByNameM(List_DataManagerHandler L , adr_T toko);
adr_Data FindByBarangM(List_DataManagerHandler L , adr_B barang);
adr_Data FindByNameNBarangM(List_DataManagerHandler L , adr_T toko , adr_B barang);

void DeleteTokoInList(List_DataManagerHandler &L , adr_T P );
void DeleteBarangInList(List_DataManagerHandler &L , adr_B P );

adr_T CariTerlengkap(List_DataManagerHandler L , List_DataT L2);
adr_T CariTerTaklengkap(List_DataManagerHandler L,List_DataT L2);
#endif // DATAMANAGER_H_INCLUDED
