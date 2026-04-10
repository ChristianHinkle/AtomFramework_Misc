
#pragma once

#include <AzCore/Module/Module.h>
#include <AzCore/Memory/Memory_fwd.h>
#include <AzCore/RTTI/RTTIMacros.h>
#include <AzCore/RTTI/TypeInfoSimple.h>
#include <AtomFramework_MiscConfiguration.h>

namespace AtomFramework
{
    class ATOMFRAMEWORK_MISC_API AtomFramework_MiscModuleInterface : public AZ::Module
    {
    public:
        AZ_TYPE_INFO_WITH_NAME_DECL_API(ATOMFRAMEWORK_MISC_API, AtomFramework_MiscModuleInterface);
        AZ_RTTI_NO_TYPE_INFO_DECL();
        AZ_CLASS_ALLOCATOR_DECL;

        AtomFramework_MiscModuleInterface();

        AZ::ComponentTypeList GetRequiredSystemComponents() const override;
    };
}
