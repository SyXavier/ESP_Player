/*
 * MIT License
 * Copyright (c) 2021 SyXavier
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "HAL.h"

uint32_t ram_heap_size()
{
	return ESP.getHeapSize();
}

uint32_t ram_free_heap_size()
{
	return ESP.getFreeHeap();
}

uint32_t ram_min_free_heap_size()
{
	return ESP.getMinFreeHeap();
}

uint32_t ram_max_alloc_heap_size()
{
	return ESP.getMaxAllocHeap();
}

uint32_t psram_size()
{
	return ESP.getPsramSize();
}

uint32_t psram_free_size()
{
	return ESP.getFreePsram();
}

uint32_t psram_min_free_size()
{
	return ESP.getMinFreePsram();
}

uint32_t psram_max_alloc_size()
{
	return ESP.getMaxAllocPsram();
}


