#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;
};

typedef struct TreeNode TreeNode;

TreeNode* createTreeNode(int value){
    TreeNode* newNode = new TreeNode();
    newNode -> value = value;
    newNode -> left = NULL;
    newNode -> right = NULL;

    return newNode;
}

void printInorder(TreeNode* root){
    if(root != NULL){
        printInorder(root -> left);
        cout << root -> value << " ";
        printInorder(root -> right);
    }
}

void printPreorder(TreeNode* root){
    if (root != NULL)
    {
        cout << root -> value << " ";
        printPreorder(root -> left);
        printPreorder(root -> right);
    }
}

void printPostorder(TreeNode* root){
    if (root != NULL)
    {
        printPostorder(root -> left);
        printPostorder(root -> right);
        cout << root -> value << " ";
    }
    
}

TreeNode* Insert(TreeNode *root, int data){
    if(root == NULL) {
        return root = createTreeNode(data);
    }
    if(data > root -> value)
        root -> right = Insert(root -> right, data);
    else
        root -> left = Insert(root -> left, data);
    
    return root;
}

TreeNode* Search(TreeNode* root, int data) {
    if(root == NULL) return NULL;

    if(root -> value == data) return root;
    else if(data < root -> value) return Search(root -> left, data);
    else return Search(root -> right, data);
}

TreeNode* rightMost(TreeNode *root){
    while (root && root -> right)
    {
        root = root -> right;
    }
    return root;
}

TreeNode* Delete(TreeNode* root, int data){
    if(!root)
        return NULL;
    if(data < root -> value)
        root -> left = Delete(root -> left, data);
    else if(data > root -> value)
        root -> right = Delete(root -> right, data);
    else {
        if (root -> left == NULL)
        {
            TreeNode *temp = root -> right;
            delete root;
            return temp;
        }
        else if(root -> right == NULL){
            TreeNode *temp = root -> left;
            delete root;
            return temp;
        }
        else {
            TreeNode *temp = rightMost(root -> left);
            root -> value = temp -> value;
            root -> left = Delete(root -> left, temp -> value);
        }
    }
    return root;
}

int main() {
    int arr[] = {50, 72, 56, 92, 30, 45, 40, 25, 100, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    TreeNode* root = NULL;

    for(int i=0; i<n; i++)
        root = Insert(root, arr[i]);

    //-----------Test Tree Traversal------------
    // TreeNode* root = createTreeNode(1);
    // root->left = createTreeNode(2);
    // root->right = createTreeNode(3);
    // root->left->left = createTreeNode(4);
    // root->left->right = createTreeNode(5);

    printInorder(root);
    cout << endl;
    printPreorder(root);
    cout << endl;
    printPostorder(root);
    cout << endl;

    if(Search(root, 30)!=NULL)
        cout << "Found\n";
    else
        cout << "Not Found\n";

    Delete(root, 92);
    cout << endl;
    printInorder(root);

    Delete(root, 50);
    cout << endl;
    printInorder(root);

    return 0;
}