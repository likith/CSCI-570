#include <iostream>
#include <queue>
#include <vector>

//#include "HuffmanNode.h"
#include "HuffmanCoding.h"

void HuffmanCoding::print_tree(){

	print_tree_utility(hTree, "");
}

void HuffmanCoding::print_tree_utility(HuffmanNode* node, std::string bit_string){
	if(node == nullptr){
		return;
	}

	if(node->is_leaf()){
		std::cout << node->get_char() << "  " << bit_string << "\n";
		return;
	}

	print_tree_utility(node->get_left(), bit_string+"0");
	print_tree_utility(node->get_right(), bit_string+"1");

	return;
}

HuffmanNode* HuffmanCoding::build_huffman_tree(){
	
	std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, cmp > tempQ = pQ;
	
	while(!tempQ.empty()){
		HuffmanNode* least_1 = tempQ.top();
		tempQ.pop();

		if(tempQ.empty()){
			hTree = least_1;
			return least_1;
		}

		HuffmanNode* least_2 = tempQ.top();
		tempQ.pop();

		HuffmanNode* combine = new HuffmanNode(least_1->get_frequency() + least_2->get_frequency(), least_1, least_2);
		tempQ.push(combine);
	}

	return nullptr;
}

int HuffmanCoding::process_input(int c){
	if(c == 1){
		unsigned n;
		std::cout << "Enter number of characters\n";
		std::cin >> n;
		for(int i=0; i < n; i++){
			char c;
			int frequency;
			std::cout << "Enter the character\n";
			std::cin >> c;
			std::cout << "Enter the frequency\n";
			std::cin >> frequency;

			HuffmanNode* h = new HuffmanNode(c, frequency);

			pQ.push(h);
		}
	}

	return 0;
}

int main()
{
	int choice;
	std::cout << "Do you want to enter (1) characters or  a (2) file name? \n";
	std::cin >> choice;

	HuffmanCoding h;

	h.process_input(choice);
	h.build_huffman_tree();
	h.print_tree();

	return 0;
}