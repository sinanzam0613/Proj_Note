LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := cri_ware_cocos2dx
LOCAL_SRC_FILES := ../../adx2/libs/android/armeabi-v7a/libcri_ware_android_LE.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

FILE_LIST := $(wildcard $(LOCAL_PATH)/../../Classes/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Object/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Object/Character/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Object/Manager/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Object/StageObject/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Object/Test/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Object/UIObject/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Object/Character/Enemy/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Object/Character/Player/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Object/StageObject/Bar/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Object/StageObject/Block/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Object/StageObject/Goal/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Object/StageObject/Note/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Object/StageObject/Rest/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Object/StageObject/StartStand/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Scene/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Scene/Credit/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Scene/GameEnd/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Scene/GameMain/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Scene/StageSelect/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Scene/Test/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Scene/Title/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/Action/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/Action/Follow/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/Animation/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/Audio/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/Audio/Define/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/Camera/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/CocosAssistant/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/Collision/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/Delegate/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/FileIO/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/Release/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/SceneSupport/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/Template/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/Timer/*.cpp)


LOCAL_SRC_FILES := hellocpp/main.cpp
LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../adx2/include/android
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Object
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Object/Character
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Object/Manager
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Object/StageObject
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Object/Test
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Object/UIObject
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Object/Character/Enemy
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Object/Character/Player
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Object/StageObject/Bar
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Object/StageObject/Block
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Object/StageObject/Goal
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Object/StageObject/Note
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Object/StageObject/Rest
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Scene
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Scene/GameEnd
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Scene/GameMain
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Scene/StageSelect
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Scene/Test
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Scene/Title
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/Action
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/Action/Follow
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/Animation
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/Audio
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/Audio/Define
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/Camera
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/CocosAssistant
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/Collision
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/Delegate
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/FileIO
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/Release
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/SceneSupport
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/Template
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/Timer

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static

# LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
# LOCAL_WHOLE_STATIC_LIBRARIES += cocosbuilder_static
# LOCAL_WHOLE_STATIC_LIBRARIES += spine_static
# LOCAL_WHOLE_STATIC_LIBRARIES += cocostudio_static
# LOCAL_WHOLE_STATIC_LIBRARIES += cocos_network_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static

LOCAL_SHARED_LIBRARIES := libcri_ware_cocos2dx

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)
$(call import-module,audio/android)

# $(call import-module,Box2D)
# $(call import-module,editor-support/cocosbuilder)
# $(call import-module,editor-support/spine)
# $(call import-module,editor-support/cocostudio)
# $(call import-module,network)
$(call import-module,extensions)
