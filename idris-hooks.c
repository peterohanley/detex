#define DEBUG 0
#if DEBUG
#include <stdio.h>
#endif
#include "detex.h"

// FIXME memory leak because these are never freed
DETEX_API
detexTexture *
makeDetexETC2(uint8_t *buf, int w, int h)
{
  detexTexture *dt = malloc(sizeof(detexTexture));
  dt->format = DETEX_TEXTURE_FORMAT_ETC2;
  dt->data = buf;
  dt->width = w;
  dt->height = h;
  dt->width_in_blocks = w/4;
  dt->height_in_blocks = h/4;
#if DEBUG
  printf("%s: buf=%p\n", __FUNCTION__, buf);
  for (int i = 0; i < 16; i++) {
    printf("%02x ", buf[i]);
  }
  puts("");
#endif
  return dt;
}

// FIXME memory leak because these are never freed
// FIXME merge copied code into a helper function
DETEX_API
detexTexture *
makeDetexETC2_RGBA8(uint8_t *buf, int w, int h)
{
  detexTexture *dt = malloc(sizeof(detexTexture));
  dt->format = DETEX_TEXTURE_FORMAT_ETC2_EAC;
  dt->data = buf;
  dt->width = w;
  dt->height = h;
  dt->width_in_blocks = w/4;
  dt->height_in_blocks = h/4;
#if DEBUG
  printf("%s: buf=%p\n", __FUNCTION__, buf);
  for (int i = 0; i < 16; i++) {
    printf("%02x ", buf[i]);
  }
  puts("");
#endif
  return dt;
}

DETEX_API
void
freeDetexTexture(detexTexture *dt)
{
  free(dt);
}
