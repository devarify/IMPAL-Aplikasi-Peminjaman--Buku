#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	struct tgl{
		int tgl;
		int bln;
		int thn;
	};
	struct Mahasiswa{
		int nim;
		char nama[20];
		char kelas[50];
		struct tgl peminjaman;
		int kodeBuku1;
		int kodeBuku2;
		int kodeBuku3;
	};
	struct Mahasiswa identitas[100];
	
	int batas=0;
	
	int data[2];
	int month[2];
	int year[2];
	int bulan_atas,bulan_bawah,bln_atas,bln_bawah,tahun_atas,tahun_bawah,tgl_atas,tgl_bawah;
	
	char buku[10][20]={"MTK","FISIKA","STATIK","INGGRIS","BIOLOGI","KIMIA","JAVA","SEJARAH","AGAMA"};
	char karangan[10][20]={"MARLENA","SUPRATI","SIMANJUNTAK","SAHERA","MELINDA","MANTENA","MONTANE","SINTANI","FATHIA","SAMPURE"};
	int thTerbit[10]={2014,2011,2010,2009,2008,2003,2004,2001,2000,1992};
	int stokBuku[10]={100,100,100,100,100,100,100,100,100,100};
	
	int bulan[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int bulan_kabisat[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	
	void tampil();
	void ErrorMenu();
	void Exit();
	void Menu();
	void ErrorPeminjaman();
	void ErrorMahasiswa();
	void tampilMahasiswa();
	void ErrorInfoBuku();
	void infoBuku();
	void cariBuku();
	void daftarBuku();
	void infoBukuTerlaris();
	void swapValue(int *tIntA, int *tIntB);
	void pengembalian();
	void ErrorPengembalian();
	int hasil_tahunansama(int a,int b,int c);
	int hasil_tahunbeda(int tahun1,int tahun2,int bln1,int bln2,int tgl1,int tgl2);
	/*===========================================1=========================*/
	void peminjamanBuku(){
		int simpan,simpan1,simpan2;
		char pil2[2];
		system("color58");
		printf("\n\n\t\t\t INPUT DATA PEMINJAMAN");
		printf("\n\t\t =============================\n\n");
		printf("\n\t - Input NIM	= ");
		scanf_s("%d",&identitas[batas].nim);
		printf("\n\t - Input Nama	= ");
		scanf("%s",&identitas[batas].nama);
		printf("\n\t - Input Kelas	= ");
		scanf("%s",&identitas[batas].kelas);
		printf("\n\t - Input Tanggal	= ");
		scanf_s("%d",&identitas[batas].peminjaman.tgl);
		scanf_s("%d",&identitas[batas].peminjaman.bln);
		scanf_s("%d",&identitas[batas].peminjaman.thn);
		printf("\n\n\t =============================\n\n");
		printf("\n\t - Kode Buku	= ");
		scanf_s("%d",&identitas[batas].kodeBuku2);
		simpan1=identitas[batas].kodeBuku2;
		stokBuku[simpan1]--;
		
		printf("\n\t - Kode Buku	= ");
		scanf_s("%d",&identitas[batas].kodeBuku3);
		simpan2=identitas[batas].kodeBuku3;
		stokBuku[simpan2]--;
		
		batas=batas+1;
		printf("\n\n\t =============================\n\n ");
		printf("\t SILAHKAN PILIH Y(KE MENU UTAMA) T(INPUT PEMINJAMAN BUKU) =");
		scanf("%s",&pil2);
		if(strcmp(pil2,"Y")==0){
			system("CLS");
			Menu();
		}else if(strcmp(pil2,"T")==0){
			system("CLS");
			peminjamanBuku();
		}else{
			system("CLS");
			peminjamanBuku();
			ErrrorPeminjaman();
		}
		
	}
	
	void ErrorPeminjaman(){
		char pil1[2];
		printf("\n\n\n");
		printf("\n\n\n\t\t\t ERROR PROGRAM\n");
		printf("\n\n\n\t\t\t DATA TIDAK ADA DALAM PILIHAN\n");
		printf("\n\tINPUT ULANG KEMBALI, PILIH Y(MENU UTAMA) DAN T(MENU PEMINJAMAN)\n\n");
		printf("\n\n\t\t\tINPUT PILIHAN ANDA =");
		scanf("%s",&pil1);
		if(strcmp(pil1,"Y")==0){
			system("CLS");
			Menu();
		}else if(strcmp(pil1,"T")==0){
			system("CLS");
			peminjamanBuku();
		}else{
			system("CLS");
			ErrrorPeminjaman();
		}
	}
	
	/*=============================Menu Utama===============================*/
	void Menu(){
		int pil1;
		system("color 5B");
		tampil();
		
		printf("\t\t\t	1.Peminjaman Buku\n\n");
		printf("\t\t\t	2.Pengembalian Buku\n\n");
		printf("\t\t\t	3.Info Buku\n\n");
		printf("\t\t\t	4.Data Mahasiswa\n\n");
		printf("\t\t\t	5.Exit\n");
		
		printf("\n\t======================================\n");
		printf("\n\t\t\t	Input Kode Menu = ");
		scanf_s("%d",&pil);
		
		switch(pil){
		case 1 :
			system("CLS");
			peminjamanBuku();
			break;
		case 2 :
			system("CLS");
			pengembalian();
			break;
		case 3 :
			system("CLS");
			infoBuku();
			break;
		case 4 :
			system("CLS");
			tampilMahasiswa();
			break;
		case 5 :
			Exit();
			break;
		default :
			system("CLS");
			ErrorMenu();
			break;	
		}
	}
	void ErrorMenu(){
		char pil1[2];
		system("color C7");
		printf("\n\n\n");
		printf("\n\n\n\n\n\t\t\t\t ERROR PROGRAM\n");
		printf("\n\tSILAHKAN INPUT ULANG KEMBALI PILIH Y(MELANJUTKAN) DAN T(KELUAR)\n\n");
		printf("\n\n\t\tINPUT PILIHAN ANDA = ");
		scanf("%s",&pil1);
		if(strcmp(pil1,"Y")==0){
			system("CLS");
			Menu();
		}else if(strcmp(pil1,"T")==0){
			Exit();
		}else{
			system("CLS");
			ErrrorMenu();
		}
	}
	void Exit(){
		system("color 37");
		system("CLS");
		printf("\n\n\n\n\n");
		printf("\n\n\n\n\n\t\t TERIMAKASIH ATAS PENGGUNAAN APLIKASI KAMI ^_^\n");
		printf("\n\n\t\t\t\t EXIT PROGRAM\n");
	}
	void tampil(){
		printf("\t=============================================================\n");
		printf("\n\t\t SELAMAT DATANG DI APLIKASI PERPUSTAKAAN\n");
		printf("\t=============================================================\n");
		printf("\t=============================================================\n");
	}
	/*======================================4========================================*/
	
	void tampilMahasiswa(){
		int i;
		char pil4[2];
		system("color 5B");
		printf("\n\n\t\t\t TAMPIL DATA MAHASISWA");
		printf("\n\t\t =====================================\n");
		for(i=0; i<batas; i++){
			printf("\n\n\t\t\t MAHASISWA KE-%d",i+1);
			printf("\n\t\t - NIM 		= %d",identitas[i].nim);
			printf("\n\t\t - NAMA 		= %s",identitas[i].nama);
			printf("\n\t\t - KELAS		= %d",identitas[i].kelas);
			printf("\n\t\t - TGL PINJAM = %d - %d - %d",identitas[i].peminjaman.tgl,identitas[i].peminjaman.bln,identitas[i].peminjaman.thn);
			
			printf("\n\n\t\t - KODE BUKU 1 = %d", identitas[i].kodeBuku1);
			printf("\n\t\t - KODE BUKU 1 = %d", identitas[i].kodeBuku2);
			printf("\n\n\t\t =========================================\n");
			
		}
		printf("\n\n\t SILAHKAN PILIH Y(KE MENU UTAMA) T(INPUT MENU PEMINJAMAN) =");
		scanf("%s",&pil4);
		if(strcmp(pil4,"Y")==0){
			system("CLS");
			Menu();
		}else if(strcmp(pil4,"T")==0){
			system("CLS");
			tampilMahasiswa();
		}else{
			system("CLS");
			ErrrorPeminjaman();
		}
	}
	
	void ErrorMahasiswa(){
		char pil1[2];
		system("color C7");
		printf("\n\n\n");
		printf("\n\n\n\n\n\t\t\t\t ERROR PROGRAM\n");
		printf("\n\n\n\n\n\t\t\t\t DATA TIDAK ADA DALAM PILIHAN\n");
		printf("\n\tSILAHKAN INPUT ULANG KEMBALI PILIH Y(MELANJUTKAN) DAN T(KELUAR)\n\n");
		printf("\n\n\t\tINPUT PILIHAN ANDA = ");
		scanf("%s",&pil1);
		if(strcmp(pil1,"Y")==0){
			system("CLS");
			Menu();
		}else if(strcmp(pil1,"T")==0){
			tampilMahasiswa();
		}else{
			system("CLS");
			ErrrorMahasiswa();
		}
	}
	
	/*==========================================3======================================*/
	
	void infoBuku(){
		int pil5;
		system("color 58");
		printf("\n\n\t\t\t INFO BUKU PERPUSTAKAAN");
		printf("\n\n\t ================================\n\n");
		printf("\n\t\t 1. Cari Buku");
		printf("\n\t\t\t 2. Daftar Buku");
		printf("\n\t\t\t 3. Info Buku Terlaris");
		printf("\n\t\ ==================================\n\n");
		printf("\n\t\t INPUT KODE INFO BUKU = ");
		scanf_s("%d",&pil5);
		
		switch(pil5){
		case 1 :
			system("CLS");
			cariBuku();
			break;
		case 2 :
			system("CLS");
			daftarBuku();
			break;
		case 3 :
			system("CLS");
			infoBukuTerlaris();
			break;
		default :
			system("CLS");
			ErrorInfoBuku();
			break;
		}
	}
	
	void ErrorInfoBuku(){
		char pil1[2];
		system("color C7");
		printf("\n\n\n");
		printf("\n\n\n\n\n\t\t\t\t ERROR PROGRAM\n");
		printf("\n\n\n\n\n\t\t\t\t DATA TIDAK ADA DALAM PILIHAN\n");
		printf("\n\tSILAHKAN INPUT ULANG KEMBALI PILIH Y(MELANJUTKAN) DAN T(KELUAR)\n\n");
		printf("\n\n\t\tINPUT PILIHAN ANDA = ");
		scanf("%s",&pil1);
		if(strcmp(pil1,"Y")==0){
			system("CLS");
			Menu();
		}else if(strcmp(pil1,"T")==0){
			infoBuku();
		}else{
			system("CLS");
			ErrrorInfoBuku();
		}
	}
	
	void cariBuku(){
		int kdBuku;
		char pil3[2];
		printf("\n\n\t ======================================\n");
		printf("\n\t\t\t CARI BUKU DI PERPUSTAKAAN\n");
		printf("\n\n\t ======================================\n");
		printf("\n\t\t\t INPUT KODE BUKU = ");
		scanf_s("%d",&kdBuku);
		
		printf("\n\n\t\t\t KODE BUKU	= %d",kdBuku);
		printf("\n\n\t\t\t JUDUL BUKU	= %s",buku[kdBuku]);
		printf("\n\n\t\t\t PENGARANG	= %s",karangan[kdBuku]);
		printf("\n\n\t\t\t TAHUN TERBIT	= %d",thTerbit[kdBuku]);
		printf("\n\n\t\t\t STOK BUKU	= %d",stokBuku[kdBuku]);
		
		printf("\n\n\t ====================================\n\n");
		printf("\n\n\t SILAHKAN PILIH Y(MENU UTAMA), T(INFO BUKU), N(CARI BUKU) =");
		scanf("%s",&pil3);
		if(strcmp(pil3,"Y")==0){
			system("CLS");
			Menu();
		}else if(strcmp(pil3,"T")==0){
			system("CLS");
			infoBuku();
		}else if(strcmp(pil3,"T")==0){
			system("CLS");
			cariBuku();
		}else{
			system("CLS");
			printf("\n\t\t\t INPUT DATA SALAH \n\n");
			cariBuku();
		}
	}
	
	
	