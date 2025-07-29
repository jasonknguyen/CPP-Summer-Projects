#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int num){
        data = num;
        next = nullptr;
        prev = nullptr;
    }
};


class DoublyLinkedList{
    private:
    Node* head;
    Node* tail;
    int length;
    


    public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList& other);
    DoublyLinkedList& operator=(const DoublyLinkedList& other);

    void push(int data); // append new node at end of list
    void pop(); // remove last element of the list
    int size() const; //returns number of elements in the list
    void print(); // prints all elements in the list to the console
    int& at(int idx) const; // returns a reference to the data at the requested index
    void insert(int data, int pos); // insert new node containing data at pos, all elements at position are shifted forward
    void remove(int pos); // remove element at the specified position

};

DoublyLinkedList::DoublyLinkedList(){
    head = nullptr;
    tail = nullptr;
    length = 0;
}

void DoublyLinkedList::push(int data){
    Node* newNode = new Node(data);

    if(head == nullptr){
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    length++;
}

void DoublyLinkedList::print(){
    Node* current = head;

    while (current != nullptr){
        cout << current->data << endl;
        current = current->next;
    }
}

void DoublyLinkedList::pop(){

    if(head == nullptr){
        cout << "Error: List is Empty" << endl;
        return;
    } else if (head == tail){
        delete  tail;
        head = nullptr;
        tail = nullptr;
    } else {
        Node* nodeDelete = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete nodeDelete;

    }

    length--;


}

int DoublyLinkedList::size() const{
    return length;
}

int& DoublyLinkedList::at(int idx) const{
    if(head == nullptr){ //check if list is empty
        throw out_of_range("List is empty");
    } else if (idx < 0 || idx >= length){ // check if index is out of range
        throw out_of_range("Out of range");
    }

    int current_idx = 0;
    Node* currentNode = head;

    while(current_idx != idx){
        current_idx++;
        currentNode = currentNode->next;
    }

    return currentNode->data;


}

void DoublyLinkedList::insert(int data, int pos){
    if(pos < 0 || pos > length){ // check if pos is out of range
        throw out_of_range("Index out of range");
    }

    Node* newNode = new Node(data);

    if(head == nullptr){
        head = newNode;
        tail = newNode;
    } else if (pos == 0){ // first index
        newNode->next = head; //swap
        head->prev = newNode;
        head = newNode;
    } else if(pos == length ) { // last index
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    } else { //index in between head & tail
        Node* current = head;

        for(int i = 0; i < pos; i++){
            current = current->next;
        }

        Node* previous = current->prev;

        newNode->prev = previous; // set previous & next of new node
        newNode->next = current;

        previous->next = newNode; // change next of previous to newNode inserted
        current->prev = newNode; // change previous of current node to newNode inserted
    }

    length++;
}

void DoublyLinkedList::remove(int pos){ 
    if(pos < 0 || pos >= length){ // check if pos is out of range
        throw out_of_range("Index out of range");
    }

    if(head == nullptr){
        throw out_of_range("List is empty");
    } else if(pos == 0) { //removing head
        Node* next = head->next;
        delete head;
        head = next;

        if(head != nullptr){ // check if removed last and only node
            head->prev = nullptr; // if not, assign nullptr to previous of new head
        } else {
            tail = nullptr; // if yes, make both tail and head nullptr
        }
    } else if(pos == length - 1){ // removing tail
        Node* replacement = tail->prev;
        delete tail;
        tail = replacement;
        
        if(tail != nullptr){ // check if tail was last node in list
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
    } else { //removing between head & tail
        Node* current = head;

        for(int i = 0; i < pos; i++){
            current = current->next;
        }

        Node* previous = current->prev;
        Node* next = current->next;

        previous->next = next;
        next->prev = previous;

        delete current;

    }

    length--;
}

DoublyLinkedList::~DoublyLinkedList(){ // deconstructor
    Node* current = head;
    while(current != nullptr){
        Node* next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
    tail = nullptr;
    length = 0;
}

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& other){
    head = nullptr;
    tail = nullptr;
    length = 0;

    Node* current = other.head;
    while(current != nullptr){
        push(current->data);
        current = current->next;
    }
}

DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& other){
   while(head != nullptr){
    Node* next = head->next;
    delete head;
    head = next;
   }

   head = nullptr;
   tail = nullptr;

   for(int i = 0; i < other.size(); i++){
    push(other.at(i));
   }

   return *this;
}

void test(){
    DoublyLinkedList dll;
    
    dll.push(1);
    dll.push(2);
    dll.push(3);
    
    DoublyLinkedList dllCopy = dll;
    
    dllCopy.push(4);
    dllCopy.remove(1);
    dllCopy.remove(0);
    dllCopy.insert(5, 1);
    
    dll.print();
    dllCopy.print();
    
    dll = dllCopy;
    dll.print();
}

int main() {
    test();
    return 0;
}
//~DoublyLinkedList();
   // DoublyLinkedList(const DoublyLinkedList& other);
   // DoublyLinkedList& operator=(const DoublyLinkedList& other);
