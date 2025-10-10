/**
 * An abstract base class that requires derived classes
 to implement a clone method.
 * This is useful for implementing the Prototype design pattern.
 */
template <typename T> class Clone {
public:
  virtual T clone() const = 0; // Pure virtual function
  virtual ~Clone() = default;  // Virtual destructor
};
