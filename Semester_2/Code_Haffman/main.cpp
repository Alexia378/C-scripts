#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <queue>

using namespace std;

class Node
{
private:
    int id = -1;
    int freq;

    Node* left;
    Node* right;

    bool code;

public:
    void joinNode(Node* node, bool left)
    {
        if (left) {
            this->left = node;
            this->left->code = false;
        } else {
            this->right = node;
            this->right->code = true;
        }
    }

    int getID() {
        return id;
    }

    int getFreq()  {
        return freq;
    }

    string getHuffCode() {
        return (code) ? "1" : "0" ;
    }

    bool hasChildren() {
        return !(left == nullptr && right == nullptr);
    }

    Node* getLeft() {
        return left;
    }

    Node* getRight() {
        return right;
    }


public:
    Node(int freq, int id)
    {
        this->id = id;
        this->freq = freq;
        left = nullptr;
        right = nullptr;
    }

    Node(int freq, Node* left, Node* right)
    {
        joinNode(left, true);
        joinNode(right, false);

        this->freq = freq;
    }
};

class Huffman
{
private:
    int N = 0;
    vector<Node*> nodes = vector<Node*>();
    vector<string> codesHuff = vector<string>();


private:
    void pop(){
        nodes.erase(nodes.begin() + N-- - 1);
    }

    void insert(Node* node){
        bool isInserted = false;

        for (int i = N-1; i >= 0; --i)
        {
            if (nodes[i]->getFreq() >= node->getFreq())
            {
                nodes.insert(nodes.begin() + i + 1, node);
                isInserted = true;
                break;
            }
        }

        if (!isInserted)
            nodes.insert(nodes.begin(), node);

        ++N;
    }

private:
    void buildTree()
    {
        while (nodes.size() != 1)
        {
            Node* left = nodes.back();
            pop();

            Node* right = nodes.back();
            pop();

            Node* node = new Node(left->getFreq() + right->getFreq(), left, right);
            insert(node);
        }
    }

    void goTo(Node* node, string code, bool addRoot = false)
    {
        if (!addRoot)
            code += node->getHuffCode();

        if (node->hasChildren()) {
            goTo(node->getLeft(), code);
            goTo(node->getRight(), code);
        } else {
            codesHuff[node->getID()] = code;
        }
    }

    void formCode()
    {
        Node* root = nodes.back();
        string code = "";
        goTo(root, code, true);
    }

public:

    Node *tree;
    void build()
    {
        // запускает алгоритм (после того как были добавлены все элементы)

        buildTree();
        formCode();
    }
    void addChance (int chance)
    {
        // добавляет элемент в список (дерево, все зависит от реализации)
        Node* tmp = new Node(chance, N);
        nodes.push_back(tmp);
        ++N;
        codesHuff.push_back("");
    }
    string get (int i)
    {
        // выдает битовый код i символа
        return codesHuff[i];
    }

};


int main() {

    int n;
    Huffman * huff = new Huffman();
    fstream fin;
    fin.open("input.txt",ios::in);
    if(fin.is_open()) {
        fin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            fin >> x;
            huff->addChance (x);
        }

        fin.close();

        huff->build();
        fstream fout;
        fout.open("output.txt",ios::out);
        for (int i = 0; i < n; i++){
            fout << huff->get(i) << (i==n-1?"":" ");
        }
        fout.close();
        delete huff;

    }

    return 0;

}