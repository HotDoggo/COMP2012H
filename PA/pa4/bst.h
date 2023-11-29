#ifndef __BST_H__
#define __BST_H__

#include <iostream>
using namespace std;

/**
 * A generic Binary Search Tree where each node contains a look-up key (for binary searching)
 * and a value corresponding to that key.
 * 
 * Note that the design of this BST is different from lecture notes: Each node is a struct of type
 * TreeNode, which contains the key, value, and 2 *instances* of BinarySearchTree. The constructor
 * initializes both these trees as empty.
 * 
 * The actual BinarySearchTree class only contains a pointer to the "root" TreeNode with respect to
 * the current tree. The default constructor initializes an empty tree (root = nullptr).
 * 
 * You need to implement the following member functions in bst.tpp:
 * - ~BinarySearchTree(): Destructor.
 * - BinarySearchTree(const BinarySearchTree&): Copy constructor. Perform deep copy for this constructor.
 * - bool contains(const K& key) const: Returns true if there is a node with the specified key.
 * - const K& findMin() const: Find the minimum key stored in this tree.
 *                             You may assume the tree is not empty.
 * - V& getValue(const K& key) const: Return a reference to the value corresponding to the provided key.
 *                                    You may assume the tree is not empty.
 * - void insert(const K& key, const V& value): Insert a node to the tree with the specified key and value,
 *                                              such that the tree remains a BST.
 * - void remove(const K& key): Remove the node with the specified key from the tree.
 * 
 * For the template types, you may assume the following:
 * - K supports comparison operators (<, >, ==, <=, >=, !=), assignment operator =, ostream print operator <<
 * - V supports assignment operator =, ostream print operator <<
 * 
 * Hint: Recursion is very useful for almost all of these functions.
*/

template <typename K, typename V> 
class BinarySearchTree
{
    private:
        struct TreeNode
        {
            K key;
            V value;
            BinarySearchTree left;
            BinarySearchTree right;

            TreeNode(const K& key, const V& value) : key(key), value(value) { }
            TreeNode(const TreeNode& node) = default;
            ~TreeNode() = default;
        };
        TreeNode* root = nullptr;
    
    public:
        BinarySearchTree() = default;
        ~BinarySearchTree();

        BinarySearchTree(const BinarySearchTree& bst);

        bool isEmpty() const { return root == nullptr; }
        bool contains(const K& key) const;

        const K& findMin() const;
        V& getValue(const K& key) const;

        void insert(const K& key, const V& value);
        void remove(const K& key);

        void print(int depth = 0) const;
};

#include "bst.tpp"

#endif // __BST_H__