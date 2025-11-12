#include <iostream>
#include <queue>
#include <vector>

struct NOD
{
    int key;
    NOD* left;
    NOD* right;
    NOD* parent;
    NOD(int k) : key(k), left(nullptr), right(nullptr), parent(nullptr) {}
};

struct SearchTree
{
    NOD* root;
    SearchTree() : root(nullptr) {}
    void INSERT(int key)
    {
        NOD* newNode = new NOD(key);
        if (!root)
        {
            root = newNode;
            return;
        }
        NOD* current = root;
        NOD* parent = nullptr;
        while (current)
        {
            parent = current;
            if (key < current->key)
                current = current->left;
            else if (key > current->key)
                current = current->right;
            else
                return; // key already exists, do not insert
        }
        newNode->parent = parent;
        if (key < parent->key)
            parent->left = newNode;
        else
            parent->right = newNode;
    }
    NOD* MAXIM(NOD* x)
    {
        while (x && x->right)
            x = x->right;
        return x;
    }
    NOD* MINIM(NOD* x)
    {
        while (x && x->left)
            x = x->left;
        return x;
    }
    NOD* SUCCESOR(NOD* x)
    {
        if (x->right)
            return MINIM(x->right);
        NOD* y = x->parent;
        while (y && x == y->right)
        {
            x = y;
            y = y->parent;
        }
        return y;
    }
    NOD* PREDECESOR(NOD* x)
    {
        if (x->left)
            return MAXIM(x->left);
        NOD* y = x->parent;
        while (y && x == y->left)
        {
            x = y;
            y = y->parent;
        }
        return y;
    }
    NOD* FIND(int key)
    {
        NOD* current = root;
        while (current)
        {
            if (key == current->key)
                return current;
            else if (key < current->key)
                current = current->left;
            else
                current = current->right;
        }
        return nullptr;
    }
    void TRANSPLANT(NOD* u, NOD* v)
    {
        if (!u->parent)
            root = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;
        if (v)
            v->parent = u->parent;
    }
    void DELETE(int key)
    {
        NOD* z = FIND(key);
        if (!z) return;
        if (!z->left)
            TRANSPLANT(z, z->right);
        else if (!z->right)
            TRANSPLANT(z, z->left);
        else
        {
            NOD* y = MINIM(z->right);
            if (y->parent != z)
            {
                TRANSPLANT(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            TRANSPLANT(z, y);
            y->left = z->left;
            y->left->parent = y;
        }
        delete z;
    }
    void ERASE(NOD* x)
    {
        if (x)
            DELETE(x->key);
    }
    void PRINT_TREE(int opt)
    {
        if (opt == 1) preOrder(root);
        else
            if (opt == 2) inOrder(root);
            else
                if (opt == 3) postOrder(root);
            else
                    if (opt == 4) levelOrder(root);
    }
    void preOrder(NOD* node)
    {
        if (node)
        {
            std::cout << node->key << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
    void inOrder(NOD* node)
    {
        if (node)
        {
            inOrder(node->left);
            std::cout << node->key << " ";
            inOrder(node->right);
        }
    }
    void postOrder(NOD* node)
    {
        if (node)
        {
            postOrder(node->left);
            postOrder(node->right);
            std::cout << node->key << " ";
        }
    }
    void levelOrder(NOD* root)
    {
        if (!root) return;
        std::queue<NOD*> q;
        q.push(root);
        while (!q.empty())
        {
            NOD* node = q.front();
            std::cout << node->key << " ";
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    void CONSTRUCT(const std::vector<int>& keys)
    {
        for (int key : keys)
            INSERT(key);
    }
    bool EMPTY()
    {
        return root == nullptr;
    }
    void CLEAR()
    {
        clearHelper(root);
        root = nullptr;
    }
    void clearHelper(NOD* node)
    {
        if (node)
        {
            clearHelper(node->left);
            clearHelper(node->right);
            delete node;
        }
    }
};
int main()
{
    SearchTree tree;
    int choice, key, opt;
    std::vector<int> keys = { 20, 8, 22, 4, 12, 10, 14 };

    tree.CONSTRUCT(keys);

    while (true) {
        std::cout << "1. Insert\n2. Find\n3. Delete\n4. Minimum\n5. Maximum\n6. Successor\n7. Predecessor\n8. Print Tree\n9. Clear\n10. Exit\n";
        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << "Enter key to insert: ";
            std::cin >> key;
            tree.INSERT(key);
            break;
        case 2:
            std::cout << "Enter key to find: ";
            std::cin >> key;
            if (tree.FIND(key)) std::cout << "Key found\n";
            else std::cout << "Key not found\n";
            break;
        case 3:
            std::cout << "Enter key to delete: ";
            std::cin >> key;
            tree.DELETE(key);
            break;
        case 4:
            if (tree.MINIM(tree.root)) std::cout << "Minimum key: " << tree.MINIM(tree.root)->key << "\n";
            else std::cout << "Tree is empty\n";
            break;
        case 5:
            if (tree.MAXIM(tree.root)) std::cout << "Maximum key: " << tree.MAXIM(tree.root)->key << "\n";
            else std::cout << "Tree is empty\n";
            break;
        case 6:
            std::cout << "Enter key to find successor: ";
            std::cin >> key;
            if (tree.SUCCESOR(tree.FIND(key))) std::cout << "Successor: " << tree.SUCCESOR(tree.FIND(key))->key << "\n";
            else std::cout << "No successor found\n";
            break;
        case 7:
            std::cout << "Enter key to find predecessor: ";
            std::cin >> key;
            if (tree.PREDECESOR(tree.FIND(key))) std::cout << "Predecessor: " << tree.PREDECESOR(tree.FIND(key))->key << "\n";
            else std::cout << "No predecessor found\n";
            break;
        case 8:
            std::cout << "Print options: 1. Preorder 2. Inorder 3. Postorder 4. Level order\n";
            std::cin >> opt;
            tree.PRINT_TREE(opt);
            std::cout << "\n";
            break;
        case 9:
            tree.CLEAR();
            std::cout << "Tree cleared\n";
            break;
        case 10:
            return 0;
        default:
            std::cout << "Invalid choice\n";
        }
    }
    return 0;

}
