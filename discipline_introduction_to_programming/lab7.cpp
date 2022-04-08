1) Требуется отсортировать массив по неубыванию методом "пузырька"{}.
#include <iostream>

using namespace std;

void bublesort(int* a, int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int size;
    cin >> size;
    int *arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    bublesort(arr, size);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}
2) Требуется отсортировать массив по неубыванию методом "вставок"{}.
#include <iostream>

using namespace std;

void insertionsort(int* a, int n) {
    int temp;
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int size;
    cin >> size;
    int *arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    insertionsort(arr, size);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}
3) Требуется отсортировать массив по неубыванию методом "выбор максимума".
#include <iostream>

using namespace std;

void selectionsort(int* a, int n) {
    int temp, max;
    for (int i = n - 1; i >= 0; i--) {
        max = i;
        for (int j = 0; j < i + 1; j++) {
            if (a[max] < a[j]) {
                max = j;
            } 
        }
        temp = a[max];
        a[max] = a[i];
        a[i] = temp;
    }
}

int main()
{
    int size;
    cin >> size;
    int *arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    selectionsort(arr, size);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}
4) Little Vasya has received a young builder’s kit. The kit consists of several wooden bars, the lengths of all of them are known. The bars can be put one on the top of the other if their lengths are the same.
Vasya wants to construct the minimal number of towers from the bars. Help Vasya to use the bars in the best way possible.
#include <iostream>

using namespace std;

void bublesort(int* a, int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int* length = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> length[i];
    }

    int height, maxheight = 1;
    for (int i = 0; i < n; i++) {
        height = 1;
        for (int j = i + 1; j < n; j++) {
            if (length[i] == length[j]) {
                height++;
            }
            if (maxheight <= height) {
                maxheight = height;
            }  
        }
    }
    bublesort(length, n);

    int towernumber = 1;
    for (int i = 0; i < n - 1; i++) {
        if (length[i] != length[i + 1]) {
            towernumber++;
        }
    }

    cout << maxheight << " " << towernumber;

    return 0;
}
5) Kirito is stuck on a level of the MMORPG he is playing now. To move on in the game, he's got to defeat all n dragons that live on this level. Kirito and the dragons have strength, which is represented by an integer. In the duel between two opponents the duel's outcome is determined by their strength. Initially, Kirito's strength equals s.
If Kirito starts duelling with the i-th (1 ≤ i ≤ n) dragon and Kirito's strength is not greater than the dragon's strength xi, then Kirito loses the duel and dies. But if Kirito's strength is greater than the dragon's strength, then he defeats the dragon and gets a bonus strength increase by yi.
Kirito can fight the dragons in any order. Determine whether he can move on to the next level of the game, that is, defeat all dragons without a single loss.
#include <iostream>

using namespace std;

void sorting(int *strength, int *bonus, int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strength[i] > strength[j]) {
                temp = strength[i];
                strength[i] = strength[j];
                strength[j] = temp;

                temp = bonus[i];
                bonus[i] = bonus[j];
                bonus[j] = temp;
            }
        }
    }
}

int main()
{
    int s, n;
    cin >> s >> n;
    int* x = new int[n];
    int* y = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    sorting(x, y, n);

    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (s > x[i]) {
            s += y[i];
        }
        else flag = false;
    }

    if (flag) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}
6) So, the New Year holidays are over. Santa Claus and his colleagues can take a rest and have guests at last. When two "New Year and Christmas Men" meet, thear assistants cut out of cardboard the letters from the guest's name and the host's name in honor of this event. Then the hung the letters above the main entrance. One night, when everyone went to bed, someone took all the letters of our characters' names. Then he may have shuffled the letters and put them in one pile in front of the door.
The next morning it was impossible to find the culprit who had made the disorder. But everybody wondered whether it is possible to restore the names of the host and his guests from the letters lying at the door? That is, we need to verify that there are no extra letters, and that nobody will need to cut more letters.
Help the "New Year and Christmas Men" and their friends to cope with this problem. You are given both inscriptions that hung over the front door the previous night, and a pile of letters that were found at the front door next morning.
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string guest, host, pileofletters;
    getline(cin, guest);
    getline(cin, host);
    getline(cin, pileofletters);
    string str = guest + host;
    
    int temp;
    for (int i = 0; i < pileofletters.size() - 1; i++) {
        for (int j = 0; j < pileofletters.size() - 1; j++) {
            if (pileofletters[j] > pileofletters[j + 1]) {
                temp = pileofletters[j];
                pileofletters[j] = pileofletters[j + 1];
                pileofletters[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < str.size() - 1; i++) {
        for (int j = 0; j < str.size() - 1; j++) {
            if (str[j] > str[j + 1]) {
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }

    if (pileofletters == str) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

	return 0;
}
7) Imagine that you have a twin brother or sister. Having another person that looks exactly like you seems very unusual. It's hard to say if having something of an alter ego is good or bad. And if you do have a twin, then you very well know what it's like.
Now let's imagine a typical morning in your family. You haven't woken up yet, and Mom is already going to work. She has been so hasty that she has nearly forgotten to leave the two of her darling children some money to buy lunches in the school cafeteria. She fished in the purse and found some number of coins, or to be exact, n coins of arbitrary values a1, a2, ..., an. But as Mom was running out of time, she didn't split the coins for you two. So she scribbled a note asking you to split the money equally.
As you woke up, you found Mom's coins and read her note. "But why split the money equally?" — you thought. After all, your twin is sleeping and he won't know anything. So you decided to act like that: pick for yourself some subset of coins so that the sum of values of your coins is strictly larger than the sum of values of the remaining coins that your twin will have. However, you correctly thought that if you take too many coins, the twin will suspect the deception. So, you've decided to stick to the following strategy to avoid suspicions: you take the minimum number of coins, whose sum of values is strictly more than the sum of values of the remaining coins. On this basis, determine what minimum number of coins you need to take to divide them in the described manner.
#include <iostream>

using namespace std;

int main()
{
	int n, sum = 0, mymoney = 0, count = 0;
	cin >> n;
	int* coins = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> coins[i];
		sum += coins[i];
	}
	int half = sum / 2;

	int temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (coins[j] > coins[j + 1]) {
				temp = coins[j];
				coins[j] = coins[j + 1];
				coins[j + 1] = temp;
			}
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		mymoney += coins[i];
		count++;
		if (mymoney > half) {
			break;
		}
	}

	cout << count;
	return 0;
}
8) Требуется отсортировать массив по максимальной цифре по неубыванию сортировкой выбором (selection sort).

9) Вам дан массив a из n целых чисел. Отсортируйте элементы массива от индекса L до индекса R. Индексы массива начинаются с нуля.
#include <iostream>

using namespace std;

int main()
{
    int size;
    cin >> size;
    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    int l, r;
    cin >> l >> r;

    int temp;
    for (int i = l; i < r; i++) {
        for (int j = l; j < r; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}
10) Выведите все исходные точки в порядке возрастания их расстояний от начала координат.
#include <iostream>
#include <cmath>

using namespace std;

struct Point {
	int x;
	int y;
	double length;
};

void sorting(Point* a, int n) {
	Point temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (a[j].length > a[j + 1].length) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	Point* point = new Point[n];
	for (int i = 0; i < n; i++) {
		cin >> point[i].x >> point[i].y;
	}
	for (int i = 0; i < n; i++) {
		point[i].length = sqrt(point[i].x * point[i].x + point[i].y * point[i].y);
	}

	sorting(point, n);

	for (int i = 0; i < n; i++) {
		cout << point[i].x << " " << point[i].y << endl;
	}

	return 0;
}
