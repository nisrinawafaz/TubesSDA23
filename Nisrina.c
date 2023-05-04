#include "header.h"
#include "Fauza.h"
#include "Nisrina.h"
#include "Agam.h"

//market modul
bool loginAdmin(infotype username, infotype password)
{
	infotype usernameAdm;
	usernameAdm = (infotype)malloc(10*sizeof(char));
	usernameAdm = "adminTubes";
	
	infotype passwordAdm;
	passwordAdm = (infotype)malloc(10*sizeof(char));
	passwordAdm = "tubesSDA23";
	
	
	if((strcmp(username, usernameAdm) == 0) && (strcmp(password, passwordAdm) == 0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void selamat_datang()
{
	puts	("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t     SELAMAT DATANG DI PENGGUNA APLIKASI MINI MARKET");
	puts	("\n\t\t\t\t\t\t\t\t\t\t\t     ^^BELANJA SENANG^^\n\n");
	puts	("\t\t\t\t\t\t\t\t\t\t       ::::::::::::::::::::::::::::::::::::");
	puts	("\t\t\t\t\t\t\t\t\t\t       :::::::@@@@@@::::::::::@@@@@@:::::::");	
	puts	("\t\t\t\t\t\t\t\t\t\t       ::::@@@@::::@@@@::::@@@@::::@@@@::::");
	puts	("\t\t\t\t\t\t\t\t\t\t       :::@@@:::::::::@@::@@:::::::::@@@:::");
	puts	("\t\t\t\t\t\t\t\t\t\t       ::@@@::::::::::::@@::::::::::::@@@::");
	puts	("\t\t\t\t\t\t\t\t\t\t       ::::@@@::::::::::::::::::::::@@@::::");
	puts	("\t\t\t\t\t\t\t\t\t\t       ::::::@@@::::::::::::::::::@@@::::::");
	puts	("\t\t\t\t\t\t\t\t\t\t       ::::::::@@@::::::::::::::@@@::::::::");
	puts	("\t\t\t\t\t\t\t\t\t\t       ::::::::::@@@::::::::::@@@::::::::::");
	puts	("\t\t\t\t\t\t\t\t\t\t       ::::::::::::@@@::::::@@@::::::::::::");
	puts	("\t\t\t\t\t\t\t\t\t\t       ::::::::::::::@@@::@@@::::::::::::::");
	puts	("\t\t\t\t\t\t\t\t\t\t       :::::::::::::::::@@:::::::::::::::::");
	puts	("\t\t\t\t\t\t\t\t\t\t       ::::::::::::::::::::::::::::::::::::");
	getche();
}

void loading(char x[100])
{										// ====>  Fitur tampilan loading  <==== //
	int i;
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("\t\t\t\t\t\t\t\t\t\t\t%s\n\n\t\t\t\t\t\t\t\t       ",x);
	for (i=0; i<=65;i++){
		printf("w",178);
		Sleep(18);
	}
	system("cls");
}


void selection(int *choice, infotype fChoice, infotype sChoice, infotype pertanyaan, infotype kesimpulan)
{
	system("cls");
	printf("%s \n", pertanyaan);
	printf("%s \n", fChoice);
	printf("%s \n", sChoice);
	printf("%s \n", kesimpulan);
	scanf("%d", choice);
}

void inputLogin(infotype *username, infotype *password)
{
	system("cls");
	printf("\n masukkan Username : ");
	scanf("%s", *username);
	printf("\n masukkan password : ");
	scanf("%s", *password);
}

void adminFitur(Link root)
{
	bool valid;
	int fitur;
	double potongan = 0.07;
	double ppn = 0.10;
	int minimal = 100000;
	int total ;
	double diskon;
	double pajak;
	double total_akhir;
	double uang_kembalian;
	uang_kembalian = 0;
	infotype username;
	username = (infotype)malloc(20*sizeof(char));
	
	infotype password;
	password = (infotype)malloc(20*sizeof(char));
	
		
	stroller front;
	front = Nil;
	
	stroller rear;
	rear = Nil;
	
	do
	{
		inputLogin(&username, &password);
		valid = loginAdmin(username,password);
		if(valid)
		{
			printf("login berhasil");
			
			do
			{
				selection(&fitur, "Input Barang Baru", "Kasir", "Fitur admin : ", "saya akan menggunakan fitur : ");
				if(fitur == 1)
				{
					InputBarang(root);
				}
				else if(fitur == 2)
				{
					pemesanan(&front, &rear, root);
					input_struk(front);
					system("cls");
					PrintInfokeranjang (front);
					total = total_harga(front);
					diskon = hitung_diskon(total, potongan);
					pajak = hitung_ppn(total, ppn);
					total_akhir = hitung_hasil(total, potongan,  minimal,  pajak);
					output_bayar(total, minimal, pajak, potongan, total_akhir);	
					uang_kembalian = UangKembalian(total_akhir);
					printf("\n di .c%g", uang_kembalian);
					tampilanKembalian(uang_kembalian);
				}
				else
				{
					printf("fitur yang anda pilih tidak tersedia\n");
					printf("pilih fitur yang sudah tersedia [klik enter]");
					getche();
				}
			}while(fitur !=1 && fitur !=2);
		}
		else
		{
			printf("login gagal");
			printf("masukkan username dan password yang valid [klik enter]");
			getche();
		}	
	}while(!valid);
	
}

void pemesanan(stroller *front, stroller *rear, Link root)
{
	char nStep;
	char pilih;
	bool search;
	infotype KodeCharBarang;
	infotype KodeCharHarga;
	infotype KodeCharStok;
	int harga;
	int kuantitas;
	int total;
	int stok;
	infotype KodeBinaryBarang;
	infotype KodeBinaryHarga; 
	infotype KodeBinaryStok;

	stroller alamatBarang;
	stroller deleteKeranjang;
	
	do
	{
		do
		{
			KodeCharBarang = (infotype) malloc (30*sizeof(char));
			KodeBinaryHarga = (infotype) malloc (30*sizeof(char));
			KodeCharHarga = (infotype) malloc (30*sizeof(char));
			KodeBinaryStok = (infotype) malloc (30*sizeof(char));
			KodeCharStok = (infotype) malloc (30*sizeof(char));
			
			KodeBinaryBarang = InputCodeBinary("\n masukkan kode yang tertera pada barang : ");
			do
			{
				printf("\n masukkan kuantitas barang : ");
				scanf("%d", &kuantitas);	
			}while(kuantitas == 0);
			search = SearchBarang("BarangBinary.txt", KodeBinaryBarang);
			if(search)
			{
				FSearchBarang("BarangBinary.txt", KodeBinaryBarang, &KodeBinaryHarga, &KodeBinaryStok);
				KodeCharBarang = Decode(root, KodeBinaryBarang);
				KodeCharHarga = Decode(root, KodeBinaryHarga);
				KodeCharStok = Decode(root, KodeBinaryStok);
				stok = atoi(KodeCharStok);
				stok = stok - kuantitas;
				sprintf(KodeCharStok, "%d", stok);
				KodeBinaryStok = (infotype) malloc (30*sizeof(char));
				KodeBinaryStok = Incode(root, KodeCharStok);
				harga  = atoi(KodeCharHarga);
				total = harga * kuantitas;
				alamatBarang = SearchKeranjang (*front, KodeCharBarang);
				if(alamatBarang != Nil)
				{
					kuantitas = kuantitas + Kuantitas(alamatBarang);
					Kuantitas(alamatBarang) = kuantitas;
					Total(alamatBarang) = harga * kuantitas;
				}
				else
				{
					InsVLastKeranjang(&(*front), &(*rear), KodeCharBarang, harga, kuantitas, total);
				}
				Replace(root, KodeBinaryBarang, KodeBinaryHarga, KodeBinaryStok);
				PrintInfokeranjang (*front);
				printf("ketikkan huruf 'H' untuk menghapus barang :  \n");
				nStep = getche();
				if(nStep == 'H' || nStep == 'h')
				{
					KodeCharBarang = (infotype) malloc (30*sizeof(char));
					KodeBinaryBarang = (infotype) malloc (30*sizeof(char));
					KodeBinaryBarang = InputCodeBinary("\n--> Masukkan kode barang: ");
					KodeCharBarang = Decode(root, KodeBinaryBarang);
					deleteKeranjang = SearchKeranjang (*front, KodeCharBarang);
					do{
						printf("\n masukkan kuantitas barang : ");
					scanf("%d", &kuantitas);
					}while(kuantitas > Kuantitas(deleteKeranjang) || kuantitas <0);
					FSearchBarang("BarangBinary.txt", KodeBinaryBarang, &KodeBinaryHarga, &KodeBinaryStok);
					KodeCharStok = Decode(root, KodeBinaryStok);
					stok = atoi(KodeCharStok);
					stok = stok + kuantitas;
					Kuantitas(deleteKeranjang) = Kuantitas(deleteKeranjang) - kuantitas;
					sprintf(KodeCharStok, "%d", stok);
					KodeBinaryStok = (infotype) malloc (30*sizeof(char));
					KodeBinaryStok = Incode(root, KodeCharStok);
					Replace(root, KodeBinaryBarang, KodeBinaryHarga, KodeBinaryStok);
					DelKeranjang (front, KodeCharBarang);
				}
				printf("Ketikkan huruf 'T' untuk menambah barang : \n");
				nStep = getche();
			}
			else
			{
				printf("\n Kode yang anda masukkan tidak valid : ");
				printf("\n masukkan kode barang yang valid [klik enter] : ");
				getche();
				break;
			}
		}while(nStep == 'T' || nStep == 't');
	}while(!search);
	
}

void input_struk(stroller data)
{
	stroller P;
	int i;
	i = 1;
	FILE *kj;
	kj=fopen("struk_belanja.txt", "a+");
	if (data != Nil)
	{
		header_struk();
		 P = data;
		 for (;;)
		 {
			if (P == Nil)
			{
				 printf("\n");
				 break;
			}
			else	/* Belum berada di akhir List */
			{
				 fprintf(kj, "  %d.\t   %s\t\t      %d\t    %d\t     %d\t      \n", i+1, Barang(P), Harga(P), Kuantitas(P), Total(P));
			fprintf(kj,"|-------------------------------------------------------------|\n");
				 P = Next(P);
				 i++;
			}
		 }
	}
	fclose(kj);
}

stroller AlokasiKeranjang(infotype barang, int harga, int kuantitas, int total)
{
	 /* Kamus Lokal */
	 stroller P;
	 
	 /* Algoritma */
	 P = (stroller) malloc (sizeof (keranjang));
	 if (P != Nil)		/* Alokasi berhasil */
	 {
		Prev(P) = Nil;
		Barang(P) = barang;
		Harga(P) = harga;
		Kuantitas(P) = kuantitas;
		Total(P) = total;
		Next(P) = Nil;
	 }
	 return (P);
}

stroller SearchKeranjang (stroller front, infotype barang)
{
	 /* Kamus Lokal */
	 stroller P;
	 bool found =  false;
	 int match;
	 P = front;
	 	while ((P != Nil) && (!found))
		{
			match = strcmp(Barang(P), barang);
			 if (match == 0)
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

void InsertLastKeranjang (stroller *front, stroller *rear, stroller P)
{
	
	if(*front == Nil)
	{
		*front= P;
		*rear = P;
	}
	else
	{
		Next(*rear) = P;
		Prev(P) = *rear;
		*rear = P;
	}
}

void InsVLastKeranjang(stroller *front, stroller *rear, infotype barang, int harga, int kuantitas, int total)
{
	stroller P;
	P = AlokasiKeranjang(barang, harga, kuantitas, total);
	if (P != Nil)
	{	
	InsertLastKeranjang (front,rear, P);
			}
			
}

void PrintInfokeranjang (stroller data)
{
	 /* Kamus Lokal */
	stroller P;
	int i;
	i = 1;
	
	 /* Algoritma */
	system("cls");
	puts	("\n\t\t\t\t\t\t\t\t\t|=============================================================|");
	puts	("\t\t\t\t\t\t\t\t\t|                       DELIVERY MARKET                       |");
	puts	("\t\t\t\t\t\t\t\t\t|                   Telepon : 087734469228                    |");
	puts	("\t\t\t\t\t\t\t\t\t|                Jl. Gegerkalong Hilir, Ciwaruga              |");
	puts	("\t\t\t\t\t\t\t\t\t|                        Bandung Barat                        |");
	puts	("\t\t\t\t\t\t\t\t\t|=============================================================|");
	puts	("\t\t\t\t\t\t\t\t\t| NO |      BARANG        |   HARGA   | KUANTITAS |   TOTAL   |");
	puts	("\t\t\t\t\t\t\t\t\t|-------------------------------------------------------------|");
	if (data == Nil)
	{
		 printf ("List Kosong .... \a\n");
	}
	else	/* List memiliki elemen */
	{
		 P = data;
		 for (;;)
		 {
			if (P == Nil)
			{
				 printf("\n");
				 break;
			}
			else	/* Belum berada di akhir List */
			{
				 printf (" \t\t\t\t\t\t\t\t\t  %d.\t   %s\t      %d\t    %d\t     %d\t      \n ", i, Barang(P), Harga(P), Kuantitas(P), Total(P));
				 puts	("\t\t\t\t\t\t\t\t\t|-------------------------------------------------------------|");	
				 P = Next(P);
				 i++;
			}
		 }
	}
}

void DelKeranjang (stroller *front, infotype nama)
/* IS : L sembarang */
/* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
/* 	Maka P dihapus dari list dan di dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	 /* Kamus Lokal */
	stroller P, Prec;
	bool found=false;
	int compare;
	 /* Algoritma */
		Prec = Nil;
	P = *front;
	while ((P != Nil) && (!found))
	{
		compare = strcmp(Barang(P), nama);
		 if (compare == 0)
		 {	found = true;	}
		 else
		 {
		Prec = P;
		P = Next(P);
		 }
	} /* P = Nil Atau Ketemu */

	if (found)
	{
		 if (Prec == Nil && Next(P) == Nil)		/* Hanya 1 elemen */
		 {	*front = Nil;	}
		 else if (Prec == Nil)			/* Ketemu di elemen 1*/
		 {	*front = Next(P);	}
		 else		/* Ketemu di elemen list yang ditengah/akhir */
		 {	Next(Prec) = Next(P);	}
		 Next(P) = Nil;
		 DeAlokasi (P);
	}
}

void DeAlokasi (stroller P)
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
{
	 if (P != Nil)
	 {
	free (P);
	 }
}

void header_struk()
{
	FILE *kj;
	kj=fopen("struk_belanja.txt", "w+");
	fprintf(kj,"|=============================================================|\n");
	fprintf(kj,"|                       DELIVERY MARKET                       |\n");
	fprintf(kj,"|                   Telepon : 087734469228                    |\n");
	fprintf(kj,"|                Jl. Gegerkalong Hilir, Ciwaruga              |\n");
	fprintf(kj,"|                        Bandung Barat                        |\n");
	fprintf(kj,"|=============================================================|\n");
    fprintf(kj,"| NO |      BARANG        |   HARGA   | KUANTITAS |   TOTAL   |\n");
    fprintf(kj,"|-------------------------------------------------------------|\n");
    fclose(kj);
}

double hitung_diskon(int total, double potongan)
{
	double hitung;
	hitung = total*potongan;
	
	return hitung;
}

double hitung_hasil(int total, double potongan, int minimal, double ppn)
{
	double totalAkhir;
	if(total>= minimal )
	{
		totalAkhir = (total - potongan)  + ppn;
	}
	else
	{
		totalAkhir = total  + ppn;
	}
	
	return totalAkhir;
}

void output_bayar(int total, int minimal, double ppn, double diskon, double hasil)
{
	printf	("\t\t\t\t\t\t\t\t\t   PPN 10 persen :                          Rp. %g\n", ppn);
	if(total >= minimal)
	{
		puts	("\t\t\t\t\t\t\t\t\t|---------------Selamat anda mendapatkan diskon!--------------|");
		printf	("\t\t\t\t\t\t\t\t\t  Jumlah pembelanjaan anda lebih dari %d\n",minimal);
		printf	("\t\t\t\t\t\t\t\t\t  Jumlah pembayaran : Rp. %g ( Diskon sebesar Rp.%g) \n",hasil, diskon);
		puts	("\t\t\t\t\t\t\t\t\t|-------------------------------------------------------------|");
		
	}
	else
	{
		printf	("\t\t\t\t\t\t\t\t\t  Jumlah pembayaran :                       Rp. %g \n",hasil);
		puts	("\t\t\t\t\t\t\t\t\t|-------------------------------------------------------------|");
	}
}

int total_harga(stroller front)
{
	stroller P;
	int total;
	total =0;
	if (front!= Nil)
	{
		 P = front;
		 for (;;)
		 {
			if (P == Nil)
			{
				 break;
			}
			else	/* Belum berada di akhir List */
			{
				 total = total + Total(P);
				 P = Next(P);
			}
		 }
	}
	
	return total;
}

double hitung_ppn(int total, double ppn)
{
	double hitung;
	hitung = total*ppn;
	
	return hitung;
}

//huffman tree modul
address AlokasiChar(char X)
{
	 /* Kamus Lokal */
	 address P;
	 
	 /* Algoritma */
	 P = (address) malloc (sizeof (Node));
	 if (P != Nil)		/* Alokasi berhasil */
	 {
		Prev(P) = Nil;
		Info(P) = X;
		Freq(P) = 1;
		Next(P) = Nil;
	 }
	 return (P);
}

address Search (address front, char X)
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
/* Menggunakan variabel bertype boolean */
{
	 /* Kamus Lokal */
	 address P;
	 bool found =  false;
	 /* algoritma */
	 P = front;
	 	while ((P != Nil) && (!found))
		{
			 if (Info(P) == X)
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

void InsertLastChar (address *front, address *rear, address P)
{
	
	if(*front == Nil)
	{
		*front= P;
		*rear = P;
	}
	else
	{
		Next(*rear) = P;
		Prev(P) = *rear;
		*rear = P;
	}
}

void InsVLastChar(address *front, address *rear, char X)
{
	address P;
	P = AlokasiChar(X);
	if (P != Nil)
	{	
	InsertLastChar (front,rear, P);
			}
			
}





address createFrekuensi()
{
	FILE *in, *out;
    char ch;
    address front, rear;
    address tempAdd;
    address temp;
    
    front = NULL;
    rear = NULL;
 
    in = fopen("panjang.txt", "r");
    if (in == NULL)
    {
        printf("Cannot open source file.\n");
        exit(1);
    }
    out = fopen("output.txt", "w");
    if (out == NULL)
    {
        printf("Cannot open destination file.\n");
        exit(1);
    }
    
    
 
    do {
        ch = getc(in);
        tempAdd = Search (front, ch);
        if(tempAdd == NULL)
        {
        	
        	InsVLastChar(&front, &rear, ch);
		}
		else
		{
			Freq(tempAdd)++;
		}
    }
    while (!feof(in));
 
    // print histogram data in the output file
    fputs("character    frequency    ", out);
    
    temp = front;
    
    while(temp != NULL)
    {
    	fprintf(out, "\n%c\t\t\t\t%2d\t\t\t\t", Info(temp), Freq(temp));
		temp = Next(temp);
	}
    

    fclose(out);
    fclose(in);
    
    return front;
}

void sortingFreq(address *front)
{
	address Pcur;
	address temp, max;
	int tempFreq;
	char tempChar;
	
	Pcur = Nil;
	temp = Nil;
	max = Nil;
	
	if(*front!=NULL)
    {
        Pcur=*front;
        while(Next(Pcur)!=NULL)
        {
            temp=Pcur;
            max=Pcur;
            while(temp!=NULL)
            {
                if(Freq(temp) > Freq(max))
                {
                    max=temp;
                }
                temp = Next(temp);
            }
            if(Freq(Pcur) < Freq(max))
            {
            	tempChar = Info(Pcur);
                tempFreq= Freq(Pcur);
                Info(Pcur) = Info(max);
                Freq(Pcur) = Freq(max);
                Info(max)=tempChar;
                Freq(max)=tempFreq;
            }
            Pcur=Next(Pcur);
        }
    }
	
}

void PrintInfoChar (address data)
{
	 /* Kamus Lokal */
	address P;
	int i;
	
	 /* Algoritma */
	if (data == Nil)
	{
		 printf ("List Kosong .... \a\n");
	}
	else	/* List memiliki elemen */
	{
		 P = data;
		 for (;;)
		 {
			if (P == Nil)
			{
				 printf("\n");
				 break;
			}
			else	/* Belum berada di akhir List */
			{
				 printf (" %c : %d \n ", Info(P), Freq(P));
				 P = Next(P);
			}
		 }
	}
}

infotype InputCodeChar(infotype deskripsi)
{
	infotype KodeChar;
	
	KodeChar = (infotype)malloc(50*sizeof(char));
	
	printf("%s", deskripsi);
	scanf("%s", KodeChar);
	
	return KodeChar;
}


void SearchTree(Link temp, char x, Link *temp2)
{
	if(temp != Nil)
	{
		if(Info(temp) == x)
			{
				*temp2 = temp;
			}
		SearchTree(RightSon(temp), x, &(*temp2));
		SearchTree(LeftSon(temp), x, &(*temp2));
	}
	
}

infotype Incode(Link root, infotype KodeChar)
{
	char huruf;
	Link alamat, Pcur;
	infotype KodeBinary;
	
	
	infotype tempBinary;
	tempBinary = (infotype)malloc(30*sizeof(char));
	tempBinary[0] = '\0';
	
	infotype temp;
	temp = (infotype)malloc(2*sizeof(char));
	temp[0] = '\0';
	
	
	alamat = Nil;
	Pcur = Nil;
	
	int i,length,j;
	i=0;
	do{
		KodeBinary = (infotype)malloc(30*sizeof(char));
		KodeBinary[0] = '\0';
		huruf = KodeChar[i];
		SearchTree(root, huruf, &alamat);
		while(alamat != root)
		{
			if(alamat == LeftSon(Parent(alamat)))
			{
				strcat(KodeBinary,"0");
				alamat = Parent(alamat);
			}
			else if(alamat == RightSon(Parent(alamat)))
			{
				strcat(KodeBinary,"1");
				alamat = Parent(alamat);
			}
		}
		length = strlen(KodeBinary);
		for(j=length;j>=0;j--)
		{
			temp[0]= KodeBinary[j];
			temp[1]= '\0';
			strcat(tempBinary,temp);
		}
		i++;
		
	}while(huruf != '\0');
	
	return tempBinary;
}



