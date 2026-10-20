// SPDX-License-Identifier: Apache-2.0
// Copyright (C) 2025-2026 Advanced Micro Devices, Inc. All rights reserved
#define XDP_PLUGIN_SOURCE

#include "core/common/api/elf_int.h"

#include "elf_helper.h"

#include <sstream>

namespace xdp {

std::vector<char>
get_elf_buffer(void* elf_handle)
{
  auto* impl = static_cast<xrt::elf_impl*>(elf_handle);
  std::stringstream ss;
  ss << std::noskipws;
  impl->save(ss);

  auto str = ss.str();
  return {str.begin(), str.end()};
}

} // namespace xdp
