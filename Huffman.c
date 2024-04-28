#include <stdio.h>
#include <stdlib.h>

struct HuffmanNode {
    char data;
    unsigned frequency;
    struct HuffmanNode* left;
    struct HuffmanNode* right;
};

struct HuffmanNode* createNode(char data, unsigned frequency) {
    struct HuffmanNode* node = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
    node->data = data;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct HuffmanNode* buildHuffmanTree(char data[], unsigned frequency[], int size) {
    struct HuffmanNode** nodes = (struct HuffmanNode**)malloc(size * sizeof(struct HuffmanNode*));
    
    for (int i = 0; i < size; i++) {
        nodes[i] = createNode(data[i], frequency[i]);
    }

    while (size > 1) {
        int min1 = 0, min2 = 1;
        for (int i = 2; i < size; i++) {
            if (nodes[i]->frequency < nodes[min1]->frequency) {
                min2 = min1;
                min1 = i;
            } else if (nodes[i]->frequency < nodes[min2]->frequency) {
                min2 = i;
            }
        }

        struct HuffmanNode* newNode = createNode('$', nodes[min1]->frequency + nodes[min2]->frequency);
        newNode->left = nodes[min1];
        newNode->right = nodes[min2];

        nodes[min1] = newNode;
        nodes[min2] = nodes[size - 1];
        size--;
    }

    struct HuffmanNode* root = nodes[0];
    free(nodes);
    return root;
}

void generateHuffmanCodes(struct HuffmanNode* root, char code[], int depth) {
    if (root == NULL) {
        return;
    }

    if (root->data != '$') {
        code[depth] = '\0';
        printf("%c: %s\n", root->data, code);
    }

    code[depth] = '0';
    generateHuffmanCodes(root->left, code, depth + 1);

    code[depth] = '1';
    generateHuffmanCodes(root->right, code, depth + 1);
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    unsigned frequency[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    struct HuffmanNode* root = buildHuffmanTree(data, frequency, size);

    char code[size];
    printf("Huffman Codes:\n");
    generateHuffmanCodes(root, code, 0);

    return 0;
}
