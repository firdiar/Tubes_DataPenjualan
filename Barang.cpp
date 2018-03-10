#include "Barang.h"

///Memasukan Data Kedalam List Dari Depan
void InsertFirst_DataB(List_DataB &L , adr_B P){
    Next(P) = First(L);
    First(L) = P;
}

///Memasukan Data Kedalam List Dari Belakang
void InsertLast_DataB(List_DataB &L , adr_B P){
    adr_B q = First(L);
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
void Delete_DataB(List_DataB &L , List_DataManagerHandler &L2 , adr_B &P){

    if(P == NULL)
            return;


    /// P Pasti Ada dalam List
    DeleteBarangInList(L2 , P);

    adr_B z = NULL;
    adr_B q = First(L);
    while(q != P){
        z = q;
        q = Next(q);
    }
    if(z == NULL){
        if(Next(P) == NULL){
            First(L) = NULL;
        }else{
            First(L) = Next(P);
        }

    }else{
        ///jika P elm terakhir maka next z akan bernilai null
        Next(z) = Next(P);

    }

    DealocateB(P);
}

///Menghapus Data Dari Memory
void DealocateB(adr_B &P){
    delete(P);
    P = NULL;
}

///Mencari Address Berdasarkan Nama
adr_B FindByNameB(List_DataB L , string Nama){
    adr_B P = First(L);

    while(P!=NULL && Info(P).Nama != Nama){
        P = Next(P);
        //cout<<Info(P).Nama<<endl;
    }

    return P;

}
