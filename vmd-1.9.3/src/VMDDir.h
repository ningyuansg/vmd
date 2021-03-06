/***************************************************************************
 *cr
 *cr            (C) Copyright 1995-2016 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/

/***************************************************************************
 * RCS INFORMATION:
 *
 *      $RCSfile: VMDDir.h,v $
 *      $Author: johns $        $Locker:  $             $State: Exp $
 *      $Revision: 1.13 $       $Date: 2016/11/28 03:05:05 $
 *
 ***************************************************************************
 * DESCRIPTION:
 *  Low level platform-specific code for scanning/querying directories.
 ***************************************************************************/

#include <stdio.h>

#if defined(_MSC_VER)
#include <windows.h>

/// Win32 directory traversal handle
typedef struct {
  HANDLE h;
  WIN32_FIND_DATA fd;
} VMDDIR;

#else
#include <dirent.h>

/// Unix directory traversal handle
typedef struct {
  DIR * d;
} VMDDIR;
#endif


VMDDIR * vmd_opendir(const char *);
char * vmd_readdir(VMDDIR *);
void vmd_closedir(VMDDIR *);
int vmd_file_is_executable(const char * filename);
