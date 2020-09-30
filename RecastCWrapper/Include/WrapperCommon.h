#ifndef WRAPPER_COMMON_H
#define WRAPPER_COMMON_H


#if _MSC_VER
#define EXPORT_API extern "C" __declspec(dllexport)
#else
#define
#define EXPORT_API extern "C"
#endif

#endif