#pragma once

#ifdef SR_PLATFORM_WINDOWS
	#ifdef NOMINMAX
		#define NOMINMAX
	#endif // NOMINMAX
#endif // SR_PLATFORM_WINDOWS

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "SirenRenderer/Log.h"

#ifdef SR_PLATFORM_WINDOWS
	#include <Windows.h>
#endif
