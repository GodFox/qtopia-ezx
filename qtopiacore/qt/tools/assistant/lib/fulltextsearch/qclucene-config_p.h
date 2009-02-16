/****************************************************************************
**
** Copyright (C) 2008 Nokia Corporation and/or its subsidiary(-ies).
** Contact: Qt Software Information (qt-info@nokia.com)
**
** This file is part of the QCLucene library and is distributable under
** the terms of the LGPL license as specified in the license.txt file.
**
****************************************************************************/

#ifndef QCLUCENE_CONFIG_P_H
#define QCLUCENE_CONFIG_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API. It exists for the convenience
// of the help generator tools. This header file may change from version
// to version without notice, or even be removed.
//
// We mean it.
//

#include <QtCore/qglobal.h>

#ifndef _SRC_CLUCENE_CLUCENE_CONFIG_H
#define _SRC_CLUCENE_CLUCENE_CONFIG_H 1
 
/*
src/CLucene/clucene-config.h.
Generated
automatically
at
end
of
configure.
*/
/* config.h.tmp.  Generated by configure.  */
/* config.h.tmp.in.  Generated from configure.ac by autoheader.  */

/* Disable multithreading */
/* #undef _CL_DISABLE_MULTITHREADING */

/* Define to 1 if you have the <algorithm> header file. */
#ifndef _CL_HAVE_ALGORITHM 
#define _CL_HAVE_ALGORITHM  1 
#endif

/* Define to 1 if you have the <ctype.h> header file. */
#ifndef _CL_HAVE_CTYPE_H 
#define _CL_HAVE_CTYPE_H  1 
#endif

/* Define to 1 if you have the <dirent.h> header file, and it defines `DIR'.
   */
#ifndef _CL_HAVE_DIRENT_H 
#define _CL_HAVE_DIRENT_H  1 
#endif

#if !defined (__MINGW32__)
    /* Define to 1 if you have the <dlfcn.h> header file. */
#   ifndef _CL_HAVE_DLFCN_H 
#   define _CL_HAVE_DLFCN_H  1 
#   endif
#endif

/* Define to 1 if you have the <errno.h> header file. */
#ifndef _CL_HAVE_ERRNO_H 
#define _CL_HAVE_ERRNO_H  1 
#endif

#if !defined(__SUNPRO_CC) && !defined(__SUNPRO_C)
    /* Define to 1 if you have the <ext/hash_map> header file. */
#   ifndef _CL_HAVE_EXT_HASH_MAP 
#   define _CL_HAVE_EXT_HASH_MAP  1 
#   endif

    /* Define to 1 if you have the <ext/hash_set> header file. */
#   ifndef _CL_HAVE_EXT_HASH_SET 
#   define _CL_HAVE_EXT_HASH_SET  1 
#   endif
#endif

/* Define to 1 if you have the <fcntl.h> header file. */
#ifndef _CL_HAVE_FCNTL_H 
#define _CL_HAVE_FCNTL_H  1 
#endif

#if !defined(__xlC__) && !defined(__xlc__) && !defined (__MINGW32__) && \
    !defined(__HP_aCC) && !defined(__SUNPRO_C) && !defined(__SUNPRO_CC) || \
    defined(__SUNPRO_CC) && (__SUNPRO_CC > 0x550) || (defined(__HP_aCC) && defined(__ia64))
    /* Define to 1 if the system has the type `float_t'. */
#   ifndef _CL_HAVE_FLOAT_T 
#   define _CL_HAVE_FLOAT_T  1 
#   endif
#endif

/* Define to 1 if you have the <functional> header file. */
#ifndef _CL_HAVE_FUNCTIONAL 
#define _CL_HAVE_FUNCTIONAL  1 
#endif

/* Does not support new float byte<->float conversions */
#ifndef _CL_HAVE_FUNCTIONING_FLOAT_BYTE 
#define _CL_HAVE_FUNCTIONING_FLOAT_BYTE   
#endif

/* Define to 1 if you have the `getpagesize' function. */
#ifndef _CL_HAVE_GETPAGESIZE 
#define _CL_HAVE_GETPAGESIZE  1
#endif

/* Define to 1 if you have the <hash_map> header file. */
/* #undef _CL_HAVE_HASH_MAP */

/* Define to 1 if you have the <hash_set> header file. */
/* #undef _CL_HAVE_HASH_SET */

/* Define to 1 if the system has the type `intptr_t'. */
#ifndef _CL_HAVE_INTPTR_T 
#define _CL_HAVE_INTPTR_T  1 
#endif

/* Define to 1 if you have the <inttypes.h> header file. */
#ifndef _CL_HAVE_INTTYPES_H 
#define _CL_HAVE_INTTYPES_H  1 
#endif

/* Define to 1 if you have the <list> header file. */
#ifndef _CL_HAVE_LIST 
#define _CL_HAVE_LIST  1 
#endif

/* Define to 1 if you have the `lltoa' function. */
/* #undef _CL_HAVE_LLTOA */

#if defined(__MINGW32__)
    /* Define to 1 if you have the `lltow' function. */
#   ifndef _CL_HAVE_LLTOW 
#   define _CL_HAVE_LLTOW  1 
#   endif
#endif

#if !defined(__SUNPRO_CC) && !defined(__SUNPRO_C) && !defined(__xlC__) && !defined(__xlc__)
    /* Define to 1 if long double works and has more range or precision than double. */
#   ifndef _CL_HAVE_LONG_DOUBLE 
#   define _CL_HAVE_LONG_DOUBLE  1 
#   endif
#endif

/* Define to 1 if you have the <map> header file. */
#ifndef _CL_HAVE_MAP 
#define _CL_HAVE_MAP  1 
#endif

/* Define to 1 if you have the <math.h> header file. */
#ifndef _CL_HAVE_MATH_H 
#define _CL_HAVE_MATH_H  1 
#endif

/* Define to 1 if you have the <memory.h> header file. */
#ifndef _CL_HAVE_MEMORY_H 
#define _CL_HAVE_MEMORY_H  1 
#endif

#if !defined(__MINGW32__) && !defined(__HP_aCC) && !defined(__xlC__) && !defined(__xlc__)
    /* Define to 1 if you have a working `mmap' system call. */
#   ifndef _CL_HAVE_MMAP 
#   define _CL_HAVE_MMAP  1 
#   endif
#endif

/* define if the compiler implements namespaces */
#ifndef _CL_HAVE_NAMESPACES 
#define _CL_HAVE_NAMESPACES   
#endif

#if defined(__SUNPRO_CC) || defined(__SUNPRO_C) || defined(__HP_aCC) || defined(__xlC__) || defined(__xlc__)
    /* Define if you have the nanosleep function */
#   ifndef _CL_HAVE_NANOSLEEP
#   define _CL_HAVE_NANOSLEEP 1
#   endif
#endif

/* Define to 1 if you have the <ndir.h> header file, and it defines `DIR'. */
/* #undef _CL_HAVE_NDIR_H */

/* Does not support new float byte<->float conversions */
/* #undef _CL_HAVE_NO_FLOAT_BYTE */

/* Does not support try/catch blocks */
/* #undef _CL_HAVE_NO_FUNCTION_TRY_BLOCKS */

/* Define to 1 if you have the `printf' function. */
#ifndef _CL_HAVE_PRINTF 
#define _CL_HAVE_PRINTF  1 
#endif

#if !defined(__MINGW32__)
    /* Define if you have POSIX threads libraries and header files. */
#   ifndef _CL_HAVE_PTHREAD 
#   define _CL_HAVE_PTHREAD  1 
#   endif
#endif

/* Define if recursive pthread mutexes are available */
/* #undef _CL_HAVE_PTHREAD_MUTEX_RECURSIVE */

/* Define to 1 if you have the <set> header file. */
#ifndef _CL_HAVE_SET 
#define _CL_HAVE_SET  1 
#endif

/* Define to 1 if you have the `snprintf' function. */
#ifndef _CL_HAVE_SNPRINTF 
#define _CL_HAVE_SNPRINTF  1 
#endif

/* Defined if the snprintf overflow test fails */
/* #undef _CL_HAVE_SNPRINTF_BUG */

/* Define to 1 if you have the `snwprintf' function. */
/* #undef _CL_HAVE_SNWPRINTF */

#if !defined(__HP_aCC) && !defined(__SUNPRO_CC) && !defined(__SUNPRO_C)
    /* define if the compiler supports ISO C++ standard library */
#   ifndef _CL_HAVE_STD 
#   define _CL_HAVE_STD   
#   endif
#endif

/* Define to 1 if you have the <stdarg.h> header file. */
#ifndef _CL_HAVE_STDARG_H 
#define _CL_HAVE_STDARG_H  1 
#endif

/* x */
#ifndef _CL_HAVE_STDEXCEPT 
#define _CL_HAVE_STDEXCEPT   
#endif

#if !defined(__SUNPRO_CC) && !defined(__SUNPRO_C) && !defined(__HP_aCC) && \
    !defined(__xlC__) && !defined(__xlc__)
    /* Define to 1 if you have the <stdint.h> header file. */
#   ifndef _CL_HAVE_STDINT_H 
#   define _CL_HAVE_STDINT_H  1 
#   endif
#endif

#if !defined(__HP_aCC)
    /* Define to 1 if you have the <stdlib.h> header file. */
#   ifndef _CL_HAVE_STDLIB_H 
#   define _CL_HAVE_STDLIB_H  1 
#   endif

    /* define if the compiler supports Standard Template Library */
#   ifndef _CL_HAVE_STL 
#   define _CL_HAVE_STL   
#   endif
#endif

/* Define to 1 if you have the <strings.h> header file. */
#ifndef _CL_HAVE_STRINGS_H 
#define _CL_HAVE_STRINGS_H  1 
#endif

/* Define to 1 if you have the <string.h> header file. */
#ifndef _CL_HAVE_STRING_H 
#define _CL_HAVE_STRING_H  1 
#endif

/* Define to 1 if you have the `strlwr' function. */
/* #undef _CL_HAVE_STRLWR */

/* Define to 1 if you have the `strtoll' function. */
/* #undef _CL_HAVE_STRTOLL */

/* Define to 1 if you have the `strupr' function. */
/* #undef _CL_HAVE_STRUPR */

/* Defined if the swprintf test fails */
#ifndef _CL_HAVE_SWPRINTF_BUG 
#define _CL_HAVE_SWPRINTF_BUG   
#endif

/* Define to 1 if you have the <sys/dir.h> header file, and it defines `DIR'.
   */
/* #undef _CL_HAVE_SYS_DIR_H */

/* Define to 1 if you have the <sys/ndir.h> header file, and it defines `DIR'.
   */
/* #undef _CL_HAVE_SYS_NDIR_H */

/* Define to 1 if you have the <sys/stat.h> header file. */
#ifndef _CL_HAVE_SYS_STAT_H 
#define _CL_HAVE_SYS_STAT_H  1 
#endif

/* Define to 1 if you have the <sys/timeb.h> header file. */
#ifndef _CL_HAVE_SYS_TIMEB_H 
#define _CL_HAVE_SYS_TIMEB_H  1 
#endif

/* Define to 1 if you have the <sys/types.h> header file. */
#ifndef _CL_HAVE_SYS_TYPES_H 
#define _CL_HAVE_SYS_TYPES_H  1 
#endif

// Do not use the tchar.h that ships with mingw, this causes the qt build to
// fail (211547, 211401, etc...), reuse the replacement as with any other compiler
// #if defined(__MINGW32__)
//     /* Define to 1 if you have the <tchar.h> header file. */
// #   ifndef _CL_HAVE_TCHAR_H 
// #   define _CL_HAVE_TCHAR_H  1 
// #   endif
// #endif

#if defined(__MINGW32__) || defined(__SUNPRO_CC) || defined(__SUNPRO_C) 
    /* Define to 1 if you have the `tell' function. */
#   ifndef _CL_HAVE_TELL 
#   define _CL_HAVE_TELL  1 
#   endif
#endif

/* Define to 1 if you have the <unistd.h> header file. */
#ifndef _CL_HAVE_UNISTD_H 
#define _CL_HAVE_UNISTD_H  1 
#endif

/* Define to 1 if you have the <vector> header file. */
#ifndef _CL_HAVE_VECTOR 
#define _CL_HAVE_VECTOR  1 
#endif

/* Define to 1 if you have the `vsnwprintf' function. */
/* #undef _CL_HAVE_VSNWPRINTF */

/* Define to 1 if you have the <wchar.h> header file. */
#ifndef _CL_HAVE_WCHAR_H 
#define _CL_HAVE_WCHAR_H  1 
#endif

/* Define to 1 if the system has the type `wchar_t'. */
#ifndef _CL_HAVE_WCHAR_T 
#define _CL_HAVE_WCHAR_T  1 
#endif

#if !defined(__SUNPRO_CC) && !defined(__SUNPRO_C) && !defined(__MINGW32__) && \
    !defined(Q_OS_MAC) && !defined(__HP_aCC)
    /* Define to 1 if you have the `wcscasecmp' function. */
#   ifndef _CL_HAVE_WCSCASECMP 
#   define _CL_HAVE_WCSCASECMP  1 
#   endif
#endif

/* Define to 1 if you have the `wcscat' function. */
#ifndef _CL_HAVE_WCSCAT 
#define _CL_HAVE_WCSCAT  1 
#endif

/* Define to 1 if you have the `wcschr' function. */
#ifndef _CL_HAVE_WCSCHR 
#define _CL_HAVE_WCSCHR  1 
#endif

/* Define to 1 if you have the `wcscmp' function. */
#ifndef _CL_HAVE_WCSCMP 
#define _CL_HAVE_WCSCMP  1 
#endif

/* Define to 1 if you have the `wcscpy' function. */
#ifndef _CL_HAVE_WCSCPY 
#define _CL_HAVE_WCSCPY  1 
#endif

/* Define to 1 if you have the `wcscspn' function. */
#ifndef _CL_HAVE_WCSCSPN 
#define _CL_HAVE_WCSCSPN  1 
#endif

#if defined(__MINGW32__)
    /* Define to 1 if you have the `wcsicmp' function. */
#   ifndef _CL_HAVE_WCSICMP 
#   define _CL_HAVE_WCSICMP  1 
#   endif
#endif

/* Define to 1 if you have the `wcslen' function. */
#ifndef _CL_HAVE_WCSLEN 
#define _CL_HAVE_WCSLEN  1 
#endif

/* Define to 1 if you have the `wcsncmp' function. */
#ifndef _CL_HAVE_WCSNCMP 
#define _CL_HAVE_WCSNCMP  1 
#endif

/* Define to 1 if you have the `wcsncpy' function. */
#ifndef _CL_HAVE_WCSNCPY 
#define _CL_HAVE_WCSNCPY  1 
#endif

/* Define to 1 if you have the `wcsstr' function. */
#ifndef _CL_HAVE_WCSSTR 
#define _CL_HAVE_WCSSTR  1 
#endif

/* Define to 1 if you have the `wcstod' function. */
#ifndef _CL_HAVE_WCSTOD 
#define _CL_HAVE_WCSTOD  1 
#endif

#if !defined(__SUNPRO_CC) && !defined(__SUNPRO_C) && !defined(__HP_aCC)
    /* Define to 1 if you have the `wcstoll' function. */
#   ifndef _CL_HAVE_WCSTOLL 
#   define _CL_HAVE_WCSTOLL  1 
#   endif
#endif

#if defined(__MINGW32__)
    /* Define to 1 if you have the `wcsupr' function. */
#   ifndef _CL_HAVE_WCSUPR 
#   define _CL_HAVE_WCSUPR  1 
#   endif
#endif

#if defined(__SUNPRO_CC) || defined(__SUNPRO_C) || defined(__HP_aCC)
    /* Define to 1 if you have a functioning <wchar.h> header file. */
#   ifndef _CL_HAVE_WCTYPE_H 
#   define _CL_HAVE_WCTYPE_H
#   endif
#endif

/* Define to 1 if you have the `wprintf' function. */
/* #undef _CL_HAVE_WPRINTF */

#if defined(__MINGW32__)
    /* Define to 1 if you have the `_filelength' function. */
#   ifndef _CL_HAVE__FILELENGTH 
#   define _CL_HAVE__FILELENGTH  1 
#   endif
#endif

/* How to define a static const in a class */
#ifndef LUCENE_STATIC_CONSTANT_SYNTAX 
#define LUCENE_STATIC_CONSTANT_SYNTAX  1 
#endif

/* Name of package */
#ifndef _CL_PACKAGE 
#define _CL_PACKAGE  "clucene-core" 
#endif

/* Define to the address where bug reports for this package should be sent. */
#ifndef _CL_PACKAGE_BUGREPORT 
#define _CL_PACKAGE_BUGREPORT  "" 
#endif

/* Define to the full name of this package. */
#ifndef _CL_PACKAGE_NAME 
#define _CL_PACKAGE_NAME  "" 
#endif

/* Define to the full name and version of this package. */
#ifndef _CL_PACKAGE_STRING 
#define _CL_PACKAGE_STRING  "" 
#endif

/* Define to the one symbol short name of this package. */
#ifndef _CL_PACKAGE_TARNAME 
#define _CL_PACKAGE_TARNAME  "" 
#endif

/* Define to the version of this package. */
#ifndef _CL_PACKAGE_VERSION 
#define _CL_PACKAGE_VERSION  "" 
#endif

/* Define to the necessary symbol if this constant uses a non-standard name on
   your system. */
/* #undef _CL_PTHREAD_CREATE_JOINABLE */

/* The size of a `unsigned char', as computed by sizeof. */
/* #undef _CL_SIZEOF_UNSIGNED_CHAR */

/* The size of a `unsigned int', as computed by sizeof. */
/* #undef _CL_SIZEOF_UNSIGNED_INT */

/* The size of a `unsigned long', as computed by sizeof. */
/* #undef _CL_SIZEOF_UNSIGNED_LONG */

/* The size of a `unsigned long long', as computed by sizeof. */
/* #undef _CL_SIZEOF_UNSIGNED_LONG_LONG */

/* The size of a `unsigned __int64', as computed by sizeof. */
/* #undef _CL_SIZEOF_UNSIGNED___INT64 */

/* Define to 1 if the `S_IS*' macros in <sys/stat.h> do not work properly. */
/* #undef _CL_STAT_MACROS_BROKEN */

#if !defined(__HP_aCC)
    /* Define to 1 if you have the ANSI C header files. */
#   ifndef _CL_STDC_HEADERS 
#   define _CL_STDC_HEADERS  1 
#   endif

/* Define to 1 if you can safely include both <sys/time.h> and <time.h>. */
#   ifndef _CL_TIME_WITH_SYS_TIME 
#   define _CL_TIME_WITH_SYS_TIME  1 
#   endif
#endif

/* Version number of package */
#ifndef _CL_VERSION 
#define _CL_VERSION  "0.9.17" 
#endif

/* Forces into Ascii mode */
/* #undef _ASCII */

/* Conditional Debugging */
/* #undef _CL__CND_DEBUG */

/* debuging option */
/* #undef _DEBUG */

/* Number of bits in a file offset, on hosts where this is settable. */
/* #undef _FILE_OFFSET_BITS */

/* If not already defined, then define as a datatype of *exactly* 32 bits. */
/* #undef uint32_t */

/* If not already defined, then define as a datatype of *exactly* 64 bits. */
/* #undef uint64_t */

/* If not already defined, then define as a datatype of *exactly* 8 bits. */
/* #undef uint8_t */
 
/* once:
_SRC_CLUCENE_CLUCENE_CONFIG_H
*/
#endif

#endif // QCLUCENE_CONFIG_P_H

