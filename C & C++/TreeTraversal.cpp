#include"bits/stdc++.h"
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(struct Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node* root){
    if(root == NULL){
        return;
    }
    
    preorder(root->left);
    cout<<root->data<<" ";
    preorder(root->right);
}

void postorder(struct Node* root){
    if(root == NULL){
        return;
    }
    
    preorder(root->left);
    preorder(root->right);
    cout<<root->data<<" ";
}

int sumoftree(Node* root){
    if(root == NULL){
        return 0;
    }
    return sumoftree(root->left) + sumoftree(root->right) + root->data;
}

int totalnodes(Node* root){
    if(root == NULL){
        return 0;
    }
    return totalnodes(root->left) + totalnodes(root->right) + 1;
}

void sumreplacement(Node* root){
    if(root == NULL){
        return;
    }
    sumreplacement(root->left);
    sumreplacement(root->right);

    if(root->left!=NULL){
        root->data+=root->left->data;
    }

    if(root->right!=NULL){
        root->data+=root->right->data;
    }
}

int height(Node*root){
    if(root==NULL){
        return 0;
    }

    return max(height(root->left),height(root->right)) + 1;
}

bool isbalanced(Node* root){
    if(root == NULL){
        return true;
    }
    if(isbalanced(root->left) == false){
        return false;
    }
    if(isbalanced(root->right) == false){
        return false;
    }
    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh-rh)<=1){
        return true;
    }
}

void levelordertraversal(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* node = q.front();
        if(node!=NULL){
            cout<<node->data;
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
            else if(!q.empty()){
                q.push(NULL);
            }
    }
}
/*
         1
        / \
       2   3
      /
     4
*/

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    preorder(root);
    cout<<"\n";
    inorder(root);
    cout<<"\n";
    postorder(root);
    cout<<"\n";
    levelordertraversal(root);
    cout<<"\n"<<sumoftree(root);
    cout<<"\n"<<totalnodes(root);
    sumreplacement(root);
    cout<<"\n";
    preorder(root);
    cout<<"\n";
    if(isbalanced(root)==true){
        cout<<"Tree is Balanced";
    }
    else{
        cout<<"Tree is Unbalanced";
    }
    return 0;
}