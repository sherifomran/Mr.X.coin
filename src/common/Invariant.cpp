// Copyright (c) 2012-2018, The CryptoNote developers, The Bytecoin developers.
// Licensed under the GNU Lesser General Public License. See LICENSE for details.

#include "Invariant.hpp"
#include <sstream>
#include <stdexcept>
#include "string.hpp"

#ifndef __EMSCRIPTEN__
#define BOOST_STACKTRACE_GNU_SOURCE_NOT_REQUIRED 1
#include <boost/stacktrace.hpp>
#endif
void common::invariant_violated(const char *expr, const char *file, int line, const std::string &msg) {
	std::stringstream str;
#ifndef __EMSCRIPTEN__
	str << boost::stacktrace::stacktrace();
#endif
	throw std::logic_error("Invariant " + std::string(expr) + " violated at " + common::to_string(line) + " " + msg +
	                       " stacktrace:\n" + str.str());
}
