#ifndef __PARAM_RW_H
#define __PARAM_RW_H

#define PARAM_SID_LENGTH 1024
#define DEFAULT_PARAM_DUMP_SIZE 64

typedef unsigned int       uint32;

typedef enum {
	PARAM_SID_PRODUCT = 0,
	PARAM_SID_CONFIG,
	PARAM_SID_LCD,
	PARAM_SID_TP,
	PARAM_SID_TP_KPD,
	PARAM_SID_CAMERA,
	PARAM_SID_SENSORS,
	PARAM_SID_BATTERY,
	PARAM_SID_RTC,
	PARAM_SID_CRASH_RECORD,
	PARAM_SID_SALEINFO,
	PARAM_SID_MISC,
	PARAM_SID_DOWNLOAD,
	PARAM_SID_PHONE_HISTORY,
	NUM_PARAM_PLAINTEXT_SEGMENT,

	PARAM_SID_INVALID = -1
} param_sid_index_t;

#ifdef CONFIG_PARAM_READ_WRITE
void init_param_mem_base_size(phys_addr_t base, unsigned long size);

int get_param_by_index_and_offset(uint32 sid_index, uint32 offset, void * buf, int length);
int set_param_by_index_and_offset(uint32 sid_index, uint32 offset, void * buf, int length);

int add_restart_08_count(void);
int add_restart_other_count(void);
#else
static inline void init_param_mem_base_size(phys_addr_t base, unsigned long size)
{
}

static inline int get_param_by_index_and_offset(uint32 sid_index, uint32 offset, void * buf, int length)
{
	return length;
}
static inline int set_param_by_index_and_offset(uint32 sid_index, uint32 offset, void * buf, int length)
{
	return 0;
}

static inline int add_restart_08_count(void)
{
	return 0;
}
static inline int add_restart_other_count(void)
{
	return 0;
}
#endif

//end
#endif

