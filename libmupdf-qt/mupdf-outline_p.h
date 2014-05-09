#ifndef MUPDF_OUTLINE_P_H
#define MUPDF_OUTLINE_P_H

#include "mupdf-link.h"
#include "mupdf-link_p.h"
#include "mupdf-document_p.h"
extern "C" {
#include <mupdf/fitz.h>
}

namespace MuPDF
{

class OutlinePrivate
{
public:
	/**
	 * @note Make sure outline o is valid.
	 *
	 * @param r If true, this is the root outline of the document tree.
	 */
	OutlinePrivate(DocumentPrivate *dp, fz_outline *o, bool r= false)
		: documentp(dp),
		  outline(o),
		  root(r)
	{
		LinkPrivate *linkp = new LinkPrivate(outline->dest);

		switch (outline->dest.kind) {
		case FZ_LINK_NONE:
			link = new MuPDF::Link(linkp);
			break;
			
		case FZ_LINK_GOTO:
			link = new MuPDF::LinkGoto(linkp);
			break;

		case FZ_LINK_URI:
			link = new MuPDF::LinkURI(linkp);
			break;

		case FZ_LINK_LAUNCH:
			link = new MuPDF::LinkLaunch(linkp);
			break;

		case FZ_LINK_NAMED:
			link = new MuPDF::LinkNamed(linkp);
			break;

		case FZ_LINK_GOTOR:
			link = new MuPDF::LinkGotoR(linkp);
			break;

		default:
			link = NULL;
			delete linkp;
			break;
		}
	}
	~OutlinePrivate()
	{
		if (root && outline) {
			fz_free_outline(documentp->context, outline);
			documentp->outlines.removeAt(documentp->outlines.indexOf(this));
		}
		delete link;
	}

	DocumentPrivate *documentp;
	fz_outline *outline;
	bool root;
	MuPDF::Link *link;
};

}

#endif // end MUPDF_OUTLINE_P_H
