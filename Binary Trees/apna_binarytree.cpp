#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <bits/stdc++.h>
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

// diameter of the tree
// TC = O(N^2)
int diam1(Node* root){

    if(root == NULL){
        return 0;
    }
    
    int currDiam = height(root->left) + height(root->right) + 1; //takes O(n)
    int leftDiam = diam1(root->left);
    int rightDiam = diam1(root->right);

    return max(currDiam, max(leftDiam, rightDiam));
}

// TC - O(N)

pair<int, int> diam2(Node* root){

    pair<int, int> leftInfo = diam2(root->left); // LD, LH
    pair<int, int> rightInfo = diam2(root->right); // RD, RH

    int currDiam = leftInfo.second + rightInfo.second + 1;
    int finalDiam = max(currDiam, max(leftInfo.first, rightInfo.first));
    int finalHt = max(leftInfo.second, rightInfo.second) + 1;

    return make_pair(finalDiam, finalHt);
}


// if an subtree exists in an subroot

// bool isIdentical(Node* root1, Node* root2){

//     if(root1 == NULL && root2 == NULL){
//         return true;
//     }else if(root == NULL || subroot == NULL){
//         return false;
//     }

//     if(root1->data != root2->data){
//         return false;
//     }

//     return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
// }

// bool isSubtree(Node* root, Node* subroot){

//     if(root == NULL && subroot == NULL){
//         return true;
//     }else if(root == NULL || subroot == NULL){
//         return false;
//     }

//     if(root->data == subroot->data){
//         if(isIdentical(root, subroot)){
//             return true;
//         }
//     }

//     int isLeftSubtree = isSubtree(root->left, subroot);
//     if(!isLeftSubtree){
//         return isSubtree(root->right, subroot);
//     }
// }

bool isIdentical(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL) return true;
    if(root1 == NULL || root2 == NULL ) return false;

    if(root1->data != root2->data) return false;

    return isIdentical(root1->left, root2->left)  && isIdentical(root1->right, root2->right);
}

bool isSubtree(Node* root, Node* subroot){
    if(root == NULL || subroot == NULL) return false;

    if(root->data == subroot->data){
        if(isIdentical(root, subroot)){
            return true;
        }
    }

    return isSubtree(root->left, subroot) || isSubtree(root->right, subroot);
}

// Top view of the tree
void topview(Node* root){
    queue<pair<Node* , int> > Q; // (node, Hd)
    map<int, int> m; // (HD, node->data)

    Q.push(make_pair(root, 0));
    while(!Q.empty()){
        pair<Node* , int> curr = Q.front();
        Q.pop();

        Node* currNode = curr.first;
        int currHD = curr.second;

        if(m.count(currHD) == 0){
            m[currHD] = currNode->data;
        }

        if(currNode->left != NULL){
            pair<Node* , int> left = make_pair(currNode->left, currHD-1);
            Q.push(left);

        }

        if(currNode->right != NULL){
            pair<Node*, int> right = make_pair(currNode->right, currHD + 1 );
            Q.push(right);
        }
    }

    for(auto it:m){
        cout << it.second << " ";
    }
}


// kth level of the order

// when we are dealing with more than 3 arguments its better to use or write and extra function 

void KthHelper(Node* root, int K, int currLevel){

    if(root == NULL){
        return ;
    }
        
    if(currLevel == K){
        cout << root->data << " ";
        return;
    }

    KthHelper(root->left, K, currLevel + 1);// left
    KthHelper(root->right, K, currLevel + 1); // right

}

void KthLevel(Node* root, int K){ // TC - O(N)
    KthHelper(root, K, 1);
    cout << endl;
}

vector<int> v1(Node* root, int n1){

    vector<int> v;
    if(root == NULL){
        return ;
    }

    queue<int> q;
    q(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr->right){
            v1(curr->left, n1);
        }

        if(curr->left){
            v1(curr->right, n2);
        }

        if(curr->data = n1){
            return v;
        }
    }

    return v;
}


// lowest common ancestor

bool rootToNodePath(Node* root, int n , vector<int> &path){ // O(N)

    if(root == NULL){
        return false;
    }

    path.push_back(root->data);
    if(root->data == n){
        return true;
    }

    int isLeft = rootToNodePath(root->left, n, path);
    int isRight = rootToNodePath(root->right, n, path);

    if(isLeft || isRight){
        return true;
    }

    path.pop_back();
    return false;
}


// 2nd approach 
Node* LCA2(Node* root, int n1, int n2){

    if(root == NULL ){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* leftLCA = LCA2(root->left, n1, n2);
    Node* rightLCA = LCA2(root->right, n1, n2);

    if(leftLCA != NULL && rightLCA != NULL){
        return root;
    }

    return leftLCA == NULL ? rightLCA: leftLCA; 


}


int lca(Node* root, int n1, int n2){

    vector<int> path1;
    vector<int> path2;

    if(!rootToNodePath(root, n1, path) || !rootToNodePath(root, n2, path2))
        return NULL;

    

    int i;
    for(int i = 0; i<path1.size() && i<path2.size(); i++){
        if(path[i] != path2[i]){
            break;
        }

    }

    return path1(i-1);


}


// minimum distance

int dist(Node* root, int n){
    if(root == NULL){
        return -1;
    }

    if(root->data == n){
        return 0;
    }

    int leftDist = dist(root->left, n);
    if(leftDist != -1){
        return leftDist + 1;
    }

    int RightDist = dist(root->right, n);
    if(rightDist != -1){
        return rightDist + 1;
    }

    return -1;
}


int minDist(Node* root, int n1, int n2){
    Node* lca = LCA(root, n1, n2);

    int dist1 = dist(lca, n1);
    int dist2 = dist(lca, n2);

    return dist1 + dist2;
}


// Kth ancestor

int kthancestor(Node* root, int node, int k){
    if(root == NULL){
        return -1;
    }

    if(root->data == node){
        return 0;
    }

    int leftDist = kthancestor(root->left, node, k);
    int rightDist = kthancestor(root->left, node, k );

    if(leftDist == -1 && rightDist == -1){
        return -1;
    }

    int validVal = leftDist == -1 ? rightDist: leftDist;
    if(validVal + 1 == K){
        cout << "Kth Ancestor" << root->data << endl;
    }

    return validVal + 1;
}


// transform to sum tree

int transform(Node* root){
    
    if(root == NULL){
        return 0;
    }

    int leftold= transform(root->left);
    int rightold = transform(root->right);
    int currold = root->data;

    root->data = leftold + rightold + root->left->data + root->right->data;
    return currOld;
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


    // creating an subroot
    Node* subroot = new Node(2);
    subroot->left = new Node(4);
    subroot->right = new Node(5);

    cout << isSubtree(root, subroot) << endl;
    KthLevel(root, 3);

    return 0;
}