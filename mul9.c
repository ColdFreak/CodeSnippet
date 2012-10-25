/*不用加减乘除法计算整数的9倍*/
#include <stdio.h>

int mul_9(int number) {
	int temp,carry;
	/*carry = temp & number 是为了看异或运算（相加）时哪些地方须要加1
	 * 然后先加上temp ^= number, 再在后面的位移运算中左移一位，为了下次的异或运算(相加)
	 * 这个下次的异或之前，还要再判断carry（加上number之后再有没有进位），如此反复*/
	for(temp = number << 3; carry = temp & number; temp ^= number, number = carry << 1)
	  	;
	return temp^number;
}

int main() {
	int num;
	scanf("%d", &num);
	printf("%d * 9 = %d\n",num, mul_9(num));
	return 0;
}

