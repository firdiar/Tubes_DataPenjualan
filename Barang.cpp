#include "Barang.h"

///Memasukan Data Kedalam List Dari Depan
void InsertFirst_DataB(List_DataB &L , adr_B &P){
    if(First(L)==NULL){
        ///Jika List Kosong
        Next(P) = P;
        Last(L) = P;
    }else{
        ///Jika Ada Isinya
        Next(P) = First(L);
        Next(Last(L)) = P;
    }
    First(L) = P;
}

///Memasukan Data Kedalam List Dari Belakang
void InsertLast_DataB(List_DataB &L , adr_B &P){
    if(Last(L) == NULL){
        ///Jika List Kosong
        Next(P) = P;
        First(L) = P;
    }else{
        ///Jika dia Ada Isisnya
        Next(Last(L)) = P;
        Next(P) = First(L);
    }
    Last(L) = P;

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
        ///Tidak Mungkin Infinity loop karna P ada di List
        z = q;
        q = Next(q);
    }


    if(q == First(L)){
        ///artinya P elm pertama
        if(Next(P) == P){
            ///List  1 elm
            First(L) = NULL;
            Last(L) = NULL;
        }else{
            ///list >1 elm
            First(L) = Next(P);
            Next(Last(L)) = First(L);
        }
    }else if(q == Last(L)){
        ///jika P == Last(L) maka z != NULL
        Next(z) = First(L);
        Last(L) = z;
    }else{
        ///P di tengah maka z != NULL
        Next(z) = Next(q);
    }
    q = NULL;
    DealocateB(P);
}

///Menghapus Data Dari Memory
void DealocateB(adr_B &P){
    Next(P) = NULL;
    delete(P);
    P = NULL;
}

///Mencari Address Berdasarkan Nama
adr_B FindByNameB(List_DataB L , string Nama){
    if(First(L)==NULL)
        return NULL;


    adr_B P = First(L);
    //cout<<"tes"<<endl;
    while(P!=Last(L) && Info(P).Nama != Nama){
        P = Next(P);
        //cout<<Info(P).Nama<<endl;
    }
    //cout<<P<<endl;
    if(Info(P).Nama == Nama){
        return P;
    }else{
        return NULL;
    }

}
