#ifndef MUPDF_OUTLINE_H
#define MUPDF_OUTLINE_H

class QString;

namespace MuPDF
{

class Outline;
class Link;
class OutlinePrivate;

/**
 * @brief A tree of the outline of a document (also known
 *        as table of contents).
 */
class Outline
{
public:
	~Outline();

	QString title() const;
	Link * link() const;
	Outline * next() const;
	Outline * down() const;

private:
	Outline(OutlinePrivate *outlinep) : d(outlinep) {}

	OutlinePrivate *d;

friend class Document;
};

}

#endif // end MUPDF_OUTLINE_H
