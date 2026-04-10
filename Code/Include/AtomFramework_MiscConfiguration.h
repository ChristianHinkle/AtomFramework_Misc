
#pragma once

#include <AzCore/PlatformDef.h>

#if defined(AZ_MONOLITHIC_BUILD)
#   define ATOMFRAMEWORK_MISC_API
#else
#   if defined(ATOMFRAMEWORK_MISC_EXPORTS)
#       define ATOMFRAMEWORK_MISC_API AZ_DLL_EXPORT
#   else
#       define ATOMFRAMEWORK_MISC_API AZ_DLL_IMPORT
#   endif
#endif
