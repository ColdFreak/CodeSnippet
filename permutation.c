/* 注意，每打印一次后，返回到上一级，然后第二个swap把两个字符换回来
   A和A换，然后原本应该是A和B换，A和C换
   但是A－B， A－C 都被推迟了，
   直接进入B和B换，接下来原本应该是B和C换
   但B－C 被推迟了，直接进入C和C换
   C－C换完之后，打印ABC
   然后退回上一级，B－C换，这时变成ACB
   再经历一次B与B换，然后打印ACB
   然后再退一级A与B换，经历一次A与A换，C与C换，打印BAC
*/

#include <stdio.h>

void swap(char *x, char *y) {
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void permute(char *a, int start, int end) {
	int curr;

	if ( start == end)
		printf("%s\n", a);
	else {
		for(curr = start; curr <= end; curr++) {
			swap(a+start, a+curr);
			permute(a , start+1,  end);
			swap(a+start, a+curr);
		}
	}
}

int main(void) {
	char a[] = "ABC";
	permute(a, 0, 2);
	return 0;
}
/*  ABC            Backtracking
	ACB            Time Complexity O(n*n!)
	BAC
	BCA
	CBA
	CAB */


