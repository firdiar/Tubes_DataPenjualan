#include "Toko.h"
#include "DataManager.h"


///Memasukan Data Kedalam List Dari Depan
void InsertFirst_DataT(List_DataT &L , adr_T P){
    if(First(L) == NULL){
        ///jika dia tidak berisi
        Last(L) = P;
    }else{
        ///jika dia berisi
        Prev(First(L)) = P;
        Next(P) = First(L);
    }
    First(L) = P;
}

///Memasukan Data Kedalam List Dari Belakang
void InsertLast_DataT(List_DataT &L , adr_T P){
    if(Last(L)==NULL){
        ///jika dia kosong
        First(L)=P;
    }else{
        ///jika dia berisi
        Next(Last(L)) = P;
        Prev(P) = Last(L);
    }
    Last(L) = P;

}

///Menghapus Data P di List L
void Delete_DataT(List_DataT &L , List_DataManagerHandler &L2, adr_T &P){

    if(P == NULL)
            return;


    /// P Pasti Ada dalam List
    DeleteTokoInList( L2 , P);
    adr_T q = First(L);

    while(q != P){
        ///Looping tidak infinity karena P pasti ada di dalam List
        q = Next(q);
    }

    if(Next(q) == NULL){
        ///jika data yg dihapus adalah elm terakhir
        adr_T z = Prev(q);
        if(q != First(L)){
            ///jika dia di urutan terakhir z!= NULL
            Next(z) = NULL;
        }else{
            ///jika dia 1 elm
            First(L) = NULL;
        }
        Last(L) = z;
    }else{
        ///jika dia elm bukan di akhir
        if(q == First(L)){
            ///jika dia elm pertama
            First(L) = Next(q);
            Prev(First(L)) = NULL;
        }else{
            ///jika dia bukan elm pertama
            adr_T z = Prev(q);
            Next(z) = Next(q);
        }
    }

    q = NULL;
    DealocateT(P);
}

///Menghapus Data Dari Memory
void DealocateT(adr_T &P){
    Prev(P) = NULL;
    Next(P) = NULL;
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
