/**
 * 
 * 힙은 완전 이진트리이다.
 * 힙의 구현은 배열을 기반으로 하며 인덱스가 0인 요소는 비워둔다.
 * 따라서 힙에 저장된 노드의 개수와 마지막 노드의 고유번호는 일치한다.
 * 노드의 고유번호가 노드가 저장되는 배열의 인덱스값이 된다.
 * 우선순위를 나타내는 정수값이 작을수록 높은 우선순위를 나타낸다고 가정한다.
 * 
 **/

#ifndef __SIMPLE_HEAP_H__
#define __SIMPLE_HEAP_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char HData;
typedef int Priority;
typedef int PriorityComp(HData d1, HData d2);

typedef struct _heap{
    int numOfData;
    HData heapArr[HEAP_LEN];
    PriorityComp * comp;

} Heap;

// 힙 초기화
void HeapInit(Heap * ph, PriorityComp * pc);

// 힙 비어있는지 확인하는 함수
int HIsEmpty(Heap * ph);

// 힙 말단노드 추가
void HInsert(Heap * ph, HData data);

// 루트노드 삭제
HData HDelete(Heap * ph);

#endif

