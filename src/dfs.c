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
