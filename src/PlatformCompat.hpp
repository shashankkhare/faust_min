#ifndef PLATFORM_COMPAT_HPP
#define PLATFORM_COMPAT_HPP

// Match the same convention as faust/export.h to avoid redefinition warnings:
// - Windows (MSVC + MinGW): no visibility attributes needed
// - Other platforms: explicit default visibility for -fvisibility=hidden
#ifndef FAUST_API
#if defined(_WIN32)
#define FAUST_API
#else
#define FAUST_API __attribute__((visibility("default")))
#endif
#endif

#endif
