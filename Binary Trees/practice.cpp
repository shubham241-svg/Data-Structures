#include <bits/stdc++.h>
using namespace std;

// levelorder traversal

void level(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        auto curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }


    }
}

// line by line 

void levellinebyline(Node* root){
    if(root == NULL) return ;
    
    queue<Node* > q;
    q.push(root);

    while(!q.empty()){
        int levelsize = q.size(); // count the current nodes at the current level

        while(levelSize--){
            Node* curr = q.front();
            q.pop();
            cout << curr->data << " ";

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }

        cout << endl; // new line after each level
    }
}

// top view 

void topview(Node* root){
    if(root == NULL) return;

    queue<pair<Node* , int>> q; // node, Hd
    map<int, int> ma; // HD , node data

    while(!q.empty()){
        auto [curr, hd] = q.front();
        q.pop();

        if(ma.count(hd) == 0){
            ma[hd]= curr->data;
        }

        if(curr->left) q.push({curr->left, hd-1});
        if(curr->right) q.push({curr->right, hd+1});
    }

    for(auto [hd, val]: ma){
        cout << val << " ";
    }
}


void kthlevel(Node* root, int k) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);
    int currlevel = 0;

    while (!q.empty()) {
        int levelsize = q.size();

        while (levelsize--) {
            Node* curr = q.front();
            q.pop();

            if (currlevel == k) {
                cout << curr->data << " ";
            }
            else {
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }

        if (currlevel == k) break; // No need to go further
        currlevel++;
    }
}
