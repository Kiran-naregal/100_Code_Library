#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node *left, *right;
};

node* addNode(int data, node *root){
    node *temp = new node;
    temp->left = temp->right = NULL;
    temp->data = data;
    if(root == NULL)
        return temp;
    node *p = NULL, *cur = root;
    while(cur != NULL){
        p = cur;
        if(cur->data > data)
            cur = cur->left;
        else
            cur = cur->right;
    }
    if(data > p->data)
        p->right = temp;
    else
        p->left = temp;
    return root;
}

int tree_height(node *root){
    if(root==NULL)
        return 0;
    int l = tree_height(root->left)+1;
    int r = tree_height(root->right)+1;
    return max(l, r);
}

void print_level(int level, node *root){
    if(root == NULL)
        return;
    if(level == 1)
        cout<<root->data<<" ";
    else{
        print_level(level-1, root->left);
        print_level(level-1, root->right);
    }
}

void level_order(node *root){
    int n = tree_height(root);
    for(int i=1; i<=n; i++){
        print_level(i, root);
        cout<<endl;
    }
}

int main(){
    node *root = NULL;
    int n, temp;
    cin>>n;
    for(int i=0; i<n ;i++){
        cin>>temp;
        root = addNode(temp, root);
    }
    level_order(root);
    return 0;
}