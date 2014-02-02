#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

struct treeNode {
    treeNode* left;
    treeNode* right;
    int key;
}*root;

template <class T> class BinarySearchTree {
public:
    BinarySearchTree() {
        root = NULL;
    }

    bool isEmpty() const {
        return root == NULL;
    }
    void inorder(treeNode*);
    void traverseInorder();

    void preorder(treeNode*);
    void traversePreorder();

    void postorder(treeNode*);
    void traversePostorder();

    void insert(T);

    void remove(T);

    treeNode* search(const T &);

    treeNode* findHelper(const T &, treeNode* &);
    treeNode* find(const T &);

    treeNode* minHelper(treeNode* &);
    treeNode* min();

    treeNode* maxHelper(treeNode* &);
    treeNode* max();

    int sizeHelper(treeNode*);
    int size();
};

// Smaller elements go left
// larger elements go right
template <class T> void BinarySearchTree<T>::insert(T d) {
    treeNode* t = new treeNode;
    treeNode* parent;
    t->key = d;
    t->left = NULL;
    t->right = NULL;
    parent = NULL;

    // is this a new tree?
    if(isEmpty()) root = t;
    else {
        //Note: ALL insertions are as leaf nodes
        treeNode* curr;
        curr = root;
        // Find the Node's parent
        while(curr) {
            parent = curr;
            if(t->key > curr->key) curr = curr->right;
            else curr = curr->left;
        }

        if(t->key < parent->key)
            parent->left = t;
        else
            parent->right = t;
    }
}

template <class T>void BinarySearchTree<T>::remove(T d) {
    //Locate the element
    bool found = false;
    if(isEmpty()) {
        cout<<" This Tree is empty! "<<endl;
        return;
    }

    treeNode* curr;
    treeNode* parent;
    curr = root;

    // root to leaf search (top-down)
    while(curr) {
        if(curr->key == d) {
            found = true;
            break;
        } else {
            parent = curr;
            if(d > curr->key) curr = curr->right;
            else curr = curr->left;
        }
    }

    if(!found) {
        cout<<" key not found! "<<endl;
        return;
    }


    // 3 cases :
    // 1. We're removing a leaf node
    // 2. We're removing a node with a single child
    // 3. we're removing a node with 2 children


    //We're looking at a leaf node
    if( curr->left == NULL && curr->right == NULL) {
        if(parent->left == curr) parent->left = NULL;
        else parent->right = NULL;
        delete curr;
        return;
    }

    // Node with single child
    if((curr->left == NULL && curr->right != NULL)|| (curr->left != NULL
            && curr->right == NULL)) {
        if(curr->left == NULL && curr->right != NULL) {
            if(parent->left == curr) {
                parent->left = curr->right;
                delete curr;
            } else {
                parent->right = curr->right;
                delete curr;
            }
        } else { // left child present, no right child
            if(parent->left == curr) {
                parent->left = curr->left;
                delete curr;
            } else {
                parent->right = curr->left;
                delete curr;
            }
        }
        return;
    }

    //Node with 2 children
    // replace node with smallest value in right subtree
    if (curr->left != NULL && curr->right != NULL) {
        treeNode* chkr;
        chkr = curr->right;
        if((chkr->left == NULL) && (chkr->right == NULL)) {
            curr = chkr;
            delete chkr;
            curr->right = NULL;
        } else { // right child has children
            //if the node's right child has a left child
            // Move all the way down left to locate smallest element

            if((curr->right)->left != NULL) {
                treeNode* lcurr;
                treeNode* lcurrp;
                lcurrp = curr->right;
                lcurr = (curr->right)->left;
                while(lcurr->left != NULL) {
                    lcurrp = lcurr;
                    lcurr = lcurr->left;
                }
                curr->key = lcurr->key;
                delete lcurr;
                lcurrp->left = NULL;
            } else {
                treeNode* tmp;
                tmp = curr->right;
                curr->key = tmp->key;
                curr->right = tmp->right;
                delete tmp;
            }

        }
        return;
    }

}

template <class T>treeNode* BinarySearchTree<T>::search(const T &d) {
    treeNode* current = root;
    while (current) {
        if(current -> key == d) {
            return current;
        } else if(d < current -> key) {
            current = current -> left;
        } else current = current -> right;
    }
    return NULL;
}

template <class T> treeNode* BinarySearchTree <T> :: findHelper(const T &d, treeNode* &node) {
    if (!node || node -> key == d) return node;
    else if(d < node -> key) findHelper(d, node -> left);
    else findHelper(d, node -> right);
}

template <class T> treeNode* BinarySearchTree <T> :: find(const T &d) {
    return findHelper(d, root);
}

template <class T> treeNode* BinarySearchTree <T> :: minHelper(treeNode* &node) {
    if(node -> left == NULL) return node;
    else minHelper(node -> left);
}

template <class T> treeNode* BinarySearchTree <T> :: min() {
    return minHelper(root);
}

template <class T> treeNode* BinarySearchTree <T> :: maxHelper(treeNode* &node) {
    if(node -> right == NULL) return node;
    else maxHelper(node -> right);
}

template <class T> treeNode* BinarySearchTree <T> :: max() {
    return maxHelper(root);
}

int count;
template<class T>int BinarySearchTree<T>::sizeHelper(treeNode* p) {
    if(p != NULL) {
        if(p->left) sizeHelper(p->left);
        if(p->right) sizeHelper(p->right);
        count++;
    } else return count;
}

template<class T>int BinarySearchTree<T>::size() {
    count = 0;
    return sizeHelper(root);
}


/**
  in-order - leftChild, root, rightChild
  pre-order - root, leftChild, rightChild
  post-order - leftChild, rightChild, root
**/
template<class T>void BinarySearchTree<T>::inorder(treeNode* p) {
    if(p != NULL) {
        if(p->left) inorder(p->left);
        cout<<" "<<p->key<<" ";
        if(p->right) inorder(p->right);
    } else return;
}

template<class T>void BinarySearchTree<T>::traverseInorder() {
    inorder(root);
}

template<class T>void BinarySearchTree<T>::preorder(treeNode* p) {
    if(p != NULL) {
        cout<<" "<<p->key<<" ";
        if(p->left) preorder(p->left);
        if(p->right) preorder(p->right);
    } else return;
}

template<class T>void BinarySearchTree<T>::traversePreorder() {
    preorder(root);
}

template<class T>void BinarySearchTree<T>::postorder(treeNode* p) {
    if(p != NULL) {
        if(p->left) postorder(p->left);
        if(p->right) postorder(p->right);
        cout << p->key << "\n";
    } else return;
}

template<class T>void BinarySearchTree<T>::traversePostorder() {
    postorder(root);
}

int main() {
    freopen("input.txt", "r", stdin);
    BinarySearchTree <int> btree;
    int value;
    while(cin >> value) {
        btree.insert(value);
    }
    btree.traversePostorder();
}
