#include "ellipsectrl.h"



void CEllipseCtrl::init(double x, double y, double rx, double ry, 
          unsigned num_steps, bool cw)
{
  ellipse::init(x, y, rx, ry, num_steps, cw);
  m_base.m_x = x;
  m_base.m_y = y;
}

void CEllipseCtrl::approximation_scale(double scale)
{
  ellipse::approximation_scale(scale);
}

void CEllipseCtrl::rewind(unsigned path_id)
{
  ellipse::rewind(path_id);
}

unsigned CEllipseCtrl::vertex(double* x, double* y)
{
  return ellipse::vertex(x, y);
}

const CGeoPoint<double>& CEllipseCtrl::GetBase()
{
  return m_base;
}