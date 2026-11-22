// func apupd_str_to_args @ 0064552c size=320

int apupd_str_to_args(int param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 local_28 [3];
  
  local_28[0] = 0;
  if ((((param_1 == 0) || (param_2 == 0)) || (param_3 == (int *)0x0)) || (param_4 < 1)) {
    iVar3 = -1;
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
      uVar2 = 0x412;
LAB_00645628:
      iVar3 = -1;
      printf(__format,"apupd_str_to_args",uVar2);
    }
  }
  else {
    iVar1 = apupd_str_to_kr(param_1,param_2,local_28);
    iVar3 = 0;
    piVar4 = param_3;
    while (iVar1 != 0) {
      if (param_4 + -1 <= iVar3) {
        if (g_apupd_error == 0) {
          return -1;
        }
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          return -1;
        }
        __format = "[APUPD_ERROR]%32s() %05d: too many arguments.\r\n";
        uVar2 = 0x41b;
        goto LAB_00645628;
      }
      *piVar4 = iVar1;
      iVar1 = apupd_str_to_kr(0,param_2,local_28);
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 1;
    }
    param_3[iVar3] = 0;
  }
  return iVar3;
}

