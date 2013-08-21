#ifndef _POINTBASIC_H_
#define _POINTBASIC_H_

const static double INVALIDCOORD = -1.;

template<typename T>
struct CGeoPoint
{
  // Only two dimensions
  T m_x;
  T m_y;

  //
  // Constructors and deconstructor
  //
  /**
  * \brief Default constructor with NAN, not a number, initialization.
  *
  * Note: 
  * 1) If passed by self-defined data type, it must have copy constructor being responsible for
  * converting doulbe to it.
  * 2) Since we adopt UEZERO as invalid point which makes sense when not initialized before being used, 
  * we had better notice the assertion happen before correctly using one geometry.
  */
  CGeoPoint() : m_x(static_cast<T>(INVALIDCOORD)), m_y(static_cast<T>(INVALIDCOORD))
  {
  }

  /**
  * \brief Default constructor with specified value.
  *
  * Note: If passed by self-defined data type, it must have copy constructor
  */
  CGeoPoint(const T &x, const T &y) : m_x(x), m_y(y)
  {
  }

  /**
  * \brief Copy constructor.
  */
  CGeoPoint(const CGeoPoint &other)
  {
    m_x = other.m_x;
    m_y = other.m_y;
  }

  /**
  * \brief Deconstructor.
  *
  * Since we want to take it as inner built-in type, it no need to inherit children and
  * virtual constructor may cause different behavior when against different compilers
  */
  ~CGeoPoint()
  {
  }

  //
  // Useful overloaded operators
  //
  /**
  * \brief Whether it is meaningful.
  *
  * Note: 
  * 1) For different C++ compilers, it should check the basic definition about NAN. For example, VC specify
  * behaviors of one NAN as below:
  *
  *   If x is NAN and y is not NAN: 
  *   (x != x) == true
  *	(x == x) == false
  *	(y > x) == false
  *	(y < x) == false
  * 2) However, above description only make sense when T is DOUBLE type:)
  */
  bool IsValid() const
  {
    return !(m_x == m_y && m_x == static_cast<T>(INVALIDCOORD));
  }

  /**
  * \brief Overload assignment operator.
  *
  * Note: If the member variable is self-defined type, it must overload assignement operator also.
  */
  const CGeoPoint &operator = (const CGeoPoint &other)
  {
    if(this == &other)
    {
      return *this;
    }

    m_x = other.m_x;
    m_y = other.m_y;

    return *this;
  }

  /**
  * \brief Overload bool operator.
  */
  bool operator == (const CGeoPoint &other) const
  {
    //assert(IsValid());
    return (m_x == other.m_x && m_y == other.m_y);
  }

  /**
  * \brief Overload not bool operator.
  */
  bool operator != (const CGeoPoint &other) const
  {
    //assert(IsValid());
    return (m_x != other.m_x || m_y != other.m_y);
  }
};

#endif //_POINTBASIC_H_