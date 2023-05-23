cmake_minimum_required(VERSION 3.14.0)
set(CMAKE_OSX_DEPLOYMENT_TARGET 13.3 CACHE STRING "")

set(vst3sdk_SOURCE_DIR "/Users/preston/Documents/audio_plugin_dev/VST_SDK/vst3sdk")
if(NOT vst3sdk_SOURCE_DIR)
    message(FATAL_ERROR "Path to VST3 SDK is empty!")
endif()

project(Lemon_Gain
    # This is your plug-in version number. Change it here only.
    # Version number symbols usable in C++ can be found in
    # source/version.h and ${PROJECT_BINARY_DIR}/projectversion.h.
    VERSION 1.0.0.0 
    DESCRIPTION "Lemon_Gain VST 3 Plug-in"
)

set(SMTG_VSTGUI_ROOT "${vst3sdk_SOURCE_DIR}")

add_subdirectory(${vst3sdk_SOURCE_DIR} ${PROJECT_BINARY_DIR}/vst3sdk)
smtg_enable_vst3_sdk()

smtg_add_vst3plugin(Lemon_Gain
    source/version.h
    source/lemongaincids.h
    source/lemongainprocessor.h
    source/lemongainprocessor.cpp
    source/lemongaincontroller.h
    source/lemongaincontroller.cpp
    source/lemongainentry.cpp
)

#- VSTGUI Wanted ----
if(SMTG_ADD_VSTGUI)
    target_sources(Lemon_Gain
        PRIVATE
            resource/lemongaineditor.uidesc
    )
    target_link_libraries(Lemon_Gain
        PRIVATE
            vstgui_support
    )
    smtg_target_add_plugin_resources(Lemon_Gain
        RESOURCES
            "resource/lemongaineditor.uidesc"
    )
endif(SMTG_ADD_VSTGUI)
# -------------------

smtg_target_add_plugin_snapshots (Lemon_Gain
    RESOURCES
        resource/D31542476D98515B88EF6647B35E9098_snapshot.png
        resource/D31542476D98515B88EF6647B35E9098_snapshot_2.0x.png
)

target_link_libraries(Lemon_Gain
    PRIVATE
        sdk
)

smtg_target_configure_version_file(Lemon_Gain)

if(SMTG_MAC)
    smtg_target_set_bundle(Lemon_Gain
        BUNDLE_IDENTIFIER studio.lemonlive.lemongain
        COMPANY_NAME "Lemon Live Studios"
    )
    smtg_target_set_debug_executable(Lemon_Gain
        "/Applications/VST3PluginTestHost.app"
        "--pluginfolder;$(BUILT_PRODUCTS_DIR)"
    )
elseif(SMTG_WIN)
    target_sources(Lemon_Gain PRIVATE 
        resource/win32resource.rc
    )
    if(MSVC)
        set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Lemon_Gain)

        smtg_target_set_debug_executable(Lemon_Gain
            "$(ProgramW6432)/Steinberg/VST3PluginTestHost/VST3PluginTestHost.exe"
            "--pluginfolder \"$(OutDir)/\""
        )
    endif()
endif(SMTG_MAC)
