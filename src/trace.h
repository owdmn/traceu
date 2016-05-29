/*
 *	strace.h
 *	Definitions and prototypes related to tracing simplices in space
 *	Author: Oliver Wiedemann
 */


#ifndef __TRACE_H__
#define __TRACE_H__

#include <stdbool.h>
#include "simplex.h"

typedef struct {
	int		samplerate;
	bool	(*cont_tracing)(simplex *);
} options;

void trace(simplex *, options *);

#endif /* __TRACE_H__ */
