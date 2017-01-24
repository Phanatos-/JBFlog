#ifndef FILEMODEL_H
#define FILEMODEL_H

#include <QObject>
#include <QFile>
#include <QStringListModel>
#include <QAbstractItemView>

class FileModel : public QObject
{
	Q_OBJECT
public:
	explicit FileModel(QObject *parent = 0);
	explicit FileModel(QFile *fh, QObject *parent = 0);
	explicit FileModel(QStringListModel *m, QObject *parent = 0);
	explicit FileModel(QStringListModel *m, QFile *fh, QObject* parent);
	~FileModel();

	void setFileName(const QString& name);
	void setStringList(const QStringList& list);
	void associate(const QAbstractItemView& view);

signals:

public slots:

private:
	bool status;
	QFile *file;
	QStringListModel *model;

};

#endif // FILEMODEL_H
