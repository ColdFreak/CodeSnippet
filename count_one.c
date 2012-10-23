#include <stdio.h>

int count_one(int num) {
	int count;
	/* num &= num-1 会削去num 中的一个1
	 * 比如 10100 &= 10011 则会削去10100中的第一个1
	 * 变成 10000 */
	for( count = 0; num; num &= num-1)
		count++;
	return count;
}

int main(void) {
	int i;
	scanf("%d",&i);
	printf("There are %d one in the number.\n",count_one(i));
	return 0;
}

