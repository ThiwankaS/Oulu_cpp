#include <iostream>
#include <memory>

using namespace std;

struct Item {
    int data;
    shared_ptr<Item> next;

    Item(int val) : data(val), next(nullptr) {}
};

int main() {

    /**
     * Creating the first node
    */
    shared_ptr<Item> first = make_shared<Item>(10);

    /**
     * Creating the second node and add to first node
    */
    first->next = make_shared<Item>(20);

    /**
     * Creating the third node and add to second node
    */
    first->next->next = make_shared<Item>(30);

    /**
     * Creating the a temporary pointer current, which will point to the
     * first node of the linked list
    */

    shared_ptr<Item> current = first;

    /**
     * Travesre through the linked list and print the data each node holds 
    */

    current = first;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    /**
     * Print empty line to formating out put 
    */
    cout<<"\n";

    /**
     * Travesre thorough the linked list and set all the valuses to first->data
    */
   current = first;
    while (current != nullptr) {
        current->data = first->data;
        current = current->next;
    }

    /**
     * Travesre through the linked list and print the data each node holds 
    */
    current = first;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    /**
     * Print empty line to formating out put 
    */
   cout<<"\n";

    /**
     * Creating new pointer call New
    */
    shared_ptr<Item> New = make_shared<Item>(40);
    
    /**
     * Travers to the end of the linked list and New node
    */
    current = first;
    while (current->next != nullptr) {
        current = current->next;
    }

    /**
     * Now current is pointing to the last node, adding New as the last node
     * to the list
    */
    current->next = New;

    /**
     * Travesre through the linked list and print the data each node holds 
    */
   current = first;
   while (current != nullptr) {
       cout << current->data << " ";
       current = current->next;
   }

   /**
    * Print empty line to formating out put 
   */
  cout<<"\n";

    return 0;
}