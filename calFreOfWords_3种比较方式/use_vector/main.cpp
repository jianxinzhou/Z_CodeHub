#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS
#endif /* __STDC_FORMAT_MACROS */
#include <inttypes.h>
#include "WordFrequency.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <stdexcept>

using namespace std;

int64_t getUTime();

int main(int argc, char const *argv[])
{
	if(argc < 3)
	{
		fprintf(stderr, "Usage: %s Dict stopList", argv[0]);
		exit(EXIT_FAILURE);
	}

	WordFrequency wf(argv[1], argv[2]);

	int64_t startTime = getUTime();

	wf.readStopList();
	wf.readWordFile();

	int64_t middleTime = getUTime();

	wf.sortWordsByFrequency();

	int64_t endTime = getUTime();

	printf("读取文件: %"PRId64" ms\n", (middleTime - startTime) / 1000);
	printf("排序: %"PRId64" ms\n", (endTime - middleTime) / 1000);

	wf.printWordFrequency();

}


int64_t getUTime()
{
    struct timeval tv;
    ::memset(&tv, 0, sizeof tv);
    if(::gettimeofday(&tv, NULL) == -1)
    {
        throw runtime_error("gettimeofday");
    }
    int64_t t = tv.tv_usec;
    t += tv.tv_sec * 1000 * 1000;
    return t;
}
