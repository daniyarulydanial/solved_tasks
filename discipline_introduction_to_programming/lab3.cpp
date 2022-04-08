1) Выведите все натуральные делители числа x в порядке возрастания (включая 1 и само число).
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x, i;
    cin >> x;
    for (i = 1; i <= x; i++) {
        if (x % i == 0) { cout << i << " "; }
    }

    return 0;
}
2) Выведите все числа на отрезке от a до b, являющиеся полными квадратами. Если таких чисел нет, то ничего выводить не нужно.
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, Sqrt;
    cin >> a >> b;

    for (a; a <= b; a++)
    {
        Sqrt = sqrt((double)a);
        if (Sqrt * Sqrt == a) { cout << a << " "; }
    }
    
    return 0;
}
3) Выведите все числа на отрезке от a до b, дающие остаток c при делении на d. Если таких чисел не существует, то ничего выводить не нужно.
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (a; a <= b; a++) {
        if ( a % d == c ) { cout << a << " "; }
    }

    return 0;
}
4) Вычислите N! – произведение всех натуральных чисел от 1 до N (N! = 1∙2∙3∙…∙N).
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, i, fact = 1;
    cin >> n;
    for (i = 1; i <= n; i++) {
        if (n <= 12) {
        fact *= i;
        }
    }
    cout << fact;
    return 0;
}
5) Найдите самый маленький натуральный делитель числа x, отличный от 1 (2 <= x <= 30000).
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x, i;
    cin >> x;

    for (i = 2; i <= x; i++) {
        if (x % i == 0) { 
            cout << i; 
            break; 
        }
    }

    return 0;
}
6) Подсчитайте количество натуральных делителей числа x (включая 1 и само число; x <= 30000).
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x, i, j = 0;
    cin >> x;

    for (i = 1; i <= x; i++) {
        if (x % i == 0) { 
            j++;
        }
    }
    cout << j;

    return 0;
}
7) По данному натуральному n вычислите сумму 12 + 22 + ... + n2.
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, i, sum = 0;
    cin >> n;

    for (i = 1; i <= n; i++) {
        if (n <= 100) { sum += i * i; }
    }
    cout << sum;

    return 0;
}
8) Дано натуральное число N. Напишите программу, вычисляющую сумму цифр числа N.
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, sum = 0;
    cin >> n;

    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    cout << sum;

    return 0;
}
9) Напишите программу, вычисляющую 2N.
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, result;
    cin >> n;

    if (n >= 0 && n <= 30) {
        result = pow(2, n);
        cout << result;
    }
    
    return 0;
}
10) Дано натуральное число N. Напишите программу, определяющую наименьшую и наибольшую цифры данного числа.
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, max = 0, min = 10;
    cin >> n;

    while (n != 0) {
        if (max <= n % 10) { max = n % 10; }
        if (min >= n % 10) { min = n % 10; }
        n /= 10;
    }
    cout << min << " " << max;

    return 0;
}
11) По для каждой пары натуральных чисел ni и mi найдите их наибольший общий делитель.
В первой строке дано натуральное число T (1 ≤ T ≤ 10). В следующих T строках даны натуральные числа ni и mi.
Выведите наибольший общий делитель для каждой пары ni и mi.

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t, i, n, m;
    cin >> t;

    for (i = 1; i <= t; i++) {
        cin >> n >> m;
        while (n != m) {
            if (n > m) {
                int tmp = n;
                n = m;
                m = tmp;
            }
            m = m - n;
        }
        cout << n << endl;
    }
    
    return 0;
}
12) Найдите все целые решения уравнения ax3 + bx2 + cx + d = 0 на отрезке [0,1000] и выведите их в порядке возрастания. Если на данном отрезке нет ни одного решения, то ничего выводить не нужно.
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    for (int x = 0; x <= 1000; x++) {
        a * pow(x, 3) + b * pow(x, 2) + c * x + d == 0;
        if (a * pow(x, 3) + b * pow(x, 2) + c * x + d == 0) { cout << x << " "; }
    }

    return 0;
}
13) Найдите все целые решения уравнения ax3 + bx2 + cx + d = 0 на отрезке [0,1000] и выведите их в порядке убывания. Если на данном отрезке нет ни одного решения, то ничего выводить не нужно.
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c, d;
    cin >> a >> b >> c >> d;

    for (int x = 1000; x >= 0; x--) {
        a * pow(x, 3) + b * pow(x, 2) + c * x + d == 0;
        if (a * pow(x, 3) + b * pow(x, 2) + c * x + d == 0) { cout << x << " "; }
    }

    return 0;
}
14) A soldier wants to buy w bananas in the shop. He has to pay k dollars for the first banana, 2k dollars for the second one and so on (in other words, he has to pay i·k dollars for the i-th banana).
He has n dollars. How many dollars does he have to borrow from his friend soldier to buy w bananas?
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int w, k, n, need, i, cost = 0;
    cin >> k >> n >> w;

    for (i = 1; i <= w; i++) {
        cost += i * k;
    }
    need = n - cost;
    if (need >= 0) { cout << 0; }
    else if (need < 0) { 
        need = -need;
        cout << need; 
    }

    return 0;
}

15) Petya loves lucky numbers. We all know that lucky numbers are the positive integers whose decimal representations contain only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.
Unfortunately, not all numbers are lucky. Petya calls a number nearly lucky if the number of lucky digits in it is a lucky number. He wonders whether number n is a nearly lucky number.

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    string nl;
    cin >> nl;
    int  res = 0;
    for (int i = 0; i <= nl.length(); i++) {
        if (nl[i] == '7' || nl[i] == '4')
            res++;
    }
    
    if (res == 4 || res == 7) { cout << "YES"; }
    else { cout << "NO"; }

    return 0;
}
16) Petya loves lucky numbers. Everybody knows that lucky numbers are positive integers whose decimal representation contains only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.
Petya calls a number almost lucky if it could be evenly divided by some lucky number. Help him find out if the given number n is almost lucky.

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int nl;
    cin >> nl;
   
    if (nl % 4 == 0 || nl % 7 == 0 || nl % 44 == 0 || nl % 47 == 0 || nl % 74 == 0 || nl % 77 == 0) { cout << "YES"; }
    else if (nl % 444 == 0 || nl % 447 == 0 || nl % 474 == 0 || nl % 477 == 0) { cout << "YES"; }
    else if (nl % 744 == 0 || nl % 747 == 0 || nl % 774 == 0 || nl % 777 == 0) { cout << "YES"; }
    else cout << "NO";
    
    return 0;
}

