#include "turret_q8.h"

Turret_Q8::Turret_Q8(QWidget *parent) : ClickableLabel(parent) {
    setStyleSheet("background-color: red;");
    setText("Label 1");
}
