#pragma once

#include <llvm/Support/raw_ostream.h>
#include <istream>

namespace lcc
{
void compile(std::istream & in, llvm::raw_ostream & out, const std::string & module_name);
}