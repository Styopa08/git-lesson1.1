#include <stdio.h>

int main() {
  
	int a = 20;
	int b = 20;

	int* pa = &a;
	int* pb = &b;

	if (*pa < 12){
		*pa *= 2;
		printf("%d \n", *pa * *pb);
	} else if (*pa > 12){
		*pb = *pb * 3;
		printf("%d \n", *pa * *pb);
	}
	}
