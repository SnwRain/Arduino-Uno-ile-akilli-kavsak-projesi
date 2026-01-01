# 🚦 Arduino Tabanlı Sensörlü Kavşak Kontrol Sistemi

[cite_start]Bu proje, trafik yoğunluğunu yönetmek, yaya güvenliğini artırmak ve gereksiz bekleme sürelerini önlemek amacıyla geliştirilmiş sensör destekli akıllı bir trafik kontrol sistemidir[cite: 2, 7, 9]. [cite_start]Sistem, **Arduino Nano** (veya Uno) kullanılarak kontrol edilmekte olup gerçek bir kavşak mantığına uygun tasarlanmıştır[cite: 26, 134].

## 🎯 Projenin Amacı
* [cite_start]4 yönlü bir kavşakta araç ve yaya trafiğini düzenlemek[cite: 15].
* [cite_start]Tali yolda araç yokken ana yolu gereksiz yere durdurmamak (Sensörlü Kontrol)[cite: 16].
* [cite_start]Yaya ışıklarını araç ışıkları ile senkronize çalıştırarak güvenliği sağlamak[cite: 17].
* [cite_start]Mod değiştirilebilir, taşınabilir ve düşük maliyetli bir sistem oluşturmak[cite: 18, 19].

## ⚙️ Çalışma Modları ve Sistem Mantığı

[cite_start]Sistemde, bir **push buton** ile kontrol edilen iki farklı çalışma modu bulunmaktadır[cite: 61, 62]:

### [cite_start]☀️ 1. Normal Mod (Gündüz) [cite: 63]
* **Genel Akış:** Sistem normal kavşak mantığında çalışır.
* [cite_start]**Tali Yol (Akıllı Sensör):** Tali yola yerleştirilen **HC-SR04 Ultrasonik Sensör** araç algılamadığı sürece tali yola yeşil ışık verilmez, ana yol trafiği kesilmez[cite: 52, 53, 54].
* [cite_start]**Tetiklenme:** Sensör araç algıladığında; ana yol sarıdan kırmızıya döner ve tali yol yeşil olur[cite: 55, 56, 57, 58].
* [cite_start]**Yaya Işıkları (Senkron):** Araçlara kırmızı yandığında yayalara yeşil yanacak şekilde senkronize çalışır (Araç-Yaya çakışması önlenir)[cite: 42, 43, 47].

### [cite_start]🌙 2. İkaz / Gece Modu [cite: 67]
[cite_start]Trafik yoğunluğunun az olduğu veya uyarı gerektiren durumlar (örn. gece saatleri) için tasarlanmıştır[cite: 71, 72].
* [cite_start]**Ana Yollar:** **SARI** yanıp söner[cite: 68].
* [cite_start]**Tali Yollar:** **KIRMIZI** yanıp söner[cite: 69].
* [cite_start]**Amaç:** Trafiği yavaşlatmak ve dikkatli geçiş sağlamaktır[cite: 70].

## 🛠 Kullanılan Malzemeler ve Donanım
[cite_start]Proje, taşınabilir olması için **9V Pil** ile beslenmektedir ve enerji kontrolü için bir **On/Off anahtar** içerir[cite: 85, 87, 90]. [cite_start]Devre bağlantıları sağlamlık açısından **CAT 6e ethernet kablosu** telleri ile yapılmıştır[cite: 156].

| Bileşen | Adet | Açıklama |
|---------|------|----------|
| **Arduino Nano** | 1 | [cite_start]Ana kontrolcü (Uno ile de uyumlu) [cite: 96, 134] |
| **HC-SR04 Sensör** | 1 | [cite_start]Tali yol araç algılama [cite: 100, 137] |
| **LED (Kırmızı)** | 12 | [cite_start]Araç ve Yaya dur ikazları [cite: 108] |
| **LED (Sarı)** | 4 | [cite_start]Araç hazırlık/ikaz ışıkları [cite: 112] |
| **LED (Yeşil)** | 12 | [cite_start]Araç ve Yaya geçiş ışıkları [cite: 116] |
| **Direnç (330Ω)** | 40 | [cite_start]LED akım sınırlama (Ohm Kanunu'na göre) [cite: 120, 145] |
| **Push Buton** | 1 | [cite_start]Mod değiştirme [cite: 104, 148] |
| **On/Off Anahtar** | 1 | [cite_start]Güç kontrolü (Pil ömrünü korumak için) [cite: 124, 150] |
| **9V Pil** | 1 | [cite_start]Taşınabilir güç kaynağı [cite: 128, 151] |

## 🔌 Devre Şeması
[cite_start]*<img width="943" height="983" alt="image" src="https://github.com/user-attachments/assets/a64cbd37-b097-427a-9966-639fe0c42fee" />
* [cite: 158]

## 🚀 Kurulum
1. Devreyi şemada belirtilen pin bağlantılarına göre kurun.
2. Yazılımı Arduino IDE ile karta yükleyin.
3. Sistemi On/Off anahtarı ile açın.
4. Varsayılan olarak Normal Mod başlar. Gece moduna geçmek için butona basın.

---
[cite_start]*Bu proje, Sistem Analizi ve Tasarımı dersi kapsamında Mehmet Ali Şenyılmazlar tarafından hazırlanmıştır[cite: 1, 2].*
