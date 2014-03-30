/**
 * @file mupdf-page.h
 * @brief class Page
 * @author xiangxw xiangxw5689@126.com
 * @date 2012-04-03
 */

#ifndef MUPDF_PAGE_H
#define MUPDF_PAGE_H

#include "mupdf-global.h"

class QImage;
class QString;
class QRect;
class QRectF;
class PagePrivate;

namespace MuPDF
{
class Page;
class Document;
class TextBox;

/**
 * @brief A document page.
 */
class MUPDF_QT_EXPORT Page
{
public:
	~Page();
	bool isValid() const;
	QImage renderImage() const;
	QRect size() const;
	void setTransparentRendering(bool enable);
	void setBackgroundColor(int r, int g, int b, int a = 255);
	void setTransform(float scaleX, float scaleY, float rotation = 0.0f);
	QString text(float x0, float y0, float x1, float y1) const;
	QList<TextBox *> textList() const;

private:
	Page(const Document &document, int index, float scaleX = 1.0f, float scaleY = 1.0f, float rotation = 0.0f);
	PagePrivate *d;

friend class Document;
};

/**
 * @brief Text Box.
 */
class MUPDF_QT_EXPORT TextBox
{
public:
	QRectF boundingBox() const;
	QRectF charBoundingBox() const;
	bool hasSpaceAfter() const;
	TextBox *nextWord() const;
	QString text() const;
	
private:
	TextBox(fz_span *span);

	fz_span *m_span;

friend class Page;
}

} // end namespace MuPDF

#endif // end MUPDF_PAGE_H
