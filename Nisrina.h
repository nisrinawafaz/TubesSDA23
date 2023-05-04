#ifndef Nisrina_H
#define Nisrina_H

#include "header.h" 

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


#endif
