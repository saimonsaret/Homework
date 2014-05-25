#pragma once
#include "widgettree.h"
#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

class FormCreationError {
	public:
		QString errorText;
};

class FormCreator {
	public:
		///Creates current object and all of it's subforms
		void createForm(WidgetTreeElement *element, QLayout *parent);

	private:
		///Creates current object
		QObject* createObject(WidgetTreeElement *element);
		///Cretes current object and creates links between parent layout and new object
		QObject* createSubform(WidgetTreeElement *currentElement, QLayout *parent);
};
