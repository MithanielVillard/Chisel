#ifndef TYPE_H
#define TYPE_H

//============ TYPEDEF =============

#undef INT8_MAX
#undef INT16_MAX
#undef INT32_MAX
#undef INT64_MAX

using int8   = char;
using int16  = short;
using int32  = int;
using int64  = long long;

using byte   = unsigned char;
using uint8  = unsigned char;
using uint16 = unsigned short;
using uint32 = unsigned int;
using uint64 = unsigned long long;

using float32 = float;
using float64 = double;
using float80 = long double;

using size_type = long unsigned int;


#define INT8_MAX  128
#define INT16_MAX 32767
#define INT32_MAX 2147483647
#define INT64_MAX 9223372036854775807

#define BYTE 8
#define KILOBYTE 1024 * BYTE
#define MEGABYTE 1024 * KILOBYTE
#define GIGABYTE 1024 * MEGABYTE

#endif // !TYPE_H
