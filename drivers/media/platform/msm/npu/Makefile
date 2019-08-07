obj-$(CONFIG_MSM_NPU)      := msm_npu.o
msm_npu-objs := npu_dev.o \
                npu_debugfs.o \
                npu_host_ipc.o \
                npu_hw_access.o \
                npu_mgr.o

ifdef CONFIG_DEBUG_KERNEL
msm_npu-objs += npu_dbg.o
endif
