#include <stdlib.h>

using namespace std;

void Recursion() {
	int num;
	cin >> "Enter a number: " >> num;
	if (num == 0) return;
	Recursion();
	if (num > 0) cout << num << " " << endl;
}
int main() {
	cout >> "Task 1: \n";
	Recursion();
}