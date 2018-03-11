#include "ProgramMenu.h"

void MainMenu(int &ans){
    system("CLS");
    cout << " Main Menu : " <<endl;
    cout << " 1.  Tambah Toko" <<endl;
    cout << " 2.  Tambah Barang" <<endl;
    cout << " 3.  Hapus Toko" <<endl;
    cout << " 4.  Hapus Barang" <<endl;
    cout << " 5.  Edit Barang Toko" <<endl;
    cout << " 6.  Tampilkan seluruh Data Toko" <<endl;
    cout << " 7.  Tampilkan seluruh Data Barang" <<endl;
    cout << " 8.  Tampilkan Data Toko (Cari)" <<endl;
    cout << " 9.  Tampilkan Data Barang (cari)" <<endl;
    cout << " 10. Tampilkan Data Toko (Terlengkap)" <<endl;
    cout << " 11. Tampilkan Data Toko (Tertidak lengkap)" <<endl;
    cout << " 12. Exit" <<endl;

    do{
        cout << " Silakan Pilih Menu Yang Anda Mau[1-12]" <<endl;
        cin>>ans;
    }while(ans > 12 || ans <= 0);

}

///Menanmbahkan Data Toko di List Toko
void TambahToko(List_DataT &L){
     string nama;
     cout << " Menu Tambah Toko " <<endl;
    do{


        cout << " Masukan Nama Toko : ";
        cin >> nama; cout<<endl;
        adr_T P = FindByNameT(L , nama);
        if(P==NULL){
            P = Allocate_DataT(nama);
            InsertLast_DataT(L , P);
            cout<<" Data Berhasil Dimasukan"<<endl;
        }else{
            cout<<" Data Sudah Ada"<<endl;
        }
        cout<<endl;
        cout<<" Ingin Memasukan Data Toko Lagi?[Y/y]"<<endl;
        cin>>nama;
    }while(nama == "Y" || nama == "y");
}


///Menambahkan Data Barang Di List Barang
void TambahBarang(List_DataB &L){
     string nama;
     cout << " Menu Tambah Barang " <<endl;
    do{

        int harga;

        cout << " Masukan Nama Barang : ";
        cin >> nama; cout<<endl;
        adr_B P = FindByNameB(L , nama);
        if(P == NULL){
            cout << " Masukan Harga Barang : ";
            cin >> harga; cout<<endl;
            P = Allocate_DataB(nama , harga);

            InsertLast_DataB(L , P);

            cout<<" Data Berhasil Dimasukan"<<endl;
        }else{
            cout<<" Nama Barang Sudah Ada"<<endl;
        }
        cout<<endl;
        cout<<" Ingin Memasukan Barang Lagi?[Y/y]"<<endl;
        cin>>nama;
    }while(nama == "Y" || nama == "y");
}

///Menghapus Toko Beserta Relasinya
void HapusToko(List_DataT &L , List_DataManagerHandler &L2){
    cout<<" Menu Hapus Toko"<<endl;
    string nama;
    ///mengeluarkan semua data barang
    cout<<" Ingin Menampilkan seluruh Data Toko?[Y/y]"<<endl;
    cin>>nama;
    if(nama == "Y" || nama == "y")
        Print_DataT(L);
    do{
        cout<<" Masukan Nama Toko Yang Ingin Dihapus"<<endl;
        cin>>nama;
        adr_T T = FindByNameT(L , nama);
        if(T!= NULL){
            Delete_DataT(L , L2 , T);
            cout<<" Toko Berhasil Dihapus"<<endl;
        }else{
            cout<<" Maaf Data Tidak Ada"<<endl;
        }
        cout<<endl;
        cout<<" Ingin Menghapus Toko Lagi?[Y/y]"<<endl;
        cin>>nama;
    }while(nama == "Y" || nama == "y");

}


///Menghapus Barang Beserta Relasinya
void HapusBarang(List_DataB &L , List_DataManagerHandler &L2){
    cout<<" Menu Hapus Barang"<<endl;
    string nama;
    ///mengeluarkan semua data barang
    cout<<" Ingin Menampilkan seluruh Data Barang?[Y/y]"<<endl;
    cin>>nama;
    if(nama == "Y" || nama == "y")
        Print_DataB(L);
    do{
        cout<<" Masukan Nama Barang Yang Ingin Dihapus"<<endl;
        cin>>nama;
        adr_B B = FindByNameB(L , nama);
        if(B == NULL){
            cout<<" Maaf Data Tidak Ada"<<endl;

        }else{
            Delete_DataB(L , L2 , B);
            cout<<" Barang Berhasil Dihapus"<<endl;

        }
        cout<<endl;
        cout<<" Ingin Menghapus Barang Lagi?[Y/y]"<<endl;
        cin>>nama;
    }while(nama == "Y" || nama == "y");

}


///Mengedit Barang yang Ada dii toko delete or add
void EditBarangToko(List_DataT &L , List_DataB &L2 ,List_DataManagerHandler &L3){


    string nama;
    cout<<" Menu Edit Barang Toko"<<endl;
    cout<<" Masukan Nama Toko Yang Ingin Diedit : " <<endl;
    cin>>nama; cout<<endl;
    adr_T T = FindByNameT(L ,nama);
    if(T == NULL){
        cout<<" Maaf Data Toko Tidak Ditemukan"<<endl;
        return;
    }

    cout<<" Mengedit Toko "<<Info(T).Nama<<endl;
    cout<<" Silakan Pilih : " <<endl;
    cout<<" 1. Menambah Barang " <<endl;
    cout<<" 2. Menghapus Barang " <<endl;
    do{
        cout<<"Selecting..."<<endl;
        cin>>nama;
    }while(nama != "1" && nama != "2");
    string input;






    switch(atoi(nama.c_str())){
        case 1:
            ///mengeluarkan semua data barang
            cout<<" Ingin Menampilkan seluruh Data Barang?[Y/y]"<<endl;
            cin>>input;
            if(input == "Y" || input == "y")
                Print_DataB(L2);

            ///menambahkan barang ke dalam toko
            do{
                cout<<" Masukan Nama Barang Yang Ingin Ditambah Kedalam Toko"<<endl;
                cin>>nama;
                adr_B B = FindByNameB(L2 , nama);
                if(B == NULL){
                    cout<<" Maaf Data Barang Tidak Ditemukan"<<endl;
                }else if(FindByNameNBarangM(L3 , T , B) != NULL){
                    cout<<" Data Tersebut Sudah Ada"<<endl;
                }else{
                    InsertAfter_DataM(L3 , FindByNameM(L3,T) , Allocate_DataManager(T , B));
                    cout<<" Data Berhasil Ditambahkan"<<endl;
                }
                cout<<" Ingin Memasukan Barang Lagi?[Y/y]"<<endl;
                cin>>nama;
            }while(nama == "Y" || nama == "y");
        break;

        case 2:
            ///Mengeluarkan semua barang yang ada di toko
            cout<<" Ingin Menampilkan Data Barang di Toko Ini?[Y/y]"<<endl;
            cin>>input;
            if(input == "Y" || input == "y")
                Print_BarangInToko(L3 , T);

             ///menghapus barang dari toko
            do{
                cout<<" Masukan Nama Barang Yang Ingin Dihapus dari Toko"<<endl;
                cin>>nama;
                adr_B B = FindByNameB(L2 , nama);
                adr_Data M = FindByNameNBarangM(L3 , T , B);
                if(B == NULL){
                    cout<<" Maaf Data Barang Tidak Ditemukan"<<endl;
                }else if( M != NULL){
                    Delete_DataM(L3 , M);
                    cout<<" Data Berhasil Dihapus"<<endl;
                }else{
                    cout<<" Data Barang Tidak Ada Di Toko"<<endl;
                }


                cout<<" Ingin Menghapus Barang Lagi?[Y/y]"<<endl;
                cin>>nama;
            }while(nama == "Y" || nama == "y");


        break;

    }


}

///Menampilkan Semua Data Barang yang ada di semua Toko
void TampilkanSeluruhDataToko(List_DataT L, List_DataManagerHandler L2){
    cout << " Mengeluarkan Semua Data Toko... " <<endl;
    Print_AllBarangInToko(L , L2);
    cout <<endl;
    cout << " Mengeluarkan Semua Data Selesai " <<endl;
}

///Menampilkan Semua Barang Di Jual Di Toko Apa Saja
void TampilkanSeluruhDataBarang(List_DataB L, List_DataManagerHandler L2){
    cout << " Mengeluarkan Semua Data Barang... " <<endl;
    Print_AllBarangSellInToko(L , L2);
    cout <<endl;
    cout << " Mengeluarkan Semua Data Selesai " <<endl;
}

void TampilkanDataTokoCari(List_DataT L, List_DataManagerHandler L2){
    string input;
    cout<<" Ingin Menampilkan Data Nama semua Toko ?[Y/y]"<<endl;
    cin>>input;
    if(input == "Y" || input == "y")
        Print_DataT(L);

    do{
        cout<<" Masukan Nama Toko : ";
        cin>>input;
        cout<<endl;

        adr_T T = FindByNameT(L,input);
        if(T==NULL){
            cout<<" Toko Tidak Dapat Ditemukan"<<endl;
        }else{
            Print_BarangInToko(L2 , T);
        }
        cout<<" ingin Menampilkan Toko Lain"<<endl;
        cin>>input;
    }while(input == "Y" || input == "y");


}

void TampilkanDataBarangCari(List_DataB L, List_DataManagerHandler L2){
    string input;
    cout<<" Ingin Menampilkan Data Nama semua Barang ?[Y/y]"<<endl;
    cin>>input;
    if(input == "Y" || input == "y")
        Print_DataB(L);

    do{
        cout<<" Masukan Nama Toko : ";
        cin>>input;
        cout<<endl;

        adr_B B = FindByNameB(L,input);
        if(B==NULL){
            cout<<" Toko Tidak Dapat Ditemukan"<<endl;
        }else{
            Print_BarangSellInToko(L2 , B);
        }
        cout<<" ingin Menampilkan Barang Lain"<<endl;
        cin>>input;
    }while(input == "Y" || input == "y");


}

///Menampilkan Toko Dengan Item Terbanyak
void TampilkanTokoTerlengkap(List_DataManagerHandler L , List_DataT L2){
    adr_T T;
    T = CariTerlengkap(L , L2);
    cout<<" Toko Terlengkap"<<endl;
    cout<<endl;
    Print_BarangInToko(L , T);

}

///Menampilkan Toko Dengan Item Paling Sedikit
void TampilkanTokoTerTaklengkap(List_DataManagerHandler L , List_DataT L2){
    adr_T T;
    T = CariTerTaklengkap(L , L2);
    cout<<" Toko Paling Tidak Lengkap"<<endl;
    cout<<endl;
    Print_BarangInToko(L , T);

}
