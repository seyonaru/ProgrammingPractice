#include <iostream>
#include <math.h>
#include <vector>
#include <stdlib.h>

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

    if (c == NULL || d == NULL) {
            cout << "Error in resizing storage";
            return 1;
        }

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
    cout << "], Length of massive: "<< n << endl << "\n";

    cout << "massive with positive numbers: [ ";
    for (i = 0; i < cntP; i++) {
        cout << c[i] << " ";
    }
    cout << "], Length of massive: " << cntP << endl << "\n";

    cout << "massive with negative numbers: [ ";
    for (i = 0; i < cntN; i++) {
        cout << d[i] << " ";
    }
    cout << "], Length of massive: " << cntN << endl << "\n";

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
    cout << "]" << endl << "\n";

    cout << "massive of sorted pointers: [ ";
    for (i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << "]" << endl << "\n";

    delete a;
    delete b;
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
    cout << "]" << endl << "\n";

    delete prime;
    return 0;
}
void lab3() {
    cout << "Task 1: " << endl;
    usingMalloc();
    cout << "Task 2: " << endl;
    usingNew();
    cout << "Task 3: " << endl;
    Eratosphene();
}

//lab4 
// ↓ calling RAM for matrix
int** matrixRAM(int rows, int cols) {
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}
// ↓ freeing RAM from matrix
void matrixFreedom(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
// ↓ filling matrix 
void matrixFilling(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}
// ↓ printing matrix 
void matrixPrinting(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
//        task1
int RandomBinaryMassive() {
    int m;
    int n = 5;

    cout << "M -> ";
    cin >> m;

    int** b = matrixRAM(m, n);
    if (!b) {
        cout << "Error in resizing RAM";
        return 1;
    }
    
    matrixFilling(b, m, n);

    cout << "Original matrix b: " << endl;
    matrixPrinting(b, m, n);

    int maxVal = b[0][0];
    int maxRow = 0;
    int maxCol = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (b[i][j] > maxVal) {
                maxVal = b[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }

    int** c = matrixRAM(m - 1, n - 1);
    for (int i = 0, ci = 0; i < m; i++) {
        if (i == maxRow) continue;
        for (int j = 0, cj = 0; j < n; j++) {
            if (j == maxCol) continue;
            c[ci][cj++] = b[i][j];
        }
        ci++;
    }

    cout << "modificated matrix c: " << endl;
    matrixPrinting(c, m - 1, n - 1);

    matrixFreedom(b, m);
    matrixFreedom(c, m - 1);

    return 0;
}
//        task2
int ExpandedMatrix() {
    int m;
    int n;

    cout << "M -> ";
    cin >> m;
    cout << endl << "N -> ";
    cin >> n;
    cout << endl;

    int** a = matrixRAM(m, n);
    if (!a) {
        cout << "Error in resizing RAM" << endl;
        return 1;
    }

    matrixFilling(a, m, n);;

    int** d = matrixRAM(m + 1, n + 1);
    if (!d) {
        cout << "Error in resizing RAM" << endl;
        return 1;
    }
    
    int sumTotal = 0;

    for (int i = 0; i < m; i++) {
        int sumRow = 0;
        for (int j = 0; j < n; j++) {
            d[i][j] = a[i][j];
            sumRow += a[i][j];
        }
        d[i][n] = sumRow;
        sumTotal += sumRow;
    }

    for (int j = 0; j < n; j++) {
        int sumCol = 0;
        for (int i = 0; i < m; i++) {
            sumCol += a[i][j];
        }
        d[m][j] = sumCol;
        sumTotal += sumCol;
    }

    d[m][n] = sumTotal;

    cout << "Expanded matrix d: " << endl;
    matrixPrinting(d, m + 1, n + 1);

    matrixFreedom(a, m);
    matrixFreedom(d, m + 1);
    return 0;
}
void lab4() {
    cout << "Task 1: " << endl;
    RandomBinaryMassive();
    cout << "Task 2: " << endl;
    ExpandedMatrix();
}

//lab5
int GeneraeNewMassiveFromAnother() {
    int m;
    int k;

    cout << "M -> ";
    cin >> m;
    cout << endl << "K (K < M) -> ";
    cin >> k;
    cout << endl;

    int* a = new int[m];
    if (!a) {
        cout << "Error in resizing RAM";
        return 1;
    }
    for (int i = 0; i < m; i++) {
        a[i] = rand() % 100;
    }

    cout << "Massive A: " << endl;
    for (int i = 0; i < m; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;

    int rows = (m + k - 1) / k;
    int** b = matrixRAM(rows, k);

    if (!b) {
        cout << "Error in resizing RAM";
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < k; j++) {
            int id = i * k + j;
            b[i][j] = (id < m) ? a[id] : 0;
        }
    }

    cout << "Matrix b: " << endl;
    matrixPrinting(b, rows, k);

    delete a;
    matrixFreedom(b, rows);

    return 0;
}
int AscendingMultiplicationTable() {
    int rows = 9;
    int cols = 1;

    int** matr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matr[i] = new int[cols];
        cols++;
    }

    if (!matr) {
        cout << "Error in resizing RAM";
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= i; j++){
            matr[i][j] = (i + 1) * (j + 1);
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= i; j++) {
            cout << matr[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete matr[i];
    }
    delete matr;

    return 0;
}
void lab5() {
    cout << "Task 1: " << endl;
    GeneraeNewMassiveFromAnother();
    cout << "Task 2: " << endl;
    AscendingMultiplicationTable();
}

//lab6
bool ExistanceOfTrianlge(int& a, int& b, int& c) {
    bool ex = true;
    if ((a + b <= c || a + c <= b || b + c <= a) || (a<0 || b<0 || c<0)) {
        ex = false;
    }
    return ex;
}
int Perimeter(int& a, int& b, int& c) {
    return a + b + c;
}
int TriangleSquare(int& a, int& b, int& c) {
    bool ex = ExistanceOfTrianlge(a, b, c);
    if (ex == false) return 1;
    else {
        int p = a + b + c;
        int temp = p * (p - a) * (p - b) * (p - c);
        int s = pow(temp, 0.5);
        return s;
    }
}
//task1
void task1() {
    int a;
    int b;
    int c;
    cout << "Write leght of sides of triangle: \n a: ";
    cin >> a;
    cout << "\n b: ";
    cin >> b;
    cout << "\n c: ";
    cin >> c;
    cout << endl;

    cout << "Perimeter of triangle: " << Perimeter(a, b, c) << ", square: " << TriangleSquare(a, b, c);
}
//task2
int fact(int& n) {
    int f = 1;
    for (int i = 1; i <= n; i++) f *= i;
    return f;
}
double c(int& n, int& m) {
    int fn = fact(n);
    int fm = fact(m);
    int temp = n - m;
    int ftemp = fact(temp);
    return fn / (fm * ftemp);
}
void task2() {
    int n;
    int m;
    cout << "Write amout of children: ";
    cin >> n;
    cout << "\nWrite amount of boys OR girls: ";
    cin >> m;

    float p = 0.45;
    float q = 1 - p;
    float pd = c(n, m) * pow(p, m) * pow(q,n - m);
    float pm = c(n, m) * pow(q, m) * pow(p, n - m);

    cout << "\nChance for girls: " << pd << ", chance for boys: " << pm;
}
void lab6() {
    cout << "Task 1: \n";
    task1();
    cout << "\nTask 2: \n";
    task2();
}

//lab8
//task1
struct school
{
    int number;
    int finished;
    int applied;
    double percent;

    void print()
    {
        cout << "Number of school: " << number
            << ", students finished school: " << finished
            << ", students applied to university: " << applied
            << ", percentage of appliance: " << percent << " \n";
    }
    void fill()
    {
        number = rand() % 1000;
        finished = rand() % 250;
        applied = rand() % (finished + 1);
    }
    void appliedpercent()
    {
        float temp = (float)finished / 100;
        percent = applied / temp;
    }
};

void Task1() {
    struct school Univ[10];
    for (int i = 0; i < 10; i++) {
        Univ[i].fill();
    }

    for (int i = 0; i < 10; i++) {
        Univ[i].appliedpercent();
    }

    vector<int> ind = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int i; // index for iteration
    int j; // index for right element in current pair
    for (i = 0; i < 10 - 1; i++) {
        for (j = 10 - 1; j > i; j--) {
            if (Univ[ind[j]].percent > Univ[ind[j - 1]].percent) {
                swap(ind[j], ind[j - 1]);
            }
        }
    }

    cout << endl;
    for (int i = 0; i < 10; i++) {
        Univ[ind[i]].print();
    }
    cout << "Index array (after swapping elements): ";
    for (int i : ind) cout << i << "\t";
}

//task2 
struct room {
    int number;
    int square;
    string degree;
    int living;

    void print() {
        cout << "Room number: " << number
            << ", \troom square: " << square
            << ", \troom degree: " << degree
            << ", \tnumber of living people: " << living
            << "\n";
    }

    void filling(int number, int square, string degree, int living) {
        this->number = number;
        this->square = square;
        this->degree = degree;
        this->living = living;
    }
};

void Task2() {
    struct room dorm[10];
    string List[] = { "programming", "engineering", "cybersecurity" };
    for (int i = 0; i < 10; i++) {
        dorm[i].filling(rand() % 100, rand() % 50, List[rand() % 3], rand() % 10);
    }

    for (int i = 0; i < 10; i++) {
        dorm[i].print();
    }

    double cnt_p = 0, cnt_ps = 0, cnt_pq = 0;
    double cnt_e = 0, cnt_es = 0, cnt_eq = 0;
    double cnt_c = 0, cnt_cs = 0, cnt_cq = 0;
    double apr_pq = 0, apr_eq = 0, apr_cq = 0;
    for (int i = 0; i < 10; i++) {
        if (dorm[i].degree == List[0]) {
            cnt_p++;
            cnt_ps += dorm[i].living;
            cnt_pq += dorm[i].square;
        }
        if (dorm[i].degree == List[1]) {
            cnt_e++;
            cnt_es += dorm[i].living;
            cnt_eq += dorm[i].square;
        }
        if (dorm[i].degree == List[2]) {
            cnt_c++;
            cnt_cs += dorm[i].living;
            cnt_cq += dorm[i].square;
        }
    }

    apr_pq = cnt_pq / cnt_ps;
    apr_eq = cnt_eq / cnt_es;
    apr_cq = cnt_cq / cnt_cs;
    cout << "\n Degree:" << List[0]
        << ", \t amount of rooms: " << cnt_p
        << ", \t amount of students: " << cnt_ps
        << ", \t approximate square per student: " << apr_pq
        <<"\n";
    cout << "\n Degree:" << List[1]
        << ", \t amount of rooms: " << cnt_e
        << ", \t amount of students: " << cnt_es
        << ", \t approximate square per student: " << apr_eq
        << "\n";
    cout << "\n Degree:" << List[2]
        << ", \t amount of rooms: " << cnt_c
        << ", \t amount of students: " << cnt_cs
        << ", \t approximate square per student: " << apr_cq
        << "\n";
}
void lab8() {
    cout << "Task 1: \n";
    Task1();

    cout << "\nTask 2: \n";
    Task2();
}

int main()
{
    srand(0);
    //lab1();
    //lab2();
    //lab3();
    //lab4();
    //lab5();
    //lab6();
    lab8();
}
