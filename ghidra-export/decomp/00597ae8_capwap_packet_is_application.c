// func capwap_packet_is_application @ 00597ae8 size=44

bool capwap_packet_is_application(char *param_1)

{
  if ((param_1 != (char *)0x0) && (*param_1 == '\x01')) {
    return param_1[4] == '\x17';
  }
  return false;
}

