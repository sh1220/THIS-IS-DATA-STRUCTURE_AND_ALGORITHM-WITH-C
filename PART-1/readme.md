## 리스트의 개념

- 데이터를 담는 노드 목록에서 첫 번째 노드를 헤드(head)라고 부르고, 마지막 노드를 테일(tail)이라 부른다. 리스트의 길이는 **헤드부터 테일까지 이르는 노드 개수**

<img width="300" alt="Untitled 1" src="https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/a6b4b8a4-34d1-4d12-a74e-c3f2528bf219">

### 리스트와 배열의 비교

- 배열은 생성하는 시점에 반드시 **배열의 크기를 지정해줘야 하고, 생성 후에 크기를 변경할 수 없다.**
- 배열처럼 데이터 집합 보관 기능을 가지면서도, **배열과 달리 유연하게 크기를 바꿀 수 있는 자료구조**

### 링크드 리스트

- 링크드 리스트는 **노드를 연결해서 만든 리스트**라고 해서 붙여진 이름이다.
- 링크드 리스트의 노드는 **데이터를 보관하는 필드, 다음 노드와 연결 고리 역할을 하는 포인터**로 이루어진다.

<img width="500" alt="Untitled 2" src="https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/ad45921d-4396-4f4f-9221-3e8d62eb5371">

- 리스트의 첫 번째 노드를 **헤드**라고 하고, 마지막 노드를 **테일**이라고 함.

### 링크드 리스트의 주요 연산

- 노드 생성(CreateNode)/소멸(DestroyNode)
- 노드 추가(AppendNode)
- 노드 탐색(GetNodeAt)
- 노드 삭제(RemoveNode)
- 노드 삽입(InsertAfter, InsertNewHead)

<aside>
💡 노드 생성/소멸, 추가, 삭제, 삽입은 링크드 리스트 자료를 구축하기 위한 연산이고, 탐색은 구축된 링크드 리스트의 데이터를 활용하기 위한 연산이다.

</aside>

## 0.3.3 메모리 레이아웃 복습

<img width="500" alt="Untitled 3" src="https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/a77409e6-eedc-4112-8e1c-4345f4dd2bd3">

- C 언어로 작성한 코드를 컴파일하면, 실행 파일이 생성 → 그 파일을 실행하면, 운영체제는 해당 실행파일을 **바탕으로 프로세스 생성 후** 이 프로세스에 **스택, 힙, 데이터, 텍스트 영역으로 이루어진 메모리를 할당합니다.**


<img width="497" alt="Untitled 4" src="https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/40823c22-cac8-4d6d-83b2-d4ad975e11dd">

- 텍스트(Text), 데이터(Data) 영역은 실행 파일에서 읽어들인 정보를 기록하는 공간이다.
- 텍스트 영역에서는 CPU가 실행할 코드가 적재되고, 데이터 부분에는 **전역 변수, 정적 변수** 저장
- 데이터 영역은 **정적 메모리** 라고도 부른다.
- 힙, 스택은 각각 자유 저장소, 자동 메모리라는 별명을 가짐.

### 0.3.4 스택에서 데이터를 다루는 방법

<img width="437" alt="Untitled 5" src="https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/66ace541-d3ef-4f45-af31-f430a67ec29b">

- 스택은 프로그래머가 신경 쓰지 않아도 자동으로 메모리를 해제함.

### 0.3.5. 힙에서 데이터를 다루는 방법

- 힙(Heap)은 **자유 저장소**라는 별명을 가집니다. 자유 저장소는 자동 메모리와 달리 프로그래머가 직접 메모리를 관리하는 메모리 영역이다.
- 프로그래머는 힙 위에 자유롭게 메모리를 할당해서 사용할 수 있지만, 그 메모리를 안전하게 해제하는 것도 프로그래머가 책임지고 해야 할 일
- C언어에서는 메모리를 할당할 때, malloc(), calloc() 사용하고, 해제할 때는 free() 함수를 사용한다.
- 프로그래머가 **인수로 입력한 크기만큼의 메모리를 할당해서, 힙에 그 주소를 반환한다.**

<img width="427" alt="Untitled 6" src="https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/439ca75f-29d2-4260-9548-d494d5d58f85">

- 이 코드를 실행하면 다음 그림과 같이 **malloc()이 Point의 크기만큼 메모리를 힙에 할당하고, 스택에 위치한 ptr**이 그 메모리 주소를 가리키게 된다.

<img width="290" alt="Untitled 7" src="https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/50d82994-8816-4da6-a411-ca6255cecc17">

- **ptr은 자신이 태어난 코드 블록이 끝나는 곳에서 스택으로부터 제거되지만,** malloc()이 할당한 공간은 힙의 한 공간을 차지한 채 남아있게 된다. → **메모리 누수 발생!**

<img width="361" alt="Untitled 8" src="https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/efcf6424-37ad-47a3-b27a-ad163e316f5a">

```jsx
free(ptr);
```

- 이 코드를 실행하면 ptr이 가리키는 공간을 해제해서 메모리 누수를 막을 수 있다.

<img width="355" alt="Untitled 9" src="https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/e9cbc8ce-62b4-4ad1-8744-f3c1331f1c7c">

## 노드 생성/소멸 연산

- 링크드 리스트의 노드는 자동 메모리와 자유 저장소 중 어느 곳에 생성하면 좋을까?

```cpp
Node* SLL_CreateNode( ElementType NewData ) 
{
	Node NewNode; // 자동 메모리에 새로운 노드 생성
	NewNode.Data = newData;
	NewNode.NextNode = NULL;
	
	return &NewNode; // NewNode가 생성된 메모리의 주소를 반환
} // 함수가 종료되면서 NewNode는 자동 메모리에서 제거된다.

Node* MyNode = SLL_CreateNode( 117 ); // MyNode는 할당하지 않은 메모리를 가리킨다.
```

- **SLL_CreateNode()** 함수가 가장 먼저 지역 변수 **NewNode**를 자동 메모리(스택)에 생성하고 NewData의 Data, NextNode 필드를 초기화한다.
- 그리고 함수 끝에서 NewNode의 주소를 반환한다.
- 문제점: 자동 메모리에 의해 제거된 **NewNode가 ‘존재했던’ 메모리의 주소를 담고 있습니다. 이미 사라져버린 NewNode의 주소를 담고 있는 MyNode 포인터에 의해 예기치 않은 동작 야기 가능**

**→ 자유 저장소를 활용하자.**

```cpp
void* malloc( size_t size ); 
```

- 반환 형식이 void*, malloc() 사용, malloc()의 매개 변수는 size**(malloc()이 할당해야 하는 메모리의 크기), 매개 변수의 형식은 size_t인데, sizeof 연산자의 반환형이기도 한, size_t(typedef로 선언한 unsigned int의 별칭)**

- malloc() 함수를 사용하여 노드를 자유 저장소에 생성하는 예제

```cpp
Node* NewNode = (Node*)malloc(sizeof(Node));
```

## 노드 생성 연산 코드

```cpp
Node* SLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = NewData; // 데이터를 저장한다.
	NewNode->NextNode = NULL; // 다음 노드에 대한 포인터는 NULL로 초기화한다.
	
	return NewNode; // 노드의 주소를 반환한다.
}
```

## 소멸 코드

```cpp
void SLL_DestroyNode(Node* Node)
{
	free(Node);
}
```

## 노드 추가 연산

- 노드 추가는 링크드 리스트의 테일 노드 뒤에 새로운 노드를 만들어 연결하는 연산이다. 꼬리를 덧붙이는 것이다.

![Untitled 10](https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/432f606c-4ec8-4b0d-99a0-c50f3d6800ea)

- 자유 저장소에 노드를 생성한 다음, 새로 생성한 노드의 주소를 테일의 NextNode 포인터에 저장하면 된다. 노드 추가 연산을 처리하는 SLL_AppendNode() 함수 구현

```cpp
void SLL_AppendNode(Node** Head, Node* NewNode)
{
	// 헤드 노드가 NULL이라면 새로운 노드가 Head가 된다.
	if ( (*Head) == NULL )
	{
		*Head = NewNode;
	}
	else
	{
		// 테일을 찾아 NewNode를 연결한다.
		Node* Tail = (*Head);
		while ( Tail->NextNode != NULL )
		{
			Tail = Tail->NextNode;
		}
		
		Tail->NextNode = NewNode;
	}
}
```

## 노드 탐색 연산

### 왜 ‘*’가 아니고 ‘**’인가요?

```java
Node* List = NULL;
Node* NewNode = NULL;
NewNode = SLL_CreateNode( 117 );
SLL_AppendNode( List, NewNode );

```

- List와 NewNode 선언 시, 다음과 같이 자동 메모리에 두 포인터 변수가 생성됨
![Untitled 11](https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/26b8b94d-4533-4608-9ccc-98613bf2bdaa)

- NewNode = SLL_CreateNode ( 117 ); 문장이 실행되면 자유 저장소에 117을 가진 노드가 생성되고, NewNode가 그 주소를 가리킴

![Untitled 12](https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/90338371-0c6d-4aa4-92eb-d680d033937b)

- SLL_AppendNode() 함수를 호출할 떄, SLL_AppendNode()의 매개 변수들(_Head 와 _NewNode)이 자동 메모리에 생성되고, List는 _Head에, NewNode는 _NewNode에 **자신이 가리키는 메모리의 주소**를 ‘복사’해 넣습니다.

![Untitled 13](https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/fa04b4da-88ea-4420-a19d-ce3a4db42f48)

- SLL_AppendNode() 함수를 호출할 때, List 포인터가 담고 있는 ‘주소값’만 _Head에 복사되고, 정작 List 포인터 변수의 주소는 전달되지 않음.
- SLL_AppendNode() 함수가 호출된 후에는 매개 변수 _Head와 _NewNode는 자동 메모리에 의해 제거되고, List는 여전히 NULL인 채로 남는다.
- SLL_AppendNode() 함수의 첫 번째 매개 변수를 Node**로 선언하면, Head 포인터 자신의 주소를 넘길 수 있게 된다. _Head 포인터는 List 포인터 변수의 ‘주소’를 가리키고, 이 주소를 이용하여 List가 NewNode의 주소를 가리키게 하는 것이다.

<img width="304" alt="Untitled" src="https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/60629e4c-ae38-4857-b1a6-d6d69ce195b7">

---

- 링크드 리스트는 헤드부터 시작해서 다음 노드에 대한 포인터를 징검다리 삼아 차근차근 노드의 개수만큼 거쳐야만 원하는 요소에 접근할 수 있다. **(찾고자 하는 요소가 N번째에 있다면 N-1개의 노드를 거쳐야만 한다.)**

```java
Node* SLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;
	
	while ( Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}
	
	return Current;
}
```

## 노드 삭제 연산

- 삭제하고자 하는 노드를 찾은 후 해당 노드의 다음 노드를 이전 노드의 NextNode 포인터에 연결하면 그 노드를 삭제할 수 있다.

![Untitled 14](https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/d828900d-43ab-4c2a-83fe-3edac02dd81d)


```java
void SLL_RemoveNode(Node** Head, Node* Remove)
{
	if ( *Head == Remove)
	{
		*Head = Remove->NextNode;
	}
	else 
	{
		Node* Current = *Head;
		while ( Current != NULL && Current->NextNode != Remove)
		{
			Current = Current->NextNode;
		}
		
		if (Current != NULL)
		
```

## 노드 삽입 연산

- 노드 삽입은 노드와 노드 사이에 새로운 노드를 끼워 넣는 연산이다.

![Untitled 15](https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/7df8aba8-0c8a-4153-b438-4568b4d34679)


```java
void SLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}
```

## 노드 개수 세기 연산

- 노드의 개수를 세는 연산(리스트의 길이를 재는 연산)

```java
int SLL_GetNodeCount(Node* Head)
{
	int Count = 0;
	Node* Current = Head;
	
	while ( Current != NULL )
	{
		Current = Current->NextNode;
		Count++;
	}
	
	return Count;
}
```

## 링크드 리스트의 장단점

**[단점]**

- 다음 노드를 가리키려는 포인터 때문에 각 노드 마다 추가적인 메모리(32bits / 4bytes, 64bits / 8bytes) 가 필요하다
- 특정 위치에 있는 노드에 접근하기 위한 비용이 크며, 접근하기까지 시간도 많이 소요
- **n번째 위치에 있는 노드에 접근하려면 n회의 노드 탐색 루프를 실행해야 해당 위치의 노드에 접근 가능**

**[장점]**

- 새로운 노드의 추가, 삽입, 삭제가 쉽고 빠릅니다. 배열은 새로운 요소를 삽입하거나, 기존 요소를 제거하기가 어려움
- 현재 노드의 다음 노드를 얻어오는 연산에 대해서 비용이 발생하지 않는다.

<aside>
💻 **링크드 리스트는 레코드의 추가, 삽입, 삭제가 잦지만 조회는 드문곳(데이터베이스에서 조회해온 레코드를 순차적으로 다루는데 제격)!**

</aside>

## 1.3 더블 링크드 리스트

![Untitled 16](https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/7a322700-b8c1-4da9-bc38-2f4377aceffc)


- 더블 링크드 리스트의 노드는 이전 노드, 다음 노드를 가리키는 포인터를 갖고 있다.

```java
Typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
	struct tagNode* PrevNode;
	struct tagNode* NextNode;
} Node;

```

## 노드 생성/소멸 연산

- 생성한 노드의 PrevNode에 NULL을 대입하여 초기화하는 부분만 추가됨

```cpp
Node* DLL_CreateNode( ElementType NewData )
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	
	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;
	
	return NewNode;
}
```

- 노드를 자유 저장소에서 제거하는 함수

```cpp
void DLL_DestroyNode( Node* Node )
{
	free(Node);
}
```

## 노드 추가 연산

- 더블 링크드 리스트에서는 새로운 테일의 PrevNode 포인터도 기존 테일의 주소를 가리키도록 해야 함

![Untitled 17](https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/8f211066-f6f7-4193-a33a-e44050538965)


```cpp
void DLL_AppendNode( Node** Head, Node* NewNode )
{
	if ( (*Head) == NULL )
	{
		*Head = NewNode;
	}
	else 
	{
		Node* Tail = (*Head);
		while ( Tail->NextNode != NULL )
		{
			Tail = Tail->NextNode;
		}
		
		Tail->NextNode = NewNode;
		NewNode->PrevNode = Tail;
	}
}
```

## 노드 삭제 연산

- 삭제할 노드의 N**extNode 포인터가 가리키던 노드를 이전 노드의 NextNode 포인터가 가리키게 바꾼다.**
- 삭제할 노드의 **PrevNode 포인터가 가리키던 노드를 다음 노드의 PrevNode 포인터가 가리키게 바꾼다.**
- NextNode, PrevNode를 NULL로 초기화

![Untitled 18](https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/2bd6a2c1-351a-455b-a5c9-eb0305fea2c3)


```cpp
Void DLL_RemoveNode( Node** Head, Node* Remove )
{
	if ( *Head == Remove )
	{
			*Head = Remove->NextNode;
			if ( (*Head) != NULL )
				(*Head)->PrevNode = NULL;
			
			Remove->PrevNode = NULL;
			Remove->NextNode = NULL;
	}
	else
	{
		Node* Temp = Remove;
		
		if (Remove->PrevNode != NULL)
			Remove->PrevNode->NextNode = Temp->NextNode;
		
		if (Remove->NextNode != NULL)
			Remove->NextNode->PrevNode = Temp->PrevNode;
		
		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
}
		
```

## 노드 삽입 연산

![Untitled 19](https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/4e24cfca-7052-4e80-a91b-0afac166cd9d)


```cpp
void DLL_InsertAfter( Node* Current, Node* NewNode )
{
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;
	
	if (Current->NextNode != NULL )
	{
		Current->NextNode->PrevNode = NewNode;
		Current->NextNode = NewNode;
	}
}
```

## 환형 링크드 리스트

![Untitled 20](https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/86e1dd0a-3405-4bf1-969c-d5a9af38d952)


**[환형 링크드 리스트의 장점]**

- **시작을 알면 끝을 알 수 있고, 끝을 알면 시작을 알 수 있다**
- 헤드의 이전 노드가 테일이 되고, 테일의 다음 노드가 헤드가 된다.
- **테일에 접근하는 비용이 거의 없는 것이다 다름없을 정도로 작아진다.**
- **DLL_AppendNode() 함수 성능 개선, 뒤에서부터 노드를 찾아나가는 노드 탐색 루틴 구현**

<aside>
💻 1. 테일은 헤드의 ‘이전 노드’이다.
2. 헤드는 테일의 ‘다음 노드’이다.

</aside>

## 노드 추가 연산

- **새로운 노드는 헤드가 되고, 헤드의 이전 노드는 헤드가 되며, 헤드의 다음 노드 역시 헤드 자신이 된다.**

![Untitled 21](https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/90360dc0-25b6-4732-8521-8d421d25c5b5)


- 리스트가 비어 있지 않은 경우 **‘테일과 헤드 사이에 새 노드를 삽입한다.’**

```cpp
void CDLL_AppendNode(Node** Head, Node* NewNode)
{
	 if ( (*Head) == NULL )
	 {
		 *Head = NewNode;
		 (*Head)->NextNode = *Head;
		 (*Head)->PrevNode = *Head;
		}
		else
		{
			// 테일과 헤드 사이에 NewNode를 삽입한다.
			Node* Tail = (*Head)->PrevNode;
			
			Tail->NextNode->PrevNode = NewNode;
			Tail->NextNode = NewNode;
			
			NewNode->NextNode = (*Head);
			NewNode->PrevNode = Tail;
		}
	}
```

## 노드 삭제 연산

```cpp
void CDLL_RemoveNode(Node** Head, Node* Remove)
{
	if ( *Head == Remove )
	{
		**(*Head)->PrevNode**->NextNode = Remove->NextNode;
		(*Head)->NextNode->PrevNode = Remove->PrevNode;
		
		*Head = Remove->NextNode;
		
		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
	else
	{
		Remove->PrevNode->NextNode = Remove->NextNode;
		Remove->NextNode->PrevNode = Remove->PrevNode;
		
		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
}
```
