/*
	Program Struct Menggunakan Nested Struct, Metode CRUD & Penerapan Prosedur Pengurutan/Sorting dan Pencarian/Searching
	Judul Program: DATA ATLIT TARUNG DERAJAT UNIVERSITAS MULAWARMAN UNTUK PERSIAPAN KEJUARAAN POMNAS 2022
	POSTTEST VII PRATIKUM ALGORITMA PEMROGRAMAN LANJUT
	2109106013 - Bramantyo Ardi Harimurti Wibisono
	Informatika A'2021
*/
#include <iostream>
#include <fstream> //-> File Eksternal
#include <sstream> //-> Konversi String Ke Tipe data lain
#include <stdlib.h> 
#include <string> //-> Manipulasi String
#include <conio.h> //-> Fungsi getch()
#include <iomanip> //-> Error Handling
#include <Windows.h> //-> sleep di WIndows OS
#include <time.h> //-> sleep di Linux OS

using namespace std;

struct biodata_atlit{
	float berat;
	float tinggi;
	string kurata;
	string kontingen;
	string ttl;
	string ttl1;
	string ttl2;
	string ttl3;
};

struct date{
	string hari;
	int tgl;
	int bln;
	int thn;
};

struct program_tc{
	int crosscountry;
	int push_up;
	int sit_up;
	int p_cepat;
	int p_lingkardalam;
	int p_lingkaratas;
	int t_lingkardalam;
	int t_lingkardepan;
	int t_lingkarbelakang;
	int t_samping;
	int t_belakang;
};

struct list_atlit{
	biodata_atlit sub_a;
	program_tc sub_b;
	date sub_c;
	string nama;
	int nim;
	int nia;
	string prodi;
	string fakultas;
	int umur;
	int akt;
	string gender;
};

list_atlit data[100];
int indeks = 0;


fstream dbFile; // Database File
fstream daFile; // Data Atlit File
fstream dpFile,myFile; // Data Program Latihan File

/* Database File Line 74 - 167 */
void OpenDbFile(){
    dbFile.open("Database.txt", ios::out);
    if (!dbFile.is_open()){
        dbFile.open("Database.txt", ios::trunc);
        dbFile.close();
    }
    dbFile.close();
}
void WriteDbFile(list_atlit data[]){
    dbFile.open("Database.txt", ios::app);
    //dbFile << "Data Atlit UKM Tarung Derajat\n\t\tUniversitas MUlawarman\n" << endl;
    for (int i = 0; i < indeks; i++){
        dbFile<<data[i].nama<<"|"<<data[i].umur<<"|"<<data[i].nim<<"|"<<data[i].nia<<"|"<<data[i].prodi<<"|"<<data[i].akt<<"|"<<data[i].fakultas<<"|"<<data[i].gender<<"|"<<data[i].sub_a.berat<<"|"<<data[i].sub_a.tinggi<<"|"<<data[i].sub_a.kurata<<"|"<<data[i].sub_a.kontingen<<"|"<<data[i].sub_a.ttl<<"|"<<data[i].sub_a.ttl1<<"|"<<data[i].sub_a.ttl2<<"|"<<data[i].sub_a.ttl3<<endl;
    }
    cout << "Memproses Export file Data Atlit.." << endl;
    Sleep(3000);
    system("cls");		//membersihkan layar
    cout << "Data Atlit Berhasil di Export kedalam Database.txt\n" << endl;
    dbFile.close();
}
void ReadDbFile(list_atlit data[]){
    // Membaca file eksternal
    // ifstream myFile;
    dbFile.open("Database.txt", ios::in);
    if (dbFile.is_open())
    {
	    int i = 0;
	    string teks;
	    while (!dbFile.eof())
	    {
    	    getline(dbFile, data[indeks].nama, '|'); 	//--> Import File Eksternal Tipe Data String
    	    getline(dbFile, teks, '|');		//--> Import File Eksternal Tipe data Integer
    	    stringstream umur(teks);
    	    umur >> data[indeks].umur;	
  		    getline(dbFile, teks, '|');
        	stringstream nim(teks);
   	    	nim >> data[indeks].nim;
        	getline(dbFile, teks, '|');
        	stringstream nia(teks);
        	nia >> data[indeks].nia;
        	getline(dbFile, data[indeks].prodi, '|');
        	getline(dbFile, teks, '|');
        	stringstream akt(teks);
        	akt >> data[indeks].akt;
        	getline(dbFile, data[indeks].fakultas, '|');
        	getline(dbFile, data[indeks].gender, '|');
        	getline(dbFile, teks, '|');		//--> Import File Eksternal Tipe data Float
        	stringstream berat(teks);	
        	berat >> data[indeks].sub_a.berat;
        	getline(dbFile, teks, '|');
        	stringstream tinggi(teks);
        	tinggi >> data[indeks].sub_a.tinggi;
        	getline(dbFile, data[indeks].sub_a.kurata, '|');
        	getline(dbFile, data[indeks].sub_a.kontingen, '|');
        	getline(dbFile, data[indeks].sub_a.ttl, '|');
        	getline(dbFile, data[indeks].sub_a.ttl1, '|');
        	getline(dbFile, data[indeks].sub_a.ttl2, '|');
        	getline(dbFile, data[indeks].sub_a.ttl3, '\n');
        	if (dbFile.eof())
        	{
        	    break;
        	}
        	indeks++;
    	}indeks++;
    	cout << "Memproses Import file Data Atlit.." << endl;
    	Sleep(3000);
    	system("cls");		//membersihkan layar
    	cout << "Data Atlit pada Database.txt telah berhasil di Import\n" << endl;
    	
    	dbFile.close();
	}
	else
	{
		cout << "Memproses Import file Data Atlit.." << endl;
    	Sleep(3000);
    	system("cls");		//membersihkan layar
    	cout << "Gagal Import Data Atlit! (Undefined Database.txt)\n" << endl;
    	Sleep(1500);
		ofstream DbFile("Database.txt");
		DbFile.close();
	}
}

void RemoveDbFile(){
	remove("Database.txt");
	cout << "Menghapus file Data Atlit.." << endl;
    Sleep(3000);
	system("cls");		//membersihkan layar
    cout << "File Data Atlit telah berhasil di hapus\n" << endl;
    Sleep(1500);
}


/* Da = Data Atlit File, Coming Soon!! */
// Data File yg berbasis formulir dengan format .txt
void OpenDaFile(){
    myFile.open("DataAtlitTD.txt", ios::out);
    if (!myFile.is_open()){
        myFile.open("DataAtlitTD.txt", ios::trunc);
        myFile.close();
    }
    myFile.close();
}
void WriteDaFile(list_atlit data[]){
    myFile.open("DataAtlitTD.txt", ios::out);
    myFile << "Data Atlit UKM Tarung Derajat\n\t\tUniversitas MUlawarman\n" << endl;
    for (int i = 0; i < indeks; i++){
    	myFile << "\nData Atlit Ke [" << i+1 << "]" << endl;
        myFile << "Nama Lengkap Atlit : " << data[i].nama << endl;
        myFile << "NIM : " << data[i].nim << endl;
        myFile << "Program Studi : " << data[i].prodi << endl;
    }
    cout << "Memproses Export file Data Atlit.." << endl;
    Sleep(3000);
    system("cls");		//membersihkan layar
    cout << "Data Atlit Berhasil di Export kedalam DataAtlitTD.txt" << endl;
    
    myFile.close();
}
void ReadDaFile(){
	ifstream myFile;
	string s1, s2, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, output, buffer;
	bool isData = false;
	int no;
	string nama, nim, nia, umur, prodi, fakultas, ttl;
	
	myFile.open("DataAtlitTD.txt");
	
	while(!isData){
		getline(myFile,buffer);
		if (buffer == "DataAtlitTD"){
			isData == true;
		}
	}
	cout << output << endl;
}




/*  Sorting (line 217 - 397)  */
void swap(list_atlit *xp, list_atlit *yp){
	list_atlit temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int partition_ascending (list_atlit data[], int low, int high){	
	int pivot = data[high].umur;
	int i = (low - 1);
	for (int j = low; j <= high- 1; j++)
	{
		if (data[j].umur <= pivot)
		{
			i++;
			swap(&data[i], &data[j]);
		}
	}
	swap(&data[i + 1], &data[high]);
	return (i + 1);
}

int partition_descending (list_atlit data[], int low, int high){
	int pivot = data[high].umur;
	int i = (low - 1);
	for (int j = low; j <= high- 1; j++)
	{
		if (data[j].umur >= pivot)
		{
			i++;
			swap(&data[i], &data[j]);
		}
	}
	swap(&data[i + 1], &data[high]);
	return (i + 1);
}

void quicksort_ascending_umur(list_atlit data[], int low, int high){
	if (low < high)
	{
		int pi = partition_ascending(data, low, high);
		quicksort_ascending_umur(data, low, pi - 1);
		quicksort_ascending_umur(data, pi + 1, high);
	}
}

void quicksort_descending_umur(list_atlit data[], int low, int high){
	if (low < high)
	{
		int pi = partition_descending(data, low, high);
		quicksort_descending_umur(data, low, pi - 1);
		quicksort_descending_umur(data, pi + 1, high);
	}
}

void bubblesort_nama(list_atlit data[], int indeks){
	int j, pilih;
	list_atlit swap;
	cout << "1. Ascending" << endl;
	cout << "2. Descending" << endl;
	cout << "Pengurutan berdasarkan: "; cin >> pilih;
	switch(pilih){
		case 1:
			for (int i=0; i<indeks-1; i++){
				for(j=0; j<indeks-1; j++){
					if(data[j].nama > data[j+1].nama){
						swap = data[j];
						data[j] = data[j+1];
						data[j+1] = swap;
					}
				}	
			}
			break;	
		case 2:
			for(int i=0; i<indeks-1; i++){
				for(j=0; j<indeks-1; j++){
					if(data[j].nama < data[j+1].nama){
						swap = data[j];
						data[j] = data[j+1];
						data[j+1] = swap;
					}
				}	
			}
			break;
		break;
	}
}

void bubblesort_nim(list_atlit data[], int indeks){
	int j, pilih;
	list_atlit swap;
	cout << "1. Ascending" << endl;
	cout << "2. Descending" << endl;
	cout << "Pengurutan berdasarkan: "; cin >> pilih;
	switch(pilih){
		case 1:
			for (int i=0; i<indeks-1; i++){
				for(j=0; j<indeks-1; j++){
					if(data[j].nim > data[j+1].nim){
						swap = data[j];
						data[j] = data[j+1];
						data[j+1] = swap;
					}
				}	
			}
			break;	
		case 2:
			for(int i=0; i<indeks-1; i++){
				for(j=0; j<indeks-1; j++){
					if(data[j].nim < data[j+1].nim){
						swap = data[j];
						data[j] = data[j+1];
						data[j+1] = swap;
					}
				}	
			}
			break;
		break;
	}
}

void selectionsort_nia(list_atlit data[], int indeks)
{
	int i, j, min_idx;
	int pilih;
	cout << "1. Ascending" << endl;
	cout << "2. Descending" << endl;
	cout << "Pengurutan berdasarkan: "; cin >> pilih;
	for (i = 0; i < indeks-1; i++)
	{
		min_idx = i;
		for (j = i+1; j < indeks; j++)
		{
			switch (pilih){
				case 1:
					if (data[j].nia < data[min_idx].nia)
					{
						min_idx = j;	
					}
					break;
				case 2:
					if (data[j].nia > data[min_idx].nia)
					{
						min_idx = j;	
					}
					break;
			}
		}
		swap(&data[i], &data[min_idx]);
	}
}

void selectionsort_kurata(list_atlit data[], int indeks)
{
	int i, j, min_idx;
	int pilih;
	cout << "1. Ascending" << endl;
	cout << "2. Descending" << endl;
	cout << "Pengurutan berdasarkan: "; cin >> pilih;
	for (i = 0; i < indeks-1; i++)
	{
		min_idx = i;
		for (j = i+1; j < indeks; j++)
		{
			switch (pilih){
				case 1:
					if (data[j].sub_a.kurata < data[min_idx].sub_a.kurata)
					{
						min_idx = j;	
					}
					break;
				case 2:
					if (data[j].sub_a.kurata > data[min_idx].sub_a.kurata)
					{
						min_idx = j;	
					}
					break;
			}
		}
		swap(&data[i], &data[min_idx]);
	}
}

/*  Searching (Line 400 - 530)  */
int binarySearch(list_atlit data[], int low, int high)
{   // input nilai yang ingin dicari
	int i;
    string x;
    cout << "Masukkan nama yang ingin anda cari : "; fflush(stdin); getline(cin, x);
    while (low <= high)
    {
        int i = low + (high - low) / 2;
        if (data[i].nama == x)
        {
            cout << "Data ditemukan" << i << endl;
            cout << "\n==========================================" << endl;
			cout << "            Biodata Atlit [" << i+1 << "]	" << endl;
			cout << "=------------------------------------------=" << endl;
			cout << "Nama Anggota : " << data[i].nama << endl;
			cout << "NIM : " << data[i].nim << endl;
			cout << "NIA : " << data[i].nia << endl;
			cout << "Umur : " << data[i].umur << " Tahun" << endl;
			cout << "Prodi : " << data[i].prodi << "(" << data[i].akt << ")" << endl;
			cout << "Fakultas : " << data[i].fakultas << endl;
			cout << "TTL : "; 
			cout << data[i].sub_a.ttl<<", "<<data[i].sub_a.ttl1<<" "<<data[i].sub_a.ttl2<<" "<<data[i].sub_a.ttl3 << endl;
			cout << "Jenis gender : " << data[i].gender << endl;
			cout << "=------------------------------------------=" << endl;
			cout << "=           Subdata Atlit [" << i+1 << "]            =" << endl;
			cout << "=------------------------------------------=" << endl;
			cout << "Berat Badan : " << data[i].sub_a.berat << endl;
			cout << "Tinggi Badan : " << data[i].sub_a.tinggi << endl;
			cout << "Tingkat Sabuk : " << data[i].sub_a.kurata << endl;
			cout << "Kontingen : " << data[i].sub_a.kontingen << endl;
			cout << "=------------------------------------------=" << endl;
			cout << "       Program Latihan Per Hari [" << i+1 << "] 	" << endl;
			cout << "=------------------------------------------=" << endl;
			cout << "Hari/Tanggal : "<<data[i].sub_c.hari<<", "<<data[i].sub_c.tgl<<" - "<<data[i].sub_c.bln<<" - "<<data[i].sub_c.thn<<endl;
			cout << "Total Push Up : " << data[i].sub_b.push_up << "x" << endl;
			cout << "Total Sit Up : " << data[i].sub_b.sit_up << "x" << endl;
			cout << "Total Jogging : " << data[i].sub_b.crosscountry << " menit" << endl;
			cout << "Total Pukulan Cepat : " << data[i].sub_b.p_cepat << "x" << endl;
			cout << "Total Pukulan Lingkar Dalam : " << data[i].sub_b.p_lingkardalam << "x" << endl;
			cout << "Total Pukulan Lingkar Atas : " << data[i].sub_b.p_lingkaratas << "x" << endl;
			cout << "Total Tendangan Lingkar Dalam : " << data[i].sub_b.t_lingkardalam << "x" << endl;
			cout << "Total Tendangan Lingkar Depan : " << data[i].sub_b.t_lingkardepan << "x" << endl;
			cout << "Total Tendangan Lingkar Belakang : " << data[i].sub_b.t_lingkarbelakang << "x" << endl;
			cout << "Total Tendangan Samping : " << data[i].sub_b.t_samping << "x" << endl;
			cout << "Total Tendangan Belakang: " << data[i].sub_b.t_belakang << "x" << endl;
			cout << "============================================" << endl;
			cout << "Tekan [Enter] untuk Melanjutkan . . ." << endl; getch();	//pause program sebelum ada inputan dari user
            return i;
			}
       	if (data[i].nama < x)
		   	low = i + 1;
        else
           	high = i - 1;
    }
    return -1;
}

void interpolation_search(list_atlit data[], int jumlahData)
{
    // inisiasi nilai variabel indeks
    int i_awal = 0, i;
    int proses = 0;
    int i_akhir = jumlahData - 1;
    // input nilai yang ingin dicari
    int key;
    cout << "Masukkan nim yang ingin anda cari : ";
    cin >> key;
    while (true)
    {
        proses++;
        // rumus interpolation search
        i = (i_awal + ((key - data[i_awal].nim) * (i_akhir - i_awal)) / (data[i_akhir].nim + data[i_awal].nim));
        // proses pembandingan search
        if (data[i].nim == key)
        {
            cout << "Data ditemukan" << endl;
            cout << "\n==========================================" << endl;
			cout << "            Biodata Atlit [" << i+1 << "]	" << endl;
			cout << "=------------------------------------------=" << endl;
			cout << "NIM : " << data[i].nim << endl;
			cout << "Nama Anggota : " << data[i].nama << endl;
			cout << "NIA : " << data[i].nia << endl;
			cout << "Umur : " << data[i].umur << " Tahun" << endl;
			cout << "Prodi : " << data[i].prodi << "(" << data[i].akt << ")" << endl;
			cout << "Fakultas : " << data[i].fakultas << endl;
			cout << "TTL : "; 
			cout << data[i].sub_a.ttl<<", "<<data[i].sub_a.ttl1<<" "<<data[i].sub_a.ttl2<<" "<<data[i].sub_a.ttl3 << endl;
			cout << "Jenis gender : " << data[i].gender << endl;
			cout << "=------------------------------------------=" << endl;
			cout << "=           Subdata Atlit [" << i+1 << "]            =" << endl;
			cout << "=------------------------------------------=" << endl;
			cout << "Berat Badan : " << data[i].sub_a.berat << endl;
			cout << "Tinggi Badan : " << data[i].sub_a.tinggi << endl;
			cout << "Tingkat Sabuk : " << data[i].sub_a.kurata << endl;
			cout << "Kontingen : " << data[i].sub_a.kontingen << endl;
			cout << "=------------------------------------------=" << endl;
			cout << "       Program Latihan Per Hari [" << i+1 << "] 	" << endl;
			cout << "=------------------------------------------=" << endl;
			cout << "Hari/Tanggal : "<<data[i].sub_c.hari<<", "<<data[i].sub_c.tgl<<" - "<<data[i].sub_c.bln<<" - "<<data[i].sub_c.thn<<endl;
			cout << "Total Push Up : " << data[i].sub_b.push_up << "x" << endl;
			cout << "Total Sit Up : " << data[i].sub_b.sit_up << "x" << endl;
			cout << "Total Jogging : " << data[i].sub_b.crosscountry << " menit" << endl;
			cout << "Total Pukulan Cepat : " << data[i].sub_b.p_cepat << "x" << endl;
			cout << "Total Pukulan Lingkar Dalam : " << data[i].sub_b.p_lingkardalam << "x" << endl;
			cout << "Total Pukulan Lingkar Atas : " << data[i].sub_b.p_lingkaratas << "x" << endl;
			cout << "Total Tendangan Lingkar Dalam : " << data[i].sub_b.t_lingkardalam << "x" << endl;
			cout << "Total Tendangan Lingkar Depan : " << data[i].sub_b.t_lingkardepan << "x" << endl;
			cout << "Total Tendangan Lingkar Belakang : " << data[i].sub_b.t_lingkarbelakang << "x" << endl;
			cout << "Total Tendangan Samping : " << data[i].sub_b.t_samping << "x" << endl;
			cout << "Total Tendangan Belakang: " << data[i].sub_b.t_belakang << "x" << endl;
			cout << "============================================" << endl;
			cout << "Tekan [Enter] untuk Melanjutkan . . ." << endl; getch();	//pause program sebelum ada inputan dari user
        	break;
        }
        else if ((data[i].nim < key) && (data[i].nim >= data[i_awal].nim))
        {
            i_awal = i + 1;
            continue;
        }
        else if ((data[i].nim > key) && (data[i].nim <= data[i_akhir].nim))
        {
            i_akhir = i - 1;
            continue;
        }
        else
        {
            cout << "Nilai yang anda cari tidak ada di dalam array" << endl;
            break;
        }
    }
}


void tampil();
void tampil_list_atlit();
void cari_list_atlit();
void tambah_list_atlit();
void ubah_list_atlit();
void hapus_list_atlit();
void main_menu();

void print_nama();
void print_umur();
void print_nim();
void print_nia();
void print_kurata();
void sorting_list_atlit();


int main(){
	cout << "================================================" << endl;
	cout << "Program Latihan dan Biodata Atlit Tarung Derajat" << endl;
	cout << "\tUKM Kodrat Universitas Mulawarman\t"<< endl;
	cout << "\t Persiapan Kejuaraan POMNAS 2022\t" << endl;
	cout << "================================================" << endl;
	cout << " >> Tekan [Enter] untuk Melanjutkan . . ." << endl; getch();	//pause program sebelum ada inputan dari user
	// system("clear");
	// system("cls");	//membersihkan layar
	main_menu();		//memanggil prosedur main_menu
	system("cls");		//mengakses sistem secara langsung dan menuliskan cls untuk membersihkan layar
	cout << endl;
	cout << "Exiting the program.. " << endl;

	return 0;			//mengembalikan nilai 0, menandakan akhir program dan program berjalan lancar
	}

void main_menu(){		//Deklarasi Prosedur Main Menu
	int pilih, pil;

	while (true){		//perulangan untuk daftar menu
		system("cls");	//membersihkan layar
		cout << "===================================" << endl;
		cout << "=	    Menu Program	  =" << endl;
		cout << "===================================" << endl;
		cout << "= (1) Cek Daftar Atlit            =" << endl;
		cout << "= (2) Cari Data Atlit             =" << endl;
		cout << "= (3) Tambah Daftar Atlit         =" << endl;
		cout << "= (4) Ubah Daftar Atlit           =" << endl;
		cout << "= (5) Hapus Daftar Atlit          =" << endl;
		cout << "= (6) Import File Eksternal       =" << endl;
		cout << "= (7) Export File Eksternal       =" << endl;
		cout << "= (8) Hapus File Eksternal        =" << endl;
		cout << "= (0) Keluar Program              =" << endl;
		cout << "===================================" << endl;
		cout << "  >> Masukan Pilihan Anda : "; cin >> pilih;
		
		if (pilih == 1){			//percabangan if else untuk memilih menu
			cout << endl;
			// system("clear");
			system("cls");		//membersihkan layar
			cout << "============================================" << endl;
			cout << "=            Daftar Data Atlit             =" << endl;
			cout << "============================================" << endl;
			cout << "(1) Tampil Data Atlit Secara Default" << endl;
			cout << "(2) Tampil Data Atlit Secara Khusus" << endl;
			cout << endl;
			cout << "  >> Masukan Pilihan Anda : "; cin >> pil;
			if (pil == 1){			//percabangan if else untuk memilih tampilkan default atau pengurutan atribut
				cout << endl;
				tampil_list_atlit();		//Memanggil Prosedur tampil_list_atlit
				cout << "Tekan [Enter] untuk Melanjutkan . . ." << endl; getch();	//pause program sebelum ada inputan dari user
				}
			else if(pil == 2){
				cout << endl;
				sorting_list_atlit();		//Memanggil Prosedur sorting_list_atlit
				cout << "Tekan [Enter] untuk Melanjutkan . . ." << endl; getch();	//pause program sebelum ada inputan dari user
				}
			else{
				cout << "Pilihan Salah" << endl;
			}
			}
		else if (pilih == 2){
			cout << endl;
			cari_list_atlit();				//Memanggil Prosedur cari_list_atlit
			cout << "Tekan [Enter] untuk Melanjutkan . . ." << endl; getch();	//pause program sebelum ada inputan dari user
			}
		else if (pilih == 3){
			cout << endl;
			tambah_list_atlit();		//Memanggil Prosedur tambah_list_atlit
			cout << "Tekan [Enter] untuk Melanjutkan . . ." << endl; getch();	//pause program sebelum ada inputan dari user
			}
		else if (pilih == 4){
			cout << endl;
			ubah_list_atlit();			//Memanggil Prosedur ubah_list_atlit
			cout << "Tekan [Enter] untuk Melanjutkan . . ." << endl; getch();	//pause program sebelum ada inputan dari user
			}
		else if (pilih == 5){
			cout << endl;
			hapus_list_atlit();			//Memanggil Prosedur hapus_list_atlit
			cout << "Tekan [Enter] untuk Melanjutkan . . ." << endl; getch();	//pause program sebelum ada inputan dari user
			}
		else if (pilih == 6){
			cout << endl;
			ReadDbFile(data);			//Memanggil Prosedur ReadDbFile (Import file database)
			cout << "Tekan [Enter] untuk Melanjutkan . . ." << endl; getch();	//pause program sebelum ada inputan dari user
			}
		else if (pilih == 7){
			cout << endl;
			WriteDbFile(data);			//Memanggil Prosedur WriteDbFile (Export file database)
			cout << "Tekan [Enter] untuk Melanjutkan . . ." << endl; getch();	//pause program sebelum ada inputan dari user
			}
		else if (pilih == 8){
			cout << endl;
			RemoveDbFile();				//Memanggil Prosedur RemoveDbFile (Delete file database)
			cout << "Tekan [Enter] untuk Melanjutkan . . ." << endl; getch();	//pause program sebelum ada inputan dari user
		}
		else if (pilih == 0){
			break;					//keluar dari perulangan dengan memberhentikan perulangan secara paksa
			}
		else {
			system("cls");			//membersihkan layar
			cout << " -= Pilihan tersebut tidak ada." << endl; getch();			//pause program sebelum ada inputan dari user
			}
		}
	}
void tampil(){			//Deklarasi Prosedur tampil. berbeda dengan tampil pesanan karna hanya menampilkan nama. digunakan pada prosedur lain
	if (indeks > 0){	//percabangan untuk memeriksa apakah ada pesanan atau tidak pada array
		for (int i = 0; i < indeks; i++){	//perulangan untuk menampilkan data array, i sebagai pembatas. selama i kurang dari nilai indeks, program akan berjalan terus
			cout << i+1 << ". "<< data[i].nama << endl; //cara memanggil data array
		}
	}
	else{				//jika data kosong, tampilkan output dibawah ini
		cout << "-=  Daftar Atlit Tidak Ada  -=" << endl;
	}
}

void tampil_list_atlit(){
	cout << "Tampil BOS" << endl;
	// system("celar");
	system("cls");		//membersihkan layar
	cout << "============================================" << endl;
	cout << "=            Daftar Data Atlit             =" << endl;
	cout << "============================================" << endl;
	if (indeks > 0){	//percabangan untuk memeriksa apakah array kosong atau tidak
		for (int i = 0; i < indeks; i++){	//perulangan untuk menampilkan data array
			cout << "\n==========================================" << endl;
			cout << "            Biodata Atlit [" << i+1 << "]	" << endl;
			cout << "=------------------------------------------=" << endl;
			cout << "Nama Anggota : " << data[i].nama << endl;
			cout << "NIM : " << data[i].nim << endl;
			cout << "NIA : " << data[i].nia << endl;
			cout << "Prodi : " << data[i].prodi << "(" << data[i].akt << ")" << endl;
			cout << "Fakultas : " << data[i].fakultas << endl;
			cout << "Umur : " << data[i].umur << " Tahun" << endl;
			cout << "TTL : "; 
			cout << data[i].sub_a.ttl<<", "<<data[i].sub_a.ttl1<<" "<<data[i].sub_a.ttl2<<" "<<data[i].sub_a.ttl3 << endl;
			cout << "Jenis gender : " << data[i].gender << endl;
			cout << "=------------------------------------------=" << endl;
			cout << "=           Subdata Atlit [" << i+1 << "]            =" << endl;
			cout << "=------------------------------------------=" << endl;
			cout << "Berat Badan : " << data[i].sub_a.berat << endl;
			cout << "Tinggi Badan : " << data[i].sub_a.tinggi << endl;
			cout << "Tingkat Sabuk : " << data[i].sub_a.kurata << endl;
			cout << "Kontingen : " << data[i].sub_a.kontingen << endl;
			cout << "=------------------------------------------=" << endl;
			cout << "       Program Latihan Per Hari [" << i+1 << "] 	" << endl;
			cout << "=------------------------------------------=" << endl;
			cout << "Hari/Tanggal : "<<data[i].sub_c.hari<<", "<<data[i].sub_c.tgl<<" - "<<data[i].sub_c.bln<<" - "<<data[i].sub_c.thn<<endl;
			cout << "Total Push Up : " << data[i].sub_b.push_up << "x" << endl;
			cout << "Total Sit Up : " << data[i].sub_b.sit_up << "x" << endl;
			cout << "Total Jogging : " << data[i].sub_b.crosscountry << " menit" << endl;
			cout << "Total Pukulan Cepat : " << data[i].sub_b.p_cepat << "x" << endl;
			cout << "Total Pukulan Lingkar Dalam : " << data[i].sub_b.p_lingkardalam << "x" << endl;
			cout << "Total Pukulan Lingkar Atas : " << data[i].sub_b.p_lingkaratas << "x" << endl;
			cout << "Total Tendangan Lingkar Dalam : " << data[i].sub_b.t_lingkardalam << "x" << endl;
			cout << "Total Tendangan Lingkar Depan : " << data[i].sub_b.t_lingkardepan << "x" << endl;
			cout << "Total Tendangan Lingkar Belakang : " << data[i].sub_b.t_lingkarbelakang << "x" << endl;
			cout << "Total Tendangan Samping : " << data[i].sub_b.t_samping << "x" << endl;
			cout << "Total Tendangan Belakang: " << data[i].sub_b.t_belakang << "x" << endl;
			cout << "============================================" << endl;
		}
	}
	else{				//jika data kosong, tampilkan output di bawah ini
		cout << "-=  Daftar Atlit Tidak Ada  -=" << endl;
	}
};

void tambah_list_atlit(){
	cout << "Tambah BOS" << endl;
	string pilih;		//deklarasi tipe data string pada var pilih

	do{					//perulangan do while, untuk dapat menjalankan programnya terlebih dahulu, lalu mengecek kondisinya
		// system("clear");
		system("cls");	//membersihkan layar
		cout << "============================================" << endl;
		cout << "-=	 Tambah Data Atlit	 -=" << endl;
		cout << "============================================" << endl;
		
		if (indeks < 1000){	//percabangan untuk memeriksa berapa banyak memori/indeks array yg kosong untuk diisi
			cout << "- Nomor Data [" << indeks+1 << "]" << endl;
			cout << "============================================" << endl;
			cout << "- Masukkan Hari Latihan (example: Senin) -" << endl;
			cout << " >> : "; fflush(stdin); getline(cin, data[indeks].sub_c.hari);
			cout << "- Masukkan Tanggal Latihan (DD MM YYYY) -" << endl;
			cout << " >> : "; cin>>data[indeks].sub_c.tgl >> data[indeks].sub_c.bln >> data[indeks].sub_c.thn;
			cout << "- Masukkan Nama Lengkap (example: Budi Tabutir) -" << endl;
			cout << " >> : "; fflush(stdin); getline(cin, data[indeks].nama);
			cout << "- Masukkan NIM (example: 2109109999) -" << endl;
			cout << " >> : "; cin >> data[indeks].nim;
			cout << "- Masukkan Program Studi (example: Informatika) -" << endl;
			cout << " >> : "; fflush(stdin); getline(cin, data[indeks].prodi);
			cout << "- Masukkan Tahun Angkatan (example: 2021) -" << endl;
			cout << " >> : "; cin >> data[indeks].akt;
			cout << "- Masukkan Fakultas (example: Fakultas Teknik) -" << endl;
			cout << " >> : "; fflush(stdin); getline(cin, data[indeks].fakultas);
			cout << "- Masukkan Nomor Anggota UKM (example: 112018278) -" << endl;
			cout << " >> : "; cin >> data[indeks].nia;
			cout << "- Masukkan Umur (xx) -" << endl;
			cout << " >> : "; cin >> data[indeks].umur;
			cout << "- Masukkan Tanggal Lahir (DD MM YYYY) -" << endl;
			cout << " >> : "; cin>>data[indeks].sub_a.ttl1 >> data[indeks].sub_a.ttl2 >> data[indeks].sub_a.ttl3;
			cout << "- Masukkan Tempat Lahir (example: Samarinda) -" << endl;
			cout << " >> : "; cin>>data[indeks].sub_a.ttl;
			cout << "- Masukkan Gender (example: Pria/Wanita) -" << endl;
			cout << " >> : "; cin>>data[indeks].gender;
			cout << "Tekan [Enter] untuk Melanjutkan Inputan . . ." << endl; getch();	//pause program sebelum ada inputan dari user
			// system("clear");
			system("cls");	//membersihkan layar
			cout << "============================================" << endl;
			cout << "\tSubData Atlit " << data[indeks].nama << endl;
			cout << "============================================" << endl;
			cout << "- Masukkan Berat Badan KG (example: 60.99) -" << endl;
			cout << " >> : "; cin>>data[indeks].sub_a.berat;
			cout << "Masukkan Tinggi Badan CM (example: 165) -" << endl;
			cout << " >> : "; cin>>data[indeks].sub_a.tinggi;
			cout << "- Masukkan Tingkatan Sabuk Kurata (example: IV) -" << endl;
			cout << " >> : "; cin>>data[indeks].sub_a.kurata;
			cout << "- Masukkan Asal Kontingen Daerah (example: Samarinda) -" << endl;
			cout << " >> : "; cin >> data[indeks].sub_a.kontingen;
			cout << "Tekan [Enter] untuk Melanjutkan Inputan . . ." << endl; getch();	//pause program sebelum ada inputan dari user
			// system("clear"); //Linux atau Mac Os
			system("cls");	//membersihkan layar Windows
			cout << "============================================" << endl;
			cout << "\tProgram Latihan " << data[indeks].nama  << endl;
			cout << "\tTanggal " << data[indeks].sub_c.hari << " "<< data [indeks].sub_c.tgl << " ";
			cout << data[indeks].sub_c.bln <<" "<< data[indeks].sub_c.thn << endl;
			cout << "============================================" << endl;
			cout << "Total Menit Crosscountry (example: 60) -" << endl;
			cout << " >> : "; cin >> data[indeks].sub_b.crosscountry;
			cout << "Total Push Up (example: 500) -" << endl;
			cout << " >> : "; cin >> data[indeks].sub_b.push_up;
			cout << "Total Sit Up (example: 500) -" << endl;
			cout << " >> : "; cin >> data[indeks].sub_b.sit_up;
			cout << "Total Pukulan Cepat (example: 1000) -" << endl;
			cout << " >> : "; cin >> data[indeks].sub_b.p_cepat;
			cout << "Total Pukulan Lingkar Dalam (example: 1000) -" << endl;
			cout << " >> : "; cin >> data[indeks].sub_b.p_lingkardalam;
			cout << "Total Pukulan Lingkar Atas (example: 1000) -" << endl;
			cout << " >> : "; cin >> data[indeks].sub_b.p_lingkaratas;
			cout << "Total Tendangan Lingkar Dalam (example: 500) -" << endl;
			cout << " >> : "; cin >> data[indeks].sub_b.t_lingkardalam;
			cout << "Total Tendangan Lingkar Depan (example: 500) -" << endl;
			cout << " >> : "; cin >> data[indeks].sub_b.t_lingkardepan;
			cout << "Total Tendangan Lingkar Belakang (example: 500) -" << endl;
			cout << " >> : "; cin >> data[indeks].sub_b.t_lingkarbelakang;
			cout << "Total Tendangan Samping (example: 500) -" << endl;
			cout << " >> : "; cin >> data[indeks].sub_b.t_samping;
			cout << "Total Tendangan Belakang (example: 500) -" << endl;
			cout << " >> : "; cin >> data[indeks].sub_b.t_belakang;
			
			
			indeks++;	//indeks akan di increment atau ditambah 1 secara terus menurus selama data ditambahkan. agar posisi data yang ditambahkan akan ada dibelakang
			cout << "Data Telah Ditambahkan!!\nApakah Anda Mau Menambahkan Pesanan Lagi? (y/n)\n >> ";
			cin >> pilih;	//Konfirmasi pengulangan atau tidak
		}
		else{
			cout << "Data Atlit Terlalu Banyak!!" << endl;
			break;			//menghentikan program secara paksa jika memori penuh/indeks penuh
		}
	} while (pilih == "y" | pilih == "Y");
};

void ubah_list_atlit(){
	cout << "Ubah BOS" << endl;

	int pilih;			//Deklarasi tipe data int pada var pilih
	string cari;		//Deklarasi tipe data string pada var cari
	system("cls");		//membersihkan layar
	cout << "============================================" << endl;
	cout << "=             Ubah Data Atlit              =" << endl;
	cout << "============================================" << endl;
	tampil();			//menampilkan nama atlit yang ada
	cout << " >> Masukan Nama Atlit yang ingin anda Ubah : "; cin >> cari;	//masukan nama
	
	while (true){		//Perulangan untuk mengatasi salah inputan
		system("cls");	//Membersihkan layar
		for (int i = 0; i < indeks; i++){		//perulangan untuk mendapatkan data array
			if (cari == data[i].nama){	//percabangan if untuk mendapatkan data dengan memeriksa apakah cari == data array nama
				cout << "============================================" << endl;
				cout << "            Biodata Atlit [" << i+1 << "]	" << endl;
				cout << "=------------------------------------------=" << endl;
				cout << "Nama Anggota : " << data[i].nama << endl;
				cout << "NIM : " << data[i].nim << endl;
				cout << "NIA : " << data[i].nia << endl;
				cout << "Prodi : " << data[i].prodi << "(" << data[i].akt << ")" << endl;
				cout << "Fakultas : " << data[i].fakultas << endl;
				cout << "Umur : " << data[i].umur << " Tahun" << endl;
				cout << "TTL : "; 
				cout << data[i].sub_a.ttl<<", "<<data[i].sub_a.ttl1<<" "<<data[i].sub_a.ttl2<<" "<<data[i].sub_a.ttl3 << endl;
				cout << "Jenis gender : " << data[i].gender << endl;
				cout << "=------------------------------------------=" << endl;
				cout << "=           Subdata Atlit [" << i+1 << "]            =" << endl;
				cout << "=------------------------------------------=" << endl;
				cout << "Berat Badan : " << data[i].sub_a.berat << endl;
				cout << "Tinggi Badan : " << data[i].sub_a.tinggi << endl;
				cout << "Tingkat Sabuk : " << data[i].sub_a.kurata << endl;
				cout << "Kontingen : " << data[i].sub_a.kontingen << endl;
				cout << "=------------------------------------------=" << endl;
				cout << "       Program Latihan Per Hari [" << i+1 << "] 	" << endl;
				cout << "=------------------------------------------=" << endl;
				cout << "Hari/Tanggal : "<<data[i].sub_c.hari<<", "<<data[i].sub_c.tgl<<" - "<<data[i].sub_c.bln<<" - "<<data[i].sub_c.thn<<endl;
				cout << "Total Push Up : " << data[i].sub_b.push_up << "x" << endl;
				cout << "Total Sit Up : " << data[i].sub_b.sit_up << "x" << endl;
				cout << "Total Jogging : " << data[i].sub_b.crosscountry << " menit" << endl;
				cout << "Total Pukulan Cepat : " << data[i].sub_b.p_cepat << "x" << endl;
				cout << "Total Pukulan Lingkar Dalam : " << data[i].sub_b.p_lingkardalam << "x" << endl;
				cout << "Total Pukulan Lingkar Atas : " << data[i].sub_b.p_lingkaratas << "x" << endl;
				cout << "Total Tendangan Lingkar Dalam : " << data[i].sub_b.t_lingkardalam << "x" << endl;
				cout << "Total Tendangan Lingkar Depan : " << data[i].sub_b.t_lingkardepan << "x" << endl;
				cout << "Total Tendangan Lingkar Belakang : " << data[i].sub_b.t_lingkarbelakang << "x" << endl;
				cout << "Total Tendangan Samping : " << data[i].sub_b.t_samping << "x" << endl;
				cout << "Total Tendangan Belakang: " << data[i].sub_b.t_belakang << "x" << endl;
				cout << "============================================" << endl;
			}
				cout << "Apa Yang Ingin Anda Ubah?:\n(1) Data Atlit\n(2) SubData Atlit\n(3) Program Latihan" << endl;
				cout << " >> Masukan Pilihan Anda : "; cin >> pilih;
				
				//percabangan if-else if-else untuk mengubah
				if (pilih == 1){ 		//mengubah nama dengan menindih indeks pada data array tersebut
					system("cls");
					cout << "============================================" << endl;
					cout << "- Masukkan Hari Latihan (example: Senin) -" << endl;
					cout << " >> : "; cin>>data[i].sub_c.hari;
					cout << "- Masukkan Tanggal Latihan (DD MM YY) -" << endl;
					cout << " >> : "; cin>>data[i].sub_c.tgl >> data[i].sub_c.bln >> data[i].sub_c.thn;
					cout << "- Masukkan Nama Lengkap (example: Budi Tabutir) -" << endl;
					cout << " >> : "; fflush(stdin); getline(cin, data[i].nama);
					cout << "- Masukkan NIM (example: 2109109999) -" << endl;
					cout << " >> : "; cin >> data[i].nim;
					cout << "- Masukkan Program Studi (example: Informatika) -" << endl;
					cout << " >> : "; fflush(stdin); getline(cin, data[i].prodi);
					cout << "- Masukkan Tahun Angkatan (example: 2021) -" << endl;
					cout << " >> : "; cin >> data[i].akt;
					cout << "- Masukkan Fakultas (example: Fakultas Teknik) -" << endl;
					cout << " >> : "; fflush(stdin); getline(cin, data[i].fakultas);
					cout << "- Masukkan Nomor Anggota UKM (example: 112018278) -" << endl;
					cout << " >> : "; cin >> data[i].nia;
					cout << "- Masukkan Umur (xx) -" << endl;
					cout << " >> : "; cin >> data[i].umur;
					cout << "- Masukkan Tanggal Lahir (DD MM YYYY) -" << endl;
					cout << " >> : "; cin>>data[i].sub_a.ttl1 >> data[i].sub_a.ttl2 >> data[i].sub_a.ttl3;
					cout << "- Masukkan Tempat Lahir (example: Samarinda) -" << endl;
					cout << " >> : "; cin>>data[i].sub_a.ttl;
					cout << "- Masukkan Gender (example: Pria/Wanita) -" << endl;
					cout << " >> : "; cin>>data[i].gender;
					cout << "Tekan [Enter] untuk Melanjutkan Inputan . . ." << endl; getch();	//pause program sebelum ada inputan dari user
					break;	//keluar dari perulangan for
				}
				
				
				else if (pilih == 2){	//mengubah isi indeks dari subdata
					system("cls");
					cout << "============================================" << endl;
					cout << "\tSubData Atlit " << data[indeks].nama << endl;
					cout << "============================================" << endl;
					cout << "- Masukkan Berat Badan KG (example: 60.99) -" << endl;
					cout << " >> : "; cin>>data[i].sub_a.berat;
					cout << "Masukkan Tinggi Badan CM (example: 165) -" << endl;
					cout << " >> : "; cin>>data[i].sub_a.tinggi;
					cout << "- Masukkan Tingkatan Sabuk Kurata (example: IV) -" << endl;
					cout << " >> : "; cin>>data[i].sub_a.kurata;
					cout << "- Masukkan Asal Kontingen Daerah (example: Samarinda) -" << endl;
					cout << " >> : "; cin >> data[i].sub_a.kontingen;
					cout << "Tekan [Enter] untuk Melanjutkan Inputan . . ." << endl; getch();	//pause program sebelum ada inputan dari user
					break;	//keluar dari perulangan for
				}
				else if (pilih == 3){	//mengubah nomor_hp dengan menindih indeks pada data array tersebut
					system("cls");
					cout << "============================================" << endl;
					cout << "\tProgram Latihan " << data[i].nama  << endl;
					cout << "\tTanggal " << data[i].sub_c.hari << " "<< data [i].sub_c.tgl << " ";
					cout << data[i].sub_c.bln << data[i].sub_c.thn << endl;
					cout << "============================================" << endl;
					cout << "Total Menit Crosscountry (example: 60) -" << endl;
					cout << " >> : "; cin >> data[i].sub_b.crosscountry;
					cout << "Total Push Up (example: 500) -" << endl;
					cout << " >> : "; cin >> data[i].sub_b.push_up;
					cout << "Total Sit Up (example: 500) -" << endl;
					cout << " >> : "; cin >> data[i].sub_b.sit_up;
					cout << "Total Pukulan Cepat (example: 1000) -" << endl;
					cout << " >> : "; cin >> data[i].sub_b.p_cepat;
					cout << "Total Pukulan Lingkar Dalam (example: 1000) -" << endl;
					cout << " >> : "; cin >> data[i].sub_b.p_lingkardalam;
					cout << "Total Pukulan Lingkar Atas (example: 1000) -" << endl;
					cout << " >> : "; cin >> data[i].sub_b.p_lingkaratas;
					cout << "Total Tendangan Lingkar Dalam (example: 500) -" << endl;
					cout << " >> : "; cin >> data[i].sub_b.t_lingkardalam;
					cout << "Total Tendangan Lingkar Depan (example: 500) -" << endl;
					cout << " >> : "; cin >> data[i].sub_b.t_lingkardepan;
					cout << "Total Tendangan Lingkar Belakang (example: 500) -" << endl;
					cout << " >> : "; cin >> data[i].sub_b.t_lingkarbelakang;
					cout << "Total Tendangan Samping (example: 500) -" << endl;
					cout << " >> : "; cin >> data[i].sub_b.t_samping;
					cout << "Total Tendangan Belakang (example: 500) -" << endl;
					cout << " >> : "; cin >> data[i].sub_b.t_belakang;
					cout << "Tekan [Enter] untuk Melanjutkan Inputan . . ." << endl; getch();	//pause program sebelum ada inputan dari user
					break;	//keluar dari perulangan for
				}
				else{					//jika pilihan diluar 1-6, maka tampilkan output dibawah
					system("cls");	//membersihkan layar
					cout << " -= Pilihan Tersebut Tidak ada " << endl;
					getch();		//pause program sebelum ada inputan dari user
					system("cls");	//membersihkan layar
				}
			}
		break; //keluar dari perulangan for	
	}
}

void hapus_list_atlit(){
	cout << "Hapus BOS" << endl;
	string cari, pilih;		//deklarasi tipe data string pada var cari dan pilih
	system("cls");			//membersihkan layar
	cout << "===================================" << endl;
	cout << "-=	 Hapus Pesanan	 -=" << endl;
	cout << "===================================" << endl;
	tampil();				//menampilkan nama pemesan yang ada
	cout << " >> Masukan Nama Pelanggan yang ingin Anda Hapus : "; cin >> cari;	//masukan nama pelanggan yang ingin dihapus

	system("cls");			//membersihkan layar
	for (int i = 0; i < indeks; i++){	//perulangan untuk mendapatkan data array
		if (cari == data[i].nama){	//percabangan untuk memeriksa apakah data yang dicari ada pada elemen array
			cout << "\n==========================================" << endl;
			cout << "            Biodata Atlit [" << i+1 << "]	" << endl;
			cout << "=------------------------------------------=" << endl;
			cout << "Nama Anggota : " << data[i].nama << endl;
			cout << "NIM : " << data[i].nim << endl;
			cout << "NIA : " << data[i].nia << endl;
			cout << "Prodi : " << data[i].prodi << "(" << data[i].akt << ")" << endl;
			cout << "Fakultas : " << data[i].fakultas << endl;
			cout << "Umur : " << data[i].umur << " Tahun" << endl;
			cout << "TTL : "; 
			cout << data[i].sub_a.ttl<<", "<<data[i].sub_a.ttl1<<" "<<data[i].sub_a.ttl2<<" "<<data[i].sub_a.ttl3 << endl;
			cout << "Jenis gender : " << data[i].gender << endl;
			cout << "=------------------------------------------=" << endl;
			cout << "=           Subdata Atlit [" << i+1 << "]            =" << endl;
			cout << "=------------------------------------------=" << endl;
			cout << "Berat Badan : " << data[i].sub_a.berat << endl;
			cout << "Tinggi Badan : " << data[i].sub_a.tinggi << endl;
			cout << "Tingkat Sabuk : " << data[i].sub_a.kurata << endl;
			cout << "Kontingen : " << data[i].sub_a.kontingen << endl;
			cout << "=------------------------------------------=" << endl;
			cout << "       Program Latihan Per Hari [" << i+1 << "] 	" << endl;
			cout << "=------------------------------------------=" << endl;
			cout << "Hari/Tanggal : "<<data[i].sub_c.hari<<", "<<data[i].sub_c.tgl<<" - "<<data[i].sub_c.bln<<" - "<<data[i].sub_c.thn<<endl;
			cout << "Total Push Up : " << data[i].sub_b.push_up << "x" << endl;
			cout << "Total Sit Up : " << data[i].sub_b.sit_up << "x" << endl;
			cout << "Total Jogging : " << data[i].sub_b.crosscountry << " menit" << endl;
			cout << "Total Pukulan Cepat : " << data[i].sub_b.p_cepat << "x" << endl;
			cout << "Total Pukulan Lingkar Dalam : " << data[i].sub_b.p_lingkardalam << "x" << endl;
			cout << "Total Pukulan Lingkar Atas : " << data[i].sub_b.p_lingkaratas << "x" << endl;
			cout << "Total Tendangan Lingkar Dalam : " << data[i].sub_b.t_lingkardalam << "x" << endl;
			cout << "Total Tendangan Lingkar Depan : " << data[i].sub_b.t_lingkardepan << "x" << endl;
			cout << "Total Tendangan Lingkar Belakang : " << data[i].sub_b.t_lingkarbelakang << "x" << endl;
			cout << "Total Tendangan Samping : " << data[i].sub_b.t_samping << "x" << endl;
			cout << "Total Tendangan Belakang: " << data[i].sub_b.t_belakang << "x" << endl;
			cout << "============================================" << endl;

			cout << "\nApakah Anda Yakin untuk Menghapus Pesanan Pelanggan " << data[indeks].nama << " (y/n)"<< endl;	//konfirmasi penghapusan
			cout << " >> Masukan Pilihan : ";cin >> pilih;

			if (pilih == "y"){			//jika pilih sama dengan y, jalankan tahapan penghapusan
				data[i] = data[i+1];	//elemen pada array pada posisi i akan ditambahkan 1
				indeks = indeks - 1;	//mengurangi indeks untuk menghilangkan elemen yang telah dihapus
				cout << " -Data Atlit Telah Dihapus" << endl;
			}
			else if (pilih == "n"){		//jika pilih == n, maka tidak jadi menghapus dan tampilkan output dibawah
				cout << " -Gagal Menghapus" << endl;
			}
		}
	}
};

void sorting_list_atlit(){
	int pilih;
	cout << endl;
	cout << "============================================" << endl;
	cout << "=          Advance View Data Atlit         =" << endl;
	cout << "============================================" << endl;
	cout << "Lihat Data Atlit Berdasarkan?" << endl;
	cout << "(1) Nama Atlit\n(2) Usia Atlit\n(3) Nomor Induk Mahasiswa\n(4) Nomor Mahasiswa\n(5) Tingkat Sabuk" << endl;
	cout << "\n >> Masukan Pilihan : ";cin >> pilih;
	if (pilih == 1){
		bubblesort_nama(data, indeks);
		print_nama();
		}
		
	else if (pilih == 2){
		cout << "1. Ascending" << endl;
		cout << "2. Descending" << endl;
		cout << "Pengurutan berdasarkan: "; cin >> pilih;
		switch (pilih){
			case 1:
				quicksort_ascending_umur(data, 0, indeks-1 );
				print_umur();
				break;
			case 2:
				quicksort_descending_umur(data, 0, indeks-1 );
				print_umur();
				break;
				}
			}
		
	else if (pilih == 3){
		bubblesort_nim(data, indeks);
		print_nim();
		}
	
	else if (pilih == 4){
		selectionsort_nia(data, indeks);
		print_nia();
		}
	
	else if (pilih == 5){
		selectionsort_kurata(data, indeks);
		print_nia();
		}
	else {
		system("cls");			//membersihkan layar
		cout << " -= Pilihan tersebut tidak ada." << endl; getch();			//pause program sebelum ada inputan dari user
		}
	}


void print_nama(){
	system("cls");
	int i;
	for (i=0; i < indeks; i++){
		cout << "\n==========================================" << endl;
		cout << "            Biodata Atlit [" << i+1 << "]	" << endl;
		cout << "=------------------------------------------=" << endl;
		cout << "Nama Anggota : " << data[i].nama << endl;
		cout << "Umur : " << data[i].umur << " Tahun" << endl;
		cout << "NIM : " << data[i].nim << endl;
		cout << "NIA : " << data[i].nia << endl;
		cout << "Prodi : " << data[i].prodi << "(" << data[i].akt << ")" << endl;
		cout << "Fakultas : " << data[i].fakultas << endl;
		cout << "TTL : "; 
		cout << data[i].sub_a.ttl<<", "<<data[i].sub_a.ttl1<<" "<<data[i].sub_a.ttl2<<" "<<data[i].sub_a.ttl3 << endl;
		cout << "Jenis gender : " << data[i].gender << endl;
		cout << "=------------------------------------------=" << endl;
		cout << "=           Subdata Atlit [" << i+1 << "]            =" << endl;
		cout << "=------------------------------------------=" << endl;
		cout << "Berat Badan : " << data[i].sub_a.berat << endl;
		cout << "Tinggi Badan : " << data[i].sub_a.tinggi << endl;
		cout << "Tingkat Sabuk : " << data[i].sub_a.kurata << endl;
		cout << "Kontingen : " << data[i].sub_a.kontingen << endl;
		cout << "=------------------------------------------=" << endl;
		cout << "       Program Latihan Per Hari [" << i+1 << "] 	" << endl;
		cout << "=------------------------------------------=" << endl;
		cout << "Hari/Tanggal : "<<data[i].sub_c.hari<<", "<<data[i].sub_c.tgl<<" - "<<data[i].sub_c.bln<<" - "<<data[i].sub_c.thn<<endl;
		cout << "Total Push Up : " << data[i].sub_b.push_up << "x" << endl;
		cout << "Total Sit Up : " << data[i].sub_b.sit_up << "x" << endl;
		cout << "Total Jogging : " << data[i].sub_b.crosscountry << " menit" << endl;
		cout << "Total Pukulan Cepat : " << data[i].sub_b.p_cepat << "x" << endl;
		cout << "Total Pukulan Lingkar Dalam : " << data[i].sub_b.p_lingkardalam << "x" << endl;
		cout << "Total Pukulan Lingkar Atas : " << data[i].sub_b.p_lingkaratas << "x" << endl;
		cout << "Total Tendangan Lingkar Dalam : " << data[i].sub_b.t_lingkardalam << "x" << endl;
		cout << "Total Tendangan Lingkar Depan : " << data[i].sub_b.t_lingkardepan << "x" << endl;
		cout << "Total Tendangan Lingkar Belakang : " << data[i].sub_b.t_lingkarbelakang << "x" << endl;
		cout << "Total Tendangan Samping : " << data[i].sub_b.t_samping << "x" << endl;
		cout << "Total Tendangan Belakang: " << data[i].sub_b.t_belakang << "x" << endl;
		cout << "============================================" << endl;
	}
	cout << "Tekan [Enter] untuk Melanjutkan . . ." << endl; getch();	//pause program sebelum ada inputan dari user
}

void print_umur(){
	system("cls");
	int i;
	for (i=0; i < indeks; i++){
		cout << "\n==========================================" << endl;
		cout << "            Biodata Atlit [" << i+1 << "]	" << endl;
		cout << "=------------------------------------------=" << endl;
		cout << "Umur : " << data[i].umur << " Tahun" << endl;
		cout << "Nama Anggota : " << data[i].nama << endl;
		cout << "NIM : " << data[i].nim << endl;
		cout << "NIA : " << data[i].nia << endl;
		cout << "Prodi : " << data[i].prodi << "(" << data[i].akt << ")" << endl;
		cout << "Fakultas : " << data[i].fakultas << endl;
		cout << "TTL : "; 
		cout << data[i].sub_a.ttl<<", "<<data[i].sub_a.ttl1<<" "<<data[i].sub_a.ttl2<<" "<<data[i].sub_a.ttl3 << endl;
		cout << "Jenis gender : " << data[i].gender << endl;
		cout << "=------------------------------------------=" << endl;
		cout << "=           Subdata Atlit [" << i+1 << "]            =" << endl;
		cout << "=------------------------------------------=" << endl;
		cout << "Berat Badan : " << data[i].sub_a.berat << endl;
		cout << "Tinggi Badan : " << data[i].sub_a.tinggi << endl;
		cout << "Tingkat Sabuk : " << data[i].sub_a.kurata << endl;
		cout << "Kontingen : " << data[i].sub_a.kontingen << endl;
		cout << "=------------------------------------------=" << endl;
		cout << "       Program Latihan Per Hari [" << i+1 << "] 	" << endl;
		cout << "=------------------------------------------=" << endl;
		cout << "Hari/Tanggal : "<<data[i].sub_c.hari<<", "<<data[i].sub_c.tgl<<" - "<<data[i].sub_c.bln<<" - "<<data[i].sub_c.thn<<endl;
		cout << "Total Push Up : " << data[i].sub_b.push_up << "x" << endl;
		cout << "Total Sit Up : " << data[i].sub_b.sit_up << "x" << endl;
		cout << "Total Jogging : " << data[i].sub_b.crosscountry << " menit" << endl;
		cout << "Total Pukulan Cepat : " << data[i].sub_b.p_cepat << "x" << endl;
		cout << "Total Pukulan Lingkar Dalam : " << data[i].sub_b.p_lingkardalam << "x" << endl;
		cout << "Total Pukulan Lingkar Atas : " << data[i].sub_b.p_lingkaratas << "x" << endl;
		cout << "Total Tendangan Lingkar Dalam : " << data[i].sub_b.t_lingkardalam << "x" << endl;
		cout << "Total Tendangan Lingkar Depan : " << data[i].sub_b.t_lingkardepan << "x" << endl;
		cout << "Total Tendangan Lingkar Belakang : " << data[i].sub_b.t_lingkarbelakang << "x" << endl;
		cout << "Total Tendangan Samping : " << data[i].sub_b.t_samping << "x" << endl;
		cout << "Total Tendangan Belakang: " << data[i].sub_b.t_belakang << "x" << endl;
		cout << "============================================" << endl;
	}
	cout << "Tekan [Enter] untuk Melanjutkan . . ." << endl; getch();	//pause program sebelum ada inputan dari user
}

void print_nim(){
	system("cls");
	int i;
	for (i=0; i < indeks; i++){
		cout << "\n==========================================" << endl;
		cout << "            Biodata Atlit [" << i+1 << "]	" << endl;
		cout << "=------------------------------------------=" << endl;
		cout << "NIM : " << data[i].nim << endl;
		cout << "Nama Anggota : " << data[i].nama << endl;
		cout << "NIA : " << data[i].nia << endl;
		cout << "Umur : " << data[i].umur << " Tahun" << endl;
		cout << "Prodi : " << data[i].prodi << "(" << data[i].akt << ")" << endl;
		cout << "Fakultas : " << data[i].fakultas << endl;
		cout << "TTL : "; 
		cout << data[i].sub_a.ttl<<", "<<data[i].sub_a.ttl1<<" "<<data[i].sub_a.ttl2<<" "<<data[i].sub_a.ttl3 << endl;
		cout << "Jenis gender : " << data[i].gender << endl;
		cout << "=------------------------------------------=" << endl;
		cout << "=           Subdata Atlit [" << i+1 << "]            =" << endl;
		cout << "=------------------------------------------=" << endl;
		cout << "Berat Badan : " << data[i].sub_a.berat << endl;
		cout << "Tinggi Badan : " << data[i].sub_a.tinggi << endl;
		cout << "Tingkat Sabuk : " << data[i].sub_a.kurata << endl;
		cout << "Kontingen : " << data[i].sub_a.kontingen << endl;
		cout << "=------------------------------------------=" << endl;
		cout << "       Program Latihan Per Hari [" << i+1 << "] 	" << endl;
		cout << "=------------------------------------------=" << endl;
		cout << "Hari/Tanggal : "<<data[i].sub_c.hari<<", "<<data[i].sub_c.tgl<<" - "<<data[i].sub_c.bln<<" - "<<data[i].sub_c.thn<<endl;
		cout << "Total Push Up : " << data[i].sub_b.push_up << "x" << endl;
		cout << "Total Sit Up : " << data[i].sub_b.sit_up << "x" << endl;
		cout << "Total Jogging : " << data[i].sub_b.crosscountry << " menit" << endl;
		cout << "Total Pukulan Cepat : " << data[i].sub_b.p_cepat << "x" << endl;
		cout << "Total Pukulan Lingkar Dalam : " << data[i].sub_b.p_lingkardalam << "x" << endl;
		cout << "Total Pukulan Lingkar Atas : " << data[i].sub_b.p_lingkaratas << "x" << endl;
		cout << "Total Tendangan Lingkar Dalam : " << data[i].sub_b.t_lingkardalam << "x" << endl;
		cout << "Total Tendangan Lingkar Depan : " << data[i].sub_b.t_lingkardepan << "x" << endl;
		cout << "Total Tendangan Lingkar Belakang : " << data[i].sub_b.t_lingkarbelakang << "x" << endl;
		cout << "Total Tendangan Samping : " << data[i].sub_b.t_samping << "x" << endl;
		cout << "Total Tendangan Belakang: " << data[i].sub_b.t_belakang << "x" << endl;
		cout << "============================================" << endl;
	}
	cout << "Tekan [Enter] untuk Melanjutkan . . ." << endl; getch();	//pause program sebelum ada inputan dari user
}

void print_nia(){
	system("cls");
	int i;
	for (i=0; i < indeks; i++){
		cout << "\n==========================================" << endl;
		cout << "            Biodata Atlit [" << i+1 << "]	" << endl;
		cout << "=------------------------------------------=" << endl;
		cout << "NIA : " << data[i].nia << endl;
		cout << "Nama Anggota : " << data[i].nama << endl;
		cout << "NIM : " << data[i].nim << endl;
		cout << "Umur : " << data[i].umur << " Tahun" << endl;
		cout << "Prodi : " << data[i].prodi << "(" << data[i].akt << ")" << endl;
		cout << "Fakultas : " << data[i].fakultas << endl;
		cout << "TTL : "; 
		cout << data[i].sub_a.ttl<<", "<<data[i].sub_a.ttl1<<" "<<data[i].sub_a.ttl2<<" "<<data[i].sub_a.ttl3 << endl;
		cout << "Jenis gender : " << data[i].gender << endl;
		cout << "=------------------------------------------=" << endl;
		cout << "=           Subdata Atlit [" << i+1 << "]            =" << endl;
		cout << "=------------------------------------------=" << endl;
		cout << "Berat Badan : " << data[i].sub_a.berat << endl;
		cout << "Tinggi Badan : " << data[i].sub_a.tinggi << endl;
		cout << "Tingkat Sabuk : " << data[i].sub_a.kurata << endl;
		cout << "Kontingen : " << data[i].sub_a.kontingen << endl;
		cout << "=------------------------------------------=" << endl;
		cout << "       Program Latihan Per Hari [" << i+1 << "] 	" << endl;
		cout << "=------------------------------------------=" << endl;
		cout << "Hari/Tanggal : "<<data[i].sub_c.hari<<", "<<data[i].sub_c.tgl<<" - "<<data[i].sub_c.bln<<" - "<<data[i].sub_c.thn<<endl;
		cout << "Total Push Up : " << data[i].sub_b.push_up << "x" << endl;
		cout << "Total Sit Up : " << data[i].sub_b.sit_up << "x" << endl;
		cout << "Total Jogging : " << data[i].sub_b.crosscountry << " menit" << endl;
		cout << "Total Pukulan Cepat : " << data[i].sub_b.p_cepat << "x" << endl;
		cout << "Total Pukulan Lingkar Dalam : " << data[i].sub_b.p_lingkardalam << "x" << endl;
		cout << "Total Pukulan Lingkar Atas : " << data[i].sub_b.p_lingkaratas << "x" << endl;
		cout << "Total Tendangan Lingkar Dalam : " << data[i].sub_b.t_lingkardalam << "x" << endl;
		cout << "Total Tendangan Lingkar Depan : " << data[i].sub_b.t_lingkardepan << "x" << endl;
		cout << "Total Tendangan Lingkar Belakang : " << data[i].sub_b.t_lingkarbelakang << "x" << endl;
		cout << "Total Tendangan Samping : " << data[i].sub_b.t_samping << "x" << endl;
		cout << "Total Tendangan Belakang: " << data[i].sub_b.t_belakang << "x" << endl;
		cout << "============================================" << endl;
	}
	cout << "Tekan [Enter] untuk Melanjutkan . . ." << endl; getch();	//pause program sebelum ada inputan dari user
}

void print_kurata(){
	system("cls");
	int i;
	for (i=0; i < indeks; i++){
		cout << "\n==========================================" << endl;
		cout << "            Biodata Atlit [" << i+1 << "]	" << endl;
		cout << "=------------------------------------------=" << endl;
		cout << "Tingkat Sabuk : " << data[i].sub_a.kurata << endl;
		cout << "Nama Anggota : " << data[i].nama << endl;
		cout << "NIM : " << data[i].nim << endl;
		cout << "NIA : " << data[i].nia << endl;
		cout << "Umur : " << data[i].umur << " Tahun" << endl;
		cout << "Prodi : " << data[i].prodi << "(" << data[i].akt << ")" << endl;
		cout << "Fakultas : " << data[i].fakultas << endl;
		cout << "TTL : "; 
		cout << data[i].sub_a.ttl<<", "<<data[i].sub_a.ttl1<<" "<<data[i].sub_a.ttl2<<" "<<data[i].sub_a.ttl3 << endl;
		cout << "Jenis gender : " << data[i].gender << endl;
		cout << "=------------------------------------------=" << endl;
		cout << "=           Subdata Atlit [" << i+1 << "]            =" << endl;
		cout << "=------------------------------------------=" << endl;
		cout << "Berat Badan : " << data[i].sub_a.berat << endl;
		cout << "Tinggi Badan : " << data[i].sub_a.tinggi << endl;
		cout << "Kontingen : " << data[i].sub_a.kontingen << endl;
		cout << "=------------------------------------------=" << endl;
		cout << "       Program Latihan Per Hari [" << i+1 << "] 	" << endl;
		cout << "=------------------------------------------=" << endl;
		cout << "Hari/Tanggal : "<<data[i].sub_c.hari<<", "<<data[i].sub_c.tgl<<" - "<<data[i].sub_c.bln<<" - "<<data[i].sub_c.thn<<endl;
		cout << "Total Push Up : " << data[i].sub_b.push_up << "x" << endl;
		cout << "Total Sit Up : " << data[i].sub_b.sit_up << "x" << endl;
		cout << "Total Jogging : " << data[i].sub_b.crosscountry << " menit" << endl;
		cout << "Total Pukulan Cepat : " << data[i].sub_b.p_cepat << "x" << endl;
		cout << "Total Pukulan Lingkar Dalam : " << data[i].sub_b.p_lingkardalam << "x" << endl;
		cout << "Total Pukulan Lingkar Atas : " << data[i].sub_b.p_lingkaratas << "x" << endl;
		cout << "Total Tendangan Lingkar Dalam : " << data[i].sub_b.t_lingkardalam << "x" << endl;
		cout << "Total Tendangan Lingkar Depan : " << data[i].sub_b.t_lingkardepan << "x" << endl;
		cout << "Total Tendangan Lingkar Belakang : " << data[i].sub_b.t_lingkarbelakang << "x" << endl;
		cout << "Total Tendangan Samping : " << data[i].sub_b.t_samping << "x" << endl;
		cout << "Total Tendangan Belakang: " << data[i].sub_b.t_belakang << "x" << endl;
		cout << "============================================" << endl;
	}
	cout << "Tekan [Enter] untuk Melanjutkan . . ." << endl; getch();	//pause program sebelum ada inputan dari user
}

void cari_list_atlit(){
	int pil;
	cout << endl;
	// system("clear");
	system("cls");		//membersihkan layar
	cout << "============================================" << endl;
	cout << "=            Daftar Data Atlit             =" << endl;
	cout << "============================================" << endl;
	cout << "(1) Cari Data Atlit Berdasarkan NIM"  << endl;
	cout << "(2) Cari Data Atlit Berdasarkan Nama" << endl;
	cout << endl;
	cout << "  >> Masukan Pilihan Anda : "; cin >> pil;
	if (pil == 1){
		interpolation_search(data, indeks);		
	}
	else if (pil == 2){
		binarySearch(data, 0, indeks);
	}
}
