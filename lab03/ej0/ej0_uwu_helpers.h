#ifndef _EJ0__UWU_HELPERS_H
#define _EJ0__UWU_HELPERS_H


/*Takes an path to a file, two arrays, one for the indexes (type unsigned int) and another for the letters. Also
takes an max_size of the arrays. This function reads an input and writes the content of the arrays. */
unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size);

/*This function prints the words that become of the array.*/
void dump(char a[], unsigned int length) ;

/*This function sort the array lol*/
void sort_array(unsigned int indexes[], char letters[], char sorted[], unsigned int max_size);

#endif
