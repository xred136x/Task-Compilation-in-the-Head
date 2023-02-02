#include <iostream>
#include <vector>
class A {
public:
	virtual void foo(std::vector<int>& vec) = 0; 	
	
	//virtual~A(){} утечка памяти
};
class B : public A {
public:
	void foo(std::vector<int>& vec) override {// если убрать &, то в main, при вызове функции выведетутся три элемента
		std::cout << "foo function" << std::endl;
		vec.erase(vec.begin());
	}
};
int main() {
	A* b = new B();
	std::vector<int> v = { 1,2,3 };
	b->foo(v);// останесся 2,3 ,т.к begin() указатель на первый(нулевой) элемент вектора, а вектор передается по ссылке
	
	//delete b; утечка памяти
}
