template<typename T>
AVLNode<T>::AVLNode(T k) : key(k), height(1), left(nullptr), right(nullptr) {}

template<typename T>
int AVLTree<T>::height(AVLNode <T> *N) {
    if (N == nullptr) return 0;
    return N->height;
}

template<typename T>
AVLNode <T> *AVLTree<T>::minValueNode(AVLNode <T> *node) {
    AVLNode <T> *current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

template<typename T>
AVLNode <T> *AVLTree<T>::rightRotate(AVLNode <T> *y) {
    // todo: complete the code

    // right rotate

    // update height

    return x;
}

template<typename T>
AVLNode <T> *AVLTree<T>::leftRotate(AVLNode <T> *x) {
    // todo: complete the code

    // left rotate

    // update height

    return y;
}

template<typename T>
int AVLTree<T>::getBalance(AVLNode <T> *N) {
    if (N == nullptr) return 0;
    return height(N->left) - height(N->right);
}

template<typename T>
AVLNode <T> *AVLTree<T>::insert(AVLNode <T> *node, T key) {
    // todo: complete the code
    // 1. BST insert

    // 2. update height

    // 3. check balance

    // left-left

    // right-right

    // left-right

    // right-left

}

template<typename T>
AVLNode <T> *AVLTree<T>::remove(AVLNode <T> *root, T key) {
    // todo: complete the code
    // 1. BST remove

    // 2. update height

    // 3. check balance

    // left-left

    // left-right

    // right-right

    // right-left

}

template<typename T>
AVLTree<T>::AVLTree() : root(nullptr) {}

template<typename T>
void AVLTree<T>::insert(T key) {
    root = insert(root, key);
}

template<typename T>
void AVLTree<T>::remove(T key) {
    root = remove(root, key);
}

template<typename T>
void AVLTree<T>::printHelper(AVLNode<T>* node, int depth) const
{
    if (!node) return;
    printHelper(node->right, depth + 1);
    for (int i = 0; i < depth; ++i) {
        cout << "\t";
    }
    cout << node->key << "(" << node->height << ")" << endl;
    printHelper(node->left, depth + 1);
}

template<typename T>
void AVLTree<T>::print() const
{
    if (root == nullptr)
       return;
    printHelper(root, 0);
}