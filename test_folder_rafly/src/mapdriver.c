#include "map.h"

int main() {
    Map map;
    Word key, tempword;
    Set set;

    CreateM(&map);

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

    DisplayM(map);

    CreateWord(10, "John Mayer", &key);
    DeleteM(&map, key);

    DisplayM(map);

    return 0;
}