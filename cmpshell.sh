gcc -fno-stack-protector victim.c -o victim
execstack -s victim
