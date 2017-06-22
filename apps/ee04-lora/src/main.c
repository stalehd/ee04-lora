/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include <assert.h>
#include <string.h>

#include "sysinit/sysinit.h"
#include "os/os.h"
#include "bsp/bsp.h"
#include "hal/hal_gpio.h"
#include "hal/hal_spi.h"
#include "mcu/nrf52_hal.h"
#include "console/console.h"
#ifdef ARCH_sim
#include "mcu/mcu_sim.h"
#endif

#include "lora.h"

/**
 * main
 *
 * The main task for the project. This function initializes packages,
 * and then blinks the BSP LED in a loop.
 *
 * @return int NOTE: this function should never return!
 */
int
main(int argc, char **argv)
{
    int rc;

#ifdef ARCH_sim
    mcu_sim_parse_args(argc, argv);
#endif

    sysinit();
    console_printf("********** Booty time!\n");
    int error;

#if 0
    struct nrf52_hal_spi_cfg spi_cfg = {
        .sck_pin      = 25,
        .mosi_pin     = 23,
        .miso_pin     = 24,
    };

    console_printf("Enable HAL SPI: Start\n");
    error = hal_spi_init(0, &spi_cfg, HAL_SPI_TYPE_MASTER);
    assert(error == 0);
    error = hal_spi_enable(0);
    assert(error == 0);
    console_printf("Enable HAL SPI: Success\n");
#endif
    console_printf("Enable antenna switch GPIO\n");
    error = hal_gpio_init_out(27, 1);
    assert(error == 0);
    hal_gpio_write(27, 1);
    console_printf("GPIO ok\n");

    lora_event_loop();

    console_printf("I assumed I wouldn't exit here\n");
    assert(0);

    return rc;
}

