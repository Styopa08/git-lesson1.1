#include <stdio.h>

int main(){

	int arr[4];

	for (int i = 0; i < 4; i++){
		scanf("%d", &arr[i]);
	}


	int sum = 0;
	int prod = 1;
	for (int i = 3; i >= 0; --i){
		sum += arr[i];
		prod *= arr[i];
	}

	printf("sum = %d \nprod = %d \n", sum, prod);


}
