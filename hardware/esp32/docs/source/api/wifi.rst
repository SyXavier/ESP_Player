#########
Wi-Fi API
#########

About
-----

The Wi-Fi API provides support for the 802.11b/g/n protocol driver. This API includes:

* Station mode (STA mode or Wi-Fi client mode). ESP32 connects to an access point

* AP mode (aka Soft-AP mode or Access Point mode). Devices connect to the ESP32

* Security modes (WPA, WPA2, WEP, etc.)

* Scanning for access points

Working as AP
*************

In this mode, the ESP32 is configured as an Access Point (AP) and it's capable of receiving incoming connections from other devices (stations) by providing
a Wi-Fi network.

.. figure:: ../_static/wifi_esp32_ap.png
    :align: center
    :width: 520
    :figclass: align-center

This mode can be used for serving a HTTP or HTTPS server inside the ESP32, for example.

Working as STA
**************

The STA mode is used to connect the ESP32 to a Wi-Fi network, provided by an Access Point.

.. figure:: ../_static/wifi_esp32_sta.png
    :align: center
    :width: 520
    :figclass: align-center

If you need to connect your project to the Internet, this is the mode you are looking for.

API Description
---------------

Here is the description about the WiFi API.

WiFiAP
------

The ``WiFiAP`` is used to configure and manage the Wi-Fi as an Access Point. This is where you can find the related functions for the AP.

Basic Usage
***********

To start the Wi-Fi as an Access Point.

.. code-block:: arduino

    WiFi.softAP(ssid, password);

Please see the full WiFiAP example in: `ap example`_.

AP Configuration
----------------

softAP
******

Use the function ``softAP`` to configure the Wi-Fi AP characteristics:

.. code-block:: arduino

    bool softAP(const char* ssid, const char* passphrase = NULL, int channel = 1, int ssid_hidden = 0, int max_connection = 4, bool ftm_responder = false);

Where:

* ``ssid`` sets the Wi-Fi network SSID.
* ``passphrase`` sets the Wi-Fi network password. If the network is open, set as ``NULL``. 
* ``channel`` configures the Wi-Fi channel.
* ``ssid_hidden`` sets the network as hidden.
* ``max_connection`` sets the maximum number of simultaneous connections. The default is 4.
* ``ftm_responder`` sets the Wi-Fi FTM responder feature. **Only for ESP32-S2 and ESP32-C3 SoC!**

Return ``true`` if the configuration was successful.

softAPConfig
************

Function used to configure the IP as static (fixed) as well as the gateway and subnet.

.. code-block:: arduino

    bool softAPConfig(IPAddress local_ip, IPAddress gateway, IPAddress subnet);

Where:

* ``local_ip`` sets the local IP address.
* ``gateway`` sets the gateway IP.
* ``subnet`` sets the subnet mask.

The function will return ``true`` if the configuration is successful.

AP Connection
-------------

softAPdisconnect
****************

Function used to force the AP disconnection.

.. code-block:: arduino

    bool softAPdisconnect(bool wifioff = false);

Where:

* ``wifioff`` sets the Wi-Fi off if ``true``.

The function will return ``true`` if the configuration is successful.


softAPgetStationNum
*******************

This function returns the number of clients connected to the AP.

.. code-block:: arduino

    uint8_t softAPgetStationNum();

softAPIP
********

Function to get the AP IPv4 address.

.. code-block:: arduino

    IPAddress softAPIP();

The function will return the AP IP address in ``IPAddress`` format.

softAPBroadcastIP
*****************

Function to get the AP IPv4 broadcast address.

.. code-block:: arduino

    IPAddress softAPBroadcastIP();

The function will return the AP broadcast address in ``IPAddress`` format.

softAPNetworkID
***************

Get the softAP network ID.

.. code-block:: arduino

    IPAddress softAPNetworkID();

The function will return the AP network address in ``IPAddress`` format.

softAPSubnetCIDR
****************

Get the softAP subnet CIDR.

.. code-block:: arduino

    uint8_t softAPSubnetCIDR();

softAPenableIpV6
****************

Function used to enable the IPv6 support.

.. code-block:: arduino

    bool softAPenableIpV6();

The function will return ``true`` if the configuration is successful.

softAPIPv6
**********

Function to get the IPv6 address.

.. code-block:: arduino

    IPv6Address softAPIPv6();

The function will return the AP IPv6 address in ``IPv6Address`` format.

softAPgetHostname
*****************

Function to get the AP hostname.

.. code-block:: arduino

    const char * softAPgetHostname();

softAPsetHostname
*****************

Function to set the AP hostname.

.. code-block:: arduino

    bool softAPsetHostname(const char * hostname);

Where:

* ``hostname`` sets the device hostname.

The function will return ``true`` if the configuration is successful.


softAPmacAddress
****************

Function to define the AP MAC address.

.. code-block:: arduino

    uint8_t* softAPmacAddress(uint8_t* mac);

Where:

* ``mac`` sets the new MAC address.

Function to get the AP MAC address.

.. code-block:: arduino

    String softAPmacAddress(void);

softAPSSID
**********

Function to get the AP SSID.

.. code-block:: arduino

    String softAPSSID(void) const;

Returns the AP SSID.

WiFiSTA
-------

The ``WiFiSTA`` is used to configure and manage the Wi-Fi as Station. The related functions for the STA are here.

Basic Usage
***********

The following code shows the basic usage of the WifiSTA functionality.

.. code-block:: arduino

    WiFi.begin(ssid, password);

Where the ``ssid`` and ``password`` are from the network you want to connect the ESP32.

To check if the connection is successful, you can use:

.. code-block:: arduino

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

After a successful connection, you can print the IP address given by the network.

.. code-block:: arduino

    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

Please see the full example of the WiFiSTA in: `sta example`_.

STA Configuration
-----------------

begin
*****

- Functions ``begin`` are used to configure and start the Wi-Fi.

.. code-block:: arduino

    wl_status_t begin(const char* ssid, const char *passphrase = NULL, int32_t channel = 0, const uint8_t* bssid = NULL, bool connect = true);

Where:

* ``ssid`` sets the AP SSID.
* ``passphrase`` sets the AP password. Set as ``NULL`` for open networks.
* ``channel`` sets the Wi-Fi channel.
* ``uint8_t* bssid`` sets the AP BSSID.
* ``connect`` sets ``true`` to connect to the configured network automatically.

.. code-block:: arduino

    wl_status_t begin(char* ssid, char *passphrase = NULL, int32_t channel = 0, const uint8_t* bssid = NULL, bool connect = true);

Where:

* ``ssid`` sets the AP SSID.
* ``passphrase`` sets the AP password. Set as ``NULL`` for open networks.
* ``channel`` sets the Wi-Fi channel.
* ``bssid`` sets the AP BSSID.
* ``connect`` sets ``true`` to connect to the configured network automatically.

Function to start the connection after being configured.

.. code-block:: arduino

    wl_status_t begin();

config
******

Function ``config`` is used to configure Wi-Fi. After configuring, you can call function ``begin`` to start the Wi-Fi process.

.. code-block:: arduino

    bool config(IPAddress local_ip, IPAddress gateway, IPAddress subnet, IPAddress dns1 = (uint32_t)0x00000000, IPAddress dns2 = (uint32_t)0x00000000);

Where:

* ``local_ip`` sets the local IP.
* ``gateway`` sets the gateway IP.
* ``subnet`` sets the subnet mask.
* ``dns1`` sets the DNS.
* ``dns2`` sets the DNS alternative option.

The function will return ``true`` if the configuration is successful.

The ``IPAddress`` format is defined by 4 bytes as described here:

.. code-block:: arduino

    IPAddress(uint8_t first_octet, uint8_t second_octet, uint8_t third_octet, uint8_t fourth_octet);

Example:

.. code-block:: arduino

    IPAddress local_ip(192, 168, 10, 20);

See the ``WiFiClientStaticIP.ino`` for more details on how to use this feature.

STA Connection
--------------

reconnect
*********

Function used to reconnect the Wi-Fi connection.

.. code-block:: arduino

    bool reconnect();

disconnect
**********

Function to force disconnection.

.. code-block:: arduino

    bool disconnect(bool wifioff = false, bool eraseap = false);

Where:

* ``wifioff`` use ``true`` to turn the Wi-Fi radio off.
* ``eraseap`` use ``true`` to erase the AP configuration from the NVS memory.

The function will return ``true`` if the configuration is successful.

isConnected
***********

Function used to get the connection state.

.. code-block:: arduino

    bool isConnected();

Return the connection state.

setAutoConnect
**************

Function used to set the automatic connection.

.. code-block:: arduino

    bool setAutoConnect(bool autoConnect);

Where:

* ``bool autoConnect`` is set to ``true`` to enable this option.

getAutoConnect
**************

Function used to get the automatic connection setting value.

.. code-block:: arduino

    bool getAutoConnect();

The function will return ``true`` if the setting is enabled.

setAutoReconnect
****************

Function used to set the automatic reconnection if the connection is lost.

.. code-block:: arduino

    bool setAutoReconnect(bool autoReconnect);

Where:

* ``autoConnect`` is set to ``true`` to enable this option.

getAutoReconnect
****************

Function used to get the automatic reconnection if the connection is lost.
.. code-block:: arduino

    bool getAutoReconnect();

    The function will return ``true`` if this setting is enabled.

WiFiMulti
---------

The ``WiFiMulti`` allows you to add more than one option for the AP connection while running as a station.

To add the AP, use the following function. You can add multiple AP's and this library will handle the connection.

.. code-block:: arduino

    bool addAP(const char* ssid, const char *passphrase = NULL);

After adding the AP's, run by the following function.

.. code-block:: arduino

    uint8_t run(uint32_t connectTimeout=5000);

To see how to use the ``WiFiMulti``, take a look at the ``WiFiMulti.ino`` example available.

WiFiScan
--------

To perform the Wi-Fi scan for networks, you can use the following functions:

Start scan WiFi networks available.

.. code-block:: arduino

    int16_t scanNetworks(bool async = false, bool show_hidden = false, bool passive = false, uint32_t max_ms_per_chan = 300, uint8_t channel = 0);

Called to get the scan state in Async mode.

.. code-block:: arduino

    int16_t scanComplete();

Delete last scan result from RAM.

.. code-block:: arduino

    void scanDelete();

Loads all infos from a scanned wifi in to the ptr parameters.

.. code-block:: arduino

    bool getNetworkInfo(uint8_t networkItem, String &ssid, uint8_t &encryptionType, int32_t &RSSI, uint8_t* &BSSID, int32_t &channel);

To see how to use the ``WiFiScan``, take a look at the ``WiFiScan.ino`` example available.

Examples
--------

.. _ap example:

Wi-Fi AP Example
****************

.. literalinclude:: ../../../libraries/WiFi/examples/WiFiAccessPoint/WiFiAccessPoint.ino
    :language: arduino

.. _sta example:

Wi-Fi STA Example
*****************

.. literalinclude:: ../../../libraries/WiFi/examples/WiFiClient/WiFiClient.ino
    :language: arduino

References
----------
