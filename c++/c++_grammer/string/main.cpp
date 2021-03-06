#include<iostream>
#include <cstring>      // 申明 strlen  strcpy

using namespace std;

// ref: https://blog.csdn.net/caoshangpa/article/details/51530482  https://blog.csdn.net/Dawn_sf/article/details/61922196(友元)

class String
{
    friend ostream& operator<<(ostream& os, const String& s);
public:
	String(const char *str = nullptr);  // 普通构造函数  
	String(String &other);    // 拷贝构造函数  
	~String(void);  // 析构函数  
	String & operator = (String &other);  // 赋值函数  
private:
	char *m_data;   // 用于保存字符串  
};

// 普通构造函数  
String::~String(void)  {
     cout << "Destructing"<< endl;
    if(m_data != nullptr)  {
        delete []m_data;
        m_data = nullptr;   //  为了避免产生野指针，将m_data赋为NULL
    }
}

// 普通构造函数  
String::String(const char *str)  {
    cout << "Construcing witth str []" << endl;
    if(str == nullptr)  {
        m_data = new char[1];
        m_data = '\0';  // 得分点：对空字符串自动申请存放结束标志'\0'的，因为 strlen 需要保证字符串是以 null 结束的
    } else  {
        m_data = new char[strlen(str) + 1];
        strcpy(m_data, str);
    }
}

/* // 拷贝构造函数
String::String(const String &other)  {
    cout << "Constructing" << endl;
    m_data = new char[strlen(other.m_data) + 1];
    strcpy(m_data, other.m_data);
} */

// 拷贝构造函数
String::String(String &other)  {
    cout << "Constructing with object" << endl;
    m_data = new char[1];       // 需要在 swap 前进行该操作，否则最后会存在内存释放问题？
    m_data = '\0';
    std::swap(m_data, other.m_data);
}


// 赋值函数  
/* String & String::operator = (const String &other)  {
    cout << "Operate = Function" << endl;
    if (this == &other)     //得分点：检查自赋值  
		return *this; 
	if (m_data)
	    delete[] m_data;    //得分点：释放原有的内存资源  
	int length = strlen(other.m_data);
	m_data = new char[length + 1];//加分点：对m_data加NULL判断  
	strcpy(m_data, other.m_data);
	return *this;//得分点：返回本对象的引用    
} */


// 赋值函数  
String & String::operator = ( String &other)  {
    cout << "Operate = Function with swap" << endl;
   std::swap(m_data, other.m_data);
   return *this;
}

/// 输出 
ostream& operator<<(ostream& os, const String& s)
{
	os << s.m_data;
	return os;
}

/// ! 当类中包括指针类成员变量时，一定要重载其拷贝构造函数、赋值函数和析构函数
int main()
{
String a("hello");//调用普通构造函数
String b("world");//调用普通构造函数
String c(a);//调用拷贝构造函数
cout <<  c << endl;;
c = b;//调用赋值函数
return 0;
}
