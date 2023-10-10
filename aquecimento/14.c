#include <stdio.h>

int main (){
	int n, c, ndig = 0, acc =0 ;
	scanf("%d", &n);
	for (ndig = 0; n > 0; ndig++) {
    	n /= 10;
	}
	for (ndig; ndig > 0; ndig--){
		for (c = 10; c < n ; c = c * 10){
			if (n % (ndig *  c) == n % c){
				acc +=1;}				
		}
	}
	if (acc == ndig){
		printf("sim");
	} else {
		printf("nao");
	}
}