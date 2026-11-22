// func capwap_packet_is_clienthello @ 00597ab0 size=56

bool capwap_packet_is_clienthello(char *param_1)

{
  if ((*param_1 == '\x01') && (param_1[4] == '\x16')) {
    return param_1[0x11] == '\x01';
  }
  return false;
}

