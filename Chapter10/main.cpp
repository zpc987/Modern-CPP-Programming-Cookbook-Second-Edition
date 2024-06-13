#include "recipe_10_01.h"
#include "recipe_10_02.h"
#include "recipe_10_03.h"
#include "recipe_10_04.h"
#include "recipe_10_05.h"
#include "recipe_10_06.h"
#include "recipe_10_07.h"

#include "iostream"
using namespace std;

void fun(const char*& n) {
	++n;
	++n;
}
int main()
{
	//int a = 10, b = 20;
	//auto f1 = [] {return a; }; // error
	//auto f2 = [&] {return a++; }; // ok
	//auto f3 = [=] {return a; }; // ok
	//auto f4 = [=] {return a++; }; // error
	//auto f5 = [a] {return a + b; }; // error
	//auto f6 = [a, &b] {return a + (b++); }; // ok
	//auto f7 = [=, &b] {return a + (b++); }; // ok

	std::string s{"thisdfadjihofdsafd"};

	const char* c = "5824395320";
	int num = 10;
	printf("1-%s\n", c);
	printf("%d\n",num);

	auto f = [=,&num, &c](const char* n) {
		n = c + 1;
		++c;
		num = 5;
		++n;
		++n;
	};
	auto fr = [&](const char* n) {
		n = c + 1;
		++c;
		num = 5;
		++n;
		++n;
	};
	auto fm = [=]  (const char* n) mutable {
		n = c + 1;
		++c;
		num = 5;
		++n;
		++n;
	};

	auto f1 = [](int n) {
		if (n > 0) {
			return true;
		}
		else {
			return false;
		}
	};

	//fun(s.c_str());
	if (f1(10)) {
		cout << "It is True" << endl;
	}
	fr(c);
	printf("2-%s\n", c);
	printf("%d\n", num);
	fun(c);
	
   recipe_10_01::execute();
   recipe_10_02::execute();
   recipe_10_03::execute();
   recipe_10_04::execute();
   recipe_10_05::execute();
   recipe_10_06::execute();
   recipe_10_07::execute();
}