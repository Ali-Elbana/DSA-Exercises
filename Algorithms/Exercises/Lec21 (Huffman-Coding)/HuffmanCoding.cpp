/*
*
* Problem description:
* Implement the Huffman coding algorithm.
*
*/

#include <iostream>
#include <vector>
#include <stdexcept> 
#include <unordered_map>
#include <queue>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::priority_queue;
using std::unordered_map;

/************************* Declarations **************************/
/****************************************************************/

// Tree node
struct Node
{
	
	char ch;
	int freq;
	Node * left;
	Node * right;
	// Constructor
	Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr){}
	
};
/////////////////////////////////////////////////////////////////////

// Compare function for priority queue (min-heap)
struct Compare
{
	bool operator()(Node * a, Node * b)
	{
		return a->freq > b->freq; // min-heap: smallest freq has highest priority
	}		
};
/////////////////////////////////////////////////////////////////////
void get_string(string & inStr);
/////////////////////////////////////////////////////////////////////
void generate_HuffmanCodes(Node* root, const string& code, unordered_map<char, string> & huffmanCode);
/////////////////////////////////////////////////////////////////////
void count_strFreq(string & inStr, unordered_map<char, int> & inFreq);
/////////////////////////////////////////////////////////////////////
void create_huffmanTree(priority_queue<Node *, vector<Node*>, Compare> & inPQue);
/////////////////////////////////////////////////////////////////////
void concat_encodedStr(string & encodedStr, string & inStr, unordered_map<char, string> & huffmanCode);
/////////////////////////////////////////////////////////////////////
void print_huffmanCode(unordered_map<char, string> & huffmanCode);

/*********************** Application ***************************/
/**************************************************************/

int main() 
{
    
    system("cls");
	
	string inStr{""};
	string blankStr{""};
	string encodedStr{""};
	
	unordered_map<char, int> umFreq;
	priority_queue<Node *, vector<Node*>, Compare> pQue;
	unordered_map<char, string> umHuffCode;
	
	get_string(inStr);

	// Count char frequency in the input text:
	count_strFreq(inStr, umFreq);
	
	// Create priority queue:
	for(auto & pair : umFreq)
	{
		pQue.push(new Node(pair.first, pair.second));
	}
	
	// Create Huffman tree:
	create_huffmanTree(pQue);
	
	Node * root = pQue.top();
	
	// Generate Huffman Code:
	generate_HuffmanCodes(root, blankStr, umHuffCode);
	
	// Print Codes:
    print_huffmanCode(umHuffCode);
	
	concat_encodedStr(encodedStr, inStr, umHuffCode);
	
	cout << "\nOriginal string: " << inStr << '\n' << '\n';
    cout << "Encoded binary:  " << encodedStr << '\n' << '\n';
    
    return 0;

}

/********************* Function definitions *********************/
/****************************************************************/

void get_string(string & inStr)
{
    cout << endl << "Enter the string: ";
    std::getline(cin, inStr);
}
/*---------------------------------------------------------------------------*/
void generate_HuffmanCodes(Node* root, const string& code, unordered_map<char, string>& huffmanCode)
{
	if(root == nullptr)
	{
		return;
	}
	// Leaf node → store code
	else if(root->left == nullptr && root->right == nullptr)
	{
		huffmanCode[root->ch] = code;
	}
	else
	{
		generate_HuffmanCodes(root->left, code + "0", huffmanCode);
		generate_HuffmanCodes(root->right, code + "1", huffmanCode);
	}
}
/*---------------------------------------------------------------------------*/
void count_strFreq(string & inStr, unordered_map<char, int> & inFreq)
{
	for(char & strCh : inStr)
	{
		inFreq[strCh]++;
	}
}
/*---------------------------------------------------------------------------*/
void create_huffmanTree(priority_queue<Node *, vector<Node*>, Compare> & inPQue)
{
	while(inPQue.size() > 1)
	{
		Node * left  = inPQue.top(); inPQue.pop(); 
		Node * right = inPQue.top(); inPQue.pop(); 
		
		Node * merged = new Node('\0', left->freq + right->freq);
		
		merged->left  = left;
		merged->right = right;
		
		inPQue.push(merged);
	}
}
/*---------------------------------------------------------------------------*/
void concat_encodedStr(string & encodedStr, string & inStr, unordered_map<char, string> & huffmanCode)
{
	for(char & ch : inStr)
	{
		encodedStr += huffmanCode[ch];
	}
}
/*---------------------------------------------------------------------------*/
void print_huffmanCode(unordered_map<char, string> & huffmanCode)
{
    cout << endl;
    cout << "Character Huffman Codes:\n\n";
    for(auto& pair : huffmanCode) {
        cout << ' ' << pair.first << " --> " << pair.second << '\n';
    }
    cout << endl;
}
/****************************************************************/
/****************************************************************/