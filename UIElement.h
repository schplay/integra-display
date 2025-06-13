#ifndef UIElement_h
#define UIElement_h

#include <Arduino_GFX_Library.h>

class UIElement {
public:
    UIElement(int16_t x, int16_t y, int16_t w, int16_t h);
    virtual ~UIElement() {}
    virtual void draw(Arduino_Canvas* canvas) = 0;
    virtual bool handleTouch(int16_t x, int16_t y) { return false; }
    void setVisible(bool v);
    bool isVisible() const;
    bool contains(int16_t tx, int16_t ty) const;
protected:
    int16_t x, y, w, h;
    bool visible;
};

#endif