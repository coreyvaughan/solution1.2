#include <mbed.h>

#include <stdbool.h>

class LED {
  DigitalOut pin;
public:
  LED(PinName p) : pin(p,1) {}
  void  on(void) { pin.write(0);}
  void off(void) { pin.write(1);}
};
LED light[] = { LED(PTB22), LED(PTE26), LED(PTB21) };
enum { Red, Green, Blue};

enum { Btn1, Btn2 };
class Button {
  DigitalIn pin;
public:
  Button(PinName p) : pin(p) {};
  bool ispressed(void) { return !pin.read(); };
};
Button buttons[] = {Button(SW2), Button(SW3)};
int main() {
    bool flashing = false;


    while(1) {
        if(buttons[Btn1].ispressed() ) flashing = true;
        if(buttons[Btn2].ispressed() ) flashing = false;

        if(flashing){
            light[Red].on();
            wait(0.5);
            light[Red].off();
            wait(0.5);
        }else{
            light[Red].off();
            wait(1);
        }
    }
}
