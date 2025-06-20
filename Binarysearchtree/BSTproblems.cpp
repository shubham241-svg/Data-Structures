#include <iostream>
#include <vector>
using namespace std;

class Node{
    public : 
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            left = right = NULL;
        }
};

//



// Largest BST ;


class Info{
    public: 
        bool isBST;
        int min;
        int max;
        int sz;

        Info(bool isBST, int min, int max, int sz){
            this->isBST = isBST;
            this->min = min;
            this->max = max;
            this->sz = sz;
        }
};

static int maxSize ;

Info* largestBST(Node* root){

    // if(root == NULL){
    //     new Info(true, INT_MAX, INT_MIN, 0);
    // }

    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL ){
        return new Info(true, root->data, root->data, 1);
    }

    Info* leftInfo = largestBST(root->left);
    Info* rightInfo = largestBST(root->right);

    int currMin = min(root->data, min(leftInfo->min, rightInfo->min));
    int currMax = max(root->data , max(leftInfo->max, rightInfo->max));
    int currSz = leftInfo->sz + rightInfo->sz + 1 ;

    if(leftInfo->isBST && rightInfo->isBST && root->data > leftInfo->max && root->data < rightInfo->min){

        maxSize = max(maxSize, currSz);
        return new Info(true, currMin, currMax, currSz);
    }

    return new Info(false, currMin, currMax, currSz);
}







void preorder(Node* root){
    if(root == NULL){
        return ;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

Node* buildBSTfromSorted(int arr[], int st, int end){
    if(st > end){
        return NULL;
    }

    int mid = st + (end-st)/2;
    Node* curr = new Node(arr[mid]);

    curr->left = buildBSTfromSorted(arr, st, mid-1);
    curr->right = buildBSTfromSorted(arr, mid+1, end);

    return curr;
}

// BST to balanced BST

Node* buildBSTfromSortedvector(vector<int> arr, int st, int end){
    if(st > end){
        return NULL;
    }

    int mid = st + (end-st)/2;
    Node* curr = new Node(arr[mid]);

    curr->left = buildBSTfromSortedvector(arr, st, mid-1);
    curr->right = buildBSTfromSortedvector(arr, mid+1, end);

    return curr;
}

void path(Node* root, vector<int>& pa){
    if(root == NULL){
        return;
    }
    path(root->left, pa);
    pa.push_back(root->data);
    path(root->right, pa);
}

Node* convertbstTOBST(Node* root){
    vector<int> pas;
    path(root, pas);

    return buildBSTfromSortedvector(pas, 0, pas.size()-1);


}


// Merge 2 BST
void vectpath(Node* root, vector<int>& v){
    
    if(root == NULL){
        return;
    }

    vectpath(root->left, v);
    v.push_back(root->data);  // Inorder sorted
    vectpath(root->right,v);

}

vector<int> merge2BST(Node* root1, Node* root2){
    vector<int> v1;
    vector<int> v2;

    vectpath(root1, v1);
    vectpath(root2, v2);

    vector<int> v3;             //Inorder of BST1
    int left = 0;
    int right = 0;

    while(left < v1.size() && right <v2.size()){
        if(v1[left] < v2[right]){
            v3.push_back(v1[left++]);
        }
        else if(v1[left] == v2[right]){
            v3.push_back(v1[left]);
            left++;
            right++;
        }else{
            v3.push_back(v2[right++]);
        }
    }

    if(left < v1.size()){
        while(left < v1.size()){
            v3.push_back(v1[left++]);
        }
    }

    if(right < v2.size()){
        while(right < v2.size()){
            v3.push_back(v2[right++]);
        }
    }

    return v3;

}
int main(){
    int arr[7] = {3, 4, 5, 6, 7, 8, 9};

    Node* root = buildBSTfromSorted(arr, 0, 6);
    preorder(root);
    cout << endl;



    Node* root1 = new Node(50);
    root1->left = new Node(30);
    root1->left->left = new Node(5);
    root1->left->right = new Node(20);

    root1->right = new Node(60);
    root1->right->left = new Node(45);
    root1->right->right = new Node(70);
    root1->right->right->left = new Node(65);
    root1->right->right->right = new Node(80);

    largestBST(root1);
    cout << "max Size : " << maxSize << endl;
    return 0;
}