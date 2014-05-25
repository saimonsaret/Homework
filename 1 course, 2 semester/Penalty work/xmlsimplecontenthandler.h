#pragma once
#include <QtXml>
#include <QXmlDefaultHandler>
#include <QtWidgets>
#include <QXmlAttributes>
#include <iostream>
#include "widgettree.h"

///Content handler class, which is used for parsing XML-file and creating WidgetTree
class XmlSimpleContentHandler : public QXmlDefaultHandler {

	public:

		XmlSimpleContentHandler() {
			widgetStruct = new WidgetTree;
			widgetStruct->ui = nullptr;
			localAtts = new QXmlAttributes;
		}

		~XmlSimpleContentHandler() {
			delete widgetStruct;
			delete localAtts;
		}

		bool startElement(const QString &namespaceURI, const QString &localName,
						const QString &qName, const QXmlAttributes &atts);

		bool endElement(const QString &namespaceURI, const QString &localName,
						const QString &qName);

		WidgetTree *widgetStruct;

	private:
		WidgetTreeElement *currentElement = nullptr;
		QXmlAttributes *localAtts = nullptr;
};
