//============================================================================
// Name        : Overloading.cpp
// Author      : Hugo Marcondes
// Version     :
// Copyright   : No rights reserved!
// Description : Slides examples of C++ Overloading functionality.
//    Based on examples from: (09/05/2016)
//    http://www.tutorialspoint.com/cplusplus/cpp_overloading.htm
//============================================================================
#include <iostream>
using namespace std;

class Box {
   public:
      Box(double len, double bre, double hei) {
         this->length = len;
         this->breadth = bre;
         this->height = hei;
      }
	  /*Box() {
	  	  this->length = 0;
	  	  this->breadth = 0;
	  	  this->height = 0;
	  }*/
      //Box(): length(0),breadth(0),height(0) {};
      Box(): Box(0,0,0) {}; //Valid only in C++11 (Delegated constructor)

      double getVolume(void) {
               return length * breadth * height;
      }

      // Overload + operator to add two Box objects.
      Box operator+(const Box& b) {
         Box box;
         box.length = this->length + b.length;
         box.breadth = this->breadth + b.breadth;
         box.height = this->height + b.height;
         return box;
      }

      friend ostream &operator<<( ostream &output, const Box& b ) {
    	 output << "Box(" << b.length << "," << b.breadth << "," << b.height << ")";
         return output;
      }

      friend istream &operator>>( istream  &input, Box &b ) {
         cout << "Length ? ";
         input >> b.length;
         cout << "Breadth ? ";
         input >> b.breadth;
         cout << "Height ? ";
         input >> b.height;
         return input;
      }

   private:
      double length;      // Length of a box
      double breadth;     // Breadth of a box
      double height;      // Height of a box
};

void binary_overload_example(){
	   Box Box1(6.0, 7.0, 5.0);
	   Box Box2(12.0, 13.0, 10.0);
	   Box Box3;

	   cout << "Volume of Box1 : " << Box1.getVolume() <<endl;
	   cout << "Volume of Box2 : " << Box2.getVolume() <<endl;
	   cout << "Volume of Box3 : " << Box3.getVolume() <<endl;

	   cout << "Box3 = Box1 + Box2" << endl;
	   Box3 = Box1 + Box2;

	   cout << "Volume of Box3 : " << Box3.getVolume() <<endl;
}

void stream_overload_example(){
	   cout << "Stream operator overloads." << endl;

	   Box Box1;
	   Box Box2;
	   Box Box3;

	   cout << "We have 3 null boxes: " << Box1 << ", " << Box2 << ", " << Box3 << endl;

	   cout << "Box1\n";
	   cin  >> Box1;
	   cout << "Box2\n";
	   cin  >> Box2;

	   cout << "Volume of " << Box1 << " " << Box1.getVolume() <<endl;
	   cout << "Volume of " << Box2 << " " << Box2.getVolume() <<endl;
	   cout << "Volume of " << Box3 << " " << Box3.getVolume() <<endl;

	   cout << "Box3 = Box1 + Box2" << endl;
	   Box3 = Box1 + Box2;

	   cout << "Volume of " << Box3 << " " << Box3.getVolume() <<endl;
}

int main() {
   binary_overload_example();
   stream_overload_example();

   return 0;
}
