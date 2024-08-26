#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
    ListNode(int x) : data(x), next(NULL) {}
};

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};

TreeNode *insertToBST(TreeNode *root, int data)
{
    if (root == NULL)
    {
        return new TreeNode(data);
    }
    if (data < root->data)
    {
        root->left = insertToBST(root->left, data);
    }
    else
    {
        root->right = insertToBST(root->right, data);
    }
    return root;
}

TreeNode *listToBST(ListNode *head)
{
    TreeNode *root = NULL;
    ListNode *current = head;
    while (current != NULL)
    {
        root = insertToBST(root, current->data);
        current = current->next;
    }
    return root;
}

void inorderTraversal(TreeNode *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main()
{
    ListNode *head = new ListNode(5);
    head->next = new ListNode(3);
    head->next->next = new ListNode(8);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next = new ListNode(9);

    TreeNode *bstRoot = listToBST(head);

    cout << "Ikili Arama Agaci Inorder gezinme: ";
    inorderTraversal(bstRoot);
    cout << endl;

    return 0;
}