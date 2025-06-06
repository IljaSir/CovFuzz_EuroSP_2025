/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */

/* Define if building universal (internal helper macro) */
/* #undef AC_APPLE_UNIVERSAL_BUILD */

/* Make use of ARM4 assembly optimizations */
/* #undef ARM4_ASM */

/* Make use of ARM5E assembly optimizations */
/* #undef ARM5E_ASM */

/* Make use of Blackfin assembly optimizations */
/* #undef BFIN_ASM */

/* Disable all parts of the API that are using floats */
/* #undef DISABLE_FLOAT_API */

/* Symbol visibility prefix */
#define EXPORT __attribute__((visibility("default")))

/* Debug fixed-point implementation */
/* #undef FIXED_DEBUG */

/* Compile as fixed-point */
/* #undef FIXED_POINT */

/* Compile as floating-point */
#define FLOATING_POINT /**/

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdio.h> header file. */
#define HAVE_STDIO_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/audioio.h> header file. */
/* #undef HAVE_SYS_AUDIOIO_H */

/* Define to 1 if you have the <sys/soundcard.h> header file. */
#define HAVE_SYS_SOUNDCARD_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to the sub-directory where libtool stores uninstalled libraries. */
#define LT_OBJDIR ".libs/"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "speex-dev@xiph.org"

/* Define to the full name of this package. */
#define PACKAGE_NAME "speexdsp"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "speexdsp 1.2.1"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "speexdsp"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "1.2.1"

/* Resample with full SINC table (no interpolation) */
/* #undef RESAMPLE_FULL_SINC_TABLE */

/* The size of `int', as computed by sizeof. */
#define SIZEOF_INT 4

/* The size of `int16_t', as computed by sizeof. */
#define SIZEOF_INT16_T 2

/* The size of `int32_t', as computed by sizeof. */
#define SIZEOF_INT32_T 4

/* The size of `long', as computed by sizeof. */
#define SIZEOF_LONG 8

/* The size of `short', as computed by sizeof. */
#define SIZEOF_SHORT 2

/* The size of `uint16_t', as computed by sizeof. */
#define SIZEOF_UINT16_T 2

/* The size of `uint32_t', as computed by sizeof. */
#define SIZEOF_UINT32_T 4

/* The size of `u_int16_t', as computed by sizeof. */
#define SIZEOF_U_INT16_T 2

/* The size of `u_int32_t', as computed by sizeof. */
#define SIZEOF_U_INT32_T 4

/* Define to 1 if all of the C90 standard headers exist (not just the ones
   required in a freestanding environment). This macro is provided for
   backward compatibility; new code need not use it. */
#define STDC_HEADERS 1

/* Enable support for TI C55X DSP */
/* #undef TI_C55X */

/* Use FFTW3 for FFT */
/* #undef USE_GPL_FFTW3 */

/* Use Intel Math Kernel Library for FFT */
/* #undef USE_INTEL_MKL */

/* Use KISS Fast Fourier Transform */
/* #undef USE_KISS_FFT */

/* Enable NEON support */
/* #undef USE_NEON */

/* Use FFT from OggVorbis */
#define USE_SMALLFT /**/

/* Enable SSE support */
#define USE_SSE /**/

/* Enable SSE2 support */
#define USE_SSE2 /**/

/* Use C99 variable-size arrays */
#define VAR_ARRAYS /**/

/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most
   significant byte first (like Motorola and SPARC, unlike Intel). */
#if defined AC_APPLE_UNIVERSAL_BUILD
# if defined __BIG_ENDIAN__
#  define WORDS_BIGENDIAN 1
# endif
#else
# ifndef WORDS_BIGENDIAN
/* #  undef WORDS_BIGENDIAN */
# endif
#endif

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
/* #undef inline */
#endif

/* Define to the equivalent of the C99 'restrict' keyword, or to
   nothing if this is not supported.  Do not define if restrict is
   supported only directly.  */
#define restrict __restrict__
/* Work around a bug in older versions of Sun C++, which did not
   #define __restrict__ or support _Restrict or __restrict__
   even though the corresponding Sun C compiler ended up with
   "#define restrict _Restrict" or "#define restrict __restrict__"
   in the previous line.  This workaround can be removed once
   we assume Oracle Developer Studio 12.5 (2016) or later.  */
#if defined __SUNPRO_CC && !defined __RESTRICT && !defined __restrict__
# define _Restrict
# define __restrict__
#endif
