#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

//lab1
void Easter(int year) {
    int a = year % 19;
    int b = year % 4;
    int c = year % 7;
    int d = (19 * a + 15) % 30;
    int e = (2 * b + 4 * c + 6 * d + 6) % 7;
    int f = d + e;

    if (f <= 26) cout << "Easter will be at "<< f + 4 << "'th of April";
    else cout << "Easter will be at "<<f - 26 << "'th of May";

    //Масленица
    if ((f - 57 >= -56) && (f - 57 <= -31)) cout << "\n Масленица будет " << f + 8 << " февраля";
    else cout << "\n Масленица будет " << f - 20 << " марта";
}

void power(double x, int n) {
    double y = x;
    if (n > 0) {
        for (int i = 0; i < n-1; i++) {
            y *= x;
        }
    }
    else {
        n *= -1;
        double temp = x;
        for (int i = 0; i < n-1; i++) {
            temp *= x;
        }
        y = 1 / temp;
    }

    cout << y;
}

void lab1() {
    //for task 1 
    int year = 2025;

    //for task 2
    int n1 = 9;
    int n2 = -4;
    double x = 1.2;

    //results
    cout << "Task 1: ";
    Easter(year);
    cout << "\nTask 2: Incoming numbers:\n Variant 1: n = " << n1 << ", x =" << x << " result: ";
    power(x, n1);
    cout << "\n Variant 1: n = " << n2 << ", x =" << x << " result: ";
    power(x, n2);
}

//lab2
void Recursion() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if (num == 0) return;
    Recursion();
    if (num > 0) cout << num << " " << endl;
}
void RecursionSorting(vector<int>& Array, int index = 0, bool isNegative = true) {
    if (index == Array.size()) {
        if (isNegative) {
            RecursionSorting(Array, 0, false);
        }
        return;
    }
    if ((isNegative && Array[index] < 0) || (!isNegative && Array[index] > 0)) {
        std::cout << Array[index] << " ";
    }
    RecursionSorting(Array, index + 1, isNegative);
}

void TransitionToBinary(int N, std::vector<int>& ans) {
    if (N == 0) {
        if (ans.empty()) {
            ans.push_back(0);
        }
        return;
    }

    if (N > 0) {
        TransitionToBinary(N / 2, ans);
        ans.push_back(N % 2);
    }
    for (int i = 0; i < ans.size(); i++) {
        if (i == 0 || i == ans.size()) {
            ans.erase(ans.begin() + i);
        }
        cout << ans[i];
    }
}

void lab2() {
    cout << "Task 1: ";
    Recursion();

    vector<int> Array = {2,3,7,-11, 6, -5, 6, -1, 4};
    const int N = 0;
    bool isNegative = true;
    cout << "\nTask 2: ";
    RecursionSorting(Array, N, isNegative);

    int A = 5;
    vector<int> ans;
    cout << "\nTask 3: ";
    TransitionToBinary(A, ans);
}
int main()
{
    /*
    //for task 1 
    int year = 2021;
    
    //for task 2
    int n1 = 9;
    int n2 = -4;
    double x = 1.2;

    //results
    cout << "Task 1: ";
    Easter(year);
    cout << "\nTask 2: Incoming numbers:\n Variant 1: n = " << n1 <<", x =" << x << " result: ";
    power(x, n1);
    cout << "\n Variant 1: n = " << n2 << ", x =" << x << " result: ";
    power(x, n2);
    */

    //lab1();
    lab2();
}
