#include <iostream>
#include <string>

using namespace std;
class NullPointerException;
template<class T>
class Gref
{
public:
    Gref():point(NULL){}
   explicit Gref(const T &x):point(&x){}
   const T &get()const
   {
      if(isNull()) throw "error";//NullPointerException();
      else return *point;
   }
   bool isNull()const
   {
       return point == NULL;
   }
private:
   const T *point;
};
class DSException
{
public:
    DSException(const std::string & msg = " "):message(msg){}
    virtual  ~DSException();
    virtual std::string TOstring()const 
    {
        return  "Exception"+std::string(": ")+what();
    }
    virtual std::string what()const
    {
        return message;
    }
private:
    std::string message;

};
class DuplicateItemDsEXception : public DSException
{
public:
    DuplicateItemDsEXception(const std::string &msg=" "):DSException(msg){}
};
class NullPointerException:public DSException
{
public:
    NullPointerException(const std::string & msg =""):DSException(msg){}
};
template<class T>
class redBlacktree;

template<class T>
class redBlackNode;

template<class T>
class redBlacktree
{
    public:
        enum {RED,BLACK};
        typedef redBlackNode<T> Node;
        redBlacktree(const T &negInf);
        ~redBlacktree();
        Gref<T> findMin()const;
        Gref<T> findMax()const;
        Gref<T> find(const T & x)const;
        void Insert(const T & x);
        void rotateWithLeftChild(Node *& k2)const;
        void rotateWithRightChild(Node *& k1)const;
        void doubleRotateWithLeftChild(Node *& k3)const;
        void doubleRotateRightChild(Node *& k1)const;
        void handleReoriend(const T & item);
        bool isEmpty()const;
        void makeEmpty();
        redBlackNode<T>* rotate(const T &item,Node *parent)const;
         // private: 测试
        void reclaimMemory(Node *t)const;
        Node *Header;
        Node *nullNode;
        Node *current;
        Node *parent;//父节点
        Node *grand;//祖父节点
        Node *great;//曾祖父节点
};

template<class T>
class redBlackNode
{
   // private:
public:
        T element;
        redBlackNode *left;
        redBlackNode *right;
        int color;
        redBlackNode(const T& theElement = T(),
                    redBlackNode *lt = NULL,
                    redBlackNode *rt = NULL,
                    int d = redBlacktree<T>::BLACK
                     ):element(theElement),left(lt),right(rt),color(d)
        {}
        friend class redBlacktree<T>;
};

template<class T>
redBlacktree<T>::redBlacktree(const T &negInf)
{
    nullNode = new Node();
    nullNode ->left = nullNode->right=nullNode;
    Header = new Node(negInf);
    Header->left=Header->right=nullNode;
}
template<class T>
redBlacktree<T>::~redBlacktree()
{
    delete nullNode;
    delete Header;
}
template<class T>
void redBlacktree<T>::Insert(const T &x)
{
    current = parent = grand = Header;
    nullNode ->element = x;
    while(current -> element !=x)
    {
        great = grand ; grand = parent; parent = current;
        current =x <current->element ? current ->left : current ->right;
        
        if(current ->left->color == RED&&current->right->color==RED)
            handleReoriend(x);
    }
    if(current != nullNode)
        throw "error";//DuplicateItemDsEXception();
    current = new Node(x,nullNode,nullNode);
    if(x<parent->element)
    {
        parent ->left =current;
    }
    else if(x>parent->element)parent ->right = current;
    handleReoriend(x);
}

template<class T>
void redBlacktree<T>::rotateWithLeftChild(Node *& k2)const
{
    Node *k1 = k2->left;
    k2 ->left = k1->right;
    k1->right = k2;
    k2= k1;
}

template<class T>
void redBlacktree<T>::rotateWithRightChild(Node *&k1)const
{
    Node *k2= k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1= k2;
}
template<class T>
void redBlacktree<T>::doubleRotateWithLeftChild(Node *& k3)const
{
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}
template<class T>
void redBlacktree<T>::doubleRotateRightChild(Node *& k1)const
{
    rotateWithLeftChild(k1->right);
    rotateWithRightChild(k1);
}
template<class T>
void redBlacktree<T>::handleReoriend(const T& item)
{
    //单旋转
    //双旋转
    //变色
    current -> color = RED;
    current -> left ->color = BLACK;
    current -> right->color = BLACK;
    if(parent -> color==RED)
    {
        grand -> color =RED;
        if(item<grand->element != item <parent ->element)
            parent = rotate(item ,grand);
        current = rotate(item,great);
        current -> color = BLACK;
    }
    Header->right ->color = BLACK;
}
template<class T>
redBlackNode<T> * redBlacktree<T>::rotate(const T &item,Node *theParent)const
{
    if(item < theParent->element)
    {
        item < theParent ->left->element ? 
            rotateWithLeftChild(theParent->left):
            rotateWithRightChild(theParent->left);
        return theParent->left;
    }
    else 
    {
        item < theParent->right->element ?
            rotateWithLeftChild(theParent->right):
            rotateWithRightChild(theParent->right);
            return theParent->right;
    }

}
template<class T>
bool redBlacktree<T>::isEmpty()const
{
    return Header ->right == nullNode;
}
template<class T>
void redBlacktree<T>::makeEmpty()
{
    reclaimMemory(Header->right);
    //Header -> right = nullNode;
}
template<class T>
void redBlacktree<T>::reclaimMemory(Node *t)const
{
    if(t != t->left)
    {
    reclaimMemory(t->left);
    reclaimMemory(t->right);
    delete t;
     }
}
template<class T>
Gref<T> redBlacktree<T>::findMin()const
{
    if(isEmpty())
        return Gref<T>();
    Node * itr =Header ->left;
    while(itr->left != nullNode)
        itr = itr->left;
    return Gref<T> (itr ->element);
}

template<class T>
Gref<T> redBlacktree<T>::findMax()const
{
    if(isEmpty())
        return Gref <T>();
    Node *itr = Header ->right;
    while(itr -> right != nullNode)
        itr = itr ->right;
    return Gref<T> (itr->element);
}
template<class T>
Gref<T> redBlacktree<T>::find(const T& x )const
{
    nullNode ->element = x;
    Node * curr=Header->right;

    for(;;)
    {
        if(x<curr->element)
            curr = curr -> left;
        else if(x>curr->element)
            curr = curr->right;
        else if(curr!= nullNode)
            return Gref<T> (curr->element);
        else 
            return Gref<T>();
    }
}
int main()
{
    const int NEG_INF = -99999;
    redBlacktree<int> t (NEG_INF);
    t.Insert(200);
    t.Insert(100);
    t.Insert(90);
    t.Insert(80);
    t.Insert(70);
    t.Insert(60);
    t.Insert(50);
    if(!t.isEmpty())std::cout<<"redblack is empty"<<std::endl;
    std::cout<<"min"<<t.findMin().get()<<std::endl;
    std::cout<<"max"<<t.findMax().get()<<std::endl;
    Gref<int> r = t.find(100);
    if(r.isNull()) cout<<"not find"<<endl;
    else cout<<"find is ok"<<endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

