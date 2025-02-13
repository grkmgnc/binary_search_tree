#include <stdio.h>
#include <stdlib.h>

//  İkili ağaç düğümü yapısı
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
void deleteNode(struct Node **);
int goMostLeft(struct Node **);
// Yeni düğüm oluşturma fonksiyonu
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// İkili arama ağacına eleman ekleme fonksiyonu
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

void preOrder(struct Node *root)
{

    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
    else
        return;
}

void inOrder(struct Node *root)
{

    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
    else
        return;
}

void postOrder(struct Node *root)
{

    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }

    else
        return;
}
void delete(int key, struct Node **leaf)
{

    if (*leaf == NULL)
        return;
    else if (key == (*leaf)->data)
        deleteNode(&(*leaf));
    else if (key < (*leaf)->data)
        delete (key, &(*leaf)->left);
    else if (key > (*leaf)->data)
        delete (key, &(*leaf)->right);
}
void deleteNode(struct Node **leaf)
{
    struct Node *deleted;

    if ((*leaf)->left == NULL && (*leaf)->right == NULL) // has no child
    {
        free(*leaf);
        *leaf = NULL;
    }
    else if ((*leaf)->left == NULL) // has only right child
    {
        deleted = *leaf;
        *leaf = (*leaf)->right;
        deleted->right = NULL;
        free(deleted);
    }
    else if ((*leaf)->right == NULL) // has only left child
    {
        deleted = *leaf;
        *leaf = (*leaf)->left;
        deleted->left = NULL;
        free(deleted);
    }
    else // has right and left child
    {
        (*leaf)->data = goMostLeft(&(*leaf)->right);
    }
}
int goMostLeft(struct Node **leaf)
{
    if ((*leaf)->left == NULL)
    {
        int data = (*leaf)->data;
        struct Node *deleted = *leaf;
        *leaf = (*leaf)->right;
        deleted->right = NULL;
        free(deleted);
        return data;
    }
    else
        goMostLeft(&(*leaf)->left);
}

int main()
{
    struct Node *root = NULL;

    // Ağaca eleman ekleme
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // Dolaşma yöntemlerini ekrana yazdırma
    printf("Pre-order traversal: ");
    preOrder(root);
    printf("\n");
    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");
    printf("Post-order traversal: ");
    postOrder(root);
    printf("\n");
    delete (70, &root);
    inOrder(root);
    printf("\n");
    delete (70, &root);
    inOrder(root);
    printf("\n");
    delete (30, &root);
    inOrder(root);
    printf("\n");
    return 0;
}
