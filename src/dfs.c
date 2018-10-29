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

    if (fp > 0)
    {
        int s = dfs_size(fp);
        void *data = malloc(s);
        dfs_read(data, 1, s, fp);
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

map_t *dfs_load_map(const char *const path, char *lang)
{
    char buffer[256];

    map_t *data = calloc(1, sizeof(map_t));

    int x = 0;
    int y = 0;
    int i = 0;
    while (true)
    {
        if (lang == NULL)
            sprintf(buffer, path, x, y);
        else
            sprintf(buffer, path, lang, x, y);

        sprite_t *sp = dfs_load(buffer);
        if (sp == NULL)
        {
            if (x == 0)
                break;
            else
            {
                y++;
                if (data->mod == 0)
                    data->mod = x;
                x = 0;
                continue;
            }
        }
        data->sprites[i] = sp;

        if (x == 0)
            data->height += data->sprites[i]->height;
        if (y == 0)
            data->width += data->sprites[i]->width;

        i++;
        x++;
    }
    data->slices = i;
    return data;
}

int dfs_openf(const char *const format, ...)
{
    char buffer[256];
    va_list args;
    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);

    return dfs_open(buffer);
}