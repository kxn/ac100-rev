// func apupd_excute_cmd @ 0064c670 size=172

void apupd_excute_cmd(char *param_1)

{
  FILE *__stream;
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  if (param_1 != (char *)0x0) {
    __stream = popen(param_1,"r");
    if (__stream == (FILE *)0x0) {
      if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        __format = "[APUPD_ERROR]%32s() %05d: popen failed!\n\r\n";
        uVar2 = 0xfa;
        goto LAB_0064c6e0;
      }
    }
    else {
      iVar1 = pclose(__stream);
      if (((iVar1 == -1) && (g_apupd_error != 0)) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        __format = "[APUPD_ERROR]%32s() %05d: pclose failed!\n\r\n";
        uVar2 = 0x101;
LAB_0064c6e0:
        printf(__format,"apupd_excute_cmd",uVar2);
        return;
      }
    }
  }
  return;
}

