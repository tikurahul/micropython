// Include MicroPython API.
#include "py/runtime.h"

// This is the function which will be called from Python as cexample.add_ints(a, b).
STATIC mp_obj_t example_add_ints(mp_obj_t a_obj, mp_obj_t b_obj) {
    // Extract the ints from the micropython input objects.
    int a = mp_obj_get_int(a_obj);
    int b = mp_obj_get_int(b_obj);

    // Calculate the addition and convert to MicroPython object.
    return mp_obj_new_int(a + b);
}

// This is the function which will be called from Python as cexample.add_array([...]).
STATIC mp_obj_t example_add_array(mp_obj_t a_obj) {
    // Extract the ints from the micropython input objects.
    size_t nitems;
    const mp_obj_t *items;
    mp_obj_get_array(a_obj, &nitems, (mp_obj_t **)&items);
    int result = 0;
    for(size_t i = 0; i < nitems; i++) {
        mp_obj_t item = items[i];
        int value = mp_obj_get_int(item);
        result += value;
    }
    // Calculate the addition and convert to MicroPython object.
    return mp_obj_new_int(result);
}

// Define a Python reference to the function above.
STATIC MP_DEFINE_CONST_FUN_OBJ_1(example_add_array_obj, example_add_array);
STATIC MP_DEFINE_CONST_FUN_OBJ_2(example_add_ints_obj, example_add_ints);

// Define all properties of the module.
// Table entries are key/value pairs of the attribute name (a string)
// and the MicroPython object reference.
// All identifiers and strings are written as MP_QSTR_xxx and will be
// optimized to word-sized integers by the build system (interned strings).
STATIC const mp_rom_map_elem_t depthai_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_depthai) },
    { MP_ROM_QSTR(MP_QSTR_add_ints), MP_ROM_PTR(&example_add_ints_obj) },
    { MP_ROM_QSTR(MP_QSTR_add_array), MP_ROM_PTR(&example_add_array_obj) },
};
STATIC MP_DEFINE_CONST_DICT(depthai_module_globals, depthai_module_globals_table);

// Define module object.
const mp_obj_module_t depthai_user_cmodule = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&depthai_module_globals,
};

// Register the module to make it available in Python.
// Note: the "1" in the third argument means this module is always enabled.
// This "1" can be optionally replaced with a macro like MODULE_CEXAMPLE_ENABLED
// which can then be used to conditionally enable this module.
MP_REGISTER_MODULE(MP_QSTR_depthai, depthai_user_cmodule, 1);
