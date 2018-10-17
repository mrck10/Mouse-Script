#pragma once
#ifndef MOUSEHAX_ARGV_RANGE
#define MOUSEHAX_ARGV_RANGE
class argv_range {
public:
	argv_range(int argc, const char * const argv[]);

	const char * const *begin() const;
	const char * const *end() const;

private:
	const int argc_;
	const char * const *argv_;
};
#endif
