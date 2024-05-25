/*
* A linked list is a linear data structure, in which the elements are not stored at contiguous memory locations (unlike arrays).
* The elements in a linked list are linked using pointers.
* In simple words, a linked list consists of nodes where each node contains a data field and a reference(link) to the next node in the list.
* This is called a self-referential structure.
* A linked list is a dynamic data structure. The number of nodes in a list is not fixed and can grow and shrink on demand, so they are useful with unknown dataset size problems.
* A linked list may be singly linked, doubly linked, or circular linked (queue).
*/

// Here, we will implement a queue using a doubly linked list.
// Each node will have a pointer to the next node and a pointer to the previous node.

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }

    void print() {
        cout << "Data: " << data << endl;
    }
};

class Queue {
    public:
    Node* head;
    // head->prev will be the tail
    // tail->next will be the head

    Queue() {
        head = nullptr;
    }

    ~Queue() {
        delete head;
    }

    // enqueue will add a new node at the end of the queue
    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    // dequeue will remove the first node from the queue (FIFO)
    int dequeue() {
        if (head == nullptr) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int data = head->data;
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            head = head->next;
            head->prev = temp->prev;
            temp->prev->next = head;
            delete temp;
        }
        return data;
    }

    void print() {
        if (head == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = head;
        do {
            temp->print();
            temp = temp->next;
        } while (temp != head);
    }

    int size() {
        if (head == nullptr) {
            return 0;
        }
        int count = 0;
        Node* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void clear() {
        delete head;
        head = nullptr;
    }

    void sortDescending() {
        if (head == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = head;
        do {
            Node* temp2 = temp->next;
            do {
                if (temp->data > temp2->data) {
                    int tempData = temp->data;
                    temp->data = temp2->data;
                    temp2->data = tempData;
                }
                temp2 = temp2->next;
            } while (temp2 != head);
            temp = temp->next;
        } while (temp != head);
    }

    void sortAscending() {
        if (head == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = head;
        do {
            Node* temp2 = temp->next;
            do {
                if (temp->data < temp2->data) {
                    int tempData = temp->data;
                    temp->data = temp2->data;
                    temp2->data = tempData;
                }
                temp2 = temp2->next;
            } while (temp2 != head);
            temp = temp->next;
        } while (temp != head);
    }
};

int main() {
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    queue.print();
    cout << "Size: " << queue.size() << endl;
    cout << "Dequeue: " << queue.dequeue() << endl;
    cout << "Dequeue: " << queue.dequeue() << endl;
    cout << "Dequeue: " << queue.dequeue() << endl;
    cout << "Clearing the queue" << endl;
    queue.clear();
    queue.print();
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    cout << "Sorting the queue in descending order" << endl;
    queue.sortDescending();
    queue.print();
    cout << "Sorting the queue in ascending order" << endl;
    queue.sortAscending();
    queue.print();
    return 0;
}