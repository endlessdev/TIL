#include "hello.h"
#include <stdio.h>

void ListInit(List* plist)
{
	(plist->numOfData) = 0;
	(plist->curPosition) = -1;
}

void LInsert(List* plist, LData data)
{
	if (plist->numOfData >= LIST_LEN)
	{
		puts("저장이 불가능합니다");
		return;
	}

	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

int LFirst(List* plist, LData* pdata)
{
	if (plist->numOfData == 0)		// 저장된 데이터가 하나도 없다면
		return FALSE;

	(plist->curPosition) = 0;		// 참조 위치 초기화! 첫 번째 데이터의 참조를 의미!
	*pdata = plist->arr[0];			// pdata가 가리키는 공간에 데이터 저장
	
	return TRUE;
}

int LNext(List* plist, LData* pdata)
{
	if (plist->curPosition >= (plist->numOfData) - 1)		// 더 이상 참조할 데이터가 없다면
		return FALSE;

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List* plist)
{
	int rpos = plist->curPosition;		// 삭제할 데이터의 인덱스 값 참조
	int num = plist->numOfData;
	LData rdata = plist->arr[rpos];		// 삭제할 데이터를 임시로 저장

	// 삭제를 위한 데이터의 이동을 진행하는 반복문
	for (int i = rpos; i < num - 1; i++)
		plist->arr[i] = plist->arr[i + 1];

	(plist->numOfData)--;				// 데이터의 수 감소
	(plist->curPosition)--;				// 참조위치를 하나 되돌린다
	return rdata;						// 삭제된 데이터의 반환
}

int LCount(List* plist)
{
	return plist->numOfData;
}

int main()
{
	// ArrayList의 생성 및 초기화
	List list;
	int data;
	ListInit(&list);

	// 5개의 데이터 저장
	LInsert(&list, 11); LInsert(&list, 11);
	LInsert(&list, 22); LInsert(&list, 22);
	LInsert(&list, 33);

	// 저장된 데이터의 전체 출력
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &data))			// 첫 번째 데이터 조회
	{
		printf("%d ", data);

		while (LNext(&list, &data))		// 두 번재 이후의 데이터 조회
			printf("%d ", data);		
	}
	printf("\n\n");

	// 숫자 22을 탐색하여 모두 삭제
	if (LFirst(&list, &data))
	{
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data == 22)
				LRemove(&list);
		}
	}

	// 삭제 후 남은 데이터 전체 출력
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}