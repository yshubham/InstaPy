#include<iostream>
using namespace std;

template<class X>
class BSTNode
{
public:
    int data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int value)
    {

        left=NULL;
        right=NULL;
        data=value;
    }
};

template<class Y>
class BST
{

public:
    BSTNode<Y>* root=NULL;

    void preOrder(BSTNode<Y> * root)
    {

        if(root)
        {
            cout<<root->data<<" ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    void postOrder(BSTNode<Y> * root)
    {

        if(root)
        {
            postOrder(root->left);
            postOrder(root->right);
            cout<<root->data<<" ";
        }
    }

    void inOrder(BSTNode<Y> * root)
    {

        if(root)
        {
            inOrder(root->left);
            cout<<root->data<<" ";
            inOrder(root->right);
        }
    }

    void search(Y data, BSTNode<Y>* root)
    {

        if(root==NULL)
        {
            cout<<"\nNot found\n";
            return;
        }
        if(root)
        {
            if(data==root->data)
            {
                cout<<"\nFound\n";
                return;
            }
            if(data<root->data)
                search(data,root->left);
            else
                search(data, root->right);
        }

    }

    void mirror(BSTNode<Y> *p)
    {
        BSTNode<Y>* temp;
        if(p->left || p->right)
        {
            if(p->left)
                mirror(p->left);
            if(p->right)
                mirror(p->right);
            temp=p->left;
            p->left=p->right;
            p->right=temp;
        }
        else
            return;
    }


    int height(BSTNode<Y>* node)
    {
        if(node==NULL)
            return 0;
        else
        {
            int leftheight = height(node->left);
            int rightheight = height(node->right);

            if (leftheight > rightheight)
                return(leftheight+1);
            else return(rightheight+1);
        }
    }

    int countLeafNode(BSTNode<Y>* root)
    {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right==NULL)
            return 1;
        else
            return countLeafNode(root->left)+countLeafNode(root->right);
    }

    int countNonLeafNode(BSTNode<Y>* root)
    {
        if(root == NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return 0;
        else
            return countNonLeafNode(root->left)+countNonLeafNode(root->right) + 1;
    }

    void insert(Y);
    void breadthFirst();

    BSTNode<Y>* deleteByCopying(Y,BSTNode<Y>*);
    BSTNode<Y>* deleteByMerging(Y, BSTNode<Y>*);

    BSTNode<Y>* findmin(BSTNode<Y>* root)    //to find min value node
    {
        if(root==NULL)return root;           //redundant
        BSTNode<Y>* node=root;
        while(root!=NULL)
        {
            if(root->left)node=root->left;
            root=root->left;
        }
        return node;
    }

    };

    template<class Y>
    void BST<Y>::insert(Y data)
    {
        BSTNode<Y>* node=new BSTNode<Y>(data);
        BSTNode<Y>* cur=root;
        BSTNode<Y>* parent;
        if(root==NULL)
        {
            root=node;
            return;
        }
        while(cur!=NULL)
        {
            parent=cur;
            if(data<parent->data)
                cur=cur->left;
            else
                cur=cur->right;
        }

        if(parent->data>data)
            parent->left=node;
        else
            parent->right=node;

    }

    template<class Y>
    BSTNode<Y>* BST<Y>::deleteByCopying(Y data, BSTNode<Y>* root)
    {
        if(root==NULL)
        {
            cout<<"\ncan't delete, element not found";
            return root;
        }
//..finding node which has the data to be deleted
        if(data<root->data) root->left=deleteByCopying(data,root->left);
        else if(data> root->data) root->right=deleteByCopying(data,root->right);

//deletion process
        else
        {
            BSTNode<Y>*temp=root;

            if(root->left==NULL && root->right==NULL) //no child case
            {
                delete root;
                root=NULL;
            }
            else if(root->left==NULL)  //one child case
            {
                root=root->right;
                delete temp;
            }
            else if(root->right==NULL)  //one child case
            {
                root=root->left;
                delete temp;
            }
            else
            {
                BSTNode<Y>* node = findmin(root->right); //two children
                root->data=node->data;
                root->right=deleteByCopying(node->data,node);
            }
        }
        return root;
    }

    template<class Y>
    BSTNode<Y>* BST<Y>::deleteByMerging(Y data, BSTNode<Y>* root)
    {
        if(root==NULL)
        {
            cout<<"\ncan't delete, element not found";
            return root;
        }
//..finding node which has the data to be deleted
        if(data<root->data) root->left=deleteByCopying(data,root->left);
        else if(data> root->data) root->right=deleteByCopying(data,root->right);

//deletion process
        else
        {
            BSTNode<Y>*temp=root;
            if(root->left==NULL && root->right==NULL) //no child case
            {
                delete root;
                root=NULL;
            }
            else if(root->left==NULL)  //one child case
            {
                root=root->right;
                delete temp;
            }
            else if(root->right==NULL)  //one child case
            {
                root=root->left;
                delete temp;
            }
            else
            {
                BSTNode<Y>* node = findmin(root->right); //two children
                node->left=root->left;
                root=root->right;
                delete temp;
            }
        }
        return root;
    }


//for breadth first traversal
    template<class Y>
    class QueueNode
    {

    public:
        BSTNode<Y> *info;
        QueueNode<Y> *next;

        QueueNode()
        {
            info=NULL;
            next=NULL;
        }

    };

    template<class Y>
    class Queue
    {


        QueueNode<Y>* head=NULL;
        QueueNode<Y>* tail=NULL;

    public:

        void enqueue(BSTNode<Y>* t)
        {
            QueueNode<Y> *node = new QueueNode<Y>();
            node->info=t;
            if(tail==NULL)
                head=tail=node;
            else
            {
                tail->next=node;
                tail=node;
            }
        }

        BSTNode<Y>* dequeue()
        {
            QueueNode<Y>* temp=head;
            if(head==NULL);
            else if(head==tail)
            {
                head=tail=NULL;
                return temp->info;
            }
            else if(head!=NULL)
            {

                head=head->next;
                return temp->info;
            }
        }

        bool isempty()
        {
            if(head==NULL)
                return true;
            else
                return false;
        }

    };

    template<class Y>
    void BST<Y>::breadthFirst()
    {
        Queue<Y> q;
        BSTNode<Y> *p=root;
        if(p)
        {
            q.enqueue(p);
            while(!q.isempty())
            {
                p=q.dequeue();
                cout<<p->data<<" ";
                if(p->left)
                    q.enqueue(p->left);
                if(p->right)
                    q.enqueue(p->right);
            }
        }
    }


    int main()
    {

        BST<int> tree;
        tree.insert(5);
        tree.insert(6);
        tree.insert(3);
        tree.preOrder(tree.root);
        cout<<endl;
        tree.insert(9);
        tree.postOrder(tree.root);
        cout<<endl;
        tree.insert(12);
        tree.insert(24);
        tree.insert(32);
        tree.inOrder(tree.root);
        cout<<endl;
        tree.root=tree.deleteByCopying(32,tree.root);
        tree.inOrder(tree.root);
        cout<<endl;
        tree.root=tree.deleteByMerging(5,tree.root);
        tree.breadthFirst();
        tree.root=tree.deleteByCopying(6,tree.root);
        cout<<endl;
        tree.breadthFirst();
        tree.search(25,tree.root);
        tree.search(9,tree.root);
        tree.insert(432);
        tree.insert(332);
        tree.insert(232);
        tree.insert(132);
        tree.breadthFirst();
        cout<<"\nLeaf Nodes= "<<tree.countLeafNode(tree.root);
        cout<<endl;
        cout<<"Non Leaf Nodes="<<tree.countNonLeafNode(tree.root);
    }