// func _apdb_radio_freq_string_to_enum @ 005fc244 size=160

undefined4 _apdb_radio_freq_string_to_enum(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == (char *)0x0) {
    uVar2 = 0xffffffff;
    if (apdb_err_switch != 0) {
      printf("[APDB_ERROR]%s()/line %d : input string null.\n","_apdb_radio_freq_string_to_enum",
             0x70e);
    }
  }
  else {
    iVar1 = strncmp("2.4G",param_1,4);
    uVar2 = 0;
    if (iVar1 != 0) {
      iVar1 = strncmp("5.0G",param_1,4);
      uVar2 = 0xffffffff;
      if (iVar1 == 0) {
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}

