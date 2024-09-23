#include <iostream>
#include <queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildtree(){
    node* root=NULL;
    cout<<"Enter data: "<<endl;
    int data;
    cin>> data;
    if(data==-1){
        return NULL;
    }
    root=new node(data);
    root->left=buildtree();
    root->right=buildtree();
    return root;
}

void traversal(node* root){
    queue <node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
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

int solve(node* root, int &diam){
    if(root==NULL){
        return 0;
    }
    int l=solve(root->left, diam);
    int r=solve(root->right, diam);
    diam=max(diam, l+r);
    return max(l, r)+1;
}
int diameter(node* root){
    int diam=0;
    solve(root, diam);
    return diam;
}

pair<bool, int> solveforIsbalanced(node* root) {
    if (root == NULL) {
        return make_pair(true, 0);
    }
    pair<bool, int> leftt = solveforIsbalanced(root->left);
    pair<bool, int> rightt = solveforIsbalanced(root->right);
    
    int height = max(leftt.second, rightt.second) + 1;
    bool leftans = leftt.first;
    bool rightans = rightt.first;
    bool diff = abs(leftt.second - rightt.second) <= 1;
    bool ans = leftans && rightans && diff;
    
    return make_pair(ans, height);
}





bool isBalanced(node* root){
    return solveforIsbalanced(root).first;
}


bool isIdentical(node* root1, node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1==NULL || root2==NULL){
        return false;
    }
    return (root1->data==root2->data && isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right));
}



bool isSubTree(node* root1, node* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    if (root1 == NULL || root2 == NULL) {
        return false;
    }
    if (root1->data == root2->data) {
        if (isSubTree(root1->left, root2->left) && isSubTree(root1->right, root2->right)) {
            return true;
        }
    }
    return isSubTree(root1->left, root2) || isSubTree(root1->right, root2); // Corrected recursion logic
}

int sum(node* r){
    if (r==NULL)
    {
        /* code */
        return 0;
    }
    
}

bool sumtree(node* root){
    if(root==NULL){
        return true;
    }
    int leftt=sumtree(root->left);
    int rightt=sumtree(root->right);
    if(left)
}


void freeTree(node* root){
    if(root==NULL){
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main(){
    node* root=buildtree();  //1 2 3 -1 -1 4 5 -1 -1 6 -1 -1 7 -1 8 -1 9 10 11 -1 -1 12 -1 -1 13 -1 -1
    node* root2=buildtree(); //1 2 3 -1 -1 4 5 -1 -1 6 -1 -1 7 -1 8 -1 9 10 11 -1 -1 12 -1 -1 13 -1 -1
    
    cout<<"Level order traversal for tree 1 is: "<<endl;
    traversal(root);
    cout<<"Level order traversal for tree 2 is: "<<endl;
    traversal(root2);



    //cout<<"Diameter of the tree is: "<<diameter(root)<<endl;
    // if(isBalanced(root)){
    //     cout<<"The tree is balanced"<<endl;
    // }else{
    //     cout<<"The tree is not balanced"<<endl;
    // }


    // if(isIdentical(root, root2)){
    //     cout<<"The trees are identical"<<endl;
    // }
    // else{
    //     cout<<"The trees are not identical"<<endl;
    // }


    if(isSubTree(root,root2)){
        cout<<"True";
    }
    else{
        cout<<"false: ";
    }


    
    freeTree(root);

    return 0;
}