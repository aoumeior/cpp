#pragma once
#include "widget.h"
#include <list>

class ListBox : public Widget
{

  public:
	ListBox(DialogDirector *);
	virtual const char *GetSelection();
	virtual void SetList(std::list<char *> *);
	virtual void HandleMouse(MouseEvent &event);
};