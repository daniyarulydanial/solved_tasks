№1 Даны два целых числа, выведите наибольшее из данных чисел.
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a;
	int b;
	cin >> a;
	cin >> b;
	if (a > b) {
		cout << a;
	}
	else {
		cout << b;
	}

	return 0;
}
№2 Требуется определить, является ли данный год високосным.
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int visgod;
	cin >> visgod;
	if (visgod % 4 == 0 && visgod % 100 != 0 || visgod % 400 == 0) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	return 0;
}
№3 Даны два целых числа, программа должна вывести число 1, если первое число больше второго, число 2, если второе больше первого, или число 0, если они равны.
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b;
	cin >> a;
	cin >> b;
	if (a > b) {
		cout << "1";
	}
	else if (a < b){
		cout << "2";
	}
	else {
		cout << "0";
	}
	return 0;
}
№4 Даны три целых числа, выведите наибольшее из данных чисел.
#include <iostream>
 
using namespace std;
 
int main() {
  int a,b,c;
  cin>>a>>b>>c;
  if(a>=b&&a>=c) {
    cout<<a;
  } 
else if(b>=a&&b>=c) {
    cout<<b;
  } 
else if(c>=a&&c>=b) {
    cout<<c;
  }
return 0;
}

№5 Требуется определить, бьет ли ладья, стоящая на клетке с указанными координатами (номер строки и номер столбца), фигуру, стоящую на другой указанной клетке.
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int x1, x2, y1, y2;
	cin >> x1;
	cin >> y1;
	cin >> x2;
	cin >> y2;
	if (x1 == x2) {
		cout << "YES";
	}
	else if (y1 == y2) {
		cout << "YES";
	}
	else { 
		cout << "NO"; 
	}
	
	return 0;
}
№6 Требуется определить, бьет ли слон, стоящий на клетке с указанными координатами (номер строки и номер столбца), фигуру, стоящую на другой указанной клетке.
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int x1, x2, y1, y2;
	cin >> x1;
	cin >> y1;
	cin >> x2;
	cin >> y2;
	int dx = x1 - x2;
	int dy = y1 - y2;
	if (dx<0) {
		dx = -dx;
	}
	if (dy<0) {
		dy = -dy;
	}
	if (dx == dy) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	
	return 0;
}
№7 Требуется определить, бьет ли ферзь, стоящий на клетке с указанными координатами (номер строки и номер столбца), фигуру, стоящую на другой указанной клетке.
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int x1, x2, y1, y2;
	cin >> x1;
	cin >> y1;
	cin >> x2;
	cin >> y2;
	int dx = x1 - x2;
	int dy = y1 - y2;
	if (dx<0) {
		dx = -dx;
	}
	if (dy<0) {
		dy = -dy;
	}
	if (dx == dy || x1 == x2 || y1 == y2) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	
	return 0;
}
№8 Поле шахматной доски определяется парой чисел (a, b), каждое от 1 до 8, первое число задает номер столбца, второе – номер строки. Заданы две клетки. Определите, может ли шахматный король попасть с первой клетки на вторую за один ход.
1.	int x1,y1,x2,y2;
2.	  cin>>x1>>y1>>x2>>y2;
3.	  int dx = x1 - x2;
4.	  int dy = y1 - y2;
5.	  if (dx < 0) dx = -dx;
6.	  if (dy < 0) dy = -dy;
7.	 
8.	  if (dx + dy == 1)
9.	    cout<<"YES";
10.	  else
11.	    if (dx + dy == 2 && dx == 1 && dy == 1)
12.	      cout<<"YES";
13.	    else
14.	      cout<<"NO";

№9 In the department there are 3 employees who receive salary in tenge. It is required to determine: how much the salary of the highest paid of them differs from the lowest paid.
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;
	if (a >= b && b >= c) {
		cout << a - c;
	}
	else if (a >= c && c >= b) {
		cout << a - b;
	}
	else if (b >= a && a >= c) {
		cout << b - c;
	}
	else if (b >= c && c >= a) {
		cout << b - a;
	}
	else if (c >= a && a >= b) {
		cout << c - b;
	}
	else if (c >= b && b >= a) {
		cout << c - a;
	}
	
	return 0;
}
№10 Требуется определить, бьет ли конь, стоящий на клетке с указанными координатами (номер строки и номер столбца), фигуру, стоящую на другой указанной клетке.
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int x1, x2, y1, y2;
	cin >> x1;
	cin >> y1;
	cin >> x2;
	cin >> y2;
	int dx = x1 - x2;
	int dy = y1 - y2;
	if (dx < 0) {
		dx = -dx;
	}
	if (dy < 0) {
		dy = -dy;
	}
	if (dx + dy == 3) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	
	return 0;
}
№11 Даны три натуральных числа a, b, c, записанные в отдельных строках. Определите, существует ли неворожденный треугольник с такими сторонами.
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;
	if (a < b + c && b < a + c && c < a + b) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	
	return 0;
}
№12 Напишите программу, которая определяет, попадает ли заданная точка в заданный прямоугольник. Стороны прямоугольника параллельны осям координат.
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int x1, y1, x2, y2, x, y;
	cin >> x1;
	cin >> y1;
	cin >> x2;
	cin >> y2;
	cin >> x;
	cin >> y;
	if (x1 <= x && y1 >= y && x2 >= x && y2 <= y) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	
	return 0;
}
№13 Размеры холодильника A x B x C. Возможно ли его пронести через дверной проем размерами X x Y? Будем считать, что холодильник можно нести только под такими углами, чтобы некоторые две стороны холодильника были параллельны сторонам проема.
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b, c, x, y;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> x;
	cin >> y;
	if (a * b <= x * y || a * c <= x * y || b * c <= x * y) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	
	return 0;
}
