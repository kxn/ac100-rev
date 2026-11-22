// func cloud_mngt_ap_update_func @ 00491598 size=180

int cloud_mngt_ap_update_func(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  if (param_2 == (int *)0x0) {
    return 0;
  }
  iVar2 = *param_1;
  iVar1 = *param_2;
  if (iVar2 == iVar1) {
LAB_0049161c:
    iVar3 = 1;
    if (cloud_mngt_debug_switch != '\0') {
      printf("[CLOUD_MNGT_DEBUG]%s()/%d should not happen\n","cloud_mngt_ap_update_func",0x665);
    }
  }
  else {
    if (iVar2 == 5) {
      iVar2 = 1;
      iVar3 = 3;
      if (iVar1 == 1) goto LAB_0049161c;
    }
    else {
      iVar3 = 2;
      if (iVar2 != 1) {
        if (iVar2 != 3) {
          return 1;
        }
        if (iVar1 != 1) {
          return 1;
        }
        *param_2 = 5;
        return 3;
      }
    }
    if (iVar1 != 3) {
      iVar3 = iVar2;
    }
  }
  return iVar3;
}

