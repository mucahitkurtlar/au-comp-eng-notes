#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "function.h"

struct nodeFB *startFB = NULL;
struct nodeGS *startGS = NULL;
struct newNodeFB *startNewFB = NULL;

int main()
{
	int id, age;
	scanf("%d", &id);
	while(id!=-1)
	{
		scanf("%d", &age);
		
		scanf("%d", &id);
	}

	scanf("%d", &id);
	while(id!=-1)
	{
		insertGS(&startGS, id); //Galatasaray bagli listesine eleman ekleme fonksiyonu
		scanf("%d", &id);
	}

	printGS(startGS); //Galatasaray bagli listesini yazdiran fonksiyon

	return 0;

}
