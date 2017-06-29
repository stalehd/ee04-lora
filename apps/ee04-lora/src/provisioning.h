/*
**   Copyright 2017 Telenor Digital AS
**
**  Licensed under the Apache License, Version 2.0 (the "License");
**  you may not use this file except in compliance with the License.
**  You may obtain a copy of the License at
**
**      http://www.apache.org/licenses/LICENSE-2.0
**
**  Unless required by applicable law or agreed to in writing, software
**  distributed under the License is distributed on an "AS IS" BASIS,
**  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
**  See the License for the specific language governing permissions and
**  limitations under the License.
*/
#ifndef LORA_CONFIG_H
#define LORA_CONFIG_H


#if 0
#define LORAWAN_OTAA 0

/* ==========================================================================
 * OTAA provisioning. This includes the device EUI, application EUI and
 * application key. The application and network session keys will be
 * negotiated when the device joins the network.
 * ========================================================================== */
#define LORAWAN_DEVICE_EUI { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }
#define LORAWAN_APP_KEY { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }
#define LORAWAN_APP_EUI { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }

/* ==========================================================================
 * ABP (activation by personalisation) parameters. Rather than negotiating
 * the application and network session keys these are set directly. This
 * eliminates the need for a join request and the device can transmit data
 * directly. The downside is that the device should keep track of the frame
 * counters when it is powered down but you won't share the application key.
 * ========================================================================== */
#define LORAWAN_DEVICE_ADDRESS (uint32_t) 0x0eefbabe
#define LORAWAN_NWKSKEY { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08 }
#define LORAWAN_APPSKEY { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08 }
#endif
	
	
#if 1

#define LORAWAN_OTAA 1

/* ==========================================================================
 * OTAA provisioning. This includes the device EUI, application EUI and
 * application key. The application and network session keys will be
 * negotiated when the device joins the network.
 * ========================================================================== */
#define LORAWAN_DEVICE_EUI { 0x00, 0x09, 0x09, 0x00, 0x00, 0x01, 0x39, 0xad }
#define LORAWAN_APPLICATION_KEY { 0x09, 0x16, 0x32, 0x84, 0x80, 0x52, 0x38, 0x80, 0x07, 0x52, 0x11, 0x43, 0x62, 0x49, 0x40, 0x53 }
#define LORAWAN_APPLICATION_EUI { 0x92, 0x70, 0x45, 0x01, 0x74, 0x47, 0x64, 0x52 }

/* ==========================================================================
 * ABP (activation by personalisation) parameters. Rather than negotiating
 * the application and network session keys these are set directly. This
 * eliminates the need for a join request and the device can transmit data
 * directly. The downside is that the device should keep track of the frame
 * counters when it is powered down but you won't share the application key.
 * ========================================================================== */
#define LORAWAN_DEVICE_ADDRESS (uint32_t) 0x0
#define LORAWAN_NWKSKEY { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }
#define LORAWAN_APPSKEY { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }

	
#endif
	
#endif

