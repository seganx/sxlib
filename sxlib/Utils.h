/********************************************************************
	created:	2013/09/03
	filename: 	Utils.h
	Author:		Sajad Beigjani
	eMail:		sajad.b@gmail.com
	Site:		www.SeganX.com
	Desc:		This file contain some functions and classes depend on
				other tools in library
*********************************************************************/
#ifndef GUARD_Utils_HEADER_FILE
#define GUARD_Utils_HEADER_FILE

#include "Array.h"
#include "String.h"


#define  SX_RAW_SIZE_TYPE		word


//! copy data to destination buffer from the source buffer and return pointer to the beginning of next data. return null if no more data available 
SEGAN_LIB_API const char* sx_raw_read( char* dest, const SX_RAW_SIZE_TYPE destsize, const char* src );

//! copy data which is specified by index to destination buffer from the source buffer and return false if no data available
SEGAN_LIB_API bool sx_raw_read( char* dest, const SX_RAW_SIZE_TYPE destsize, const char* src, const uint dataindex );

/*! 
append data to the destination buffer and return new size of raw data on successful. return 0 on fail
NOTE: destination buffer should be 0 filled
*/
SEGAN_LIB_API uint sx_raw_write( char* dest, const uint destsize, const char* data, const SX_RAW_SIZE_TYPE size );

/*!
append text to the destination buffer and return new size of raw data on successful. return 0 on fail
NOTE: destination buffer should be 0 filled
*/
SEGAN_LIB_API uint sx_raw_write_text(char* dest, const uint destsize, const char* data);

//! print raw data on console
SEGAN_LIB_API void sx_raw_print( const char* src );

//!	load a text file and append that to the string
SEGAN_LIB_API bool sx_load_string( String& dest, const wchar* filename );

//!	load a text file and parse the lines. return false if operation failed
SEGAN_LIB_API bool sx_load_string_list( Array<String*>& dest, const wchar* filename );

//! clear all allocated strings
SEGAN_LIB_API void sx_clear_string_list( Array<String*>& list );

//! write time stamp to the buffer with specified format and return the length of string
SEGAN_LIB_API uint sx_time_to_str( wchar* dest, const uint destSize, const wchar* timeFormat );

/*! this function generates a unique hash by specified index.
the index can be retrieve later from the hash */
SEGAN_LIB_API void sx_hash_write_index( char* dest, const int destsize, const uint index );

//! retrieve index from given hash which is generated by sx_hash_write_index. return default value on fail
SEGAN_LIB_API uint sx_hash_read_index( const char* hash, const uint defaul_val );

//! randomize random function with time as seed
SEGAN_LIB_API void sx_randomize_by_time( void );


#endif	//	GUARD_Utils_HEADER_FILE
