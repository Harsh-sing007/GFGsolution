class Solution {
public:
    struct Node {
        int freq;
        int order;  // smallest index in subtree
        Node *left, *right;
        
        Node(int f, int o) {
            freq = f;
            order = o;
            left = right = NULL;
        }
    };
    
    struct cmp {
        bool operator()(Node* a, Node* b) {
            if (a->freq == b->freq)
                return a->order > b->order;  // smaller index first
            return a->freq > b->freq;
        }
    };
    
    void preorder(Node* root, string code, vector<string>& ans) {
        if (!root) return;
        
        if (!root->left && !root->right) {
            ans.push_back(code);
            return;
        }
        
        preorder(root->left, code + "0", ans);
        preorder(root->right, code + "1", ans);
    }
    
    vector<string> huffmanCodes(string S, vector<int> f) {
        int N = S.size();
        
        if (N == 1) return {"0"};
        
        priority_queue<Node*, vector<Node*>, cmp> pq;
        
        // Insert leaf nodes
        for (int i = 0; i < N; i++) {
            pq.push(new Node(f[i], i));
        }
        
        while (pq.size() > 1) {
            Node* left = pq.top(); pq.pop();
            Node* right = pq.top(); pq.pop();
            
            Node* newNode = new Node(
                left->freq + right->freq,
                min(left->order, right->order)  // ✅ FIX
            );
            
            newNode->left = left;
            newNode->right = right;
            
            pq.push(newNode);
        }
        
        vector<string> ans;
        preorder(pq.top(), "", ans);
        
        return ans;
    }
};