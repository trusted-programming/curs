sub    $0x28,%rsp
mov    %rsi,0x8(%rsp)
mov    %rdi,%rax
mov    0x8(%rsp),%rdi
mov    %rax,0x18(%rsp)
mov    %rdi,0x20(%rsp)
lea    0x0(%rip),%rsi        
mov    $0xc,%edx
callq  *0x0(%rip)        
mov    %al,0x17(%rsp)
mov    0x17(%rsp),%al
and    $0x1,%al
movzbl %al,%eax
add    $0x28,%rsp
retq   
