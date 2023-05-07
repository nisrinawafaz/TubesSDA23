#include "header.h"
#include "Fauza.h"
#include "Nisrina.h"
#include "Agam.h"

Link CreateNodeTree(char huruf, int freq)
{
	Link P;
	
	P = (Link) malloc (sizeof(nodeTree));
	
	if (P != NULL){
		Info(P) = huruf;
		Freq(P) = freq;
		LeftSon(P) = NULL;
		RightSon(P) = NULL;
		Parent(P) = NULL;
	}
	
	return P;
}

address1 CreateLeafRef(Link leaf)
{
	address1 P;
	
	P = (address1) malloc (sizeof(leafref));
	
	if (P != NULL){		
		Info(P) = leaf;
		Prev(P) = NULL;
		Next(P) = NULL;
	}
	
	return P;
}

void InsLastLeaf (address1* head, address1* tail, address1 Q)
{
	address1 P;
	
	P = *tail;
	
	if (*head == NULL){
		*head = Q;
	} else{
		Prev(Q) = P;
		Next(P) = Q;
	}
	
	*tail = Q;
}

void InsFirstLeaf (address1* head, address1 Q)
{
	address1 P;
	
	P = *head;
	
	if (*head != NULL){
		Prev(P) = Q;
		Next(Q) = P;
	}
	
	*head = Q;
}

void InsBetweenLeaf (address1* Pcur, address1 Q)
{
	address1 P;
	
	P = *Pcur;
	
	Prev(Next(P)) = Q;
	Next(Q) = Next(P);
	
	Next(P) = Q;
	Prev(Q) = P;
	
	*Pcur = Q;
}

Link Pop (address1* tail)
{
	address1 Pcur, Pdel;
	Link temp;
	
	Pcur = *tail;
	temp = Info(Pcur);
	Pdel = *tail;
	
	if (Prev(Pcur) != NULL){
		Pcur = Prev(Pcur);
		Next(Pcur) = NULL;	
	} else{
		Pcur = NULL;
	}
	
	*tail = Pcur;
	
	free(Pdel);
	
	return temp;
}

address1 CreateListOfLeaf (address head)
{
	address1 front, rear, P;
	
	front = NULL;
	rear = NULL;
	
	while (head != NULL){
		P = CreateLeafRef(CreateNodeTree (Info(head), Freq(head)));
		
		InsLastLeaf (&front, &rear, P);
		
		head = Next(head);
	}
	
	return front;
}

Link CreateTree (address1 front)
{
	Link parent, right, left;
	address1 rear, P, pcur;
	int i;
	
	rear = NULL;
	rear = front;
	
	while (Next(rear) != NULL){
		rear = Next(rear);
	}
	
	while (1){
		right = Pop (&rear);
		left = Pop(&rear);

		parent = CreateNodeTree('*', Freq(right)+Freq(left));
		
		RightSon(parent) = right;
		LeftSon(parent) = left;
		Parent(right) = parent;
		Parent(left) = parent;
		
		if (rear == NULL){
			return parent;
		} else{
			pcur = rear;
			
			P = CreateLeafRef(parent);
		
			if(Freq(parent) > Freq(Info(pcur))){
				while (Freq(parent) > Freq(Info(pcur)) && Prev(pcur) != NULL){
					pcur = Prev(pcur);
				}
				if (Prev(pcur) == NULL) {
					InsFirstLeaf (&front, P);
				} else {
					InsBetweenLeaf (&pcur, P);
				}
			}else {
				InsLastLeaf (&front, &rear, P);
			}
		}	 
	}
}

void CekHarga (Link root)
{
	infotype kode, barang, size, harga, stok;
	
	barang = InputCodeBinary("\n--> Masukkan kode barang: ");
	
	if (SearchBarang("BarangBinary.txt", barang)){
    	FSearchBarang("BarangBinary.txt", &kode, barang, size, &harga, &stok);
    	barang = Decode(root, barang);
    	printf ("\nNama barang: %s", barang);
    	harga = Decode(root, harga);
    	printf ("\nHarga: %s", harga);
    	stok = Decode(root, stok);
    	printf ("\nJumlah stok: %s", stok);
	} else{
		printf ("\nKode barang yang anda inputkan salah");
	}
}

bool SearchBarang(infotype NmFile, infotype NmBarang)
{
	FILE *in;
	bool ketemu = false;
	infotype nama, harga, stok, kode, size;
	
	in = fopen(NmFile,"r");
    if(!in){  
       	in = fopen(NmFile,"a");
	    if(!in){  
	       printf("\nFile tidak ditemukan");
	    }else{
	       fclose(in);
	    }
    }else{
       while(!feof(in) && !ketemu){
			kode = (infotype) malloc (50*sizeof(char));
			nama = (infotype) malloc (50*sizeof(char));
			size = (infotype) malloc (50*sizeof(char));
			harga = (infotype) malloc (50*sizeof(char));
			stok = (infotype) malloc (50*sizeof(char));
			
        	fscanf(in,"%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", kode, nama, size, harga, stok);
			fflush(stdin);
			
        	if (strcmp(NmBarang, nama) == 0){
	          	ketemu = true;
			}
       }
       fclose(in);
    }
    
	return ketemu;
}

bool SearchSize (infotype NmFile, infotype NmBarang, infotype Size)
{
	FILE *in;
	bool ketemu = false;
	infotype nama, harga, stok, kode, size;
	
	in = fopen(NmFile,"r");
    if(!in){  
       	in = fopen(NmFile,"a");
	    if(!in){  
	       printf("\nFile tidak ditemukan");
	    }else{
	       fclose(in);
	    }
    }else{
       while(!feof(in) && !ketemu){
			kode = (infotype) malloc (50*sizeof(char));
			nama = (infotype) malloc (50*sizeof(char));
			size = (infotype) malloc (50*sizeof(char));
			harga = (infotype) malloc (50*sizeof(char));
			stok = (infotype) malloc (50*sizeof(char));
			
        	fscanf(in,"%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", kode, nama, size, harga, stok);
			fflush(stdin);
			
        	if (strcmp(NmBarang, nama) == 0){
	          	if (strcmp(Size, size) == 0){
	          		ketemu = true;
				}
			}
       }
       fclose(in);
    }
    
	return ketemu;
}

void FSearchBarang(infotype NmFile, infotype *kode, infotype NmBarang, infotype size, infotype *Harga, infotype *Stok){
	FILE *in;
	infotype nama;
	
	in = fopen(NmFile,"r");
    if(!in){  
       printf("\nFile tidak ditemukan");
    }else{
       while(1){
			*kode = (infotype) malloc (50*sizeof(char));
			nama = (infotype) malloc (50*sizeof(char));
			size = (infotype) malloc (50*sizeof(char));
			*Harga = (infotype) malloc (50*sizeof(char));
			*Stok = (infotype) malloc (50*sizeof(char));
			
        	fscanf(in,"%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", *kode, nama, size, *Harga, *Stok);
			fflush(stdin);
			
        	if (strcmp(NmBarang, nama) == 0){
				break;
			}
       }
       fclose(in);
    }
}

void FSearchKode(infotype NmFile, infotype *kode, infotype NmBarang)
{
	FILE *in;
	infotype nama;
	infotype size, Harga, Stok;
	
	in = fopen(NmFile,"r");
    if(!in){  
       printf("\nFile tidak ditemukan");
    }else{
       while(1){
			*kode = (infotype) malloc (50*sizeof(char));
			nama = (infotype) malloc (50*sizeof(char));
			size = (infotype) malloc (50*sizeof(char));
			Harga = (infotype) malloc (50*sizeof(char));
			Stok = (infotype) malloc (50*sizeof(char));
			
        	fscanf(in,"%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", *kode, nama, size, Harga, Stok);
			fflush(stdin);
			
        	if (strcmp(NmBarang, nama) == 0){
				break;
			}
       }
       fclose(in);
    }
}

void FSearchKodeBinary(infotype NmFile, infotype Kode, infotype *kodebinary)
{
	FILE *in;
	infotype kode;
	
	in = fopen(NmFile,"r");
    if(!in){  
       printf("\nFile tidak ditemukan");
    }else{
       while(!feof(in)){
        	fscanf(in,"%[^\t]\t%[^\n]\n", kode, *kodebinary);
			fflush(stdin);
			
        	if (strcmp(Kode, kode) == 0){
				break;
			}
       }
       fclose(in);
    }
}

void Replace(infotype namabrg, infotype hargabaru, infotype stokbaru)
{
	FILE *in;
	bool ketemu = false;
	infotype nama, harga, stok, kode, size;
	address2 front = Nil, rear = Nil, temp = Nil;
	
	in = fopen("NamaBarang.txt","r");
    if(!in){  
       printf("\nFile tidak ditemukan");
    }else{
       while(!feof(in) && !ketemu){
			kode = (infotype) malloc (50*sizeof(char));
			nama = (infotype) malloc (50*sizeof(char));
			size = (infotype) malloc (50*sizeof(char));
			harga = (infotype) malloc (50*sizeof(char));
			stok = (infotype) malloc (50*sizeof(char));
			
        	fscanf(in,"%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", kode, nama, size, harga, stok);
			fflush(stdin);
			
        	InsVLastBrg(&front, &rear, kode, nama, size, harga, stok);
       }
       fclose(in);
    }
    
    temp = SearchNodeBrg(front, namabrg);
    
    if (temp == NULL){
    	printf ("Barang yang anda inputkan tidak ada");
	} else {
		Harga(temp) = hargabaru;
		Stok(temp) = stokbaru;
	}
	
	in = fopen("NamaBarang.txt", "w");
	if(!in){  
       printf("\nFile tidak ditemukan");
    }else{
       while(front != Nil && !ketemu){
        	fprintf(in,"%s\t%s\t%s\t%s\t%s\n", Kode(front), NamaBrg(front), Size(front), Harga(front), Stok(front));
			DelFirstBrg (&front, &kode, &nama, &size, &harga, &stok);
       }
       fclose(in);
    }
    
    rear = Nil;
}

void InsertLastBrg (address2 *head, address2 *tail, address2 Q)
{
	address2 P;
	
	P = *tail;
	
	if (*head == NULL){
		*head = Q;
	} else{
		Next(P) = Q;
	}
	
	*tail = Q;
}

void InsVLastBrg(address2 *front, address2 *rear,infotype U, infotype V, infotype X, infotype Y, infotype Z)
{
	address2 P;
	
	P = CreateNodeBrg(U, V, X, Y, Z);
	
	if (P != Nil){	
		InsertLastBrg (front,rear, P);
	}
			
}

address2 CreateNodeBrg(infotype kode, infotype nmbrg, infotype size, infotype harga, infotype stok)
{
	address2 P;
	
	P = (address2) malloc (sizeof(filecontent));
	
	if (P != NULL){		
		Kode(P) = kode;
		NamaBrg(P) = nmbrg;
		Size(P) = size;
		Harga(P) = harga;
		Stok(P) = stok;
		Next(P) = NULL;
	}
	
	return P;
}

address2 SearchNodeBrg (address2 front, infotype X)
{
	address2 P;
	bool found =  false;
	
	P = front;
	while ((P != Nil) && (!found))
	{
		if (strcmp(NamaBrg(P), X) == 0)
		{ 
			found = true; 	
			return P;
		}
		else
		{	
			P = Next(P);
		}
	}
	
	return NULL;
}

void DelFirstBrg (address2 *front, infotype *kode, infotype *nmbrg, infotype *size, infotype *harga, infotype *stok)
{
	address2 temp;
	
	temp = *front;
	
	*kode = Kode(temp);
	*nmbrg = NamaBrg(temp);
	*size = Size(temp);
	*harga = Harga(temp);
	*stok = Stok(temp);
	
	*front = Next(temp);
	
	free (temp);
}

infotype BuatKodeBarang (infotype NamaBarang)
{
	infotype kode, binary, KodeBaru, NomorKode;
	int nomor = 1;
	FILE *in;
	
	in = fopen("KodeBarang.txt","r");
    if(!in){  
        in = fopen("KodeBarang.txt","a");
	    if(!in){  
	       printf("\nFile tidak ditemukan");
	    }else{
	       fclose(in);
	    }
    }else{
       while(!feof(in)){
			kode = (infotype) malloc (50*sizeof(char));
			binary = (infotype) malloc (50*sizeof(char));
			
        	fscanf(in,"%[^\t]\t%[^\n]\n", kode, binary);
			fflush(stdin);
			
			nomor = nomor + 1;
       }
       fclose(in);
    }
    
    KodeBaru = (infotype) malloc (7*sizeof(char));
    NomorKode = (infotype) malloc (4*sizeof(char));
    sprintf (NomorKode, "%d", nomor);
    
    if (nomor < 10){
    	KodeBaru[0] = '0';
    	KodeBaru[1] = '0';
    	KodeBaru[2] = '\0';
	} else if (nomor >= 10 && nomor < 100){
		KodeBaru[0] = '0';
		KodeBaru[1] = '\0';
	}
    
    strcat (KodeBaru, NomorKode);
    strncat (KodeBaru, NamaBarang, 2);
    
    return KodeBaru;
}

void InputFileKodeBarang (infotype KodeBarang, infotype BinaryKodeBarang)
{
	FILE *in;
	
	in = fopen("KodeBarang.txt","a");
    if(!in){  
        printf("\nFile tidak ditemukan, input tidak berhasil");
    }else{
	    fprintf (in,"%s\t%s\n", KodeBarang, BinaryKodeBarang);
	    fclose(in);
    }
}
