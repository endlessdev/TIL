#include "PriorityQueue.h"
#include "SimpleHeap.h"
#include <stdio.h>

int DataPriorityComp(char ch1, char ch2){
        return ch2-ch1;
    }
    
int main(){
    PQueue pq;
    PQueueInit(&pq, DataPriorityComp);
    
    PEnqueue(&pq, 'A');
    PEnqueue(&pq, 'B');
    PEnqueue(&pq, 'C');
    printf("%c \n", PDequeue(&pq));
    
    PEnqueue(&pq, 'A');
    PEnqueue(&pq, 'B');
    PEnqueue(&pq, 'C');
    printf("%c \n", PDequeue(&pq));
    
    while(!PQIsEmpty(&pq))
        printf("%c \n", PDequeue(&pq));
    
    return 0;
}

void PQueueInit(PQueue * ppq, PriorityComp pc){
    HeapInit(ppq, pc);
}

int PQIsEmpty(PQueue * ppq){
    return HIsEmpty(ppq);
}

void PEnqueue(PQueue * ppq, PQData data){
    HInsert(ppq, data);
}

PQData PDequeue(PQueue * ppq){
    return HDelete(ppq);
}


void HeapInit(Heap * ph, PriorityComp * pc){
    ph->numOfData = 0;
    ph->comp = pc;
}


int HIsEmpty(Heap * ph){
    if(ph->numOfData == 0){
        return TRUE;
    } else {
        return FALSE;
    }
}

int GetParentIdx(int idx){
    return idx/2;
}

int GetLChildIdx(int idx){
    return idx*2;
}

int GetRChildIdx(int idx){
    return (idx*2)+1;
}

/**
 * 
 * idx : 이 인덱스를 가진 노드 두 자식 노드들 중에서 제일 Priorty 높은걸 반환
 **/
int GetHiPriChildIdx(Heap * ph, int idx){
    if(GetLChildIdx(idx) > ph->numOfData){
        // 둘 다 없다는 소리
        return 0;
    } else if(GetLChildIdx(idx) == ph->numOfData) {
        // Right 가 없다는 소리
        return GetLChildIdx(idx);
    } else {
        // Right 가 있을때.
        
        if(ph->comp(ph->heapArr[GetLChildIdx(idx)], ph->heapArr[GetRChildIdx(idx)]) < 0){
            return GetRChildIdx(idx);
        } else {
            return GetLChildIdx(idx);
        }
    }
}

void HInsert(Heap * ph, HData data){
    int newIdx = ph->numOfData+1;
    
    // 제일 첫번째 만나지 않을떄까지 존나 도는거야
    while(newIdx !=1){
        if(ph->comp(data, ph->heapArr[GetParentIdx(newIdx)]) > 0){
            ph->heapArr[newIdx] = ph->heapArr[GetParentIdx(newIdx)];
            newIdx = GetParentIdx(newIdx);
        } else {
            break;
        }
    }
    
    ph->heapArr[newIdx] = data;
    ph->numOfData += 1;
}

// 힙에서 데이터를 삭제하는데,
// 잘 삭제가 됬으면 그 값 반환
HData HDelete(Heap * ph){
    HData retData = ph->heapArr[1];
    HData lastElem  = ph->heapArr[ph->numOfData];
    
    int parentIdx = 1;
    int childIdx;
    
    while(childIdx = GetHiPriChildIdx(ph, parentIdx)){
        if(ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
            break;
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;
    }
    
    ph->heapArr[parentIdx] = lastElem;
    ph->numOfData -= 1;
    return retData;
}