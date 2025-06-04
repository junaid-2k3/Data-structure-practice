#include <iostream>
#include <queue>             // For priority queue (used as min-heap here)
#include <unordered_map>     // For mapping characters to frequencies and codes
#include <vector>            // For using vectors in the priority queue
using namespace std;

// ------------------------- Huffman Tree Node -------------------------
struct Node {
    char ch;                 // Character stored in this node
    int freq;                // Frequency of the character
    Node *left, *right;      // Left and right child pointers

    // Constructor to initialize node
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// ------------------------- Custom Comparator -------------------------
// This is used to create a min-heap based on frequency
struct Compare {
    bool operator()(Node* l, Node* r) {
        // Return true if left frequency is greater than right
        // This ensures that nodes with smaller frequency come first
        return l->freq > r->freq;
    }
};

// ------------------------- Generate Huffman Codes -------------------------
// Traverses the Huffman tree and generates binary codes for each character
void generateCodes(Node* root, string str, unordered_map<char, string>& huffmanCode) {
    if (!root) return;  // Base case: empty node

    // If it's a leaf node (has no children), store the code
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;  // Assign binary code to character
    }

    // Traverse left with '0' and right with '1'
    generateCodes(root->left, str + "0", huffmanCode);
    generateCodes(root->right, str + "1", huffmanCode);
}

// ------------------------- Decode Huffman String -------------------------
// Decodes the binary string using the Huffman tree
string decode(Node* root, string encodedStr) {
    string decoded = "";
    Node* curr = root;

    for (char bit : encodedStr) {
        // Go left if bit is '0', right if bit is '1'
        if (bit == '0') curr = curr->left;
        else curr = curr->right;

        // If leaf node is reached, add character and reset to root
        if (!curr->left && !curr->right) {
            decoded += curr->ch;
            curr = root;
        }
    }

    return decoded;
}

// ------------------------- Main Huffman Function -------------------------
void HuffmanCoding(string text) {
    // ---------- Step 1: Count frequency of each character ----------
    unordered_map<char, int> freq;  // Hash map: character -> frequency
    for (char ch : text) {
        freq[ch]++;  // Increment frequency count for each character
    }

    // ---------- Step 2: Create a min-heap (priority queue) ----------
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Push each character and its frequency as a node into the priority queue
    for (auto pair : freq) { // in an unordered map it is possible to use its elements as a pair 
        pq.push(new Node(pair.first, pair.second));
    }

    // ---------- Step 3: Build the Huffman Tree ----------
    while (pq.size() != 1) { // ye loop huffman tree banaega 
        // jab tak priority queue ka size 1 nhi hojata ye loop chalta rahega 
        // Remove two nodes with the lowest frequency
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        // Create a new internal node with these two nodes as children
        // The new node has no character (use '\0') and sum of frequencies
        Node *merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        // Add the new merged node back into the priority queue
        pq.push(merged);
    }

    // Final node in the priority queue is the root of the Huffman Tree
    Node* root = pq.top();

    // ---------- Step 4: Generate Huffman Codes ----------
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);  // Start with empty string

    // Print all characters with their corresponding Huffman codes
    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << " -> " << pair.second << '\n';
    }

    // ---------- Step 5: Encode the input string ----------
    string encoded = "";
    for (char ch : text) {
        encoded += huffmanCode[ch];  // Replace each character with its code
    }

    cout << "\nEncoded string:\n" << encoded << endl;

    // ---------- Step 6: Decode the encoded string ----------
    string decoded = decode(root, encoded);
    cout << "\nDecoded string:\n" << decoded << endl;
}

// ------------------------- Main Function -------------------------
int main() {
    string text = "sudais";  // Input string to encode
    cout << "Original string:\n" << text << "\n\n";

    HuffmanCoding(text);  // Perform Huffman Encoding and Decoding
    return 0;
}
