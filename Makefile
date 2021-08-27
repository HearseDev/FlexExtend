#THEOS_DEVICE_IP = 10.0.0.130
#THEOS_DEVICE_PORT = 2222
export ARCHS = arm64 arm64e
export TARGET := iphone:clang:latest:9.0


include $(THEOS)/makefiles/common.mk

TWEAK_NAME = flexextend
flexextend_FILES = Tweak.xm
flexextend_LIBRARIES = FLEX

flexextend_CFLAGS += -fobjc-arc -w

include $(THEOS_MAKE_PATH)/tweak.mk

