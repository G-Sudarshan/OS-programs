//Program for implementation of opendir() and readdir()

//Github link : https://github.com/G-Sudarshan/

// 16 07 2019

// first practical program [ for GP Nashik CM Department ]


#include <stdio.h>
#include <dirent.h> // Required header file for opendir() and readdir() functions

int main()
{
	struct dirent *dp; // Through this we will perform all functions . It is like an object, But it is actually a pointer.

	DIR *dr = opendir("C:/Program Files/");

	/* Here you can give any location and it will be stored This statement of
       opendir() returns pointer of DIR type.
	   Don't use backward slash'\' while writing location it may result in error because
	   compiler consider it escape sequence like \n */

	if (dr == NULL) // if location you entered do exist then  opendir() will return NULL
	{
		printf("Could not open current directory" );
		return 0; // Return statement terminates whole main function here and also whole program
	}


	while ((dp = readdir(dr)) != NULL)   // Like file handling program we read next character from file until EOF. The next directory name ( Folder or File name ) is read till no more dir are remaining
			printf("%s\n", dp->d_name);

			/* Actual struct dirent is defined in header file as follow hence you de->d_name is used

			   struct dirent
               {
	              long		d_ino;		//Always zero.
                  unsigned short	d_reclen;	//Always zero.
	              unsigned short	d_namlen;	//Length of name in d_name.
	              char		d_name[FILENAME_MAX]; // File name.
                };


			*/

	closedir(dr); // To close dir
	return 0;
}

// Official Documentation By UNIX is available here http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html for readdir()

