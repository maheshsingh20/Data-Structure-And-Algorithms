/*#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left) {
            q.push(temp->left);
        }
        if (temp->right) {
            q.push(temp->right);
        }
    }
    cout << endl;
}

void buildLevelOrderTraversal(node*& root) {
    queue<node*> q;
    cout << "Enter data for root: ";
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        cout << "Enter left node for " << temp->data << endl;
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1) {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }
        cout << "Enter right node for " << temp->data << endl;
        int rightdata;
        cin >> rightdata;
        if (rightdata #!= -1) {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

int main(){
    node* root = NULL;
    buildLevelOrderTraversal(root);
    levelOrderTraversal(root);
    return 0;
}
*/


#include <iostream>
#include <queue>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
	node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

// // This is normal method to build tree using level order traversal
void buildlevelorder(node*& root) {
	queue<node*> q;
	cout << "Enter data for root element: " << endl;
	int data;
	cin >> data;
	root = new node(data);
	q.push(root);
	while (!q.empty()) {
		node* temp = q.front();
		q.pop();
		cout << "Insert left element node of " << temp->data << " (-1 in case no element left to insert)" << endl;
		int leftdata;
		cin >> leftdata;
		if (leftdata != -1) {
			temp->left = new node(leftdata);
			q.push(temp->left);
		}
		cout << "Insert right element of " << temp->data << " (-1 in case no element left to insert)" << endl;
		int rightdata;
		cin >> rightdata;
		if (rightdata != -1) {
			temp->right = new node(rightdata);
			q.push(temp->right);
		}
	}
}




// node* buildtree() {
// 	cout << "Enter data for node (-1 for no node): ";
// 	int data;
// 	cin >> data;
// 	if (data == -1) {
// 		return NULL;
// 	}
// 	node* root = new node(data);
// 	cout << "Enter data for left node of " << data << ": " << endl;
// 	root->left = buildtree();
// 	cout << "Enter data for right node of " << data << ": " << endl;
// 	root->right = buildtree();
// 	return root;
// }

void levelorderTraversal(node*& root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty()) {
		node* temp = q.front();
		q.pop();
		if (temp == NULL) {
			cout << endl;
			if (!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			cout << temp->data << " ";
			if (temp->left) {
				q.push(temp->left);
			}
			if (temp->right) {
				q.push(temp->right);
			}
		}
	}
}



// int heightoftree(node* root) {
// 	if (root == NULL) {
// 		return 0;
// 	}
// 	int left = heightoftree(root->left);
// 	int right = heightoftree(root->right);
// 	int ans = max(left, right) + 1;
// 	return ans;
// }


// void printkthnode(node* root, int k){
//     if(root == NULL){
//         return;
//     }
//     if(k == 0){
//         cout << root->data << " ";
//     } else {
//         printkthnode(root->left, k-1);
//         printkthnode(root->right, k-1);
//     }
// }



int main() {
	node* root = NULL;
	// Uncomment one of the methods below based on which tree-building method you want to use.

	buildlevelorder(root); // Build tree using level order  1 10 20 8 9 18 19 6 -1 7 -1 16 -1 17 -1 -1 -1 -1 -1 -1 -1 -1 -1
	//root = buildtree(); // Build tree using recursion  1 10 8 6 -1 -1 -1 9 7 -1 -1 -1 20 18 16 -1 -1 -1 19 17 -1 -1 -1 

	levelorderTraversal(root);
	// cout << "Height of the tree: " << heightoftree(root) << endl;
	printkthnode(root,3);
	return 0;
}


// #include <iostream>
// #include <queue>
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

// node* buildtreerec(node* root) {
//     cout << "Enter data (-1 for NULL node): ";
//     int data;
//     cin >> data;
//     if(data == -1){
//         return NULL;
//     }
//     root = new node(data);
//     cout << "Enter left of " << root->data << ": ";
//     root->left = buildtreerec(root->left);
//     cout << "Enter right of " << root->data << ": ";
//     root->right = buildtreerec(root->right);
//     return root;
// }

// void levelordertraversal(node* root){
//     if(root == NULL) return;
//     queue <node*> q;
//     q.push(root);
//     q.push(NULL);
//     while(!q.empty()){
//         node* temp = q.front();
//         q.pop();
//         if(temp == NULL){
//             cout << endl;
//             if(!q.empty()){
//                 q.push(NULL);
//             }
//         } else {
//             cout << temp->data << " ";
//             if(temp->left){
//                 q.push(temp->left);
//             }
//             if(temp->right){
//                 q.push(temp->right);
//             }
//         }
//     }
// }

// int countnodes(node* root){
//     if(root == NULL){
//         return 0;
//     }
//     int leftCount = countnodes(root->left);
//     int rightCount = countnodes(root->right);
//     return leftCount + rightCount + 1;
// }

// int heightofbst(node* root){
//     if(root==NULL){
//         return 0;
//     }
//     int leftcount=heightofbst(root->left);
//     int righttcount=heightofbst(root->right);
//     int ans=max(leftcount,righttcount)+1;
//     return ans;
// }


// int sumofnode(node* root){
//     if(root==NULL){
//         return 0;
//     }
//     int leftsum=sumofnode(root->left);
//     int rightsum=sumofnode(root->right);
//     int ans=root->data+leftsum+rightsum;
//     return ans;
// }

// int solve(node* root, int &diam){
//     if (root==NULL)
//     {
//         /* code */return 0;
//     }
//     int leftt=solve(root->left,diam);
//     int rightt=solve(root->right,diam);
//     diam=max(diam,leftt+rightt);
//     int ans=max(leftt,rightt)+1;
//     return ans;
// }

// int diameteroftree(node* root){
//     int d=0;
//     solve(root,d);
//     return d;
// }

// // int childrensum(node* root){
// //     if(root == NULL || (root->left == NULL && root->right == NULL)){
// //         return 1;
// //     }
// //     int t=root->left->data;
// //     int r=root->right->data;
// //     if((t+r)==root && childrensum(root->left) &&childrensum(root->right)){
// //         return 1;
// //     }else{
// //         return 0;
// //     }
// // }

// bool isIdentical(node* root1, node* root2) {
//     if (root1 == NULL && root2 == NULL) {
//         return true;
//     }
//     if (root1 == NULL || root2 == NULL) {
//         return false;
//     }
//     return (root1->data == root2->data) && isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
// }

// bool isSubtree(node* root, node* subroot) {
//     if (root == NULL) {
//         return false;
//     }
//     if (subroot == NULL) {
//         return true; // An empty tree is always a subtree
//     }
//     if (isIdentical(root, subroot)) {
//         return true;
//     }
//     return isSubtree(root->left, subroot) || isSubtree(root->right, subroot);
// }


// int main() {
//     node* root1 = NULL;
//     cout<<"Enter elements for root1: "<<endl; //1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
//     //root1 = buildtreerec(root1);   //1 10 8 6 -1 -1 -1 9 7 -1 -1 -1 20 18 16 -1 -1 -1 19 17 -1 -1 -1
//     //node* root2=NULL; //  2 4 -1 -1 5 -1 -1
//     //cout<<"Enter elements for root2: "<<endl;
//     //root2=buildtreerec(root2);
//     cout << "\nLevel Order Traversal:\n";
//     levelordertraversal(root1);
//     // cout << "\nTotal number of nodes: " << countnodes(root) << endl;
//     // cout<<"Height of tree is: "<<heightofbst(root)<<endl;
//     // cout<<"Sum of all nodes: "<<sumofnode(root)<<endl;
//     // cout<<"Diameter of tree is: "<<diameteroftree(root)<<endl;
//     //bool res=isSubtree(root1,root2);
//     // cout<<res;
//     return 0;
// }
