#include "gui/gui.h"

int main() {
    if (!GUI::setup())
        return -1;
    GUI::draw();
}