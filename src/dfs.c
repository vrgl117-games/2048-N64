/* dfs.c -- dfs helpers implementation
 *
 * Copyright (C) 2018 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#include <malloc.h>
#include <stdarg.h>
#include <stdio.h>

#include "dfs.h"

void dfs_free_map(map_t *map)
{
    int i = 0;
    for (; map->sprites[i] != 0; i++)
        free(map->sprites[i]);
    free(map->sprites[i]);
    free(map);
}

void *dfs_load(const char *const path)
{
    int fp = dfs_open(path);

    if (fp)
    {
        int size = dfs_size(fp);
        void *data = malloc(size);
        dfs_read(data, 1, size, fp);
        dfs_close(fp);
        return data;
    }

    return NULL;
}
void *dfs_loadf(const char *const format, ...)
{
    char buffer[256];
    va_list args;
    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);

    return dfs_load(buffer);
}

map_t *dfs_load_map(const char *const path, int slices, int mod)
{
    char buffer[256];

    map_t *data = malloc(sizeof(map_t *));
    data->sprites = malloc((slices + 1) * sizeof(sprite_t *));
    data->mod = mod;

    for (int i = 0; i < slices; i++)
    {
        sprintf(buffer, path, i);

        data->sprites[i] = dfs_load(buffer);
        if (i % mod == 0)
            data->height += data->sprites[i]->height;
        if (i < mod)
            data->width += data->sprites[i]->width;
    }
    data->sprites[slices] = 0;
    return data;
}
