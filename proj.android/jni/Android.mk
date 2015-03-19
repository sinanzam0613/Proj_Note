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
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/GameTitle/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/SceneSupport/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/Audio/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/Audio/Define/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/Collision/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/Delegate/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/FileIO/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/Release/*.cpp)

LOCAL_SRC_FILES := hellocpp/main.cpp
LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../adx2/include/android
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/GameTitle
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/SceneSupport
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/Audio
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/Audio/Define
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/Collision
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/Delegate
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/FileIO
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/Release

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static

# LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
# LOCAL_WHOLE_STATIC_LIBRARIES += cocosbuilder_static
# LOCAL_WHOLE_STATIC_LIBRARIES += spine_static
# LOCAL_WHOLE_STATIC_LIBRARIES += cocostudio_static
# LOCAL_WHOLE_STATIC_LIBRARIES += cocos_network_static
# LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static

LOCAL_SHARED_LIBRARIES := libcri_ware_cocos2dx

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)
$(call import-module,audio/android)

# $(call import-module,Box2D)
# $(call import-module,editor-support/cocosbuilder)
# $(call import-module,editor-support/spine)
# $(call import-module,editor-support/cocostudio)
# $(call import-module,network)
# $(call import-module,extensions)
