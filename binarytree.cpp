#include  <iostream>
using namespace std;

struct TreeNode{
 int value;
 TreeNode * left;
 TreeNode * right;

 TreeNode(int val): value(value), left(nullptr), right(nullptr) {};
};

void inordertraversal(TreeNode * node){
    if(node){
        inordertraversal(node->left);
        cout << node-> value<< "";
        inordertraversal(node->right);
    }
}
void preordertraversal(TreeNode * node){
    if(node){
        cout << node->value << "";
        preordertraversal(node ->left);
        preordertraversal(node ->right);
    }
}

void postordertraversal(TreeNode * node){
    if(node){
        postordertraversal(node->left);
        postordertraversal(node->right);
        cout << node->value;
    }
}

int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root-> left-> right = new TreeNode(5);

    cout << "Inorder traversal";
    inordertraversal(root);
    cout << endl;

    cout << "Preorder traversal";
    preordertraversal(root);
    cout << endl;

    cout << "Postorder traversal";
    postordertraversal(root);
    cout << endl;

    
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;



}
