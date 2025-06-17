#ifndef __M2INI_H__
#define __M2INI_H__

/**
 * To use this library - do this in one C or C++ file:
 *   #define M2INI_IMPLEMENTATION
 *   #include "m2ini.h"
 */

#ifndef MIDEF
#ifdef MI_STATIC
#define MIDEF static
#else
#define MIDEF extern
#endif
#endif

#ifndef MI_HAS_C99
#ifdef __STDC_VERSION__
#if __STDC_VERSION__ >= 199901L
#define MI_HAS_C99
#endif
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

#ifdef MI_HAS_C99
#else
#endif

typedef struct mi_ini {
} mi_ini_t;

/**
 * @~english
 * @brief Parse INI
 * @param data Data
 * @param size Size
 * @return Parsed result
 */
MIDEF mi_ini_t* mi_parse(const char* data, size_t size);

/**
 * @~english Parse INI
 * @param path Path
 * @return Parsed result
 */
MIDEF mi_ini_t* mi_parse_file(const char* path);

#ifdef M2INI_IMPLEMENTATION
#include <stdio.h>
#include <stdlib.h>

MIDEF mi_ini_t* mi_parse(const char* data, size_t size) {}

MIDEF mi_ini_t* mi_parse_file(const char* path) {
	FILE* f = fopen(path, "rb");
	if(f != NULL) {
		size_t	       sz;
		unsigned char* buffer;
		mi_ini_t*      ini;

		fseek(f, 0, SEEK_END);
		sz = ftell(f);
		fseek(f, 0, SEEK_SET);

		buffer = malloc(sz);
		fread(buffer, sz, 1, f);

		fclose(f);
		ini = mi_parse(buffer, sz);
		free(buffer);

		return ini;
	}
	return NULL;
}

#endif

#ifdef __cplusplus
}
#endif

#endif
