#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef deathstar_ZZTDeathstar_h
#define deathstar_ZZTDeathstar_h

typedef enum {
    MAP_OK,
    MAP_INVALID_PATH,
    MAP_INVALID_HEADER,
    MAP_INVALID_INDEX_POINTER
} MapError;

typedef struct {
    char *buffer;
    uint32_t length;
    MapError error;
} MapData;


MapData openMapAtPath(const char *path);
MapData openMapFromBuffer(void *buffer);
int saveMap(const char *path, MapData map);
MapData zteam_deprotect(MapData map);
MapData name_deprotect(MapData map);

#endif
