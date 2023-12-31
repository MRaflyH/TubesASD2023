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

boolean IsIdxValidLD(ListDinamik l, IdxType i) {
    return i < l.Neff && i >= 0;
}

ElType GetLD(ListDinamik l, IdxType i) {
    return Title(l.Content[i]);
}

void InsertLD(ListDinamik *l, ElType x, IdxType i) {
	StrukBerkait xsb;

	CreateSB(&xsb);
	Title(xsb) = x;

    int j;

    if (IsFullLD(*l)) {
		StrukBerkait *temp = (StrukBerkait *)malloc(sizeof(StrukBerkait) * (*l).Capacity);
		for (j = 0; j < (*l).Neff; j++)
		{
            PasteWord(Title((*l).Content[j]), &Title(temp[j]));
			First(temp[j]) = First((*l).Content[j]);
		}

		DeallocateLD(l);
		(*l).Capacity *= 2;
		(*l).Content = (StrukBerkait *)malloc(sizeof(StrukBerkait) * (*l).Capacity);

		for (j = 0; j < (*l).Neff; j++)
		{
            PasteWord(Title(temp[j]), &Title((*l).Content[j]));
			First((*l).Content[j]) = First(temp[j]);
		}
		free(temp);
    }

	for (j = (*l).Neff; j > i; j--)
	{
		PasteWord(Title((*l).Content[j - 1]), &Title((*l).Content[j]));
		First((*l).Content[j]) = First((*l).Content[j - 1]);
	}

	PasteWord(Title(xsb), &Title((*l).Content[i]));
	(*l).Neff++;
}

void DeleteLD(ListDinamik *l, IdxType i) {
	int j;
	for (j = i; j < (*l).Neff; j++)
	{
		PasteWord(Title((*l).Content[j + 1]), &Title((*l).Content[j]));
		First((*l).Content[j]) = First((*l).Content[j + 1]);
	}
	(*l).Neff--;

    if ((*l).Neff <= ((*l).Capacity / 4)) {
		StrukBerkait *temp = (StrukBerkait *)malloc(sizeof(StrukBerkait) * (*l).Capacity);
		for (j = 0; j < (*l).Neff; j++)
		{
            PasteWord(Title((*l).Content[j]), &Title(temp[j]));
			First(temp[j]) = First((*l).Content[j]);
		}

		DeallocateLD(l);
		(*l).Capacity /= 2;
		(*l).Content = (StrukBerkait *)malloc(sizeof(StrukBerkait) * (*l).Capacity);

		for (j = 0; j < (*l).Neff; j++)
		{
            PasteWord(Title(temp[j]), &Title((*l).Content[j]));
			First((*l).Content[j]) = First(temp[j]);
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
			printf("    %d. ", i+1);
			DisplayWordNewLine(Title(l.Content[i]));
		}
	}
}

void DisplayIsiLD(ListDinamik l, ElType x) {
	boolean found = false;
	int i = 0;
	while (i < l.Neff && !found) {
		if (IsWordSame(Title(l.Content[i]), x)) {
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
		printf("Judul %d: ", i+1);
		DisplayWordNewLine(Title(l.Content[i]));
		DisplaySB(l.Content[i]);
	}

}
