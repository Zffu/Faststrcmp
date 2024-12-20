/**
 * The main file of the lib.
 */

#ifndef FASTSTRCMP_H
#define FASTSTRCMP_H

/**
 * Compares the two string given. If they are both the same, return 0 if not return another number.
 */
int faststrcmp(char* string1, char* string2);

/**
 * Gets the "hash" of the string.
 */
long strhash(char* string);

#endif
