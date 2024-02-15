# AT commands for RAK3172

Initialize the LoRa module (use 868 MHz for testing)

- Frequency: 868 MHz (868000000)
- Spreading Factor: 12 (12)
- Bandwidth: 125 kHz (0)
- Code Rate: 4/5 (0)
- Preamble Length: 8 (8)
- Tx Power: 14 dBm (14)

```
AT+NWM=0
AT+P2P=868000000:12:0:0:8:14
```

Initialize the LoRa module with the right frequency

```
AT+NWM=0
AT+P2P=433775000:12:0:0:8:14
```

Transmit a coordinate point via APRS

- Header: <FF01
- Payload: DO2DKH-7>APLG01:!4932.05NL01047.50E&Test

```
AT+PSEND=3CFF01444F32444B482D373E41504C4730313A21343933322E30354E4C30313034372E353045265465737432
AT+PRECV=65534
```