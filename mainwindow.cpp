#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTextStream>
#include <QFile>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	QStringList list;

	QFile file("C:/test/first_log.log");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;

	QTextStream in(&file);
	while (!in.atEnd()) {
		 list << in.readLine();
	}

	QStringListModel *first_model = new QStringListModel(list);

	ui->listView->setModel(first_model);

}

MainWindow::~MainWindow()
{
	delete ui;
}
