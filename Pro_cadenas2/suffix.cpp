#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
};

class SuffixTrie {
private:
    TrieNode* root;
    void print(TrieNode* node, string palabra) {
        for (auto hijo : node->children) {
            cout << palabra + hijo.first << endl;
            print(hijo.second, palabra + hijo.first);
        }
    }

public:
    SuffixTrie() {
        root = new TrieNode();
    }
    void insert(string text) {
        cout << "Construyendo el Suffix Trie...\n\n";
        cout << "Sufijos insertados:\n";
        for (int i = 0; i < text.size(); i++) {
            cout << text.substr(i) << endl;
            TrieNode* current = root;
            for (int j = i; j < text.size(); j++) {
                char c = text[j];
                if (current->children.find(c) == current->children.end()) {
                    current->children[c] = new TrieNode();
                }
                current = current->children[c];
            }
        }
        cout << "\nConstruccion Finalizada\n";
    }

    bool search(string pattern) {
        TrieNode* current = root;
        for (char c : pattern) {
            if (current->children.find(c) == current->children.end())
                return false;
            current = current->children[c];
        }
        return true;
    }
};

int main() {
    SuffixTrie trie;
    string texto;
    string patron;
    cout << "Ingrese el texto: ";
    cin >> texto;
    trie.insert(texto);
    cout << "\nIngrese el patron: ";
    cin >> patron;
    cout << "Resultado: ";
    if (trie.search(patron)) {
        cout << "El patron \"" << patron << "\" SI pertenece al texto\n";

    } else {
        cout << "El patron \"" << patron << "\" NO pertenece al texto\n";

    }
    return 0;
}