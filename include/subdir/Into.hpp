/**
 * An abstract base class that requires derived classes
 * to implement a clone method.
 * This is useful for implementing the Prototype design pattern.
 */
template <typename T> class Into {
public:
  virtual T into() && = 0;
  virtual ~Into() = default;
};
