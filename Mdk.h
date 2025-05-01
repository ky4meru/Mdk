/**
 * @file Mdk.h
 * @author Ky4meru (@ky4meru)
 * @brief Malware Development Kit in a C header only.
 * @version 0.1
 * @date 2025-05-01
 * @copyright Copyright (c) 2025
 */

#ifndef _MDK_H_
#define _MDK_H_

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <Windows.h>

/**
 * @brief 
 * 
 * @param lhs 
 * @param rhs 
 * @param count 
 * @return INT 
 */
INT MdkCompareMemory(LPCVOID lhs, LPCVOID rhs, SIZE_T count)
{
    LPCBYTE p1 = (LPCBYTE)lhs;
    LPCBYTE p2 = (LPCBYTE)rhs;

    for (SIZE_T i = 0; i < count; ++i)
    {
        if (p1[i] < p2[i])
        {
            return -1;
        }
        else if (p1[i] > p2[i])
        {
            return 1;
        }
    }

    return 0;
}

/**
 * @brief 
 * 
 * @param dest 
 * @param src 
 * @param count 
 * @return VOID 
 */
VOID MdkCopyMemory(LPVOID dest, LPCVOID src, SIZE_T count)
{
    PBYTE bsrc = (PBYTE)src;
    PBYTE bdest = (PBYTE)dest;

    for (SIZE_T i = 0; i < count; ++i)
    {
        bdest[i] = bsrc[i];
    }
}

#ifdef __cplusplus
}
#endif

#endif // _MDK_H_