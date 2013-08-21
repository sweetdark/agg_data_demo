#include "agg_rendering_buffer.h"
#include "agg_platform_support.h"
//#include "agg_ellipse.h"
#include "ellipsectrl.h"
#include "agg_renderer_base.h"
#include "agg_pixfmt_rgb.h"
#include "agg_rasterizer_scanline_aa.h"
#include "agg_scanline_u.h"
#include "agg_path_storage.h"
#include "agg_conv_stroke.h"
#include "ellipsecontainer.h"

class the_application : public agg::platform_support
{
public:

  the_application(agg::pix_format_e pixfmt, bool flip_y) : agg::platform_support(pixfmt, flip_y)
  {

  }
  virtual void on_draw()
  {
    agg::rendering_buffer buffer = this->rbuf_window();


    CEllipseCtrl *ell = new CEllipseCtrl(200, 200, 20, 20);

    CEllipseCtrl *ell2 = new CEllipseCtrl(300, 300, 30, 30);

    CEllipseContainer &container = CEllipseContainer::GetContainer();

    container.AddEllipseCtrl(ell);
    container.AddEllipseCtrl(ell2);
    container.Render(buffer);

  }
};

int agg_main(int argc, char* argv[])
{
  the_application app(agg::pix_format_bgr24, true);
  app.caption("Agg Example");
  if (app.init(480, 350, agg::window_resize))
  {
    return app.run();
  }

  return -1;
}