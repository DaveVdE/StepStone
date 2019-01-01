#include "MIDIUSB.h"
#include "CSequencer.h"
#include "CGrid.h"

CSequencer sequencer;
CGrid grid(sequencer);

void setup() {
  grid.initialize();
}

#define MIDI_CLOCK 0xF8
#define MIDI_START 0xFA
#define MIDI_STOP 0xFC

void handleMIDIInput() 
{
  midiEventPacket_t rx;

  while ((rx = MidiUSB.read()).byte1 != 0)
  {
      switch (rx.byte1)
      {
        case MIDI_START:
          sequencer.start();
          grid.render();
          break;

        case MIDI_STOP:
          sequencer.stop();
          grid.render();
          break;

        case MIDI_CLOCK:
          sequencer.handlePulse();
          grid.render();
          break;
      }
  }
}

void loop() {
  handleMIDIInput();
}
