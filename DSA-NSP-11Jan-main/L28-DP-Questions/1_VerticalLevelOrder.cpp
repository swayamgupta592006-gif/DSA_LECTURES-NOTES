#include <iostream>
#include <queue>
using namespace std;

class node{
public:
	int data;
	node* left, *right;

	node(int d){
		data = d;
		left = right = NULL;
	}
};

node* createTree(){
	int data;
	cin>>data;
	if(data == -1){
		return NULL;
	}

	node* root = new node(data);
	root->left = createTree();
	root->right = createTree();	

	return root;
}

void preOrder(node* root){
	if(root == NULL){
		return;
	}

	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(node* root){
	if(root == NULL){
		return;
	}

	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

void postOrder(node* root){
	if(root == NULL){
		return;
	}
	
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}

void findMinMaxLevel(node* root,int currentLevel, int &minLevel, int &maxLevel){
	if(root == NULL){
		return;
	}

	minLevel = min(currentLevel, minLevel);
	maxLevel = max(currentLevel, maxLevel);

	findMinMaxLevel(root->left, currentLevel - 1, minLevel, maxLevel);
	findMinMaxLevel(root->right, currentLevel + 1, minLevel, maxLevel);
}

void printLevel(node* root, int currentLevel, int level){
	if(root == NULL){
		return;
	}

	if(currentLevel == level){
		cout << root->data<<" ";
	}

	printLevel(root->left, currentLevel - 1, level);
	printLevel(root->right, currentLevel + 1, level);
}

int main(){

	node* root = createTree();
	int minLevel = INT_MAX, maxLevel = INT_MIN;
	findMinMaxLevel(root, 0, minLevel, maxLevel);

	cout << "Min Level : "<<minLevel<<endl;
	cout << "Max Level : "<<maxLevel<<endl;

	for (int i = minLevel; i <= maxLevel; ++i)
	{
		cout << "Level "<<i<<" : ";
		printLevel(root, 0, i);
		cout << endl;
	}
	return 0;
}
















