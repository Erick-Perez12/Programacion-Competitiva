#ifndef TREE_H
#define TREE_H

class Tree {
public:
    Tree();
    ~Tree();
    void insert(int value);
    bool search(int value) const;
    void inorder() const;
    void preorder() const;
    void postorder() const;
    void remove(int value);

private:
    struct Node {
        int data;
        Node* left;
        Node* right;

        explicit Node(int value);
    };

    Node* root;

    Node* insert(Node* node, int value);
    bool search(Node* node, int value) const;
    void inorder(Node* node) const;
    void preorder(Node* node) const;
    void postorder(Node* node) const;
    Node* findMin(Node* node) const;
    Node* remove(Node* node, int value);
    void destroy(Node* node);
};

#endif
