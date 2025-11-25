/* font.c -- font helpers implementation
 *
 * Copyright (C) 2018-2025 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#include "font.h"

#include "colors.h"

void font_init()
{
    rdpq_font_t *font_debug = rdpq_font_load_builtin(FONT_BUILTIN_DEBUG_MONO);
    rdpq_text_register_font(FONT_DEBUG, font_debug);

    rdpq_font_t *font_bold = rdpq_font_load("rom:/fonts/ClearSans-Bold.font64");
    rdpq_font_style(font_bold, 0, &(rdpq_fontstyle_t){.color = colors[COLOR_FONT]});
    rdpq_text_register_font(FONT_BOLD, font_bold);

    rdpq_font_t *font_bold_flipped = rdpq_font_load("rom:/fonts/ClearSans-Bold-flipped.font64");
    rdpq_font_style(font_bold_flipped, 0, &(rdpq_fontstyle_t){.color = colors[COLOR_FONT]});
    rdpq_text_register_font(FONT_BOLD_FLIPPED, font_bold_flipped);
}
