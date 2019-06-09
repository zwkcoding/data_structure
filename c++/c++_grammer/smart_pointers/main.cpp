#include "../../include/base.h"

#include  <memory> // We need to include this for shared_ptr

#define __tmain 
#ifdef __tmain
#define debug cout
#else
#define debug 0 && cout
#endif // __tmain
 
// #define __auto_ptr
// #define __unique_ptr
// #define __shared_ptr
#define __weak_ptr
class A 
{ 
public: 
    A() : a(3) {}
    void show() {  cout << "A::show()" << endl; } 
    int a;
}; 

int main()
{

#ifdef __auto_ptr
    /**************************************************************/
    /*************************auto_ptr usage*************************/
    /**************************************************************/
    /// only one auto_ptr object can own the pointer at any given time
    /// i.e. auto_ptr should not be used where copy semantics are needed.


    // p1 is an auto_ptr of type A 
    auto_ptr<A> p1(new A); 
    p1 -> show(); 
  
    // returns the memory address of p1 
    cout << p1.get() << endl; 
  
    // copy constructor called, this makes p1 empty. 
    auto_ptr <A> p2(p1); 
    p2 -> show(); 
  
    // p1 is empty now 
    cout << p1.get() << endl; 
  
    // p1 gets copied in p2 
    cout<< p2.get() << endl; 
  
    return 0; 
#endif

 #ifdef __unique_ptr
    /**************************************************************/
    /*************************unique_ptr usage*************************/
    /**************************************************************/
    /// Use unique_ptr when you want to have single ownership(Exclusive) of resource. 

    unique_ptr<A> p1 (new A); 
    p1 -> show(); 
  
    // returns the memory address of p1 
    cout << p1.get() << endl; 
  
    // transfers ownership to p2 
     // unique_ptr<A> ptr2 = ptr1;   // Error: can't copy unique_ptr 
    unique_ptr<A> p2 = move(p1); 
    p2 -> show(); 
    cout << p1.get() << endl; 
    cout << p2.get() << endl; 
#endif

 #ifdef __shared_ptr0
    /**************************************************************/
    /*************************shared_ptr usage*************************/
    /**************************************************************/
    /// we should use shared_ptr when we want to assign one raw pointer to multiple owners.. 
   
    // shared_ptr<A> p1 (new A); 
    // cout << p1.get() << endl; 
    // p1->show(); 
    // shared_ptr<A> p2 (p1); 
    // p2->show(); 
    // cout << p1.get() << endl; 
    // cout << p2.get() << endl; 
  
    // // Returns the number of shared_ptr objects 
    // // referring to the same managed object. 
    // cout << p1.use_count() << endl; 
    // cout << p2.use_count() << endl; 
  
    // // Relinquishes ownership of p1 on the object 
    // //and pointer becomes NULL 
    // p1.reset(); 
    // cout << p1.get() << endl; 
    // cout << p2.use_count() << endl; 
    // cout << p2.get() << endl; 
  
    // shared_ptr<A>p3 = p2;
    // cout << p2.use_count() << endl; 
    // cout << p3.use_count() << endl; 
    // cout << p3.get() << endl; 
    // return 0; 

    shared_ptr<int>p1(new int(3));//智能指针的对象该指针指向一块内存a
    cout << p1.get() << endl;
	cout << p1.use_count() << endl;
	shared_ptr<int>p2(p1);//又有一个智能指针指向这个内存a
    cout << p2.get() << endl;
    cout << p1.use_count() << endl;
    cout << p2.use_count() << endl;
	shared_ptr<int>p3 = p1;//又有一个智能指针指向这个内存a
    cout << p3.get() << endl;
    cout << p1.use_count() << endl;
	shared_ptr<int>p4 = p1;//又有一个指针指针指向这个内存a
    cout << p4.get() << endl;
    cout << p1.use_count() << endl;

	/// 到这里内存a的引用计数为 4

	shared_ptr<int>p5(new int(5));//一个智能指针指向内存b
	p2.reset(/*p5.get()*/);//原先p2指向的是内存a，使用reset(p5.get())后，对p2进行重置，使p2指向内存b。
						//此时指向a内存的引用计数-1变为3，指向b内存的引用计数+1变为2；
    cout << p2.use_count() << endl;
    cout << p5.use_count() << endl;
    return 0;   
#endif

 #ifdef __shared_ptr
    // ref1: https://thispointer.com/learning-shared_ptr-part-1-usage-details/
    // ref2: https://docs.microsoft.com/en-us/cpp/cpp/how-to-create-and-use-shared-ptr-instances?view=vs-2019
    // Creating a shared_ptr through make_shared
	std::shared_ptr<int> p1 = std::make_shared<int>();
	*p1 = 78;
	std::cout << "p1 = " << *p1 << std::endl;
 
	// Shows the reference count
	std::cout << "p1 Reference count = " << p1.use_count() << std::endl;
 
	// Second shared_ptr object will also point to same pointer internally
	// It will make the reference count to 2.
	std::shared_ptr<int> p2(p1);
 
	// Shows the reference count
	std::cout << "p2 Reference count = " << p2.use_count() << std::endl;
	std::cout << "p1 Reference count = " << p1.use_count() << std::endl;
 
	// Comparing smart pointers
	if (p1 == p2)
	{
		std::cout << "p1 and p2 are pointing to same pointer\n";
	}
 
	std::cout<<"Reset p1 "<<std::endl;
 
	p1.reset();
 
	// Reset the shared_ptr, in this case it will not point to any Pointer internally
	// hence its reference count will become 0.
 
	std::cout << "p1 Reference Count = " << p1.use_count() << std::endl;
 
	// Reset the shared_ptr, in this case it will point to a new Pointer internally
	// hence its reference count will become 1.
 
	p1.reset(new int(11));
 
	std::cout << "p1  Reference Count = " << p1.use_count() << std::endl;
 
	// Assigning nullptr will de-attach the associated pointer and make it to point null
	p1 = nullptr;
 
	std::cout << "p1  Reference Count = " << p1.use_count() << std::endl;
 
	if (!p1)
	{
		std::cout << "p1 is NULL" << std::endl;
	}
	return 0;
 #endif


 #ifdef __weak_ptr
    /**************************************************************/
    /*************************weak_ptr usage*************************/
    /**************************************************************/
    /// When you do want to refer to your object from multiple places , 
    /// they’ll just note the object is gone when you try to dereference

    shared_ptr<A> sp(new A());//指向该资源的引用计数为1
    weak_ptr<A> wp(sp);
    // sp.reset();
 
    if (shared_ptr<A> pa = wp.lock())//使用weak_ptr中的lock成员函数来判断与weak_ptr关联的shared_ptr是否释放了资源
    {                                //如果释放，返回的一个"空"shared_ptr
        cout << pa->a << endl;
    }
    else
    {
        cout << "wp指向对象为空" << endl;
    }

   
#endif
}
