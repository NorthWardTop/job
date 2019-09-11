#include <iostream>
#include <vector>
#include <list>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <string.h>

using namespace std;

class A
{
public:
 void FuncA()
 {
     printf( "FuncA called\n" );
 }
 virtual void FuncB()
 {
     printf( "FuncB called\n" );
 }
};
class B : public A
{
public:
 void FuncA()
 {
     A::FuncA();
     printf( "FuncAB called\n" );
 }
 virtual void FuncB()
 {
     printf( "FuncBB called\n" );
 }
};
void main( void )
{
 B  b;
 A  *pa;
 pa = &b;
 A *pa2 = new A;
 pa->FuncA(); 
 pa->FuncB(); 
 pa2->FuncA();
 pa2->FuncB();
 delete pa2;
 
}
