#include "py/runtime.h"
#include "py/obj.h"

extern mp_obj_t init_spi();
extern mp_obj_t deinit_spi();
extern mp_obj_t depthai_send_data_spi(mp_obj_t stream_name, mp_obj_t data);
