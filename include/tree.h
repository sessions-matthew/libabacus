#ifndef LIBABACUS_TREE_H
#define LIBABACUS_TREE_H

#include "result.h"
#include "vec.h"

/**
 * Enum to represent the variant of a tree node.
 */
enum libab_tree_variant_e {
    NONE,
    BASE,
    ID,
    NUM,
    OP,
    UNARY_OP,
    BLOCK,
    IF
};

/**
 * A tree node that has been parsed from the input tokens.
 */
struct libab_tree_s {
    /**
     * The variant of tree node.
     */
    enum libab_tree_variant_e variant;
    /**
     * The string value of this tree, if applicable.
     */
    char* string_value;
    /**
     * The int value of this tree, if applicable.
     */
    int int_value;
    /**
     * The children of this tree node. This vector
     * will not be initialized if this tree node
     * type does not usually have children.
     */
    vec children;

    /**
     * The line on which this tree starts.
     */
    size_t line;
    /**
     * The index in the string where this line begins.
     */
    size_t line_from;
    /**
     * The beginning in the string of this tree.
     */
    size_t from;
    /**
     * The index in the string of the next
     * thing that isn't part of this tree.
     */
    size_t to;
};

typedef enum libab_tree_variant_e libab_tree_variant;
typedef struct libab_tree_s libab_tree;

/**
 * Frees the given tree, using its
 * variant as a hint as to what
 * variables need to be freed.
 * @param tree the tree to free.
 */
void libab_tree_free(libab_tree* tree);
/**
 * Frees the given tree recursively,
 * deleting the children first and the moving on
 * to the parents. 
 * @param tree the tree to free.
 */
void libab_tree_free_recursive(libab_tree* tree);

#endif
