/*
 * Copyright (c) 2026 Shashank Khare
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

#ifndef FAUST_LOG_HPP
#define FAUST_LOG_HPP

#include <cstdio>
#include <cstdarg>
#include <cstring>

#if defined(__ANDROID__)
#include <android/log.h>
#define FM_LOG_TAG "FaustMin"
#define FM_LOGI(...) __android_log_print(ANDROID_LOG_INFO,  FM_LOG_TAG, __VA_ARGS__)
#define FM_LOGW(...) __android_log_print(ANDROID_LOG_WARN,  FM_LOG_TAG, __VA_ARGS__)
#define FM_LOGE(...) __android_log_print(ANDROID_LOG_ERROR, FM_LOG_TAG, __VA_ARGS__)

#elif defined(__APPLE__)
#include <TargetConditionals.h>
#include <os/log.h>
#define FM_LOGI(...) do { os_log(OS_LOG_DEFAULT, "[FaustMin INFO] " __VA_ARGS__); printf("[FaustMin INFO] " __VA_ARGS__); printf("\n"); fflush(stdout); } while(0)
#define FM_LOGW(...) do { os_log(OS_LOG_DEFAULT, "[FaustMin WARN] " __VA_ARGS__); printf("[FaustMin WARN] " __VA_ARGS__); printf("\n"); fflush(stdout); } while(0)
#define FM_LOGE(...) do { os_log_error(OS_LOG_DEFAULT, "[FaustMin ERROR] " __VA_ARGS__); fprintf(stderr, "[FaustMin ERROR] " __VA_ARGS__); fprintf(stderr, "\n"); fflush(stderr); } while(0)

#elif defined(_WIN32) || defined(_WIN64)
#include <windows.h>
inline void fm_log_win32(const char* prefix, const char* fmt, ...) {
    char buf[1024];
    int len = snprintf(buf, sizeof(buf), "%s ", prefix);
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf + len, sizeof(buf) - len, fmt, args);
    va_end(args);
    strcat(buf, "\n");
    OutputDebugStringA(buf);
    printf("%s", buf);
    fflush(stdout);
}
#define FM_LOGI(...) fm_log_win32("[FaustMin INFO]", __VA_ARGS__)
#define FM_LOGW(...) fm_log_win32("[FaustMin WARN]", __VA_ARGS__)
#define FM_LOGE(...) fm_log_win32("[FaustMin ERROR]", __VA_ARGS__)

#else // Linux and other POSIX platforms
#define FM_LOGI(...) do { printf("[FaustMin INFO] "); printf(__VA_ARGS__); printf("\n"); fflush(stdout); } while(0)
#define FM_LOGW(...) do { printf("[FaustMin WARN] "); printf(__VA_ARGS__); printf("\n"); fflush(stdout); } while(0)
#define FM_LOGE(...) do { fprintf(stderr, "[FaustMin ERROR] "); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\n"); fflush(stderr); } while(0)
#endif

#endif // FAUST_LOG_HPP
