# YANG DIGANTI CUMAN "display.c" "displaydriver.c" JADI "FILENAME.c" "FILENAMEDRIVER.c"
gcc "ADT/kata.c" "ADT/detaillagu.c" "ADT/mesinkarakter.c" "ADT/mesininput.c" "ADT/listdinamik.c" "ADT/liststatik.c" "ADT/map.c" "ADT/queue.c" "ADT/set.c" "ADT/stack.c" "ADT/strukturberkait.c" "data.c" "display.c" "displaydriver.c" -o main
./main

# CARA NGERUN UNTUK LINUX (CARA WINDOWS LAGI AKU CARI)
# cd <ini path ke local gitnya>/src
# bash <nama_file>.sh
# contoh:
# cd /Users/macpro/Documents/GitHub/TubesASD2023/test_folder_rafly/src
# bash displaydriver.sh

# KALAU CARA WINDOWS HARUS DOWNLOAD WSL (Windows Subsystem for Linux)
# abis itu sama tapi run wsl dulu, contoh:
# wsl
# cd /Users/macpro/Documents/GitHub/TubesASD2023/test_folder_rafly/src
# bash displaydriver.sh