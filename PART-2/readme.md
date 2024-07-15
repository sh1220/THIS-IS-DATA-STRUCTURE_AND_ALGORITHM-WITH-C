# 2장 스택


## 스택의 개념

- 가장 **마지막에 들어간 데이터가 제일 먼저 나오고(LIFO Last In-First Out), 가장 먼저 들어간 데이터(FILO: First In Last Out)는 가장 나중에 나온다.**

### **스택 예제**

- 자동 메모리가 스택을 기반으로 동작, 거의 대부분의 네트워크 프로토콜도 스택을 기반으로 구성됨

### 스택 ADT의 주요 기능

- 삽입 연산: 스택 위에 새로운 노드(요소)를 쌓는 일

![Untitled](https://github.com/user-attachments/assets/6e4289bc-a16e-475f-97ae-c315db59193e)


### 

- 제거 연산: 스택에서 최상위 노드를 걷어 내는 일

![Untitled 1](https://github.com/user-attachments/assets/997f1b7e-a6ec-4308-afcd-bb1e8f36bb1a)


## 배열로 구현하는 스택

- 배열을 이용한 스택은 **용량을 동적으로 변경하는 비용이 크지만**, 구현이 간단하다.
- 각 노드를 동적으로 생성하고 제거하는 대신, 스택 생성 초기에 사용자가 부여한 용량만큼의 노드를 한꺼번에 생성한다. (최상위 노드의 위치를 나타내는 변수를 두고 삽입, 제거 연산 수행)

### 배열 기반 스택과 스택의 노드 표현

- 노드가 존재하는 위치는 배열의 인덱스로 알수 있기 때문에 링크드 리스트의 포인터가 필요 없다.
- **용량, 최상위 노드의 위치, 노드 배열**

```cpp
typedef struct tagArrayStack
{
	int Capacity;
	int Top;
	Node* Nodes;
} ArrayStack;
```

![Untitled 2](https://github.com/user-attachments/assets/70d46af3-036a-49aa-9e29-15d5f82d9455)


### 스택 및 노드 생성/소멸 연산

- 스택을 생성하고 노드를 받아들일 공간을 준비하는 `AS_CreateStack()` 함수

```cpp
void AS_CreateStack(ArrayStack** Stack, int Capacity)
{
	// 스택을 힙에 생성
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
	
	// 입력된 Capacity만큼의 노드를 힙에 생성
	(*Stack)->Nodes = (Nodes)malloc(sizeof(Node)*Capacity);
	
	// 초기화
	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = -1;
	
```

### Top을 0이 아닌 -1로 초기화하는 이유?

<aside>
💻 첫 번째 배열 요소를 가리키는 첨자가 0이므로, 비어있는 스택의 초상위 위치가 이보다 작아야 한다.

</aside>

- 사용이 끝난 힙을 반드시 정리해줘야 하기 때문에, 스택 내의 노드와 스택을 삭제하는 임무

```cpp
void AS_DestroyStack(ArrayStack* Stack)
{
	// 노드를 힙에서 해제
	free(Stack->Nodes);
	
	// 스택을 힙에서 해제
	free(Stack);
]
```

### 노드 삽입 연산

- 삽입 연산은 최상위 노드의 인덱스에서 1을 더한 곳에 새 노드를 입력하는 함수

```cpp
void AS_Push(ArrayStack* Stack, ElementType Data)
{
	Stack->Top++;
	Stack->Nodes[Stack->Top].Data = Data;
}
```

### 노드 제거 연산

- 제거 연산은 최상위 노드의 인덱스(Top) 값을 1만큼 낮추도록 구현하는 함수
- **최상위 노드에 있던 데이터를 호출자에게 반환해야 한다.**

```cpp
ElementType AS_Pop(ArrayStack* Stack)
{
	int Position = Stack->Top--;
	return Stack->Nodes[Position].Data;
}
```

## 링크드 리스트로 구현하는 스택

- 링크드 리스트는 스택 용량에 제한을 두지 않아도 된다.

```cpp
typedef struct tagNode
{
	char *Data;
	struct tagNode* NextNode;
} Node;
```

- Data 필드가 `char*` 형으로 선언되어, 문자열이 저장된 주소만 담을 수 있다.
- 문자열은 자동 메모리(스택)이 아닌, 자유 저장소(힙)에 저장된다.

![Untitled 3](https://github.com/user-attachments/assets/12482d47-6b84-4c16-bd1c-4ad43184f2ed)


### 링크드 리스트 스택의 구조체

```cpp
typedef struct tagLinkedListStack
{
	Node* List;
	Node* Top;
} LinkedListStack;
```

- `List` 포인터는 데이터를 담는 링크드 리스트를 가리킨다.
- `Top` 포인터는 링크드 리스트의 테일을 가리킨다.

![Untitled 4](https://github.com/user-attachments/assets/a32e76d2-a290-424b-977b-fc511e511ffe)


### 스택 생성/소멸 연산

- 링크드 리스트 기반이므로 용량 제한에서 자유롭다.

```cpp
void LLS_CreateStack(LinkedListStack** Stack)
{
	(*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;
}
```

- 메모리를 해제하는 함수

```cpp
void LLS_DestroyStack(LinkedListStack* Stack)
{
	while (!LLS_IsEmpty(Stack))
	{
		Node* Popped = LLS_Pop(Stack);
		LLS_DestroyNode(Popped);
	}
	
	free(Stack);
}
```

### 노드 생성/소멸 연산

- `malloc()` 함수가 Node 구조체를 할당하기 위해 한 번, `Data` 필드를 할당하기 위해 한 번 호출

```cpp
Node* LLS_CreateNode( char* NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(strlen(NewData) + 1);
	
	strcpy(NewNode->Data, NewData);
	
	NewNode->NextNode = NULL;
	
	return NewNode;
}
	
```

- 노드를 메모리에서 제거하는 `LLS_DestroyNode()` 함수

```cpp
void LLS_DestroyNode(Node* _Node)
{
	free(_Node->Data);
	free(_Node);
}
```

### 노드 삽입 연산

- 삽입 연산은 스택의 최상위 노드의 `Top` 에 새 노드를 얹도록 구현하면 된다.
- 새로운 최상위 노드의 주소를 `LinkedListStack` 구조체의 `Top` 필드에 등록한다.

```cpp
void LLS_Push(LinkedListStack* Stack, Node* NewNode)
{
	if (Stack->List == NULL)
	{
		Stack->List = NewNode;
	}
	else
	{
		Stack->Top->NextNode = NewNode;
	}
	
	Stack->Top = NewNode;
}
```

### 노드 제거 연산

1. 현재 `Top` 의 주소를 다른 포인터에 복사한다.
2. 새로운 최상위 노드의 이전 노드를 찾는다.
3. `LinkedListStack` 구조체의 `Top` 필드에 새로운 최상위 노드의 주소를 등록한다.
4. `단계 1` 에서 포인터에 저장했던 예전 최상위 노드의 주소를 반환한다.

```cpp
Node* LLS_Pop(LinkedListStack* Stack)
{
	Node* TopNode = Stack->Top;
	
	if(Stack->List == Stack->Top)
	{
			Stack->List = NULL;
			Stack->Top = NULL;
	}
	else
	{
			// Top 아래에 있던 노드를 새로운 CurrentTop에 저장
			Node* CurrentTop = Stack->List;
			while (CurrentTop != NULL && CurrentTop->NextNode != Stack->Top)
			{
				CurrentTop = CurrentTop->NextNode;
			}
		
			// CurrentTop을 Top에 저장
			Stack->Top = CurrentTop;
			Stack->Top->NextNode = NULL;
   }
   
   return TopNode;
 }
```
