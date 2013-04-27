#include "file3.h"
#include <stdio.h>


void use_it (void) {
	printf("global variable: %d\n", ++global_variable);
}

int main(void) {
	use_it();
	return 0;
}


