
#include <Source/AtomFramework_MiscModuleInterface.h>

#include <AzCore/Memory/Memory.h>

#include <AtomFramework_MiscTypeIds.h>

#include <Source/AtomFramework_MiscSystemComponent.h>

namespace AtomFramework
{
    AZ_TYPE_INFO_WITH_NAME_IMPL(AtomFramework_MiscModuleInterface, "AtomFramework_MiscModuleInterface", AtomFramework_MiscModuleInterfaceTypeId);
    AZ_RTTI_NO_TYPE_INFO_IMPL(AtomFramework_MiscModuleInterface, AZ::Module);
    AZ_CLASS_ALLOCATOR_IMPL(AtomFramework_MiscModuleInterface, AZ::SystemAllocator);

    AtomFramework_MiscModuleInterface::AtomFramework_MiscModuleInterface()
    {
        // Append all items used by both editor and non-editor targets.
        m_descriptors.insert(m_descriptors.end(), {
            AtomFramework_MiscSystemComponent::CreateDescriptor(),
            }
        );
    }

    AZ::ComponentTypeList AtomFramework_MiscModuleInterface::GetRequiredSystemComponents() const
    {
        // Append all items used by both editor and non-editor targets.
        return AZ::ComponentTypeList{
        };
    }
}
