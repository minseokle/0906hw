#include <iostream>

using namespace std;

class Node
{
public:
    Node(char val);
    ~Node();
    void preorder(char*result,int &index);
    void inorder(char*result,int &index);
    void postorder(char*result,int &index);
    void add(char r,char l);
    Node* search(char search);
private:
    char value;
    Node *rchild=nullptr;
    Node *lchild=nullptr;
};

Node::Node(char val)
{
    value=val;
}
Node::~Node()
{
    if(rchild!=nullptr)
    {
        delete rchild;
    }
    if(lchild!=nullptr)
    {
        delete lchild;
    }
}

void Node::add(char r, char l)
{
    if(r!='.')
    {
        rchild=new Node(r);
    }
    if(l!='.')
    {
        lchild=new Node(l);
    }
}
Node* Node::search(char search)
{
    if(value==search)
    {
        return this;
    }
    if(rchild!=nullptr)
    {
        Node* result=rchild->search(search);
        if(result!=nullptr)
        {
            return result;
        }
    }
    if(lchild!=nullptr)
    {
        Node* result=lchild->search(search);
        if(result!=nullptr)
        {
            return result;
        }
    }
    return nullptr;
}

void Node::inorder(char *result, int &index)
{
    if(lchild!=nullptr)
    {
        lchild->inorder(result,index);
    }
    result[index]=value;
    index++;
    if(rchild!=nullptr)
    {
        rchild->inorder(result,index);
    }
}

void Node::postorder(char *result, int &index)
{

    if(lchild!=nullptr)
    {
        lchild->postorder(result,index);
    }
    if(rchild!=nullptr)
    {
        rchild->postorder(result,index);
    }
    result[index]=value;
    index++;
}

void Node::preorder(char *result, int &index)
{
    result[index]=value;
    index++;
    if(lchild!=nullptr)
    {
        lchild->preorder(result,index);
    }
    if(rchild!=nullptr)
    {
        rchild->preorder(result,index);
    }
}

int main()
{
    int num;
    cin>>num;
    Node* tree1;
    {
        char parent;
        char rchild;
        char lchild;
        cin>>parent>>lchild>>rchild;
        tree1= new Node(parent);
        tree1->add(rchild,lchild);
    }
    for(int i=1;i<num;i++)
    {
        char parent;
        char rchild;
        char lchild;
        cin>>parent>>lchild>>rchild;
        tree1->search(parent)->add(rchild,lchild);
    }
    {
        char*result=new char[num+1];
        int index=0;
        tree1->preorder(result,index);
        cout<<result<<endl;
        delete [] result;
    }
    {
        char*result=new char[num+1];
        int index=0;
        tree1->inorder(result,index);
        cout<<result<<endl;
        delete [] result;
    }
    {
        char*result=new char[num+1];
        int index=0;
        tree1->postorder(result,index);
        cout<<result<<endl;
        delete [] result;
    }

    delete tree1;
    return 0;
}
