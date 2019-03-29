#include "fontdialogdirector.h"
#include "button.h"
#include "listbox.h"
#include "widget.h"

FontDialogDirector::FontDialogDirector()
{

	_ok = new Button(this);
	_cancel = new Button(this);
	_fontList = new ListBox(this);
}

FontDialogDirector::~FontDialogDirector()
{
}

void FontDialogDirector::WidgetChanged(Widget *theChangedWidgets)
{

	if (theChangedWidgets == _fontList)
	{

		_fontName->SetText(_fontList->GetSelection());
	}
	else

		if (theChangedWidgets == _ok)
	{
	}
	else

		if (theChangedWidgets == _cancel)
	{
	}
}
