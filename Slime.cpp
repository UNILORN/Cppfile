
/*********************

	�X���C�����[�X

**********************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define Slimesuu 8		//�X���C���̐�


/*	�X���C���̂̑��x�ƍ��W	*/

class _Cslime{			
public:
	int speed;
	int location;
};


/*	���C���v���O����	*/

int main(void)
{
	srand((unsigned int)time(NULL));		/*	�����_���֐�	�@�@�@�@*/
	_Cslime step[Slimesuu];					/*	�X���C�����i�ސ�	�@�@*/
	int mainout = 0;						/*�@�X���C�����[�X���I���@*/
	float bairitu[Slimesuu];				/*�@�X���C���̔{���@�@�@�@�@*/
	int bet = 0;							/*�@BET��					*/	
	int betSlime = 0;						/*  BET����X���C���ԍ�     */
	int winSlime = 0;						/*  �������X���C���̗v�f��  */
	int winSlimebet = 0;

	for (int a = 0; a < Slimesuu; a++) step[a].location = 0;			/*	������	*/	
	for (int a = 0; a < Slimesuu; a++) step[a].speed = rand()%100;
	
	/**********************

	�J�n���

	***********************/

	printf("  +-----------------------------------------------------+\n");
	printf("  |                                                     |\n");
	printf("  |                 �X���C���@���[�X                    |\n");
	printf("  |                                                     |\n");
	printf("  +-----------------------------------------------------+\n");
	printf("  \n");
	printf("  �����L�[�������Ďn�߂�I\n");

	getch();

	system("cls");	/*��ʃN���A*/

	/**********************

	�X���C���x�b�h

	***********************/
	printf("  \n");
	printf("  +-----------------------------------------------------+\n");
	printf("�@|�@�@�@����̃X���C�������I                           |\n");
	printf("  +-----------------------------------------------------+\n");

	for (int i = 0; i < Slimesuu; i++){
		bairitu[i] = step[i].speed *0.1;
		printf("  |%3d�Ԗ�  :  %1.2f �{\n", i + 1, bairitu[i]);
	}

	while (betSlime > Slimesuu || betSlime < 1 ){
		printf("  +-----------------------------------------------------+\n");
		printf("  |  �ǂ̎q�ɓq����H ( 1 - %d ) \n", Slimesuu);
		printf("  +-----------------------------------------------------+\n");
		printf("  |�@�ԍ��@�F�@");
		scanf("%d", &betSlime);
	}
	while (bet > 10000 || bet < 1){
		printf("  +-----------------------------------------------------+\n");
		printf("  |  �����炩����H ( 1 - 10000 ) \n");
		printf("  +-----------------------------------------------------+\n");
		printf("  |�@���z�@�F�@");
		scanf("%d", &bet);
	}
	printf("  +-----------------------------------------------------+\n");
	printf("  \n");
	printf("  �����I�@���[�X���J�n���܂��I�I�@�i�����L�[�������Ă��������j\n");
	getch();
	
	
	/**********************

	�X���C�����[�X�J�n�I

	***********************/

	while (1)
	{
		
		system("cls");	/*��ʃN���A*/

		printf("+---+-----------------------------------------------------------------+\n");
		printf("|   | �X���C�����[�X   [%d�Ԗ�]��[%5d�|�C���g]�@���Ă�P+[%1.2f]�{�I   |\n",betSlime,bet,bairitu[betSlime-1]);
		printf("+---+-----------------------------------------------------------------+\n");

		for (int i = 0; i < Slimesuu; i++)
		{
			printf("|%3d| ",i+1);
			

			for (int j = 0; j < step[i].location; j++)	/*�X���C���O��*/
			{
				printf(" ");
			}

			printf("�X");

			for (int j = 62; j > step[i].location; j--)	/*�X���C�����*/
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

		���ʁI�I

	***********************/

	for (int i = 0; i < Slimesuu; i++){
		if (step[i].location == 63){
			printf("�@[�@%d�@]�@�Ԗڂ̃X���C���������܂����I�I\n", i + 1);
			winSlime = i;
		}
	}

	getch();
	system("cls");

	if (betSlime - 1 == winSlime){
		winSlimebet = bet*bairitu[betSlime - 1];
		printf("  \n");
		printf("  ���߂łƂ��������܂��I\n");
		getch();
		printf("  \n");
		printf("  �|����[%5d]�|�C���g�@���@�{��[%1.2f] = [%5d]�|�C���g�I�I\n", bet, bairitu[betSlime - 1], winSlimebet);
		getch();
		printf("  \n");
		printf("  ���v���z[%5d]�|�C���g�I�I\n",winSlimebet+bet);
	}
	else {
		printf("  \n");
		printf("  �c�O�ł����B�E�E�E\n\n");
	}



	return 0;
}