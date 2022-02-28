0:	48 83 ec 58          	sub    $0x58,%rsp
4:	48 89 4c 24 08       	mov    %rcx,0x8(%rsp)
9:	48 89 54 24 10       	mov    %rdx,0x10(%rsp)
e:	48 89 f0             	mov    %rsi,%rax
11:	48 8b 74 24 08       	mov    0x8(%rsp),%rsi
16:	48 89 f9             	mov    %rdi,%rcx
19:	48 8b 7c 24 10       	mov    0x10(%rsp),%rdi
1e:	48 89 4c 24 18       	mov    %rcx,0x18(%rsp)
23:	48 89 4c 24 20       	mov    %rcx,0x20(%rsp)
28:	48 89 44 24 40       	mov    %rax,0x40(%rsp)
2d:	48 89 7c 24 48       	mov    %rdi,0x48(%rsp)
32:	48 89 74 24 50       	mov    %rsi,0x50(%rsp)
37:	e8 00 00 00 00       	callq  3c <<serde_json::read::StrRead as serde_json::read::Read>::parse_str::{{closure}}+0x3c>
3c:	48 89 44 24 28       	mov    %rax,0x28(%rsp)
41:	48 89 54 24 30       	mov    %rdx,0x30(%rsp)
46:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
4b:	48 8b 4c 24 18       	mov    0x18(%rsp),%rcx
50:	48 8b 54 24 30       	mov    0x30(%rsp),%rdx
55:	48 8b 74 24 28       	mov    0x28(%rsp),%rsi
5a:	48 89 71 08          	mov    %rsi,0x8(%rcx)
5e:	48 89 51 10          	mov    %rdx,0x10(%rcx)
62:	48 c7 01 00 00 00 00 	movq   $0x0,(%rcx)
69:	48 83 c4 58          	add    $0x58,%rsp
6d:	c3                   	retq   
