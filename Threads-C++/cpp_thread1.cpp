// Compile with: g++ ... -std=c++11 -pthread

#include <iostream>
#include <thread>

int foo() {
	std::cout << "Foo thread\n";
}

void bar(int x, int y) {
	std::cout << "Bar thread, x = " << x << std::endl;
}

int main() {

	std::thread task1(foo);
	std::thread task2(bar, 5, 2);

	std::cout << "main, foo and bar now execute concurrently...\n";

	// synchronize threads:
	task1.join();                // pauses until first finishes
	task2.join();               // pauses until second finishes

	std::cout << "foo and bar completed.\nNow I'll finish\n";

	return 0;
}
