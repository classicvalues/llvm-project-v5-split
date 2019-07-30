//===- LLDBTableGenBackends.h -----------------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains the declarations for all of the LLDB TableGen
// backends. A "TableGen backend" is just a function.
//
// See "$LLVM_ROOT/utils/TableGen/TableGenBackends.h" for more info.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LLDB_UTILS_TABLEGEN_TABLEGENBACKENDS_H
#define LLVM_LLDB_UTILS_TABLEGEN_TABLEGENBACKENDS_H

#include <map>
#include <string>

namespace llvm {
class raw_ostream;
class RecordKeeper;
class Record;
} // namespace llvm

using llvm::raw_ostream;
using llvm::RecordKeeper;

namespace lldb_private {

/// Map of names to their associated records. This map also ensures that our
/// records are sorted in a deterministic way.
typedef std::map<std::string, std::vector<llvm::Record *>> RecordsByName;

void EmitOptionDefs(RecordKeeper &RK, raw_ostream &OS);
void EmitPropertyDefs(RecordKeeper &RK, raw_ostream &OS);
void EmitPropertyEnumDefs(RecordKeeper &RK, raw_ostream &OS);

} // namespace lldb_private

#endif
