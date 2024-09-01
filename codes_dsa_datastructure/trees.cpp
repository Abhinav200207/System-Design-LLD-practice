#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution
{
    vector<int> preorder(TreeNode *root)
    {
        vector<int> pre;
        if (!root)
            return {};
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *curr = st.top();
            st.pop();
            pre.push_back(curr->val);
            if (curr->right)
            {
                st.push(curr->right);
            }
            if (curr->left)
            {
                st.push(curr->left);
            }
        }
        return pre;
    }
    vector<int> inorder(TreeNode *root)
    {
        vector<int> in;
        if (!root)
            return {};
        stack<TreeNode *> st;
        TreeNode *curr = root;

        while (curr || !st.empty())
        {
            while (curr)
            {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            in.push_back(curr->val);

            curr = curr->right;
        }
        return in;
    }
    vector<int> postorder(TreeNode *root)
    {
        stack<TreeNode *> st1, st2;
        st1.push(root);

        while (!st1.empty())
        {
            TreeNode *curr = st1.top();
            st1.pop();

            if (curr->left)
            {
                st1.push(curr->left);
            }
            if (curr->right)
            {
                st1.push(curr->right);
            }
            st2.push(curr);
        }
        vector<int> post;
        while (!st2.empty())
        {
            post.push_back(st2.top()->val);
            st2.pop();
        }
        return post;
    }

    vector<int> postorder(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> post;

        stack<TreeNode *> st;
        while (root || !st.empty())
        {

            if (root)
            {
                st.push(root);
                root = root->left;
            }
            else
            {
                TreeNode *temp = st.top()->right;
                if (!temp)
                {
                    temp = st.top();
                    st.pop();
                    post.push_back(temp->val);
                    while (!st.empty() && temp == st.top()->right)
                    {
                        temp = st.top();
                        st.pop();
                        post.push_back(temp->val);
                    }
                }
                else
                {
                    root = temp;
                }
            }
        }
        return post;
    }
    vector<int> inorder(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> in;

        TreeNode *curr = root;

        while (curr)
        {
            if (!curr->left)
            {
                in.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode *temp = curr->left;
                while (temp->right && temp->right != curr)
                {
                    temp = temp->right;
                }

                if (!temp->right)
                {
                    temp->right = curr;
                    curr = curr->left;
                }
                else
                {
                    temp->right = NULL;
                    in.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return in;
    }
    vector<int> preorder(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> pre;

        TreeNode *curr = root;

        while (curr)
        {
            if (!curr->left)
            {
                pre.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode *temp = curr->left;
                while (temp->right && temp->right != curr)
                {
                    temp = temp->right;
                }

                if (!temp->right)
                {
                    temp->right = curr;
                    pre.push_back(curr->val);
                    curr = curr->left;
                }
                else
                {
                    temp->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return pre;
    }
    void flatten(TreeNode *root) // Preorder
    {
        TreeNode *curr = root;

        while (curr)
        {
            if (curr->left)
            {
                TreeNode *temp = curr->left;
                while (temp->right)
                {
                    temp = temp->right;
                }

                temp->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
    TreeNode *prev = NULL;
    void flatten(TreeNode *root) // Preorder - recursive
    {
        if (!root)
            return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }

    TreeNode *head = NULL;
    TreeNode *prev = NULL;
    TreeNode *bToDLL(TreeNode *root) // inorder - recursive
    {
        if (!root)
            return NULL;
        bToDLL(root->left);
        if (head == NULL)
            head = root;
        else
        {
            prev->right = root;
            root->left = prev;
        }
        prev = root;
        bToDLL(root->right);
        return head;
    }
    TreeNode *bToDLL(TreeNode *root) // inorder - iterative
    {
        if (!root)
            return NULL;

        TreeNode *head = NULL;
        TreeNode *prev = NULL;
        TreeNode *curr = root;
        std::stack<TreeNode *> st;

        while (curr != NULL || !st.empty())
        {
            while (curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            if (head == NULL)
            {
                head = curr;
            }
            else
            {
                prev->right = curr;
                curr->left = prev;
            }

            prev = curr;
            curr = curr->right;
        }

        return head;
    }
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            // If the tree is empty, create a new node with the given value
            TreeNode *newNode = new TreeNode(val);
            return newNode;
        }

        if (val < root->val)
        {
            // If the value is less than the current node's value, go to the left subtree
            root->left = insertIntoBST(root->left, val);
        }
        else
        {
            // If the value is greater than or equal to the current node's value, go to the right subtree
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if (root->left == NULL)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                TreeNode *minNode = findMinNode(root->right);
                root->val = minNode->val;
                root->right = deleteNode(root->right, minNode->val);
            }
        }

        return root;
    }
    TreeNode *findMinNode(TreeNode *node)
    {
        while (node->left != NULL)
        {
            node = node->left;
        }
        return node;
    }
    void allTraversal(TreeNode *root)
    {
        stack<pair<TreeNode *, int>> st;
        st.push({root, 1});
        vector<int> pre, in, post;

        if (!root)
            return;

        while (st.size())
        {
            auto p = st.top();
            st.pop();

            if (p.second == 1)
            {
                pre.push_back(p.first->val);
                p.second++;
                st.push(p);

                if (p.first->left != NULL)
                {
                    st.push({p.first, 1});
                }
            }
            else if (p.second == 2)
            {
                in.push_back(p.first->val);
                p.second++;
                st.push(p);

                if (p.first->right != NULL)
                {
                    st.push({p.first, 1});
                }
            }
            else
            {
                post.push_back(p.first->val);
            }
        }
    }
};