#include <iostream>
#include<vector>
#include<queue>

using namespace std;

#define COUNT 10

class Node {
	Node* leftChild;
	Node* rightChild;
	int data;

	friend class BST;
public:
	Node(int d = 0) :data(d), leftChild(NULL), rightChild(NULL) {}
};

class BST {
	Node* root;

	Node* insert(Node* root, int key) {

		if (root == NULL)
			return root = new Node(key);
		if (key < root->data)
			root->leftChild = insert(root->leftChild, key);
		else {
			if (key > root->data)
				root->rightChild = insert(root->rightChild, key);
		}
		return root;
	}
	Node* search(int key, Node* root) {
		if (root == NULL || key == root->data)
			return root;
		if (key < root->data)


			return (search(key, root->leftChild));
		return(search(key, root->rightChild));
	}
	Node* minimum(Node* root) {
		while (root->leftChild != NULL) {
			root = root->leftChild;
		}
		return root;
	}
	Node* maximum(Node* root) {
		while (root->rightChild != NULL) {
			root = root->rightChild;
		}
		return root;
	}
	int HeightOf_BST(Node* root) {
		if (root == NULL) {
			return 0;
		}
		else {
			int left_side;
			int right_side;
			left_side = HeightOf_BST(root->leftChild);
			right_side = HeightOf_BST(root->rightChild);
			if (left_side > right_side) {
				return left_side + 1;

			}
			else {
				return right_side + 1;
			}
		}
	}
	int DepthOf_BST(Node* root){
		if (root == NULL)
			return 0;
		else{
			/* compute the depth of each subtree */
			int lDepth = DepthOf_BST(root->leftChild);
			int rDepth = DepthOf_BST(root->rightChild);
			/* use the larger one */
			if (lDepth > rDepth)
				return(lDepth + 1);
			else return(rDepth + 1);
		}
	}
	bool areIdentical(Node* root1, Node* root2) {
		/* base cases */
		if (root1 == NULL && root2 == NULL)
			return true;

		if (root1 == NULL || root2 == NULL)
			return false;

		/* Check if the data of both roots is
		same and data of left and right
		subtrees are also same */
		return (root1->data == root2->data &&
			areIdentical(root1->leftChild, root2->leftChild) &&
			areIdentical(root1->rightChild, root2->rightChild));
	}
	bool isSubtree(Node* T, Node* S) {
		if (S == NULL)
			return true;
		if (T == NULL)
			return false;
		if (areIdentical(T, S))
			return true;
		return isSubtree(T->leftChild, S) ||
			isSubtree(T->rightChild, S);
	}
	void BreadthFirstTravseral(Node* root){
		queue<Node*> q;

		if (!root) {
			return;
		}
		for (q.push(root); !q.empty(); q.pop()) {
			const Node* const temp_node = q.front();
			cout << temp_node->data << " ";

			if (temp_node->leftChild) {
				q.push(temp_node->leftChild);
			}
			if (temp_node->rightChild) {
				q.push(temp_node->rightChild);
			}
		}
	}
	void printBST(Node* root, int space){ 
		if (root == NULL)
			return;
		space += COUNT;
		printBST(root->rightChild, space);
		cout << endl;
		for (int i = COUNT; i < space; i++)
			cout << " ";
		cout << root->data << "\n";
		printBST(root->leftChild, space);
	}
public:
	BST() {
		root = NULL;
	}
	BST(const BST& toCopy) {
		root = copyHelper(toCopy.root);
	}
	BST(Node* root, int storedData[])
	{
		static int pos = 0;
		if (root == NULL) return;

		BST(root->leftChild, storedData);
		storedData[pos++] = root->data;
		BST(root->rightChild, storedData);

	}
	Node* copyHelper(Node* toCopy) {
		if (toCopy == NULL)
			return NULL;
		Node* copyNode = new Node;
		copyNode->data = toCopy->data;
		copyNode->leftChild = copyHelper(toCopy->leftChild);
		copyNode->rightChild = copyHelper(toCopy->rightChild);
		return copyNode;
	}
	~BST() {
		delete root;
	}
	void insert(int key) {
		root = insert(root, key);
	}
	Node* search(int key) {
		return search(key, root);
	}
	void neighbours(int key, int* prevNeighbour, int* nextNeighbour) {
		Node* temp = search(key);
		if (temp == NULL) {
			cout << "List is empty!\n";
			return;
		}
		Node* left = maximum(root->leftChild);
		Node* right = minimum(root->rightChild);
		*prevNeighbour = left->data;
		*nextNeighbour = right->data;
	}
	int HeightOf_BST() {
		if (root == NULL) {
			return 0;
		}
		else {
			int left_side;
			int right_side;
			left_side = HeightOf_BST(root->leftChild);
			right_side = HeightOf_BST(root->rightChild);
			if (left_side > right_side) {
				return left_side + 1;

			}
			else {
				return right_side + 1;
			}
		}
	}
	int DepthOf_BST() {
		if (root == NULL)
			return 0;
		else {
			/* compute the depth of each subtree */
			int lDepth = DepthOf_BST(root->leftChild);
			int rDepth = DepthOf_BST(root->rightChild);
			/* use the larger one */
			if (lDepth > rDepth)
				return(lDepth + 1);
			else return(rDepth + 1);
		}
	}
	bool isSubtree(){
		Node* T=NULL; 
		Node* S=NULL;
		if (S == NULL)
			return true;
		if (T == NULL)
			return false;
		if (areIdentical(T, S))
			return true;
		return isSubtree(T->leftChild, S) ||
			isSubtree(T->rightChild, S);
	}
	void BreadthFirstTravseral(){
		queue<Node*> q;
		if (!root) {
			return;
		}
		for (q.push(root); !q.empty(); q.pop()) {
			const Node* const temp_node = q.front();
			cout << temp_node->data << " ";

			if (temp_node->leftChild) {
				q.push(temp_node->leftChild);
			}
			if (temp_node->rightChild) {
				q.push(temp_node->rightChild);
			}
		}
	}
	void printbst(){
		printBST(root, 0);
	}
};

int main() {
	BST bst;
	bst.insert(7);
	bst.insert(3);
	bst.insert(0);
	bst.insert(4);
	bst.insert(27);
	bst.insert(13);
	bst.insert(76);


	cout << "Height Of Binary Search Tree:" << bst.HeightOf_BST() << endl;
	cout << "Depth of Binary Search Tree: " << bst.DepthOf_BST() << endl;
	if (bst.isSubtree() == true) {
		cout << "Tree is a SubTree" << endl;
	}
	else {
		cout << "Tree is not a SubTree" << endl;
	}
	cout << "Breadth First Traversal: ";
	bst.BreadthFirstTravseral();
	cout << endl;
	
	int x, y;
	bst.neighbours(7, &x, &y);
	std::cout << "Prev: " << x << std::endl;
	std::cout << "Next: " << y << std::endl;

	bst.printbst();

	system("pause");
}