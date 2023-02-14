SRC_CC := vfs.cc

DDE_LINUX_DIR := $(subst /src/include/lx_kit,,$(call select_from_repositories,src/include/lx_kit))

INC_DIR += $(DDE_LINUX_DIR)/src/include

LIBS := a64_wifi

PC_REPO_DIR := $(call select_from_repositories,src/lib/pc)

vpath %.cc $(PC_REPO_DIR)/../vfs/wifi

SHARED_LIB := yes
