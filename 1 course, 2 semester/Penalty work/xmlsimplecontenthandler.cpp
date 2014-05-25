#include "xmlsimplecontenthandler.h"

bool XmlSimpleContentHandler::startElement(const QString &namespaceURI, const QString &localName,
				const QString &qName, const QXmlAttributes &atts) {

	if (qName == "item") {

		if (localAtts->count() != 0)
			return false;

		for (int i = 0; i < atts.count(); i++)
			localAtts->append(atts.qName(i), atts.uri(i), atts.localName(i), atts.value(i));

	} else {

		QXmlAttributes newAtts = atts;
		for (int i = 0; i < localAtts->count(); i++)
			newAtts.append(localAtts->qName(i), localAtts->uri(i), localAtts->localName(i), localAtts->value(i));
		localAtts->clear();

		WidgetTreeElement *newElement = new WidgetTreeElement(newAtts, qName);
		if (currentElement == nullptr) {
			if (localName != "ui")
				return false;
			widgetStruct->ui = newElement;
		}
		newElement->setParent(currentElement);

		currentElement = newElement;
	}

	return true;
}

bool XmlSimpleContentHandler::endElement(const QString &namespaceURI, const QString &localName,
				const QString &qName) {

	if (qName != "item")
		currentElement = currentElement->parent;

	return true;
}
