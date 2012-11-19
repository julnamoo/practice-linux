#include "fluid_example.h"

Fl_Double_Window* make_window() {
  Fl_Double_Window* w;
  {
    Fl_Double_Window* o = new Fl_Double_Window(100, 100);
    w = o;
    o->end();
  }
  return w;
}
