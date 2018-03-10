#include "Toko.h"
#include "DataManager.h"


///Memasukan Data Kedalam List Dari Depan
void InsertFirst_DataT(List_DataT &L , adr_T P){
    Next(P) = First(L);
    First(L) = P;
}

///Memasukan Data Kedalam List Dari Belakang
void InsertLast_DataT(List_DataT &L , adr_T P){
    adr_T q = First(L);
    while(q != NULL && Next(q) != NULL){
        q = Next(q);
    }
    if(q != NULL){
        Next(q) = P;
    }else{
        First(L) = P;
    }

}

///Menghapus Data P di List L
void Delete_DataT(List_DataT &L , List_DataManagerHandler &L2, adr_T &P){

    if(P == NULL)
            return;


    /// P Pasti Ada dalam List
    DeleteTokoInList( L2 , P);
    adr_T z = NULL;
    adr_T q = First(L);
    while(q != P){
        z = q;
        q = Next(q);
    }
    if(z != NULL){
        ///jika P elm terakhir maka next z akan bernilai null
        Next(z) = Next(P);
    }else{
        if(Next(P) != NULL){
            First(L) = Next(P);
        }else{
            First(L) = NULL;
        }
    }


    DealocateT(P);
}

///Menghapus Data Dari Memory
void DealocateT(adr_T &P){
    delete(P);
    P = NULL;
}

///Mencari Address Berdasarkan Nama
adr_T FindByNameT(List_DataT L , string Nama){
    adr_T P = First(L);
    while(P!=NULL && Info(P).Nama != Nama){
        P = Next(P);
    }

    return P;

}
