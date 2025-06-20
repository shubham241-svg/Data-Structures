#include <iostream>
#include <vector>
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

Node* insert(Node* root, int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    }

    if(val < root->data){ // left subtree
        root->left = insert(root->left, val);
    }

    else {// right subtree
        root->right = insert(root->right, val);
    }

    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return ;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* buildBST(int arr[], int n){
    Node* root = NULL;

    for(int i= 0; i<n; i++){
        root = insert(root, arr[i]);
    }

    return root;
}

bool search(Node* root, int key){ // O(height): avg => logn for skewed it becomes O(N)
    if(root == NULL){
        return false;
    }
    if(root->data == key){ // found
        return true;
    }

    if(root->data > key){ // left subtree
        return search(root->left, key);     
    }else{
        return search(root->right, key); // right subtree
    }
}

Node* getInorderSuccessor(Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* delNode(Node* root, int val){
    if(root == NULL){
        return NULL;
    }

    if(val < root->data){// left subtree
        root->left = delNode(root->left, val);

    }else if(val > root->data){// right subtree
        root->right = delNode(root->right, val);

    }else{
        //root == val
        //case1 : 0 children
        if(root->left == NULL && root->right == NULL ){
            delete root;
            return NULL;
        }

        // case 2: 1 child
        if(root->left == NULL || root->right == NULL){
            Node* temp = root->left == NULL ? root->right: root->left;
            delete root;
            return temp;
            
        }

        // case 3 : 2 children
        Node* IS = getInorderSuccessor(root->right);
        root->data = IS->data;
        root->right = delNode(root->right, IS->data); // case1 case 2
        return root;


    }
    return root;

}


// Root to leaf

void printInRange(Node* root, int start, int end){

    if(root == NULL){
        return;
    }

    if(start <= root->data && root->data <= end){
        cout << root->data << " ";
        printInRange(root->left, start, end);
        //cout << root->data if you want to print the sorted sequence
        printInRange(root->right, start, end);
    }else if(root->data < start){ // case 2
        printInRange(root->right, start, end);
    }else{// case 3
        printInRange(root->left, start, end);

    }

}



// Utility to print a single root-to-leaf path
void printPath(const vector<int>& path) {
    cout << "path: ";
    for (int val : path) {
        cout << val << " ";
    }
    cout << endl;
}

// Recursive helper function to build root-to-leaf paths
void pathHelper(Node* root, vector<int>& path) {
    if (root == NULL) return;

    path.push_back(root->data);

    if (root->left == NULL && root->right == NULL) {
        // It's a leaf node, print the path
        printPath(path);
    } else {
        // Recurse on children
        pathHelper(root->left, path);
        pathHelper(root->right, path);
    }

    // Backtrack to explore other paths
    path.pop_back();
}

// Wrapper function to start the recursion
void roottoleaf(Node* root) {
    vector<int> path;
    pathHelper(root, path);
}

// Validate BST

bool validateHelper(Node* root, Node * min, Node* max){
    if(root == NULL){
        return true;
    }
    if(min != NULL && root->data < min->data){
        return false;
    }
    if(max != NULL && root->data > max->data){
        return false;
    }

    return validateHelper(root->left, min, root)
        && validateHelper(root->right, root, max);


}

bool validateBST(Node* root){
    return validateHelper(root, NULL, NULL);
}

int main(){
    int arr[6] = {5, 1, 3, 4, 2,7};
    //int arr2[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14}

    Node* root = buildBST(arr, 6);
    inorder(root);
    cout << endl;

    cout << search(root, 4) << endl;

    inorder(root);
    cout << endl;
    delNode(root, 4);

    printInRange(root, 2, 4);
    cout << endl;

    cout << validateBST(root) << endl;


    return 0;

}