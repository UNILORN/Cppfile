
/*********************

	スライムレース

**********************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define Slimesuu 8		//スライムの数


/*	スライム個体の速度と座標	*/

class _Cslime{			
public:
	int speed;
	int location;
};


/*	メインプログラム	*/

int main(void)
{
	srand((unsigned int)time(NULL));		/*	ランダム関数	　　　　*/
	_Cslime step[Slimesuu];					/*	スライムが進む数	　　*/
	int mainout = 0;						/*　スライムレースを終わる　*/
	float bairitu[Slimesuu];				/*　スライムの倍率　　　　　*/
	int bet = 0;							/*　BET数					*/	
	int betSlime = 0;						/*  BETするスライム番号     */
	int winSlime = 0;						/*  勝ったスライムの要素数  */
	int winSlimebet = 0;

	for (int a = 0; a < Slimesuu; a++) step[a].location = 0;			/*	初期化	*/	
	for (int a = 0; a < Slimesuu; a++) step[a].speed = rand()%100;
	
	/**********************

	開始画面

	***********************/

	printf("  +-----------------------------------------------------+\n");
	printf("  |                                                     |\n");
	printf("  |                 スライム　レース                    |\n");
	printf("  |                                                     |\n");
	printf("  +-----------------------------------------------------+\n");
	printf("  \n");
	printf("  何かキーを押して始める！\n");

	getch();

	system("cls");	/*画面クリア*/

	/**********************

	スライムベッド

	***********************/
	printf("  \n");
	printf("  +-----------------------------------------------------+\n");
	printf("　|　　　今回のスライムたち！                           |\n");
	printf("  +-----------------------------------------------------+\n");

	for (int i = 0; i < Slimesuu; i++){
		bairitu[i] = step[i].speed *0.1;
		printf("  |%3d番目  :  %1.2f 倍\n", i + 1, bairitu[i]);
	}

	while (betSlime > Slimesuu || betSlime < 1 ){
		printf("  +-----------------------------------------------------+\n");
		printf("  |  どの子に賭ける？ ( 1 - %d ) \n", Slimesuu);
		printf("  +-----------------------------------------------------+\n");
		printf("  |　番号　：　");
		scanf("%d", &betSlime);
	}
	while (bet > 10000 || bet < 1){
		printf("  +-----------------------------------------------------+\n");
		printf("  |  いくらかける？ ( 1 - 10000 ) \n");
		printf("  +-----------------------------------------------------+\n");
		printf("  |　金額　：　");
		scanf("%d", &bet);
	}
	printf("  +-----------------------------------------------------+\n");
	printf("  \n");
	printf("  さあ！　レースを開始します！！　（何かキーを押してください）\n");
	getch();
	
	
	/**********************

	スライムレース開始！

	***********************/

	while (1)
	{
		
		system("cls");	/*画面クリア*/

		printf("+---+-----------------------------------------------------------------+\n");
		printf("|   | スライムレース   [%d番目]に[%5dポイント]　勝てばP+[%1.2f]倍！   |\n",betSlime,bet,bairitu[betSlime-1]);
		printf("+---+-----------------------------------------------------------------+\n");

		for (int i = 0; i < Slimesuu; i++)
		{
			printf("|%3d| ",i+1);
			

			for (int j = 0; j < step[i].location; j++)	/*スライム前空白*/
			{
				printf(" ");
			}

			printf("ス");

			for (int j = 62; j > step[i].location; j--)	/*スライム後空白*/
			{
				printf(" ");
			}

			printf("|\n");

			printf("+---+-----------------------------------------------------------------+\n");

		}
				
		for (int i = 0; i < Slimesuu; i++){
				if (rand() % 100 > step[i].speed){
					step[i].location++;
			}
		}

		for (int i = 0; i < Slimesuu; i++){
			if (step[i].location == 63){
				mainout = 1;
			}
		}

		if (mainout)break;

		getch();

	}

	/**********************

		結果！！

	***********************/

	for (int i = 0; i < Slimesuu; i++){
		if (step[i].location == 63){
			printf("　[　%d　]　番目のスライムが勝ちました！！\n", i + 1);
			winSlime = i;
		}
	}

	getch();
	system("cls");

	if (betSlime - 1 == winSlime){
		winSlimebet = bet*bairitu[betSlime - 1];
		printf("  \n");
		printf("  おめでとうございます！\n");
		getch();
		printf("  \n");
		printf("  掛け金[%5d]ポイント　＊　倍率[%1.2f] = [%5d]ポイント！！\n", bet, bairitu[betSlime - 1], winSlimebet);
		getch();
		printf("  \n");
		printf("  合計金額[%5d]ポイント！！\n",winSlimebet+bet);
	}
	else {
		printf("  \n");
		printf("  残念でした。・・・\n\n");
	}



	return 0;
}