/*
 * ECOS - Embedded Conic Solver.
 * Copyright (C) 2011-12 Alexander Domahidi [domahidi@control.ee.ethz.ch],
 * Automatic Control Laboratory, ETH Zurich.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


/* data type definitions used with ECOS */

#ifndef __GLBLOPTS_H__
#define __GLBLOPTS_H__

#include "SuiteSparse_config.h"

/* DATA TYPES ---------------------------------------------------------- */
typedef double pfloat;              /* for numerical values  */

/* SET PRINT LEVEL ----------------------------------------------------- */
#define PRINTLEVEL (3)     /* 0: no prints					             */
						   /* 1: only final info				         */
                           /* 2: progress print per iteration            */
						   /* 3: debug level, enables print & dump fcns. */

/* SET PROFILING LEVEL ------------------------------------------------- */
#define PROFILING (2)      /* 0: no timing information				     */
                           /* 1: runtime (divided in setup and solve)    */
                           /* 2: detailed profiling                      */

/* SET DEBUG LEVEL ----------------------------------------------------- */
#define DEBUG (1)          /* 0: no debugging information                */
                           /* 1: debug info & dump intermediate results  */

/* NAN ----------------------------------------------------------------- */
#define NAN ((double)0x7ff8000000000000)

/* use this if pfloat is float: */
/* #define NAN ((float)0x7fc00000) */

/* USE SAME NUMBER REPRESENTATION FOR INDEXING AS AMD AND LDL ---------- */
typedef SuiteSparse_long idxint;

/* SYSTEM INCLUDE IF COMPILING FOR MATLAB ------------------------------ */
#ifdef MATLAB_MEX_FILE
#include "mex.h"
#endif

/* SYSTEM INCLUDES FOR PRINTING ---------------------------------------- */
#if PRINTLEVEL > 0
#include <stdio.h>
#ifndef MATLAB_MEX_FILE
#define PRINTTEXT printf
#else
#include "mex.h"
#define PRINTTEXT mexPrintf
#endif
#endif

/* CHOOSE RIGHT MEMORY MANAGER ----------------------------------------- */
#ifdef MATLAB_MEX_FILE
#define MALLOC mxMalloc
#define FREE mxFree
#else 
#define MALLOC malloc
#define FREE free
#endif

#endif