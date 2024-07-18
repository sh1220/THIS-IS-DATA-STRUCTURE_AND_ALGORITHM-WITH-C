
#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int newData) : data(newData), left(nullptr), right(nullptr) {}
};


class BinaryTree {
public:
	Node* root = nullptr;
	Node* CreateNode(int data);
	void DestroyNode(Node* node);
	Node* SearchNode(Node* node, int serachData, Node* parent);
	void RemoveNode(int removeData);
	void InsertNode(int newData);
	int CountNode(Node* node);
	void PrintInOrder(Node* node);
};


Node* BinaryTree::CreateNode(int newData)
{
	Node* newNode = new Node(newData);
	return newNode;
}

void BinaryTree::DestroyNode(Node* node)
{
	delete node;
}

Node* BinaryTree::SearchNode(Node* node, int searchData, Node* parent)
{
	if (node == nullptr || node->data == searchData) return parent;

	if (node->data > searchData) {
		return SearchNode(node->left, searchData, node);
	}

	if (node->data < searchData) {
		return SearchNode(node->right, searchData, node);
	}

}

void BinaryTree::RemoveNode(int removeData)
{

	Node* parentNode = SearchNode(root, removeData, nullptr);

	if (parentNode == nullptr) return;

	Node* removeNode = nullptr;
	bool isLeftChild = false;
	if (parentNode == nullptr) {
		removeNode = root;
	}
	else {
		if (parentNode->left != nullptr && parentNode->left->data == removeData) {
			removeNode = parentNode->left;
			isLeftChild = true;
		}
		else if (parentNode->right != nullptr && parentNode->right->data == removeData) {
			removeNode = parentNode->right;
		}
	}

	if (removeNode == nullptr) return; // 노드가 존재하지 않으면 아무것도 하지 않음


	if (removeNode->left == nullptr && removeNode->right == nullptr)
	{
		if (removeNode == root) {
			root = nullptr;
		}
		else if (isLeftChild) {
			parentNode->left = nullptr;
		}
		else {
			parentNode->right = nullptr;
		}
		DestroyNode(removeNode);
	}
	else if (removeNode->left == nullptr || removeNode->right == nullptr) {
		Node* child = (removeNode->left != nullptr) ? removeNode->left : removeNode->right;
		if (removeNode == root) {
			root = child;
		}
		else if (isLeftChild) {
			parentNode->left = child;
		}
		else {
			parentNode->right = child;
		}
		DestroyNode(removeNode);
	}
	else {
		Node* successorParent = removeNode;
		Node* successor = removeNode->right;
		while (successor->left != nullptr) {
			successorParent = successor;
			successor = successor->left;
		}
		removeNode->data = successor->data;
		if (successorParent->left == successor) {
			successorParent->left = successor->right;
		}
		else {
			successorParent->right = successor->right;
		}
		DestroyNode(successor);
	}

}

void BinaryTree::InsertNode(int newData)
{
	if (root == nullptr) {
		root = CreateNode(newData);
		return;
	}
	Node* tempNode = SearchNode(root, newData, nullptr);

	if (tempNode == nullptr || tempNode->data == newData) return;


	if (newData < tempNode->data) {
		tempNode->left = CreateNode(newData);
	}
	else {
		tempNode->right = CreateNode(newData);
	}

}


int BinaryTree::CountNode(Node* node)
{
	if (node == nullptr) return 0;
	return 1 + CountNode(node->left) + CountNode(node->right);
	
}

void BinaryTree::PrintInOrder(Node* node) {
	if (node == nullptr) return;
	PrintInOrder(node->left);
	cout << node->data << " ";
	PrintInOrder(node->right);
}



int main()
{
	BinaryTree tree;
	tree.InsertNode(10);
	tree.InsertNode(5);
	tree.InsertNode(13);
	tree.InsertNode(22);
	tree.InsertNode(154);
	tree.InsertNode(11);
	tree.InsertNode(33);
	tree.InsertNode(26);

	tree.PrintInOrder(tree.root);


	cout << "\n노드 갯수 : " << tree.CountNode(tree.root) << "\n";


	tree.RemoveNode(13);

	cout << "\n노드 갯수 : " << tree.CountNode(tree.root) << "\n";


	tree.PrintInOrder(tree.root);



}