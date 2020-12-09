#include <bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    Node* left;
    Node* right;
    Node(char data): data(data), right{nullptr}, left{nullptr} {};
};

Node* insert(Node* root, char data)
{
    if(root == nullptr) return new Node(data);
    if(root->data > data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// BFT

void LevelOrder(Node* root)
{
    if(root ==NULL)
        return;
    queue<Node*> Q;
    Q.push(root);
    //while there is atleast one discovered node
    while(!Q.empty())
    {
        Node* current = Q.front();
        cout << current->data<< " ";
        if(current->left != NULL)   Q.push(current->left);
        if(current->right != NULL)  Q.push(current->right);
        Q.pop();
    }
}

// PREORDER DFT

void Preorder(Node* root)
{
    if(root == NULL)    return;
    cout<< root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
} 

void Inorder(Node* root)
{
    if(root == NULL)   return;
    Inorder(root->left);
    cout << root->data <<" ";
    Inorder(root->right);
}

void Postorder(Node* root)
{
    if(root == NULL)    return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}


void printInOrder(Node* head)
{
    if(head ==NULL)
        return ;
    printInOrder(head->left);
    cout << head->data << " ";
    printInOrder(head->right);
}


int main()
{
    int N;
    char val;
    cin>>N;
    cin>>val;
    N--;
    Node* root = insert(nullptr, val);
    while(N--)
    {
        cin>>val;
        root = insert(root, val);
    }
    printInOrder(root);
    cout<<'\n';
    LevelOrder(root);
    return 0;
}
