#include "DoublyLinkedList.h"

//노드 생성
Node* DLL_CreateNode(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->nextNode = NULL;

    return NewNode;
}

// 노드 소멸
void DLL_DestroyNode(Node* Node)
{
    free(Node);
}

// 노드 추가
void DLL_AppendNode(Node** Head, Node* NewNode)
{
    if ((*Head) == NULL)
    {
        *Head = NewNode;
    }
    else
    {
        Node* Tail = (*Head);
        while (Tail->nextNode != NULL)
        {
            Tail = Tail->nextNode;
        }

        Tail->nextNode = NewNode;
        NewNode->PrevNode = Tail;
    }
}

// 노드 삽입
void DLL_InsertAfter(Node* Current, Node* NewNode)
{
    NewNode->NextNode = Current->nextNode;
    NewNode->PrevNode = Current;

    if (Current->NextNode != NULL)
    {
        Current->NextNode->PrevNode = NewNode;
        Current->NextNode = NewNode;
    }
}

// 노드 제거
void DLL_RemoveNode(Node** Head, Node* Remove)
{
    if (*Head == Remove)
    {
        *Head = Remove->nextNode;
        if ((*Head) != NULL)
            (*Head)->PrevNode = NULL;

        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
    else
    {
        Node* Temp = Remove;

        if (Remove->PrevNode != NULL)
            Remove->PrevNode->NextNode = Temp->nextNode;
        if (Remove->NextNode != NULL)
            Remove->NextNode->PrevNode = Temp->PrevNode;

        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
}

// 노드 탐색
Node* DLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;

    while (Current != NULL && (--Location) >= 0)
    {
        Current = Current->NextNode;
    }

    return Current;
}

// 노드 개수 세기
int DLL_GetNodeCount(Node* Head)
{
    unsigned int Count = 0;
    Node* Current = Head;

    while (Current != NULL)
    {
        Current = Current->NextNode;
        Count++;
    }

    return Count;
}

void PrintNode(Node* _Node)
{
    if (_Node->PrevNode == NULL)
        printf("Prev: NULL");
    else
        printf("Prev: %d", _Node->PrevNode->Data);

    printf("Current: %d", _Node->Data);

    if (_Node->NextNode == NULL)
        printf("Next: NULL");
    else
        printf("Next: &d", _Node->NextNode->Data);
}

void PrintReverse(Node* Head)
{
    if (Head == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        Node* Current = Head;
        int Count = 0;

        while (Current->NextNode != NULL)
        {
            Count++;
            Current = Current->NextNode;
        }

        for (int i = Count; i < 0; i--)
        {
            printf("List[%d] : %d", i, Current->Data);
            Current = Current->PrevNode;
        }
    }

}