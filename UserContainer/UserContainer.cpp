
#include <iostream>
#include <algorithm>

using namespace std;

struct singly_ll_node
{
    int data; // 단순한 데이터를 담을 곳
    singly_ll_node* next; // 다음에 올 구조체의 주소를 담을 곳 -> 같은 형태
};


class singly_ll
{
public:
    using node = singly_ll_node; // modern cpp에서는 typedef 대신 using을 사용해서 type alias를 지정할 수 있다. singly_ll_node 타입의 새로운 별명
    using node_ptr = node*; // singly_ll_node의 주소를 담는 변수로 선언

private:
    node_ptr head; // 헤드로 사용 //head는 구조체의 주소를 담고 있다


public:
    void push_front(int val)
    {
        auto new_node = new node{ val,NULL }; // 구조체 초기화 후 카피한 새로운 노드 생성 
        if (head != NULL) // 현재 노드의 주소를 담고 있는 헤드-> 현재 헤드에 값이 있다면 -> 처음에는 NULL
            new_node->next = head; // 새로 생성한 노드의 next 포인터에 값을 할당 -> push_back이라면 반대로 한다.

        head = new_node; // head는 포인터임
    }

    void push_back(int val)
    {
        auto new_node = new node{ val,NULL }; //구조체 참조를 반환한다.
        if (head != NULL)
        {
            head->next = new_node;
        }
    }

    void pop_front()
    {
        auto first = head; 
        if (head) //-> 헤드가 있다면
            head = head->next; // 헤드 다음에 있는 주소 정보 즉 다음 노드를 head에 할당
        delete first; // 메모리 동적 사용 가능하게 하는 delete -> 해당 주소의 메모리 삭제
    }

    void pop_back()
    {
        while (this->head->next != NULL)
        {
            this->head = this->head->next;
        }

        delete this->head;//마지막 노드를 삭제해 준다. -> 노드를 그냥 끊어버리면 되는데..일단..
    }

    struct singly_ll_iterator { //내부의 반복자를 구현


    private:
        node_ptr ptr; // 구조체 객체

    public:
        singly_ll_iterator(node_ptr p) : ptr(p) {}; // 생성자 구조체를 인수로 받고 그 인수를 내부 변수에 주입

        int& operator*() { return ptr->data; } //참조를 반환 // 연산자 오버로딩 참조값을 반환함 

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
            return left.ptr == right.ptr;
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
            head = new node{ 0,NULL };
            auto cur = head;
            auto it = other.begin();
            while (true)
            {
                cur->data = *it;
                
                auto tmp = it;
                ++tmp;
                if (tmp == other.end())
                    break;

                cur->next = new node{ 0,NULL };
                cur = cur->next;
                it = tmp;
            }
        }
    }

    singly_ll(const initializer_list<int>& ilist) : head(NULL) 
    {
        for (auto it = rbegin(ilist); it != rend(ilist) ; it++)
        {
            push_front(*it);
        }
    }
};



int main()
{
    singly_ll sll = { 1,2,3 };
    sll.push_front(0);

    cout << "첫 번째 리스트 : ";
    for (auto i : sll)
        cout << i << " ";

    cout << endl;

    auto sll2 = sll;

    sll2.push_front(-1);
    cout << "첫 번째 리스트를 복사한 후, 맨 앞에 -1을 추가 : ";
    for (auto i : sll2)
        cout << i << ' ';

    cout << endl;

    cout << "깊은 복사 후 첫 번째 리스트 : ";

    for (auto i : sll)
        cout << i << ' ';

    cout << endl;
       
}
