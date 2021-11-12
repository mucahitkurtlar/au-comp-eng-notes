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
		insertFB(&startFB, id, age); //Fenerbahce bagli listesine eleman ekleme fonksiyonu
		scanf("%d", &id);
	}

	scanf("%d", &id);
	while(id!=-1)
	{
		
		scanf("%d", &id);
	}

	printFB(startFB); //Fenerbahce bagli listesini yazdiran fonksiyon
	return 0;

}
