// Copyright (c) 2002 Utrecht University
//
// This file is part of an example program for CGAL. This example
// program may be used, distributed and modified without limitation.

struct Point {
  double vec[3];

  Point() { vec[0]= vec[1] = vec[2] = 0; }
  Point (double x, double y, double z) { vec[0]=x; vec[1]=y; vec[2]=z;  }
 
  double x() const { return vec[ 0 ]; }
  double y() const { return vec[ 1 ]; }
  double z() const { return vec[ 2 ]; }

  double& x() { return vec[ 0 ]; }
  double& y() { return vec[ 1 ]; }
  double& z() { return vec[ 2 ]; }
  
  bool operator==(const Point& p) const 
  {
    return (x() == p.x()) && (y() == p.y()) && (z() == p.z())  ;
  }

  bool  operator!=(const Point& p) const { return ! (*this == p); }
}; //end of class



namespace CGAL {

  template <>
  struct Kernel_traits<Point> {
    struct Kernel {
      typedef double FT;
      typedef double RT;
    };
  };
}


struct Construct_coord_iterator {
  const double* operator()(const Point& p) 
  { return static_cast<const double*>(p.vec); }

  const double* operator()(const Point& p, int) 
  { return static_cast<const double*>(p.vec+3); }
};
