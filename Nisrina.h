#ifndef Nisrina_H
#define Nisrina_H

#include "header.h" 

bool loginAdmin(infotype username, infotype password);

void selamat_datang();

void loading(char x[100]);

void selection(int *choice, infotype fChoice, infotype sChoice, infotype pertanyaan, infotype kesimpulan);

void inputLogin(infotype *username, infotype *password);

void adminFitur(Link *root);

void pemesanan(stroller *front, stroller *rear, Link root);

void input_struk(stroller data);

stroller AlokasiKeranjang(infotype kode, infotype barang,infotype size,  int harga, int kuantitas, int total);

stroller SearchKeranjang (stroller front, infotype barang);

void FSearchBarang2(infotype NmFile, infotype kode, infotype *NmBarang, infotype *size, infotype *Harga, infotype *Stok);

void FSearchKodeChar(infotype NmFile, infotype binary, infotype *kodeChar);

void InsertLastKeranjang (stroller *front, stroller *rear, stroller P);

void InsVLastKeranjang(stroller *front, stroller *rear, infotype kode, infotype barang, infotype size, int harga, int kuantitas, int total);

void PrintInfokeranjang (stroller data);

void DelKeranjang (stroller *front, infotype nama);

void DeAlokasi (stroller P);

void header_struk();

double hitung_diskon(int total, double potongan);

double hitung_hasil(int total, double potongan, int minimal, double ppn);

void output_bayar(int total, int minimal, double ppn, double diskon, double hasil);

int total_harga(stroller front);

double hitung_ppn(int total, double ppn);

stroller SearchKeranjang (stroller front, infotype barang);

double hitung_diskon(int total, double potongan);

double hitung_hasil(int total, double potongan, int minimal, double ppn);

void output_bayar(int total, int minimal, double ppn, double diskon, double hasil);

int total_harga(stroller front);

double hitung_ppn(int total, double ppn);

//huffman tree
address AlokasiChar(char X);

address Search (address front, char X);

void InsertLastChar (address *front, address *rear, address P);

void InsVLastChar(address *front, address *rear, char X);

void PrintInfoChar (address data);

void sortingFreq(address *front);

address createFrekuensi();

infotype InputCodeChar(infotype deskripsi);

void SearchTree(Link root, char x, Link *temp2);

infotype Incode(Link root, infotype KodeChar);

Link CreateHuffmanTree();

void  incodeBarang(infotype *barangbinary, infotype *sizebinary, infotype *hargabinary, infotype *stokbinary, infotype barang, infotype size, infotype harga, infotype stok, Link root);


#endif
