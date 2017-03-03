template <class T>
class Point {
public:
  Point(T x, T y);
  T distance(Point<T> point);
  T x;
  T y;
};
