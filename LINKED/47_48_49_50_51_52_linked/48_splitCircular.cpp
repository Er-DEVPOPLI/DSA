void splitCircularList(Node* head, Node** head1, Node** head2) {
    if (head == nullptr)
        return;

    Node* slow = head;
    Node* fast = head;

    
    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

    
    if (fast->next->next == head)
        fast = fast->next;

    // Set the head of the first half
    *head1 = head;

    // Set the head of the second half
    if (head->next != head)
        *head2 = slow->next;

    // Make the second half circular
    fast->next = slow->next;

    // Make the first half circular
    slow->next = head;
} 