#include "ProgramMenu.h"


int main()
{
    ///Membuat List Barang Toko Dan Yang Mengaturnya
    List_DataB lBarang = CreateList_DataB();
    List_DataT lToko = CreateList_DataT();
    List_DataManagerHandler lManager = CreateList_DataManager();

    int ans;
    string ansstr;
    do{
    MainMenu(ans);
    system("CLS");
    switch(ans){
        case 1:
            TambahToko(lToko);
            break;
        case 2:
            TambahBarang(lBarang);
            break;
        case 3:
            HapusToko(lToko , lManager);
            break;
        case 4:
            HapusBarang(lBarang , lManager);
            break;
        case 5:
            EditBarangToko(lToko , lBarang , lManager);
            break;
        case 6:
            TampilkanSeluruhDataToko(lToko,lManager);
            break;
        case 7:
            TampilkanSeluruhDataBarang(lBarang,lManager);
            break;
        case 8:
            TampilkanDataTokoCari(lToko , lManager);
            break;
        case 9:
            TampilkanDataBarangCari(lBarang , lManager);
            break;
        case 10:
            TampilkanTokoTerlengkap(lManager , lToko);
            break;
        case 11:
            TampilkanTokoTerTaklengkap(lManager , lToko);
            break;
        }

        cout <<" Kembali Ke Menu Utama?[Y/y]" << endl;
        cin>>ansstr;
        if(ansstr != "Y" && ansstr != "y"){
            cout <<" Yakin Ingin Keluar? , Klik [Y/y] Untuk Kembali!" << endl;
            cin>>ansstr;
        }
    }while(ansstr == "Y" || ansstr == "y");

    return 0;
}
