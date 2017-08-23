/* TextImpl.cpp - 3DS */

#include <3ds.h>
#include <citro3d.h>
#include <Stack.h>
#include "Global3DS.h"
#include "TextImpl.h"

#include "stdio.h"

void TextImpl::initGraphics() {
    // We have only one color per Text object
    // Set to white
    m_quads[0].verts[0].r = 1.0f;
    m_quads[0].verts[0].g = 1.0f;
    m_quads[0].verts[0].b = 1.0f;
    m_quads[0].verts[0].a = 1.0f;
}

void TextImpl::updateGraphics() {
    if (m_has_changed) {
        m_has_changed = false;
        m_quads_len = m_length;
        update_vertices();
    }
}

void TextImpl::update_color(int8_t color) {
    if (m_color != color) {
        m_color = color;

        switch (m_color) {
            case TextColor::BLACK:
                m_quads[0].verts[0].r = 0.0f;
                m_quads[0].verts[0].g = 0.0f;
                m_quads[0].verts[0].b = 0.0f;
                m_quads[0].verts[0].a = 1.0f;
                break;

            case TextColor::WHITE:
                m_quads[0].verts[0].r = 1.0f;
                m_quads[0].verts[0].g = 1.0f;
                m_quads[0].verts[0].b = 1.0f;
                m_quads[0].verts[0].a = 1.0f;
                break;

            case TextColor::RED:
                m_quads[0].verts[0].r = 1.0f;
                m_quads[0].verts[0].g = 0.0f;
                m_quads[0].verts[0].b = 0.0f;
                m_quads[0].verts[0].a = 1.0f;
                break;

            case TextColor::GREEN:
                m_quads[0].verts[0].r = 0.0f;
                m_quads[0].verts[0].g = 1.0f;
                m_quads[0].verts[0].b = 0.0f;
                m_quads[0].verts[0].a = 1.0f;
                break;

            case TextColor::BLUE:
                m_quads[0].verts[0].r = 0.0f;
                m_quads[0].verts[0].g = 0.0f;
                m_quads[0].verts[0].b = 1.0f;
                m_quads[0].verts[0].a = 1.0f;
                break;

            case TextColor::YELLOW:
                m_quads[0].verts[0].r = 1.0f;
                m_quads[0].verts[0].g = 1.0f;
                m_quads[0].verts[0].b = 0.0f;
                m_quads[0].verts[0].a = 1.0f;
                break;

            case TextColor::MAGENTA:
                m_quads[0].verts[0].r = 1.0f;
                m_quads[0].verts[0].g = 0.0f;
                m_quads[0].verts[0].b = 1.0f;
                m_quads[0].verts[0].a = 1.0f;
                break;

            case TextColor::CYAN:
                m_quads[0].verts[0].r = 0.0f;
                m_quads[0].verts[0].g = 1.0f;
                m_quads[0].verts[0].b = 1.0f;
                m_quads[0].verts[0].a = 1.0f;
                break;

            case TextColor::ORANGE:
                m_quads[0].verts[0].r = 1.0f;
                m_quads[0].verts[0].g = 0.5f;
                m_quads[0].verts[0].b = 0.0f;
                m_quads[0].verts[0].a = 1.0f;
                break;

            case TextColor::TRANSPARENT:
                m_quads[0].verts[0].r = 1.0f;
                m_quads[0].verts[0].g = 1.0f;
                m_quads[0].verts[0].b = 1.0f;
                m_quads[0].verts[0].a = 0.3125f;
                break;

            default:
                m_quads[0].verts[0].r = 1.0f;
                m_quads[0].verts[0].g = 1.0f;
                m_quads[0].verts[0].b = 1.0f;
                m_quads[0].verts[0].a = 1.0f;
                break;
        }
    }
}

void TextImpl::update_vertices() {
    int offset = 0;
    int pos_x = 9 * m_pos_x;
    int pos_y = 9 * m_pos_y;

    if (m_length > TEXT_LEN_LIMIT)
        m_length = TEXT_LEN_LIMIT;

    for (unsigned int i = 0; i < 11/*m_length*/; ++i) {
        char c = m_str[i];

        switch(c) {
            case ' ':
                m_quads[i].verts[0].x = 0; m_quads[i].verts[0].y = 0;
                m_quads[i].verts[0].u = 0; m_quads[i].verts[0].v = 0;

                m_quads[i].verts[1].x = 0; m_quads[i].verts[1].y = 0;
                m_quads[i].verts[1].u = 0; m_quads[i].verts[1].v = 0;

                m_quads[i].verts[2].x = 0; m_quads[i].verts[2].y = 0;
                m_quads[i].verts[2].u = 0; m_quads[i].verts[2].v = 0;

                m_quads[i].verts[3].x = 0; m_quads[i].verts[3].y = 0;
                m_quads[i].verts[3].u = 0; m_quads[i].verts[3].v = 0;

                offset += 4;
                break;

            case '\'':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[0].u = 53.0f / 64.0f; m_quads[i].verts[0].v = 48.0f / 64.0f;

                m_quads[i].verts[1].x = pos_x + offset + 4; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[1].u = 0; m_quads[i].verts[1].v = 0;

                m_quads[i].verts[2].x = pos_x + offset + 4; m_quads[i].verts[2].y = pos_y + 5;
                m_quads[i].verts[2].u = 0; m_quads[i].verts[2].v = 0;

                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 5;
                m_quads[i].verts[3].u = 0; m_quads[i].verts[3].v = 0;

                //m_quads[i].tex_w = 4; m_quads[i].tex_h = 5;
                //m_quads[i].tex_x = 53; m_quads[i].tex_y = 48;

                offset += 5;
                break;

            case '?':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 8; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 8; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 8; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 45; m_quads[i].tex_y = 48;

                offset += 9;
                break;

            case '!':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 4; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 4; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 4; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 58; m_quads[i].tex_y = 24;

                offset += 5;
                break;

            case '.':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y + 8;
                m_quads[i].verts[1].x = pos_x + offset + 4; m_quads[i].verts[1].y = pos_y + 8;
                m_quads[i].verts[2].x = pos_x + offset + 4; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 4; m_quads[i].tex_h = 4;
                //m_quads[i].tex_x = 53; m_quads[i].tex_y = 56;

                offset += 5;
                break;

            case ',':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y + 8;
                m_quads[i].verts[1].x = pos_x + offset + 4; m_quads[i].verts[1].y = pos_y + 8;
                m_quads[i].verts[2].x = pos_x + offset + 4; m_quads[i].verts[2].y = pos_y + 13;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 13;

                //m_quads[i].tex_w = 4; m_quads[i].tex_h = 5;
                //m_quads[i].tex_x = 57; m_quads[i].tex_y = 56;

                offset += 5;
                break;

            case ':':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 4; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 4; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 4; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 41; m_quads[i].tex_y = 48;

                offset += 5;
                break;

            case '0':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 8; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 8; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 8; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 0; m_quads[i].tex_y = 0;

                offset += 9;
                break;

            case '1':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 5; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 5; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 5; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 8; m_quads[i].tex_y = 0;

                offset += 6;
                break;

            case '2':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 8; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 8; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 8; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 13; m_quads[i].tex_y = 0;

                offset += 9;
                break;

            case '3':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 8; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 8; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 8; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 21; m_quads[i].tex_y = 0;

                offset += 9;
                break;

            case '4':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 9; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 9; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 9; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 29; m_quads[i].tex_y = 0;

                offset += 10;
                break;

            case '5':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 8; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 8; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 8; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 38; m_quads[i].tex_y = 0;

                offset += 9;
                break;

            case '6':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 8; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 8; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 8; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 46; m_quads[i].tex_y = 0;

                offset += 9;
                break;

            case '7':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 8; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 8; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 8; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 54; m_quads[i].tex_y = 0;

                offset += 9;
                break;

            case '8':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 8; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 8; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 8; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 0; m_quads[i].tex_y = 12;

                offset += 9;
                break;

            case '9':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 8; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 8; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 8; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 7; m_quads[i].tex_y = 12;

                offset += 9;
                break;

            case 'A':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[0].u = 15.0f / 64.0f; m_quads[i].verts[0].v = 12.0f / 64.0f;

                m_quads[i].verts[1].x = pos_x + offset + 8; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[1].u = 23.0f / 64.0f; m_quads[i].verts[1].v = 12.0f / 64.0f;

                m_quads[i].verts[2].x = pos_x + offset + 8; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[2].u = 23.0f / 64.0f; m_quads[i].verts[2].v = 24.0f / 64.0f;

                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;
                m_quads[i].verts[3].u = 15.0f / 64.0f; m_quads[i].verts[3].v = 24.0f / 64.0f;

                offset += 9;
                break;

            case 'B':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 8; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 8; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 8; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 23; m_quads[i].tex_y = 12;

                offset += 9;
                break;

            case 'C':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 8; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 8; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 8; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 30; m_quads[i].tex_y = 12;

                offset += 9;
                break;

            case 'D':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 8; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 8; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 8; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 38; m_quads[i].tex_y = 12;

                offset += 9;
                break;
                break;

            case 'E':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[0].u = 46.0f / 64.0f; m_quads[i].verts[0].v = 12.0f / 64.0f;

                m_quads[i].verts[1].x = pos_x + offset + 8; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[1].u = 54.0f / 64.0f; m_quads[i].verts[1].v = 12.0f / 64.0f;

                m_quads[i].verts[2].x = pos_x + offset + 8; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[2].u = 54.0f / 64.0f; m_quads[i].verts[2].v = 24.0f / 64.0f;

                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;
                m_quads[i].verts[3].u = 46.0f / 64.0f; m_quads[i].verts[3].v = 24.0f / 64.0f;

                offset += 9;
                break;
                break;

            case 'F':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 8; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 8; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 8; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 54; m_quads[i].tex_y = 12;

                offset += 9;
                break;
                break;

            case 'G':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 8; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 8; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 8; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 0; m_quads[i].tex_y = 24;

                offset += 9;
                break;

            case 'H':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 8; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 8; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 8; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 8; m_quads[i].tex_y = 24;

                offset += 9;
                break;

            case 'I':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 4; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 4; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 4; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 15; m_quads[i].tex_y = 24;

                offset += 5;
                break;

            case 'J':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 8; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 8; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 8; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 19; m_quads[i].tex_y = 24;

                offset += 9;
                break;

            case 'K':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 8; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 8; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 8; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 27; m_quads[i].tex_y = 24;

                offset += 9;
                break;

            case 'L':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 8; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 8; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 8; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 35; m_quads[i].tex_y = 24;

                offset += 9;
                break;

            case 'M':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 9; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 9; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 9; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 43; m_quads[i].tex_y = 24;

                offset += 10;
                break;

            case 'N':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 8; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 8; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 8; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 51; m_quads[i].tex_y = 24;

                offset += 9;
                break;

            case 'O':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 8; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 8; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 8; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 0; m_quads[i].tex_y = 36;

                offset += 9;
                break;

            case 'P':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[0].u = 8.0f / 64.0f; m_quads[i].verts[0].v = 36.0f / 64.0f;

                m_quads[i].verts[1].x = pos_x + offset + 8; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[1].u = 16.0f / 64.0f; m_quads[i].verts[1].v = 36.0f / 64.0f;

                m_quads[i].verts[2].x = pos_x + offset + 8; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[2].u = 16.0f / 64.0f; m_quads[i].verts[2].v = 48.0f / 64.0f;

                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;
                m_quads[i].verts[3].u = 8.0f / 64.0f; m_quads[i].verts[3].v = 48.0f / 64.0f;

                //m_quads[i].tex_w = 8; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 8; m_quads[i].tex_y = 36;

                offset += 9;
                break;

            case 'Q':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 9; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 9; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 9; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 16; m_quads[i].tex_y = 36;

                offset += 9;
                break;

            case 'R':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[0].u = 25.0f / 64.0f; m_quads[i].verts[0].v = 36.0f / 64.0f;

                m_quads[i].verts[1].x = pos_x + offset + 8; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[1].u = 33.0f / 64.0f; m_quads[i].verts[1].v = 36.0f / 64.0f;

                m_quads[i].verts[2].x = pos_x + offset + 8; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[2].u = 33.0f / 64.0f; m_quads[i].verts[2].v = 48.0f / 64.0f;

                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;
                m_quads[i].verts[3].u = 25.0f / 64.0f; m_quads[i].verts[3].v = 48.0f / 64.0f;

                offset += 9;
                break;

            case 'S':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[0].u = 33.0f / 64.0f; m_quads[i].verts[0].v = 36.0f / 64.0f;

                m_quads[i].verts[1].x = pos_x + offset + 8; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[1].u = 41.0f / 64.0f; m_quads[i].verts[1].v = 36.0f / 64.0f;

                m_quads[i].verts[2].x = pos_x + offset + 8; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[2].u = 41.0f / 64.0f; m_quads[i].verts[2].v = 48.0f / 64.0f;

                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;
                m_quads[i].verts[3].u = 33.0f / 64.0f; m_quads[i].verts[3].v = 48.0f / 64.0f;

                offset += 9;
                break;

            case 'T':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[0].u = 41.0f / 64.0f; m_quads[i].verts[0].v = 36.0f / 64.0f;

                m_quads[i].verts[1].x = pos_x + offset + 8; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[1].u = 49.0f / 64.0f; m_quads[i].verts[1].v = 36.0f / 64.0f;

                m_quads[i].verts[2].x = pos_x + offset + 8; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[2].u = 49.0f / 64.0f; m_quads[i].verts[2].v = 48.0f / 64.0f;

                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;
                m_quads[i].verts[3].u = 41.0f / 64.0f; m_quads[i].verts[3].v = 48.0f / 64.0f;

                offset += 9;
                break;

            case 'U':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 8; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 8; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 8; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 49; m_quads[i].tex_y = 36;

                offset += 9;
                break;

            case 'V':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 8; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 8; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 8; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 0; m_quads[i].tex_y = 48;

                offset += 9;
                break;

            case 'W':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 9; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 9; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 9; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 8; m_quads[i].tex_y = 48;

                offset += 10;
                break;

            case 'X':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 8; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 8; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 8; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 17; m_quads[i].tex_y = 48;

                offset += 9;
                break;

            case 'Y':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 8; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 8; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 8; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 25; m_quads[i].tex_y = 48;

                offset += 9;
                break;

            case 'Z':
                m_quads[i].verts[0].x = pos_x + offset; m_quads[i].verts[0].y = pos_y;
                m_quads[i].verts[1].x = pos_x + offset + 8; m_quads[i].verts[1].y = pos_y;
                m_quads[i].verts[2].x = pos_x + offset + 8; m_quads[i].verts[2].y = pos_y + 12;
                m_quads[i].verts[3].x = pos_x + offset; m_quads[i].verts[3].y = pos_y + 12;

                //m_quads[i].tex_w = 8; m_quads[i].tex_h = 12;
                //m_quads[i].tex_x = 33; m_quads[i].tex_y = 48;

                offset += 9;
                break;
        }
    }
}

void TextImpl::draw() const {
    C3D_TexBind(0, &text_tex);

    C3D_ImmDrawBegin(GPU_TRIANGLES);

    // We have only one color per Text object
    // TODO color

    for (unsigned int i = 0; i < m_quads_len; ++i) {
        C3D_ImmSendAttrib(m_quads[i].verts[0].x, m_quads[i].verts[0].y, 0.5f, 0.0f);
        C3D_ImmSendAttrib(m_quads[i].verts[0].u, m_quads[i].verts[0].v, 0.0f, 0.0f);

        C3D_ImmSendAttrib(m_quads[i].verts[2].x, m_quads[i].verts[2].y, 0.5f, 0.0f);
        C3D_ImmSendAttrib(m_quads[i].verts[2].u, m_quads[i].verts[2].v, 0.0f, 0.0f);

        C3D_ImmSendAttrib(m_quads[i].verts[1].x, m_quads[i].verts[1].y, 0.5f, 0.0f);
        C3D_ImmSendAttrib(m_quads[i].verts[1].u, m_quads[i].verts[1].v, 0.0f, 0.0f);

        C3D_ImmSendAttrib(m_quads[i].verts[0].x, m_quads[i].verts[0].y, 0.5f, 0.0f);
        C3D_ImmSendAttrib(m_quads[i].verts[0].u, m_quads[i].verts[0].v, 0.0f, 0.0f);

        C3D_ImmSendAttrib(m_quads[i].verts[3].x, m_quads[i].verts[3].y, 0.5f, 0.0f);
        C3D_ImmSendAttrib(m_quads[i].verts[3].u, m_quads[i].verts[3].v, 0.0f, 0.0f);

        C3D_ImmSendAttrib(m_quads[i].verts[2].x, m_quads[i].verts[2].y, 0.5f, 0.0f);
        C3D_ImmSendAttrib(m_quads[i].verts[2].u, m_quads[i].verts[2].v, 0.0f, 0.0f);
    }

    C3D_ImmDrawEnd();
}
