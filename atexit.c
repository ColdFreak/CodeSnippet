#include <stdio.h>
#include <stdlib.h>

void fnExit1 (void)
{
    puts ("Exit function 1.");
}

void fnExit2 (void)
{
    puts ("Exit function 2.");
}

int main ()
{
	/* main() 在return之后，还是可以执行这个特定的函数
	 * 用它来注册在程序中止时调用的函数*/
   /* int atexit(void (*func)(void))*/
   /* 成功则返回0，否则返回-1，并且errno被设定*/
	/*最后注册的最先调用*/
    atexit (fnExit1);
    atexit (fnExit2);
    puts ("Main function.");
    return 0;
}
