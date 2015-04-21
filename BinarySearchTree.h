// Assignment #6

// Name: Tyler Woo

// ASU Email Address: twoo2@asu.edu

// Description: Header file containing class information for binary search tree

#include <iostream> //to use cout

#include <string> //to use strings

using namespace std;

//ZipInfo represents some ip address

class ZipInfo

 {

  private: 

    string city, state, zipcode;

    ZipInfo * left, * right, * parent;

  public:

    //The following three functions are constructors

    ZipInfo()

     { 

      city = "?";

      state = "?";

      zipcode = "?";

      parent = NULL;

      left = NULL;

      right = NULL;

     }

    ZipInfo(string city1, string state1, string zip1)

     {

      zipcode = zip1;

      city = city1;

      state = state1;

      parent = NULL;

      left = NULL;

      right = NULL;

     }

     ZipInfo(string city1, string state1)

     {

         zipcode = "?";

         city = city1;

         state = state1;

         parent = NULL;

         left = NULL;

         right = NULL;

     }

    //The following functions are accessor functions

    ZipInfo * getLeft()

     {

      return left;

     }

    ZipInfo * getRight()

     {

      return right;

     }

    ZipInfo * getParent()

     {

      return parent;

     }

     

    string getCity()

     {

         return city;

     }

     string getState()

     {

         return state;

     }

     string getZip()

     {

         return zipcode;

     }

    //The following three functions are mutator functions

    void setLeft(ZipInfo * other)

     {

       left = other;

     }

    void setRight(ZipInfo * other)

     {

       right = other;

     }

    void setParent(ZipInfo * other)

     {

       parent = other;

     }

    //The print method prints the city, state, and zip code

    void print()

     {

      cout << city << " in " << state << " with zipcode of " << zipcode;

     }

    //compare two cities

    int compareTo(ZipInfo * other)

     {

      if (this->state.compare(other->state) < 0)

       return -1;

      else if (this->state.compare(other->state) > 0)

       return 1;

      else

       {

        if (this->city.compare(other->city) < 0)

         return -1;

        else if (this->city.compare(other->city) > 0)

         return 1;

        else

         {

           return 0;

         }

       }

     }

   //copy the content of one ZipInfo without making them aliases

   bool copy(ZipInfo * other)

     {

         this->zipcode = other->zipcode;

         this->city = other->city;

         this->state = other->state;

     }

 };

//class BinarySearchTree will contains cities

class BinarySearchTree

 {

  private:

     ZipInfo * root;

  public:

     BinarySearchTree();

     ~BinarySearchTree();

     int postOrderTreeDelete(ZipInfo *);

     bool isEmpty();

     void inOrderTreePrint();

     void preOrderTreePrint();

     void postOrderTreePrint();

     void inOrderTreeWalk(ZipInfo *);

     void preOrderTreeWalk(ZipInfo *);

     void postOrderTreeWalk(ZipInfo *);

     ZipInfo * treeSearchNode(ZipInfo *, ZipInfo *);

     ZipInfo * treeSearch(string, string);

     ZipInfo * treeMinimum();

     ZipInfo * treeMaximum();

     ZipInfo * treeMinimumNode(ZipInfo *);

     ZipInfo * treeMaximumNode(ZipInfo *);

     ZipInfo * treeSuccessor(string,string);

     ZipInfo * treePredecessor(string,string);

     ZipInfo * treeSuccessorNode(ZipInfo *);

     ZipInfo * treePredecessorNode(ZipInfo *);

     bool treeInsert(string,string,string);

     ZipInfo * treeDelete(string,string);

 };

//The constructor initialize the root to be NULL

BinarySearchTree::BinarySearchTree()

 {

  root = NULL;

 }

//The destructor should delete all nodes in the tree 

//and perform garbage collections starting from leaves (bottom-up order). 

//The destructor should also print â€œThe number of nodes deleted: Xâ€  

//where X is the number of nodes deleted

BinarySearchTree::~BinarySearchTree()

 {

   int count = 0;

   count = postOrderTreeDelete(root);

   cout << "The number nodes deleted: " << count << endl; 

 }

//Delete all nodes under the node x in bottom up order

int BinarySearchTree::postOrderTreeDelete(ZipInfo * x)

 {

  int count = 0;

  if (x != NULL)

   {

    if (x->getLeft() != NULL)

     count += postOrderTreeDelete(x->getLeft());

    if (x->getRight() != NULL)

     count += postOrderTreeDelete(x->getRight());

    ZipInfo * temp = x;

    if (x->getParent() != NULL)

     {

     if (x == x->getParent()->getLeft())

      x->getParent()->setLeft(NULL);

     else if (x == x->getParent()->getRight())

      x->getParent()->setRight(NULL);

     }

    else

     root = NULL;

    delete temp;

    x = NULL;

    count++;

   }

   return count;

 }

//isEmpty() return true if the tree is empty, false otherwise

bool BinarySearchTree::isEmpty()

 {

   if (root == NULL)

    return true;

   else

    return false; 

 }

//prints all nodes using in-order starting from root

//and in-order walk function

void BinarySearchTree::inOrderTreePrint()

 {

  if (isEmpty())

    cout << "tree is empty" << endl;

  else

   {

    cout << "\n";

    inOrderTreeWalk(root);

    cout << "\n";

   }

 }

//it prints all nodes using pre-order starting from root

//and pre-order walk function

void BinarySearchTree::preOrderTreePrint()

 {

  if (isEmpty())

    cout << "tree is empty" << endl;

  else

   {

    cout << "\n";

    preOrderTreeWalk(root);

    cout << "\n";

   }

 }

//it prints all nodes using post-order starting from root

//and post-order walk

void BinarySearchTree::postOrderTreePrint()

 {

  if (isEmpty())

    cout << "tree is empty" << endl;

  else

   {

    cout << "\n";

    postOrderTreeWalk(root);

    cout << "\n";

   }

 }

//print nodes under the parameter x using in-order

void BinarySearchTree::inOrderTreeWalk(ZipInfo * x)

 {

  if (x != NULL)

   {

    inOrderTreeWalk(x->getLeft());

    x->print();

    cout << endl;

    inOrderTreeWalk(x->getRight());

   }

 }

//print nodes under the parameter x using pre-order

void BinarySearchTree::preOrderTreeWalk(ZipInfo * x)

 {

  if (x != NULL)

   {

    x->print();

    cout << endl;

    preOrderTreeWalk(x->getLeft());

    preOrderTreeWalk(x->getRight());

   }

 }

//print nodes under the parameter x using post-order

void BinarySearchTree::postOrderTreeWalk(ZipInfo * x)

 {

  if (x != NULL)

   { 

    postOrderTreeWalk(x->getLeft());

    postOrderTreeWalk(x->getRight());

    x->print();

    cout << endl;

   }

 }

//Using the string parameter of city and state, it returns 

//its zipcode information (node) within the tree if found

//return NULL if not found

ZipInfo * BinarySearchTree::treeSearch(string city, string state)

 {

   ZipInfo * other = new ZipInfo(city, state);

   return treeSearchNode(root, other);

 }

//Starting from the parameter x node, 

//search for the parameter other within the tree;

//It returns NULL if not found

ZipInfo * BinarySearchTree::treeSearchNode(ZipInfo * x, ZipInfo * other)

 {

   if (other == NULL)

     return NULL;

   while (x != NULL && x->compareTo(other) != 0)

    {

      if (other->compareTo(x) < 0)

        x = x->getLeft();

      else

        x = x->getRight();

    }

   return x;

 } 

 

//Searches and returns the node with the minimum key within the tree

ZipInfo * BinarySearchTree::treeMinimum()

 {

    return treeMinimumNode(root);

 }

//Searches and returns the node with the minimum key starting the node x

ZipInfo * BinarySearchTree::treeMinimumNode(ZipInfo * x)

 {

   if (x == NULL)

    return NULL;

   while (x->getLeft() != NULL)

     x = x->getLeft();

   return x;

 }

//Searches and returns the node with the maximum key within the tree

ZipInfo * BinarySearchTree::treeMaximum()

 {

   return treeMaximumNode(root);

 }

//Searches and returns the node with the maximum key starting the node x

ZipInfo * BinarySearchTree::treeMaximumNode(ZipInfo * x)

 {

   if (x == NULL)

     return NULL;

   while (x->getRight() != NULL)

     x = x->getRight();

   return x;

 }

//Searches and returns the successor of the parameters city and state

ZipInfo * BinarySearchTree::treeSuccessor(string city, string state)

 {

   ZipInfo * temp = new ZipInfo(city, state);

   return treeSuccessorNode(temp);

 }

//Searches and returns the succusor of the parameter city and state

ZipInfo * BinarySearchTree::treeSuccessorNode(ZipInfo * aNode)

 {

     ZipInfo * x = treeSearchNode(root, aNode);

     ZipInfo * y = NULL;

     if (x == NULL)

       return NULL;

     if (x->getRight() != NULL)

      return treeMinimumNode(x->getRight());

     else

      {

       y = x->getParent();

       while (y != NULL && x == y->getRight())

        {

           x = y;

           y = y->getParent();

        }

       return y;

      } 

 }

//Searches and returns the predecessor of the parameter city and state

ZipInfo * BinarySearchTree::treePredecessor(string city, string state)

 {

   ZipInfo * temp = new ZipInfo(city, state);

   return treePredecessorNode(temp);

 }

//Searches and returns the predecessor of the parameter city and state

ZipInfo * BinarySearchTree::treePredecessorNode(ZipInfo * aNode)

 {

     ZipInfo * x = treeSearchNode(root, aNode);

     ZipInfo * y = NULL;

     if (x == NULL)

       return NULL;

     if (x->getLeft() != NULL)

      return treeMaximumNode(x->getLeft());

     else

      {

       y = x->getParent();

       while (y != NULL && x == y->getLeft())

        {

           x = y;

           y = y->getParent();

        }

       return y;

      }

 }

//It inserts the parameter city, state zipcode

//and returns tree if successful, false otherwise

bool BinarySearchTree::treeInsert(string city, string state, string zipcode)

 {

  ZipInfo * z = new ZipInfo(city,state,zipcode);

  if (z == NULL)

    return false;

  ZipInfo * y = NULL;

  ZipInfo * x = root;

  while (x != NULL)

   {

    y = x;

    if (z->compareTo(y) < 0)

     x = x->getLeft();

    else

     x = x->getRight();

   }

  z->setParent(y);

  if (y == NULL)

    root = z;

  else

   {

      if (z->compareTo(y) < 0)

        y->setLeft(z);

      else

        y->setRight(z);

   }

     

   return true;

 }

//It deletes the node specified by the parameters city and state

//and deletes and returns the node if it is found in the tree

//It returns NULL if not found

ZipInfo * BinarySearchTree::treeDelete(string city, string state)

 {

   

   ZipInfo * x = NULL;

   ZipInfo * y = NULL;

   ZipInfo * z = NULL;

   z = treeSearch(city, state);

   if (z == NULL)

     return NULL;

   if (z->getLeft() == NULL || z->getRight() == NULL)

      y = z;

   else

      y = treeSuccessorNode(z);

   if (y->getLeft() != NULL)

      x = y->getLeft();

   else

      x = y->getRight();

   if (x != NULL)

      x->setParent(y->getParent());

 

   if (y->getParent() == NULL)

      this->root = x;

   else

      if (y == y->getParent()->getLeft())

          y->getParent()->setLeft(x);

      else

          y->getParent()->setRight(x);

 

   if (y != z)

     z->copy(y);

    return y;

 }