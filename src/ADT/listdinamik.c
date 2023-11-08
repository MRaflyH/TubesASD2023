#include "listdinamik.h"

ListDinamik CreateLD() {
	ListDinamik A;
	A.Content = (StrukBerkait *)malloc(sizeof(StrukBerkait) * InitialCapacity);
	A.Capacity = InitialCapacity;
	A.Neff = 0;
	return A;
}

void DeallocateLD(ListDinamik *l) {
	free((*l).Content);
}

boolean IsEmptyLD(ListDinamik l) {
    return l.Neff == 0;
}

boolean IsFullLD(ListDinamik l) {
    return l.Neff == l.Capacity;
}

boolean IsIdValidLD(ListDinamik l, IdxType i) {
    return i <= l.Neff;
}

ElType GetLD(ListDinamik l, IdxType i) {
    return l.Content[i].Info;
}

void InsertLD(ListDinamik *l, ElType x, IdxType i) {
	Address xnode;
	xnode = NewNodeSB(x);

    int j;

    if (IsFullLD(*l)) {
		StrukBerkait *temp = (StrukBerkait *)malloc(sizeof(StrukBerkait) * (*l).Capacity);
		for (j = 0; j < (*l).Neff; j++)
		{
            PasteWord((*l).Content[j].Info, &temp[j].Info);
			temp[j].Next = (*l).Content[j].Next;
		}

		DeallocateLD(l);
		(*l).Capacity *= 2;
		(*l).Content = (StrukBerkait *)malloc(sizeof(StrukBerkait) * (*l).Capacity);

		for (j = 0; j < (*l).Neff; j++)
		{
            PasteWord(temp[j].Info, &(*l).Content[j].Info);
			(*l).Content[j].Next = temp[j].Next;
		}
		free(temp);
    }

	for (j = (*l).Neff; j > i; j--)
	{
		PasteWord((*l).Content[j - 1].Info, &(*l).Content[j].Info);
		(*l).Content[j].Next = (*l).Content[j - 1].Next;
	}
	PasteWord(xnode->Info, &(*l).Content[i].Info);
	CreateSB(xnode);
	(*l).Neff++;
}

void DeleteLD(ListDinamik *l, IdxType i) {
	int j;
	for (j = i; j < (*l).Neff; j++)
	{
		PasteWord((*l).Content[j + 1].Info, &(*l).Content[j].Info);
	}
	(*l).Neff--;

    if ((*l).Neff <= ((*l).Capacity / 4)) {
		StrukBerkait *temp = (StrukBerkait *)malloc(sizeof(StrukBerkait) * (*l).Capacity);
		for (j = 0; j < (*l).Neff; j++)
		{
            PasteWord((*l).Content[j].Info, &temp[j].Info);
		}

		DeallocateLD(l);
		(*l).Capacity /= 2;
		(*l).Content = (StrukBerkait *)malloc(sizeof(StrukBerkait) * (*l).Capacity);

		for (j = 0; j < (*l).Neff; j++)
		{
            PasteWord(temp[j].Info, &(*l).Content[j].Info);
		}
		free(temp);
    }
}

void DisplayLD(ListDinamik l) {
	if (IsEmptyLD(l)) {
		printf("Kosong\n");
	}
	else {
		for (int i = 0; i < l.Neff; i++) {
			printf("%d. ", i+1);
			DisplayWord(l.Content[i].Info);
		}
	}
}