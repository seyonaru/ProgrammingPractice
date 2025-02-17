#include <iostream>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <conio.h>

using namespace std;

//lab1
void Easter(int year) {
    int a = year % 19;
    int b = year % 4;
    int c = year % 7;
    int d = (19 * a + 15) % 30;
    int e = (2 * b + 4 * c + 6 * d + 6) % 7;
    int f = d + e;

    if (f <= 26) cout << "Easter will be at " << f + 4 << "'th of April";
    else cout << "Easter will be at " << f - 26 << "'th of May";

    //Масленица
    if ((f - 57 >= -56) && (f - 57 <= -31)) cout << "\n Масленица будет " << f + 8 << " февраля";
    else cout << "\n Масленица будет " << f - 20 << " марта";
}
void power(double x, int n) {
    double y = x;
    if (n > 0) {
        for (int i = 0; i < n - 1; i++) {
            y *= x;
        }
    }
    else {
        n *= -1;
        double temp = x;
        for (int i = 0; i < n - 1; i++) {
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

    vector<int> Array = { 2,3,7,-11, 6, -5, 6, -1, 4 };
    const int N = 0;
    bool isNegative = true;
    cout << "\nTask 2: ";
    RecursionSorting(Array, N, isNegative);

    int A = 5;
    vector<int> ans;
    cout << "\nTask 3: ";
    TransitionToBinary(A, ans);
}

//lab3
int usingMalloc() {
    int i;
    int n;
    int* b;
    int* c; //positive
    int* d; //negative

    cout << "Size of massive -> ";
    cin >> n;
    cout << "\n";

    b = (int*)malloc(n * sizeof(int));

    if (b == NULL) {
        cout << "Error in resizing storage";
        return 1;
    }

    for (i = 0; i < n; i++) {
        b[i] = rand() % 1000 / 1000. + rand() % 2000 - 1000;
    }

    int cntN = 0; //negative count
    int cntP = 0; //positive count

    for (i = 0; i < n; i++) {
        if (b[i] < 0) cntN++;
        else cntP++;
    }

    c = (int*)malloc(cntP * sizeof(int));
    d = (int*)malloc(cntN * sizeof(int));
    int tempN = 0;
    int tempP = 0;
    for (i = 0; i < n; i++) {
        if (b[i] < 0) {
            d[tempN] = b[i];
            tempN++;
        }
        else {
            c[tempP] = b[i];
            tempP++;
        }
    }

    cout << "main massive: [ ";
    for (i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << "], Length of massive: "<< n << endl;

    cout << "massive with positive numbers: [ ";
    for (i = 0; i < cntP; i++) {
        cout << c[i] << " ";
    }
    cout << "], Length of massive: " << cntP << endl;

    cout << "massive with negative numbers: [ ";
    for (i = 0; i < cntN; i++) {
        cout << d[i] << " ";
    }
    cout << "], Length of massive: " << cntN << endl;

    free(b);
    free(c);
    free(d);
    return 0;
}
int usingNew() {
    int i;
    int n;
    float* a;//massive of numbers 
    float* b;//massive of pointers

    cout << "Size of massive -> ";
    cin >> n;
    cout << "\n";

    a = new float[n];
    b = new float[n];

    if (a == NULL || b == NULL) {
        cout << "Error in resizing storage";
        return 1;
    }

    for (i = 0; i < n; i++) {
        a[i] = rand() % 1000 / 1000. + rand() % 2000 - 1000;
    }

    for (i = 0; i < n; i++) {
        b[i] = *(a + i);
    }
    int minId;
    for (int i = 0; i < n - 1; i++) {
        minId = i;
        for (int j = i + 1; j < n; j++) {
            if (b[j] < b[minId]) minId = j;
        }
        if (minId != i) {
            swap(b[minId], b[i]);
        }
    }
    cout << "main massive: [ ";
    for (i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "]" << endl;

    cout << "massive of sorted pointers: [ ";
    for (i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << "]" << endl;
    return 0;
}
int Eratosphene() {
    int n;
    int p = 2;
    int* prime;

    cout << "N -> ";
    cin >> n;
    cout << "\n";

    prime = new int[n + 1];

    if (prime == NULL) {
        cout << "Error in resizing storage";
        return 1;
    }

    for (int i = 0; i < n + 1; i++) {
        prime[i] = i;
    }

    for (p = 2; p <= n; p++) {
        for (int j = p * p; j < n + 1; j += p) {
            prime[j] = 0;
        }
    }

    cout << "massive of prime numbers: [ ";
    for (int i = 0; i < n; i++) {
        if (prime[i] == 0) continue;
        cout << prime[i] << " ";
    }
    cout << "]" << endl;


    return 0;
}
void lab3() {
    usingMalloc();
    usingNew();
    Eratosphene();
}

int main()
{
    srand(0);
    //lab1();
    //lab2();
    lab3();
}
