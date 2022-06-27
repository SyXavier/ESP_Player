#!/bin/bash

set -e

if [ ! -z "$TRAVIS_TAG" ]; then
	echo "Skipping Test: Tagged build"
	exit 0
fi

if [ ! -z "$GITHUB_WORKSPACE" ]; then
	export TRAVIS_BUILD_DIR="$GITHUB_WORKSPACE"
	export TRAVIS_REPO_SLUG="$GITHUB_REPOSITORY"
elif [ ! -z "$TRAVIS_BUILD_DIR" ]; then
	export GITHUB_WORKSPACE="$TRAVIS_BUILD_DIR"
	export GITHUB_REPOSITORY="$TRAVIS_REPO_SLUG"
else
	export GITHUB_WORKSPACE="$PWD"
	export GITHUB_REPOSITORY="espressif/arduino-esp32"
fi

CHUNK_INDEX=$1
CHUNKS_CNT=$2
BUILD_PIO=0
if [ "$#" -lt 2 ] || [ "$CHUNKS_CNT" -le 0 ]; then
	CHUNK_INDEX=0
	CHUNKS_CNT=1
elif [ "$CHUNK_INDEX" -gt "$CHUNKS_CNT" ]; then
	CHUNK_INDEX=$CHUNKS_CNT
elif [ "$CHUNK_INDEX" -eq "$CHUNKS_CNT" ]; then
	BUILD_PIO=1
fi

echo "Updating submodules ..."
git -C "$GITHUB_WORKSPACE" submodule update --init --recursive > /dev/null 2>&1

if [ "$BUILD_PIO" -eq 0 ]; then
	# ArduinoIDE Test
	FQBN="espressif:esp32:esp32:PSRAM=enabled,PartitionScheme=huge_app"
	source ./.github/scripts/install-arduino-ide.sh
	source ./.github/scripts/install-arduino-core-esp32.sh
	if [ "$OS_IS_WINDOWS" == "1" ]; then
		build_sketch "$FQBN" "$ARDUINO_ESP32_PATH/libraries/WiFiClientSecure/examples/WiFiClientSecure/WiFiClientSecure.ino" && \
		build_sketch "$FQBN" "$ARDUINO_ESP32_PATH/libraries/BLE/examples/BLE_server/BLE_server.ino" && \
		build_sketch "$FQBN" "$ARDUINO_ESP32_PATH/libraries/AzureIoT/examples/GetStarted/GetStarted.ino" && \
		build_sketch "$FQBN" "$ARDUINO_ESP32_PATH/libraries/ESP32/examples/Camera/CameraWebServer/CameraWebServer.ino"
	elif [ "$OS_IS_MACOS" == "1" ]; then
		build_sketch "$FQBN" "$ARDUINO_ESP32_PATH/libraries/WiFi/examples/WiFiClient/WiFiClient.ino" && \
		build_sketch "$FQBN" "$ARDUINO_ESP32_PATH/libraries/WiFiClientSecure/examples/WiFiClientSecure/WiFiClientSecure.ino" && \
		build_sketch "$FQBN" "$ARDUINO_ESP32_PATH/libraries/BluetoothSerial/examples/SerialToSerialBT/SerialToSerialBT.ino" && \
		build_sketch "$FQBN" "$ARDUINO_ESP32_PATH/libraries/BLE/examples/BLE_server/BLE_server.ino" && \
		build_sketch "$FQBN" "$ARDUINO_ESP32_PATH/libraries/AzureIoT/examples/GetStarted/GetStarted.ino" && \
		build_sketch "$FQBN" "$ARDUINO_ESP32_PATH/libraries/ESP32/examples/Camera/CameraWebServer/CameraWebServer.ino"
	else
		# CMake Test
		if [ "$CHUNK_INDEX" -eq 0 ]; then
			bash "$ARDUINO_ESP32_PATH/.github/scripts/check-cmakelists.sh"
		fi
		build_sketches "$FQBN" "$ARDUINO_ESP32_PATH/libraries" "$CHUNK_INDEX" "$CHUNKS_CNT"
	fi
else
	# PlatformIO Test
	source ./.github/scripts/install-platformio-esp32.sh
	BOARD="esp32dev"
	build_pio_sketch "$BOARD" "$PLATFORMIO_ESP32_PATH/libraries/WiFi/examples/WiFiClient/WiFiClient.ino" && \
	build_pio_sketch "$BOARD" "$PLATFORMIO_ESP32_PATH/libraries/WiFiClientSecure/examples/WiFiClientSecure/WiFiClientSecure.ino" && \
	build_pio_sketch "$BOARD" "$PLATFORMIO_ESP32_PATH/libraries/BluetoothSerial/examples/SerialToSerialBT/SerialToSerialBT.ino" && \
	build_pio_sketch "$BOARD" "$PLATFORMIO_ESP32_PATH/libraries/BLE/examples/BLE_server/BLE_server.ino" && \
	build_pio_sketch "$BOARD" "$PLATFORMIO_ESP32_PATH/libraries/AzureIoT/examples/GetStarted/GetStarted.ino" && \
	build_pio_sketch "$BOARD" "$PLATFORMIO_ESP32_PATH/libraries/ESP32/examples/Camera/CameraWebServer/CameraWebServer.ino"
	#build_pio_sketches esp32dev "$PLATFORMIO_ESP32_PATH/libraries"
fi
