1) Минимум 4 чисел
#include <iostream>

using namespace std;

void min(int var1, int var2, int var3, int var4) {
    int Min = var1;
    int arr[4] = {var1, var2, var3, var4};
    for (int i = 0; i < 4; i++) {
        if (Min >= arr[i]) Min = arr[i];
    }
    cout << Min;
}

int main()
{
    int var1, var2, var3, var4;
    cin >> var1 >> var2 >> var3 >> var4;
    min(var1, var2, var3, var4);
    return 0;
}
2) Напишите функцию double power (double a, int n) (C/C++), function power (a:real; n:longint): real (Pascal), вычисляющую значение an.
#include <iostream>
#include <iomanip>

using namespace std;

double power(double a, int n) {
    double result = 1;
    for (int i = 1; i <= n; i++) {
        result *= a;
    }
    return result;
}

int main()
{
    double a;
    int n;
    cin >> a >> n;
    cout << fixed << setprecision(10) << power(a, n);
    return 0;
}
3) Напишите функцию
bool Xor (bool x, bool y) (C/C++),
function Xor (x,y:boolean): boolean (Pascal),
def xor(x, y):(Python)
реализующую функцию "Исключающее ИЛИ"{} двух логических переменных x и y. Функция Xor должна возвращать true, если ровно один из ее аргументов x или y, но не оба одновременно, равны true.
#include <iostream>

using namespace std;

bool Xor(bool x, bool y) {
    int inverse_x, inverse_y;
    if (x == true) inverse_x = false;
    else inverse_x = true;
    if (y == true) inverse_y = false;
    else inverse_y = true;
    return (x * inverse_y) + (inverse_x * y);
}

int main()
{
    bool x, y;
    cin >> x >> y;
    cout << Xor(x, y);
    return 0;
}
4) Напишите "функцию голосования"{} bool Election(bool x, bool y, bool z) (C/C++), function Election (x, y, z:boolean): boolean (Pascal), возвращающую то значение (true или false), которое среди значений ее аргументов x, y, z встречается чаще.
#include <iostream>

using namespace std;

bool Election(bool x, bool y, bool z) {
    int count = 0;
    if (x == true) count++;
    if (y == true) count++;
    if (z == true) count++;
    if (count >= 2) return true;
    else return false;
}

int main()
{
    bool x, y, z;
    cin >> x >> y >> z;
    cout << Election(x, y, z);
    return 0;
}
5) Проверьте, является ли число простым.
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            cout << "composite";
            return 0;
        }
    }
    cout << "prime";
    return 0;
}
6) Напишите функцию, возводящую число a в степень n. Гарантируется, что все числа «помещаются» в стандартные вещественные (a и ответ) и целые (n) типы.
#include <iostream>
#include <iomanip>

using namespace std;

double power(double a, int n) {
    double result = 1;
    if (n > 0) {
        for (int i = 1; i <= n; i++) {
            result *= a;
        }
    }
    else if (n < 0) {
        for (int i = n; i <= -1; i++) {
            result *= 1 / a;
        }
    }
    else if (n == 0 && a != 0) result = 1;
    return result;
}

int main()
{
    double a;
    int n;
    cin >> a >> n;
    cout << fixed << setprecision(10) << power(a, n);
    return 0;
}
7) Напишите функцию быстрого возведения в степень. Количество действий должно быть пропорционально двоичному логарифму n.
#include <iostream>
#include <iomanip>

using namespace std;

double power(double a, int n) {
    double result = 1;
    while (n > 0) {
        if (n % 2 == 1)
            result *= a;
        a *= a;
        n /= 2;
    }
    return result;
}

int main()
{
    double a;
    int n;
    cin >> a >> n;
    cout << fixed << setprecision(10) << power(a, n);
    return 0;
}
8) Последовательность Фибоначчи определена следующим образом: φ0=1, φ1=1, φn=φn−1+φn−2 при n>1. Начало ряда Фибоначчи выглядит следующим образом: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ... Напишите функцию int phi(int n) (C/C++), function phi (n:integer): integer, (Pascal), которая по данному натуральному n возвращает φn.
#include <iostream>

using namespace std;

int fibonacci(int n) {
    int a = 1, b = 0;
    for (int i = 0; i <= n; i++) {
        a += b;
        b = a - b;
    }
    return b;
}

int main()
{
    int x;
    cin >> x;
    cout << fibonacci(x);
    return 0;
}
9) Для биномиальных коэффициентов (числа сочетаний из n по k) хорошо известна рекуррентная формула: Ckn=Ck−1n−1+Ckn−1, C0n=Cnn=1.
#include <iostream>

using namespace std;

long long binom(long long n, long long k) {
    if (k > n / 2) k = n - k;
    if (k == 0) return 1;
    if (k == 1) return n;
    long long result = 1;
    for (int i = 1; i <= k; ++i) {
        result *= n - k + i;
        result /= i;
    }
    return result;
}

int main()
{
    int x, y;
    cin >> x >> y;
    cout << binom(x, y);
    return 0;
}
10) Дана строка, содержащая только десятичные цифры. Найти и вывести наибольшую цифру.
#include <iostream>
#include <string>

using namespace std;

char maxnum(string numbers) {
    char max = 0;
    for (int i = 0; i <= numbers.length(); i++) {
        if (max <= numbers[i]) max = numbers[i];
    }
    return max;
}

int main()
{
    string Numbers;
    cin >> Numbers;
    cout << maxnum(Numbers);
    return 0;
}
11) Дана строка, содержащая цифры и английские буквы (большие и маленькие). Найти и вывести количество цифр.
#include <iostream>
#include <string>

using namespace std;

int numofdigits(string symbols) {
    int count = 0;
    for (int i = 0; i <= symbols.length(); i++) {
        if (symbols[i] >= '0' && symbols[i] <= '9') count++;
    }
    return count;
}

int main()
{
    string Symbols;
    cin >> Symbols;
    cout << numofdigits(Symbols);
    return 0;
}
12) Дана строка, содержащая только английские буквы (большие и маленькие). Добавить символ '*' (звездочка) между буквами (перед первой буквой и после последней символ '*' добавлять не нужно).
#include <iostream>
#include <string>

using namespace std;

void letterswithstar(string letters) {
    for (int i = 1; i < letters.length(); i++) {
        letters.insert(i, 1, '*');
        ++i;
    }
    cout << letters;
}

int main()
{
    string Letters;
    cin >> Letters;
    letterswithstar(Letters);
    return 0;
}
13) Дана строка, содержащая только английские буквы (большие и маленькие). Добавить открывающиеся и закрывающиеся скобки по следующему образцу: "example"{} -> "e(x(a(m)p)l)e"{} (До середины добавлены открывающиеся скобки, после середины – закрывающиеся. В случае, когда длина строки четна в скобках, расположенных в середине, должно быть 2 символа. ("card"{} -> "c(ar)d"{}, но не "(c(a()r)d)"{}).
#include <iostream>
#include <string>

using namespace std;

void parenthesis(string letters) {
    for (int i = 1; i < (letters.size() / 2) + 1; i++) {
        letters.insert(i, 1, '(');
        letters.insert(letters.size() - i, 1, ')');
        ++i;
    }
    if (letters.find("()") != -1) {
        letters.erase(letters.find("()"), 2);
    }
    cout << letters << endl;
}

int main()
{
    string Letters;
    cin >> Letters;
    parenthesis(Letters);
    return 0;
}
14) Дана строка, содержащая только английские буквы (большие и маленькие) и открывающиеся скобки. Сформировать новую строку добавлением справа «зеркальной»{} строки с закрывающимися скобками. "(abc(def(g"{} -> "(abc(def(gg)fed)cba)"{}.
#include <iostream>
#include <string>

using namespace std;

void withreverse(string letters) {
    string reverse = letters;
    for (int i = letters.size() - 1; i >= 0; i--) {
        if (letters[i] == '(') reverse += ')';
        else reverse += letters[i];
    }
    cout << reverse;
}

int main()
{
    string Letters;
    cin >> Letters;
    withreverse(Letters);
    return 0;
}
15) Дана строка, содержащая только маленькие английские буквы. Сформировать новую строку путем «сокращения»{} одинаковых букв, находящихся на симметричных местах (то есть если на одинаковом расстоянии от центра строки находятся 2 одинаковые буквы, то их нужно убрать из строки). Если длина строки нечётна, то среднюю букву сокращать не нужно.
#include <iostream>
#include <string>

using namespace std;

string erased(string letters) {
    if (letters.size() == 0 || letters.size() == 1) {
        return letters;
    }
    else if (letters.size() == 2 && letters[0] != letters[letters.size() - 1]) {
        return letters;
    }
    else if (letters[0] == letters[letters.size() - 1]) {
        letters = letters.substr(1, letters.size() - 2);
        return erased(letters);
    }
    return letters[0] + erased(letters.substr(1, letters.size() - 2)) + letters[letters.size() - 1];
}

int main()
{
    string Letters;
    cin >> Letters;
    cout << erased(Letters);
    return 0;
}
16) Даны два числа. Найти их наибольший общий делитель.
#include <iostream>
#include <string>

using namespace std;

void gcd(int var1, int var2) {
    while (var1 != var2) {
        if (var1 > var2) var1 -= var2;
        else var2 -= var1;
    }
    cout << var1;
}

int main()
{
    int Var1, Var2;
    cin >> Var1 >> Var2;
    gcd(Var1, Var2);
    return 0;
}
17) Требуется вычислить площадь комнаты в квадратном лабиринте.
#include <iostream>
#include <string>

using namespace std;

int n, counter = 0;
char room[10][10];

void area(int x, int y)
{
    if (room[x][y] == '*' || x + 1 == n || y + 1 == n || x - 1 == -1 || y - 1 == -1)
        return;
    counter++;
    room[x][y] = '*';
    area(x + 1, y);
    area(x, y + 1);
    area(x - 1, y);
    area(x, y - 1);
}
 
int main()
{
    int X, Y;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> room[i][j];
        }
    }

    cin >> X >> Y;
    area(X - 1, Y - 1);
    cout << counter;
    return 0;
}

18) Дана полоска из клеток, пронумерованных от 1 до N. На каждом ходе разрешено поставить фишку на клетку (если её там еще нет) или снять фишку с клетки (если она там есть). При этом, можно выбрать не любую клетку, а только клетку под номером 1 или клетку, следующую за самой первой фишкой. Изначально полоска пуста. Требуется занять все клетки.
#include <iostream>

using namespace std;

void chips(int begin, int n) {
    if (n <= 0) {
        return;
    }
    if (begin <= n) {
        cout << begin << ' ';
        if (begin > 1 && begin != n) {
            cout << -(begin - 1) << ' ';
        }
        chips(begin + 1, n);
    }
    else {
        chips(1, n - 2);
    }
}

int main()
{
    int N;
    cin >> N;
    int Begin = 1;
    chips(Begin, N);
    return 0;
}
19) Выведите двумерный массив, размерами N×N, заполненный числами от единицы до N2 по спирали. Числовая спираль начинается в левом верхнем углу и закручивается по часовой стрелке.
#include <iostream>

using namespace std;

void helix(int n) {
    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }
    int size = n, num = 1;
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            arr[i][j] = num;
            num++;
        }
        for (int j = i + 1; j < size; j++) {
            arr[j][size - 1] = num;
            num++;
        }
        for (int j = size - 2; j >= i; j--) {
            arr[size - 1][j] = num;
            num++;
        }
        for (int j = size - 2; j >= i + 1; j--) {
            arr[j][i] = num;
            num++;
        }
        size--;
    }
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            cout << arr[a][b] << " ";
        }
        if (a != n - 1) cout << endl;
    }
}

int main()
{
    int x;
    cin >> x;
    helix(x);
    return 0;
}

20) Последовательностью Фибоначчи называется последовательность чисел a0,a1,...,an,..., где a0=0, a1=1, ak=ak−1+ak−2 (k>1).
Требуется найти N-е число Фибоначчи.
Примечание. В программе запрещается использовать циклы
#include <iostream>

using namespace std;

int fib(int n) {
    if (n == 0 || n == 1) return n;
    else return fib(n - 1) + fib(n - 2);
}

int main()
{
    int x;
    cin >> x;
    cout << fib(x);
    return 0;
}
21) Даны два натуральных числа N и K. Требуется вывести все цепочки x1,x2,...,xN такие, что xi - натуральное и 1≤xi≤K.
#include <iostream>
using namespace std;
int n, k;
char numbers[6], permanent[6];
void generator(int position) {
    if (position == n) {
        for (int i = 0; i < n; ++i)
            cout << permanent[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 0; i < k; ++i) {
        permanent[position] = numbers[i];
        generator(position + 1);
    }
}

int main()
{
    cin >> n >> k;
    numbers[0] = '1';
    numbers[1] = '2';
    numbers[2] = '3';
    numbers[3] = '4';
    numbers[4] = '5';
    numbers[5] = '6';

    generator(0);
    return 0;
}
22) Дано натуральное число N и последовательность из N элементов. Требуется вывести эту последовательность в обратном порядке.
Примечание. В программе запрещается объявлять массивы и использовать циклы (даже для ввода и вывода).
#include <iostream>

using namespace std;

void reverseorder(int amount) { 
    int a;
    if (amount > 0) {
        cin >> a;
        reverseorder(amount-1);
        cout << a << " ";
    }
}

int main()
{
    int Amount;
    cin >> Amount;
    reverseorder(Amount);
    return 0;
}
23) У Вас есть N камней с массами W1, W2, … WN. Требуется разложить камни на 2 кучки так, чтобы разница масс этих кучек была минимальной.
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

string shifting(int x) {
    string value;
    while (x > 0) {
        value.push_back(x % 2 + '0');
        x = x / 2;
    }
    return value;
}

int main() {
    int n, answer = 10000000, sum = 0;
    cin >> n;
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
        sum += weights[i];
    }
    long long start = (pow(2.0, n - 1)), end = (pow(2.0, n)) - 1;
    for (int i = start; i <= end; i++) {
        string mask = shifting(i);
        int current = 0;
        for (int j = 0; j < mask.length(); j++) {
            if (mask[j] == '1')
                current += weights[j];
        }
        if (abs(sum - current - current) < answer)
            answer = abs(sum - current - current);
    }
    cout << answer << endl;
    return 0;
}

24) Требуется найти число способов расставить на шахматной доске N×N K ладей так, чтобы они не били друг друга. Все ладьи считаются одинаковыми.
#include <iostream>

using namespace std;

void numofways(int n, int k) {
    int total = 1, x = 1;
    for (int i = 0; i < k; i++) {
        total = total * (n - i) * (n - i);
        x = x * (i + 1);
    }
    cout << total / x;
}

int main()
{
    int x, y;
    cin >> x >> y;
    numofways(x, y);
    return 0;
}
26) Головоломка "Ханойские башни" состоит из трех стержней, пронумерованных числами 1, 2, 3. На стержень 1 надета пирамидка из n дисков различного диаметра в порядке возрастания диаметра. Диски можно перекладывать с одного стержня на другой по одному, при этом диск нельзя класть на диск меньшего диаметра. Необходимо переложить всю пирамидку со стержня 1 на стержень 3 за минимальное число перекладываний.
Напишите программу, которая решает головоломку; для данного числа дисков n печатает последовательность перекладываний в формате a b c, где a — номер перекладываемого диска, b — номер стержня с которого снимается данный диск, c — номер стержня на который надевается данный диск.
Например, строка 1 2 3 означает перемещение диска номер 1 со стержня 2 на стержень 3. В одной строке печатается одна команда. Диски пронумерованы числами от 1 до n в порядке возрастания диаметров.
#include <iostream>

using namespace std;

void tower(int disks, int a, int b) {
    if (disks == 1) cout << disks << " " << a << " " << b << endl;
    else {
        tower(disks - 1, a, 6 - a - b);
        cout << disks << " " << a << " " << b << endl;
        tower(disks - 1, 6 - a - b, b);
    }
}

int main()
{
    int x;
    cin >> x;
    tower(x, 1, 3);
    return 0;
}
 

