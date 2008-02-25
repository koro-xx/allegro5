/*         ______   ___    ___
 *        /\  _  \ /\_ \  /\_ \
 *        \ \ \L\ \\//\ \ \//\ \      __     __   _ __   ___
 *         \ \  __ \ \ \ \  \ \ \   /'__`\ /'_ `\/\`'__\/ __`\
 *          \ \ \/\ \ \_\ \_ \_\ \_/\  __//\ \L\ \ \ \//\ \L\ \
 *           \ \_\ \_\/\____\/\____\ \____\ \____ \ \_\\ \____/
 *            \/_/\/_/\/____/\/____/\/____/\/___L\ \/_/ \/___/
 *                                           /\____/
 *                                           \_/__/
 *
 *      Main header file for all OpenGL drivers.
 *
 *      By Milan Mimica.
 *
 */


#ifndef A5_OPENGL_ALLEGRO_H
#define A5_OPENGL_ALLEGRO_H

#include "allegro5/base.h"


AL_BEGIN_EXTERN_C

#ifdef ALLEGRO_MACOSX

#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glext.h>

#ifndef GL_GLEXT_PROTOTYPES
#define GL_GLEXT_PROTOTYPES
#endif

#else /* ALLEGRO_MACOSX */

/* HACK: Prevent both Mesa and SGI's broken headers from screwing us */
#define __glext_h_
#define __glxext_h_
#include <GL/gl.h>
#undef  __glext_h_
#undef  __glxext_h_

#endif /* ALLEGRO_MACOSX */

#include "allegro5/opengl/gl_ext.h"

#ifdef ALLEGRO_WINDOWS
	
/* Missing #defines from Mingw */
#ifndef PFD_SWAP_LAYER_BUFFERS
#define PFD_SWAP_LAYER_BUFFERS  0x00000800
#endif

#ifndef PFD_GENERIC_ACCELERATED
#define PFD_GENERIC_ACCELERATED 0x00001000
#endif

#ifndef PFD_SUPPORT_DIRECTDRAW
#define PFD_SUPPORT_DIRECTDRAW  0x00002000
#endif

#ifndef CDS_FULLSCREEN
#define CDS_FULLSCREEN      0x00000004
#endif

#ifndef ENUM_CURRENT_SETTINGS
#define ENUM_CURRENT_SETTINGS       ((DWORD)-1)
#endif

#endif /* #ifdef ALLEGRO_WINDOWS */

#if defined ALLEGRO_WINDOWS
	#define ALLEGRO_DEFINE_PROC_TYPE(type, name, args) \
		typedef type (APIENTRY * name) args;
#else
	#define ALLEGRO_DEFINE_PROC_TYPE(type, name, args) \
		typedef type (*name) args;
#endif


typedef struct OGL_PIXEL_FORMAT {
   int format;
   int doublebuffered;
   int depth_size;
   int rmethod;
   int stencil_size;
   int r_shift, g_shift, b_shift, a_shift;
   int r_size, g_size, b_size, a_size;
   int fullscreen;
   int sample_buffers;
   int samples;
   int float_color;
   int float_depth;
} OGL_PIXEL_FORMAT;


/* Puiblic OpenGL-related API */
AL_FUNC(float,                 al_opengl_version,                (void));
AL_FUNC(int,                   al_is_opengl_extension_supported, (AL_CONST char *extension));
AL_FUNC(void*,                 al_get_opengl_proc_address,       (AL_CONST char *name));
AL_FUNC(ALLEGRO_OGL_EXT_LIST*, al_get_opengl_extension_list,     (void));


AL_END_EXTERN_C

#endif /* #ifndef A5_OPENGL_ALLEGRO_H */
