/*
 *
 *This file is used to debug the library error!
 *
 *
 */


#ifndef LIB_ERROR_H
#define LIB_ERROR_H
#define __ERROR_CHECK__  
#ifdef  __ERROR_CHECK__
#define show_info(format,...) printf("File: "__FILE__", Line: %05d: "format"\n", __LINE__, ##__VA_ARGS__)  
#else  
#define show_info(format,...)  
#endif  

#endif
