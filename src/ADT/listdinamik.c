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
    return l.Content[i].Info.Name;
}

void InsertLD(ListDinamik *l, ElType x, IdxType i) {
	Address xnode;
    Word wkosong;
    Detail d;

    CreateWord(0, "", &wkosong);
	CreateD(&d, wkosong, wkosong, x);
	xnode = NewNodeSB(d);

    int j;

    if (IsFullLD(*l)) {
		StrukBerkait *temp = (StrukBerkait *)malloc(sizeof(StrukBerkait) * (*l).Capacity);
		for (j = 0; j < (*l).Neff; j++)
		{
            PasteWord((*l).Content[j].Info.Name, &temp[j].Info.Name);
			temp[j].Next = (*l).Content[j].Next;
		}

		DeallocateLD(l);
		(*l).Capacity *= 2;
		(*l).Content = (StrukBerkait *)malloc(sizeof(StrukBerkait) * (*l).Capacity);

		for (j = 0; j < (*l).Neff; j++)
		{
            PasteWord(temp[j].Info.Name, &(*l).Content[j].Info.Name);
			(*l).Content[j].Next = temp[j].Next;
		}
		free(temp);
    }

	for (j = (*l).Neff; j > i; j--)
	{
		PasteWord((*l).Content[j - 1].Info.Name, &(*l).Content[j].Info.Name);
		(*l).Content[j].Next = (*l).Content[j - 1].Next;
	}

	PasteWord(xnode->Info.Name, &(*l).Content[i].Info.Name);
	CreateSB(xnode);
	(*l).Neff++;
}

void DeleteLD(ListDinamik *l, IdxType i) {
	int j;
	for (j = i; j < (*l).Neff; j++)
	{
		PasteWord((*l).Content[j + 1].Info.Name, &(*l).Content[j].Info.Name);
		(*l).Content[j].Next = (*l).Content[j + 1].Next;
	}
	(*l).Neff--;

    if ((*l).Neff <= ((*l).Capacity / 4)) {
		StrukBerkait *temp = (StrukBerkait *)malloc(sizeof(StrukBerkait) * (*l).Capacity);
		for (j = 0; j < (*l).Neff; j++)
		{
            PasteWord((*l).Content[j].Info.Name, &temp[j].Info.Name);
			temp[j].Next = (*l).Content[j].Next;
		}

		DeallocateLD(l);
		(*l).Capacity /= 2;
		(*l).Content = (StrukBerkait *)malloc(sizeof(StrukBerkait) * (*l).Capacity);

		for (j = 0; j < (*l).Neff; j++)
		{
            PasteWord(temp[j].Info.Name, &(*l).Content[j].Info.Name);
			(*l).Content[j].Next = temp[j].Next;
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
			DisplayWord(l.Content[i].Info.Name);
		}
	}
}

void DisplayIsiLD(ListDinamik l, ElType x) {
	boolean found = false;
	int i = 0;
	while (i < l.Neff && !found) {
		if (IsWordSame(l.Content[i].Info.Name, x)) {
			DisplaySB(l.Content[i]);
			found = true;
		}
		i++;
	}
	if (!found) {
		printf("Playlist tidak ada\n");
	}
}

void DisplaySemuaLD(ListDinamik l) {
	if (IsEmptyLD(l)) {
		printf("Kosong\n");
	}

	for (int i = 0; i < l.Neff; i++) {
		printf("Playlist ");
		DisplayWord(l.Content[i].Info.Name);
		DisplaySB(l.Content[i]);
	}

}
