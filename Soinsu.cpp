/*********************************************
	�w�b�_�t�@�C��
**********************************************/
#include <stdio.h>
#include <conio.h>
#include <time.h>

/*********************************************
	��`

		d_sosu�@�F�@�f���̓���z��̌�

**********************************************/
#define d_sosu 100000

/*********************************************

	���͂����l��f��������

**********************************************/

int main(void){

	clock_t start;								//	Time �v�Z
	clock_t end;								//	Time �v�Z
	double Time[2];

	/*�@�S�̗p�ϐ��@*/
	int suji;
	int sosu[d_sosu];							//�f��������z��
	sosu[0] = 2;								//sosu[0]�ɑf���ł���"2"�����@( sosu_yoso = 1 )


	/*�@�f�������p�ϐ��@*/
	int sosu_yoso = 1;							//sosu�̗v�f��
	int cnt = 0;								//�J�E���g�ϐ��@0:�񌟏o 1:���o

	
	/*�@�f��������p�ϐ��@*/
	int soinsu_yoso[d_sosu];
	int soinsu_suji;


	printf("���l����͂��Ă��������F");
	scanf("%d", &suji);


	start = clock();	//	���Ԍv�Z�J�n
	
	/*	�f�������J�n�I�@*/

	for (int i = 3; i <= suji; i+=2){			//�@�u3�v����usuji�v�܂ł̊
		cnt = 0;						
		for (int j = 0; j < sosu_yoso; j++){	//sosu�̗v�f���������[�v
			if (i % sosu[j] == 0){				//�f���Ŋ��������Ɋ���؂��΂��̒l�͑f���ł͂Ȃ�
				cnt++;							//�J�E���g�@1:���o
				break;
			}
		}
		if (cnt == 0){ sosu[sosu_yoso++] = i; }	//���o����Ȃ���΁@�ui�v�̒l�͑f��
	}
	


	
	end = clock();		//	���Ԍv�Z�I��	
	Time[0] = (double)(end - start) / CLOCKS_PER_SEC;	//	Time�֐��Ő������ꂽ�����l���uCLOCKS_PER_SEC�v�Ŋ���ƕb���ɒ�����

	/*---------------------------------------*/
	//�m�F�p�\���v���O����

	for (int i = 0; i < sosu_yoso; i++)
	{
		printf("%7d\n", sosu[i]);
	}

	printf("�f���̐��@:�@%d��\n", sosu_yoso);
	/*---------------------------------------*/




	/*�@�f���������J�n�@*/

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
	//�usoinsu_yoso�v���m�F�v���O����

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

	printf("�f���v�Z���ԁF%.4f�b",Time[0]);

	getch();

	return 0;
}