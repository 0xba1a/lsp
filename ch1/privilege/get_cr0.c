#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef unsigned long u64;

static u64 get_rcx(void)
{
   /* ABI: [RAX] is returned by the function! */
   __asm__ __volatile__("movq %cr0, %rax");
}

int main(void)
{
   printf("Hello, inline assembly:\n [RCX] = 0x%lx\n", get_rcx());
   exit(0);
}
