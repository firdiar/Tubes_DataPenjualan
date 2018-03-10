#ifndef PROGRAMMENU_H_INCLUDED
#define PROGRAMMENU_H_INCLUDED
#include "LibraryHandler.h"
#include "Toko.h"
#include "Barang.h"
#include "DataManager.h"
#include <cstdlib>

void MainMenu(int &ans);
void TambahToko(List_DataT &L);
void TambahBarang(List_DataB &L);
void HapusToko(List_DataT &L , List_DataManagerHandler &L2);
void HapusBarang(List_DataB &L , List_DataManagerHandler &L2);
void EditBarangToko(List_DataT &L , List_DataB &L2 ,List_DataManagerHandler &L3);
void TampilkanSeluruhDataToko(List_DataT L, List_DataManagerHandler L2);
void TampilkanSeluruhDataBarang(List_DataB L, List_DataManagerHandler L2);
void TampilkanDataTokoCari(List_DataT L, List_DataManagerHandler L2);
void TampilkanDataBarangCari(List_DataB L, List_DataManagerHandler L2);
void TampilkanTokoTerlengkap(List_DataManagerHandler L , List_DataT L2);
void TampilkanTokoTerTaklengkap(List_DataManagerHandler L , List_DataT L2);

#endif // PROGRAMMENU_H_INCLUDED
