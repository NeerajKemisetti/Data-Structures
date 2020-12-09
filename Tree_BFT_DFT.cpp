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

//INORDER DFT

void Inorder(Node* root)
{
    if(root == NULL)   return;
    Inorder(root->left);
    cout << root->data <<" ";
    Inorder(root->right);
}

// POSTORDER DFT

void Postorder(Node* root)
{
    if(root == NULL)    return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

int FindHeight(Node* root)
{
    if(root == NULL)
        return -1;
    int left = FindHeight(root->left);
    int right = FindHeight(root->right);
    return (left<right)? right+1: left+1;
   //return max(left,right)+1;
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
    int N,h;
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
    h = FindHeight(root);
    cout << "\n"<<h<<"\n";
    return 0;
}
