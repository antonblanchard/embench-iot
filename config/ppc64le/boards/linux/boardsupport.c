/* Copyright (C) 2017 Embecosm Limited and University of Bristol

   Contributor Graham Markall <graham.markall@embecosm.com>

   This file is part of Embench and was formerly part of the Bristol/Embecosm
   Embedded Benchmark Suite.

   SPDX-License-Identifier: GPL-3.0-or-later */

#include <time.h>
#include <support.h>

void
initialise_board ()
{
}

static struct timespec before, after;

void __attribute__ ((noinline)) __attribute__ ((externally_visible))
start_trigger ()
{
	clock_gettime(CLOCK_MONOTONIC, &before);
}

void __attribute__ ((noinline)) __attribute__ ((externally_visible))
stop_trigger ()
{
	unsigned long elapsed;

	clock_gettime(CLOCK_MONOTONIC, &after);
	elapsed = (after.tv_sec - before.tv_sec) * 1000000000UL +
		(after.tv_nsec - before.tv_nsec);
	printf("Duration: %.2f\n", 1.0*elapsed/1000000000UL);
}
