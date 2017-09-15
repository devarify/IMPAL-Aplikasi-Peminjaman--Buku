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
	
void daftarBuku(){
	int i;
	char pil3[2];
	printf("\n\n\t =========================================\n");
	printf("\n\t\t\t Cari Buku di Perpustakaan");
	printf("\n\n\t =========================================\n\n");
	printf("\n\n\t No\tJUDUL BUKU\tPENGARANG\tTAHUN TERBIT\tSTOK\n");
	for(i=0;i<10;i++){
		printf("\n\n\t %d\t%s\t		%s\t	%d\t	%d\t %d\n",i+1,buku[i],karangan[i],thTerbit[i],stokBuku[i]);
	}
	printf("\n\t =================================================\n");
	printf("\n\n\t SILAHKAN PILIH Y(MENU UTAMA), T(INFO BUKU) =");
	scanf("%s",&&pil3);
	if(strcmp(pil3,"Y")==0){
		system("CLS");
		Menu();
	}else if(strcmp(pil3,"T")==0){
		system("CLS");
		infoBuku();
	}else{
		system("CLS");
		daftarBuku();
	}
}
	
void infoBukuTerlaris(){
char pil3[2];
int tSwap;
int tUrutan;
	do{
		tSwap = 0;
		for(tUrutan=0;tUrutan)<19;tUrutan++){
			if(stokBuku[tUrutan]<stokBuku[tUrutan+1])
			{
				swapValue(&stokBuku[tUrutan],
				&stokBuku[tUrutan+1]);
				tSwap = 1;
			}
		}
	}
	while(tSwap == 1);
	printf("\n\n\t ========================================\n");
	printf("\n\t\t\t INFO BUKU TERLARIS DI PERPUSTAKAAN");
	printf("\n\n\t ========================================\n");
	printf("\n\n NO\tJUDUL BUKU\tPENGARANG\tTAHUN TERBIT\tSTOK\tSTATUS\n");
	for(tUrutan=0;tUrutan<10;tUrutan++){
		if(stokBuku[tUrutan]==stokBuku[9]){
			printf("\n\n %d\t%s\t	%s\t	%d\t %d \t TERLARIS\n",tUrutan+1,buku[tUrutan],karangan[tUrutan],thTerbit[tUrutan],stokBuku[tUrutan]);
		}else if(stokBuku[tUrutan]==100){
			printf("\n\n %d\t%s\t	%s\t	%d\t %d \t TDK LARIS\n",tUrutan+1,buku[tUrutan],karangan[tUrutan],thTerbit[tUrutan],stokBuku[tUrutan]);
		}else{
			printf("\n\n %d\t%s\t	%s\t	%d\t %d \t SEDANG\n",tUrutan+1,buku[tUrutan],karangan[tUrutan],thTerbit[tUrutan],stokBuku[tUrutan]);
		}
		}
	printf("\n================================\n")
	printf("\n\n\t SILAHKAN PILIH Y(MENU UTAMA), T(INFO BUKU) =");
	scanf("%s",&&pil3);
	if(strcmp(pil3,"Y")==0){
		system("CLS");
		Menu();
	}else if(strcmp(pil3,"T")==0){
		system("CLS");
		infoBuku();
	}else{
		system("CLS");
		infoBukuTerlaris();
	}
}
	
void swapValue(int *tIntA, int *tIntB){
	int tInt = *tIntA;
	*tIntA = *tIntB;
	*tIntB = tInt;
}	
/*==============================*/
	
void pengembalian(){
	int idSiswa;
	int hari,hari1,hasil,denda;
	char pil2[2];
	system ("color 5B")
	
	printf("\n\n\t ========================================\n");
	printf("\n\t\t\t INFO BUKU TERLARIS DI PERPUSTAKAAN");
	printf("\n\n\t ========================================\n");
	printf("\n\t\t\t Masukan Tanggal Pengembalian [ex 11 12 2014]");
	scanf_s("%d",&date[1]);
	scanf_s("%d",&month[1]);
	scanf_s("%d",&year[1]);
	printf("\n\t Cari Berdasarkan ID Pelanggan =");
	scanf_s("%d",&idSiswa);

	date[0]=identitas[idSiswa-1].peminjam.tgl;
	month[0]=identitas[idSiswa-1].peminjaman.bln;
	year[0]=identitas[idSiswa-1].peminjaman.thn;
	
	//menempatkan nilai tertinggi apakah nilai 1 atau yang ke 2
	if(month[0]>month[1]){
		bulan_atas=month[0];
		bulan_bawah=month[1];
	}else{
		bulan_atas=month[1];
		bulan_bawah=month[0];
	}if(year[0]>year[1]){
		tahun_atas=year[0];
		tgl_atas=date[0];
		bln_atas=month[0];
		tahun_bawah=year[1];
		tgl_bawah=date[1];
		bln_bawah=month[1];
		}else{
		tahun_atas=year[1];
		tgl_atas=date[1];
		bln_atas=month[1];
		tahun_bawah=year[0];
		tgl_bawah=date[0];
		bln_bawah=month[0];
	}
		//memanggil fungsi rumus
			
	if(year[0]==year[1] && month[0]!=month[1]){
		hari = hasil_tahunsama(bulan_bawah,bulan_atas,tahun_atas);
		//printf("Hasil selisihnya = %d hari", hasil_tahunsama(bulan_bawah,bulan_atas,tahun_atas));
	}else{
		hari = hasil_tahunbeda(tahun_bawah,tahun_atas,bulan_bawah,tgl_atas,tgl_bawah);
		//printf("Hasil selisihnya = %d hari", hasil_tahunsama(bulan_bawah,bulan_atas,tahun_atas));
	}

	if(hari<0){
		hari1=-1*hari;
		}else{
		hari1=hari;
	}
	
	printf("\n\n\t\t\t MAHASISWA KE-&d",idSiswa);
	printf("\n\n\t\t - NIM		= %d",identitas[idSiswa-1].nim);
	printf("\n\n\t\t - NAMA		= %s",identitas[idSiswa-1].nama);
	printf("\n\n\t\t - KELAS	= %s",identitas[idSiswa-1].kelas);
	printf("\n\t\t - TGL PINJAM	= %d - %d - d",identitas[idSiswa-1].peminjaman.tgl,identitas[idSiswa-1].peminjaman.bln,identitas[idSiswa-1].peminjaman.thn);
	
	print("\n\n\t\t - KODE BUKU 1 = %d",identitas[idSiswa-1].kodeBuku1);
	print("\n\t\t - KODE BUKU 2 = %d",identitas[idSiswa-1].kodeBuku2);
	print("\n\t\t - KODE BUKU 3  = %d",identitas[idSiswa-1].kodeBuku3);
	print("\n\t\t - JUMLAH HARI = %d",hari);
	
	if(hari<=3){
		printf("\n\t\t - DENDA ANDA = 0");
	}else{
		hasil=hari1-3;
		denda=hasil*10000;
		printf("\n\t\t - DENDA ANDA = %d",denda);
	}
	printf("\n\t ============================\n")
	printf("\n\n\t SILAHKAN PILIH Y(MENU UTAMA), T(MENU PENGEMBALIAN) =");
	scanf("%s",&pil2);
	if(strcmp(pil2,"Y")==0){
		system("CLS");
		Menu();
	}else if(strcmp(pil2,"T")==0){
		system("CLS");
		infoBuku();
	}else{
		system("CLS");
		ErrorPengembalian();
	}
}
	
void Error Pengembalian(){
	char pil1[2];
	system("color C7");
	printf("\n\n\n");
	printf("\n\n\n\n\n\t\t\t\t ERROR PROGRAM\n");
	printf("\n\t\t\t DATA TIDAK ADA DALAM PILIHAN\n");
	printf("\n\tINPUT ULANG KEMBALI, PILIH Y(MENU UTAMA) DAN T(MENU PENGEMBALIAN)\n\n");
	printf("\n\n\t\t\tINPUT PILIHAN ANDA =");
		scanf("%s",&pil1);
	if(strcmp(pil1,"Y")==0){
		system("CLS");
		Menu();
	}else if(strcmp(pil1,"T")==0){
		pengembalian();
	}else{
	system("CLS");
	ErrorPengembalian();
	}
}	
int hasiltahunsama(int a,int b,int c){
	int i,batas_bawah,hasilnya,hasil_akhir;
	int hasil=0;
	
	for(i=a-1;i<=b;i++){
		if(c%4==0){
			hasil=hasil+bulan_kabisat[i];
		}else{
			hasil=hasil+bulan[i];
		}
	}
	batas_bawah=bulan[b+1]-date[1];
	hasilnya=hasil-(date[0]+batas_bawah);
	hasil_akhir=abs(hasilnya);
	return hasil_akhir;
}
	
int hasiltahunbeda(int tahun1,int tahun2,int bulan1,int bulan2,int tgl1,int tgl2){
	int hasil_tahun=0,hasil_bulan=0,hasilnya;
	int k,i,j;		
	for(i=tahun1;i<=tahun2;i++){
		if(i%4==0){
			hasil_thn=hasil_thn+366;
		}else{
			hasil_thn=hasil_thn+365;
		}
	}
	for(j=0;j<bulan1-1;j++){
		if(tahun1%4==0){
			hasil_bln=hasil_bln+bulan_kabisat[j];
		}else{
			hasil_bln=hasil_bln+bulan[j];
		}
	}
	for(k=bln2-1;k12;k++){
		if(tahun2%4==0){
			hasil_bln=hasil_bln+bulan_kabisat[k];
		}else{
			hasil_bln=hasil_bln+bulan[k];
		}
	}
	
	hasilnya = ((hasil_thn-hasil_bln)-tgl1)+tgl2;
	return hasilnya;
}
	
	
	
