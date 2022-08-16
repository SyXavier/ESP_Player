# ESP_Player

* ### 硬件

  * 主控（ESP32-WROVER-IE）

  * 音频解码器（PCM5102A、MAX98357A需要使用2个组成双声道）

    | 模块引脚 | 主控引脚 |
    | :------: | :------: |
    | I2S_DOUT |    25    |
    | I2S_BCLK |    27    |
    | I2S_LRC  |    26    |

  * 屏幕（ST7789 240*240分辨率）

    | 模块引脚 | 主控引脚 |
    | :------: | :------: |
    | TFT_MOSI |    13    |
    | TFT_SCLK |    14    |
    |  TFT_DC  |    2     |
    | TFT_RST  |    4     |
    | TFT_BLK  |    32    |

  * 编码器（EC11）

    | 模块引脚 | 主控引脚 |
    | :------: | :------: |
    |   CLK    |    39    |
    |    DT    |    34    |
    |    SW    |    35    |

  * TFT读卡器

    | 模块引脚 | 主控引脚 |
    | :------: | :------: |
    |  SD_CS   |    5     |
    | SD_MOSI  |    23    |
    | SD_MISO  |    19    |
    | SD_SCLK  |    18    |
    | SD_DECT  |    36    |

  * 熄屏

    | 模块引脚 | 主控引脚 |
    | :------: | :------: |
    |  BL_SW   |    33    |

  * 注意事项：

    * 屏幕我选用中景园的1.3inch 240*240 IPS ST7789V2，尺寸可以选择1.5inch的
    * 音频解码器PCM5102A尽量选择好一点的模块，几块钱的模块踩过坑（都是噪音，根本没法听）

* ### 软件

  * 支持格式：MP3、M4A、AAC、WAV、FLAC

  * 使用Arduino配合ESP-IDF开发

  * 图形框架使用LVGL 8.0版本

  * arduino-esp32/esp32 复制到Arduino安装路径中的hardware下

  * libraries中的驱动复制到Arduino安装路径中的Arduino/libraries

  * Arduino设置如下

    |       选项       |      参数值       |
    | :--------------: | :---------------: |
    |      开发板      | ESP32 Dev Module  |
    |   Upload Speed   |      256000       |
    |  CPU Frequency   |  240MHz(WiFi/BT)  |
    | Flash Frequency  |       80MHz       |
    |    Flash Mode    |        QIO        |
    |    Flash Size    |     8MB(64Mb)     |
    | Partition Scheme | 8M Flash(7MB APP) |
    | Core Debug Level |        无         |
    |      PSRAM       |      Enable       |

    * 注意事项：
      * 主控可以选择ESP32其他型号，但是核心必须是ESP32-D0WD-V3（其他核心没有测试）
      * 主控必须带有PSRAM，否则无法正常工作（FLAC格式解码需要大量内存）
      * Arduino APP分区必须给的很大，这里Flash我分了7MB（中文字库很吃存储空间）
      * LVGL版本为8.0，每个版本之间会有很多改动，最好使用对应版本

* ### 常见问题

  * 某些FLAC格式可能无法解析，FLAC有很多头格式，只是适配了常用的头格式
  * 插入TF卡后无法获取歌曲，请把歌曲放在根目录下；若依旧无法获取，可能是TF卡的格式不对（之前用Windows自带的格式化工具出过问题），使用SD Card Formatter工具进行格式化（只支持FAT32格式）
  * 插入TF卡后，播放某些歌曲正常，播放另外一些会出现界面卡死、重启问题，是TF卡拷贝歌曲的时候由于TF读卡器不稳定造成的卡内数据错乱导致的，重新格式化TF卡后拷贝歌曲
  * 给主控供电需要一个稳定的适配器（可能会导致播放器工作不稳定、音质差、有噪音等等）



#### 目前我测试就发现了以上问题，如果有其他问题，可以在B站或者QQ群里反馈给我，群号：575212603。在此也欢迎大家一起修改源代码。

