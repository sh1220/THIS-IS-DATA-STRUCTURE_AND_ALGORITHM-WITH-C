### 리스트의 개념

- 데이터를 담는 노드 목록에서 첫 번째 노드를 헤드(head)라고 부르고, 마지막 노드를 테일(tail)이라 부른다. 리스트의 길이는 **헤드부터 테일까지 이르는 노드 개수**

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/39b7c1c6-2541-4f60-b63f-df648981b3e5/1adbda38-c6f5-413c-bc6b-93f265fd4f10/Untitled.png)

### 리스트와 배열의 비교

- 배열은 생성하는 시점에 반드시 **배열의 크기를 지정해줘야 하고, 생성 후에 크기를 변경할 수 없다.**
- 배열처럼 데이터 집합 보관 기능을 가지면서도, **배열과 달리 유연하게 크기를 바꿀 수 있는 자료구조**

### 링크드 리스트

- 링크드 리스트는 **노드를 연결해서 만든 리스트**라고 해서 붙여진 이름이다.
- 링크드 리스트의 노드는 **데이터를 보관하는 필드, 다음 노드와 연결 고리 역할을 하는 포인터**로 이루어진다.

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/39b7c1c6-2541-4f60-b63f-df648981b3e5/b74f86b3-8024-46c8-a352-472b9793b098/Untitled.png)

- 리스트의 첫 번째 노드를 **헤드**라고 하고, 마지막 노드를 **테일**이라고 함.

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/39b7c1c6-2541-4f60-b63f-df648981b3e5/04e12f43-334e-44d8-8292-43925cfa485f/Untitled.png)

### 링크드 리스트의 주요 연산

- 노드 생성(CreateNode)/소멸(DestroyNode)
- 노드 추가(AppendNode)
- 노드 탐색(GetNodeAt)
- 노드 삭제(RemoveNode)
- 노드 삽입(InsertAfter, InsertNewHead)

<aside>
💡 노드 생성/소멸, 추가, 삭제, 삽입은 링크드 리스트 자료를 구축하기 위한 연산이고, 탐색은 구축된 링크드 리스트의 데이터를 활용하기 위한 연산이다.

</aside>

## 노드 생성/소멸 연산

### 0.3.3 메모리 레이아웃 복습

- C 언어로 작성한 코드를 컴파일하면, 실행 파일이 생성 → 그 파일을 실행하면, 운영체제는 해당 실행파일을 **바탕으로 프로세스 생성 후** 이 프로세스에 **스택, 힙, 데이터, 텍스트 영역으로 이루어진 메모리를 할당합니다.**

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/39b7c1c6-2541-4f60-b63f-df648981b3e5/7d054cb2-4f6f-49b3-befd-6a0f28523e83/Untitled.png)

- 텍스트(Text), 데이터(Data) 영역은 실행 파일에서 읽어들인 정보를 기록하는 공간이다.
- 텍스트 영역에서는 CPU가 실행할 코드가 적재되고, 데이터 부분에는 **전역 변수, 정적 변수** 저장
- 데이터 영역은 **정적 메모리** 라고도 부른다.
- 힙, 스택은 각각 자유 저장소, 자동 메모리라는 별명을 가짐.

### 0.3.4 스택에서 데이터를 다루는 방법

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/39b7c1c6-2541-4f60-b63f-df648981b3e5/52ada4b4-0840-4a75-bdea-6b6beaf6c599/Untitled.png)

- 스택은 프로그래머가 신경 쓰지 않아도 자동으로 메모리를 해제함.

### 0.3.5. 힙에서 데이터를 다루는 방법

- 힙(Heap)은 **자유 저장소**라는 별명을 가집니다. 자유 저장소는 자동 메모리와 달리 프로그래머가 직접 메모리를 관리하는 메모리 영역이다.
- 프로그래머는 힙 위에 자유롭게 메모리를 할당해서 사용할 수 있지만, 그 메모리를 안전하게 해제하는 것도 프로그래머가 책임지고 해야 할 일
- C언어에서는 메모리를 할당할 때, malloc(), calloc() 사용하고, 해제할 때는 free() 함수를 사용한다.
- 프로그래머가 **인수로 입력한 크기만큼의 메모리를 할당해서, 힙에 그 주소를 반환한다.**

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/39b7c1c6-2541-4f60-b63f-df648981b3e5/882a5f52-cb3a-4333-a37c-d31ee459603a/Untitled.png)

- 이 코드를 실행하면 다음 그림과 같이 **malloc()이 Point의 크기만큼 메모리를 힙에 할당하고, 스택에 위치한 ptr**이 그 메모리 주소를 가리키게 된다.

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/39b7c1c6-2541-4f60-b63f-df648981b3e5/c6945d69-0434-4088-9150-886df8f5bfb5/Untitled.png)

- **ptr은 자신이 태어난 코드 블록이 끝나는 곳에서 스택으로부터 제거되지만,** malloc()이 할당한 공간은 힙의 한 공간을 차지한 채 남아있게 된다. → **메모리 누수 발생!**

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/39b7c1c6-2541-4f60-b63f-df648981b3e5/7c911cea-5b7b-4822-9d06-d46524877312/Untitled.png)

```jsx
free(ptr);
```

- 이 코드를 실행하면 ptr이 가리키는 공간을 해제해서 메모리 누수를 막을 수 있다.

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/39b7c1c6-2541-4f60-b63f-df648981b3e5/2ad82379-bd12-45ad-8a0c-1d02960a991e/Untitled.png)

### 노드 생성/소멸 연산

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

### 노드 생성 연산 코드

```cpp
Node* SLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = NewData; // 데이터를 저장한다.
	NewNode->NextNode = NULL; // 다음 노드에 대한 포인터는 NULL로 초기화한다.
	
	return NewNode; // 노드의 주소를 반환한다.
}
```

### 소멸 코드

```cpp
void SLL_DestroyNode(Node* Node)
{
	free(Node);
}
```

### 노드 추가 연산

- 노드 추가는 링크드 리스트의 테일 노드 뒤에 새로운 노드를 만들어 연결하는 연산이다. 꼬리를 덧붙이는 것이다.

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/39b7c1c6-2541-4f60-b63f-df648981b3e5/ce064d49-28b4-4427-b533-585f08480b2f/Untitled.png)

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

### 노드 탐색 연산

왜 ‘*’가 아니고 ‘**’인가요?

```java
Node* List = NULL;
Node* NewNode = NULL;
NewNode = SLL_CreateNode( 117 );
SLL_AppendNode( List, NewNode );

```

- List와 NewNode 선언 시, 다음과 같이 자동 메모리에 두 포인터 변수가 생성됨

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/39b7c1c6-2541-4f60-b63f-df648981b3e5/b4eb0ac8-479a-4e09-8c0c-35eecf927f09/Untitled.png)

- NewNode = SLL_CreateNode ( 117 ); 문장이 실행되면 자유 저장소에 117을 가진 노드가 생성되고, NewNode가 그 주소를 가리킴

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/39b7c1c6-2541-4f60-b63f-df648981b3e5/5e5a338c-f505-4507-9d5d-1b41c0cf30aa/Untitled.png)

- SLL_AppendNode() 함수를 호출할 떄, SLL_AppendNode()의 매개 변수들(_Head 와 _NewNode)이 자동 메모리에 생성되고, List는 _Head에, NewNode는 _NewNode에 **자신이 가리키는 메모리의 주소**를 ‘복사’해 넣습니다.

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/39b7c1c6-2541-4f60-b63f-df648981b3e5/314e5d9b-f550-4d19-b29e-f471b02349a9/Untitled.png)

- SLL_AppendNode() 함수를 호출할 때, List 포인터가 담고 있는 ‘주소값’만 _Head에 복사되고, 정작 List 포인터 변수의 주소는 전달되지 않음.
- SLL_AppendNode() 함수가 호출된 후에는 매개 변수 _Head와 _NewNode는 자동 메모리에 의해 제거되고, List는 여전히 NULL인 채로 남는다.
- SLL_AppendNode() 함수의 첫 번째 매개 변수를 Node**로 선언하면, Head 포인터 자신의 주소를 넘길 수 있게 된다. _Head 포인터는 List 포인터 변수의 ‘주소’를 가리키고, 이 주소를 이용하여 List가 NewNode의 주소를 가리키게 하는 것이다.

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/39b7c1c6-2541-4f60-b63f-df648981b3e5/23c72944-94b2-4094-b83f-87894d251a35/Untitled.png)