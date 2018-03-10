# Tubes_DataPenjualan
Tubes 2018 STD Data Penjualan Dengan Multiple LinkList dan Single LinkList

Script Structure

DataManager | DataToko | DataBarang
     |
	 V
LibraryHandler
    |
	V
Program Menu
    |
	V
Main Program



Judul : Data Penjualan
Descripsi : implementasikan multi linked-list yang memodelkan data toko dan data barang beserta relasi keduanya. 
Suatu toko bisa banyak menjual barang. Dan suatu barang bisa di jual oleh banyak toko.
Fungsionalitas :

a. Penambahan data toko.														(Toko.cpp : 5)  (Toko.cpp : 12)
b. Penambahan data barang.														(Barang.cpp : 4)  (Barang.cpp : 10)
c. Penentuan relasi toko dan barang yang dijual (dan sebalikknya). 				(Model 1)
d. Menghapus data toko. 														(Toko.cpp : 26)
e. Manghapus data barang. 														(Barang.cpp : 24)
f. Menampilkan data keseluruhan toko beserta data barang yang dijualnya.		(LibraryHandler.cpp : 139)
g. Menampilkan data barang yang dijual oleh toko tertentu.						(LibraryHandler.cpp : 103)
h. Menampilkan data toko menjual barang tertentu.								(LibraryHandler.cpp : 121)
i. Menampilkan data toko yang paling lengkap jualannya dan yang paling sedikit.	(DataManager.cpp : 129) (DataManager.cpp : 159)