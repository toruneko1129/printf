make
gcc -c -Wall -Wextra -Werror test_printf.c
gcc test_printf.o libftprintf.a
valgrind --leak-check=full --show-leak-kinds=all ./a.out
rm *.o a.out*
