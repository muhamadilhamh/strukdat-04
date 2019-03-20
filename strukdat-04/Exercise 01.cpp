/*
Nama	= Muhamad Ilham Habib
NPM		= 140810180018
Kelas	= B
Deskripsi = struktur data Pegawai
Tahun	= 2019
*/
#include <iostream>
#include <iomanip>
using namespace std;

struct ElemtList {
	char pegawai[50];
	char bidang[30];
	int gaji;
	ElemtList* next;
};
typedef ElemtList* pointer;
typedef pointer List;

void createList(List& First) {
	First = NULL;
}
void createElmt(pointer& pBaru) {
	pBaru = new ElemtList;
	cout << "masukan pegawai ="; cin.ignore(); cin.getline(pBaru->pegawai, 50);
	cout << "masukan bidang =";cin.getline(pBaru->bidang, 30);
	cout << "masukan gaji ="; cin >> pBaru->gaji;
	pBaru->next = NULL;
	cin.get();
}
void insertFirst(List& First, pointer pBaru) {
	if (First == NULL)
		First = pBaru;
	else {
		pBaru->next = First;
		First = pBaru;
	}
}
void insertLast(List& First, pointer pBaru) {
	pointer last;
	cout << "Insert Last" << endl;
	if (First == NULL) {
		First = pBaru;
	}
	else {
		last = First;
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = pBaru;
	}
}
void deleteFirst(List& First, pointer& pHapus) {
	if (First == NULL) {
		pHapus = NULL;
		cout << "List kosong, tidak ada yg dihapus" << endl;
	}
	else if (First->next == NULL) {
		pHapus = First;
		First = NULL;
	}
	else {
		pHapus = First;
		First = First->next;
		pHapus->next = NULL;
	}
}
void deleteLast(List&First, pointer& pHapus) {
	pointer Last, precLast;
	if (First == NULL) {
		pHapus = NULL;
		cout << "List Kosong" << endl;
	}
	else if (First->next == NULL) {
		pHapus = First;
		First = NULL;
	}
	else {
	Last = First;
	precLast = NULL;
	while (Last->next != NULL) {
		precLast = Last;
		Last = Last->next;
	}
	pHapus = Last;
	precLast->next = NULL;
	}
}
void traversal(List First) {
	pointer pBantu;
	pBantu = First;
	int i = 1;
	cout << setw(5) << "No" << setw(23) << " Nama" << setw(18) << "Bidang" << setw(18) << " Gaji" << endl;
	do {
		cout << setw(5) << i << setw(23) << pBantu->pegawai << setw(18) << pBantu->bidang << setw(18) << pBantu->gaji << endl;
		pBantu = pBantu->next;
		i++;
	} while (pBantu != NULL); {
		cout << endl;
	}
}
int main() {
	pointer pBaru;
	pointer pBantu;
	List First;
	int pilihan;
	char jawab;
	createList(First);
	do {
		system("cls");
		cout << "Pilih Menu : \n" << endl;
		cout << "1. Insert First" << endl;
		cout << "2. Insert Last" << endl;
		cout << "3. Delete First" << endl;
		cout << "4. Delete Last" << endl;
		cout << "5. Tampilkan Data ( traversal )" << endl;
		cout << "\nMasukan Pilihan : "; cin >> pilihan;
		switch (pilihan) {
		case 1:
			createElmt(pBaru);
			insertFirst(First, pBaru);
			break;

		case 2:
			createElmt(pBaru);
			insertLast(First, pBaru);
			break;

		case 3:
			deleteFirst(First, pBaru);
			break;

		case 4:
			deleteLast(First, pBaru);
			break;

		case 5:
			cout << "\n====================================================================\n";
			traversal(First);
			break;

		case 6:
			return 0;
			break;
		}

		cout << "Ingin Ke Menu lagi? (Y/N) "; cin >> jawab;
		cin.ignore();
		if (jawab == 'Y' || jawab == 'y') { system("cls"); }
		else
			cout << "\n=====================================================================\n";
		traversal(First);
	} while (jawab == 'Y' || jawab == 'y');
	cin.get();	
}

