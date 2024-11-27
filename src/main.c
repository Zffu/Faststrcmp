/**
 * The main file of the lib.
 */

/**
 * Compares the two string given. If they are both the same, return 0 if not return another number.
 */
int faststrcmp(char* string1, char* string2) {
	return ((long*)string1) - ((long*)string2);
}
