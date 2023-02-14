TARGET  := a64_wifi_drv
SRC_CC  := main.cc wpa.cc
LIBS    := base a64_wifi
$(info a64_wifi_firmware not yet available)
LIBS    += libc
LIBS    += wpa_supplicant
LIBS    += libcrypto libssl wpa_driver_nl80211

PC_REPO_DIR := $(call select_from_repositories,src/lib/pc)
PC_SRC_DIR  := $(PC_REPO_DIR)/../../drivers/wifi/pc

INC_DIR += $(PC_SRC_DIR)

CC_CXX_WARN_STRICT :=

vpath %.cc $(PC_SRC_DIR)
