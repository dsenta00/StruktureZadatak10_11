clear
rm *.o
rm program
gcc list_node.c -o list_node.o -c
gcc list.c -o list.o -c
gcc list_test.c -o list_test.o -c
gcc -o program list.o list_node.o list_test.o
rm *.o
./program