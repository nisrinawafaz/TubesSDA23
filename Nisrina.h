#ifndef Nisrina_H
#define Nisrina_H

#include "header.h" 

#include "header.h"
#include "Fauza.h"
#include "Nisrina.h"
#include "Agam.h"

//market modul
bool loginAdmin(infotype username, infotype password);

void selamat_datang();

void loading(char x[100]);

void selection(char *choice, infotype fChoice, infotype sChoice, infotype pertanyaan, infotype kesimpulan);

void inputLogin(infotype *username, infotype *password);

void adminFitur(Link *root);

void pemesanan(stroller *front, stroller *rear, Link root);

void input_struk(stroller data, float total, float minimal, float ppn, float diskon, float hasil, float uang_bayar,float uang_kembalian);

stroller AlokasiKeranjang(infotype kode, infotype barang,infotype size,  float harga, int kuantitas, float total);

stroller SearchKeranjang (stroller front, infotype kode);

void InsertLastKeranjang (stroller *front, stroller *rear, stroller P);

void InsVLastKeranjang(stroller *front, stroller *rear, infotype kode, infotype barang, infotype size, float harga, int kuantitas, float total);

void PrintInfokeranjang (stroller data);

void DelKeranjang (stroller *front, infotype kode);

void DeAlokasi (stroller P);

void header_struk();

void footer_struk();

float hitung_diskon(float total, float potongan);

float hitung_hasil(float total, float potongan, float minimal, float ppn);

void output_bayar(float total, float minimal, float ppn, float diskon, float hasil);

float total_harga(stroller front);

float hitung_ppn(float total, float ppn);


//huffman tree modul
address AlokasiChar(char X);

address Search (address front, char X);

void InsertLastChar (address *front, address *rear, address P);

void InsVLastChar(address *front, address *rear, char X);

address createFrekuensi();

void sortingFreq(address *front);

Link CreateHuffmanTree();

void  incodeBarang(infotype *kodebinary, infotype *barangbinary, infotype *sizebinary, infotype *hargabinary, infotype *stokbinary, infotype kode, infotype barang, infotype size, infotype harga, infotype stok, Link root);

void PrintFrekuensi (address data);

infotype InputCodeChar(infotype deskripsi);

void SearchTree(Link temp, char x, Link *temp2);

infotype Incode(Link root, infotype KodeChar);

void FSearchBarang2(infotype NmFile, infotype kode, infotype *NmBarang, infotype *size, infotype *Harga, infotype *Stok);

void FSearchKodeChar(infotype NmFile, infotype binary, infotype *kodeChar);
#endif
