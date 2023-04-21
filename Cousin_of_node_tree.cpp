#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node *left, *right;
        node(int d){data = d;}
};

node* addNode(node* root, int data){
    node *temp = new node(data);
    temp->left = temp->right = NULL;
    if(root == NULL)
        return temp;
    node *cur = root, *p = NULL;
    while(cur != NULL){
        p = cur;
        if(data > cur->data)
            cur = cur->right;
        else
            cur = cur->left;
    }
    if(data > p->data)
        p->right = temp;
    else
        p->left = temp;
    return root;
}
//Level order traversal using queue
void getDepth(node* root, int ele){
    if(root == NULL)
        return;
    bool found =false;
    queue<node*> q;
    q.push(root);
    node* temp;
    while(q.empty() == false){
        int size = q.size();
        while (size--){
            temp = q.front();
            q.pop();
            if(temp->left->data == ele || temp->right->data == ele){
                found = true;
            }else{
                if(temp->left != NULL)
                    q.push(temp->left);
                if(temp->right != NULL)
                    q.push(temp->right);
            }
        }
        if(found){
            while (!q.empty()){
                cout<<q.front()->data<<" ";
                q.pop();
            }
        }
    }
    return;
}

int main(){
    int n, temp;
    cin>>n;
    node* root;
    for(int i=0; i<n; i++){
        cin>>temp;
        root = addNode(root, temp);
    }
    return 0;
}