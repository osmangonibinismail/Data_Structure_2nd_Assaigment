// problem 01
// #include <iostream>
// #include <limits>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
// };

// Node* createNode(int value) {
//     Node* newNode = new Node;
//     newNode->data = value;
//     newNode->next = nullptr;
//     return newNode;
// }

// int findMaxMinDifference(Node* head) {
//     if (!head) return 0;

//     int maxVal = numeric_limits<int>::min();
//     int minVal = numeric_limits<int>::max();

//     Node* current = head;
//     while (current) {
//         if (current->data > maxVal) maxVal = current->data;
//         if (current->data < minVal) minVal = current->data;
//         current = current->next;
//     }

//     return maxVal - minVal;
// }

// int main() {
//     Node* head = nullptr;
//     Node* tail = nullptr;

//     int value;
//     while (cin >> value && value != -1) {
//         Node* newNode = createNode(value);

//         if (!head) {
//             head = newNode;
//             tail = newNode;
//         } else {
//             tail->next = newNode;
//             tail = newNode;
//         }
//     }

//     int difference = findMaxMinDifference(head);
//     cout << difference << endl;

//     Node* current = head;
//     while (current) {
//         Node* temp = current;
//         current = current->next;
//         delete temp;
//     }

//     return 0;
// }



//problem 02

// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
// };

// int main() {
//     int T;
//     cin >> T;
//     while (T--) {
//         Node* head = nullptr;
//         Node* tail = nullptr;

//         int value;
//         while (cin >> value && value != -1) {
//             Node* newNode = new Node;
//             newNode->data = value;
//             newNode->next = nullptr;

//             if (!head) {
//                 head = newNode;
//                 tail = newNode;
//             } else {
//                 tail->next = newNode;
//                 tail = newNode;
//             }
//         }

//         int X;
//         cin >> X;

//         int index = 0;
//         Node* current = head;
//         bool found = false;
//         while (current) {
//             if (current->data == X) {
//                 cout << index << endl;
//                 found = true;
//                 break;
//             }
//             current = current->next;
//             index++;
//         }

//         if (!found) {
//             cout << -1 << endl;
//         }

//         current = head;
//         while (current) {
//             Node* temp = current;
//             current = current->next;
//             delete temp;
//         }
//     }

//     return 0;
// }


//problem 03

// #include <iostream>
// using namespace std;

// int main() {
//     int value;

//     int list1[1000];
//     int size1 = 0;
//     while (cin >> value && value != -1) {
//         list1[size1++] = value;
//     }

//     int list2[1000];
//     int size2 = 0;
//     while (cin >> value && value != -1) {
//         list2[size2++] = value;
//     }

//     bool isSame = (size1 == size2);

//     for (int i = 0; i < size1 && isSame; ++i) {
//         if (list1[i] != list2[i]) {
//             isSame = false;
//         }
//     }

//     cout << (isSame ? "YES" : "NO") << endl;

//     return 0;
// }


//problem 04
// #include <iostream>
// using namespace std;

// struct Node {
//     int value;
//     Node* next;

//     Node(int val) : value(val), next(nullptr) {}
// };

// class LinkedList {
// private:
//     Node* head;
//     Node* tail;

// public:
//     LinkedList() : head(nullptr), tail(nullptr) {}

//     void insertHead(int val) {
//         Node* newNode = new Node(val);
//         if (!head) {
//             head = tail = newNode;
//         } else {
//             newNode->next = head;
//             head = newNode;
//         }
//     }

//     void insertTail(int val) {
//         Node* newNode = new Node(val);
//         if (!head) {
//             head = tail = newNode;
//         } else {
//             tail->next = newNode;
//             tail = newNode;
//         }
//     }

//     void deleteAtIndex(int index) {
//         if (!head || index < 0) return;

//         if (index == 0) {
//             Node* temp = head;
//             head = head->next;
//             if (!head) tail = nullptr;
//             delete temp;
//             return;
//         }

//         Node* current = head;
//         for (int i = 0; current && i < index - 1; ++i) {
//             current = current->next;
//         }

//         if (!current || !current->next) return;

//         Node* temp = current->next;
//         current->next = temp->next;
//         if (!current->next) tail = current;
//         delete temp;
//     }

//     void printList() {
//         Node* current = head;
//         while (current) {
//             cout << current->value << " ";
//             current = current->next;
//         }
//         cout << endl;
//     }
// };

// int main() {
//     int Q;
//     cin >> Q;

//     LinkedList list;

//     for (int i = 0; i < Q; ++i) {
//         int X, V;
//         cin >> X >> V;

//         if (X == 0) {
//             list.insertHead(V);
//         } else if (X == 1) {
//             list.insertTail(V);
//         } else if (X == 2) {
//             list.deleteAtIndex(V);
//         }

//         list.printList();
//     }

//     return 0;
// }


//problem 05
#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->value = val;
    newNode->next = nullptr;
    return newNode;
}

void insertHead(Node*& head, int val) {
    Node* newNode = createNode(val);
    newNode->next = head;
    head = newNode;
}

void insertTail(Node*& head, int val) {
    Node* newNode = createNode(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}

void deleteAtIndex(Node*& head, int index) {
    if (!head || index < 0) return;

    if (index == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    for (int i = 0; current && i < index - 1; ++i) {
        current = current->next;
    }

    if (!current || !current->next) return;

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}

void removeDuplicates(Node*& head) {
    Node* current = head;
    while (current) {
        Node* runner = current;
        while (runner->next) {
            if (runner->next->value == current->value) {
                Node* temp = runner->next;
                runner->next = runner->next->next;
                delete temp;
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    int val;
    while (cin >> val && val != -1) {
        insertTail(head, val);
    }

    removeDuplicates(head);
    printList(head);

    return 0;
}
