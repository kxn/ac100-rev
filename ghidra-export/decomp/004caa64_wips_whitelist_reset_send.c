// func wips_whitelist_reset_send @ 004caa64 size=140

void wips_whitelist_reset_send(uint param_1)

{
  undefined1 auStack_48 [64];
  
  param_1 = param_1 & 0xffff;
  if (sensor_debug_switch != '\0') {
    printf("[SENSOR_DEBUG]%s()/%d reset ap[id=%d]\'s whitelist\n","wips_whitelist_reset_send",0x5f8,
           param_1);
  }
  memcpy(auStack_48,"{\"method\":\"do\",\"sensor_white_list\":{\"reset_white_list\":null}}",0x3e);
  if (param_1 == 0xffff) {
    sensor_pkt_tdcp_send_all(auStack_48);
  }
  else {
    sensor_pkt_tdcp_send(param_1,auStack_48);
  }
  return;
}

