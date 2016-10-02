#ifndef HUFFMAN_NODE_H
#define HUFFMAN_NODE_H

class HuffmanNode{
    char c;
    int f;
    bool leaf;
    HuffmanNode* left;
    HuffmanNode* right;

public:
    HuffmanNode(char, int);
    HuffmanNode(int, HuffmanNode*, HuffmanNode*);
    int get_frequency();
    bool is_leaf();
    char get_char();
    HuffmanNode* get_left();
    HuffmanNode* get_right();

};

HuffmanNode::HuffmanNode(char _c, int _f): c(_c), f(_f), leaf(true), left(nullptr), right(nullptr){

}

HuffmanNode::HuffmanNode(int _f, HuffmanNode* _left, HuffmanNode* _right): f(_f), leaf(false), left(_left), right(_right){

}

int HuffmanNode::get_frequency(){
    return this->f;
}

bool HuffmanNode::is_leaf(){
    return this->leaf;
}

char HuffmanNode::get_char(){
    return this->c;
}

HuffmanNode* HuffmanNode::get_left(){
    return this->left;
}

HuffmanNode* HuffmanNode::get_right(){
    return this->right;
}

#endif //HUFFMAN_NODE_H