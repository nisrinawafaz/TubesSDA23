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
	
	while (Next(head) != NULL){
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
			PrintTree(parent);
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

void CekHarga ()
{
	infotype binary, nama, size, harga, stok;
	infotype kodeChar;
				
	binary = (infotype) malloc (50*sizeof(char));
	nama = (infotype) malloc (50*sizeof(char));
	size = (infotype) malloc (50*sizeof(char));
	harga = (infotype) malloc (50*sizeof(char));
	stok = (infotype) malloc (50*sizeof(char));
	kodeChar = (infotype) malloc (50*sizeof(char));
	
	teksUserPelanggan();
	
	tampilanFile("TAMPILAN(2).txt");
	sound("Suara/MasukkanKodeBarangFix.wav");
	
	do
	{
		binary = InputCodeBinary("\n\n\t\t\t\t\t\t\t--> Masukkan kode yang tertera pada barang: ");
		FSearchKodeChar("KodeBarang.txt", binary, &kodeChar);
		if(kodeChar != Nil)
		{
			FSearchBarang2("NamaBarang.txt", kodeChar, &nama, &size, &harga, &stok);
			printf ("\n\t\t\t\t\t\t\t\t\t\t  --> Nama barang: %s", nama);
			printf ("\n\t\t\t\t\t\t\t\t\t\t  --> Ukuran barang: %s", size);
	    	printf ("\n\t\t\t\t\t\t\t\t\t\t  --> Harga: %s", harga);
	    	printf ("\n\t\t\t\t\t\t\t\t\t\t  --> Jumlah stok: %s", stok);	
		} else{
			printf ("\n\t\t\t\t\t\t\t --> Kode barang yang anda inputkan salah <--");
		}
	}while(kodeChar == Nil);
	
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
	       printf("\n\t\t\t\t\t\t\t\t\t\t  --> File tidak ditemukan");
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
	       printf("\n\t\t\t\t\t\t\t\t\t  --> File tidak ditemukan");
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
       printf("\n\t\t\t\t\t\t\t\t\t  --> File tidak ditemukan");
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

void Replace(infotype kodebrg, infotype hargabaru, infotype stokbaru)
{
	FILE *in;
	bool ketemu = false;
	infotype nama, harga, stok, kode, size;
	address2 front = Nil, rear = Nil, temp = Nil;
	
	in = fopen("NamaBarang.txt","r");
    if(!in){  
       printf("\n\t\t\t\t\t\t\t\t\t  --> File tidak ditemukan");
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
    
    temp = SearchNodeBrg(front, kodebrg);
    
    if (temp == NULL){
    	printf ("\n\t\t\t\t\t\t\t\t\t  --> Barang yang anda inputkan tidak ada");
	} else {
		Harga(temp) = hargabaru;
		Stok(temp) = stokbaru;
	}
	
	in = fopen("NamaBarang.txt", "w");
	if(!in){  
       printf("\n\t\t\t\t\t\t\t\t\t  --> File tidak ditemukan");
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
		if (strcmp(Kode(P), X) == 0)
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
	       printf("\n\t\t\t\t\t\t\t\t\t  --> File tidak ditemukan");
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
        printf("\n\t\t\t\t\t\t\t\t\t  --> File tidak ditemukan, input tidak berhasil");
    }else{
	    fprintf (in,"%s\t%s\n", KodeBarang, BinaryKodeBarang);
	    fclose(in);
    }
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void preOrder(Link root, int baris, int kolom, int bantu)
{
	if (root != NULL){
		
		gotoxy(kolom, baris);
		
		printf ("|%c|%d|", Info(root), Freq(root));
		
        preOrder(LeftSon(root), baris+3, kolom-bantu, bantu/2);
        preOrder(RightSon(root), baris+3, kolom+bantu, bantu/2);
	}
}

void PrintTree (Link root){
	int i = 1;
	int j = 3;
	int bantu = 1;
	
	while (i < maxDepth(root)){
		bantu = bantu + j;
		j = j*2;
		i = i+1;
	}
	
	preOrder(root, 4, bantu, (bantu/2)+1);
	
	gotoxy(0, (i+1)*3+2);
}

int maxDepth(Link node) {
    if (node == NULL) {
        return 0;
    } else {
        int leftDepth = maxDepth(LeftSon(node));
        int rightDepth = maxDepth(RightSon(node));

        if (leftDepth > rightDepth) {
            return (leftDepth + 1);
        } else {
            return (rightDepth + 1);
        }
    }
}

void SearchIsiTree(Link nodetree, infotype *IsiTree)
{
	if(nodetree != Nil)
	{
		if(LeftSon(nodetree) == NULL && RightSon(nodetree) == NULL)
		{
			infotype temp;
			temp = (infotype) malloc (2*sizeof(char));
			
			temp[0] = Info(nodetree);
			temp[1] = '\0';
			
			strcat(*IsiTree, temp);
		}
		
		SearchIsiTree(LeftSon(nodetree), &(*IsiTree));
		SearchIsiTree(RightSon(nodetree), &(*IsiTree));
	}
}

void TampilTabel (Link root)
{
	FILE *pf;
	infotype temp = (infotype) malloc (20*sizeof(char));
	int i = 0;
	int j = 0;
	int cek = 0;
	int k = 0;


	printf ("\n\n4. Proses encode dan decode\n");
	printf ("Berikut adalah tabel yang berisi huruf serta kode huffmannya yang dapat digunakan untuk proses encode dan decode: \n");
	printf ("\t\t\t\t\t     ==================================================\n");
	printf ("\t\t\t\t\t           HURUF\t==\t    KODE BINARY\t\t\n");
	printf ("\t\t\t\t\t     ==================================================\n");
	
	SearchIsiTree(root, &temp);
	
	i = 0;
	
	pf = fopen("KodeDecode.txt","w+");
	if (!pf){
		printf ("\n\t\t\t\t\t  --> File tidak ditemukan");
	} else {
		while (temp[i] != '\0'){
			infotype tempChar = (infotype) malloc (2*sizeof(char));
			infotype binary = (infotype) malloc (20*sizeof(char));
			
			tempChar[0] = temp[i];
			tempChar[1] = '\0';
			
			binary = Incode (root, tempChar);
			
			fprintf(pf,"%s\n", binary);	
			
			printf ("\t\t\t\t\t      \t     %c\t        ==\t     %s\t\t\n", temp[i], binary);
			printf ("\t\t\t\t\t     ==================================================\n");
			
			i++;		
		}
		fclose(pf);	
	}
	
	CekCode(root);
}
