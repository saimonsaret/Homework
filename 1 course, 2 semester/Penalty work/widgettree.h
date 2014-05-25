#pragma once
#include <QXmlAttributes>
#include <QList>

class WidgetTreeElement {
	public:
		WidgetTreeElement(QXmlAttributes dataAtts, const QString &dataName) {
			atts = dataAtts;
			name = dataName;
			children = new QList<WidgetTreeElement*>;
		}

		~WidgetTreeElement() {
			for (int i = 0; i < children->size(); i++)
				delete children->at(i);
			delete children;
		}
		void setParent(WidgetTreeElement *element) {
			if (element != nullptr)
				element->children->append(this);
			parent = element;
		}
		///If it's a layout, contains all of the children objects; otherwise, it should be empyu
		QList<WidgetTreeElement*> *children;
		WidgetTreeElement *parent = nullptr;
		QXmlAttributes atts;
		QString name;
};

///Provides hierarchy structure of all widgets and layouts
class WidgetTree {
	public:
		~WidgetTree() {
			delete ui;
		}

		WidgetTreeElement *ui;
};
