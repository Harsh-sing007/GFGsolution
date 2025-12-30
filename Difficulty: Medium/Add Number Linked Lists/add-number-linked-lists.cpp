class Solution {
private:
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;

        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    Node* addTwoLists(Node* num1, Node* num2) {

        num1 = reverse(num1);
        num2 = reverse(num2);

        Node* dummy = new Node(0);
        Node* curr = dummy;
        int carry = 0;
        while (num1 || num2 || carry) {
            int sum = carry;

            if (num1) {
                sum += num1->data;
                num1 = num1->next;
            }
            if (num2) {
                sum += num2->data;
                num2 = num2->next;
            }

            carry = sum / 10;
            curr->next = new Node(sum % 10);
            curr = curr->next;
        }
        Node* result = reverse(dummy->next);

        while (result && result->data == 0 && result->next) {
            result = result->next;
        }

        return result;
    }
};
