#include <iostream>

class A {
public:
   A(int x) : x(x) {};
   ~A() {};

   virtual int getX() { 
      std::cout << "A::getX" << std::endl; 
      return x; 
   };

   //Function overloading
   void setX() { x=10; };
   void setX(int x) { this->x = x; };

   //Not allowed
   //float getX() { return 2.0; };

// private:

protected:
   int x;
};

class B : public A { 
public: 
   B() :  
      A(7), y(-1) {}; 
   B(int y): 
      A(50), y(y) {};  
   ~B() {}; 

   virtual int getX(){ 
      std::cout << "B::getX" << std::endl; 
      return x*2; 
   } 
   
   int getY(){return y;}; 
   // void setX(int newX){x = newX;} 

private: 
   int y; 
}; 

class C : public B{
public:
   C() : 
      B(7), z(-1) {};

   ~C() {};

   int getZ(){return z;};
   virtual int getX(){ 
      std::cout << "C::getX" << std::endl; 
      return A::getX(); 
   } 

private:
   int z;
};


int main(void) {

   A a(10);
   std::cout << a.getX() << std::endl;

   B b; 
   std::cout << b.getX() << std::endl; 

   C c; 
   std::cout << c.getX() << std::endl; 
   std::cout << c.getY() << std::endl; 
   std::cout << c.getZ() << std::endl; 


   return EXIT_SUCCESS;
}


// class C : public B{
// public:
//    C() : 
//       B(7), z(-1) {};

//    ~C() {};

//    int getZ(){return z;};
// private:
//    int z;
// };
