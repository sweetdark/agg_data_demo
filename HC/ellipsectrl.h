#ifndef _ELLIPSECTRL_H_
#define _ELLIPSECTRL_H_

#include "agg_ellipse.h"
#include "pointbasic.h"

class CEllipseCtrl : public agg::ellipse
{
public:
  CEllipseCtrl() : ellipse() 
  {
    m_base.m_x = 0.0;
    m_base.m_y = 0.0;
  }

  CEllipseCtrl(double x, double y, double rx, double ry, 
    unsigned num_steps=0, bool cw=false) : ellipse(x, y, rx, ry, num_steps, cw) 
  {
    m_base.m_x = x;
    m_base.m_y = y;
  }

  void init(double x, double y, double rx, double ry, 
    unsigned num_steps=0, bool cw=false);

  void approximation_scale(double scale);

  void rewind(unsigned path_id);

  unsigned vertex(double* x, double* y); 

  const CGeoPoint<double>& GetBase();
private:
  CGeoPoint<double> m_base;
};


#endif //_ELLIPSECTRL_H_

