#include <iostream>

struct node {
	int data;
	node* left;
	node* right;
};

struct bst {
	node* root = nullptr; //널포인터

	node* find(int value) // 포인터를 반환하고 밸류를 입력받는 내부 메소드
	{
		return find_impl(root, value);
	}

private:
	node* find_impl(node* current, int value)
	{
		if (!current)
		{
			std::cout << std::endl;
			return NULL;
		}
		
		if (current->data == value)
		{
			std::cout << value << "을(를) 찾았습니다." << std::endl;
			return current;
		}

		if (value < current->data) // 왼쪽으로 진행
		{
			std::cout << current << "에서 왼쪽으로 이동 : ";
			return find_impl(current->left, value);
		}

		std::cout << current->data << "에서 오른쪽으로 이동 : ";
		return find_impl(current->right, value);
	}


public:
	void insert(int value)
	{
		if (!root)
		{
			root = new node{ value, NULL,NULL };
		}
		else
		{
			insert_impl(root, value);
		}
	}
private:
	void insert_impl(node* current, int value)
	{
		if (value < current->data) // 
		{
			if (!current->left)
				current->left = new node{ value,NULL,NULL };
			else
				insert_impl(current->left, value);
		}
		else
		{
			if (!current->right)
				current->right = new node{ value,NULL,NULL };
			else
				insert_impl(current->right, value);
		}
	}
public:
	void inorder()
	{
		inorder_impl(root);
	}

private:
	void inorder_impl(node* start) // 중위 순회
	{
		if (!start)
			return;
		inorder_impl(start->left);
		std::cout << start->data << " ";
		inorder_impl(start->right);
	}
public:
	node* successor(node* start)
	{
		auto current = start->right;
		while (current && current->left)
			current = current->left;
		return current;
	}
	void deleteValue(int value)
	{
		root = delete_impl(root, value);
	}

private:
	node* delete_impl(node* start, int value)
	{
		if (!start)
			return NULL;

		if (value < start->data)
			start->left = delete_impl(start->left, value);
		else if (value > start->data)
			start->right = delete_impl(start->right, value);
		else{
			if (!start->left)
			{
				auto tmp = start->right;
				delete start;
				return tmp;
			}

			if (!start->right)
			{
				auto tmp = start->right;
				delete start;
				return tmp;
			}

			auto succNode = successor(start);
			start->data = succNode->data;

			start->right = delete_impl(start->right, succNode->data);
		}
		return start;
	}
};