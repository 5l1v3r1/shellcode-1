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
		mov $0x1,%al   \n\
		xor %ebx, %ebx \n\
		int $0x80      \n\
		shell_end:     \n\
	");
	return 0;
}
