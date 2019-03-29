#pragma once

class DialogDirector;
class MouseEvent;

class Widget
{

  public:
	Widget(DialogDirector *){};
	virtual void Changed();

	virtual void HandleMouse(MouseEvent &event);

  private:
	DialogDirector *_dorector;
};
