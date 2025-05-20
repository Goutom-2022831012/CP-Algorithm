#include <bits/stdc++.h>
using namespace std;

struct BST {
    int key;
    BST *left, *right;
    BST(int key) {
        this->key = key;
        left = right = NULL;
    }
};

BST* insert(BST* root, int key) {
    if (root == NULL) return new BST(key);
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}
BST* search(BST* root, int key) {
    if (root == NULL || root->key == key) return root;
    if (key < root->key) return search(root->left, key);
    return search(root->right, key);
}

BST* findMin(BST* root) {
    while (root && root->left) root = root->left;
    return root;
}

BST* deleteNode(BST* root, int key) {
    if (root == NULL) return root;
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            BST* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            BST* temp = root->left;
            delete root;
            return temp;
        }
        BST* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void inorder(BST* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

void deleteTree(BST* &root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
}

int main() {
    BST* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 50);
    cout << "After deleting 50: ";
    inorder(root);
    cout << endl;

    deleteTree(root);
    return 0;
}
