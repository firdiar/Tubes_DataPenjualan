#include "DataManager.h"

///Memasukan Data Kedalam List Dari Depan
void InsertFirst_DataM(List_DataManagerHandler &L , adr_Data P){
    Next(P) = First(L);
    First(L) = P;
}

///Memasukan Data Kedalam List Dari Belakang
void InsertLast_DataM(List_DataManagerHandler &L , adr_Data P){
    adr_Data q = First(L);
    while(q != NULL && Next(q) != NULL){
        q = Next(q);
    }
    if(q != NULL){
        Next(q) = P;
    }else{
        First(L) = P;
    }

}

///Memasukan Data baru setelah prec
void InsertAfter_DataM(List_DataManagerHandler &L , adr_Data prec , adr_Data P){
    if(prec == NULL){
        InsertLast_DataM(L , P);
    }else{
        Next(P) = Next(prec);
        Next(prec) = P;
    }
}

///Menghapus Data P di List L
void Delete_DataM(List_DataManagerHandler &L , adr_Data P){

    if(P == NULL)
            return;


    /// P Pasti Ada dalam List

    adr_Data z = NULL;
    adr_Data q = First(L);
    while(q != P){
        z = q;
        q = Next(q);
    }
    if(z != NULL){
        ///jika P elm terakhir maka next z akan bernilai null
        Next(z) = Next(P);
    }else{
        First(L) = Next(P);
    }
    DealocateB(P);
}

///Menghapus Data Dari Memory
void DealocateB(adr_Data &P){
    Next(P) = NULL;
    delete(P);
    P = NULL;
}


///Mencari Data Berdasarkan Address Toko
adr_Data FindByNameM(List_DataManagerHandler L , adr_T toko){
    adr_Data P = First(L);
    while(P !=NULL && Info(Toko(P)).Nama != Info(toko).Nama){
        P = Next(P);
    }

    return P;

}


///Mencari Data Berdasarkan Address Barang
adr_Data FindByBarangM(List_DataManagerHandler L , adr_B barang){
    adr_Data P = First(L);
    while(P !=NULL && Info(Barang(P)).Nama != Info(barang).Nama){
        P = Next(P);
    }

    return P;

}

///Mencari Data Berdasarkan Address Toko Dan Barang
adr_Data FindByNameNBarangM(List_DataManagerHandler L , adr_T toko , adr_B barang){
    adr_Data P = First(L);
    while(P !=NULL && !((Info(Toko(P)).Nama == Info(toko).Nama)&&(Info(Barang(P)).Nama == Info(barang).Nama))  ){
        P = Next(P);
    }

    return P;

}

///Menghapus Semua elm yang terdapat toko
void DeleteTokoInList(List_DataManagerHandler &L , adr_T P ){
    adr_Data q = First(L);
    while(q != NULL){
        if(Toko(q) == P){
            adr_Data z = q;
            q = Next(q);
            Delete_DataM( L , z);
        }else{
            q = Next(q);
        }
    }

}

///mengahpus semua elm yang terdapat barang
void DeleteBarangInList(List_DataManagerHandler &L , adr_B P ){
    adr_Data q = First(L);
    while(q != NULL){
        if(Barang(q) == P){
            adr_Data z = q;
            q = Next(q);
            Delete_DataM( L , z);
        }else{
            q = Next(q);
        }
    }

}

///mencari toko yang menjual baranga paling banyak
adr_T CariTerlengkap(List_DataManagerHandler L , List_DataT L2){

    adr_T P = First(L2);
    adr_Data Q = NULL;
    adr_T R = NULL;
    int sum = 0;
    int sumcurrent = 0;
    while(P != NULL){
        sumcurrent = 0;
        Q = First(L);
        while(Q != NULL){
            if(Toko(Q) == P){
                sumcurrent++;
            }
            Q = Next(Q);
        }

        if(sumcurrent>sum || sum == 0){
            sum = sumcurrent;
            R = P;
        }
        Q = NULL;
        P = Next(P);
    }
    return R;

}


///mencari toko yang menjual barang paling sedikit
adr_T CariTerTaklengkap(List_DataManagerHandler L,List_DataT L2){

    adr_T P = First(L2);
    adr_Data Q = NULL;
    adr_T R = NULL;
    int sum = 0;
    int sumcurrent = 0;
    while(P != NULL){
        Q = First(L);
        sumcurrent = 0;
        while(Q != NULL){
            if(Toko(Q) == P){
                sumcurrent++;
            }
            Q = Next(Q);
        }

        if(sumcurrent<sum||R == NULL){
            sum = sumcurrent;
            R = P;
        }
        Q = NULL;
        P = Next(P);
    }
    return R;

}
