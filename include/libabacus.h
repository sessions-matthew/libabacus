#ifndef LIBABACUS_H
#define LIBABACUS_H

#include "ht.h"
#include "lexer.h"
#include "table.h"
#include "parser.h"
#include "result.h"
#include "custom.h"

/**
 * The main struct of libabacus,
 * which essentially holds all the informatiom
 * for the library's state and operation.
 */
struct libab_s {
    /**
     * The lexer used to convert a string
     * to tokens.
     */
    libab_lexer lexer;
    /**
     * The parser used to convert
     * tokens to a tree.
     */
    libab_parser parser;
    /**
     * The table used to store top-level
     * things like functions and operators.
     */
    libab_table table;
};

typedef struct libab_s libab;

/**
 * Initializes the libabacus struct as well
 * as all its internal structures such as the lexer.
 * @param ab the libabacus instance used to keep state.
 * @return the result of the initialization.
 */
libab_result libab_init(libab* ab);
/**
 * Registers an operator with libabacus.
 * @param ab the libabacus instance to reigster the operator with.
 * @param op the operator string to register.
 * @param precedence the precedence of the operator.
 * @param associativity the associativity of the operator.
 * @param type the type of this operator.
 * @param func the function that describes the functionality of the operator.
 * @return the result of the initialization.
 */
libab_result libab_register_operator_infix(libab* ab, const char* op, int precedence, int associativity, libab_ref* type, libab_function_ptr func);
/**
 * Registers an operation with libabacus that appears
 * before its operand.
 * @param ab the libabacus instance to register the operator with.
 * @param op the operator string to register.
 * @param type the type of this operator.
 * @param func the function that describes the functionality of the operator.
 * @return the result of the registration.
 */
libab_result libab_register_operator_prefix(libab* ab, const char* op, libab_ref* type, libab_function_ptr func);
/**
 * Registers an operation with libabacus that appears
 * after its operand.
 * @param ab the libabacus instance to register the operator with.
 * @param op the operator string to register.
 * @param type the type of this operator.
 * @param func the function that describes the functionality of the operator.
 * @return the result of the registration.
 */
libab_result libab_register_operator_postfix(libab* ab, const char* op, libab_ref* type, libab_function_ptr func);

/**
 * Registers a function with libabacus.
 * @param ab the libabacus instance used to keep state.
 * @param name the name of the function.
 * @param type the type of this operator.
 * @param func the function that describes the functionality of the function.
 * @return the result of the registration.
 */
libab_result libab_register_function(libab* ab, const char* name, libab_ref* type, libab_function_ptr func);
/**
 * Registers a base type with abacus.
 * @param ab the libabacus instance used to keep state.
 * @param name the name to register the basetype under.
 * @param basetype the basetype to register.
 * @return the result of the registration.
 */
libab_result libab_register_basetype(libab* ab, const char* name, libab_basetype* basetype);
/**
 * Constructs and resolves a parse type, similarly to how it's done in the
 * parser.
 * @param ab the libab instance to use for constructing the type.
 * @param into the reference to populate with the given type.
 * @param type the type to parse.
 * @return the result of the operation.
 */
libab_result libab_create_type(libab* ab, libab_ref* into, const char* type);
/**
 * Releases all the resources allocated by libabacus.
 * @param ab the libabacus instance to release.
 * @return the result of the initialization.
 */
libab_result libab_free(libab* ab);

#endif
