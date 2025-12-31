class Solution {
public:
    Node* intersectPoint(Node* head1, Node* head2) {
        if (!head1 || !head2) return NULL;

        Node* a = head1;
        Node* b = head2;

        while (a != b) {
            a = (a == NULL) ? head2 : a->next;
            b = (b == NULL) ? head1 : b->next;
        }

        return a; 
    }
};
