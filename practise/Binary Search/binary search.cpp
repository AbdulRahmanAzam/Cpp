// build tree
// levelOrderTraversal
// inorder
//pre order
//post order
// buildFromLevelOrder


#include <iostream>
#include <queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    
    public:
    node(int d) : data(d), left(NULL), right(NULL) {}
};
node* buildTree(node* root){
    int data;
    cout << "Enter the data" << endl;
    cin >> data;
    
    root = new node(data);
    
    if(data == -1){
        return NULL;
    }
    
    cout << "Enter the data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    
    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        
        if(temp == NULL){ // shows that purana level complete ho chuka he
            cout << endl;
            
            if(!q.empty()){ //  queue isnt finished yet (seperator)
                q.push(NULL);
            }
        }else{
            cout << temp->data << " ";
            if(temp->left)
                q.push(temp->left);
            
            if(temp->right)
                q.push(temp->right);
        }
    }
}

void inorder(node* root){
    if(root == NULL)
        return;
        
    inorder(root->left);
    cout << root -> data << "  ";
    inorder(root->right);
}

void preorder(node* root){
    if(root == NULL)
        return;
        
    cout << root -> data << "  ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root == NULL)
        return;
    
    postorder(root->left);
    postorder(root->right);
    cout << root->data << "  ";
}

void buildFromLevelOrder(node* &root){
    queue<node*> q;
    cout << "Enter data" << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);
    
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        
        // inserting left part
        cout << "Enter left of: " << temp->data << endl;
        int leftdata;
        cin >> leftdata;
        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }
        
        // inserting right part
        cout << "Enter right of: " << temp->data << endl;
        int rightdata;
        cin >> rightdata;
        if(rightdata != -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

int main() {
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node* root = NULL;
    // root = buildTree(root);
    // levelOrderTraversal(root);
    // cout << "\ninorder Traversal is:  " << endl;
    // inorder(root);
    // cout << "\nPreorder Traversal is:  "  << endl;
    // preorder(root) ;
    // cout << "\nPostorder Traversal is:  " << endl;
    //  postorder(root);
    
    buildFromLevelOrder(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    levelOrderTraversal(root);
}




