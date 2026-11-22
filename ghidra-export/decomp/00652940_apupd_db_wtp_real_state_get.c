// func apupd_db_wtp_real_state_get @ 00652940 size=208

int apupd_db_wtp_real_state_get(int param_1,int *param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    if (g_apupd_error == 0) {
      return -1;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return -1;
    }
    __format = "[APUPD_ERROR]%32s() %05d: inputs  error.\r\n";
    uVar2 = 0x1ae2;
  }
  else {
    if (*param_2 == 1) {
      return *(int *)(param_1 + 0x48);
    }
    if (*param_2 == 0) {
      if (*(int *)(param_1 + 0x48) - 1U < 2) {
        return 0xb;
      }
      return *(int *)(param_1 + 0x48);
    }
    if (g_apupd_error == 0) {
      return -1;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return -1;
    }
    __format = "[APUPD_ERROR]%32s() %05d: some error occured.\r\n";
    uVar2 = 0x1af7;
  }
  printf(__format,"apupd_db_wtp_real_state_get",uVar2);
  return -1;
}

