# 3장 큐

## 큐의 개념

- **먼저 들어간 데이터가 먼저 나오는(FIFO First In First Out 또는 선입 선출) 자료구조**

### 큐의 핵심 기능: 삽입과 제거 연산

- 큐의 가장 앞 요소를 `전단(Front)` , 가장 마지막 요소를 `후단(Rear`) 이라고 부른다.
- 큐의 경우, `삽입(Enqueue)` 연산은 후단, `제거(Dequeue)` 연산은 전단에서 각각 수행 된다.
  
![Untitled](https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/d6e4d25a-314c-4a6e-bd21-a635db872740)
![Untitled 1](https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/25c50cec-eac6-4fcc-88c4-21f97c927325)


- 제거는 전단의 노드를 없애서 전단 뒤에 있는 노드를 새로운 전단으로 만드는 연산


### 순환 큐

- 배열을 이용해서 큐를 구현할 경우(제거 연산)

![Untitled 3](https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/10ba8c16-cd61-456c-9aab-03e261254eae)

- 전단인 1을 제거하면, **배열 내의 첫 번째 인덱스의 요소가 비게 되고, 빈 자리를 채우기 위해 뒤 에 있던 요소가 앞으로 한 칸씩 옮겨짐**
- 전단을 제거한 후 **나머지 요소들을 한 칸씩 앞으로 옮기는 데 드는 비용이 상당하다.**

<aside>
✅ 전단을 가리키는 변수를 도입해서, 전단의 위치만 변경하자.
후단을 가리키는 변수(실제 후단의 위치 + 1) 한 값을 담자.

</aside>

![Untitled 4](https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/7d372623-da70-4205-830f-f90c28aca06d)

- 이렇게 하면 배열 요소들의 이동으로 인한 부하 문제 해결
- 제거 연산을 수행할 때마다 큐의 가용 용량이 줄어든다.

### 순환 큐(Circular Queue)의 도입

![Untitled 5](https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/afa99b06-8f50-4538-b696-44a7d62c5d5f)

- **시작과 끝을 연결해서 효율적인 삽입/삭제 연산이 가능하도록 고안된 큐**

### 공백 상태와 포화 상태

![Untitled 6](https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/1bd48d93-4d09-4710-a722-88e0ce958e55)

- 공백 상태, 포화 상태일 때도 전단과 후단이 만나기 때문에, **두 상태를 구분하는 방법을 찾아야 한다.**

![Untitled 7](https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/c52bf3b2-ea41-449e-85b7-f218184b83ad)

<aside>
✅ 큐 배열을 생성할 때, 실제 용량보다 1만큼 더 크게 만들어서 전단과 후단 사이를 비운다.
큐가 공백 상태일 때, **전단과 후단이 같은 곳**을 가리킨다.
큐가 포화 상태일 때, 후단이 전단보다 1 작은 값을 가진다.

</aside>

## 순환 큐의 기본 연산

### 순환 큐 선언

```cpp
typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
} Node;
```

- `CircularQueue` 구조체는 `Queue` 의 용량(Capacity), 전단의 위치(Front), 후단의 위치(Rear), 순환 큐 요소의 배열에 대한 포인터를 갖고 있다.

```cpp
typedef struct tagCircularQueue
{
	int Capacity;
	int Front;
	int Rear;
	
	Node* Nodes;
} CircularQueue;
```

- CircularQueue 구조체의 `Nodes` 포인터가 가리키는 배열은 큐에 생성된다.
- `Capacity` 는 순환 큐의 용량, Nodes를 메모리에 할당할 때는 `Capacity+1` 만큼의 크기를 할당한다. **(노드 하나를 공백/포화 상태 구분용 더미 노드로 사용)**
  
![Untitled 8](https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/5999df78-0285-4653-ba59-14ce90d8c494)

### 순환 큐 생성/소멸 연산

```cpp
void CQ_CreateQueue(CircularQueue** Queue, int Capacity)
{
	(*Queue) = (CircularQueue*)malloc(sizeof(CircularQueue));
	
	(*Queue)->Nodes = (Node*)malloc(sizeof(Node)*(Capacity+1));
	
	(*Queue)->Capacity = Capacity;
	(*Queue)->Front = 0;
	(*Queue)->Rear = 0;
}
```

- 순환 큐를 자유 저장소(큐)에 생성한 다음, 배열을 `Node 크기 x (Capacity+1)` 의 크기만큼 자유 저장소(큐)에 할당한다. **(더미 노드가 필요하기 때문에 Capacity+1 크기 할당)**

```cpp
void CQ_DestroyQueue(CircularQueue* Queue)
{
	free(Queue->Nodes);
	free(Queue);
}
```

- 순환 큐를 메모리에서 제거하는 함수

### 노드 삽입 연산

- `Rear` 값이 `*Queue -> Capacity + 1` 과 같은 값이라면 후단이 배열 끝에 도달했다는 의미이므로,  `Rear` 와 `Position` 을 0으로 지정합니다.
- 그렇지 않은 경우, Rear에 위치를 Position에 저장하고 Rear 값을 1 증가시킵니다.

![Untitled 9](https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/257db039-d93f-4c01-b9ca-2d98218be522)

```cpp
void CQ_Enqueue(CircularQueue* Queue, ElementType Data)
{
	int Position = 0;
	
	if(Queue->Rear==Queue->Capacity)
	{
		Position=Queue->Rear;
		Queue->Rear=0;
	}
	else
		Position=Queue->Rear++;
	
	Queue->Nodes[Position].Data = Data;
}

```

### 노드 제거 연산

```cpp
ElementType CQ_Dequeue(CircularQueue* Queue)
{
	int Position = Queue->Front;
	
	if (Queue->Front == Queue->Capacity)
		Queue->Front = 0;
	else
		Queue->Front++;
	
	return Queue->Nodes[Position].Data;
}
```

- 전단의 위치(Front)를 `Position` 에 저장합니다.
- `Position` 은 `CQ_Dequeue()` 함수가 큐에 저장되어 있던 데이터를 반환할 때, `Nodes` 배열의 인덱스로 사용되는 변수
- `Front` 의 값이 `Capacity` 와 같을 때, `Front` 를 0으로 초기화하고, 그렇지 않은 경우 `Front` 의 값을 1만큼 증가

![Untitled 10](https://github.com/kmw10693/THIS-IS-DATA-STRUCTURE_AND_ALGORITHM-WITH-C/assets/60867950/67507e82-9357-407b-ab12-872da48930d0)

### 공백 상태 확인

- 전단과 후단의 값이 같으면 공백 상태라는 의미이다.

```cpp
int CQ_IsEmpty(CircularQueue* Queue)
{
	return (Queue->Front == Queue->Rear);
}
```

### 포화 상태 확인

- 전단이 후단 앞에 있는 경우 (Rear - Front)가 큐의 용량(Capacity)와 동일 한 경우
- 후단에 1을 더한 값(Rear + 1)이 전단(Front)와 동일한 경우

```cpp
int CQ_IsFull(CircularQueue* Queue)
{
	if (Queue->Front < Queue->Rear)
		return (Queue->Rear - Queue->Front) == Queue->Capacity;
	else
		return (Queue->Rear + 1 ) == Queue->Front;
}
```

## 링크드 큐

- 링크드 큐가 순환 큐와 다른 한 가지 점은 큐가 가득 찬 상태인지 확인할 필요가 없다.
- 성능은 순환 큐가 더 빠르다**(`malloc` , `calloc`  함수를 쓸 필요가 없기 때문)**
- 필요한 큐의 크기를 미리 정할 수 있고, 고성능이 요구 되는 상황에서는 링크드 큐보다 순환 큐를 선택하는 것이 낫다.

### 링크드 큐와 노드 선언

- 데이터 필드와 다음 노드를 가리키는 포인터로 구성

```cpp
typedef struct tagNode
{
	char* Data;
	struct tagNode* NextNode;
} Node;
```

- 링크드 큐 구조체는 큐의 전단을 가리키는 `Front` , 후단을 가리키는 `Rear` , 노드 개수를 나타내는 `Count` 로 구성

```cpp
typedef struct tagLinkedQueue
{
	Node* Front;
	Node* Rear;
	int Count;
} LinkedQueue;
```

### 링크드 큐 생성/소멸 연산

- `LinkedQueue` 구조체를 자유 저장소에 생성하고, 이 구조체의 각 필드를 초기화 한다.

```cpp
void LQ_CreateQueue(LinkedQueue** Queue)
{
	(*Queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	(*Queue)->Front = NULL;
	(*Queue)->Rear = NULL;
	(*Queue)->Count = 0;
}
```

- 링크드 큐의 소멸을 담당하는 함수는 큐 내부에 있는 모든 노드를 힙에서 제거하고, 큐 마저 제거한다.

```cpp
void LQ_DestroyQueue(LinkedQueue* Queue)
{
	while(!LQ_IsEmpty(Queue))
	{
		Node* Popped = LQ_Dequeue(Queue);
		LQ_DestroyNode(Popped);
	}
	
	free(Queue);
}
```

### 노드 삽입 연산

- 새로운 노드를 후단에 붙인다.

```cpp
void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode)
{
	if(Queue->Front == NULL)
	{
		Queue->Front = NewNode;
		Queue->Rear = NewNode;
		Queue->Count++;
	}
	else
	{
		Queue->Rear->NextNode = NewNode;
		Queue->Rear = NewNode;
		Queue->Count++;
	}
}
```

### 노드 제거 연산

- 전단 뒤에 있던 노드를 새로운 전단으로 만들고 전단이었던 노드의 포인터를 호출자에게 반환 하면 된다.

```cpp
Node* LQ_Dequeue(LinkedQueue* Queue)
{
	Node* Front = Queue->Front;
	
	if(Queue->Front->NextNode == NULL)
	{
		Queue->Front = NULL;
		Queue->Rear = NULL;
	}
	else
	{
		Queue->Front = Queue->Front->NextNode;
	}
	
	Queue->Count--;
	return Front;
}
```
