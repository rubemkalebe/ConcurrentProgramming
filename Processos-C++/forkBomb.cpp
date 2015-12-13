/*
 * ulimit -u => 29848
 */
#include <iostream>
#include <unistd.h>

int main() {

	int max = -1;

	while(true) {
		int x = fork();
		std::cout << x << std::endl;
		if(x > max) {
			max = x;
			std::cout << "MAX: " << max << std::endl;
		}
	}

	return 0;
}