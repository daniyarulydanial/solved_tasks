1) Всем известен, так называемый, принцип Дирихле, который формулируется следующим образом:
Предположим, что некоторое число кроликов рассажены в клетках. Если число кроликов больше, чем число клеток, то хотя бы в одной из клеток будет больше одного кролика.
В данной задаче мы рассмотрим более общий случай этого классического математического факта. Пусть есть n клеток и m зайцев, которых рассадили по этим клеткам. Вам требуется расcчитать максимальное количество зайцев, которое гарантированно окажется в одной клетке.
#include <iostream>

using namespace std;

int main()
{
    int n, m, count = 0;
    cin >> n >> m;
    
    while (m > 0) {
        m = m - n;
        count++;
    }
    cout << count;
   
    return 0;
}
2) Сумму всех целых чисел от 1 до 100 можно посчитать при помощи хитрого приема. Разобьем все числа по парам 1 и 100, 2 и 99, 3 и 98 и т.д. Сумма каждой пары 101. Пар всего 100 пополам (50). Поэтому сумма равна (1+100)×1002.
Для нечетного количества слагаемых работает та же формула: например, 1+2+3=(1+3)×32=6.
#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    
    if (n > 1)
    cout << (1 + n) * n / 2;
   
    return 0;
}
3) Идёт k-я секунда суток. Определите, сколько целых часов h и целых минут m прошло с начала суток. Например, если
k=13257=3×3600+40×60+57,
то h=3 и m=40.
#include <iostream>

using namespace std;

int main()
{
    int k, h, m;
    cin >> k;
    if (k >= 0 && k <= 86399) {
        h = k / 3600;
        m = (k - 3600 * h) / 60;
        cout << "It is " << h << " hours " << m << " minutes.";
    }
    
    return 0;
}
4) Часовая стрелка повернулась с начала суток на d градусов. Определите, сколько сейчас целых часов h и целых минут m.
#include <iostream>

using namespace std;

int main()
{
    int d, h, m;
    cin >> d;
    if (d >= 0 && d <= 360) {
        h = d / 30;
        m = (d % 30) * 2;
        cout << "It is " << h << " hours " << m << " minutes.";
    }
    
    return 0;
}
5) В книге на одной странице помещается k строк. Таким образом, на 1-й странице печатаются строки с 1-й по k-ю, на второй — с (k+1)-й по (2k)-ю и т. д. Напишите программу, по номеру строки в тексте определяющую номер страницы, на которой будет напечатана эта строка, и порядковый номер этой строки на странице.
#include <iostream>

using namespace std;

int main()
{
    int k, n, page, line;
    cin >> k >> n;
    page = (n - 1) / k + 1;
    line = (n - 1) % k + 1;
        
    cout << page << " " << line;
    return 0;
}
6) Даны значения двух моментов времени, принадлежащих одним и тем же суткам: часы, потом минуты и секунды для каждого из моментов времени. Известно, что второй момент времени наступил не раньше первого. Определите, сколько секунд прошло между двумя моментами времени.
#include <iostream>

using namespace std;

int main()
{
    int h1, m1, s1, dif, h2, m2, s2;
    
    cin >> h1 >> m1 >> s1;
    cin >> h2 >> m2 >> s2;

    if (h1 <= h2 || m1 <= m2 || s1 <= s2) {
        dif = 3600*h2 - 3600*h1 + 60*m2 - 60*m1 + s2 - s1;
        cout << dif;
    }
          
    return 0;
}
7) Напишите функцию boolean IsDigit(char c) (Java), function IsDigit(c:char):boolean (Pascal), bool IsDigit(unsigned char c) (C/C++), определяющую, является ли данный символ цифрой или нет.
Естественно, программа должна считывать данные, вызывать эту функцию и выдавать ответ.
#include <iostream>

using namespace std;

void IsDigit(unsigned char c) 
{
    if (c >= '0' && c <= '9')
        cout << "yes";
    else
        cout << "no";
}

int main()
{
    char c;
    cin >> c;
    IsDigit(c);     
    return 0;
}
8) Напишите функцию unsigned char ToUpper(unsigned char c) (C/C++), function ToUpper(c:char):char (Pascal), которая переводит данный символ в верхний регистр.
#include <iostream>

using namespace std;

int main()
{
    char c;
    cin >> c;
    cout << char(toupper(c));
    return 0;
}
9) Измените регистр символа, если он был латинской буквой: сделайте его заглавным, если он был строчной буквой и наоборот. Для этого напишите отдельную функцию, меняющую регистр символа.
#include <iostream>

using namespace std;

int main()
{
    char c;
    cin >> c;
    if (char(isupper(c)))
        cout << char(tolower(c));
    else
        cout << char(toupper(c));
    return 0;
}
10) Напишите функцию bool Compare(string S1, string S2), определяющую, совпадают ли 2 строки.
#include <iostream>
#include <string>

using namespace std;

void compare(string s1, string s2) {
    if (s1 == s2) cout << "yes";
    else cout << "no";
}

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    compare(s1, s2);
    
    return 0;
}
11) Дана строка, содержащая пробелы. Найдите, сколько в ней слов (слово – это последовательность непробельных символов, слова разделены одним пробелом, первый и последний символ строки – не пробел).
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int count = 0;
    char prev = ' ';
    for (int i = 0; i <= s.length(); i++) {
        if (s[i] != ' ' && prev == ' ') count++;
        prev = s[i];
    }
    cout << count;
    
    return 0;
}
12) Дана строка, содержащая пробелы. Найдите в ней самое длинное слово, выведите это слово и его длину. Если таких слов несколько, выведите первое из них.
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int count = 0, slen = 0, index = 0, i;
    for (i = 0; i < s.size(); i++) {
        if (s[i] != ' ') count++;
        else {
            if (count > slen) {
                slen = count;
                index = i - count;
            }
            count = 0;
        }
        
    }
    if (count > slen) {
        slen = count;
        index = i - count;
    }

    slen = slen + index;
    for (i = index; i < slen; i++) {
        cout << s[i];
    }
    cout << endl << (slen - index);
    
    return 0;
}

13) По данной строке определите, является ли она палиндромом (то есть, можно ли прочесть ее наоборот, как, например, слово "топот"{}).
#include <iostream>
#include <string>

using namespace std;

bool check(string s) {
    int i, j, count = 0;
    int Length = s.length();
    for (i = 0, j = Length - 1; j > i; ++i, --j) {
        if (s[i] != s[j]) return false;
        else count++;
    }
    if (count >= Length / 2) return true;
}

int main()
{
    string s;
    getline(cin, s);
    if (check(s)) cout << "yes";
    else cout << "no";
    return 0;
}

14) Дана строка. Известно, что она содержит ровно две одинаковые буквы. Найдите эти буквы. Гарантируется, что повторяются буквы только одного вида.
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    bool flag = false;
    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < s.length(); j++)
            if (i != j && s[i] == s[j]) {
                cout << s[i];
                flag = true;
                break;
            }
        if (flag) break;
    }
    return 0;
}

15) Даны две строки. Определите, является ли первая строка подстрокой второй строки.
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s, sub;
    int n;
    getline(cin, sub);
    getline(cin, s);
    n = s.find(sub);
    if (n == -1) cout << "no";
    else cout << "yes";
    return 0;
}

16) Капитан Флинт зарыл клад на Острове сокровищ. Он оставил описание, как найти клад. Описание состоит из строк вида: "North 5"{}, где слово – одно из "North"{}, "South"{}, "East"{}, "West"{}, – задает направление движения, а число – количество шагов, которое необходимо пройти в этом направлении.

Напишите программу, которая по описанию пути к кладу определяет точные координаты клада, считая, что начало координат находится в начале пути, ось OX направлена на восток, ось OY – на север.
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int n, x = 0, y = 0;
    
    while (cin >> s >> n) {
        if (s == "East")
            x = x + n;
        else if (s == "West")
            x = x - n;
        else if (s == "North")
            y = y + n;
        else if (s == "South")
            y = y - n;
        else break;
    }
    cout << x << " " << y; 

    return 0;
}

17) Дана строка, состоящая из строчных латинских букв и пробелов. Проверьте, является ли она палиндромом без учета пробелов (например, "аргентина манит негра"{}).
#include <iostream>
#include <string>

using namespace std;

bool check(string s) {
    int i, j, count = 0;
   
    for (i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            s.erase(i, 1);
            i--;
        }
    }

    int Length = s.length();
    for (i = 0, j = Length - 1; j > i; ++i, --j) {
        if (s[i] != s[j]) return false;
        else count++;
    }
    if (count >= Length / 2) return true;
}

int main()
{
    string s;
    getline(cin, s);
    if (check(s)) cout << "yes";
    else cout << "no";
    return 0;
}

18) Юлий Цезарь использовал свой способ шифрования текста. Каждая буква заменялась на следующую по алфавиту через K позиций по кругу. Необходимо по заданной шифровке определить исходный текст.
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i, k, find;
    const int ABC_SIZE = 26;
    string s;
    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    getline(cin, s);
    cin >> k;
    
    for (i = 0; i < s.length(); i++) {
        find = s[i] - 'A';
        if (find - k < 0) {
            s.at(i) = letters.at(ABC_SIZE - (k - find));
        }
        else s.at(i) = letters.at(find - k);
    }
    
    cout << s;
    return 0;
}

19) Дана строка S, в которой выделили подстроку, состоящую из символов с i-го по j-й включительно (символы строки S нумеруются с единицы) и поменяли местами i-й символ с j-м, (i+1)-й с (j−1)-м и так далее (конвертировали подстроку). Выведите строку S после внесенных изменений.
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i, j, t, temp;
    string s;
    getline(cin, s);
    cin >> i >> j;
    for (t = i; t <= (j + i)/2; t++) {
        temp = s[t - 1];
        s[t - 1] = s[j + i - t - 1];
        s[j + i - t - 1] = temp;
    }
    
    cout << s;
    return 0;
}

20) Дана строка, Вам требуется преобразовать все идущие подряд пробелы в один.
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i;
    string s;
    getline(cin, s);
    for (i = 0; i <= s.length(); i++) {
        if (s[i] == ' ' && s[i + 1] == ' ') {
            s.erase(i, 1);
            i--;
        }
    }
    cout << s;
    return 0;
}
