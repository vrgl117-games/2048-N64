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
#include <string.h>

#include "dfs.h"

void dfs_free_map(map_t *map)
{
    if (map == NULL)
        return;

    for (int i = 0; map->sprites[i] != 0; i++)
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

map_t *dfs_load_map(const char *const path, int mod)
{
    char buffer[256];

    map_t *data = calloc(1, sizeof(map_t));
    data->mod = mod;

    int i = 0;
    while (true)
    {
        sprintf(buffer, path, i);

        data->sprites[i] = dfs_load(buffer);
        if (data->sprites[i] == NULL)
            break;

        if (i % mod == 0)
            data->height += data->sprites[i]->height;
        if (i < mod)
            data->width += data->sprites[i]->width;

        i++;
    }
    data->slices = i;
    return data;
}
