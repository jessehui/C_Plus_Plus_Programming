# C++ 程序设计语言 Notes

<p align="right">---Reference: "The C++ programming Language"</p>

###1 Hello World
Example:
```C++
#include <iostream>

int main()
{
	std::cout << "Hellow World.\n"

}
```

###2 异常捕捉
使异常所造成的奇怪现象最小化的第一种方式用一个try块作为体

```C++
try{
	//code
}

catch (out_of_range){
	cerr << "Range Error\n";
}

catch (...){
	cerr << "Unknown exception thrown\n";
}
```

###3 迭代器 iterator
迭代器（iterator）是一种对象，它能够用来遍历标准模板库容器中的部分或全部元素，每个迭代器对象代表容器中的确定的地址。迭代器修改了常规指针的接口，所谓迭代器是一种概念上的抽象：那些行为上像迭代器的东西都可以叫做迭代器。然而迭代器有很多不同的能力，它可以把抽象容器和通用算法有机的统一起来。

迭代器提供一些基本操作符：*、++、==、!=、=。这些操作和C/C++“操作array元素”时的指针接口一致。不同之处在于，迭代器是个所谓的复杂的指针，具有遍历复杂数据结构的能力。其下层运行机制取决于其所遍历的数据结构。因此，每一种容器型都必须提供自己的迭代器。事实上每一种容器都将其迭代器以嵌套的方式定义于内部。因此各种迭代器的接口相同，型号却不同。这直接导出了泛型程序设计的概念：所有操作行为都使用相同接口，虽然它们的型别不同。


###4 类型
布尔类型（bool）,字符类型（char），整数类型(int), 放到一起称为整型（integral type）。
整型和浮点类型一起称为算术类型。
枚举和类称为用户定义类型，因为他们必须由用户定义出来，不能事先未声明而直接使用。
`int（c）`将给出字符c的整数值
整数类型（int）后缀U可以用于显示地写出unsigned文字量。后缀L可以用于明显的写出long文字量。例如 `int a = 3U`.
浮点类型： float单精度， double双精度， long double扩展精度


###5 枚举类型
enum是计算机编程语言中的一种数据类型。枚举类型：在实际问题中，有些变量的取值被限定在一个有限的范围内。例如，一个星期内只有七天，一年只有十二个月，一个班每周有六门课程等等。
在“枚举”类型的定义中列举出所有可能的取值，被说明为该“枚举”类型的变量取值不能超过定义的范围。应该说明的是，枚举类型是一种基本数据类型，而不是一种构造类型，因为它不能再分解为任何基本类型。
枚举符可以被赋值。按默认方式，枚举符所赋的值从0开始递增。
如果某个枚举中所有枚举值均非负，该枚举的表示范围就是0-(2^k-1),其中的2^k就是能使所有枚举符位于此范围内的最小的2次幂。如果存在负的枚举值，该枚举的取值范围就是[-2^k:2^k-1]。
一个整型值可以显式地转换到一个枚举值，除非这种转换的结果位于该枚举的范围之内，否则就是无定义的。
一个枚举的`sizeof()`就是能够容纳其范围的整型的sizeof。
一个枚举是一个用户定义的类型，所以用户可以为枚举定义它自身的操作.


###6 命名规则
用于较大的作用域的名族应该是相对比较长的更加明确的名字.然而如果在很小的作用域里只使用那些短小而熟悉的名字,如x,i,p等,代码会显得更清晰些.(类和名字空间可用来保持较小的作用域).
让那些频繁使用的名字相对比较短,将较长的名字保留给不常用的实体,这种做法也很有价值. 


###7 作用域解析运算符
`::`作用域解析运算符,就是当局部变量和全局变量名字重叠的时候，指定某变量一定是来自全局变量。


###8 typedef
为类型声明了一个新的名字,而不是声明一个指定类型的对象
```C++
typedef char* Pchar;
typedef unsigned char uchar;//原本较笨拙的类型名的缩写

typedef int int32;
typedef short int16;
//将对某个类型的直接引用限制到一个地方. 如果我们在所有可能需要较大的整数的地方都用int32, 那么就很容易将我们的程序移植到另一个sizeof(int)是2的机器上,因为只要在代码中重新定义
typedef long int32;

```

###9 指针
```C++
char** ppc;//到字符的指针的指针

int (*fp) (char*);//到函数的指针,以char*为参数
int* f(char*);//以char*为参数, 返回一个int类型的指针(int*)
```

没有任何对象被分配到地址0,因此0也被当做一个指针文字量, 表明一个指针当时并没有指向任何对象. C中流行的是用一个宏NULL表示0指针. C++取消了这一定义. 如果感到必须使用,可以重新定义:
`const int NULL = 0; `


###10 数组
数组元素的个数, 即数组的界,必须是一个常量表达式. 如果是需要变化的界,那么要用vector
Example:
```C++
void f(int i)
{
	int v1[i];//错误
	vector<int> v2(i);//可以使用
}
```


###11 字符串文字量
如果我们希望一个字符串保证能够被修改,那么就必须将有关的字符复制到数组里
```C++
void f()
{
 char p[] = "Zeno";
 p[0] = "R";//合法
}



void g()
{
	char* p = "Plato";
	p[4] = "e";//不合法
}
```
字符串文字量是静态分配的, 所以让函数返回他们是安全的.
```C++
const char* error_message(int i)
{
	//...
	//...
	return "Range Error";
}
```
在应用于指针时,==比较的是地址(指针的值),而不是被指的东西.
编译器将拼接器连续的字符串. 将空字符放到字符串里也是可能的, 但是大部分程序将不会去考虑在这个字符的后边还有其他字符. 举例来说,字符串"Jers\000Munk"将被各种标准库函数,例如strcpy()和strlen(),当做"Jers"看待.
带有前缀L的字符串,例如L"angst",是宽字符的字符串


###12 到数组的指针
```C++
int v[] = {1,2,3,4};
int* p1 = v;
int* p2 = &v[0]; 等价于上一句
int* p3 = &v[4];//合法
```
取得超出一个数组结束之后一个元素位置的指针是可以做到的. 但指针并不指向数组里的一个元素, 因此不能通过它去读或者写. 取得数组开始元素之前的元素地址是无定义的, 应该避免.
++对指针做增量操作,使其索引这个数组中的下一个字符.
将算术运算符+,-,++,--应用于指针的结果依赖于被指对象的类型.
复杂的指针算术通常并不必要,最好避免使用.


###13 指针和常量
讲一个指针的声明用const预先固定将使那个`对象`而不是使这个`指针`成为常量. 
要将`指针`本身而不是被指`对象`声明为常量,必须使用声明运算符*const, 而不能只用简单的const
```C++
char s[] = "Gorm";
char p[] = "whatever";

const char* pc = s;//指向常量(指向的东西是一个不能更改的常量)
pc[3] = 'g'; 	//错误, pc指向常量
pc = p; 		//可以,当p也为const常量

char *const cp = s;//常量指针(指向的东西不能变化,东西本身可以变)
cp[3] = 'a';		//可以
cp = p; 		//不可以, cp一定指向s

const char *const cpc = s;
cpc[3] = 'a';		//不可以
cpc = p;			//不可以

```
并没有`const*`声明符, 所以出现在*之前的const是作为基础类型的一部分.


###14 引用
一个引用就是某对象的另一个名字. 引用的主要用途是为了描述函数的参数和返回值. 特别是为了运算符的重载. 记法`X&`表示到X的引用.
```C++
int i = 1;
int& r = i;//r和i现在引用同一个int
int x = r; // x = 1
r = 2;	//i = 2
```
为了确保一个引用总能是某个东西的名字(总能约束到某个对象), 引用时必须要初始化.
Example:
```C++
int i = 1;
int& r1 = i;		//正确:有初始化
int& r2;			//错误

extern int& r3;		//正确:r3在别处初始化
```
对一个引用的初始化时与对它赋值完全不同的. 实际上根本没有能操作引用的运算符操作.
左值可以表示对象，即具有对应的可以由用户访问的存储单元.正因为如此，用于取得对象的指针的内建操作符&要求操作数是左值。
考虑:
```C++
double& dr = 1;			//错误, 要求建立一个具有正确值的临时变量
const double& cdr = 1;	//可以

//第二句也可以写成
double temp = double(1);
const double& cdr = temp;
```
在将引用作为函数参数进行传递时，实质上传递的是实参本身，即传递进来的不是实参的一个拷贝，因此对形参的修改其实是对实参的修改，所以在用引用进行参数传递时，不仅节约时间，而且可以节约空间。


###15 指向void的指针
一个指向任何对象类型的指针都可以赋值给类型为void*的变量. 要使用void*,就必须显式地将它转换到某个指向特定类型的指针.
C++中显式转换:
```C++
int* pi2 = static_cast<int*> (pv);//显式转换成int*
```
void*最重要的用途是需要向函数传递一个指针,而又不能对对象的类型做任何假设.
避免`void*`的使用,除了在某些低级底层的代码里.

###16 结构体struct
一个struct是任意类型元素的一个聚集. 例如:
```C++
struct address{
	char* name;
	long int number;
	char* street;
	char* town;
	char state[2];
	long zip;
};//这是C++里很少有的几处在花括号之后还需要写分号的地方
```
类型为address的变量可以像其他变量一样声明,其中的各个成员可以通过`.`运算符访问.
```C++
address jd;
jd.name = "Jim Dandy";
jd.number = 61;
```
结构体变量的引用和赋值，有两种形式，一种是用符号`.`，一种是用符号`->`。结构体指针变量一般用`->`，非结构体指针变量，也就是一般结构体变量，一般用`.`。
当p为指针时,`p->name`等价于`(*p).name`
```C++
void print_addr(address* p)
{
	cout << p->name << '\n'
	<< p->number << '\0' << p->street << '\n';
}
```
类型的名字在出现之后立即就可以使用了,不必等到看到完整的声明之后. 例如:
```C++
struct Link{
	Link* a;
	Link* b;
};//正确 内存大小可知

struct No_good{
	No_good member;//错误: 递归定义 内存大小未知
}
```
这种情况不经常出现, 可能在初始化自引用数据结构的时候偶然出现. 例如, 对于一个链接表结构,有时让它有一个包含指向自己的指针的卫兵节点将能方便使用.
两个结构总是不同的类型,即使它们有着相同的成员. 例如:
```C++
struct S1{
	int a;
};
Struct S2{
	int a;
}

S1 x;
S2 y = x; 	//错误,类型不匹配
```
每个struct都必须是在程序里唯一定义的.


###17 重载 Overload
函数重载是指在同一作用域内，可以有一组具有相同函数名，不同参数列表的函数，这组函数被称为重载函数。重载函数通常用来命名一组功能相似的函数，这样做减少了函数名的数量，避免了名字空间的污染，对于程序的可读性有很大的好处。例如:
```C++
int Add(int a, int b)
{
	return a+b;
}

double Add(double a, double b)
{
	return a+b;
}

int Add(int a, int b, int c)
{
	return a+b+c;
}
```
这些都是函数重载,它不受函数返回值的影响,只受参数类型和个数的影响.
除了函数重载,还有运算符重载. 由于一般数据类型间的运算符没有重载的必要，所以运算符重载主要是面向对象之间的. 后面会提到.

###18 构造函数
构造函数主要用来在创建对象时完成对对象属性的一些初始化等操作, 当创建对象时, 对象会自动调用它的构造函数。一般来说, 构造函数有以下三个方面的作用:
- 给创建的对象建立一个标识符
- 为对象数据成员开辟内存空间
- 完成对象数据成员的初始化

当用户没有显式的去定义构造函数时, 编译器会为类生成一个默认的构造函数, 称为 "默认构造函数", 默认构造函数不能完成对象数据成员的初始化, 只能给对象创建一标识符, 并为对象中的数据成员开辟一定的内存空间。
无论是用户自定义的构造函数还是默认构造函数都主要有以下特点:
- 在对象被创建时自动执行;
- 构造函数的函数名与类名相同;
- 没有返回值类型、也没有返回值;
- 构造函数不能被显式调用。

###19 析构函数
与构造函数相反, 析构函数实在对象被撤销时被自动调用,用于对成员撤销时的一些清理工作. 
析构函数函数名与类名相同,结贴在名称前用波浪号`~`与构造函数相区分. 
当用户没有显式定义析构函数时, 编译器同样会为对象生成一个默认的析构函数, 但默认生成的析构函数只能释放类的普通数据成员所占用的空间, 无法释放通过 new 或 malloc 进行申请的空间, 因此有时我们需要自己显式的定义析构函数对这些申请的空间进行释放, 避免造成内存泄露。
```C++
using namespace std

class Book
{
	public:
		Book( const char *name )	//构造函数(带参数的)
		{
			BookName = new char[strlen(name)+1];
			strcpy(BookName, name);
		}

		~Book()				//析构函数
		{
			cout << "析构函数被调用.\n";
			delete []BookName;	//释放通过new申请的空间
		}

	void showName()
	{
		cout << "Book Name :" << BookName << endl; 
	}

	private:
		char *Bookname;
}
``` 
Reference : [构造函数与析构函数](http://www.cnblogs.com/mr-wid/archive/2013/02/19/2917911.html)


###20 String
之所以抛弃`char*`的字符串而选用C++标准程序库中的`string`类，是因为他和前者比较起来，不必担心内存是否足够、字符串长度等等，而且作为一个类出现，他集成的操作函数足以完成我们大多数情况下(甚至是100%)的需要。我们可以用 = 进行赋值操作，== 
进行比较，+ 做串联.
尽可以把它看成是C++的基本数据类型.



###21 std::endl
`\n`是C语言风格的换行，C++具有这个是为了兼容C语言。
`endl`是标准的C++风格的换行。用`endl`时会刷新缓冲区，使得栈中的东西刷新一次，但用`\n`不会刷新，它只会换行，盏内数据没有变化。
 `cout << endl;` 等价于: `cout << '\n' << flush;`


###22 cin.get()用法
1. `cin.get(字符变量名)`用来接收字符
```C++
char ch;
ch = cin.get();		//或者cin.get(ch);
cout << ch << endl;
```
即使输入很多字符,只会输出第一个字符

2. `cin.get(字符数组名,接收字符个数)`用来接收一行字符串,可以接受空格
```C++
char a[20];
cin.get(a,20);
cout << a << endl;
```
如果输入超过20个字符, 只会输出19个字符(还有一个字符为`\0`).
`cin.getline()`也可以这样用,结果和`cin.get()`一样.

但是`cin.get()`和`cin.getline()`是有一定区别的. `cin.get()`每次读取一整行并把由`Enter`键生成的换行符留在输入队列中.
而`cin.getline()`每次读取一整行并把由`Enter`键生成的换行符抛弃. 
Example:
```C++
	char str3[30];
	cin.get(str3, 30);
	cout << str3 << endl;


	char str2[30];
	cin.getline(str2, 30);
	cout << str2 << endl;
```
这里第二次`getline`输入是无法输入的. 交换顺序就可以解决. 注意一点,如果读取的内容很少,比如`cin.get(str3,3)`,而本身输入很多, 那么只会读取`2`个字符(还有一个字符为`\0`)
这样的情况,不管顺序如何,第二个都不能正常输入.
注意:常用函数strlen不考虑作为结束标志的空字符.


###23 关于引用的问题
```C++
void f(char c)
{
	std::cout<< c << std:endl;
}

void g(char &c)
{
	std::cout<< c << std:endl;
}

void h(const char &c)
{
	std::cout<< c << std:endl;
}

int main()
{
	f(3);//合法
	g(3);//非法
	h(3);//危险: 临时对象
}
```
有些调用是非法的, 因为涉及到将一个右值(例如,一个临时对象或者一个文字量) 约束于一个非const的引用.
引用要求对象必须为左值. 


###24 运算符
* 作用域解析`class_name::member`; 全局`::name`
* 成员选择 `object.member`, `pointer->member`

运算符`,`,`&&(逻辑与)`,`||(逻辑或)`保证了位于它们左边的运算对象一定在右边运算对象之前求值. 例如`b = (a=2,a+1)`将把3赋给b.
`*p++`的意思是`*(p++)`而不是`(*p)++`

以0结尾的字符串可以用下列方式来复制:
```C++
void cpy(char* p, const char *p)
{
	while(*p++ = *q++);
}

char *strcpy(char*, const char*);//来自<string.h>

```
注:赋值表达式本身是有值的. 例如`x = 5` 这个




















