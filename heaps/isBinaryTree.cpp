#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int val;
    Node *right;
    Node *left;
    Node(int val)
    {
        this->val = val;
    }
};

bool isMax(Node* root){
    if(root == NULL) return true;
    if(root->left && root->val< root->left->val) return false;
    if(root->right && root->val< root->right->val) return false;
    isMax(root->left);
    isMax(root->right);
    return true;
}

int main()
{
    Node *a = new Node(20);
    Node *b = new Node(15);
    Node *c = new Node(10);
    Node *d = new Node(8);
    Node *e = new Node(11);
    Node *f = NULL;
    Node *g = new Node(6);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    cout<<isMax(a)<<endl;

    
}