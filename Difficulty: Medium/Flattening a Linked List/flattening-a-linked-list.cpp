class Solution {
public:

    Node* mergeBottom(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;

        Node* result;
        if (a->data < b->data) {
            result = a;
            result->bottom = mergeBottom(a->bottom, b);
        } else {
            result = b;
            result->bottom = mergeBottom(a, b->bottom);
        }

        result->next = NULL;
        return result;
    }

    Node* flatten(Node* root) {
        if (!root || !root->next)
            return root;

        root->next = flatten(root->next);
        root = mergeBottom(root, root->next);

        return root;
    }
};
