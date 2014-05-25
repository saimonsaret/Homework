#include "formcreator.h"

QObject* FormCreator::createObject(WidgetTreeElement *element) {

	QString name = element->name;
	QString type = element->atts.value(element->atts.index("type"));

	if (name == "layout") {

		if (type == "grid")
			return new QGridLayout;
		if (type == "vertical")
			return new QVBoxLayout;
		if (type == "horizontal")
			return new QHBoxLayout;

		FormCreationError error;
		error.errorText = "Layout type " + type + " is unknown";
		throw error;

	} else if (name == "widget") {

		QString text = "";
		if (element->atts.index("text") != -1)
			text = element->atts.value(element->atts.index("text"));

		if (type == "button") {
			QPushButton *newButton = new QPushButton;
			newButton->setText(text);
			return newButton;
		}
		if (type == "lineEdit") {
			QLineEdit *newLineEdit = new QLineEdit;
			newLineEdit->setText(text);
			return newLineEdit;
		}
		if (type == "label") {
			QLabel *newLabel = new QLabel;
			newLabel->setText(text);
			return newLabel;
		}
		FormCreationError error;
		error.errorText = "Widget type " + type + " is unknown";
		throw error;
	}
	FormCreationError error;
	error.errorText = "Object type " + name + " is unknown";
	throw error;
}

QObject* FormCreator::createSubform(WidgetTreeElement *currentElement, QLayout *parent) {

	QString name = currentElement->name;

	QString parentLayoutType = "";
	QString parentName = currentElement->parent->name;
	if (parentName != "ui")
		parentLayoutType = currentElement->parent->atts.value(currentElement->parent->atts.index("type"));

	int row = 0;
	if (currentElement->atts.index("row") != -1)
		row = currentElement->atts.value(currentElement->atts.index("row")).toInt();

	int col = 0;
	if (currentElement->atts.index("col") != -1)
		col = currentElement->atts.value(currentElement->atts.index("col")).toInt();


	if (parentLayoutType == "" || parentLayoutType == "grid") {
		QGridLayout *layout = dynamic_cast<QGridLayout*>(parent);

		QObject *newObject;
		try {
			newObject = createObject(currentElement);
		} catch (FormCreationError &error) {
			throw error;
		}

		if (name == "layout")
			layout->addLayout(dynamic_cast<QLayout*>(newObject), row, col);
		if (name == "widget")
			layout->addWidget(dynamic_cast<QWidget*>(newObject), row, col);

		return newObject;
	}

	if (parentLayoutType == "vertical") {
		QVBoxLayout *layout = dynamic_cast<QVBoxLayout*>(parent);

		QObject *newObject;
		try {
			newObject = createObject(currentElement);
		} catch (FormCreationError &error) {
			throw error;
		}
		if (name == "layout")
			layout->insertLayout(row, dynamic_cast<QLayout*>(newObject));
		if (name == "widget")
			layout->insertWidget(row, dynamic_cast<QWidget*>(newObject));

		return newObject;
	}

	if (parentLayoutType == "horizontal") {
		QHBoxLayout *layout = dynamic_cast<QHBoxLayout*>(parent);

		QObject *newObject;
		try {
			newObject = createObject(currentElement);
		} catch (FormCreationError &error) {
			throw error;
		}
		if (name == "layout")
			layout->insertLayout(col, dynamic_cast<QLayout*>(newObject));
		if (name == "widget")
			layout->insertWidget(col, dynamic_cast<QWidget*>(newObject));

		return newObject;
	}
	FormCreationError error;
	error.errorText = "Layout type " + parentLayoutType + " is unknown";
	throw error;
}

void FormCreator::createForm(WidgetTreeElement *element, QLayout *parent) {

	QObject *newObject;
	try {
		newObject = createSubform(element, parent);
	} catch (FormCreationError &error) {
		throw error;
	}

	for (int i = 0; i < element->children->size(); i++) {
		createForm(element->children->at(i), dynamic_cast<QLayout*>(newObject));
	}
}
