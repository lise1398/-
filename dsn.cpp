/*
�ڷγ� ���� �� Ȯ���� ��Ȳ�� �����ִ� ���α׷��̴�. 
��ü ������ ũ�� 17�������� �����Ͽ�����, �̴� �����������ο��� �����ϴ� ���� ���п� �ش��Ѵ�. 
�������� Ȯ���� ���� ���� ��ȭ�ϹǷ� �̸� �ٷ� �ݿ��� �� �ֵ��� , ������ ���� �� ���� ������ �� �ֵ��� �Ͽ���.
����ü�� Ȱ���Ͽ� ������ Ȯ���� ���� �����Ͽ���.
���ο� �Լ��� �����Ͽ� ����ü �� ���� ��ȭ�� �� �ֵ��� �Ͽ���.
*/


#include <stdio.h>
#include <string.h>

typedef struct _localCovid19     //���� �� Ȯ���� ���� �����ϱ� ���� ����ü 
{
	char local[17];              //���� �̸� 
	int patient;				 //Ȯ���ڼ� 
} localCovid19, *PlocalCovid19;					  

void updatePatient(localCovid19 *local19)			//������ Ȯ���� �� ��ȭ�� �ݿ��ϱ� ���� �Լ� 
{
	for (int i = 0 ; i < 17 ; i++)
	{
		printf("%s : ", local19[i].local);			//�ش� ���� ���� ��� 
		scanf("%d", &local19[i].patient);			//�ش� ������ Ȯ���� ���� ���� 
	}
	printf("------------------------------------\n");    //����� ���� ������ �Է��� ����� �ԽõǴ� ������ �������ֱ� ���� ��� 
}

int main(void)
{
	localCovid19 localCovid19[25];						//����ü�� �̿��Ͽ� ���� 
	char *local[17] = {"Seoul", "gyeonggi-do", "Gangwon-do", "Chungcheongbuk-do", "Chungcheongnam-do", "Jeollabuk-do", "Jeollanam-do", "Gyeongsangbuk-do", 
						"Gyeongsangnam-do", "Incheon", "Sejong", "Daejeon", "Dae-gu", "Gwangju", "Ulsan", "Busan", "Jeju"};			//Ȯ���� ���� �����ϴ� ���� 
	int patient[17] = {3637088, 4950835, 519731, 557267, 717598, 601833, 597808, 783967, 1095230, 1076537, 139483, 513517, 765295, 534681, 381010, 1098165, 236840};   //������ Ȯ���ڼ� �ݿ� �ð� : 2022.06.11.23:00 
	for (int i = 0 ; i < 17 ; i++)
	{
		strcpy(localCovid19[i].local, local[i]);											//���� �̸��� ����ü �� �迭�� ���� 
		localCovid19[i].patient = patient[i];												//�� �ð� ������ Ȯ���� ���� ����ü �� �迭�� ���� 
	}
	for (int i = 0 ; i < 17 ; i++)															//������ Ȯ���� ���� �Խ� 
		{
			printf("%s : %d\n", localCovid19[i].local, localCovid19[i].patient);
		}
	while (true)																			//���������� ������ Ȯ���� ���� �Խ� & �����ϱ� ���� ������ �ݺ��ϵ��� �ݺ��� ���� 
	{
		char doWork[2];
		printf("Would you like to update the patient information? (y or n) ");				//Ȯ���� �� ������ �� ������ ���θ� �ľ��ϱ� ���� ���ǹ� ���� , ������ �����ϱ� ���� �Է°��� y Ȥ�� n ���� ����
		scanf("%s", doWork);
		if (strcmp(doWork, "y") == 0)														//Ȯ���� ���� ������ ���� �� �ۼ��� �Լ��� �̿��Ͽ� ���� 
		{
			updatePatient(localCovid19);
		}
		for (int i = 0 ; i < 17 ; i++)														//������ Ȯ���� ���� �Խ� 
		{
			printf("%s : %d\n", localCovid19[i].local, localCovid19[i].patient);
		}
	}
	return 0;
}



