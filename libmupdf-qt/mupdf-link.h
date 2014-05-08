#ifndef MUPDF_LINK_H
#define MUPDF_LINK_H

#include <QRectF>

class LinkPrivate;

namespace MuPDF
{

class Link
{
public:
	enum LinkType
	{
		None = 0,
		Goto, ///< Goto a position in current file
		URI, ///< A URI link
		Launch,
		Named,
		GotoR ///< Goto a position in another file
	};

	virtual ~Link() {}

	virtual LinkType linkType() const {return None;}
	virtual QRectF linkArea() const;

protected:
	Link(LinkPrivate *linkp) : d(linkp) {}

	LinkPrivate *d;
};

class LinkGoto : public Link
{
public:
	LinkType linkType() const {return Goto;}
	int page() const;
	bool fitHorizontally() const;
	bool fitVertically() const;
	float zoom() const;

protected:
	LinkGoto(LinkPrivate *linkp) : Link(linkp) {}
};

class LinkURI : public Link
{
public:
	LinkType linkType() const {return URI;}
	QString uri() const;
	bool isMap() const;

private:
	LinkURI(LinkPrivate *linkp) : Link(linkp) {}
};

class LinkGotoR : public LinkGoto
{
public:
	LinkType linkType() const {return GotoR;}
	int page() const;
	QString destination() const;
	QString file() const;
	bool newWindow() const;

private:
	LinkGotoR(LinkPrivate *linkp) : LinkGoto(linkp) {}
};

}

#endif // end MUPDF_LINK_H
