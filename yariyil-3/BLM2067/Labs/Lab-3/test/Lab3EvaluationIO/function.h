struct nodeFB
{
	int id;
	int age;
	struct nodeFB *next;
};

struct nodeGS
{
	int id;
	struct nodeGS *next;
};

struct newNodeFB
{
	int id;
	int age;
	struct newNodeGS *next;
};

struct newNodeGS
{
	int id;
	struct newNodeFB *next;
};

void insertFB(struct nodeFB** startFB, int id, int age) {
	struct nodeFB* new_node = (struct nodeFB*) malloc(sizeof(struct nodeFB));
	new_node->id = id;
	new_node->age = age;
	struct nodeFB* current; 

    if (*startFB == NULL || (*startFB)->id >= new_node->id) { 
        new_node->next = *startFB; 
        *startFB = new_node; 
    } else 
	{
        current = *startFB; 
        while (current->next != NULL && current->next->id < new_node->id)
		{ 
            current = current->next; 
        } 
        new_node->next = current->next; 
        current->next = new_node; 
    }
}

void insertGS(struct nodeGS** startGS, int id) {
	struct nodeGS* new_node = (struct nodeGS*) malloc(sizeof(struct nodeGS));
	new_node->id = id;
	struct nodeGS* current; 

    if (*startGS == NULL || (*startGS)->id <= new_node->id) { 
        new_node->next = *startGS; 
        *startGS = new_node; 
    } else 
	{
        current = *startGS; 
        while (current->next != NULL && current->next->id > new_node->id)
		{ 
            current = current->next; 
        } 
        new_node->next = current->next; 
        current->next = new_node; 
    }
}

void printFB(struct nodeFB* startFB) {
	while (startFB != NULL) { 
        printf("%d %d\n", startFB->id, startFB->age); 
        startFB = startFB->next; 
    }
	puts("");
}

void printGS(struct nodeGS* startGS) {
	while (startGS != NULL) { 
        printf("%d\n", startGS->id); 
        startGS = startGS->next; 
    } 
	puts("");
}

void createFinalList(struct newNodeFB** startNewFB, struct nodeFB* startFB, struct nodeGS* startGS) {
	struct newNodeGS* startNewGS = (struct newNodeGS*) malloc(sizeof(struct newNodeGS));
	struct newNodeFB* _startNewFB = (struct newNodeFB*) malloc(sizeof(struct newNodeFB));
	*startNewFB = _startNewFB;
	struct newNodeFB* currentNewFB;
	struct newNodeGS* currentNewGS;
	struct nodeFB* currentFB;
	struct nodeGS* currentGS;
	currentNewFB = *startNewFB;
	currentNewGS = startNewGS;
	currentFB = startFB;
	currentGS = startGS;
	while (currentFB != NULL)
	{	
		currentNewFB->id = currentFB->id;
		currentNewFB->age = currentFB->age;
		currentNewFB->next = currentNewGS;
		currentNewGS->id = currentGS->id;
		currentFB = currentFB->next;
		currentGS = currentGS->next;

		printf("%d %d\n%d\n", currentNewFB->id, currentNewFB->age, currentNewGS->id);
		
	}
	
}

void printAll(struct newNodeFB* startNewFB) {
	struct newNodeGS* startNewGS = (struct newNodeGS*) malloc(sizeof(struct newNodeGS));
	struct newNodeFB* currentNewFB;
	struct newNodeGS* currentNewGS;
	currentNewFB = startNewFB;
	currentNewGS = startNewGS;
	while (1)
	{
		currentNewGS = currentNewFB->next;
		currentNewFB = currentNewGS->next;
		if (currentNewGS == NULL || currentNewFB == NULL)
		{
			break;
		}
		
		printf("%d %d\n%d\n", currentNewFB->id, currentNewFB->age, currentNewGS->id);
		
	}
}

// Bu lab kapsaminda kullanilacak butun fonksiyon tanimlarini bu dosyanin icine yazmaniz gerekmektedir.
// Tanimlanmasi zorunlu fonksiyonlar icerisinden kendi tanimayacaginiz baska fonksiyonlari cagirabilirsiniz.
// main.c dosyasinda bir degisiklik yapmayiniz.
// Sisteme function.h dosyasinin ismini OgrenciNumarasi.h olarak yukleyiniz.


