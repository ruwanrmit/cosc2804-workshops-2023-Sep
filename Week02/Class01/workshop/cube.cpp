class Cube{
public:

  Cube(int, int) : height(height), width(width) , depth(10) {};
  ~Cube(){};
  
  int height; int width; int depth;
};

Cube* foo(){
  Cube* cube3 = new Cube(5, 9);
  Cube cube4(1,2);
  
  return &cube4;
}

int main(){
  int a = 10;
  int *p = new int(0);
  
  Cube cube1(5,7);
  Cube* cube2 = new Cube(4, 7);
  
  Cube* cube_foo = foo();
  
  return 0;
}