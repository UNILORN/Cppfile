#include<stdio.h>

int main(void){

	int H[300], W[300];

	for (int i = 0;; i++){
		scanf("%d %d", &H[i], &W[i]);
		if (H[i] == 0 && W[i] == 0){ break; }
	}
	for (int z = 0;; z++){
		for (int i = 0; i < H[z]; i++){
			for (int j = 0; j < W[z]; j++){
				if (i % 2 == 0){
					if (j % 2 == 0){ printf("#"); }
					else{ printf("."); }
				}
				else{
					if (j % 2 == 0){ printf("."); }
					else{ printf("#"); }
				}
			}
			printf("\n");
		}
		if (H[z] == 0 && W[z] == 0){ break; }
		printf("\n");
	}
	return 0;
}