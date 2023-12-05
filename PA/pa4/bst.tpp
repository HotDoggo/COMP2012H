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
    if (isEmpty())
        return;

    root->right.print(depth + 1);

    for (int j = 0; j < depth; j++)
        cout << '\t';
    cout << root->value << "(" << root->key << ")" << endl;

    root->left.print(depth + 1);
}

// TODO: Implement BinarySearchTree's member functions
template <typename K, typename V>
BinarySearchTree<K, V>::~BinarySearchTree()
{
    if (root != nullptr)
        delete root;
}

template <typename K, typename V>
BinarySearchTree<K, V>::BinarySearchTree(const BinarySearchTree<K, V> &bst)
{
    if (!bst.isEmpty())
        root = bst.root;
}

template <typename K, typename V>
bool BinarySearchTree<K, V>::contains(const K &key) const
{
    if (!isEmpty())
    {
        if (key < root->key)
            return root->left.contains(key);
        else if (key > root->key)
            return root->right.contains(key);
        else
            return true;
    }
    return false;
}

template <typename K, typename V>
const K &BinarySearchTree<K, V>::findMin() const
{
    if (root->left.isEmpty())
        return root->key;
    return root->left.findMin();
}

template <typename K, typename V>
V &BinarySearchTree<K, V>::getValue(const K &key) const
{
    if (key < root->key)
        return root->left.getValue(key);
    else if (key > root->key)
        return root->right.getValue(key);
    return root->value;
}

template <typename K, typename V>
void BinarySearchTree<K, V>::insert(const K &key, const V &value)
{
    if (isEmpty())
        root = new TreeNode(key, value);
    else if (key < root->key)
        root->left.insert(key, value);
    else if (key > root->key)
        root->right.insert(key, value);
}

template <typename K, typename V>
void BinarySearchTree<K, V>::remove(const K &key)
{
    // cout << root->key << endl;
    if (root == nullptr)
        return;

    if (key < root->key)
        root->left.remove(key);
    else if (key > root->key)
        root->right.remove(key);

    else
    {
        if (root->left.root == nullptr || root->right.root == nullptr)
        {
            // cout << "here" << endl;
            TreeNode *temp = root->left.root ? root->left.root : root->right.root;
            if (temp == nullptr)
            {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp;
            // cout << temp->key << endl;
            delete temp;
        }
        else
        {
            K min_key = root->right.findMin();
            // cout << min_key << endl;
            root->key = min_key;
            root->value = root->right.getValue(min_key);
            // cout << root->key << root->value << endl;
            root->right.remove(min_key);
        }
    }

    // if (root->left.isEmpty() || root->right.isEmpty())
    // {
    //     TreeNode *temp = root->left.isEmpty() ? root->left.root : root->right.root;

    //     if (temp == nullptr)
    //     {
    //         temp = root;
    //         root = nullptr;
    //     }
    //     else
    //         *root = *temp;
    //     delete temp;
    // }
    // else
    // {
    //     K min_key = root->right.findMin();
    //     root->key = min_key;
    //     root->value = root->right.getValue(min_key);
    //     root->right.remove(min_key);
    // }
}
