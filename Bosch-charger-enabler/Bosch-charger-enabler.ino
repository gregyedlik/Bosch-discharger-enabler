// send a frame from can bus

#include <SPI.h>
#include "mcp_can.h"

#include <mcp_can.h>
#include <SPI.h>

const int SPI_CS_PIN = 17;              // CANBed CS pin selection
unsigned char data[1] = {0};            // Data to transmit, invariant

MCP_CAN CAN(SPI_CS_PIN);                // Set CS pin
 

void setup()
{
  CAN.begin(CAN_500KBPS);
  CAN.sendMsgBuf(0x9A, 0, 1, data);   // send data:  ID, frame type, DCL, data

  for (int i = 0; i < 1000; i++)
    delayMicroseconds(100);           // send data every 100ms
}

void loop()
{
  CAN.sendMsgBuf(0x9A, 0, 1, data);   // send data:  ID, frame type, DCL, data

  for (int i = 0; i < 1000; i++)
    delayMicroseconds(100);           // send data every 100ms
}
