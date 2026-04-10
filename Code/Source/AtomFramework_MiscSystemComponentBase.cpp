
#include <Source/AtomFramework_MiscSystemComponentBase.h>

#include <AtomFramework_MiscTypeIds.h>
#include <AzCore/Serialization/SerializeContext.h>

namespace AtomFramework
{
    AZ_COMPONENT_IMPL(AtomFramework_MiscSystemComponentBase, "AtomFramework_MiscSystemComponentBase",
        AtomFramework_MiscSystemComponentBaseTypeId);

    void AtomFramework_MiscSystemComponentBase::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<AtomFramework_MiscSystemComponentBase, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void AtomFramework_MiscSystemComponentBase::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("AtomFramework_MiscBaseService"));
    }

    void AtomFramework_MiscSystemComponentBase::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("AtomFramework_MiscBaseService"));
    }

    void AtomFramework_MiscSystemComponentBase::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void AtomFramework_MiscSystemComponentBase::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        // @Christian: TODO: [todo][techdebt][workaround][engine] Fix this properly with an engine pull request to allow multiplayer components to exist in
        // multiple gems without worrying about the order that they are registered in. We add this dependency on the multiplayer system component to make sure
        // it activates (and registers its multiplayer components) before we activate (and register our multiplayer components). In editor, it seems that
        // the AtomFramework_Misc system component activates before the Multiplayer system component, but the opposite happens in non-editor. This would cause the
        // net component IDs to get mismatched between the different targets, and then testing dedicated server in editor would break.
        dependent.push_back(AZ_CRC_CE("MultiplayerService"));
    }

    AtomFramework_MiscSystemComponentBase::AtomFramework_MiscSystemComponentBase()
    {
        if (AtomFramework_MiscInterface::Get() == nullptr)
        {
            AtomFramework_MiscInterface::Register(this);
        }
    }

    AtomFramework_MiscSystemComponentBase::~AtomFramework_MiscSystemComponentBase()
    {
        if (AtomFramework_MiscInterface::Get() == this)
        {
            AtomFramework_MiscInterface::Unregister(this);
        }
    }

    void AtomFramework_MiscSystemComponentBase::Init()
    {
    }

    void AtomFramework_MiscSystemComponentBase::Activate()
    {
        AtomFramework_MiscRequestBus::Handler::BusConnect();
        AZ::TickBus::Handler::BusConnect();
    }

    void AtomFramework_MiscSystemComponentBase::Deactivate()
    {
        AZ::TickBus::Handler::BusDisconnect();
        AtomFramework_MiscRequestBus::Handler::BusDisconnect();
    }

    void AtomFramework_MiscSystemComponentBase::OnTick([[maybe_unused]] float deltaTime, [[maybe_unused]] AZ::ScriptTimePoint time)
    {
    }
}
