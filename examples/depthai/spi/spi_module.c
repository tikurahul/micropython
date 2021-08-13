#include "spi.h"

// Define Python Module

STATIC MP_DEFINE_CONST_FUN_OBJ_0(init_spi_obj, init_spi);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(deinit_spi_obj, deinit_spi);
STATIC MP_DEFINE_CONST_FUN_OBJ_2(depthai_send_data_spi_obj, depthai_send_data_spi);
STATIC MP_DEFINE_CONST_FUN_OBJ_1(depthai_set_chunk_callback_obj, depthai_set_chunk_callback);
STATIC MP_DEFINE_CONST_FUN_OBJ_1(depthai_pop_messages_obj, depthai_pop_messages);

STATIC const mp_rom_map_elem_t depthai_spi_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_depthai_spi) },
    { MP_ROM_QSTR(MP_QSTR_init_spi), MP_ROM_PTR(&init_spi_obj) },
    { MP_ROM_QSTR(MP_QSTR_deinit_spi), MP_ROM_PTR(&deinit_spi_obj) },
    { MP_ROM_QSTR(MP_QSTR_send_data), MP_ROM_PTR(&depthai_send_data_spi_obj) },
    { MP_ROM_QSTR(MP_QSTR_set_chunk_callback), MP_ROM_PTR(&depthai_set_chunk_callback_obj) },
    { MP_ROM_QSTR(MP_QSTR_pop_messages), MP_ROM_PTR(&depthai_pop_messages_obj) },
};

STATIC MP_DEFINE_CONST_DICT(depthai_spi_module_globals, depthai_spi_module_globals_table);

const mp_obj_module_t depthai_spi_module = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&depthai_spi_module_globals,
};

MP_REGISTER_MODULE(MP_QSTR_depthai_spi, depthai_spi_module, 1);
