#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>

struct HuffmanNode{
    char data;
    unsigned frequency;
    struct HuffmanNode * left;
    struct HuffmanNode * right;
};

struct HuffmanNode* createNode(char data,unsigned frequency,int size){
    struct HuffmanNode* node = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
    node->data = data;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct HuffmanNode* buildHuffmanTree(char data[],unsigned frequency[]){
    struct HuffmanNode** nodes = (struct HuffmanNode**)malloc(size * sizeof(struct HuffmanNode*));
    for(int i =0;i<size;i++){
        nodes[i] = createNode(data[i],frequency[i]);
    }

    while(size > 1){

        for(int i =0;i<size-1;i++){
            for(int j = i+1;j<size;j++){
                if(nodes[i]->frequency > nodes[j]->frequency){
                    struct HuffmanNode* temp = nodes[i];
                    nodes[i] = nodes[j]
                    nodes[j] = temp;
                }
            }
        }

        struct HuffmanNode* newNode = createNode('$',nodes[0]->frequency + nodes[1]->frequency);
        newNode->left = nodes[0];
        newNode->right = nodes[1];
        nodes[0] = newNode;

        for(int i =0;i<size-1;i++){
            nodes[i] = nodes[i+1];
        }

        size--;

    }

    struct HuffmanNode* root = nodes[0];
    free(nodes);

    return root;
}

void generateHuffmanCodes(char code[],struct HuffmanNode* root,int depth){

    if(root == NULL){
        return ;
    }
    if(root->data != '$'){
        code[depth] = '\0';
        printf("%c : %s\n",root->data,code);
    }

    code[depth] = '0';
    generateHuffmanCodes(code,root->left,depth + 1);
    generateHuffmanCodes(code,root->right,depth+1);
}

int main(){
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    unsigned frequency[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    struct HuffmanNode* root = buildHuffmanTree(data,frequency,size);

    char code[size];
    printf("Huffman codes: \n");
    printHuffmanCodes(root,code,0);

    return 0;
}