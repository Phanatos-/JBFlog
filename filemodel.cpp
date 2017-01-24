#include "filemodel.h"
#include <QFile>
#include <QString>
#include <QStringList>
#include <QStringListModel>

FileModel::FileModel(QObject *parent) :
	QObject(parent)
{
	file = new QFile();
}

FileModel::FileModel(QFile* fh, QObject* parent) :
	QObject(parent), file(fh)
{

}

FileModel::FileModel(QStringListModel* m, QObject* parent) :
	QObject(parent), model(m)
{

}

FileModel::FileModel(QStringListModel* m ,QFile fh, QObject* parent) :
	QObject(parent), model(m), file(fh)
{

}

void FileModel::setFileName(const QString& name)
{
	file->setFileName(name);
}

void FileModel::setStringList(const QStringList& list){
	model->setStringList(list);
}

void FileModel::associate(const QAbstractItemView& view)
{
	view->setModel(model);
}

FileModel::~FileModel(){
	if(file) delete file;
	if(model) delete model;
}

