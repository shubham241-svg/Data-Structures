class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data;
        left = right = NULL;
    }
};
static int idx = -1;

Node *buildTree(vector<int> &nodes)
{
    idx++;
    if (nodes[idx] == -1)
    {
        return NULL;
    }

    Node *currnode = new Node(nodes[idx]);
    currnode->left = buildTree(nodes);
    currnode->right = buildTree(nodes);

    return currnode;
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// basic levelorder
void levelOrder(Node* root){

    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);


    }
}

// line by line order 

void levelOrderlinebyline(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr == NULL){

            cout << endl;
            if(q.empty()){
                break;
            }
            q.push(NULL);
            continue;
        }
        
        cout << curr->data;

        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}

// void height of the tree

int height(Node* root){
    if(root == NULL) return 0;

    int leftHt = height(root->left);
    int rightHt = height(root->right);

    return max(leftHt, rightHt) + 1;
}

int count(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftCount = count(count->left);
    int rightCount = count(count->right);

    return leftCount + rightCount + 1;
}

int sum(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftsum = sum(root->left);
    int rightsum = sum(root->right);

    return leftsum + rightsum + root->data;
}


int diam1(Node* root){
    if(root == NULL){
        return 0;
    }

    int currDiam = height(root->left) + height(root->right) + 1;
    int leftdiam = diam1(root->left);
    int rightdiam = diam1(root->right);

    return max(currDiam, max(leftdiam, rightdiam));
}

// O(N)

pair<int, int> diam2(Node* root){
    if(root == NULL){
        return {0, 0};
    }

    pair<int, int> leftInfo = diam2(root->left);
    pair<int, int> rightInfo = diam2(root->right);

    int currdiam = leftInfo.second + rightInfo.second + 1;
    int finaldiam = max(currdiam, max(leftInfo.first, rightInfo.first));
    int finalHt = max(leftInfo.second, rightInfo.second) + 1;

    return make_pair(finalDiam, finalHt);
}


//
pair<int, int> minimaxi(int a, vector<int> Backlinks){
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(int i=0; i<Backlinks.size(); i++){
        if(Backlinks[i] == a){
            mini = min(mini, i);
            maxi = max(maxi, i);
        }
        }

        return {mini, maxi};
}
vector<string> sorter(vector<string> Webpage, vector<int> Backlink){

    priority_queue<pair<int, string>> pq;
    vector<string> ans;
    unordered_map<int, int> uma;

    for(int i = 0; i < Webpage.size(); i++){
        pq.push({Backlink[i], Webpage[i]});
        uma[Backlink[i]]++;       
    }

    pair<int, int> pari;
    while(!pq.empty()){
        auto it = pq.top();

        if(uma[it.first] > 1){
            pari = minimaxi(it.first, Backlink);

            int minyu = pari.first;
            int maxiyu = pari.second;

            while(minyu <= maxiyu){
                ans.push_back(Webpage[minyu])
                pq.pop();
                minyu++;
            
            }

            continue;
        }

        pq.pop();
    }

    return ans;
}



class Heap{

    vector<int> v;

    public:
        void push(val){

            // step 1:

            v.push_back(val);

            // fix heap;
            int chi = v.size() -1;
            int pari = (chi -1)/2;

            while(pari >= 0 && v[chi] > v[parI]){
                swap(v[chi], v[parI]);
                chi = parI;
                parI = (chi -1)/2;
            }
        }

        void heapify(int i){
            leftchi = 2*i + 1;
            rightchi = 2*i + 2;
            int maxi = i;

            if(leftchi < v.size() && v[leftchi] > v[maxi]){
                maxi = leftchi;
            }

            if(rightchi < v.size() && v[rightchi] > v[maxi]){
                maxi = rightchi;
            }

            if(maxi != i){
                swap(v[maxi], v[i]);
                heapify(maxI);
            }
        }

        void pop(){
            swap(v[0], v[v.size()-1]);

            v.pop_back();

            heapify(0);
        }


    
}

void heapfy(int i, vector<int> &arr, int n){

    

    int leftchi = 2*i + 1;
    int rightchi = 2*i + 2;
    maxi = i;

    if(leftchi < n && arr[leftchi] > v[i]){
        maxi = leftchi;
    }
    if(leftchi < n && arr[rightchi] > v[i]){
        maxi = rightchi;
    }

    if(maxi != i){
        swap(arr[i], arr[maxi]);
        heapify(maxi, arr);

    }


}

void heapsort(vector<int> &arr){

    int n = arr.size();

    for(int i = n/2 -1; i>= 0; i--){
        heapify(i, arr);
    }

    for(int i = n - 1; i>= 0; i--){
        swap(arr[0], arr[i]);
        heapify(0, arr, i);
    }
}