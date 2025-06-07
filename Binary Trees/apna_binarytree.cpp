#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            left = right = NULL;
        }
};

static int idx = -1;

Node* buildTree(vector<int>& nodes){
    idx++;
    if(nodes[idx] == -1){
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes); // left subtree
    currNode->right = buildTree(nodes); // right subtree

    return currNode;
}

void preorder(Node* root){

    if(root == NULL){
        return;
    }
    cout << root->data<< " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    // left tree
    inorder(root->left);
    // print the data
    cout << root->data << " ";
    //right tree
    inorder(root->right);
}

void postorder(Node* root){

    if(root == NULL){
        return;
    }

    //left
    postorder(root->left);
    //right
    postorder(root->right);
    //root
    cout << root->data << " ";
}

// TC - O(N) & SC-O(N)
void levelOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> Q;         // use capital Q or lowercase 'q' consistently
    Q.push(root);           // start with the root node

    while (!Q.empty()) {
        Node* curr = Q.front();  // get the front node
        Q.pop();                 // remove it from the queue

        cout << curr->data << " "; // process the current node

        if (curr->left != NULL) {
            Q.push(curr->left);    // add left child to the queue
        }

        if (curr->right != NULL) {
            Q.push(curr->right);   // add right child to the queue
        }
    }
}

// TC and O(N)

void levelOrderlinebyline(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> Q;         // use capital Q or lowercase 'q' consistently
    Q.push(root);
    Q.push(NULL);           // start with the root node

    while (!Q.empty()) {
        Node* curr = Q.front();  // get the front node
        Q.pop();                 // remove it from the queue
        if(curr == NULL){
            cout << endl;
            if(Q.empty()){
                break;
            }
            Q.push(NULL); // to track next line
            continue; 
        }
        cout << curr->data << " "; // process the current node

        if (curr->left != NULL) {
            Q.push(curr->left);    // add left child to the queue
        }

        if (curr->right != NULL) {
            Q.push(curr->right);   // add right child to the queue
        }
    }
}

// Height of the tree

int height(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftHt = height(root->left);
    int rightHt = height(root->right);
    int currHt = max(leftHt, rightHt);

    return currHt;
}


int count(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftCount = count(root->left);
    int rightCount = count(root->right);

    return leftCount + rightCount + 1;
}

int sum(Node* root){

    if(root == NULL){
        return 0;
    }

    int leftSum = sum(root->left);
    int rightSum = sum(root->right);

    int currSum = leftSum + rightSum + root->data;
    cout << "sum = " << currSum << endl;
    return currSum;
}

int main() {
    vector<int> nodes;
    nodes.push_back(1);
    nodes.push_back(2);
    nodes.push_back(4);
    nodes.push_back(-1);
    nodes.push_back(-1);
    nodes.push_back(5);
    nodes.push_back(-1);
    nodes.push_back(-1);
    nodes.push_back(3);
    nodes.push_back(-1);
    nodes.push_back(6);
    nodes.push_back(-1);
    nodes.push_back(-1);

    Node* root = buildTree(nodes);

    preorder(root); // Expected Output: 1 2 4 5 3
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    levelOrder(root);
    cout << endl;
    levelOrderlinebyline(root);
    cout << endl;

    cout<< count(root)<<endl;

    Node* root2 = new Node(5);
    root2->left = new Node(3);
    root2->right = new Node(4);
    cout << count(root2) << endl;

    cout << sum(root)<< endl;


    return 0;
}