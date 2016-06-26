
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

/************************

	Number（要素数）
	Random（ランダム範囲）
	Number_suu（ランダム配列数）

************************/

#define Number 50000
#define Random 10000
#define Number_suu 4

/************************

	クイックソート

*************************/

/*	Quick ( [ソート対象] , [先頭要素（初期値：0）] , [要素数-1] )	*/

int Quick(int T[],int head,int tail){
	
	int left, right, pivot, work;
	
	if (head < tail){
		
		left = head;
		right = tail;
		pivot = T[(left + right) / 2];

		while (left < right){

			for (; T[left] < pivot; left++);
			for (; (left<right) && (T[right]>pivot || T[left] == T[right]); right--);

			if (left < right){
				work = T[left];
				T[left] = T[right];
				T[right] = work;
			}
		}
		Quick(T, head, left - 1);
		Quick(T, right + 1, tail);
	}
	return 0;
}

/************************
	
	バブルソート

*************************/

	/*	Bubble ( [ソート対象] , [要素数])	*/

int Bubble(int T[],int N){
	int tail, idx, work;
	for (tail = N - 1; tail > 0; tail--){
		for (idx = 0; idx < tail; idx++){
			if (T[idx]>T[idx + 1]){
				work = T[idx];
				T[idx] = T[idx + 1];
				T[idx + 1] = work;
			}
		}
	}
	return 0;
}

/************************

	インサートソート

*************************/

	/*	Insert ( [ソート対象] , [要素数])	*/

int Insert(int T[], int N){
	int head, idx, work;
	for (head = 1; head < N; head++){
		work = T[head];
		for (idx = head - 1; idx >= 0 && T[idx] > work; idx--){
			T[idx + 1] = T[idx];
		}
		T[idx + 1] = work;
	}
	return 0;
}

/************************

	メインプログラム

*************************/


int main(void)
{
	srand((unsigned int)time(NULL));			//	ランダム関数生成　（書式　rand() % [範囲] ）

	char hantei;
	int Ran[Number_suu][Number];				//	[Number_suu]　0：メイン　1～任意：各ソート　[Number]　要素数
	double Time[3];								//	Time[]　0：クイックソート　1：バブルソート
	clock_t start;								//	Time 計算
	clock_t end;								//	Time 計算

	printf("ランダム要素を %d 個作成します。(Enter)\n", Number);
	printf("ランダム値と結果を表示しますか？　（y）or（n）：");
	scanf("%c", &hantei);

	
	for (int i = 0; i < Number; i++){ Ran[0][i] = rand() % Random; }				//	ランダム値を配列に格納
	for (int j = 1; j < Number_suu; j++){
		for (int i = 0; i < Number; i++){ Ran[j][i] = Ran[0][i];}					//	ランダム値を配列に格納
	}	
	if (hantei == 'y'){ for (int i = 0; i < Number; i++){ printf("%5d", Ran[1][i]); } }		//	ランダム値を表示

	printf("ソートを開始します。(Enter)\n");	getch();


	/************************
		クイックソート開始
	************************/
	start = clock();									//	時間計算開始
	Quick(Ran[1], 0, Number - 1);
	end = clock();										//	時間計算終了
	Time[0] = (double)(end - start) / CLOCKS_PER_SEC;	//	Time関数で生成された整数値を「CLOCKS_PER_SEC」で割ると秒数に直せる


	/************************
		バブルソート開始
	************************/
	start = clock();									//	時間計算開始
	Bubble(Ran[2], Number);
	end = clock();										//	時間計算終了
	Time[1] = (double)(end - start) / CLOCKS_PER_SEC;	//	Time関数で生成された整数値を「CLOCKS_PER_SEC」で割ると秒数に直せる


	/************************
		インサートソート開始
	************************/
	start = clock();									//	時間計算開始
	Insert(Ran[3], Number);
	end = clock();										//	時間計算終了
	Time[2] = (double)(end - start) / CLOCKS_PER_SEC;	//	Time関数で生成された整数値を「CLOCKS_PER_SEC」で割ると秒数に直せる


	if (hantei == 'y'){ for (int i = 0; i < Number; i++){ printf("%5d", Ran[1][i]); } }			//整列した値を表示

	printf(" ソートが終了しました。\n\n");
	printf("　+----------+------------+\n");
	printf("　| ソート名 |  処理時間  |\n");
	printf("　+----------+------------+\n");
	printf("　| クイック |  %.4f秒  |　\n", Time[0]);
	printf("　|  バブル  |  %.4f秒  |　\n", Time[1]);
	printf("　|インサート|  %.4f秒  |  \n", Time[2]);
	printf("　+----------+------------+\n (Enter)\n");	getch();

	

	return 0;

}