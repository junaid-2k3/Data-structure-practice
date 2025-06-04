#include <iostream>
#include <queue> // priority queue is also include but with max priority 
#include <unordered_map>
#include <vector>
using namespace std;

// A Huffman tree node
struct Node { // node for the huffman tree 
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Comparator for the min-heap
struct Compare {  // to change the max heap into min heap 
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Traverse the Huffman Tree and store codes in a map
void generateCodes(Node* root, string str, unordered_map<char, string>& huffmanCode) {
    if (!root) return;
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }
    generateCodes(root->left, str + "0", huffmanCode);
    generateCodes(root->right, str + "1", huffmanCode);
}

// Decode the encoded string using the Huffman tree
string decode(Node* root, string encodedStr) {
    string decoded = "";
    Node* curr = root;
    for (char bit : encodedStr) {
        if (bit == '0') curr = curr->left;
        else curr = curr->right;

        // If a leaf node is reached
        if (!curr->left && !curr->right) {
            decoded += curr->ch;
            curr = root;
        }
    }
    return decoded;
}

// Build Huffman Tree and encode/decode text
void HuffmanCoding(string text) { // these three lines store the character with its coresponding frequency 
    unordered_map<char, int> freq; // hashtable to stare key value pairs // char is the key and int is the value 
    for (char ch : text) freq[ch]++; // traverse the string and push it into the unordered map freq  

    // these three lines push those charcters and their frequency to the priority queue as a node 
    priority_queue<Node*, vector<Node*>, Compare> pq; // min priority queue , so freq will be at the top 
    for (auto pair : freq) {  //pair<char,int>, which also store into two values 
        pq.push(new Node(pair.first, pair.second));// pair.first=char , pair.second=freq
    }

    while (pq.size() != 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();
        Node *merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }
    Node* root = pq.top();
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);
    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << " -> " << pair.second << '\n';
    }
    // Encode the input text
    string encoded = "";
    for (char ch : text) {
        encoded += huffmanCode[ch];
    }
    cout << "\nEncoded string:\n" << encoded << endl;
    // Decode the encoded string
    string decoded = decode(root, encoded);
    cout << "\nDecoded string:\n" << decoded << endl;
}

int main() {
    string text = "losless";
    cout << "Original string:\n" << text << "\n\n";
    HuffmanCoding(text);
    return 0;
}
