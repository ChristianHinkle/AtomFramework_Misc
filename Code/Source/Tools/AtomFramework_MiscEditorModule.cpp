
#include <Source/AtomFramework_MiscModuleInterface.h>
#include <AtomFramework_MiscTypeIds.h>
#include <Source/Tools/AtomFramework_MiscEditorSystemComponent.h>

namespace AtomFramework
{
    class AtomFramework_MiscEditorModule : public AtomFramework_MiscModuleInterface
    {
    public:
        AZ_RTTI(AtomFramework_MiscEditorModule, AtomFramework_MiscEditorModuleTypeId, AtomFramework_MiscModuleInterface);
        AZ_CLASS_ALLOCATOR(AtomFramework_MiscEditorModule, AZ::SystemAllocator);

        AtomFramework_MiscEditorModule()
        {
            // Append editor-only items.
            m_descriptors.insert(m_descriptors.end(), {
                AtomFramework_MiscEditorSystemComponent::CreateDescriptor(),
                }
            );
        }

        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            AZ::ComponentTypeList list = AtomFramework_MiscModuleInterface::GetRequiredSystemComponents();

            // Append editor-only items.
            list.insert(list.end(), {
                azrtti_typeid<AtomFramework_MiscEditorSystemComponent>(),
                }
            );

            return list;
        }
    };
}

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME, _Editor), AtomFramework::AtomFramework_MiscEditorModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_AtomFramework_Misc_Editor, AtomFramework::AtomFramework_MiscEditorModule)
#endif
