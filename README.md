# 🚦 Arduino Akıllı Kavşak Simülasyonu (4 Yol)

Bu proje, Arduino Uno kullanılarak 3 ana yol ve 1 tali yoldan oluşan akıllı bir trafik ışığı sistemini simüle eder. Sistem, gündüz ve gece modlarında farklı senaryolara göre çalışarak trafik akışını optimize etmeyi hedefler.

## 🌟 Proje Özellikleri

Sistemde iki temel çalışma modu bulunur ve modlar arası geçiş **buton** aracılığıyla yapılır:

### ☀️ 1. Gündüz Modu (Normal Akış)
* **Ana Yollar:** Trafik akışı normal döngüde 3 ana yol arasında sırasıyla devam eder.
* **Tali Yol (Sensörlü):** Tali yol normal döngüye dahil edilmez ve sürekli **KIRMIZI** yanar.
* **Algılama:** Tali yolda bulunan ultrasonik sensör araç algıladığında (tetiklendiğinde), sistem ana yolları durdurur ve tali yola geçiş hakkı verir. Araç geçtikten sonra döngü tekrar ana yollara döner.
* **Yaya Işıkları:** Araç ışıklarıyla senkronize olarak çalışır.

### 🌙 2. Gece Modu (İkaz Modu)
* Trafik yoğunluğunun azaldığı saatler için tasarlanmıştır.
* **Yaya Işıkları:** Tamamen devre dışıdır (yanmaz).
* **Ana Yollar:** Kırmızı flaşör (yanıp sönen) modundadır.
* **Tali Yol:** Sarı flaşör (yanıp sönen) modundadır.

## 🛠 Donanım ve Malzemeler
* **Mikrodenetleyici:** Arduino Uno
* **Sensör:** HC-SR04 Ultrasonik Mesafe Sensörü (Tali yol kontrolü için)
* **Kontrol:** 1 x Push Buton (Modlar arası geçiş için)
* **Işıklandırma:**
  * Trafik Işıkları için LED'ler (Kırmızı, Sarı, Yeşil)
  * Yaya Işıkları için LED'ler (Kırmızı, Yeşil)
* **Diğer:** Jumper kablolar, dirençler (220Ω/330Ω ve 10kΩ), Breadboard

## 🚀 Kurulum ve Kullanım
1. Devreyi şemada belirtilen pinlere göre kurun.
2. `ProjeAdi.ino` dosyasını Arduino IDE ile açın ve karta yükleyin.
3. Sistem açıldığında varsayılan modda başlar.
4. **Mod Değişimi:** Devreye bağlı butona basarak Gündüz ve Gece modları arasında geçiş yapabilirsiniz.

## 🔌 Devre Şeması
**

---
*Bu proje Arduino öğrenimi ve trafik sistemlerinin mantığını kavramak amacıyla geliştirilmiştir.*
