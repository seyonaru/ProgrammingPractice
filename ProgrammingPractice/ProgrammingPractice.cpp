#include <iostream>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <Windows.h>
#include <limits>

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

//lab10
int lab10() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        cout << "Не удалось открыть файл input.txt\n";
        return 1;
    }

    vector<string> words;
    string line;

    while (getline(inputFile, line)) {
       stringstream ss(line);
        string word;

        while (ss >> word) {
            words.push_back(word);
        }
    }

    inputFile.close();

    sort(words.begin(), words.end());

    for (const string& word : words) {
        outputFile << word << "\n";
    }

    outputFile.close();

    cout << "Слова успешно отсортированы и записаны в output.txt\n";
    return 0;
}

//lab11
struct Passenger {
    string surname;
    string name;
    string secondName;
    int luggagePlace;
    double totalWeight;

    void print() {
        cout << surname << "\t"
            << name << "\t"
            << secondName << "\t"
            << luggagePlace << "\t\t"
            << totalWeight << "\n";
    }
};

void createFile(const string& filename, int N) {
    ofstream out(filename, ios::binary);
    if (!out) {
        cout << "Ошибка при создании файла\n";
        return;
    }

    for (int i = 0; i < N; i++) {
        Passenger p;
        cout << "Пассажир №" << i + 1 << " (введите через пробел: Фамилия Имя Отчество Кол-во_мест Вес):\n";

        cin.ignore(1000, '\n');

        string line;
        getline(cin, line);
        istringstream iss(line);
        vector<string> words;
        while (iss >> line) {
            words.push_back(line);
        }

        if (words.size() != 5) {
            cerr << "Неверный формат ввода. Попробуйте снова.\n";
            i--;
            continue;
        }

        p.surname = words[0];
        p.name = words[1];
        p.secondName = words[2];
        p.luggagePlace = stoi(words[3]);
        try {
            
            p.totalWeight = stod(words[4]);
        }
        catch (const invalid_argument& e) {
            cout << "Ошибка: введено не число для веса.\n";
            i--;
            continue;
        }
        catch (const out_of_range& e) {
            cout << "Ошибка: число веса вне диапазона.\n";
            i--;
            continue;
        }

        out.write(p.surname.c_str(), p.surname.size() + 1);
        out.write(p.name.c_str(), p.name.size() + 1);
        out.write(p.secondName.c_str(), p.secondName.size() + 1);
        out.write(reinterpret_cast<char*>(&p.luggagePlace), sizeof(p.luggagePlace));
        out.write(reinterpret_cast<char*>(&p.totalWeight), sizeof(p.totalWeight));
    }
    out.close();
}

void viewFile(const string& filename) {
    ifstream in(filename, ios::binary);
    if (!in) {
        cout << "Файл не найден.\n";
        return;
    }

    Passenger p;
    int n = 0;
    cout << "№\tФамилия\tИмя\tОтчество\tКол-во багажа\tОбщий вес\n";

    while (true) {
        getline(in, p.surname, '\0');
        if (in.eof()) 
            break;
        getline(in, p.name, '\0');
        getline(in, p.secondName, '\0');

        in.read(reinterpret_cast<char*>(&p.luggagePlace), sizeof(p.luggagePlace));
        in.read(reinterpret_cast<char*>(&p.totalWeight), sizeof(p.totalWeight));

        cout << ++n << "\t";
        p.print();
    }
    in.close();
}

void addRecord(const string& filename) {
    ofstream out(filename, ios::binary | ios::app);
    if (!out) {
        cout << "Ошибка при открытии файла.\n";
        return;
    }

    Passenger p;
    cout << "Введите данные нового пассажира (ФИО полностью, количество мест багажа, общий вес багажа): ";

    cin.ignore(1000, '\n');

    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<string> words;

    while (iss >> line) {
        words.push_back(line);
    }

    if (words.size() != 5) {
        cout << "Неверный формат ввода. Запись не добавлена.\n";
        return;
    }

    p.surname = words[0];
    p.name = words[1];
    p.secondName = words[2];

    try {
        p.luggagePlace = stoi(words[3]);
        p.totalWeight = stod(words[4]);
    }
    catch (const invalid_argument& e) {
        cout << "Ошибка: введены некорректные числа.\n";
        return;
    }
    catch (const out_of_range& e) {
        cout << "Ошибка: значение чисел вне диапазона.\n";
        return;
    }

    out.write(p.surname.c_str(), p.surname.size() + 1);
    out.write(p.name.c_str(), p.name.size() + 1);
    out.write(p.secondName.c_str(), p.secondName.size() + 1);
    out.write(reinterpret_cast<char*>(&p.luggagePlace), sizeof(p.luggagePlace));
    out.write(reinterpret_cast<char*>(&p.totalWeight), sizeof(p.totalWeight));
    out.close();
}

void deletePassenger(const string& filename, const double condition) {
    ifstream in(filename, ios::binary);
    ofstream temp("temp.dat", ios::binary);
    if (!in || !temp) {
        cout << "Ошибка при открытии файла.\n";
        return;
    }

    Passenger p;
    while (true) {
        getline(in, p.surname, '\0');
        if (in.eof()) 
            break;
        getline(in, p.name, '\0');
        getline(in, p.secondName, '\0');

        in.read(reinterpret_cast<char*>(&p.luggagePlace), sizeof(p.luggagePlace));
        in.read(reinterpret_cast<char*>(&p.totalWeight), sizeof(p.totalWeight));

        if (p.totalWeight >= condition) {
            temp.write(p.surname.c_str(), p.surname.size() + 1);
            temp.write(p.name.c_str(), p.name.size() + 1);
            temp.write(p.secondName.c_str(), p.secondName.size() + 1);
            temp.write(reinterpret_cast<char*>(&p.luggagePlace), sizeof(p.luggagePlace));
            temp.write(reinterpret_cast<char*>(&p.totalWeight), sizeof(p.totalWeight));
        }
    }

    in.close();
    temp.close();
    remove(filename.c_str());
    rename("temp.dat", filename.c_str());
}

void changeWeight(const string& filename, const string& surname) {
    fstream file(filename, ios::binary | ios::in | ios::out);
    if (!file) {
        cout << "Файл не найден.\n";
        return;
    }

    Passenger p;
    bool f = 0;

    while (true) {
        streampos pos = file.tellg();

        getline(file, p.surname, '\0');
        if (file.eof()) 
            break;
        getline(file, p.name, '\0');
        getline(file, p.secondName, '\0');

        file.read(reinterpret_cast<char*>(&p.luggagePlace), sizeof(p.luggagePlace));
        file.read(reinterpret_cast<char*>(&p.totalWeight), sizeof(p.totalWeight));

        if (p.surname == surname) {
            cout << "Текущий вес: " << p.totalWeight << ". Введите новый вес: ";
            double newWeight;
            cin >> newWeight;

            cin.ignore(1000, '\n');

            p.totalWeight = newWeight;

            file.seekp(pos);
            file.write(p.surname.c_str(), p.surname.size() + 1);
            file.write(p.name.c_str(), p.name.size() + 1);
            file.write(p.secondName.c_str(), p.secondName.size() + 1);
            file.write(reinterpret_cast<char*>(&p.luggagePlace), sizeof(p.luggagePlace));
            file.write(reinterpret_cast<char*>(&p.totalWeight), sizeof(p.totalWeight));

            f = 1;
            break;
        }
    }

    if (!f) {
        cout << "Пассажир с фамилией " << surname << " не найден.\n";
    }

    file.close();
}

void lab11() {
    string filename = "passengers.dat";
    int key;

    double condition;
    string surname;

    do {
        cout << "\nМеню:\n"
            << "1. Создать файл\n"
            << "2. Посмотреть файл\n"
            << "3. Добавить запись\n"
            << "4. Удалить записи с весом багажа < N\n"
            << "5. Изменить вес багажа по фамилии\n"
            << "0. Выход\n"
            << "Выберите пункт: ";
        cin >> key;

        switch (key) {
        case 1: 
            int N;
            cout << "Введите количество записей: ";
            cin.ignore(1000, '\n');
            cin >> N;
            createFile(filename, N);
            break;
        case 2:
            viewFile(filename);
            break;
        case 3:
            addRecord(filename);
            break;
        case 4:
            cout << "Удалить пассажиров с весом багажа меньше чем: ";
            cin >> condition;
            cin.ignore(1000, '\n');
            deletePassenger(filename, condition);
            break;
        case 5:
            cout << "Введите фамилию для изменения общего веса багажа: ";
            cin >> surname;
            cin.ignore(1000, '\n');
            changeWeight(filename, surname);
            break;
        case 0:
            cout << "Exiting";
            break;
        default:
            cout << "Неверный пункт выбора меню.\n";
        }
    } while (key != 0);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    srand(0);
    //lab1();
    //lab2();
    //lab3();
    //lab4();
    //lab10();
    lab11();
}
