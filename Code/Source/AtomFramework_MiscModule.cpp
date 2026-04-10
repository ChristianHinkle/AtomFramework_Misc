
#include <Source/AtomFramework_MiscModuleInterface.h>
#include <AtomFramework_MiscTypeIds.h>
#include <Source/AtomFramework_MiscSystemComponent.h>

namespace AtomFramework
{
    class AtomFramework_MiscModule : public AtomFramework_MiscModuleInterface
    {
    public:
        AZ_RTTI(AtomFramework_MiscModule, AtomFramework_MiscModuleTypeId, AtomFramework_MiscModuleInterface);
        AZ_CLASS_ALLOCATOR(AtomFramework_MiscModule, AZ::SystemAllocator);

        AtomFramework_MiscModule()
        {
            // Append non-editor items.
            m_descriptors.insert(m_descriptors.end(), {
                AtomFramework_MiscSystemComponent::CreateDescriptor(),
                }
            );
        }

        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            AZ::ComponentTypeList list = AtomFramework_MiscModuleInterface::GetRequiredSystemComponents();

            // Append non-editor items.
            list.insert(list.end(), {
                azrtti_typeid<AtomFramework_MiscSystemComponent>(),
                }
            );

            return list;
        }
    };
}

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME), AtomFramework::AtomFramework_MiscModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_AtomFramework_Misc, AtomFramework::AtomFramework_MiscModule)
#endif
