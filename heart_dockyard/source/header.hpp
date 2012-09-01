#ifndef __HEADER_HPP__
#define __HEADER_HPP__

#ifdef WIN32
#	include <windows.h>
#endif // WIN32

// OGRE
#include <Ogre.h>

#ifndef RENDER_API
#   define RENDER_API "Direct3D9" // "Direct3D9" // "GL"
#endif

#ifndef _DEBUG
#	pragma comment(lib, "OgreMain.lib")
#   define RENDER_SYSTEM "RenderSystem_"RENDER_API
#else
#	pragma comment(lib, "OgreMain_d.lib")
#   define RENDER_SYSTEM "RenderSystem_"RENDER_API"_d"
#endif

// Google Test
#include "gtest/gtest.h"

// heart
#include "heart.hpp"

#endif // __HEADER_HPP__