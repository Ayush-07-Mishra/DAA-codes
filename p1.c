#include<stdio.h>
#include<stdlib.h>

struct HuffmanNode {
    char data;
    unsigned frequency;
    struct HuffmanNode* left;
    struct HuffmanNode* right;
};

struct HuffmanNode* createNode(char data, unsigned frequency) {
    struct HuffmanNode *node = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
    node->data = data;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct HuffmanNode* buildHuffmanTree(char data[], unsigned frequency[], int size) {
    struct HuffmanNode** nodes = (struct HuffmanNode**)malloc(size * sizeof(struct HuffmanNode*));
    
    for(int i = 0; i < size; i++) {
        nodes[i] = createNode(data[i], frequency[i]);
    }
    for(int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            if(nodes[i]->frequency > nodes[j]->frequency) {
                struct HuffmanNode* temp = nodes[i];
                nodes[i] = nodes[j];
                nodes[j] = temp;
            }
        }
    }

    while (size > 1) {
        struct HuffmanNode* newnode = createNode('$' ,nodes[0]->frequency + nodes[1]->frequency);
        newnode->left = nodes[0];
        newnode->right = nodes[1];

        nodes[0] = newnode;

        for(int i = 1; i < size - 1; i++) {
            nodes[i] = nodes[i + 1];
        }

        size--;
    }
    struct HuffmanNode* root = nodes[0];
    free(nodes);
    
    return root;
}

void printHuffmanCodes(struct HuffmanNode* root, char code[], int depth) {
    if(root == NULL) {
        return;
    }

    if(root->data != '$') {
        code[depth] = '\0';
        printf("%c: %s\n", root->data, code);
    }

    code[depth] = '0';
    printHuffmanCodes(root->left, code, depth + 1);
    
    code[depth] = '1';
    printHuffmanCodes(root->right, code, depth + 1);
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    unsigned frequency[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    struct HuffmanNode* root = buildHuffmanTree(data, frequency, size);

    char code[size];
    printf("Huffman Codes:\n");
    printHuffmanCodes(root, code, 0);

    return 0;
}
