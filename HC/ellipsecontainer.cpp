#include "ellipsecontainer.h"
#include "agg_rendering_buffer.h"
#include "agg_renderer_base.h"
#include "agg_pixfmt_rgb.h"
#include "agg_rasterizer_scanline_aa.h"
#include "agg_scanline_u.h"
#include "agg_path_storage.h"
#include "agg_conv_stroke.h"
#include "agg_renderer_scanline.h"

CEllipseContainer::CEllipseContainer() {}

CEllipseContainer::~CEllipseContainer()
{
  for (EllipseIterator first = m_vec.begin(); first != m_vec.end(); ++first)
  {
    delete *first;
  }

  m_vec.clear();
}

CEllipseContainer& CEllipseContainer::GetContainer()
{
  static CEllipseContainer m_container;
  return m_container;
}

void CEllipseContainer::AddEllipseCtrl(CEllipseCtrl *ctrl)
{
  if (ctrl)
  {
    m_vec.push_back(ctrl);
  }
}

void CEllipseContainer::Render(agg::rendering_buffer &buffer)
{

  if (!m_vec.size())
  {
    return;
  }
  agg::pixfmt_bgr24 pixfmt(buffer);


  typedef agg::renderer_base<agg::pixfmt_bgr24> renbase;
  typedef agg::renderer_scanline_aa_solid<renbase> render_solid;

  renbase rbase(pixfmt);
  render_solid renderSolid(rbase);
  rbase.clear(agg::rgba8(255, 255, 255));

  agg::rasterizer_scanline_aa<> ras;

  for (EllipseIterator first = m_vec.begin(); first != m_vec.end(); ++first)
  {
    ras.add_path(*(*first));
  }

  agg::path_storage line;
  CEllipseCtrl *ell = m_vec[0];
  line.move_to(ell->GetBase().m_x, ell->GetBase().m_y);

  for(unsigned int i = 1; i < m_vec.size(); ++i)
  {
    ell = m_vec[i];
    line.line_to(ell->GetBase().m_x, ell->GetBase().m_y);
  }
  agg::conv_stroke<agg::path_storage> strokeLine(line);
  strokeLine.width(1.0);

  ras.add_path(strokeLine);

  renderSolid.color(agg::rgba8(255, 0, 0));

  agg::scanline_u8 sl;

  agg::render_scanlines(ras, sl, renderSolid);

}