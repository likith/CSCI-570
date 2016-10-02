#ifndef HUFFMAN_CODING_H
#define HUFFMAN_CODING_H

#include "HuffmanNode.h"

class cmp{
public:
	bool operator()(HuffmanNode* h1, HuffmanNode* h2){
		return h1->get_frequency() > h2->get_frequency();
	}
};


class HuffmanCoding{
private:
	std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, cmp > pQ;
	HuffmanNode* hTree;

public:
	int process_input(int c);
	HuffmanNode* build_huffman_tree();
	void print_tree();
	void print_tree_utility(HuffmanNode*, std::string);
};


#endif // HUFFMAN_CODING_H