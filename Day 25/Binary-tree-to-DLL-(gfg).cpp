class Solution {
  public:
    void intrv(Node* root, vector<int>& ans) {
        if (!root) return;
        intrv(root->left, ans);
        ans.push_back(root->data);
        intrv(root->right, ans);
    }

    Node* dd(vector<int> ans, int n) {
        if (n == 0) {
            return nullptr; // Handle empty array case
        }

        Node* head = new Node(ans[0]);
        Node* temp = head;

        for (int i = 1; i < n; i++) {
            Node* newNode = new Node(ans[i]);
            temp->right = newNode;
            newNode->left = temp;
            temp = temp->right;
        }

        return head;
    }

    Node* bToDLL(Node* root) {
        vector<int> ans;
        intrv(root, ans);
        int n = ans.size();
        Node* curr = dd(ans, n);
        return curr;
    }
};