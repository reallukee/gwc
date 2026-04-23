//
// :.:.:.:.:.
// GWC.Native
// v0.3.2
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// canvas_macros.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_CANVAS_MACROS_HPP
#define GWC_CANVAS_MACROS_HPP

#ifdef __cplusplus

#include "macros.hpp"

#include "Color.hpp"

#include "CanvasHost.clr.hpp"

#ifndef CC_CANVAS_VOID_CPP
#define CC_CANVAS_VOID_CPP(canvas) \
    CC_VOID_CPP(CanvasHost, canvas)
#endif // !CC_CANVAS_VOID_CPP

#ifndef CC_CANVAS_BOOL_CPP
#define CC_CANVAS_BOOL_CPP(canvas) \
    CC_BOOL_CPP(CanvasHost, canvas)
#endif // !CC_CANVAS_BOOL_CPP

#ifndef CC_CANVAS_INT_CPP
#define CC_CANVAS_INT_CPP(canvas) \
    CC_INT_CPP(CanvasHost, canvas)
#endif // !CC_CANVAS_INT_CPP



#ifndef CCI_CANVAS_VOID_CPP
#define CCI_CANVAS_VOID_CPP(canvas, target) \
    CCI_VOID_CPP(CanvasHost, canvas, target)
#endif // !CCI_CANVAS_VOID_CPP

#ifndef CCI_CANVAS_BOOL_CPP
#define CCI_CANVAS_BOOL_CPP(canvas, target) \
    CCI_BOOL_CPP(CanvasHost, canvas, target)
#endif // !CCI_CANVAS_BOOL_CPP

#ifndef CCI_CANVAS_INT_CPP
#define CCI_CANVAS_INT_CPP(canvas, target) \
    CCI_INT_CPP(CanvasHost, canvas, target)
#endif // !CCI_CANVAS_INT_CPP



#ifndef CCI_CANVAS_GET_COLOR_CPP
#define CCI_CANVAS_GET_COLOR_CPP(canvas, target) \
    CCI_GET_COLOR_CPP(CanvasHost, canvas, target, color)
#endif // !CCI_CANVAS_GET_COLOR_CPP

#ifndef CCI_CANVAS_SET_COLOR_CPP
#define CCI_CANVAS_SET_COLOR_CPP(canvas, target, color) \
    CCI_SET_COLOR_CPP(CanvasHost, canvas, target, color)
#endif // !CCI_CANVAS_SET_COLOR_CPP

#endif // __cplusplus

#endif // !GWC_CANVAS_MACROS_HPP
