/* See LICENSE file for license and copyright information */

#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <gtk/gtk.h>
#include <girara/types.h>

#include "document.h"

#define LENGTH(x) (sizeof(x)/sizeof((x)[0]))

typedef struct page_offset_s
{
  int x;
  int y;
} page_offset_t;

/**
 * This function checks if the file has a valid extension. A extension is
 * evaluated as valid if it matches a supported filetype.
 *
 * @param zathura Zathura object
 * @param path The path to the file
 * @return true if the extension is valid, otherwise false
 */
bool file_valid_extension(zathura_t* zathura, const char* path);

/**
 * Generates the document index based upon the list retreived from the document
 * object.
 *
 * @param model The tree model
 * @param parent The tree iterator parent
 * @param tree The Tree iterator
 */
void document_index_build(GtkTreeModel* model, GtkTreeIter* parent, girara_tree_node_t* tree);

/**
 * Rotate a rectangle by 0, 90, 180 or 270 degree
 *
 * @param rectangle the rectangle to rotate
 * @param degree rotation degree
 * @param height the height of the enclosing rectangle
 * @param width the width of the enclosing rectangle
 * @return the rotated rectangle
 */
zathura_rectangle_t rotate_rectangle(zathura_rectangle_t rectangle, unsigned int degree, double height, double width);

/**
 * Calculates the new coordinates based on the rotation and scale level of the
 * document for the given rectangle
 *
 * @param page Page where the rectangle should be
 * @param rectangle The rectangle
 * @return New rectangle
 */
zathura_rectangle_t recalc_rectangle(zathura_page_t* page, zathura_rectangle_t rectangle);

/**
 * Returns the page widget of the page
 *
 * @param zathura The zathura instance
 * @param page The page object
 * @return The page widget of the page
 * @return NULL if an error occured
 */
GtkWidget* zathura_page_get_widget(zathura_t* zathura, zathura_page_t* page);

/**
 * Set if the search results should be drawn or not
 *
 * @param zathura Zathura instance
 * @param value true if they should be drawn, otherwise false
 */
void document_draw_search_results(zathura_t* zathura, bool value);

/**
 * Create zathura version string
 *
 * @param zathura The zathura instance
 * @param markup Enable markup
 * @return Version string
 */
char* zathura_get_version_string(zathura_t* zathura, bool markup);

/**
 * Replaces all occurences of \ref old in \ref string with \ref new and returns
 * a new allocated string
 *
 * @param string The original string
 * @param old String to replace
 * @param new Replacement string
 *
 * @return new allocated string
 */
char* replace_substring(const char* string, const char* old, const char* new);

/**
 * Get a pointer to the GdkAtom of the current clipboard.
 *
 * @param zathura The zathura instance
 *
 * @return A pointer to a GdkAtom object correspoinding to the current
 * clipboard, or NULL.
 */
GdkAtom* get_selection(zathura_t* zathura);

#endif // UTILS_H
