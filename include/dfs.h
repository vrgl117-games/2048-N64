/* dfs.h -- dfs helpers header
 *
 * Copyright (C) 2018 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#ifndef __FILESYSTEM_H__
#define __FILESYSTEM_H__

#include <libdragon.h>

typedef struct map
{
    sprite_t *sprites[12];
    int slices;

    int height;
    int width;

    int mod;
} map_t;

void dfs_free_map(map_t *map);
void *dfs_load(const char *const path);
void *dfs_loadf(const char *const format, ...);
map_t *dfs_load_map(const char *const path, int mod, char *lang);

#endif //__FILESYSTEM_H__