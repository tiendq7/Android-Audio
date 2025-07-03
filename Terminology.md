# 📚 Thuật ngữ trong hệ thống audio Android

Đây là danh sách các thuật ngữ liên quan đến hệ thống âm thanh (audio) trong Android, bao gồm cả các thuật ngữ tổng quát (generic) và các thuật ngữ đặc trưng trong Android (Android-specific).

## 🎧 Generic Terms (Thuật ngữ tổng quát)

- `Digital audio`: Âm thanh được mã hóa dưới dạng tín hiệu số.
- `AC-3`: Một định dạng mã hóa âm thanh của Dolby (Dolby Digital).
- `Acoustics`: Nghiên cứu về đặc tính cơ học của âm thanh (vị trí đặt loa, micro ảnh hưởng đến chất lượng).
- `Attenuation`: Giảm cường độ tín hiệu âm thanh bằng một hệ số nhỏ hơn hoặc bằng 1.0. (So sánh: gain)
- `Audiophile`: Người đam mê chất lượng âm thanh cao cấp.
- `AVB (Audio Video Bridging)`: Chuẩn truyền tín hiệu âm thanh số thời gian thực qua Ethernet.
- `Bits per sample / Bit depth`: Số bit thông tin trên mỗi mẫu âm thanh.
- `Channel`: Luồng âm thanh tương ứng với một vị trí phát hoặc thu.
- `Downmixing`: Giảm số kênh âm thanh (ví dụ từ stereo về mono).
- `DSD (Direct Stream Digital)`: Phương pháp mã hóa âm thanh sử dụng mật độ xung (pulse-density modulation).
- `Duck`: Tạm thời giảm âm lượng của luồng âm thanh đang phát khi có luồng khác phát chen vào.
-`FIFO (First In First Out)`: Cơ chế lưu trữ dữ liệu dạng hàng đợi, thường dùng cho frame audio.
- `Frame`: Một tập hợp các sample tại một thời điểm.
- `Frames per buffer`: Số frame truyền giữa các module trong một lần.
- `Gain`: Tăng cường độ tín hiệu âm thanh bằng hệ số >= 1.0. (So sánh: attenuation)
- `HD audio / High-resolution audio`: Âm thanh có độ phân giải cao hơn CD, không nén mất dữ liệu.
- `Headphones`: Tai nghe không micro.
- `Headset`: Tai nghe có micro.
- `Hz`: Đơn vị của sample rate.
- `Interleaved`: Cách lưu trữ xen kẽ dữ liệu giữa các channel.
- `Latency`: Độ trễ khi tín hiệu âm thanh truyền qua hệ thống.
- `Lossless / Lossy`: Phân biệt giữa nén không mất dữ liệu và nén có mất dữ liệu (ví dụ: FLAC vs MP3).
- `Mono / Stereo / Multichannel`: Số lượng kênh âm thanh.
- `Mute`: Ép âm lượng về 0 trong thời gian ngắn.
- `Overrun / Underrun`: Lỗi do truyền dữ liệu không kịp gây ra giật âm thanh.
- `Panning`: Điều chỉnh vị trí âm thanh trong không gian kênh.
- `PCM (Pulse-code modulation)`: Dạng mã hóa âm thanh số phổ biến.
- `Ramp`: Tăng/giảm âm lượng dần dần.
- `Sample / Sample Rate`: Giá trị âm thanh tại một thời điểm và số mẫu trên giây.
- `Sonification`: Dùng âm thanh để thể hiện thông tin, ví dụ như âm bàn phím.
- `SPL (Sound Pressure Level)`: Mức áp suất âm thanh.
- `Stereo widening / Surround sound / Upmixing`: Các kỹ thuật xử lý làm âm thanh nghe rộng và đa chiều hơn.
- `Transparency`: Tín hiệu nén lossy nhưng không thể phân biệt bằng tai người so với tín hiệu gốc.

---

## 🔹 Interconnect (Kết nối giữa thiết bị)

- `Bluetooth`: Công nghệ không dây tầm ngắn truyền âm thanh (A2DP, SCO, AVRCP).
- `HDMI / DisplayPort / MHL / SlimPort`: Chuẩn truyền âm thanh và hình ảnh qua dây cáp.
- `USB`: Kết nối thông dụng cho audio interface, DAC rời.
- `S/PDIF / TOSLINK`: Chuẩn truyền âm thanh số qua cáp đồng trục hoặc cáp quang.
- `Dongle`: Thiết bị chuyển đổi nhỏ kết nối với các cổng âm thanh.
- `Phone connector`: Jack 3.5mm (TRS/TRRS) kết nối tai nghe hoặc microphone.

---

## 🔌 Intradevice Interconnect (Kết nối nội bộ thiết bị)

- `I2S / TDM / SLIMbus / SoundWire`: Chuẩn kết nối dữ liệu âm thanh số giữa các IC.
- `I2C / SPI / GPIO`: Bus điều khiển cho thiết bị audio nội bộ.
- `McASP / AC'97 / Intel HDA`: Giao diện âm thanh nội bộ phổ biến trên SoC hoặc PC.

---

## ⏳ Sample Rate Conversion (Chuyển đổi tốc độ mẫu)

- `AEC (Acoustic Echo Cancellation)`: Triệt tiêu tiếng vọng.
- `ANC (Active Noise Control)`: Triệt tiêu tiếng ồn chủ động.
- `Sidetone`: Nghe lại giọng nói của mình khi gọi.
- `TTY / HCO / VCO / TDD`: Các chế độ hỗ trợ người khiếm thính.

---

## 🪄 Android-specific Terms (Thuật ngữ riêng của Android)

- `ALSA / TinyALSA`: Kiến trúc driver âm thanh trong Linux/Android.

- `AudioFlinger`: Audio server trong Android, xử lý phát và thu âm thanh.

- `AudioMixer / AudioResampler`: Module trong AudioFlinger để mix và resample.

- `AudioTrack / AudioRecord`: Lớp ứng dụng để ghi âm và phát âm thanh PCM.
- `AudioPolicyService`: Dịch vụ quyết định route, stream, volume.
- `FastMixer / FastCapture`: Cơ chế ưu tiên độ trễ thấp của AudioFlinger.
- `AudioEffect`: API xử lý hiệu ứng âm thanh (Echo, Bass Boost, ...).
- `MediaPlayer / SoundPool / ToneGenerator`: Các lớp cao cấp để phát âm thanh.
- `mediaserver`: Tiến trình hệ thống chứa AudioFlinger và media services.
- `HAL (Audio HAL)`: Lớp trừu tượng phần cứng giữa AudioFlinger và driver.
- `NBAIO / StateQueue / Strategy / Stream Type`: Thành phần nội bộ dùng để routing, đồng bộ, logic.
- `Pro Audio`: Cờ tính năng hệ thống hỗ trợ độ trễ thấp cho ứng dụng chuyên nghiệp.
