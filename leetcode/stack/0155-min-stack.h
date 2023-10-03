/**
 * @see https://leetcode.com/problems/min-stack/description/
 * 
 * Double Linked List
 * 
 */
class MinStack {
public:
    class Node {
        public:
            int val;
            int min;
            Node *prev, *next;
        Node(int _val, int _min): val(_val), min(_min) {
            prev = NULL;
            next = NULL;
        }
    };
    Node* head = new Node(INT_MAX, INT_MAX);
    Node* tail = new Node(INT_MAX, INT_MAX);
    MinStack() {
        head->next = tail;
        tail->prev = head;
    }

    void insertNode(int val, int min) {
        Node* nn = new Node(val, min);
        nn->next = tail;
        nn->prev = tail->prev;
        tail->prev->next = nn;
        tail->prev = nn;
    }
    
    void push(int val) {
        if (head->next == tail) {
            insertNode(val, val);
        } else {
            Node* temp = tail->prev;
            if (val <= temp->min) {
                insertNode(val, val);
            } else {
                insertNode(val, temp->min);
            }
        }
    }
    
    void pop() {
        if (head->next == tail) return;

        Node* temp = tail->prev;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
        temp = NULL;
    }
    
    int top() {
        return tail->prev->val;
    }
    
    int getMin() {
        return tail->prev->min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */