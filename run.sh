gcc -c -Wall -Wextra -Werror test_printf.c
gcc test_printf.o libftprintf.a
./a.out
rm a.out
