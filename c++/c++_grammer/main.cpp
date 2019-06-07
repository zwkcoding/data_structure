#include "../include/base.h"

#define __tmain 
#ifdef __tmain
#define debug cout
#else
#define debug 0 && cout
#endif // __tmain

int main()
{

    std::string str = "HelloWorld!";     //初始化string类型，并具体赋值
    char* constc = nullptr;         //初始化const char*类型，并赋值为空
    constc= (char *)str.c_str();                 //string类型转const char*类型,再转化为 char*
    printf("%s\n", str.c_str());        //打印string类型数据 .c_str()
    printf("%s\n", constc);             //打印const char*类型数据
    return 0;



    // string str = "hello";
    // const char* p = str.data();
    // output(str);
    // debug << endl;
    // printf("%s\n",p); 
}
