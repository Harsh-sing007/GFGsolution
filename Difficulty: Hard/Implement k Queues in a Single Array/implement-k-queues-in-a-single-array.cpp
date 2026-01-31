class kQueues {
private:
    int *arr;       // main array
    int *front;     // front indices of queues
    int *rear;      // rear indices of queues
    int *next;      // next index array
    int freeSpot;   // beginning of free list
    int n, k;

public:
    kQueues(int n, int k) {
        this->n = n;
        this->k = k;

        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];

        // Initialize queues as empty
        for (int i = 0; i < k; i++) {
            front[i] = rear[i] = -1;
        }

        // Initialize free list
        for (int i = 0; i < n - 1; i++) {
            next[i] = i + 1;
        }
        next[n - 1] = -1;

        freeSpot = 0;
    }

    // Check if array is full
    bool isFull() {
        return freeSpot == -1;
    }

    // Check if i-th queue is empty
    bool isEmpty(int qi) {
        return front[qi] == -1;
    }

    // Enqueue x into i-th queue
    void enqueue(int x, int qi) {
        if (isFull()) return;

        int index = freeSpot;
        freeSpot = next[index];

        arr[index] = x;
        next[index] = -1;

        if (front[qi] == -1) {
            front[qi] = index;
        } else {
            next[rear[qi]] = index;
        }

        rear[qi] = index;
    }

    // Dequeue from i-th queue
    int dequeue(int qi) {
        if (isEmpty(qi)) return -1;

        int index = front[qi];
        front[qi] = next[index];

        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }
};
