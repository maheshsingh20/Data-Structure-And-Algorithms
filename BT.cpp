// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;

// class node {
// public:
//     int data;
//     node* left;
//     node* right;
//     node(int data) {
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };

// // Build tree function
// node* buildTree() {
//     int data;
//     cout << "Enter data: ";
//     cin >> data;
//     if (data == -1) {
//         return NULL;
//     }
//     node* newNode = new node(data);
//     cout << "Enter data for the left of " << data << ": " << endl;
//     newNode->left = buildTree();
//     cout << "Enter data for the right of " << data << ": " << endl;
//     newNode->right = buildTree();
//     return newNode;
// }

// // Level order traversal function
// void levelOrderTraversal(node* root) {
//     if (root == NULL) {
//         return;
//     }
//     queue<node*> q;
//     q.push(root);
//     q.push(NULL);

//     while (!q.empty()) {
//         node* temp = q.front();
//         q.pop();

//         if (temp == NULL) {
//             cout << endl;  // End of current level
//             if (!q.empty()) {
//                 q.push(NULL);  // Insert NULL to mark the end of the next level
//             }
//         } else {
//             cout << temp->data << " ";
//             if (temp->left) {
//                 q.push(temp->left);
//             }
//             if (temp->right) {
//                 q.push(temp->right);
//             }
//         }
//     }
// }

// // Helper function for calculating diameter
// int helperofDiameter(node* root, int &diam) {
//     if (root == NULL) {
//         return 0;
//     }

//     int leftt = helperofDiameter(root->left, diam);
//     int rightt = helperofDiameter(root->right, diam);

//     // Update the diameter if the current path is larger
//     diam = max(diam, leftt + rightt);

//     // Return the height of the current node
//     return max(leftt, rightt) + 1;
// }

// // Function to calculate diameter
// int diameter(node* root) {
//     int diam = 0;
//     helperofDiameter(root, diam);
//     return diam;
// }

// // Helper function to find elements at the k-th level
// void KthLevelHelperFunction(node* root, int k, vector<int> &result) {
//     if (root == NULL || k < 0) {
//         return;
//     }

//     if (k == 0) {
//         result.push_back(root->data);
//         return;
//     }

//     KthLevelHelperFunction(root->left, k - 1, result);
//     KthLevelHelperFunction(root->right, k - 1, result);
// }

// // Function to get the elements at the k-th level
// vector<int> KthLevel(node* root, int k) {
//     vector<int> result;
//     KthLevelHelperFunction(root, k, result);
//     return result;
// }


// int LCA(node* root){

// }

// int main() {
//     node* root = buildTree();   // Build the tree
//     cout << "Level order traversal of the tree:" << endl;
//     levelOrderTraversal(root);  // Perform level-order traversal

//     // Print the diameter of the tree
//     cout << "Diameter of tree is: " << diameter(root) << endl;

//     // Print the elements at the 3rd level
//     vector<int> kthLevelNodes = KthLevel(root, 3);
//     cout << "Elements at the 3rd level of the tree: ";
//     for (int val : kthLevelNodes) {
//         cout << val << " ";
//     }
//     cout << endl;

//     return 0;
// }


#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* btrec(){
    int data;
    cout << "Enter data (-1 for no node): ";
    cin >> data;
    
    if(data == -1){
        return NULL;
    }
    
    node* root = new node(data);
    
    cout << "Enter data for left of " << data << ": ";
    root->left = btrec();
    
    cout << "Enter data for right of " << data << ": ";
    root->right = btrec();
    
    return root;
}

void levelordertraversal(node* root){
    if(root == NULL) return;

    queue<node*> q;
    q.push(root);
    q.push(NULL); // Marker for new level
    
    while (!q.empty()){
        node* temp = q.front();
        q.pop();
        
        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL); // Add marker for next level
            }
        }else{
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

bool solveforLCA(node* root, int n, vector<int> &path){
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data==n) return true;
    int leftt=solveforLCA(root->left,n,path);
    int rightt=solveforLCA(root->right,n,path);
    if(leftt||rightt){
        return true;
    }
    path.pop_back();
    return false;
}

vector<int> pathofnode(node* root, int k){
    vector<int> path;
    solveforLCA(root, k,path);
    return path;
}

int lowestCommonAncestor(node* root, int k ,int j){
    vector<int> path1;
    vector<int> path2;

    solveforLCA(root ,k,path1);
    solveforLCA(root ,j,path2);
    int LCA=0;
    for(int i=0,j=0;i<path1.size() && j<path2.size();i++,j++){
        if(path1[i]!=path2[j]){
            break;
        }else{
            LCA=path1[i];
        }
    }
    return LCA;
}



int main(){
    node* root = btrec();
    cout << "Level Order Traversal:" << endl;
    levelordertraversal(root);
    int res=lowestCommonAncestor(root, 8, 7);
    cout << "Lowest Common Ancestor: " << res << endl;
    cout<<"Path of node is: ";
    vector<int> path = pathofnode(root, 6);
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
    return 0;
}
