
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

/************************

	Number�i�v�f���j
	Random�i�����_���͈́j
	Number_suu�i�����_���z�񐔁j

************************/

#define Number 50000
#define Random 10000
#define Number_suu 4

/************************

	�N�C�b�N�\�[�g

*************************/

/*	Quick ( [�\�[�g�Ώ�] , [�擪�v�f�i�����l�F0�j] , [�v�f��-1] )	*/

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
	
	�o�u���\�[�g

*************************/

	/*	Bubble ( [�\�[�g�Ώ�] , [�v�f��])	*/

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

	�C���T�[�g�\�[�g

*************************/

	/*	Insert ( [�\�[�g�Ώ�] , [�v�f��])	*/

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

	���C���v���O����

*************************/


int main(void)
{
	srand((unsigned int)time(NULL));			//	�����_���֐������@�i�����@rand() % [�͈�] �j

	char hantei;
	int Ran[Number_suu][Number];				//	[Number_suu]�@0�F���C���@1�`�C�ӁF�e�\�[�g�@[Number]�@�v�f��
	double Time[3];								//	Time[]�@0�F�N�C�b�N�\�[�g�@1�F�o�u���\�[�g
	clock_t start;								//	Time �v�Z
	clock_t end;								//	Time �v�Z

	printf("�����_���v�f�� %d �쐬���܂��B(Enter)\n", Number);
	printf("�����_���l�ƌ��ʂ�\�����܂����H�@�iy�jor�in�j�F");
	scanf("%c", &hantei);

	
	for (int i = 0; i < Number; i++){ Ran[0][i] = rand() % Random; }				//	�����_���l��z��Ɋi�[
	for (int j = 1; j < Number_suu; j++){
		for (int i = 0; i < Number; i++){ Ran[j][i] = Ran[0][i];}					//	�����_���l��z��Ɋi�[
	}	
	if (hantei == 'y'){ for (int i = 0; i < Number; i++){ printf("%5d", Ran[1][i]); } }		//	�����_���l��\��

	printf("�\�[�g���J�n���܂��B(Enter)\n");	getch();


	/************************
		�N�C�b�N�\�[�g�J�n
	************************/
	start = clock();									//	���Ԍv�Z�J�n
	Quick(Ran[1], 0, Number - 1);
	end = clock();										//	���Ԍv�Z�I��
	Time[0] = (double)(end - start) / CLOCKS_PER_SEC;	//	Time�֐��Ő������ꂽ�����l���uCLOCKS_PER_SEC�v�Ŋ���ƕb���ɒ�����


	/************************
		�o�u���\�[�g�J�n
	************************/
	start = clock();									//	���Ԍv�Z�J�n
	Bubble(Ran[2], Number);
	end = clock();										//	���Ԍv�Z�I��
	Time[1] = (double)(end - start) / CLOCKS_PER_SEC;	//	Time�֐��Ő������ꂽ�����l���uCLOCKS_PER_SEC�v�Ŋ���ƕb���ɒ�����


	/************************
		�C���T�[�g�\�[�g�J�n
	************************/
	start = clock();									//	���Ԍv�Z�J�n
	Insert(Ran[3], Number);
	end = clock();										//	���Ԍv�Z�I��
	Time[2] = (double)(end - start) / CLOCKS_PER_SEC;	//	Time�֐��Ő������ꂽ�����l���uCLOCKS_PER_SEC�v�Ŋ���ƕb���ɒ�����


	if (hantei == 'y'){ for (int i = 0; i < Number; i++){ printf("%5d", Ran[1][i]); } }			//���񂵂��l��\��

	printf(" �\�[�g���I�����܂����B\n\n");
	printf("�@+----------+------------+\n");
	printf("�@| �\�[�g�� |  ��������  |\n");
	printf("�@+----------+------------+\n");
	printf("�@| �N�C�b�N |  %.4f�b  |�@\n", Time[0]);
	printf("�@|  �o�u��  |  %.4f�b  |�@\n", Time[1]);
	printf("�@|�C���T�[�g|  %.4f�b  |  \n", Time[2]);
	printf("�@+----------+------------+\n (Enter)\n");	getch();

	

	return 0;

}