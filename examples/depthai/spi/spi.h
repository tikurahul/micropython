#include "py/runtime.h"
#include "py/obj.h"

extern mp_obj_t init_spi();
extern mp_obj_t deinit_spi();
extern mp_obj_t depthai_send_data_spi(mp_obj_t stream_name, mp_obj_t data);
extern mp_obj_t depthai_set_chunk_callback(mp_obj_t stream_name, mp_obj_t func);
extern mp_obj_t depthai_pop_messages(mp_obj_t stream_name);
extern mp_obj_t depthapi_request_data(mp_obj_t stream_name);
