
#include <Source/Tools/AtomFramework_MiscEditorSystemComponent.h>

#include <AtomFramework_MiscTypeIds.h>
#include <AzCore/Serialization/SerializeContext.h>

namespace AtomFramework
{
    AZ_COMPONENT_IMPL(AtomFramework_MiscEditorSystemComponent, "AtomFramework_MiscEditorSystemComponent",
        AtomFramework_MiscEditorSystemComponentTypeId, BaseSystemComponent);

    void AtomFramework_MiscEditorSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<AtomFramework_MiscEditorSystemComponent, BaseSystemComponent>()
                ->Version(0)
                ;
        }
    }

    void AtomFramework_MiscEditorSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        BaseSystemComponent::GetProvidedServices(provided);
        provided.push_back(AZ_CRC_CE("AtomFramework_MiscEditorService"));
    }

    void AtomFramework_MiscEditorSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        BaseSystemComponent::GetIncompatibleServices(incompatible);
        incompatible.push_back(AZ_CRC_CE("AtomFramework_MiscEditorService"));
    }

    void AtomFramework_MiscEditorSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        BaseSystemComponent::GetRequiredServices(required);
    }

    void AtomFramework_MiscEditorSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        BaseSystemComponent::GetDependentServices(dependent);
    }

    AtomFramework_MiscEditorSystemComponent::AtomFramework_MiscEditorSystemComponent() = default;
    AtomFramework_MiscEditorSystemComponent::~AtomFramework_MiscEditorSystemComponent() = default;

    void AtomFramework_MiscEditorSystemComponent::Activate()
    {
        BaseSystemComponent::Activate();

        AzToolsFramework::EditorEvents::Bus::Handler::BusConnect();
    }

    void AtomFramework_MiscEditorSystemComponent::Deactivate()
    {
        AzToolsFramework::EditorEvents::Bus::Handler::BusDisconnect();

        BaseSystemComponent::Deactivate();
    }
}
