
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

int main(void){

	char mozi;
	int count_side = 1;
	int Enter_cl = 0;

	for (;;){

		mozi = getch();
		system("cls");

		if (mozi == 72){ printf("上"); }
		if (mozi == 75){ count_side--; }
		if (mozi == 77){ count_side++; }
		if (mozi == 80){ printf("下"); }
		if (mozi == 13){ Enter_cl = 1; }
		if (count_side < 1){ count_side = 1; }
		if (count_side > 3){ count_side = 3; }

		printf("        +---+     +---+     +---+\n");
		printf("        |   |     |   |     |   |\n");
		printf("        | 1 |     | 2 |     | 3 |\n");
		printf("        |   |     |   |     |   |\n");
		printf("        +---+     +---+     +---+\n");

		for (int i = 0; i < count_side; i++){ printf("          "); }
		printf("△");

		if (Enter_cl == 1){ break; }

	}

	system("cls");
	if (count_side == 1){ printf("1番を押しましたね"); }
	else if (count_side == 2){ printf("2番を押しましたね"); }
	else if (count_side == 3){ printf("3番を押しましたね"); }

	return 0;
}