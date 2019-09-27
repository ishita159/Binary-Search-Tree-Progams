#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
};
Node *newnode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
Node *insert(Node *node, int data)
{
    if (node == NULL)
        return newnode(data);
    if (node->data >= data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);
    return node;
}
int findheight(Node *node)
{
    if (node == NULL)
        return 0;
    int lh = 0, rh = 0;
    if (node->left != NULL)
        lh = findheight(node->left);
    if (node->right != NULL)
        rh = findheight(node->right);
    return max(lh, rh) + 1;
}
int main()
{
    int n;
    cin >> n;
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (i == 0)
            root = insert(root, temp);
        else
            insert(root, temp);
    }
    cout << findheight(root) << "\n";
    return 0;
}