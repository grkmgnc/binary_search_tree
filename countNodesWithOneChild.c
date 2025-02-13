#include <stdio.h>
#include <stdlib.h>
// Binary Tree Example (Not a binary search tree)
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Tek çocuğu olan düğümlerin sayısını hesaplayan recursive fonksiyonumuz
int countNodesWithOneChild(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int count = 0;

    // Eğer bir çocuğu varsa sayacı 1'e eşitliyoruz.
    if ((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL))
    {
        count = 1;
        printf("Tek cocuga sahip olan dugum: %d \n", root->data);
    }

    // Sol ve sağ alt ağaçları kontrol ediyoruz
    return count + countNodesWithOneChild(root->left) + countNodesWithOneChild(root->right);
}
int main()
{
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->right->right = createNode(5);
    root->right->right->right = createNode(6); // İstenilen şekilde ağacı oluşturuyoruz.

    printf("Tek cocuga sahip olan dugum sayisi : %d", countNodesWithOneChild(root));
}
