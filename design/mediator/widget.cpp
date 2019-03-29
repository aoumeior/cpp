#include "widget.h"
#include "dialogdirector.h"

void Widget::Changed()
{

	_dorector->WidgetChanged(this);
}

void Widget::HandleMouse(MouseEvent &event)
{
}
