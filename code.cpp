// // problem 01. Get Difference
// #include <bits/stdc++.h>

// using namespace std;

// struct Node {
//     int value;
//     Node* next;
    
//     Node(int val) : value(val), next(nullptr) {}
// };

// Node* createLinkedList() {
//     int value;
//     Node* head = nullptr;
//     Node* tail = nullptr;

//     while (cin >> value && value != -1) {
//         Node* newNode = new Node(value);
        
//         if (head == nullptr) {
//             head = newNode;
//             tail = head;
//         } else {
//             tail->next = newNode;
//             tail = newNode;
//         }
//     }
//     return head;
// }

// int calculateDifference(Node* head) {
//     if (head == nullptr) {
//         return 0;
//     }
    
//     int max_val = INT_MIN;
//     int min_val = INT_MAX;
    
//     Node* current = head;
//     while (current != nullptr) {
//         max_val = max(max_val, current->value);
//         min_val = min(min_val, current->value);
//         current = current->next;
//     }

//     return max_val - min_val;
// }

// int main() {
//     Node* head = createLinkedList();
    
//     cout << calculateDifference(head) << endl;

//     return 0;
// }


// // problem 02. Search

// #include <bits/stdc++.h>

// using namespace std;

// struct Node {
//     int value;
//     Node* next;
    
//     Node(int val) : value(val), next(nullptr) {}
// };

// Node* createLinkedList() {
//     int value;
//     Node* head = nullptr;
//     Node* tail = nullptr;

//     while (cin >> value && value != -1) {
//         Node* newNode = new Node(value);
        
//         if (head == nullptr) {
//             head = newNode;
//             tail = head;
//         } else {
//             tail->next = newNode;
//             tail = newNode;
//         }
//     }
//     return head;
// }

// int findIndex(Node* head, int X) {
//     int index = 0;
//     Node* current = head;

//     while (current != nullptr) {
//         if (current->value == X) {
//             return index;
//         }
//         current = current->next;
//         index++;
//     }

//     return -1;
// }

// int main() {
//     int T;
//     cin >> T;

//     while (T--) {
//         Node* head = createLinkedList();

//         int X;
//         cin >> X;

//         cout << findIndex(head, X) << endl;
//     }

//     return 0;
// }

// problem 03. Same to Same


// #include <bits/stdc++.h>

// using namespace std;

// struct Node {
//     int value;
//     Node* next;
    
//     Node(int val) : value(val), next(nullptr) {}
// };

// Node* createLinkedList() {
//     int value;
//     Node* head = nullptr;
//     Node* tail = nullptr;

//     while (cin >> value && value != -1) {
//         Node* newNode = new Node(value);
        
//         if (head == nullptr) {
//             head = newNode;
//             tail = head;
//         } else {
//             tail->next = newNode;
//             tail = newNode;
//         }
//     }
//     return head;
// }

// bool areIdentical(Node* head1, Node* head2) {
//     while (head1 != nullptr && head2 != nullptr) {
//         if (head1->value != head2->value) {
//             return false;
//         }
//         head1 = head1->next;
//         head2 = head2->next;
//     }
    
//     return head1 == nullptr && head2 == nullptr;
// }

// int main() {
//     Node* head1 = createLinkedList();

//     Node* head2 = createLinkedList();

//     if (areIdentical(head1, head2)) {
//         cout << "YES" << endl;
//     } else {
//         cout << "NO" << endl;
//     }

//     return 0;
// }

// // problem 04. Queries

// #include <iostream>
// using namespace std;

// struct Node {
//     int value;
//     Node* next;
    
//     Node(int val) : value(val), next(nullptr) {}
// };

// class LinkedList {
// public:
//     Node* head;
    
//     LinkedList() : head(nullptr) {}
    
//     void insertAtHead(int value) {
//         Node* newNode = new Node(value);
//         newNode->next = head;
//         head = newNode;
//     }
    
//     void insertAtTail(int value) {
//         Node* newNode = new Node(value);
//         if (!head) {
//             head = newNode;
//         } else {
//             Node* temp = head;
//             while (temp->next) {
//                 temp = temp->next;
//             }
//             temp->next = newNode;
//         }
//     }
    
//     void deleteAtIndex(int index) {
//         if (index < 0) return;
        
//         if (index == 0 && head) {
//             Node* temp = head;
//             head = head->next;
//             delete temp;
//             return;
//         }
        
//         Node* temp = head;
//         int count = 0;
        
//         while (temp && count < index - 1) {
//             temp = temp->next;
//             count++;
//         }
        
//         if (temp && temp->next) {
//             Node* nodeToDelete = temp->next;
//             temp->next = temp->next->next;
//             delete nodeToDelete;
//         }
//     }
    
//     void printList() {
//         Node* temp = head;
//         if (!temp) {
//             cout << endl;
//             return;
//         }
        
//         while (temp) {
//             cout << temp->value;
//             if (temp->next) cout << " ";
//             temp = temp->next;
//         }
//         cout << endl;
//     }
// };

// int main() {
//     int Q;
//     cin >> Q;
    
//     LinkedList list;
    
//     for (int i = 0; i < Q; i++) {
//         int X, V;
//         cin >> X >> V;
        
//         if (X == 0) {
//             list.insertAtHead(V);
//         } else if (X == 1) {
//             list.insertAtTail(V);
//         } else if (X == 2) {
//             list.deleteAtIndex(V);
//         }
        
//         list.printList();
//     }
    
//     return 0;
// }


// //problem 05. Remove Duplicate

// #include <bits/stdc++.h>

// using namespace std;



// struct Node {
//     int value;
//     Node* next;
    
//     Node(int val) : value(val), next(nullptr) {}
// };

// class LinkedList {
// public:
//     Node* head;
    
//     LinkedList() : head(nullptr) {}
    
//     void insert(int value) {
//         Node* newNode = new Node(value);
//         if (!head) {
//             head = newNode;
//         } else {
//             Node* temp = head;
//             while (temp->next) {
//                 temp = temp->next;
//             }
//             temp->next = newNode;
//         }
//     }

//     void removeDuplicates() {
//         if (!head) return;
        
//         unordered_set<int> seen;
//         Node* current = head;
//         Node* prev = nullptr;
        
//         while (current) {
//             if (seen.find(current->value) != seen.end()) {
//                 prev->next = current->next;
//                 delete current;
//                 current = prev->next;
//             } else {
//                 seen.insert(current->value);
//                 prev = current;
//                 current = current->next;
//             }
//         }
//     }
    
//     void printList() {
//         Node* temp = head;
//         if (!temp) {
//             cout << endl;
//             return;
//         }
        
//         while (temp) {
//             cout << temp->value;
//             if (temp->next) cout << " ";
//             temp = temp->next;
//         }
//         cout << endl;
//     }
// };

// int main() {
//     int value;
//     LinkedList list;
    
//     while (cin >> value) {
//         if (value == -1) break;
//         list.insert(value);
//     }
    
//     list.removeDuplicates();
    
//     list.printList();
    
//     return 0;
// }


