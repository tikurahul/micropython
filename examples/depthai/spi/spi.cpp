#include "py/runtime.h"
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

mp_obj_t init_spi() {
    init_esp32_spi();
    spiApi.set_send_spi_impl(&esp32_send_spi);
    spiApi.set_recv_spi_impl(&esp32_recv_spi);
    return mp_obj_new_bool(1);
}

}
