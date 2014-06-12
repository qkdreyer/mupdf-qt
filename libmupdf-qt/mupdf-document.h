#ifndef MUPDF_DOCUMENT_H
#define MUPDF_DOCUMENT_H

#include <QByteArray>

class QString;
class QDateTime;

class DocumentPrivate;
namespace MuPDF
{
class Document;
class Page;

Document * loadDocument(const QString &filePath);
Document * loadDocument(const QByteArray &bytes);

class Document
{
public:
	~Document();
	bool needsPassword() const;
	bool authPassword(const QString &password);
	int numPages() const;
	Page *page(int index) const;
	QString pdfVersion() const;
	QString title() const;
	QString author() const;
	QString subject() const;
	QString keywords() const;
	QString creator() const;
	QString producer() const;
	QDateTime creationDate() const;
	QDateTime modDate() const;
	void setTransparentRendering(bool enable);
	void setBackgroundColor(int r, int g, int b, int a = 255);

private:
	Document(const QString &filePath);
    Document(unsigned char* bytes, int len);
	// disable copy
	Document(const Document &);
	Document &operator=(const Document &);

	DocumentPrivate *d;

friend class Page;
friend Document *loadDocument(const QString &filePath);
friend Document *loadDocument(const QByteArray &bytes);
};

} // end namespace MuPDF

#endif // end MUPDF_DOCUMENT_H
