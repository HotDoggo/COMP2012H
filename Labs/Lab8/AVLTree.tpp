template <typename T>
AVLNode<T>::AVLNode(T k) : key(k), height(1), left(nullptr), right(nullptr) {}

template <typename T>
int AVLTree<T>::height(AVLNode<T> *N)
{
    if (N == nullptr)
        return 0;
    return N->height;
}

template <typename T>
AVLNode<T> *AVLTree<T>::minValueNode(AVLNode<T> *node)
{
    AVLNode<T> *current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

template <typename T>
AVLNode<T> *AVLTree<T>::rightRotate(AVLNode<T> *y)
{
    // todo: complete the code
    AVLNode<T> *x = y->left;
    AVLNode<T> *T2 = x->right;

    // right rotate
    x->right = y;
    y->left = T2;

    // update height
    // x->height = max(height(x->left), height(x->right)) + 1;
    // y->height = max(height(y->left), height(y->right)) + 1;
    // ^^^ what the fuck i did this backwards oh my god i was stuck here for TWO DAYS

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

template <typename T>
AVLNode<T> *AVLTree<T>::leftRotate(AVLNode<T> *x)
{
    // todo: complete the code
    AVLNode<T> *y = x->right;
    AVLNode<T> *T2 = y->left;

    // left rotate
    y->left = x;
    x->right = T2;

    // update height
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

template <typename T>
int AVLTree<T>::getBalance(AVLNode<T> *N)
{
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

template <typename T>
AVLNode<T> *AVLTree<T>::insert(AVLNode<T> *node, T key)
{
    // todo: complete the code
    // 1. BST insert
    if (node == nullptr)
        return new AVLNode<T>(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    // 2. update height
    node->height = max(height(node->left), height(node->right)) + 1;

    // 3. check balance
    int balance = getBalance(node);

    // left-left
    AVLNode<T> *temp;
    if (balance > 1 && getBalance(node->left) >= 0)
        node = rightRotate(node);

    // right-right
    else if (balance < -1 && getBalance(node->right) <= 0)
        node = leftRotate(node);

    // left-right
    else if (balance > 1 && getBalance(node->left) == -1)
    {
        node->left = leftRotate(node->left);
        node = rightRotate(node);
    }

    // right-left
    else if (balance < -1 && getBalance(node->right) == 1)
    {
        node->right = rightRotate(node->right);
        node = leftRotate(node);
    }

    return node;
}

template <typename T>
AVLNode<T> *AVLTree<T>::remove(AVLNode<T> *root, T key)
{
    // todo: complete the code
    // 1. BST remove
    if (root == nullptr)
        return nullptr;

    if (key < root->key)
        root->left = remove(root->left, key);
    else if (key > root->key)
        root->right = remove(root->right, key);
    else
    {
        if (root->left == nullptr || root->right == nullptr)
        {
            AVLNode<T> *temp = root->left ? root->left : root->right;
            if (temp == nullptr)
            {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp;
            delete temp;
        }
        else
        {
            AVLNode<T> *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = remove(root->right, root->key);
        }
    }

    if (root == nullptr)
        return root;

    // 2. update height
    root->height = max(height(root->left), height(root->right)) + 1;

    // 3. check balance
    int balance = getBalance(root);

    // left-left
    if (balance > 1 && getBalance(root->left) >= 0)
        root = rightRotate(root);

    // right-right
    else if (balance < -1 && getBalance(root->right) <= 0)
        root = leftRotate(root);

    // left-right
    else if (balance > 1 && getBalance(root->left) == -1)
    {
        root->left = leftRotate(root->left);
        root = rightRotate(root);
    }

    // right-left
    else if (balance < -1 && getBalance(root->right) == 1)
    {
        root->right = rightRotate(root->right);
        root = leftRotate(root);
    }

    return root;
}

template <typename T>
AVLTree<T>::AVLTree() : root(nullptr) {}

template <typename T>
void AVLTree<T>::insert(T key)
{
    root = insert(root, key);
}

template <typename T>
void AVLTree<T>::remove(T key)
{
    root = remove(root, key);
}

template <typename T>
void AVLTree<T>::printHelper(AVLNode<T> *node, int depth) const
{
    if (!node)
        return;
    printHelper(node->right, depth + 1);
    for (int i = 0; i < depth; ++i)
    {
        cout << "\t";
    }
    cout << node->key << "(" << node->height << ")" << endl;
    printHelper(node->left, depth + 1);
}

template <typename T>
void AVLTree<T>::print() const
{
    if (root == nullptr)
        return;
    printHelper(root, 0);
}