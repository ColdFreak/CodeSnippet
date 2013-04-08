#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void strReverse(char *str, int len) {
	int i, j;
	char temp;
	for(i=0, j = len -1; i < j; i++, j--) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	
}

char *reverseWords(char *str) {
	int i,j;
	i = j = 0;
	strReverse(str,strlen(str));
	while(1) {
		if(str[i] == ' ' || str[i] == '\0') {
			strReverse(str+j, i-j);
			j = i+1;

		}
		if(str[i] == '\0')
			break;
		else 
			i++;
	}
}
		
		

int main(void) {
	char string[50] = "I love you";

	reverseWords(string);
	printf("%s\n",string);
	return 0;
}
