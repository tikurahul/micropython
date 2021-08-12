#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "depthai-spi-api/common/esp32_spi_impl.h"
#include "depthai-spi-api/spi_api.hpp"

// The SPI API handle.
// There is probably a better way to do this.
static dai::SpiApi spiApi;

extern "C" {
#include "spi.h"
mp_obj_t depthai_send_data_spi(mp_obj_t stream_name, mp_obj_t data) {
    if (!mp_obj_is_str(stream_name)) {
        mp_raise_TypeError(NULL);
    }
    const char* name = mp_obj_str_get_str(stream_name);
    mp_buffer_info_t bufinfo;
    mp_get_buffer_raise(data, &bufinfo, MP_BUFFER_READ);
    dai::Data spi_data = {
        .size = bufinfo.len,
        .data = (uint8_t *) bufinfo.buf
    };
    uint8_t result = spiApi.send_data(&spi_data, name);
    return mp_obj_new_int(result);
}

mp_obj_t init_spi() {
    init_esp32_spi();
    spiApi.set_send_spi_impl(&esp32_send_spi);
    spiApi.set_recv_spi_impl(&esp32_recv_spi);
    return mp_obj_new_bool(1);
}

mp_obj_t deinit_spi() {
    deinit_esp32_spi();
    return mp_obj_new_bool(1);
}
}
