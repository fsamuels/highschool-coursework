#ifndef _QUAD_H
#define _QUAD_H
// file name: quad.h  (the file on disk lists pre- and post-conditions)

class quadraticEquation {
public:
//--constructor (no default constructor for quadraticEquation)
  quadraticEquation(double initA, double initB, double initC); 
  // post: initialize coefficients of quadratic equation initA*x*x + initB + c
  
//--accessors  
  double root1() const;
  // pre: there is at least one real root: b*b-4*a*c >= 0.0 
  // post: returns one real root as  (-b+sqrt(b*b-4*a*c)) / (2*a)
  
  double root2() const;
  // pre: there is at least one real root: b*b-4*a*c >= 0.0 
  // post: returns one real root as  (-b+sqrt(b*b-4*a*c)) / (2*a)
  
  bool hasRealRoots() const;
  // post: returns true if an only if b*b-4*a*c >= 0.0, otherwise return false

  void display() const;
  // post: shows the quadratic equation like -1x^2 + 3x - 9.7
  //       when my_a == -1, my_b = 3, and my_c == -9.7

private:
  double my_a, my_b, my_c; // the three coefficients of the quadratic equation
};

#endif