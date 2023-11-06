#include "listdinamik.h"

ListDinamik CreateLD() {
	ListDinamik A;
	A.Content = (ElType *)malloc(sizeof(ElType) * InitialCapacity);
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
    return l.Content[i];
}

void InsertLD(ListDinamik *l, ElType x, IdxType i) {
    int j;

    if (IsFullLD(*l)) {
		ElType *temp = (ElType *)malloc(sizeof(ElType) * (*l).Capacity);
		for (j = 0; j < (*l).Neff; j++)
		{
            PasteWord((*l).Content[j], &temp[j]);
		}

		DeallocateLD(l);
		(*l).Capacity *= 2;
		(*l).Content = (ElType *)malloc(sizeof(ElType) * (*l).Capacity);

		for (j = 0; j < (*l).Neff; j++)
		{
            PasteWord(temp[j], &(*l).Content[j]);
		}
		free(temp);
    }

	for (j = (*l).Neff; j > i; j--)
	{
		PasteWord((*l).Content[j - 1], &(*l).Content[j]);
	}
	PasteWord(x, &(*l).Content[i]);
	(*l).Neff++;
}

void DeleteLD(ListDinamik *l, IdxType i) {
	int j;
	for (j = i; j < (*l).Neff; j++)
	{
		PasteWord((*l).Content[j + 1], &(*l).Content[j]);
	}
	(*l).Neff--;

    if ((*l).Neff <= ((*l).Capacity / 4)) {
		ElType *temp = (ElType *)malloc(sizeof(ElType) * (*l).Capacity);
		for (j = 0; j < (*l).Neff; j++)
		{
            PasteWord((*l).Content[j], &temp[j]);
		}

		DeallocateLD(l);
		(*l).Capacity /= 2;
		(*l).Content = (ElType *)malloc(sizeof(ElType) * (*l).Capacity);

		for (j = 0; j < (*l).Neff; j++)
		{
            PasteWord(temp[j], &(*l).Content[j]);
		}
		free(temp);
    }
}

void DisplayLD(ListDinamik l) {
    for (int i = 0; i < l.Neff; i++) {
        printf("%d. ", i+1);
        DisplayWord(l.Content[i]);
    }
}