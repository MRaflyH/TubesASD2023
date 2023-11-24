#include "map.h"

int main() {
    Map map;
    Word key, tempword;
    Set set;

    CreateM(&map);
    printf("IsEmpty: %d\n", IsEmptyM(map));
    printf("IsFull: %d\n", IsFullM(map));
    printf("Ini map kosong: \n");
    DisplayM(map);

    CreateWord(12, "Taylor Swift", &key);
    CreateSet(&set);

    CreateWord(4, "1989", &tempword);
    AddSet(&set, tempword);
    CreateWord(10, "reputation", &tempword);
    AddSet(&set, tempword);
    CreateWord(3, "red", &tempword);
    AddSet(&set, tempword);
    CreateWord(5, "lover", &tempword);
    AddSet(&set, tempword);

    InsertM(&map, key, set);

    CreateWord(10, "John Mayer", &key);
    CreateSet(&set);

    CreateWord(10, "Continuum.", &tempword);
    AddSet(&set, tempword);
    CreateWord(24, "The Search Of Everything", &tempword);
    AddSet(&set, tempword);
    CreateWord(14, "Battle Studies", &tempword);
    AddSet(&set, tempword);

    InsertM(&map, key, set);

    printf("\nIni inisial map: \n");
    DisplayM(map);
    
    printf("IsMember John Mayer: %d\n", IsMemberM(map, key));
    printf("Value John Mayer:\n");
    DisplayValueM(map, key);

    CreateWord(10, "John Mayer", &key);
    DeleteM(&map, key);

    printf("\nDihapus John Mayer: \n");
    DisplayM(map);



    return 0;
}