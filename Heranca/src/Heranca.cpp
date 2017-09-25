//============================================================================
// Name        : Heranca.cpp
// Author      : Hugo Marcondes
// Version     :
// Copyright   : No rights reserved!
// Description :
//============================================================================
#include <iostream>
using namespace std;

// Base class Shape
class Shape {
   public:
	  Shape(int w, int h){
		  width = w;
		  height = h;
	  }

	  void scale(int vx, int vy){
		  width += vx;
		  height += vy;
	  }

	  void scaleFactor(int factor){
		  width *= factor;
		  height *= factor;
	  }

   protected:
      int getWidth() { return width; }
      int getHeight() { return height; }

   private:
      int width;
      int height;
};

// Base class PaintCost
class PaintCost {
   public:
	  PaintCost(int cost): cost_per_m2(cost) {}

	  void updateCost(int cost) { cost_per_m2 = cost; }

	  int getCost() { return 0; }

      int getCost(int area) {
         return area * cost_per_m2;
      }

   private:
      int cost_per_m2;
};

// Derived class
class Rectangle: public Shape, public PaintCost {
   public:
	  Rectangle(): Shape(0,0), PaintCost(70) { }
	  Rectangle(int cost): Shape(0,0), PaintCost(70) { }
	  Rectangle(int w, int h): Shape(w,h), PaintCost(70) { }
	  Rectangle(int w, int h, int cost): Shape(w,h), PaintCost(cost) { }

	  int getArea() {
         return (getWidth() * getHeight());
      }

	  int getCost(){
		  return PaintCost::getCost(getArea());
	  }

	  //int getCost(int a){
	  //		  return PaintCost::getCost(a);
	  //}
};

int main(void)
{
   Rectangle Rect(5,7,100);
   int area;

   area = Rect.getArea();
   // Print the area of the object.
   cout << "Total area: " << Rect.getArea() << endl;

   // Print the total cost of painting
   cout << "Total paint cost: $" << Rect.getCost() << endl;

   Rect.updateCost(50);

   // Print the total cost of painting
   cout << "Total paint cost2: $" << Rect.getCost() << endl;

   return 0;
}
