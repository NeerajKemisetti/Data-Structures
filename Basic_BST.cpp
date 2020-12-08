/* NOTES:
0. In a BST, a node at max can have two childrens(Left, Right)
1. Binary Search tree is a binary tree data structure which has the following properties:
    a. The left subtree of a node 'A' should contain all the nodes with lesser value that 'A'.
    b. The right subtree of a node 'A' should contain all the nodes with higher value than 'A'
    c. The left and right subtree also must be a binary search tree
2. It is like having sorted data in tree.
3. In-order to have sorted data in a tree, tree should also have above three properties.

BENEFITS:
0. Instead of using sorted array if we use BST then complexity of Insert, Delete becomes log(n).

COMPLEXITY:
0. Search, Insert, Delete Complexity: log2(n)
1. Space complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;
    Node(int data): data{data}, right{nullptr}, left{nullptr} {};
};

Node* insert(Node* head, int data)
{
    if(head == nullptr) return new Node(data);
    if(head->data > data)
    {
        head->left = insert(head->left, data);
    }
    else
    {   
        head->right = insert(head->right, data);
    }
    return head;
}

void search(Node* head, int data)
{
    if(head == NULL)    return false;
    else if(head->data == data)     return true;
    else if(data<=head->data)   return search(head->left, data);
    else    return search(head->right, data);
}

int findMin(Node* head)
{
    if(head==NULL)
    {
        cout <<"ERROR: TREE is EMPTY\n";
        return -1;
    }
    else if(head->left == NULL)
    {
        return head->data;
    }
    return findMin(head->left);
}

int findMax(Node* head)
{
    if(head == NULL)
    {
        cout << "ERROR: Tree is empty\n";
        return -1;
    }
    else if(head->right == NULL)
    {
        return head->data;
    }
    return findMax(head->right);
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
    int N, val;
    cin >>N;
    cin >>val;
    N--;
    Node* head = insert(nullptr, val);
    while(N--)
    {
        cin >> val;
        insert(head, val);
    }
    printInOrder(head);
    int number;
    cin>>number;
    if(search(head,number)==true)   cout<<"Found\n";
    else    cout<<"Not Found\n";
    return 0;
}
