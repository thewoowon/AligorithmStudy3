#include <iostream>
#include <algorithm>

struct singly_ll_node {
    int data;
    singly_ll_node* next;
};

class singly_ll
{
public:
    using node = singly_ll_node;
    using node_ptr = node*;

private:
    node_ptr head;


public:
    void push_front(int val) {
        auto new_node = new node{ val,NULL };
        if (head != NULL)
            new_node->next = head;
        head = new_node;
    }   

    void pop_front()
    {
        auto first = head;
        if (head)
        {
            head = head->next;
            delete first;
        }
    }

    struct singly_ll_iterator
    {
    private:
        node_ptr ptr;

    public:
        singly_ll_iterator(node_ptr p) : ptr(p) {}

        int& operator*() { return ptr->data; }

        node_ptr get() { return ptr; }

        singly_ll_iterator& operator++() {
            ptr = ptr->next;
            return *this;
        }
        singly_ll_iterator operator++(int)
        {
            singly_ll_iterator result = *this;
            ++(*this);
            return result;
        }

        friend bool operator==(const singly_ll_iterator& left, const singly_ll_iterator& right)
        {
            return  left.ptr == right.ptr;
        }

        friend bool operator!=(const singly_ll_iterator& left, const singly_ll_iterator& right)
        {
            return left.ptr != right.ptr;
        }

    };

    singly_ll_iterator begin() { return singly_ll_iterator(head); }
    singly_ll_iterator end() { return singly_ll_iterator(NULL); }
    singly_ll_iterator begin() const { return singly_ll_iterator(head); }
    singly_ll_iterator end() const { return singly_ll_iterator(NULL); }

    singly_ll() = default;

    singly_ll(const singly_ll& other) : head(NULL)
    {
        if (other.head)
        {

        }
    }


};



int main()
{
    std::cout << "Hello World!\n";
}
