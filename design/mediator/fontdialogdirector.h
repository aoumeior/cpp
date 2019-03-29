#pragma once

#include "dialogdirector.h"

class Button;
class ListBox;
class FontDialogDirector : public DialogDirector
{

  public:
	FontDialogDirector();
	virtual ~FontDialogDirector();

	virtual void WidgetChanged(Widget *) override;

  protected:
	virtual void CreateWidgets() override;

  private:
	Button *_ok;
	Button *_cancel;
	ListBox *_fontList;
};