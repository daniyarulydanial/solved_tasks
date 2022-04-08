""" Реализуйте программу, которая будет эмулировать работу с пространствами имен. 
Необходимо реализовать поддержку создания пространств имен и добавление в них переменных.
В данной задаче у каждого пространства имен есть уникальный текстовый идентификатор – его имя.
Вашей программе на вход подаются следующие запросы:

create <namespace> <parent> –  создать новое пространство имен с именем <namespace> внутри пространства <parent>
add <namespace> <var> – добавить в пространство <namespace> переменную <var>
get <namespace> <var> – получить имя пространства, из которого будет взята переменная <var> при запросе из пространства <namespace>, 
или None, если такого пространства не существует

Рассмотрим набор запросов
add global a
create foo global
add foo b
create bar foo
add bar a

Структура пространств имен описанная данными запросами будет эквивалентна структуре пространств имен, созданной при выполнении данного кода
a = 0
def foo():
  b = 1
  def bar():
    a = 2
    
В основном теле программы мы объявляем переменную a, тем самым добавляя ее в пространство global. 
Далее мы объявляем функцию foo, что влечет за собой создание локального для нее пространства имен внутри пространства global.
В нашем случае, это описывается командой create foo global. Далее мы объявляем внутри функции foo функцию bar, 
тем самым создавая пространство bar внутри пространства foo, и добавляем в bar переменную a.

Добавим запросы get к нашим запросам
get foo a
get foo c
get bar a
get bar b

Представим как это могло бы выглядеть в коде
a = 0
def foo():
  b = 1
  get(a)
  get(c)
  def bar():
    a = 2
    get(a)
    get(b)
    
Результатом запроса get будет имя пространства, из которого будет взята нужная переменная.
Например, результатом запроса get foo a будет global, потому что в пространстве foo не объявлена переменная a, 
но в пространстве global, внутри которого находится пространство foo, она объявлена. Аналогично, результатом запроса get bar b будет являться foo,
а результатом работы get bar a будет являться bar.

Результатом get foo c будет являться None, потому что ни в пространстве foo, ни в его внешнем пространстве global не была объявлена переменная с.
Более формально, результатом работы get <namespace> <var> является
<namespace>, если в пространстве <namespace> была объявлена переменная <var>
get <parent> <var> – результат запроса к пространству, внутри которого было создано пространство <namespace>, если переменная не была объявлена
None, если не существует <parent>, т. е. <namespace> – это global """

def add(namespace, var):
    my_namespaces[namespace]['variables'] += [var]


def create(namespace, parent):
    my_namespaces[namespace] = {'variables': [], 'parent': parent}


def get(namespace, var):
    if var in my_namespaces[namespace]['variables']:
        return namespace
    elif namespace == 'global' and var not in my_namespaces['global']['variables']:
        return
    else:
        return get(my_namespaces[namespace]['parent'], var)

n = int(input())
my_namespaces = {'global': {'variables': [], 'parent': None}}
for i in range(n):
    call, ns, arg = input().split()
    if call == 'add':
        add(ns, arg)
    elif call == 'create':
        create(ns, arg)
    elif call == 'get':
        print(get(ns, arg))

""" Вам дается последовательность целых чисел и вам нужно ее обработать и вывести на экран сумму первой пятерки чисел из этой последовательности,
затем сумму второй пятерки, и т. д.
Но последовательность не дается вам сразу целиком. С течением времени к вам поступают её последовательные части. 
Например, сначала первые три элемента, потом следующие шесть, потом следующие два и т. д.
Реализуйте класс Buffer, который будет накапливать в себе элементы последовательности и выводить сумму пятерок последовательных элементов по мере их накопления.
Одним из требований к классу является то, что он не должен хранить в себе больше элементов, чем ему действительно необходимо,
т. е. он не должен хранить элементы, которые уже вошли в пятерку, для которой была выведена сумма. """
        
class Buffer:
    def __init__(self):
        self.a = []

    def add(self, *a):
        self.a.extend(a)
        while len(self.a) >= 5:
            sum = 0
            for i in range(5):
                sum += self.a.pop(0)
            print(sum)

    def get_current_part(self):
        return self.a    
        
"""Вам дано описание наследования классов в следующем формате.
<имя класса 1> : <имя класса 2> <имя класса 3> ... <имя класса k>
Это означает, что класс 1 отнаследован от класса 2, класса 3, и т. д.

Или эквивалентно записи:
class Class1(Class2, Class3 ... ClassK):
    pass
    
Класс A является прямым предком класса B, если B отнаследован от A:
class B(A):
    pass

Класс A является предком класса B, если
A = B;
A - прямой предок B
существует такой класс C, что C - прямой предок B и A - предок C

Например:
class B(A):
    pass

class C(B):
    pass

# A -- предок С

Вам необходимо отвечать на запросы, является ли один класс предком другого класса

Важное примечание:
Создавать классы не требуется.
Мы просим вас промоделировать этот процесс, и понять существует ли путь от одного класса до другого.

Формат входных данных
В первой строке входных данных содержится целое число n - число классов.
В следующих n строках содержится описание наследования классов. В i-й строке указано от каких классов наследуется i-й класс. 
Обратите внимание, что класс может ни от кого не наследоваться. Гарантируется, что класс не наследуется сам от себя (прямо или косвенно), 
что класс не наследуется явно от одного класса более одного раза.

В следующей строке содержится число q - количество запросов.

В следующих q строках содержится описание запросов в формате <имя класса 1> <имя класса 2>.
Имя класса – строка, состоящая из символов латинского алфавита, длины не более 50.

Формат выходных данных
Для каждого запроса выведите в отдельной строке слово "Yes", если класс 1 является предком класса 2, и "No", если не является."""

def make_inheritance(inh):
    if len(inh) == 1:
        classes[inh[0]] = []
    elif len(inh) > 1:
        classes[inh[0]] = inh[2:]


def create_queue(parent, child, queue):
    global answer
    if parent == child:
        return True
    if child in classes:
        queue += classes[child]
        if parent in queue:
            return True
        if classes[child] == []:
            return False
    else:
        return False
    for parents_of_child in classes[child]:
        if answer:
            return answer
        answer = create_queue(parent, parents_of_child, queue)
    return answer


classes = {}
n = int(input())
for i in range(n):
    inheritance = input().split()
    make_inheritance(inheritance)
q = int(input())
for i in range(q):
    answer = False
    queue = []
    parent, child = input().split()
    if create_queue(parent, child, queue):
        print('Yes')
    else:
        print('No')