#ifndef CONTENT
#define CONTENT

// Qt includes
#include <QWidget>
#include <QMenuBar>
#include <QShortcut>
#include <QApplication>
#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>

// std includes
#include <map>
#include <iostream>

class Content : public QWidget {
	Q_OBJECT
public:
	Content();
private:
	QLineEdit* mLineEdit;
	QTextEdit* mText;
	QVBoxLayout* mLayout;
public slots:
	void lineTyped();
	void print(std::string);
signals:
	void input(std::string);
};

#endif // CONTENT
