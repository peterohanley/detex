#include "detex.h"
#include <string.h>
#include <assert.h>

DETEX_API
int
flipVerticalRGBA8(uint8_t *buf, int width, int height)
{
  if (width <= 0) return -1;
  if (height <= 0) return -1;
  uint8_t *buf2 = malloc(sizeof(uint32_t) * width * height);
  assert(buf2);
  memcpy(buf2, buf, width*height*4);
  int stride = width*4;
  for (int i = 0; i < height; i++) {
    memcpy(buf+(stride*i), buf2+((height-1)-i)*stride, stride);
  }
  free(buf2);
  return 0;
}

DETEX_API
detexTexture *
makeDetexTexture(uint8_t *buf)
{
  detexTexture *dt = malloc(sizeof(detexTexture));
  dt->data = buf;
  return dt;
}

DETEX_API
void
freeDetexTexture(detexTexture *dt)
{
  free(dt);
}

DETEX_API
int
detexFormatRGB8(void)
{
  return DETEX_PIXEL_FORMAT_RGB8;
}
DETEX_API
int
detexFormatRGBA8(void)
{
  return DETEX_PIXEL_FORMAT_RGBA8;
}
DETEX_API
int
detexFormatETC1(void)
{
  return DETEX_TEXTURE_FORMAT_ETC1;
}
DETEX_API
int
detexFormatETC2(void)
{
  return DETEX_TEXTURE_FORMAT_ETC2;
}
DETEX_API
int
detexFormatETC2_EAC(void)
{
  return DETEX_TEXTURE_FORMAT_ETC2_EAC;
}
