#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    {
        this->head = NULL;
        this->tail = NULL;
    }
    void delete_at_tail()
    {
        if (!head)
        {
            cout << "List is empty!\n";
        }
        else if (!head->next)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            cout << "The only element present in the list has been deleted!\n";
        }
        else
        {
            Node *current = head;
            while (current->next->next)
            {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
            tail = current;
            cout << "Last element has been deleted!\n";
        }
    }

    void delete_at_head()
    {
        if (!head)
        {
            cout << "List is empty!" << endl;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
            cout << "First element has been deleted!" << endl;
        }
    }
    void insertAtHead(int val)
    {
        Node *temp = new Node(val);
        if (!head)
        {
            head = temp;
            tail = temp;
            cout << val << " has been added (first)!\n";
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
            cout << val << " has been added O(1)!\n";
        }
    }
    void addat_tail(int val)
    {
        Node *temp = new Node(val);
        if (!head)
        {
            head = temp;
            tail = temp;
            cout << val << " has been added (first)!\n";
        }
        else
        {
            Node *current = head;
            tail->next = temp;
            tail = temp;
            cout << val << " has been added O(1)!\n";
        }
    }

    void add_after(int val, int data)
    {
        if (tail->data == val)
        {
            addat_tail(data);
            return;
        }
        Node *temp = new Node(data);
        bool isFound = false;
        for (Node *current = head; current->next; current = current->next, current->prev = current)
        {
            if (current->data == val)
            {
                isFound = true;
                temp->next = current->next;
                temp->prev = current;
                current->next->prev = temp;
                current->next = temp;

                cout << "Added " << data << " after " << val << endl;
            }
        }
        if (!isFound)
        {
            cout << "Value not found after which " << data << " will be added!\n";
        }
    }
    void delete_val(int val)
    {
        bool isFound = false;
        if (!head)
        {
            cout << "List is Empty!\n";
            return;
        }
        else if (!head->next)
        {
            if (head->data == val)
            {
                delete_at_head();
                cout << val << " deleted!\n";
                isFound = true;
                return;
            }
        }
        else if (tail->data == val)
        {
            delete_at_tail();
            cout << val << " deleted!\n";
            return;
        }
        else
        {
            for (Node *current = head; current->next; current = current->next, current->prev = current)
            {
                if (current->next->data == val)
                {
                    isFound = true;
                    Node *todelete = current->next;

                    // Check if current->next->next exists before updating its prev pointer
                    if (current->next->next)
                    {
                        current->next->next->prev = current;
                    }

                    current->next = current->next->next;

                    delete todelete;
                    cout << "Value " << val << " deleted!\n";
                }
            }
        }
        if (!isFound)
        {
            cout << val << " is not found in the list and cannot be deleted!\n";
        }
    }
    void selection_sort()
    {
        Node *current = head;
        for (; current; current = current->next)
        {
            Node *minNode = current;

            for (Node *temp = current->next; temp; temp = temp->next)
            {
                if (temp->data < minNode->data)
                { // Use < for ascending order
                    minNode = temp;
                }
            }

            // Swap the data of current and minNode
            int temp = minNode->data;
            minNode->data = current->data;
            current->data = temp;
        }
    }
    void insertion_sort()
    {
        if (!head || !head->next)
        {
            return; // List is empty or has only one element, it's already sorted.
        }

        Node *sorted = nullptr;
        Node *current = head;

        while (current)
        {
            Node *next = current->next;

            if (!sorted || current->data < sorted->data)
            {
                // Insert at the beginning of the sorted list
                current->next = sorted;
                current->prev = nullptr;
                sorted = current;
            }
            else
            {
                // Find the correct position in the sorted list
                Node *temp = sorted;

                while (temp->next && current->data > temp->next->data)
                {
                    temp = temp->next;
                }

                // Insert the current node after temp
                current->next = temp->next;
                current->prev = temp;

                if (temp->next)
                {
                    temp->next->prev = current;
                }

                temp->next = current;
            }

            current = next;
        }

        head = sorted; // Update the head to the sorted list
    }
    void display()
    {
        if (!head)
        {
            cout << "List is empty!" << endl;
            return;
        }
        Node *current = head;
        while (current)
        {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
    void sort()
    {
        Node *current = head;
        Node *index = NULL;
        int temp;
        if (!head)
        {
            cout << "The Linked list is empty!!\n";
        }
        else
        {
            while (current)
            {
                index = current;
                while (index->next)
                {
                    if (index->data > index->next->data)
                    {
                        temp = index->data;
                        index->data = index->next->data;
                        index->next->data = temp;
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
    }
};

int main()
{
    DoublyLinkedList D1;
    D1.addat_tail(1);
    D1.addat_tail(2);
    D1.addat_tail(3);
    D1.addat_tail(4);
    D1.addat_tail(5);
    D1.insertAtHead(342);
    D1.insertAtHead(41);
    D1.display();
    D1.delete_at_head();
    D1.delete_at_tail();
    D1.add_after(3, 69);
    D1.add_after(54, 22);
    D1.delete_val(3);
    D1.delete_val(1);
    D1.delete_val(2);
    D1.delete_val(4);
    D1.display();
    D1.delete_val(342);
    D1.add_after(69, 26);
    D1.delete_val(69);
    D1.delete_val(26);
    cout << "Before sorting:\n";
    D1.display();
    D1.insertion_sort();
    cout<<"After sorting:\n";
    D1.display();

    return 0;
}
