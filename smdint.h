/**
 * @file smdint.h
 *
 * ISO C99 standard library
 *
 * @author Dario Sneidermanis
 */

#ifndef _SMDINT_H_
#define _SMDINT_H_


typedef signed char          int8_t;
typedef unsigned char       uint8_t;
typedef short                int16_t;
typedef unsigned short      uint16_t;
typedef int                  int32_t;
typedef unsigned int        uint32_t;
typedef long long            int64_t;
typedef unsigned long long  uint64_t;


#define PRId8 "hhd"
#define PRIi8 "hhi"
#define PRIu8 "hhu"
#define PRIx8 "hhx"
#define PRIX8 "hhX"
#define SCNd8 "hhd"
#define SCNi8 "hhi"
#define SCNu8 "hhu"
#define SCNx8 "hhx"
#define SCNX8 "hhX"


#define PRId16 "hd"
#define PRIi16 "hi"
#define PRIu16 "hu"
#define PRIx16 "hx"
#define PRIX16 "hX"
#define SCNd16 "hd"
#define SCNi16 "hi"
#define SCNu16 "hu"
#define SCNx16 "hx"
#define SCNX16 "hX"


#define PRId32 "d"
#define PRIi32 "i"
#define PRIu32 "u"
#define PRIx32 "x"
#define PRIX32 "X"
#define SCNd32 "d"
#define SCNi32 "i"
#define SCNu32 "u"
#define SCNx32 "x"
#define SCNX32 "X"


#define PRId64 "lld"
#define PRIi64 "lli"
#define PRIu64 "llu"
#define PRIx64 "llx"
#define PRIX64 "llX"
#define SCNd64 "lld"
#define SCNi64 "lli"
#define SCNu64 "llu"
#define SCNx64 "llx"
#define SCNX64 "llX"


#endif /* _SMDINT_H_ */
