#ifndef header_H
#define header_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <windows.h>
#define Nil NULL
#define Barang(Q) (Q)->nama_barang
#define Harga(Q) (Q)->harga
#define Kuantitas(Q) (Q)->kuantitas
#define Total(Q) (Q)->total
#define Info(P) (P)->info
#define Freq(P) (P)->freq
#define Prev(P) (P)->prev
#define Next(P) (P)->next
#define LeftSon(P) (P)->leftson
#define RightSon(P) (P)->rightson
#define Parent(P) (P)->parent
#define NamaBrg(P) (P)->nmbrg
#define Stok(P) (P)->stok
#define Kode(P) (P)->kode
#define Size(P) (P)->size

typedef char *infotype;

typedef struct Keranjang *stroller;
typedef struct Keranjang{
	stroller prev;
	infotype kode;
	infotype nama_barang;
	infotype size;
	float harga;
	int kuantitas;
	float total;
	stroller next;
} keranjang;

typedef struct node *address;
struct node {
	char info;
	int freq;
	address prev;
	address next;
}Node;

typedef struct NodeTree *Link;
typedef struct NodeTree {
	char info;
	int freq;
	Link leftson, rightson, parent;
} nodeTree;

typedef struct LeafRef *address1;
typedef struct LeafRef {
	address1 prev, next;
	Link info;
} leafref;

typedef struct FileContent *address2;
typedef struct FileContent {
	infotype kode, nmbrg, harga, stok, size;
	address2 next;
} filecontent;

#endif
