clear
rm *.o
rm program
gcc city_tree.c -o city_tree.o -c
gcc city.c -o city.o -c
gcc helpers.c -o helpers.o -c
gcc program.c -o program.o -c
gcc state_hash.c -o state_hash.o -c
gcc state_list.c -o state_list.o -c
gcc state.c -o state.o -c
gcc zadatak10a.c -o zadatak10a.o -c
gcc zadatak11.c -o zadatak11.o -c
gcc -o program city_tree.o city.o zadatak10a.o zadatak11.o helpers.o program.o state_hash.o state_list.o state.o
rm *.o
./program