以上文件夹包含了对各智能指针的简单实现，并展示了Weak_ptr的环状引用问题

1. boost提供的scoped_ptr不可以复制和赋值，是一种最简单的智能指针。  

2. C++98的auto_ptr提供了复制和赋值，但是采取的策略是控制权转移，这是一种糟糕的设计。   

3. C++11提供了unique_ptr，禁止了复制和赋值能力，但是拥有移动构造能力和移动赋值。   
   
   a) unique_ptr可以取代scoped_ptr，因为保留了scoped_ptr的全部能力，         
      同时移动构造使得它可以放入容器，没有带来额外的缺点。
   
   b) 在C++11中，容器内的元素如果不具备复制和赋值能力，就必须具备移动能力。         
      如果二者都不具备，可以使用unique_ptr作为中介。 

4. C++11和boost提供了引用计数型的智能指针，shared_ptr。    
   
5. Shared_ptr使用不当会造成内存泄露，原因可能是两个堆上的对象相互引用，      
   所以引用计数始终为1，造成一个环状结构，找不到对象delete的时机。   
   解决方案是采用弱引用：weak_ptr。

6. weak_ptr要与shared_ptr配合使用，它只指向对象地址，但是不参与引用计数，是一种弱引用。  

7. 拓展阅读：http://www.cnblogs.com/Solstice/archive/2011/08/16/2141515.html

8. C++11最有益的特性：
   a) 右值引用（rvalue reference）、转移语义（move semantics）     
   b) function /bind      
   c) 智能指针     
   d) lamdba表达式   

9. 对于引用计数型智能指针，绝对不可以这样使用（会造成两套计数系统）：     
   CounterPtr<Test> ptr2(ptr.get());
   
   甚至这样的使用也是不推荐的（因为可以在外部delete pt，容易造成错误）：          
   Test *pt = new Test;      
   CounterPtr<Test> ptr1(pt);     
   
   规范的用法应该是：
   CounterPtr<Test> ptr1(new Test);         
   或者：    
   CounterPtr<Test> make_ptr()    
   {
       return CounterPtr(new Test);      
   }      
   CounterPtr<Test> ptr1(make_ptr());  

10. c++11中使用智能指针加上头文件 #include<memory>    
