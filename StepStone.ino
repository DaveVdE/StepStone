#include "MIDIUSB.h"
#include "CSequencer.h"
#include "CGrid.h"

CSequencer sequencer;
CGrid grid(sequencer);

void setup() {
  grid.Initialize();
}

void HandleMIDIInput() 
{
  midiEventPacket_t rx;

  do 
  {
      rx = MidiUSB.read();

      if (rx.byte1 == 0xFA)
      {
        sequencer.Start();
      }

      if (rx.byte1 == 0xF8)
      {
        sequencer.HandlePulse();
        grid.Render();
      }
  }
  while (rx.header != 0);
}
void loop() {
  HandleMIDIInput();
}
