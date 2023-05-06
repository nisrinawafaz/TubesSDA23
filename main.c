#include "header.h"
#include "Fauza.h"
#include "Nisrina.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
	address front, P;
	address1 leafref;
	Link root;
	int role;
	infotype KodeChar;
	
	
	infotype KodeBinary;
	KodeBinary = (infotype)malloc(30*sizeof(char));
	
	front = Nil;
	KodeChar = Nil;
	
	//pembuatan huffman tree
	front = createFrekuensi();
	sortingFreq(&front);
	
	leafref = CreateListOfLeaf(front);
	
	root = CreateTree (leafref);
	
	//market
	//selamat_datang();
	system("cls");
	loading("\tTUNGGU SEBENTAR...");
	do
	{
		selection(&role, "user", "admin", "Siapakah Anda?", "saya adalah");
		if(role == 1)
		{
			CekHarga (root);
		}
		else if(role == 2)
		{
			adminFitur(root);
		}
		else
		{
			printf("role yang and pilih tidak tersedia\n");
			printf("pilih role yang sudah tersedia [klik enter]");
			getche();
		}
	}while(role !=1 && role !=2);
	
	return 0;
}
