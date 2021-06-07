#include<bits/stdc++.h>
using namespace std;

struct Node{

    int data ;       // data stored in each node
    Node* left;   // pointer to left child
    Node* right; // poimter to right child
};

Node* rootptr;  // pointer to root node

Node* GetNewNode(int data)      // creates new node and returns address of node
{
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
}

void Insert(Node* rootptr,int data)
{
        if(rootptr == NULL)
        {
            rootptr = GetNewNode(data);
        }

        else
        {
            if(data<=rootptr->data)
            {
                     Insert(rootptr->left,data);
            }

            else 
            {
                Insert(rootptr->right,data);
            }
        }
        
}


int main()
{
        rootptr = NULL; // initially empty tree

        /// Inserting nodes in the tree
        Insert(rootptr,15);
       // Insert(rootptr,10 );
        //Insert(rootptr,20);

        cout<<"Hello"<<endl;
        cout<<rootptr->data<<endl;
        //cout<<(rootptr->left)->data;
       // cout<<(rootptr->right)->data;
}
