#include "LibraryHandler.h"

///Membuat Balok Baru Toko
void Allocate_DataT(adr_T &p , string nama){
    p = new DataT;
    Info(p).Nama = nama;
    Next(p) = NULL;
}

///Membuat Balok Baru Barang
void Allocate_DataB(adr_B &p , string nama , int harga){
    p = new DataB;
    Info(p).Nama = nama;
    Info(p).Harga = harga;
    Next(p) = NULL;
}


///Membuat Balok Baru Penghubung Toko&Barang
void Allocate_DataManager(adr_Data &p , adr_T TokoAdr , adr_B BarangAdr){
    p = new DataManagerHandler;
    Toko(p) = TokoAdr;
    Barang(p) = BarangAdr;
    Next(p) = NULL;
}


///Membuat Balok Baru Toko
adr_T Allocate_DataT(string nama){
    adr_T  p = new DataT;
    Info(p).Nama = nama;
    Next(p) = NULL;
    return p;
}

///Membuat Balok Baru Barang
adr_B Allocate_DataB(string nama , int harga){
    adr_B p = new DataB;
    Info(p).Nama = nama;
    Info(p).Harga = harga;
    Next(p) = NULL;
    return p;
}

///Membuat Balok Baru Penghubung Toko&Barang
adr_Data Allocate_DataManager(adr_T TokoAdr , adr_B BarangAdr){
    adr_Data p = new DataManagerHandler;
    Toko(p) = TokoAdr;
    Barang(p) = BarangAdr;
    Next(p) = NULL;
    return p;
}




///Membuat List Data Baru
List_DataT CreateList_DataT(){
    List_DataT p;
    First(p) = NULL;
    return p;
}

///Membuat List Data Baru
List_DataB CreateList_DataB(){
    List_DataB p;
    First(p) = NULL;
    return p;
}

///Membuat List DataManager Baru
List_DataManagerHandler CreateList_DataManager(){
    List_DataManagerHandler p;
    First(p) = NULL;
    return p;
}

///Mengoutputkan Semua Data di List Toko
void Print_DataT(List_DataT L){
    adr_T p = First(L);
    int i = 1;
    while(p != NULL){
        cout<<i<<Info(p).Nama<<endl;
        p = Next(p);
        i++;
    }
}

///Mengoutputkan Semua Data di List Barang
void Print_DataB(List_DataB L){
    adr_B p = First(L);
    int i = 1;
    while(p != NULL){
        cout<<i<<". "<<Info(p).Nama<<endl;
        cout<<"    Rp."<<Info(p).Harga;
        p = Next(p);
        i++;
        cout<<endl;
    }
}

///Mengoutputkan Semua Barang Yang Dijual Toko Terterntu
void Print_BarangInToko(List_DataManagerHandler L , adr_T p){
    adr_Data q = First(L);
    int i = 1;
    cout<<"  Toko "<<Info(p).Nama<<endl;
    while(q != NULL){
        if(Toko(q) == p){
            cout<<"   "<<i<<". "<<Info(Barang(q)).Nama<<"\t"<<endl;
            i++;
             cout<<endl;
        }
        q = Next(q);
    }
    if(i == 1){
        cout<<"[Kosong]"<<endl;
    }
}

///Mengoutputkan Barang ini di jual di toko apa saja
void Print_BarangSellInToko(List_DataManagerHandler L , adr_B p){
    adr_Data q = First(L);
    int i = 1;
    cout<<"  Item "<<Info(p).Nama<<endl;
    while(q != NULL){
        if(Barang(q) == p){
            cout<<"   "<<i<<". "<<Info(Toko(q)).Nama<<"\t"<<endl;
            i++;
             cout<<endl;
        }
        q = Next(q);
    }
    if(i == 1){
        cout<<"[Tidak Dijual Dimanapun]"<<endl;
    }
}

///Mengoutputkan Semua Barang Yang Dijual Disemua Toko
void Print_AllBarangInToko(List_DataT L , List_DataManagerHandler L2){

    adr_T p = First(L);
    while(p != NULL){
        Print_BarangInToko(L2 , p);
        p = Next(p);
       // cout<<endl;
    }

}

///Mengoutputkan Semua Toko Yang Menjual Barang
void Print_AllBarangSellInToko(List_DataB L , List_DataManagerHandler L2){

    adr_B p = First(L);
    while(p != NULL){
        Print_BarangSellInToko(L2 , p);
        p = Next(p);
       // cout<<endl;
    }

}














