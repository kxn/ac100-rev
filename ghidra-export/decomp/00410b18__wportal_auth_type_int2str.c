// func _wportal_auth_type_int2str @ 00410b18 size=148

char * _wportal_auth_type_int2str(int param_1)

{
  char *pcVar1;
  
  if (param_1 == 1) {
    return "web";
  }
  if (param_1 == 2) {
    return "wechat";
  }
  if (param_1 == 4) {
    return "onekey";
  }
  if (param_1 != 8) {
    if (param_1 == 0x10) {
      return "remote";
    }
    if (param_1 != 0x20) {
      pcVar1 = (char *)0x0;
      if (param_1 == 0x40) {
        pcVar1 = "cloud";
      }
      return pcVar1;
    }
    return "cmcc";
  }
  return "sms";
}

