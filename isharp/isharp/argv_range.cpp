#include "stdafx.h"
#include "argv_range.h"

argv_range::argv_range(int argc, const char * const argv[])
	: argc_(argc), argv_(argv)
{
}

const char * const * argv_range::begin() const { return argv_; }

const char * const * argv_range::end() const { return argv_ + argc_; }
