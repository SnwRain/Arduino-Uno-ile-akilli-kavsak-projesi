# 🚦 Arduino Tabanlı Sensörlü Kavşak Kontrol Sistemi

Bu proje, trafik yoğunluğunu yönetmek, yaya güvenliğini artırmak ve gereksiz bekleme sürelerini önlemek amacıyla geliştirilmiş sensör destekli akıllı bir trafik kontrol sistemidir. Sistem, **Arduino Nano** kullanılarak kontrol edilmekte olup gerçek bir kavşak mantığına uygun tasarlanmıştır.

## 🎯 Projenin Amacı
* 4 yönlü bir kavşakta araç ve yaya trafiğini düzenlemek.
* Tali yolda araç yokken ana yolu gereksiz yere durdurmamak (Sensörlü Kontrol).
* Yaya ışıklarını araç ışıkları ile senkronize çalıştırarak güvenliği sağlamak.
* Mod değiştirilebilir, taşınabilir ve düşük maliyetli bir sistem oluşturmak.

## ⚙️ Çalışma Modları ve Sistem Mantığı

Sistemde, bir **push buton** ile kontrol edilen iki farklı çalışma modu bulunmaktadır:

### ☀️ 1. Normal Mod (Gündüz)
* **Genel Akış:** Sistem normal kavşak mantığında çalışır.
* **Tali Yol (Akıllı Sensör):** Tali yola yerleştirilen **HC-SR04 Ultrasonik Sensör** araç algılamadığı sürece tali yola yeşil ışık verilmez, ana yol trafiği kesilmez.
* **Tetiklenme:** Sensör araç algıladığında; ana yol sarıdan kırmızıya döner ve tali yol yeşil olur.
* **Yaya Işıkları (Senkron):** Araçlara kırmızı yandığında yayalara yeşil yanacak şekilde senkronize çalışır (Araç-Yaya çakışması önlenir).

### 🌙 2. İkaz / Gece Modu
Trafik yoğunluğunun az olduğu veya uyarı gerektiren durumlar (örn. gece saatleri) için tasarlanmıştır.
* **Ana Yollar:** **SARI** yanıp söner.
* **Tali Yollar:** **KIRMIZI** yanıp söner.
* **Amaç:** Trafiği yavaşlatmak ve dikkatli geçiş sağlamaktır.

## 🛠 Kullanılan Malzemeler ve Donanım
Proje, taşınabilir olması için **9V Pil** ile beslenmektedir ve enerji kontrolü için bir **On/Off anahtar** içerir. Devre bağlantıları sağlamlık açısından **CAT 6e ethernet kablosu** telleri ile yapılmıştır.

| Bileşen | Adet | Açıklama |
|---------|------|----------|
| **Arduino Nano** | 1 | Ana kontrolcü (Uno ile de uyumlu) |
| **HC-SR04 Sensör** | 1 | Tali yol araç algılama |
| **LED (Kırmızı)** | 12 | Araç ve Yaya dur ikazları |
| **LED (Sarı)** | 4 | Araç hazırlık/ikaz ışıkları |
| **LED (Yeşil)** | 12 | Araç ve Yaya geçiş ışıkları |
| **Direnç (330Ω)** | 40 | LED akım sınırlama (Ohm Kanunu'na göre) |
| **Push Buton** | 1 | Mod değiştirme |
| **On/Off Anahtar** | 1 | Güç kontrolü (Pil ömrünü korumak için) |
| **9V Pil** | 1 | Taşınabilir güç kaynağı |

## 🔌 Devre Şeması
![Uploading image.png…]()


## 🚀 Kurulum
1. Devreyi şemada belirtilen pin bağlantılarına göre kurun.
2. Yazılımı Arduino IDE ile karta yükleyin.
3. Sistemi On/Off anahtarı ile açın.
4. Varsayılan olarak Normal Mod başlar. Gece moduna geçmek için butona basın.

---
*Bu proje, Sistem Analizi ve Tasarımı dersi kapsamında Mehmet Ali Şenyılmazlar tarafından hazırlanmıştır.*
