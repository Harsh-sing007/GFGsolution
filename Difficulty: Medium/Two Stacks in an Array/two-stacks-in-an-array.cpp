#include <bits/stdc++.h>
using namespace std;

class twoStacks {
    int *arr;
    int size;
    int top1, top2;

public:
    // ✅ Default constructor for GFG's Driver (calls parameterized one)
    twoStacks() {
        size = 100; // GFG uses fixed 100
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    // ✅ Parameterized constructor (for completeness)
    twoStacks(int n) {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = n;
    }

    // ✅ Push element into stack1
    void push1(int x) {
        if (top1 + 1 < top2) {
            arr[++top1] = x;
        }
        // else overflow ignored (as per GFG convention)
    }

    // ✅ Push element into stack2
    void push2(int x) {
        if (top2 - 1 > top1) {
            arr[--top2] = x;
        }
    }

    // ✅ Pop from stack1
    int pop1() {
        if (top1 >= 0) {
            return arr[top1--];
        }
        return -1;
    }

    // ✅ Pop from stack2
    int pop2() {
        if (top2 < size) {
            return arr[top2++];
        }
        return -1;
    }
};
