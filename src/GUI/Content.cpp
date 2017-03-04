#include "GUI/Content.h"

Content::Content(){
	mLineEdit = new QLineEdit();
	mText = new QTextEdit();
	mText->setReadOnly(true);

	mLayout = new QVBoxLayout();
	mLayout->addWidget(mText);
	mLayout->addWidget(mLineEdit);
	setLayout(mLayout);

	connect(mLineEdit, SIGNAL(returnPressed()), this, SLOT(lineTyped()));
}

// Public slots
void Content::lineTyped(){
	std::string str = std::string(mLineEdit->text().toStdString());
	mLineEdit->clear();
	emit input(str);
}
void Content::print(std::string str){
	mText->setPlainText(mText->toPlainText() + QString(str.c_str()) + QString("\n"));
	mText->moveCursor(QTextCursor::End);
}
