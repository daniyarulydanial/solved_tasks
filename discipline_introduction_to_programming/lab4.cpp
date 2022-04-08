1) Дан массив, состоящий из целых чисел. Нумерация элементов начинается с 0. Напишите программу, которая выведет элементы массива, номера которых четны (0, 2, 4...).
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i, x;
    cin >> x;
    int *a = new int[x];
    for (i = 0; i < x; i++) {
        cin >> a[i];
    }
   
    for (i = 0; i < x; i++) {
        if (i % 2 == 0) { cout << a[i] << " "; } 
    } 

    return 0;
}
2) Дан массив, состоящий из целых чисел. Напишите программу, которая выводит те элементы массива, которые являются чётными числами.
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i, x;
    cin >> x;
    int *a = new int[x];
    for (i = 0; i < x; i++) {
        cin >> a[i];
    }
   
    for (i = 0; i < x; i++) {
        if (a[i] % 2 == 0) { cout << a[i] << " "; } 
    } 

    return 0;
}
3) Дан массив, состоящий из целых чисел. Напишите программу, которая подсчитывает количество положительных чисел среди элементов массива.

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i, x, count = 0;
    cin >> x;
    int *a = new int[x];
    for (i = 0; i < x; i++) {
        cin >> a[i];
    }
   
    for (i = 0; i < x; i++) {
        if (a[i] > 0) { count++; } 
    } 
    cout << count;

    return 0;
}
4) Дан массив, состоящий из целых чисел. Напишите программу, которая подсчитает количество элементов массива, больших предыдущего (элемента с предыдущим номером).
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i, x, count = 0;
    cin >> x;
    int *a = new int[x];
    for (i = 0; i < x; i++) {
        cin >> a[i];
    }
   
    for (i = 0; i < x; i++) {
        if (i == 0) continue;
        if (a[i] > a[i - 1]) { count++; } 
    } 
    cout << count;

    return 0;
}
5) Дан массив, состоящий из целых чисел. Напишите программу, которая определяет, есть ли в массиве пара соседних элементов с одинаковыми знаками.
#include <iostream>

using namespace std;

int main()
{
    int i, x, count = 0;
    cin >> x;
    int* a = new int[x];
    for (i = 0; i < x; i++) {
        cin >> a[i];
    }
    for (i = 1; i < x; i++) {
        if (a[i - 1] * a[i] > 0) {
            count++;
            cout << "YES";
            break;
        }
    }
    if (count == 0) { cout << "NO"; }

    return 0;
}
6) Дан массив, состоящий из целых чисел. Напишите программу, которая в данном массиве определит количество элементов, у которых два соседних и, при этом, оба соседних элемента меньше данного.
#include <iostream>

using namespace std;

int main()
{
    int i, x, count = 0;
    cin >> x;
    int* a = new int[x];
    for (i = 0; i < x; i++) {
        cin >> a[i];
    }
    for (i = 1; i < x - 1; i++) {
        if (a[i - 1] < a[i] && a[i + 1] < a[i]) {
            count++;
        }
    }
    cout << count;

    return 0;
}
7) Напишите программу, которая переставляет элементы массива в обратном порядке без использования дополнительного массива. Программа должна считать массив, поменять порядок его элементов, затем вывести результат (просто вывести элементы массива в обратном порядке – недостаточно!)
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i, x;
    cin >> x;
    int* a = new int[x];
    for (i = 0; i < x; i++) {
        cin >> a[i];
    }
    for (i = x - 1; i >= 0; i--) {
        cout << a[i] << " ";
    }
    return 0;
}
8) Напишите программу, которая циклически сдвигает элементы массива вправо (например, если элементы нумеруются, начиная с нуля, то 0-й элемент становится 1-м, 1-й становится 2-м, ..., последний становится 0-м, то есть массив {3, 5, 7, 9} превращается в массив {9, 3, 5, 7}).
#include <iostream>

using namespace std;

int main()
{
    int i, x, temp;
    cin >> x;
    int* a = new int[x];
    for (i = 0; i < x; i++) {
        cin >> a[i];
    }
    temp = a[x - 1];
    for (i = x - 1; i >= 0; i--) {
            a[i] = a[i - 1];
    }
    a[0] = temp;
    for (i = 0; i < x; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
9) Вводится массив, состоящий из целых чисел. Найти наибольшее среди них.
#include <iostream>

using namespace std;

int main()
{
    int i, x, max;
    cin >> x;
    int* a = new int[x];
    
    for (i = 0; i < x; i++) {
        cin >> a[i];
    }
    max = a[0];
    for (i = 1; i < x; i++) {
        if (max < a[i]) max = a[i];
    }
    cout << max;

    return 0;
}
10) Напишите программу, которая переставляет соседние элементы массива (1-й элемент поменять с 2-м, 3-й с 4-м и т.д. Если элементов нечетное число, то последний элемент остается на своем месте).
#include <iostream>

using namespace std;

int main()
{
    int i, x, temp;
    cin >> x;
    int* a = new int[x];
    
    for (i = 0; i < x; i++) {
        cin >> a[i];
    }
    for (i = 0; i < x; i++) {
        if (i % 2 == 1) {
            temp = a[i - 1];
            a[i - 1] = a[i];
            a[i] = temp;
        }
    }
    for (i = 0; i < x; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
11) Дан массив, состоящий из целых чисел. Известно, что числа упорядочены по неубыванию (то есть каждый следующий элемент не меньше предыдущего). Напишите программу, которая определит количество различных чисел в этом массиве.
#include <iostream>

using namespace std;

int main()
{
    int i, x, count = 1;
    cin >> x;
    int* a = new int[x];
    
    for (i = 0; i < x; i++) {
        cin >> a[i];
    }
    for (i = 0; i < x - 1; i++) {
        if (a[i + 1] != a[i]) {
            count++;
        }
    }
    cout << count;

    return 0;
}
12) Петя впервые пришел на урок физкультуры в новой школе. Перед началом урока ученики выстраиваются по росту, в порядке невозрастания. Напишите программу, которая определит на какое место в шеренге Пете нужно встать, чтобы не нарушить традицию, если заранее известен рост каждого ученика и эти данные уже расположены по невозрастанию (то есть каждое следующее число не больше предыдущего). Если в классе есть несколько учеников с таким же ростом, как у Пети, то программа должна расположить его после них.
#include <iostream>

using namespace std;

int main()
{
    int i, x, petya, count = 1;
    cin >> x;
    int* a = new int[x];

    for (i = 0; i < x; i++) {
        cin >> a[i];
    }
    cin >> petya;

    for (i = 0; i < x; i++) {
        if (a[i] >= petya) { count++; }
    }
    cout << count;

    return 0;
}
13) Дана последовательность натуральных чисел 1, 2, 3, ..., N (1≤N≤1000). Необходимо сначала расположить в обратном порядке часть этой последовательности от элемента с номером A до элемента с номером B, а затем от C до D (A<B; C<D; 1≤A,B,C,D≤N).
#include <iostream>

using namespace std;

int main()
{
    int i, x, a, b, c, d, temp;
    cin >> x >> a >> b >> c >> d;
    int* arr = new int[x];

    for (i = 0; i < x; i++) {
        arr[i] = i + 1;
    }
    for (i = a; i <= (b + a)/2; i++) {
        temp = arr[i - 1];
        arr[i - 1] = arr[b + a - i - 1];
        arr[b + a - i - 1] = temp;
    }
    for (i = c; i <= (d + c)/2; i++) {
        temp = arr[i - 1];
        arr[i - 1] = arr[d + c - i - 1];
        arr[d + c - i - 1] = temp;
    }  
    for (i = 0; i < x; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
14) В одной компьютерной игре игрок выставляет в линию шарики разных цветов. Когда образуется непрерывная цепочка из трех и более шариков одного цвета, она удаляется из линии. Все шарики при этом сдвигаются друг к другу, и ситуация может повториться.
Напишите программу, которая по данной ситуации определяет, сколько шариков будет "уничтожено"{}. Естественно, непрерывных цепочек из трех и более одноцветных шаров в начальный момент может быть не более одной.

#include <iostream>

using namespace std;

int main()
{
    int i, x, counter = 0, left, right, count;
    cin >> x;
    int* arr = new int[x];

    for (i = 0; i < x; i++) {
        cin >> arr[i];
    }
    for (i = 0; i < x - 2; i++) {
        left = i;
        right = i + 1;
        while (arr[left] == arr[right]) {
            count = 2;
            while (--left >= 0 && arr[left] == arr[right]) { count++; }
            while (++right < x && arr[right] == arr[left + 1]) { count++; }
            if (count < 3) { break; }
            counter += count;
        }
        if (counter) {
            cout << counter;
            return 0;
        }
    }
    cout << counter;
    return 0;
}
