# 3장 큐

## 큐의 개념

- **먼저 들어간 데이터가 먼저 나오는(FIFO First In First Out 또는 선입 선출) 자료구조**

### 큐의 핵심 기능: 삽입과 제거 연산

- 큐의 가장 앞 요소를 `전단(Front)` , 가장 마지막 요소를 `후단(Rear`) 이라고 부른다.
- 큐의 경우, `삽입(Enqueue)` 연산은 후단, `제거(Dequeue)` 연산은 전단에서 각각 수행 된다.

![Untitled](3%E1%84%8C%E1%85%A1%E1%86%BC%20%E1%84%8F%E1%85%B2%20d4c2cffedb2f45638f97f50b23e4da48/Untitled.png)

![Untitled](3%E1%84%8C%E1%85%A1%E1%86%BC%20%E1%84%8F%E1%85%B2%20d4c2cffedb2f45638f97f50b23e4da48/Untitled%201.png)

- 제거는 전단의 노드를 없애서 전단 뒤에 있는 노드를 새로운 전단으로 만드는 연산

![Untitled](3%E1%84%8C%E1%85%A1%E1%86%BC%20%E1%84%8F%E1%85%B2%20d4c2cffedb2f45638f97f50b23e4da48/Untitled%202.png)

### 순환 큐

- 배열을 이용해서 큐를 구현할 경우(제거 연산)

![Untitled](3%E1%84%8C%E1%85%A1%E1%86%BC%20%E1%84%8F%E1%85%B2%20d4c2cffedb2f45638f97f50b23e4da48/Untitled%203.png)

- 전단인 1을 제거하면, **배열 내의 첫 번째 인덱스의 요소가 비게 되고, 빈 자리를 채우기 위해 뒤 에 있던 요소가 앞으로 한 칸씩 옮겨짐**
- 전단을 제거한 후 **나머지 요소들을 한 칸씩 앞으로 옮기는 데 드는 비용이 상당하다.**

<aside>
✅ 전단을 가리키는 변수를 도입해서, 전단의 위치만 변경하자.
후단을 가리키는 변수(실제 후단의 위치 + 1) 한 값을 담자.

</aside>

![Untitled](3%E1%84%8C%E1%85%A1%E1%86%BC%20%E1%84%8F%E1%85%B2%20d4c2cffedb2f45638f97f50b23e4da48/Untitled%204.png)

- 이렇게 하면 배열 요소들의 이동으로 인한 부하 문제 해결
- 제거 연산을 수행할 때마다 큐의 가용 용량이 줄어든다.

### 순환 큐(Circular Queue)의 도입

![Untitled](3%E1%84%8C%E1%85%A1%E1%86%BC%20%E1%84%8F%E1%85%B2%20d4c2cffedb2f45638f97f50b23e4da48/Untitled%205.png)

- **시작과 끝을 연결해서 효율적인 삽입/삭제 연산이 가능하도록 고안된 큐**

### 공백 상태와 포화 상태

![Untitled](3%E1%84%8C%E1%85%A1%E1%86%BC%20%E1%84%8F%E1%85%B2%20d4c2cffedb2f45638f97f50b23e4da48/Untitled%206.png)

- 공백 상태, 포화 상태일 때도 전단과 후단이 만나기 때문에, **두 상태를 구분하는 방법을 찾아야 한다.**

![Untitled](3%E1%84%8C%E1%85%A1%E1%86%BC%20%E1%84%8F%E1%85%B2%20d4c2cffedb2f45638f97f50b23e4da48/Untitled%207.png)

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

![Untitled](3%E1%84%8C%E1%85%A1%E1%86%BC%20%E1%84%8F%E1%85%B2%20d4c2cffedb2f45638f97f50b23e4da48/Untitled%208.png)

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