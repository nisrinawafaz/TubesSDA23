#include "header.h"
#include "Nisrina.h"
#include "Fauza.h"
#include "Agam.h"

infotype InputCodeBinary(infotype deskripsi)
{
	infotype str;
	
	str = (infotype) malloc (30 * sizeof(char));
	
	printf("%s", deskripsi);
	scanf("%s", str);
	
	return str;
}

infotype Decode(Link root, infotype str){
	int i = 0;
	Link pCur;
	
	infotype kalimat;
	kalimat = (infotype) malloc (30 * sizeof(char));
	kalimat[0] ='\0';
	
	infotype temp;
	temp = (infotype) malloc (2 * sizeof(char));
	temp[0] ='\0';
	
	pCur = root;
	
	while(str[i] != '\0'){
		while(RightSon(pCur) != Nil && LeftSon(pCur) != Nil){
			if(str[i] == '1'){
				pCur = RightSon(pCur);
			}else if(str[i] == '0'){
				pCur = LeftSon(pCur);
			}
			i++;
		} 
		temp[0] = Info(pCur);
		temp[1] = '\0';
		strcat(kalimat,temp);
		pCur = root;	
	}

	return kalimat;
}

infotype sensitiveCase(infotype kata){
	int i;
	
	for (i = 0; kata[i]!='\0'; i++) {
		if(kata[i] >= 'a' && kata[i] <= 'z'){ //'a' itu 75, 'z' itu 122. Pake ascii
  			kata[i] = kata[i] - 32;
		} 
	}
	
	return kata;
}

void InputBarang(Link *root){
	FILE *pf;
	FILE *in;
	infotype kode, barang, size, harga, stok, kodebinary, barangbinary, sizebinary, hargabinary, stokbinary, penampung;
	char pilihan, pilihan1, lagi = 'y';
	int stokbarang, stokbarang1;
	int cek = 0;
	
	
	while (lagi == 'y' || lagi =='Y'){
		kode = (infotype) malloc (50*sizeof(char));
		barang = (infotype) malloc (50*sizeof(char));
		size = (infotype) malloc (50*sizeof(char));
		harga = (infotype) malloc (50*sizeof(char));
		stok = (infotype) malloc (50*sizeof(char));
		kodebinary = (infotype) malloc (50*sizeof(char));
		barangbinary = (infotype) malloc (50*sizeof(char));
		sizebinary = (infotype) malloc (50*sizeof(char));
		hargabinary = (infotype) malloc (50*sizeof(char));
		stokbinary = (infotype) malloc (50*sizeof(char));
	
		barang = InputCodeChar("\n\t\t\t\t\t\t\t\t  --> Masukkan Nama Barang: ");
		barang = sensitiveCase(barang);
		size = InputCodeChar("\n\t\t\t\t\t\t\t\t  --> Masukkan Ukuran Barang: ");
		size = sensitiveCase(size);
		if(SearchBarang("NamaBarang.txt", barang) && SearchSize("NamaBarang.txt", barang, size)){
			FSearchBarang("NamaBarang.txt", &kode, barang, size, &harga, &stok);
			
			printf("\nBerikut adalah Harga, Size, dan Stok Barang %s:\n", barang);
			printf("Size: %s, Harga: %s, Stok: %s\n", size, harga, stok);
			
			printf("Apakah anda ingin mengubah Harga? (Y/N)");
			fflush(stdin);
			scanf("%c", &pilihan);
			
			if(pilihan == 'Y' || pilihan == 'y'){
				harga = InputCodeChar("Masukkan Harga Barang Terbaru:");
				pf = fopen("panjang.txt","a");
				if (!pf){
					printf("\nFile tidak ditemukan");
				} else{
					fprintf(pf,"%s", harga);
					fclose(pf);
				}
			}
			
			printf("Apakah anda ingin menambah Stok? (Y/N)");
			fflush(stdin);
			scanf("%c", &pilihan1);
			
			if(pilihan1 == 'Y' || pilihan1 == 'y'){
				stokbarang = atoi(stok);
				stok = InputCodeChar("Masukkan Stok Barang yang ingin ditambahkan:");
				
				pf = fopen("panjang.txt","a");
				if (!pf){
					printf("\nFile tidak ditemukan");
				} else{
					fprintf(pf,"%s", stok);
					fclose(pf);
				}
				
				stokbarang1 = atoi(stok);
				sprintf(stok, "%d", (stokbarang+stokbarang1));
				
			}
			Replace(kode, harga, stok);
		} else{
			harga = InputCodeChar("\n\t\t\t\t\t\t\t\t  --> Masukkan Harga Barang: ");
			stok = InputCodeChar("\n\t\t\t\t\t\t\t\t  --> Masukkan Stok Barang: ");
			
			kode = BuatKodeBarang (barang);
			
			pf = fopen("NamaBarang.txt","a");
			if (!pf){
				printf("\nFile tidak ditemukan");
			} else{
				fprintf(pf,"%s\t%s\t%s\t%s\t%s\n", kode, barang, size, harga, stok);
				fclose(pf);
			}
			
			pf = fopen("panjang.txt","a");
			if (!pf){
				printf("\nFile tidak ditemukan");
			} else{
				fprintf(pf,"%s%s%s%s%s", kode, barang, size, harga, stok);
				fclose(pf);
			}
			
			*root = CreateHuffmanTree();
			incodeBarang(&kodebinary, &barangbinary, &sizebinary, &hargabinary, &stokbinary,kode ,barang, size, harga, stok, *root);
			InputFileKodeBarang (kode, kodebinary);
			
			printf ("\ncoba");
			getche();
			pf = fopen("BarangBinary.txt","a");
			if (!pf){
				printf("\nFile tidak ditemukan");
			} else{
				fprintf(pf,"%s\t%s\t%s\t%s\n", kodebinary, barangbinary, sizebinary, hargabinary, stokbinary);
				fclose(pf);
			}
		}
		printf ("\n\nApakah anda ingin menginputkan barang lagi? (y/t)");
		lagi = getche ();	
	}
	printf ("\n\nApakah anda ingin menggunakan fitur lainnya? (y/t)");
	lagi = getche ();
	if(lagi == 'y' || lagi== 'Y')
	{
		adminFitur(root);
	}
	else
	{
			system("cls");
		system("color 0F");
		tampilanFile("TAMPILAN(6).txt");
	}
	
}

float UangKembalian(float totalHarga, float *JumlahUang){
	float UangKembali;
	
	do{
		printf("\nMasukkan Jumlah Uang: ");
		scanf("%f", JumlahUang);
		
		if(totalHarga > *JumlahUang){
			printf("\nMaaf Uang Anda kurang");
		}	
	}while(totalHarga > *JumlahUang);

	UangKembali = *JumlahUang - totalHarga;
	
	return UangKembali;
}

void tampilanKembalian(float Uangkembalian){
	printf("\t\t\t\t\t\t\t\t\t  Kembalian :                       Rp. %g \n",Uangkembalian);
	system("cls");
	puts	("\n\t\t\t\t\t\t\t\t\t|=============================================================|");
	puts	("\t\t\t\t\t\t\t\t\t|             TERIMA KASIH, SUDAH BERBELANJA                  |");
	puts	("\t\t\t\t\t\t\t\t\t|              SELAMAT BERBELANJA KEMBALI :)                  |");
	puts	("\n\t\t\t\t\t\t\t\t\t|=============================================================|");
}

void loadingBar(int waktu){
	int i;
    char a = 177, b = 219;

    printf("\n\n\n\t\t\t\t\t\t\t\t\t         Loading...\n\n");
    printf("\t\t\t\t\t\t\t\t\t");
  
    for (i = 0; i < 26; i++){
        printf("%c", a);
  	}
    printf("\r");
    printf("\t\t\t\t\t\t\t\t\t");
  
    for (i = 0; i < 26; i++) {
        printf("%c", b);
        Sleep(waktu);
    }
}


void tampilanFile(char* namaFile){
	FILE *f_teks;
	char string[256];
	
	if ((f_teks=fopen(namaFile, "rt")) == NULL)
	{
		printf("\n\n\t\t\t\t\t\t\t   ---> File Tidak Ada\n");
		exit(1);
	}

	while ((fgets(string, 256, f_teks)) != NULL)
	{
		printf("%s\r", string);
	}
	fclose(f_teks); 
	
}

void selamatDatang(){
	
	system("color 0A");
	
	printf  ("\n\n\n\n");
	printf  ("\t        /$$$$$$  /$$$$$$$$ /$$        /$$$$$$  /$$      /$$  /$$$$$$  /$$$$$$$$       /$$$$$$$   /$$$$$$  /$$$$$$$$ /$$$$$$  /$$   /$$  /$$$$$$   \n");
	printf  ("\t       /$$__  $$| $$_____/| $$       /$$__  $$| $$$    /$$$ /$$__  $$|__  $$__/      | $$__  $$ /$$__  $$|__  $$__//$$__  $$| $$$ | $$ /$$__  $$ \n");
	printf  ("\t      | $$  \\__/| $$      | $$      | $$  \\ $$| $$$$  /$$$$| $$  \\ $$   | $$         | $$  \\ $$| $$  \\ $$   | $$  | $$  \\ $$| $$$$| $$| $$  \\__/ \n");
	printf  ("\t      |  $$$$$$ | $$$$$   | $$      | $$$$$$$$| $$ $$/$$ $$| $$$$$$$$   | $$         | $$  | $$| $$$$$$$$   | $$  | $$$$$$$$| $$ $$ $$| $$ /$$$$ \n");
	printf  ("\t       \\____  $$| $$__/   | $$      | $$__  $$| $$  $$$| $$| $$__  $$   | $$         | $$  | $$| $$__  $$   | $$  | $$__  $$| $$  $$$$| $$|_  $$ \n");
	printf  ("\t       /$$  \\ $$| $$      | $$      | $$  | $$| $$\\  $ | $$| $$  | $$   | $$         | $$  | $$| $$  | $$   | $$  | $$  | $$| $$\\  $$$| $$  \\ $$ \n");  
	printf  ("\t      |  $$$$$$/| $$$$$$$$| $$$$$$$$| $$  | $$| $$ \\/  | $$| $$  | $$   | $$         | $$$$$$$/| $$  | $$   | $$  | $$  | $$| $$ \\  $$|  $$$$$$/ \n");  
	printf  ("\t       \\______/ |________/|________/|__/  |__/|__/     |__/|__/  |__/   |__/         |_______/ |__/  |__/   |__/  |__/  |__/|__/  \\__/ \\______/  \n"); 
	printf  ("\n\n\n");
	printf  ("\t\t\t\t\t      /$$$$$$$  /$$$$$$$$ /$$   /$$  /$$$$$$   /$$$$$$  /$$   /$$ /$$   /$$  /$$$$$$       \n");
	printf  ("\t\t\t\t\t     | $$__  $$| $$_____/| $$$ | $$ /$$__  $$ /$$__  $$| $$  | $$| $$$ | $$ /$$__  $$     \n");
	printf  ("\t\t\t\t\t     | $$  \\ $$| $$      | $$$$| $$| $$  \\__/| $$  \\__/| $$  | $$| $$$$| $$| $$  \\ $$ \n");
	printf  ("\t\t\t\t\t     | $$$$$$$/| $$$$$   | $$ $$ $$| $$ /$$$$| $$ /$$$$| $$  | $$| $$ $$ $$| $$$$$$$$     \n");
	printf  ("\t\t\t\t\t     | $$____/ | $$__/   | $$  $$$$| $$|_  $$| $$|_  $$| $$  | $$| $$  $$$$| $$__  $$     \n");
	printf  ("\t\t\t\t\t     | $$      | $$      | $$\\  $$$| $$  \\ $$| $$  \\ $$| $$  | $$| $$\\  $$$| $$  | $$ \n");
	printf  ("\t\t\t\t\t     | $$      | $$$$$$$$| $$ \\  $$|  $$$$$$/|  $$$$$$/|  $$$$$$/| $$ \\  $$| $$  | $$   \n");
	printf  ("\t\t\t\t\t     |__/      |________/|__/  \\__/ \\______/  \\______/  \\______/ |__/  \\__/|__/  |__/\n");
	printf  ("\n\n\n");
	printf  ("\t\t                /$$      /$$ /$$$$$$ /$$   /$$ /$$$$$$       /$$      /$$  /$$$$$$  /$$$$$$$  /$$   /$$ /$$$$$$$$ /$$$$$$$$             \n");
	printf  ("\t\t               | $$$    /$$$|_  $$_/| $$$ | $$|_  $$_/      | $$$    /$$$ /$$__  $$| $$__  $$| $$  /$$/| $$_____/|__  $$__/             \n");
	printf  ("\t\t               | $$$$  /$$$$  | $$  | $$$$| $$  | $$        | $$$$  /$$$$| $$  \\ $$| $$  \\ $$| $$ /$$/ | $$         | $$                \n");
	printf  ("\t\t               | $$ $$/$$ $$  | $$  | $$ $$ $$  | $$        | $$ $$/$$ $$| $$$$$$$$| $$$$$$$/| $$$$$/  | $$$$$      | $$                \n");
	printf  ("\t\t               | $$  $$$| $$  | $$  | $$  $$$$  | $$        | $$  $$$| $$| $$__  $$| $$__  $$| $$  $$  | $$__/      | $$                \n");
	printf  ("\t\t               | $$\\  $ | $$  | $$  | $$\\  $$$  | $$        | $$\\  $ | $$| $$  | $$| $$  \\ $$| $$\\  $$ | $$         | $$                \n");
	printf  ("\t\t               | $$ \\/  | $$ /$$$$$$| $$ \\  $$ /$$$$$$      | $$ \\/  | $$| $$  | $$| $$  | $$| $$ \\  $$| $$$$$$$$   | $$                \n");
	printf  ("\t\t               |__/     |__/|______/|__/  \\__/|______/      |__/     |__/|__/  |__/|__/  |__/|__/  \\__/|________/   |__/                \n");
	sound("Suara/SelamatDatangFix.wav");
	loadingBar(100);
}

void teksUserPelanggan(){
	
	system("cls");
	system("color 0E");
	printf  ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf  ("\t          /$$   /$$  /$$$$$$  /$$$$$$$$ /$$$$$$$        /$$$$$$$  /$$$$$$$$ /$$        /$$$$$$  /$$   /$$  /$$$$$$   /$$$$$$   /$$$$$$  /$$   /$$\n");
	printf  ("\t         | $$  | $$ /$$__  $$| $$_____/| $$__  $$      | $$__  $$| $$_____/| $$       /$$__  $$| $$$ | $$ /$$__  $$ /$$__  $$ /$$__  $$| $$$ | $$\n");
	printf  ("\t         | $$  | $$| $$  \\__/| $$      | $$  \\ $$      | $$  \\ $$| $$      | $$      | $$  \\ $$| $$$$| $$| $$  \\__/| $$  \\__/| $$  \\ $$| $$$$| $$\n");
	printf  ("\t         | $$  | $$|  $$$$$$ | $$$$$   | $$$$$$$/      | $$$$$$$/| $$$$$   | $$      | $$$$$$$$| $$ $$ $$| $$ /$$$$| $$ /$$$$| $$$$$$$$| $$ $$ $$\n");
	printf  ("\t         | $$  | $$ \\____  $$| $$__/   | $$__  $$      | $$____/ | $$__/   | $$      | $$__  $$| $$  $$$$| $$|_  $$| $$|_  $$| $$__  $$| $$  $$$$\n");
	printf  ("\t         | $$  | $$ /$$  \\ $$| $$      | $$  \\ $$      | $$      | $$      | $$      | $$  | $$| $$\\  $$$| $$  \\ $$| $$  \\ $$| $$  | $$| $$\\  $$$\n");
	printf  ("\t         |  $$$$$$/|  $$$$$$/| $$$$$$$$| $$  | $$      | $$      | $$$$$$$$| $$$$$$$$| $$  | $$| $$ \\  $$|  $$$$$$/|  $$$$$$/| $$  | $$| $$ \\  $$\n");
	printf  ("\t          \\______/  \\______/ |________/|__/  |__/      |__/      |________/|________/|__/  |__/|__/  \\__/ \\______/  \\______/ |__/  |__/|__/  \\__/\n");
	sound("Suara/UserPelangganFix.wav");
	loadingBar(100);
	system("cls");
}

void teksAdmin(){
	system("cls");
	system("color 0B");
	
	printf  ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf  ("\t\t\t\t\t\t\t    /$$$$$$  /$$$$$$$  /$$      /$$ /$$$$$$ /$$   /$$\n");
	printf  ("\t\t\t\t\t\t\t   /$$__  $$| $$__  $$| $$$    /$$$|_  $$_/| $$$ | $$\n");
	printf  ("\t\t\t\t\t\t\t  | $$  \\ $$| $$  \\ $$| $$$$  /$$$$  | $$  | $$$$| $$\n");
	printf  ("\t\t\t\t\t\t\t  | $$$$$$$$| $$  | $$| $$ $$/$$ $$  | $$  | $$ $$ $$\n");
	printf  ("\t\t\t\t\t\t\t  | $$__  $$| $$  | $$| $$  $$$| $$  | $$  | $$  $$$$\n");
	printf  ("\t\t\t\t\t\t\t  | $$  | $$| $$  | $$| $$\\  $ | $$  | $$  | $$\\  $$$\n");
	printf  ("\t\t\t\t\t\t\t  | $$  | $$| $$$$$$$/| $$ \\/  | $$ /$$$$$$| $$ \\  $$\n");
	printf  ("\t\t\t\t\t\t\t  |__/  |__/|_______/ |__/     |__/|______/|__/  \\__/\n");
	sound("Suara/AdminFix.wav");
	loadingBar(100);
	system("cls");

}

void sound(char* namaFile){
	
	PlaySound(namaFile, NULL, SND_SYNC);
	
}
