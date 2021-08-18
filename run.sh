gcc -c test_printf.c
gcc test_printf.o libftprintf.a
./a.out lib > lib.txt
./a.out > ft.txt
diff -s lib.txt ft.txt
#valgrind --leak-check=full --show-leak-kinds=all ./a.out
rm test_printf.o a.out
rm -rf a.out*
