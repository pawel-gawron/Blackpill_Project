/*
 * bitmap.c
 *
 *  Created on: Jan 10, 2022
 *      Author: Paweł
 */

#include "bitmap.h"

const uint8_t logo[] = {
		0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x7F, 0xFF, 0xFF, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xFF,
		0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xF8, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00,
		0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x07, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x00,
		0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x80,
		0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x0F, 0xFF, 0xC3, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x0F, 0xFE, 0x00, 0x0F, 0x7F, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xF0, 0x1F, 0xFE, 0x00, 0x0E, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0,
		0x3F, 0xFE, 0x0E, 0x0E, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x3F, 0xFE, 0x1F, 0x0E,
		0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0xF8, 0x7F, 0xFE, 0x3F, 0x8E, 0x00, 0x00, 0x00, 0x00,
		0x01, 0xFF, 0xFF, 0xFC, 0x7F, 0xFE, 0x1F, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFC,
		0xFF, 0xFE, 0x04, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFE, 0xFF, 0xFE, 0x00, 0x0E,
		0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFE, 0x00, 0xFE, 0x00, 0x0F, 0xFF, 0xFF, 0x5F, 0xFD,
		0x80, 0x00, 0x7F, 0xFE, 0x00, 0x1E, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x00, 0x7F, 0xFF,
		0x00, 0x1E, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0x71, 0xC7, 0xFF, 0xFF, 0x00, 0x1E, 0x00, 0x0F,
		0xFF, 0xFF, 0xFF, 0xFF, 0xF3, 0xCF, 0xFF, 0xFF, 0x00, 0x1E, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF,
		0xF3, 0xCF, 0xFF, 0xFF, 0x00, 0x1E, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xF3, 0xCF, 0xFF, 0xFF,
		0x00, 0x1E, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xF3, 0xCF, 0xFF, 0xFF, 0x00, 0x1E, 0x00, 0x0F,
		0xFF, 0xFF, 0xFF, 0xFF, 0xF3, 0xCF, 0xFF, 0xFF, 0x00, 0x1E, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF,
		0xE3, 0xCF, 0x7F, 0xFF, 0x00, 0x1E, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xC7, 0xC2, 0x7F, 0xFF,
		0x00, 0x1E, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0x87, 0xE0, 0xFF, 0xFF, 0x0E, 0x3E, 0x00, 0x0F,
		0xFF, 0xFF, 0xFA, 0xFF, 0x87, 0xF3, 0xFF, 0xFE, 0xFF, 0xFE, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00,
		0x01, 0xFF, 0xFF, 0xFE, 0xFF, 0xFE, 0x04, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFE,
		0x7F, 0xFE, 0x1F, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFC, 0x7F, 0xFE, 0x3F, 0x8E,
		0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFC, 0x3F, 0xFE, 0x1F, 0x8E, 0x00, 0x00, 0x00, 0x00,
		0x7F, 0xFF, 0xFF, 0xF8, 0x3F, 0xFE, 0x0E, 0x0E, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8,
		0x1F, 0xFE, 0x00, 0x0E, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x0F, 0xFE, 0x00, 0x0F,
		0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x0F, 0xFF, 0xF0, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xE0, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0,
		0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x01, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x00,
		0x00, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x00, 0x00, 0x0F, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x00,
		0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
		0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0xFE,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x00
};