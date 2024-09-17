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
using namespace std;



int main(){
vector <int> nodes={1,2,3,4,5,6,7};
node* root=buildtree(nodes);
}