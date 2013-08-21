#ifndef _ELLIPSECONTAINER_H_
#define _ELLIPSECONTAINER_H_

#include "agg_rendering_buffer.h"
#include "ellipsectrl.h"
#include <vector>
using namespace std;

class CEllipseContainer
{
  CEllipseContainer();


  ~CEllipseContainer();

  typedef vector<CEllipseCtrl* > EllipseVec;

  typedef EllipseVec::iterator EllipseIterator;
public:
  static CEllipseContainer& GetContainer();

  void AddEllipseCtrl(CEllipseCtrl *ctrl);

  void Render(agg::rendering_buffer &buffer);
private:
  EllipseVec m_vec;
};

#endif //_ELLIPSECONTAINER_H_