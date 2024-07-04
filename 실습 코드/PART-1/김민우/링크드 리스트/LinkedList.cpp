#include "LinkedList.h"

 // 노드 생성
Node* SLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->NextNode = NULL;

	return NewNode;
}

// 노드 소멸
void SLL_DestroyNode(Node* Node)
{
	free(Node);
}

// 노드 추가
void SLL_AppendNode(Node** Head, Node* NewNode)
{
	// 헤드 노드가 NULL이라면 새로운 노드가 Head가 된다.
	if ((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		Node* Tail = (*Head);
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}

		Tail->NextNode = NewNode;
	}
}

// 노드 삽입
void SLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

// 노드 앞에 삽입
void SLL_InsertBefore(Node** Head, Node* Current, Node* NewHead)
{
	if ((*Head) == Current)
	{
		NewHead->NextNode = (*Head);
		(*Head) = NewHead;
	}
	else
	{
		Node* TmpHead = (*Head);
		while (TmpHead != NULL && TmpHead->NextNode != Current) {
			TmpHead = TmpHead->NextNode;
		}

		if (TmpHead != NULL) {
			NewHead->NextNode = TmpHead->NextNode;
			TmpHead->NextNode = NewHead;
		}
	}
}

void SLL_InsertNewHead(Node** Head, Node* NewHead)
{
	if (Head == NULL)
	{
		(*Head) = NewHead;
	}
	else
	{
		NewHead->NextNode = (*Head);
		(*Head) = NewHead;
	}
}

// 노드 제거
void SLL_RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == Remove)
	{
		*Head = Remove->NextNode;

	}
	else
	{
		Node* Current = *Head;
		while (Current != NULL && Current->NextNode != Remove)
		{
			Current = Current->NextNode;
		}

		if (Current != NULL)
			Current->NextNode = Remove->NextNode;
	}
}

Node* SLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

// 노드 개수 세기
int SLL_GetNodeCount(Node* Head)
{
	int Count = 0;
	Node* Current = Head;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;
	}

	return Count;
}

// 링크드 리스트의 모든 노드 한번에 제거
void SLL_DestroyAllNodes(Node** List)
{
	Node* Head = (*List);
	while (Head->NextNode != NULL)
	{
		Node* tmp = Head;
		Head = Head->NextNode;
		free(tmp);
	}
}