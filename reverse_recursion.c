#include <stdio.h>

void reverse(char *str) {
	if(*str){
		reverse(str+1);
		printf("%c",*str);
	}
}

// 下面这个函数是把每个字符付到另一个字符中，
// 和上面的没什么区别
char *reverse2th(char *input, char *output) {
	static i = 0;
	if(*input) {
		reverse2th(input+1, output);
		output[i] = *input;
		i++;
	}
	return input;
}


int main(void) {
	char str[50] = "I love you";
	char input[50] = "Geeks for Geeks.";
	char output[5]= {0};

	reverse(str);
	reverse2th(input, output);
	printf("\n%s\n",output);
	return 0;
}
