// func _wportal_auth_type_int2chinesestr @ 00411690 size=152

char * _wportal_auth_type_int2chinesestr(int param_1)

{
  if (param_1 == 1) {
    return &DAT_006778cc;
  }
  if (param_1 == 2) {
    return &DAT_006778d8;
  }
  if (param_1 == 4) {
    return &DAT_006778e8;
  }
  if (param_1 != 8) {
    if (param_1 == 0x10) {
      return &DAT_00677908;
    }
    if (param_1 != 0x20) {
      if (param_1 == 0x40) {
        return &DAT_006778c0;
      }
      return "--";
    }
    return &DAT_006778b4;
  }
  return &DAT_006778f8;
}

