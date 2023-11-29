// This function has been implemented for you.
// It prints the binary search tree in the console.
// Example format:
/**
 *          8
 *      7 
 *          6
 * 5
 *          4
 *      3
 *          2
*/
template <typename K, typename V>
void BinarySearchTree<K, V>::print(int depth) const
{
    if (isEmpty()) return;

    root->right.print(depth+1);

    for (int j = 0; j < depth; j++)
        cout << '\t';
    cout << root->value << "(" << root->key << ")" << endl;

    root->left.print(depth+1);
}

// TODO: Implement BinarySearchTree's member functions

