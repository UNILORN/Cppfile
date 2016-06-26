/*********************************************
	ヘッダファイル
**********************************************/
#include <stdio.h>
#include <conio.h>
#include <time.h>

/*********************************************
	定義

		d_sosu　：　素数の入る配列の個数

**********************************************/
#define d_sosu 100000

/*********************************************

	入力した値を素因数分解

**********************************************/

int main(void){

	clock_t start;								//	Time 計算
	clock_t end;								//	Time 計算
	double Time[2];

	/*　全体用変数　*/
	int suji;
	int sosu[d_sosu];							//素数を入れる配列
	sosu[0] = 2;								//sosu[0]に素数である"2"を代入　( sosu_yoso = 1 )


	/*　素数検索用変数　*/
	int sosu_yoso = 1;							//sosuの要素数
	int cnt = 0;								//カウント変数　0:非検出 1:検出

	
	/*　素因数分解用変数　*/
	int soinsu_yoso[d_sosu];
	int soinsu_suji;


	printf("数値を入力してください：");
	scanf("%d", &suji);


	start = clock();	//	時間計算開始
	
	/*	素数検索開始！　*/

	for (int i = 3; i <= suji; i+=2){			//　「3」から「suji」までの奇数
		cnt = 0;						
		for (int j = 0; j < sosu_yoso; j++){	//sosuの要素数だけループ
			if (i % sosu[j] == 0){				//素数で割った時に割り切れればその値は素数ではない
				cnt++;							//カウント　1:検出
				break;
			}
		}
		if (cnt == 0){ sosu[sosu_yoso++] = i; }	//検出されなければ　「i」の値は素数
	}
	


	
	end = clock();		//	時間計算終了	
	Time[0] = (double)(end - start) / CLOCKS_PER_SEC;	//	Time関数で生成された整数値を「CLOCKS_PER_SEC」で割ると秒数に直せる

	/*---------------------------------------*/
	//確認用表示プログラム

	for (int i = 0; i < sosu_yoso; i++)
	{
		printf("%7d\n", sosu[i]);
	}

	printf("素数の数　:　%d個\n", sosu_yoso);
	/*---------------------------------------*/




	/*　素因数分解開始　*/

	soinsu_suji = suji;

	for (int i = 0; i < sosu_yoso; i++){ soinsu_yoso[i] = 0; }

	for (; soinsu_suji != 1;){
		for (int i = 0; i < sosu_yoso; i++){
			if (soinsu_suji%sosu[i] == 0){
				soinsu_suji = soinsu_suji / sosu[i];
				soinsu_yoso[i]++;
				break;
			}
		}
	}


	/*---------------------------------------*/
	//「soinsu_yoso」内確認プログラム

	/*for (int i = 0; i < sosu_yoso; i++){
		printf("%2d /",soinsu_yoso[i]);
	}*/
	/*---------------------------------------*/



	printf("\n");

	
	for (int i = 0; i < sosu_yoso; i++){
		if (soinsu_yoso[i]>0){
			printf("[%3d] ^ [%d] \n", sosu[i],soinsu_yoso[i]);
		}
	}

	printf("素数計算時間：%.4f秒",Time[0]);

	getch();

	return 0;
}