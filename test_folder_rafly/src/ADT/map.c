#include "map.h"

void CreateM(Map *m) {
    (*m).Length = 0;
}

boolean IsEmptyM(Map m) {
    return (m.Length == 0);
}

boolean IsFullM(Map m) {
    return (m.Length == MaxCapacity);
}

boolean IsMemberM(Map m, KeyType k) {
    int i;
    for (i = 0; i < m.Length; i++) {
        if (IsWordSame(m.Content[i].Key, k)) {
            return true;
        }
    }
    return false;
}

ValType ValueM(Map m, KeyType k) {
    int i;
    for (i = 0; i < m.Length; i++) {
        if (IsWordSame(m.Content[i].Key, k)) {
            return m.Content[i].Value;
        }
    }
    Set s;
    CreateSet(&s);
    return s;
}

void InsertM(Map *m, KeyType k, ValType v) {
    if (!IsFullM(*m) && !IsMemberM(*m, k)) {
        PasteWord(k, &(*m).Content[(*m).Length].Key);
        CopySet(v, &(*m).Content[(*m).Length].Value);
        (*m).Length++;
    }
    else if (IsMemberM(*m, k)) {
        for (int i = 0; i < (*m).Length; i++) {
            if (IsWordSame((*m).Content[i].Key, k)) {
                CopySet(v, &(*m).Content[i].Value);
            }
        }
    }
}

void DeleteM(Map *m, KeyType k) {
    int i = 0;

    while (!IsWordSame((*m).Content[i].Key, k) && i < (*m).Length) {
        i++;
    }


    if (IsWordSame((*m).Content[i].Key, k)) {
        for (int j = i; j < (*m).Length; j++) {
            PasteWord((*m).Content[(*m).Length - 1].Key, &(*m).Content[i].Key);
            CopySet((*m).Content[(*m).Length - 1].Value, &(*m).Content[i].Value);
        }
        (*m).Length--;
    }
}

void DisplayValueM(Map m, KeyType k) {
    if (IsMemberM(m, k)) {
        DisplaySet(ValueM(m, k));
    }
    else {
        printf("Key Tidak Ditemukan\n");
    }
}

void DisplayM(Map m) {
    if (IsEmptyM(m)) {
        printf("Kosong\n");
    }
    else {
        for (int i = 0; i < m.Length; i++) {
            printf("Key %d: ", i+1);
            DisplayWord(m.Content[i].Key);
            DisplaySet(m.Content[i].Value);
        }
    }
}
