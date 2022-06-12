/*
코로나 지역 별 확진자 현황을 보여주는 프로그램이다. 
전체 지역은 크게 17지역으로 구분하였으며, 이는 질병관리본부에서 제공하는 지역 구분에 해당한다. 
지역별로 확진자 수는 매일 변화하므로 이를 바로 반영할 수 있도록 , 수정을 원할 시 직접 수정할 수 있도록 하였다.
구조체를 활용하여 지역별 확진자 수를 저장하였다.
새로운 함수를 정의하여 구조체 내 값을 변화할 수 있도록 하였다.
*/


#include <stdio.h>
#include <string.h>

typedef struct _localCovid19     //지역 별 확진자 수를 저장하기 위한 구조체 
{
	char local[17];              //지역 이름 
	int patient;				 //확진자수 
} localCovid19, *PlocalCovid19;					  

void updatePatient(localCovid19 *local19)			//지역별 확진자 수 변화를 반영하기 위한 함수 
{
	for (int i = 0 ; i < 17 ; i++)
	{
		printf("%s : ", local19[i].local);			//해당 지역 명을 출력 
		scanf("%d", &local19[i].patient);			//해당 지역의 확진자 수를 수정 
	}
	printf("------------------------------------\n");    //변경된 이후 기존에 입력한 내용과 게시되는 내용을 구별해주기 위해 사용 
}

int main(void)
{
	localCovid19 localCovid19[25];						//구조체를 이용하여 정의 
	char *local[17] = {"Seoul", "gyeonggi-do", "Gangwon-do", "Chungcheongbuk-do", "Chungcheongnam-do", "Jeollabuk-do", "Jeollanam-do", "Gyeongsangbuk-do", 
						"Gyeongsangnam-do", "Incheon", "Sejong", "Daejeon", "Dae-gu", "Gwangju", "Ulsan", "Busan", "Jeju"};			//확진자 수를 제공하는 지역 
	int patient[17] = {3637088, 4950835, 519731, 557267, 717598, 601833, 597808, 783967, 1095230, 1076537, 139483, 513517, 765295, 534681, 381010, 1098165, 236840};   //지역별 확진자수 반영 시각 : 2022.06.11.23:00 
	for (int i = 0 ; i < 17 ; i++)
	{
		strcpy(localCovid19[i].local, local[i]);											//지역 이름을 구조체 내 배열에 저장 
		localCovid19[i].patient = patient[i];												//현 시각 지역별 확진자 수를 구조체 내 배열에 저장 
	}
	for (int i = 0 ; i < 17 ; i++)															//지역볗 확진자 수를 게시 
		{
			printf("%s : %d\n", localCovid19[i].local, localCovid19[i].patient);
		}
	while (true)																			//지속적으로 지역별 확진자 수를 게시 & 갱신하기 위한 무한히 반복하도록 반복문 생성 
	{
		char doWork[2];
		printf("Would you like to update the patient information? (y or n) ");				//확진자 수 수정을 할 것인지 여부를 파악하기 위한 조건문 생성 , 오류를 방지하기 위해 입력값을 y 혹은 n 으로 한정
		scanf("%s", doWork);
		if (strcmp(doWork, "y") == 0)														//확진자 수를 수정을 원할 시 작성한 함수를 이용하여 수정 
		{
			updatePatient(localCovid19);
		}
		for (int i = 0 ; i < 17 ; i++)														//지역볗 확진자 수를 게시 
		{
			printf("%s : %d\n", localCovid19[i].local, localCovid19[i].patient);
		}
	}
	return 0;
}



