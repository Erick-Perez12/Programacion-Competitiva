#include "tree.h"
#include <iostream>

Tree::Node::Node(int value) : data(value), left(nullptr), right(nullptr) {}
Tree::Tree() : root(nullptr) {}
Tree::~Tree() {
    destroy(root);
}

Tree::Node* Tree::insert(Node* node, int value) {
    if (node == nullptr) {
        return new Node(value);
    }

    if (value < node->data) {
        node->left = insert(node->left, value);
    } else {
        node->right = insert(node->right, value);
    }

    return node;
}

bool Tree::search(Node* node, int value) const {
    if (node == nullptr) {
        return false;
    }

    if (node->data == value) {
        return true;
    }

    if (value < node->data) {
        return search(node->left, value);
    }

    return search(node->right, value);
}

void Tree::inorder(Node* node) const {
    if (node != nullptr) {
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }
}

void Tree::preorder(Node* node) const {
    if (node != nullptr) {
        std::cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void Tree::postorder(Node* node) const {
    if (node != nullptr) {
        postorder(node->left);
        postorder(node->right);
        std::cout << node->data << " ";
    }
}

Tree::Node* Tree::findMin(Node* node) const {
    while (node->left != nullptr) {
        node = node->left;
    }

    return node;
}

Tree::Node* Tree::remove(Node* node, int value) {
    if (node == nullptr) {
        return nullptr;
    }

    if (value < node->data) {
        node->left = remove(node->left, value);
    } else if (value > node->data) {
        node->right = remove(node->right, value);
    } else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }

        if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = findMin(node->right);
        node->data = temp->data;
        node->right = remove(node->right, temp->data);
    }

    return node;
}

void Tree::destroy(Node* node) {
    if (node != nullptr) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

void Tree::insert(int value) {
    root = insert(root, value);
}

bool Tree::search(int value) const {
    return search(root, value);
}

void Tree::inorder() const {
    inorder(root);
    std::cout << std::endl;
}

void Tree::preorder() const {
    preorder(root);
    std::cout << std::endl;
}

void Tree::postorder() const {
    postorder(root);
    std::cout << std::endl;
}

void Tree::remove(int value) {
    root = remove(root, value);
}
