#include <iostream>
#include <queue>


struct node { // 현재의 정보를 담고 있는 노드 자체 // 가지가 두개
    std::string position; // 직급
    node* first; // 두가지 중 첫번째
    node* second; // 두가지 중 두번째
};

struct org_tree { // organize -> 조직도 트리
    node* root; // 가장 기본이 되는 루트 노드 선언 아마 CEO

    static org_tree create_org_structure(const std::string& pos)
    {
        org_tree tree;
        tree.root = new node{ pos,NULL,NULL }; // 초기화
        return tree; // 반환
    }

    static node* find(node* root, const std::string& value) // 해당 노드의 포인터를 반환하는 찾기 함수 // 루트와 해당 정보값 입력
    {
        if (root == NULL) //루트가 없다면 null리턴
        {
            return NULL;
        }
        if (root->position == value) // 일치한다면 반환
            return root;

        auto firstFound = org_tree::find(root->first, value); // 재귀함수로 다시 탐색
        if (firstFound != NULL)
            return firstFound;

        return org_tree::find(root->second, value);
    }

    bool addSubordinate(const std::string& manager, const std::string& subordinate)
    {
        auto managerNode = org_tree::find(root, manager);

        if (!managerNode)
        {
            std::cout << manager << "을(를) 찾을 수 없습니다 : " << std::endl;

            return false;
        }

        if (managerNode->first && managerNode->second)
        {
            std::cout << manager << " 아래에 " << subordinate << "을(를)  추가할 수 없습니다." << std::endl;
            return false;
        }

        if (!managerNode->first)
            managerNode->first = new node{ subordinate,NULL,NULL };
        else
            managerNode->second = new node{ subordinate,NULL,NULL };


        std::cout << manager << " 아래에 " << subordinate << "을(를) 추가했습니다." << std::endl;

        return true;
    }       

    static void preOrder(node* start) { // 전위 순회
        if (!start)
        {
            return;
        }

        std::cout << start->position << ", ";

        preOrder(start->first);
        preOrder(start->second);
    }

    static void inOrder(node* start) // 중위 순회
    {
        if (!start)
        {
            return;
        }

        inOrder(start->first);
        std::cout << start->position << ", ";
        inOrder(start->second);
    }

    static void postOrder(node* start)
    {
        if (!start)
        {
            return;
        }
        postOrder(start->first);
        postOrder(start->second);
        std::cout << start->position << ", ";
    }

    static void levelOrder(node* start)
    {
        if (!start)
            return;

        std::queue<node*> q; // 프론트롤 들어와서 리어로 나가는 선형 자료구조
        q.push(start); // 프론트에 시작 노드 삽입

        while (!q.empty()) // 값이 비어 있으면 참 , 비어 있지 않으면 거짓 
        {
            // 값이 들어 있다면
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto current = q.front();
                q.pop();

                std::cout << current->position << ", ";
                if (current->first)
                    q.push(current->first);
                if (current->second)
                    q.push(current->second);
            }   
            std::cout << std::endl;
        }
    }

};


int main()
{
    auto tree = org_tree::create_org_structure("CEO");

    tree.addSubordinate("CEO", "부사장");
    tree.addSubordinate("부사장", "IT부장");
    tree.addSubordinate("부사장", "마케팅부장");
    tree.addSubordinate("IT부장", "보안팀장");
    tree.addSubordinate("IT부장", "앱개발팀장");
    tree.addSubordinate("마케팅부장", "물류팀장");
    tree.addSubordinate("마케팅부장", "홍보팀장");
    tree.addSubordinate("부사장", "재무팀장");
    std::cout << "\n" << std::endl;

    org_tree::preOrder(tree.root);
    std::cout << "\n"<<std::endl;
    org_tree::inOrder(tree.root);
    std::cout << "\n" << std::endl;
    org_tree::postOrder(tree.root);
    std::cout << "\n" << std::endl;
    org_tree::levelOrder(tree.root);

}
