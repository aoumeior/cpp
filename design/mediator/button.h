#pragma once
#include "widget.h"
class Button : public Widget
{

  public:
	Button(DialogDirector *);

	virtual void SetText(const char *text);
	virtual void HandleMouse(MouseEvent &event);
};