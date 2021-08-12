#include "py/runtime.h"

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "depthai-spi-api/common/esp32_spi_impl.h"
#include "depthai-spi-api/spi_api.hpp"

mp_obj_t init_spi() {
    init_esp32_spi();
    return mp_obj_new_bool(1);
}
