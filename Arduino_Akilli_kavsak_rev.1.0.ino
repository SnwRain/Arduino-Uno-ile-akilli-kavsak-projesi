// Define pin numbers for each traffic light color for all four directions
int red1 = 13;   // Red light for direction 1
int yellow1 = 12; // Yellow light for direction 1
int green1 = 11;  // Green light for direction 1
int red2 = 10;   // Red light for direction 2
int yellow2 = 9; // Yellow light for direction 2
int green2 = 8;  // Green light for direction 2
int red3 = 7;    // Red light for direction 3
int yellow3 = 6; // Yellow light for direction 3
int green3 = 5;  // Green light for direction 3
int red4 = 4;    // Red light for direction 4
int yellow4 = 3; // Yellow light for direction 4
int green4 = 2;  // Green light for direction 4

// Ultrasonik sensör pinleri
int trigPin = A0;
int echoPin = A1;

// Buton pini
int butonPin = A2;

// Yaya ışıkları (ana yollar için)
int yaya1 = A3;  // Yol 1 için yaya ışığı
int yaya2 = A4;  // Yol 2 için yaya ışığı
int yaya3 = A5;  // Yol 3 için yaya ışığı
int yaya4Yesil = 1;   // Yol 4 için yaya yeşil ışığı (D1 pini)
int yaya4Kirmizi = 0; // Yol 4 için yaya kırmızı ışığı (D0 pini)

// Mesafe eşiği (cm cinsinden)
int mesafeEsik = 20;

// Mod değişkeni (1: Normal mod, 2: Yanıp sönen mod)
int mod = 1;

// Buton değişkenleri
int oncekiButonDurum = HIGH;  // INPUT_PULLUP kullandığımız için başlangıç HIGH
unsigned long sonBasmaZamani = 0;
unsigned long debounceGecikme = 50;  // 50ms yeterli

void setup() {
  // Set each pin as an OUTPUT
  pinMode(red1, OUTPUT);
  pinMode(yellow1, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(yellow2, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(red3, OUTPUT);
  pinMode(yellow3, OUTPUT);
  pinMode(green3, OUTPUT);
  pinMode(red4, OUTPUT);
  pinMode(yellow4, OUTPUT);
  pinMode(green4, OUTPUT);
  
  // Ultrasonik sensör pinleri
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Buton pini (internal pull-up kullan)
  pinMode(butonPin, INPUT_PULLUP);
  
  // Yaya ışıkları
  pinMode(yaya1, OUTPUT);
  pinMode(yaya2, OUTPUT);
  pinMode(yaya3, OUTPUT);
  pinMode(yaya4Yesil, OUTPUT);
  pinMode(yaya4Kirmizi, OUTPUT);
  
  // NOT: Serial.begin() KALDIRILDI - D0/D1 pinlerini kullanmak için
  // Serial monitör çalışmayacak ama D0/D1 pinleri normal çalışacak
}

// Mesafe ölçme fonksiyonu
long mesafeOlc() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long sure = pulseIn(echoPin, HIGH, 30000);
  long mesafe = sure * 0.034 / 2;
  
  return mesafe;
}

// Buton kontrolü - DÜZELTİLMİŞ VERSİYON
void butonKontrol() {
  int butonDurum = digitalRead(butonPin);
  
  // Butona basıldığında (HIGH'dan LOW'a geçiş)
  if (butonDurum == LOW && oncekiButonDurum == HIGH) {
    unsigned long simdikiZaman = millis();
    if (simdikiZaman - sonBasmaZamani > debounceGecikme) {
      // Mod değiştir
      if (mod == 1) {
        mod = 2;
        // Serial.println kaldırıldı - D0/D1 için
      } else {
        mod = 1;
        // Serial.println kaldırıldı - D0/D1 için
      }
      sonBasmaZamani = simdikiZaman;
    }
  }
  oncekiButonDurum = butonDurum;
}

// Tüm ışıkları kapat
void tumIsiklariKapat() {
  digitalWrite(red1, LOW);
  digitalWrite(yellow1, LOW);
  digitalWrite(green1, LOW);
  digitalWrite(red2, LOW);
  digitalWrite(yellow2, LOW);
  digitalWrite(green2, LOW);
  digitalWrite(red3, LOW);
  digitalWrite(yellow3, LOW);
  digitalWrite(green3, LOW);
  digitalWrite(red4, LOW);
  digitalWrite(yellow4, LOW);
  digitalWrite(green4, LOW);
  digitalWrite(yaya1, LOW);
  digitalWrite(yaya2, LOW);
  digitalWrite(yaya3, LOW);
  digitalWrite(yaya4Yesil, LOW);
  digitalWrite(yaya4Kirmizi, LOW);
}

// Function to turn on green light for direction 1 and red for others
void case1() {
  digitalWrite(red1, LOW);
  digitalWrite(yellow1, LOW);
  digitalWrite(green1, HIGH);
  digitalWrite(red2, HIGH);
  digitalWrite(yellow2, LOW);
  digitalWrite(green2, LOW);
  digitalWrite(red3, HIGH);
  digitalWrite(yellow3, LOW);
  digitalWrite(green3, LOW);
  digitalWrite(red4, HIGH);
  digitalWrite(yellow4, LOW);
  digitalWrite(green4, LOW);
  
  // Yaya ışıkları: Yol 1 yeşil olduğu için yaya1 kapalı, diğerleri açık
  digitalWrite(yaya1, LOW);
  digitalWrite(yaya2, HIGH);
  digitalWrite(yaya3, HIGH);
  digitalWrite(yaya4Yesil, HIGH);    // Yol 4 kırmızı, yaya yeşil
  digitalWrite(yaya4Kirmizi, LOW);
}

// Function for yellow light for direction 1
void case2() {
  digitalWrite(red1, LOW);
  digitalWrite(yellow1, HIGH);
  digitalWrite(green1, LOW);
  digitalWrite(red2, HIGH);
  digitalWrite(yellow2, LOW);
  digitalWrite(green2, LOW);
  digitalWrite(red3, HIGH);
  digitalWrite(yellow3, LOW);
  digitalWrite(green3, LOW);
  digitalWrite(red4, HIGH);
  digitalWrite(yellow4, LOW);
  digitalWrite(green4, LOW);
  
  // Sarı ışıkta yayalar geçemez
  digitalWrite(yaya1, LOW);
  digitalWrite(yaya2, HIGH);
  digitalWrite(yaya3, HIGH);
  digitalWrite(yaya4Yesil, HIGH);    // Yol 4 kırmızı, yaya yeşil
  digitalWrite(yaya4Kirmizi, LOW);
}

// Function to turn on green light for direction 2
void case3() {
  digitalWrite(red1, HIGH);
  digitalWrite(yellow1, LOW);
  digitalWrite(green1, LOW);
  digitalWrite(red2, LOW);
  digitalWrite(yellow2, LOW);
  digitalWrite(green2, HIGH);
  digitalWrite(red3, HIGH);
  digitalWrite(yellow3, LOW);
  digitalWrite(green3, LOW);
  digitalWrite(red4, HIGH);
  digitalWrite(yellow4, LOW);
  digitalWrite(green4, LOW);
  
  // Yaya ışıkları: Yol 2 yeşil olduğu için yaya2 kapalı, diğerleri açık
  digitalWrite(yaya1, HIGH);
  digitalWrite(yaya2, LOW);
  digitalWrite(yaya3, HIGH);
  digitalWrite(yaya4Yesil, HIGH);    // Yol 4 kırmızı, yaya yeşil
  digitalWrite(yaya4Kirmizi, LOW);
}

// Function for yellow light for direction 2
void case4() {
  digitalWrite(red1, HIGH);
  digitalWrite(yellow1, LOW);
  digitalWrite(green1, LOW);
  digitalWrite(red2, LOW);
  digitalWrite(yellow2, HIGH);
  digitalWrite(green2, LOW);
  digitalWrite(red3, HIGH);
  digitalWrite(yellow3, LOW);
  digitalWrite(green3, LOW);
  digitalWrite(red4, HIGH);
  digitalWrite(yellow4, LOW);
  digitalWrite(green4, LOW);
  
  // Sarı ışıkta yayalar geçemez
  digitalWrite(yaya1, HIGH);
  digitalWrite(yaya2, LOW);
  digitalWrite(yaya3, HIGH);
  digitalWrite(yaya4Yesil, HIGH);    // Yol 4 kırmızı, yaya yeşil
  digitalWrite(yaya4Kirmizi, LOW);
}

// Function to turn on green light for direction 3
void case5() {
  digitalWrite(red1, HIGH);
  digitalWrite(yellow1, LOW);
  digitalWrite(green1, LOW);
  digitalWrite(red2, HIGH);
  digitalWrite(yellow2, LOW);
  digitalWrite(green2, LOW);
  digitalWrite(red3, LOW);
  digitalWrite(yellow3, LOW);
  digitalWrite(green3, HIGH);
  digitalWrite(red4, HIGH);
  digitalWrite(yellow4, LOW);
  digitalWrite(green4, LOW);
  
  // Yaya ışıkları: Yol 3 yeşil olduğu için yaya3 kapalı, diğerleri açık
  digitalWrite(yaya1, HIGH);
  digitalWrite(yaya2, HIGH);
  digitalWrite(yaya3, LOW);
  digitalWrite(yaya4Yesil, HIGH);    // Yol 4 kırmızı, yaya yeşil
  digitalWrite(yaya4Kirmizi, LOW);
}

// Function for yellow light for direction 3
void case6() {
  digitalWrite(red1, HIGH);
  digitalWrite(yellow1, LOW);
  digitalWrite(green1, LOW);
  digitalWrite(red2, HIGH);
  digitalWrite(yellow2, LOW);
  digitalWrite(green2, LOW);
  digitalWrite(red3, LOW);
  digitalWrite(yellow3, HIGH);
  digitalWrite(green3, LOW);
  digitalWrite(red4, HIGH);
  digitalWrite(yellow4, LOW);
  digitalWrite(green4, LOW);
  
  // Sarı ışıkta yayalar geçemez
  digitalWrite(yaya1, HIGH);
  digitalWrite(yaya2, HIGH);
  digitalWrite(yaya3, LOW);
  digitalWrite(yaya4Yesil, HIGH);    // Yol 4 kırmızı, yaya yeşil
  digitalWrite(yaya4Kirmizi, LOW);
}

// Function to turn on green light for direction 4 (sensör tetiklendiğinde)
void case7() {
  digitalWrite(red1, HIGH);
  digitalWrite(yellow1, LOW);
  digitalWrite(green1, LOW);
  digitalWrite(red2, HIGH);
  digitalWrite(yellow2, LOW);
  digitalWrite(green2, LOW);
  digitalWrite(red3, HIGH);
  digitalWrite(yellow3, LOW);
  digitalWrite(green3, LOW);
  digitalWrite(red4, LOW);
  digitalWrite(yellow4, LOW);
  digitalWrite(green4, HIGH);
  
  // Yol 4 (tali yol) yeşil olduğunda - yaya kırmızı yanar
  digitalWrite(yaya1, HIGH);
  digitalWrite(yaya2, HIGH);
  digitalWrite(yaya3, HIGH);
  digitalWrite(yaya4Yesil, LOW);     // Yol 4 yeşil, yaya yeşil KAPALI
  digitalWrite(yaya4Kirmizi, HIGH);  // Yol 4 yeşil, yaya kırmızı AÇIK
}

// Function for yellow light for direction 4
void case8() {
  digitalWrite(red1, HIGH);
  digitalWrite(yellow1, LOW);
  digitalWrite(green1, LOW);
  digitalWrite(red2, HIGH);
  digitalWrite(yellow2, LOW);
  digitalWrite(green2, LOW);
  digitalWrite(red3, HIGH);
  digitalWrite(yellow3, LOW);
  digitalWrite(green3, LOW);
  digitalWrite(red4, LOW);
  digitalWrite(yellow4, HIGH);
  digitalWrite(green4, LOW);
  
  // Sarı ışıkta yayalar geçemez
  digitalWrite(yaya1, HIGH);
  digitalWrite(yaya2, HIGH);
  digitalWrite(yaya3, HIGH);
  digitalWrite(yaya4Yesil, LOW);     // Yol 4 sarı, yaya yeşil KAPALI
  digitalWrite(yaya4Kirmizi, HIGH);  // Yol 4 sarı, yaya kırmızı AÇIK
}

// Tüm yolları kırmızıya çevir (4. yol hariç yeşil)
void tumKirmiziYol4Yesil() {
  digitalWrite(red1, HIGH);
  digitalWrite(yellow1, LOW);
  digitalWrite(green1, LOW);
  digitalWrite(red2, HIGH);
  digitalWrite(yellow2, LOW);
  digitalWrite(green2, LOW);
  digitalWrite(red3, HIGH);
  digitalWrite(yellow3, LOW);
  digitalWrite(green3, LOW);
  digitalWrite(red4, LOW);
  digitalWrite(yellow4, LOW);
  digitalWrite(green4, HIGH);
  
  // Yol 4 yeşil olduğunda - yaya kırmızı yanar
  digitalWrite(yaya1, HIGH);
  digitalWrite(yaya2, HIGH);
  digitalWrite(yaya3, HIGH);
  digitalWrite(yaya4Yesil, LOW);     // Yol 4 yeşil, yaya yeşil KAPALI
  digitalWrite(yaya4Kirmizi, HIGH);  // Yol 4 yeşil, yaya kırmızı AÇIK
}

// Mod 2: Yanıp sönen mod
void yanipSonenMod() {
  // Ana yollar (Yol 1 ve 3): Sarı yanıp söner (pinler 12 ve 6)
  // Tali yollar (Yol 2 ve 4): Kırmızı yanıp söner (pinler 10 ve 4)
  // Yaya geçitleri: Kırmızı sabit yanar (yeşil pinleri kapalı tutar)
  
  // Yaya yeşil ışıklarını kapat (böylece sadece kırmızılar yanar)
  digitalWrite(yaya1, LOW);
  digitalWrite(yaya2, LOW);
  digitalWrite(yaya3, LOW);
  digitalWrite(yaya4Yesil, LOW);
  digitalWrite(yaya4Kirmizi, LOW);
  
  while (mod == 2) {
    butonKontrol();
    if (mod == 1) break;
    
    // Işıkları yak
    digitalWrite(yellow1, HIGH);  // Yol 1 sarı (pin 12)
    digitalWrite(yellow3, HIGH);  // Yol 3 sarı (pin 6)
    digitalWrite(red2, HIGH);     // Yol 2 kırmızı (pin 10)
    digitalWrite(red4, HIGH);     // Yol 4 kırmızı (pin 4)
    
    // Diğer tüm ışıkları söndür
    digitalWrite(red1, LOW);
    digitalWrite(green1, LOW);
    digitalWrite(yellow2, LOW);
    digitalWrite(green2, LOW);
    digitalWrite(red3, LOW);
    digitalWrite(green3, LOW);
    digitalWrite(yellow4, LOW);
    digitalWrite(green4, LOW);
    
    delay(500);
    butonKontrol();
    if (mod == 1) break;
    
    // Trafik ışıklarını söndür (yaya ışıkları kapalı kalır)
    digitalWrite(yellow1, LOW);
    digitalWrite(yellow3, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(red4, LOW);
    
    delay(500);
    butonKontrol();
  }
  
  // Mod 1'e döndüğünde tüm ışıkları kapat
  tumIsiklariKapat();
}

void loop() {
  // Buton kontrolü
  butonKontrol();
  
  // Mod 2 ise yanıp sönen moda geç
  if (mod == 2) {
    yanipSonenMod();
    return;
  }
  
  // Mod 1: Normal trafik işleyişi
  // Her döngüde sensörü kontrol et
  long mesafe = mesafeOlc();
  
  if (mesafe > 0 && mesafe < mesafeEsik) {
    // Sensör tetiklendi - 4. yolu yeşile çevir
    // Serial.println kaldırıldı - D0/D1 için
    tumKirmiziYol4Yesil();
    
    // 7 saniye boyunca buton kontrolü yap
    for (int i = 0; i < 70; i++) {
      butonKontrol();
      if (mod == 2) return;
      delay(100);
    }
    
    // Sarıya çevir
    case8();
    
    // 2 saniye boyunca buton kontrolü yap
    for (int i = 0; i < 20; i++) {
      butonKontrol();
      if (mod == 2) return;
      delay(100);
    }
  }
  
  // Normal trafik döngüsü (sadece 1-2-3 yollar)
  case1();  // Green light for direction 1
  for (int i = 0; i < 50; i++) {
    butonKontrol();
    if (mod == 2) return;
    delay(100);
  }
  
  case2();  // Yellow light for direction 1
  for (int i = 0; i < 20; i++) {
    butonKontrol();
    if (mod == 2) return;
    delay(100);
  }
  
  case3();  // Green light for direction 2
  for (int i = 0; i < 50; i++) {
    butonKontrol();
    if (mod == 2) return;
    delay(100);
  }
  
  case4();  // Yellow light for direction 2
  for (int i = 0; i < 20; i++) {
    butonKontrol();
    if (mod == 2) return;
    delay(100);
  }
  
  case5();  // Green light for direction 3
  for (int i = 0; i < 50; i++) {
    butonKontrol();
    if (mod == 2) return;
    delay(100);
  }
  
  case6();  // Yellow light for direction 3
  for (int i = 0; i < 20; i++) {
    butonKontrol();
    if (mod == 2) return;
    delay(100);
  }
}
