//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

int nodecounts(struct Node* tree){
    if(tree == NULL)
        return 0;
    
    int ans = 1+ nodecounts(tree->left)+nodecounts(tree->right);
    return ans;
}


bool isBst(struct Node* tree,int index, int cnt){
    if(tree==NULL){
       
        return true;
    }
     if(index>=cnt){
        return false;
    }
    else{
        bool left = isBst(tree->left,2*index+1,cnt);
        bool right = isBst(tree->right,2*index+2,cnt);
        return (left && right);
    }
}

bool isMax(struct Node* tree){
    if(tree->left==NULL && tree->right==NULL){
        return true;
    }
    else if(tree->right==NULL){
        return (tree->data > tree->left->data);
    }
    else{
        bool left = isMax(tree->left);
        bool right = isMax(tree->right);
        if(left && right &&(tree->data > tree->left->data && tree->data >tree->right->data)){
            return true;
        }else{
            return false;
        }
    }
}

class Solution {
  public:
    bool isHeap(struct Node* tree) {
        
        int index=0;
        int nodecount = nodecounts(tree);
        
        // code here
        if(isBst(tree,index,nodecount) && isMax(tree)){
            return true;
        }
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
// } Driver Code Ends