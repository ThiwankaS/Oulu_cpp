/**
 * @file list.cpp
 * Singly Linked List (lab_gdb).
 *
 * @author Chase Geigle
 * @date (created) Fall 2011
 * @date (modified) Spring 2012, Fall 2012
 *
 * @author Jack Toole
 * @date (modified) Fall 2011
 *
 * @author Veer Dedhia
 * @date (modified) Spring 2014
 *
 * @modified in Spring 2025 by Anna LaValle and Elmeri Uotila
 */

/**
 * @file list.cpp
 * Singly Linked List (lab_gdb).
 *
 * @brief Implementation of a singly linked list.
 */

/**
 * Destroys the current List. This function ensures that
 * memory does not leak on destruction of a list.
 */
template <class T>
List<T>::~List()
{
    clear();
}

/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <class T>
void List<T>::clear()
{
    // @todo Graded in lab_gdb
    ListNode *current = head, *next;
    while(current != nullptr)
    {
        next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    length = 0;
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertFront(T const & ndata)
{
    // @todo Graded in lab_gdb
    ListNode* newNode = new ListNode(ndata);
    newNode->next = head;
    head = newNode;
    length++;
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertBack(const T & ndata)
{
    // @todo Graded in lab_gdb
    ListNode * temp = head;

    if (temp == NULL)
    {
        head = new ListNode(ndata);
        length++;
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new ListNode(ndata);
        length++;
    }
}

/**
 * Reverses the current List.
 */
template <class T>
void List<T>::reverse()
{
    head = reverse(head, nullptr, length);
}

/**
 * Helper function to recursively reverse the entire sequence of
 * linked memory inside a List.
 *
 * @param curr The current node we are reversing
 * @param prev The node that should be placed before the current node in the
 * final reversed list
 * @param len The length of the remaining list to be reversed
 */
template <class T>
typename List<T>::ListNode* List<T>::reverse(ListNode* curr, ListNode* prev, int len)
{
    // @todo Graded in lab_gdb
    ListNode * temps;
    if (curr == nullptr)
    {
        return prev;
    }
    else
    {
        temps = curr->next;
        curr->next = prev;
        return reverse(temps, curr, len - 1);
    }
}

/**
 * Shuffles the current list by applying a perfect shuffle once. This entails
 * splitting the list in half, then interleaving the two halves.
 * For example:
 * start : < 1, 2, 3, 4, 5 >
 * split : < 1, 2, 3 >    < 4, 5 >
 * final : < 1, 4, 2, 5, 3 >
 */
template <class T>
void List<T>::shuffle()
{
    // @todo Graded in lab_gdb
    if (length < 2) return;
    int mid = (length + 1) / 2;
    ListNode* first = head;
    ListNode* second = head;
    for (int i = 0; i < mid - 1; i++)
        second = second->next;
    ListNode* second_half = second->next;
    second->next = NULL;
    ListNode* dummy = new ListNode();
    ListNode* curr = dummy;
    while (first || second_half) {
        if (first) {
            curr->next = first;
            curr = curr->next;
            first = first->next;
        }
        if (second_half) {
            curr->next = second_half;
            curr = curr->next;
            second_half = second_half->next;
        }
    }
    head = dummy->next;
    delete dummy;
}
