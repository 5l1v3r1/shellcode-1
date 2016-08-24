/*
Contact: Harrys Kon
Email: konharrys at gmail dot com

int 0x80           ;Execute the syscall
*/

int main(int argc, char **argv)
{
	asm("\
		shell_start:   \n\
		xor %eax, %eax \n\
		add $60, %eax  \n\
		xor %ebx, %ebx \n\
		add $20, %ebx  \n\
		int $0x80      \n\
		shell_end:     \n\
	");
	return 0;
}