// SPDX-License-Identifier: GPL-3.0-or-later AND MIT
/* Copyright (C) 2021-2026 red031000
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef JSON_H
#define JSON_H

#include "options.h"

struct JsonToCellOptions *ParseNCERJson(char *path);
char *GetNCERJson(struct JsonToCellOptions *options);
struct JsonToScreenOptions *ParseNSCRJson(char *path);
struct JsonToAnimationOptions *ParseNANRJson(char *path);
char *GetNANRJson(struct JsonToAnimationOptions *options);
void FreeNCERCell(struct JsonToCellOptions *options);
void FreeNSCRScreen(struct JsonToScreenOptions *options);
void FreeNANRAnimation(struct JsonToAnimationOptions *options);
char *GetNtrFontMetadataJson(struct NtrFontMetadata *metadata);
struct NtrFontMetadata *ParseNtrFontMetadataJson(char *path);

#endif //JSON_H
