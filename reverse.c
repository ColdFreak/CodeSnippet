#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void strReverse1(char *str) {
	int len = strlen(str);
	int i, j;
	char temp;
	for(i=0, j = len -1; i < j; i++, j--) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	
}

char *strReverse2(char *str) {
	char *ptr;
	int len = strlen(str);
	int i; 
	ptr = malloc(sizeof(char)*(len+1));
	for (i = len-1; i>=0; i--) 
		ptr[len-i-1] = str[i];
	ptr[len] = '\0';
	return ptr;
}


int main(void) {
	char string[50] = "I love you";
	strReverse1(string);
	printf ("%s\n",string);
//	char *ptr;
//	ptr = strReverse2(string);
//	printf("%s\n",ptr);
	
	return 0;
}
	
	
