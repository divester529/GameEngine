#ifndef RENDERER_H_INCLUDED
#define RENDERER_H_INCLUDED

namespace renderer
{
  class Renderer{
  public:
    Renderer();
    ~Renderer();

    void render();
  private:
    Camera* camera;
  };

}

#endif // RENDERER_H_INCLUDED
