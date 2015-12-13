#include <iostream>
#include <unistd.h>
#include <signal.h>

using namespace std;

void tratadorDeSinais(int sinal) {
	cout << "Recebi um sinal #" << sinal << endl;
}

int main() {
	signal(10, tratadorDeSinais);

	while(1) {
		cout << "Primeiro cout" << endl;
		sleep(1);
		cout << "Segundo cout" << endl;
		sleep(1);
		cout << "Terceiro cout" << endl;
		sleep(1);
	}
}
