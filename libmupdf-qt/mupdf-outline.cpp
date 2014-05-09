#include "mupdf-outline.h"
#include "mupdf-outline_p.h"
#include <QString>

namespace MuPDF
{

Outline::~Outline()
{
	if (d) {
		delete d;
	}
}

/**
 * @brief Title.
 */
QString Outline::title() const
{
	return d->outline->title;
}

/**
 * @brief Link.
 *
 * @note Do not delete the returned pointer. It will be
 *       deleted automatically when Outline is deleted.
 */
Link * Outline::link() const
{
	return d->link;
}

/**
 * @brief The next outline.
 *
 * @return NULL is returned if there is no next outline.
 *
 * @note Delete the returned pointer when it's useless.
 */
Outline * Outline::next() const
{
	fz_outline *outline = d->outline->next;

	if (outline) {
		return new Outline(new OutlinePrivate(d->documentp, outline));
	}

	return NULL;
}

/**
 * @brief The down outline.
 *
 * @return NULL is returned if there is no down outline.
 *
 * @note Delete the returned pointer when it's useless.
 */
Outline * Outline::down() const
{
	fz_outline *outline = d->outline->down;

	if (outline) {
		return new Outline(new OutlinePrivate(d->documentp, outline));
	}

	return NULL;
}

}
