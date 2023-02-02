#include <iostream>
#include <vector>
class A {
public:
	virtual void foo(std::vector<int>& vec) = 0; 	
	
	//virtual~A(){} ������ ������
};
class B : public A {
public:
	void foo(std::vector<int>& vec) override {// ���� ������ &, �� � main, ��� ������ ������� ����������� ��� ��������
		std::cout << "foo function" << std::endl;
		vec.erase(vec.begin());
	}
};
int main() {
	A* b = new B();
	std::vector<int> v = { 1,2,3 };
	b->foo(v);// ��������� 2,3 ,�.� begin() ��������� �� ������(�������) ������� �������, � ������ ���������� �� ������
	
	//delete b; ������ ������
}
