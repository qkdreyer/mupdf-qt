#ifndef MUPDF_LINK_P_H
#define MUPDF_LINK_P_H

extern "C" {
#include <mupdf/fitz.h>
}

class LinkPrivate
{
public:
	LinkPrivate(fz_link *l) : link(l) {}

	fz_link *link;
};

#endif // end MUPDF_LINK_P_H
