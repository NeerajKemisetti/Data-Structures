/* #include <iostream>
using namespace std;

struct LinkedList
{
    int data;
    LinkedList *next;
};

void printLinkedList(LinkedList *root)
{
    while(root)
    {
        printf("%d\n", root->data);
        root = root->next;
    }
}

int main()
{
    LinkedList *root, *second, *third;

    root = new LinkedList;
    second = new LinkedList;
    third = new LinkedList;

    root->data = 10;
    root->next =second;

    second->data =20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    printLinkedList(root);

    return 0;
} */



//Creating a Node
#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    int data;
    Node *next;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }

    Node(int k, int d)
    {
        key = k;
        data = d;
        next = NULL;
    }
};

class SinglyLinkedList
{
public:
    Node *head;
    SinglyLinkedList()
    {
        head = NULL;
    }
    SinglyLinkedList(Node *n)
    {
        head = n;
    }

    //1. check if node exits using key value
    Node *nodeExists(int k)
    {
        Node *temp = NULL;

        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }

    //2. Append a node to the list

    void appendNode(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node Already exists with key value : " << n->key << " . Append another node with different key value idiot " << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "node appended" << endl;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout << "node appended" << endl;
            }
        }
    }

    //3. Prepend a node in the beginning
    void prependNode(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node Already exists with key value : " << n->key << " . Prepend another node with different key value idiot " << endl;
        }
        else
        {
            n->next = head;
            head = n;
            cout << "Node prepended" << endl;
        }
    }
    //4. Insert a node after a particlar node in the list
    void insertNodeAfter(int k, Node *n)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "No Node exists with key value : " << k << endl;
        }
        else
        {
            if (nodeExists(n->key) != NULL)
            {
                cout << "Node Already exists with key value : " << n->key << " . Prepend another node with different key value idiot " << endl;
            }
            else
            {
                n->next = ptr->next;
                ptr->next = n;
                cout << "NOde inserted" << endl;
            }
        }
    }

    //5. Delete node by unique key
    void deleteNodeByKey(int k)
    {
        if (head == NULL)
        {
            cout << "singly linked list already empty dumbass" << endl;
        }
        else if (head != NULL)
        {
            if (head->key == k)
            {
                head = head->next;
                cout << " Node unlinkd with key value " << k << endl;
            }
            else
            {
                Node *temp = NULL;
                Node *prevptr = head;
                Node *currentptr = head->next;
                while (currentptr != NULL)
                {
                    if (currentptr->key == k)
                    {
                        temp = currentptr;
                        currentptr = NULL;
                    }
                    else
                    {
                        prevptr = prevptr->next;
                        currentptr = currentptr->next;
                    }
                }
                if (temp != NULL)
                {
                    prevptr->next = temp->next;
                    cout << "Node unlinked with key value : " << k << endl;
                }
                else
                {
                    cout << "Node Doesnt exist with key value : " << k << endl;
                }
            }
        }
    }

    //6. Update Node
    void updateNodeByKey(int k, int d)
    {
        Node *ptr = nodeExists(k);
        if (ptr != NULL)
        {
            ptr->data = d;
            cout << "Node data updated successfully " << endl;
        }
        else
        {
            cout << "Node doesnt exist with the key value: " << k << endl;
        }
    }

    //7. Printing
    void printList()
    {
        if(head ==NULL)
        {
            cout<< "No node in singly linked list";
        }
        else
        {
            cout<<endl<<"Songly Linked lsit values: ";
            Node* temp = head;

            while(temp!=NULL)
            {
                cout<<"("<<temp->key<<","<<temp->data<<") --> " <<endl<<endl;
                temp =temp->next;
            }
        }
        
    }
};

int main()
{
    SinglyLinkedList s;
    int option;
    int key1,k1,data1;
    do
    {
        cout<<"\nWhat operation do you want to perform? select option number.Enter 0 to exit. "<<endl;
        cout<<"1. appendNode() "<<endl;
        cout<<"2. prependNode() "<<endl;
        cout<<"3. insertNodeAfter() "<<endl;
        cout<<"4. deleteNodeByKey() "<<endl;
        cout<<"5. updateNodeByKey() "<<endl;
        cout<<"6. printList() "<<endl;
        cout<<"7. Clear Screen() "<<endl<<endl;
        
        cin>> option;
        Node* n1 = new Node();
        //Node n1;

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout <<"Append node operation \nEnter key & data of the node to be appended " <<endl;
            cin >>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;
            s.appendNode(n1);
            break;
        
        case 2:
            cout <<"Insert Node after operation \nEnter key of existing node after which you want to insert this new node: " <<endl;
            cin>>k1;
            cout<<"Enter key and data of the new node first "<<endl;
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;
            s.insertNodeAfter(k1,n1);

        case 3:
        cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
        cin >> k1;
        cout << "Enter key & data of the New Node first: " << endl;
        cin >> key1;
        cin >> data1;
        n1 -> key = key1;
        n1 -> data = data1;
 
        s.insertNodeAfter(k1, n1);
        break;
 
        case 4:
 
         cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
         cin >> k1;
         s.deleteNodeByKey(k1);
 
         break;
        case 5:
         cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
         cin >> key1;
        cin >> data1;
        s.updateNodeByKey(key1, data1);
 
        break;
       case 6:
       s.printList();
 
        break;
       case 7:
         system("cls");
          break;
        default:
         cout << "Enter Proper Option number " << endl;
       }
 
     } while (option != 0);
 
  return 0;
}
            

