#include <LCD5110_Graph.h> //Kütüphaneyi projeye dahil ettik. 
  LCD5110 myGLCD(8,9,10,11,12);
  extern unsigned char TinyFont[];
  extern uint8_t BigNumbers[];
  int maxval = 0;
  int dezenfektansayisi =0;
  
  void setup() {
   myGLCD.InitLCD();
  }
  
  void loop() {
  int alkol = analogRead(A2);
  int alkol_grafik = map(alkol,0,1023,2,81);
  
  myGLCD.clrScr();
  myGLCD.setFont(BigNumbers);
  myGLCD.printNumI(alkol,10,10);
  myGLCD.setFont(TinyFont);
  myGLCD.print("ALKOLMETRE", CENTER, 0);
  
  cerceve(); // Progressbar çerçevesi çizdirilir.
  yuzde_dolum(alkol_grafik); 
  
  if (alkol > maxval) { //Maksimum ölçüm değerini elde ediyoruz.
    maxval = alkol;
  }
  if (maxval < 100) {
   dezenfektansayisi = 0;
   }
  if (maxval > 100 && maxval < 160) {
    dezenfektansayisi=1;
  }
  if (maxval > 161 && maxval < 200) {
    dezenfektansayisi=2;
  }
  if (maxval > 201 && maxval < 230) {
    dezenfektansayisi=3;
  }
  
  myGLCD.print("MAX: ", 55, 15); // Maksimum ölçüm değeri
  myGLCD.print("DZNF: ", 55, 25); //Mevcut alkol ölçümünün tahmini kaç dezenfektana denk gelir
  myGLCD.printNumI(maxval, 72, 15);
  myGLCD.printNumI(dezenfektansayisi, 75, 25);
  myGLCD.update();
  delay(100);
  }
  
  void cerceve(){ //Dis cerceve
    
    myGLCD.drawRect(2, 38, 81, 47);
    myGLCD.update(); 
  }
  
  void yuzde_dolum(int yuzde){  //ProgressBar algoritması.. Aslında birbirine paralel uzayan kısalan çizgilerden ibaret...
      myGLCD.drawLine(2, 39, yuzde, 39);
      myGLCD.drawLine(2, 40, yuzde, 40);
      myGLCD.drawLine(2, 41, yuzde, 41);
      myGLCD.drawLine(2, 42, yuzde, 42);
      myGLCD.drawLine(2, 43, yuzde, 43);
      myGLCD.drawLine(2, 44, yuzde, 44);
      myGLCD.drawLine(2, 45, yuzde, 45);
      myGLCD.drawLine(2, 46, yuzde, 46);
  }
