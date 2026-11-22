// func cloud_mngt_client_update_func @ 0049779c size=332

undefined4 cloud_mngt_client_update_func(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *__dest;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  if (param_2 == (int *)0x0) {
    return 0;
  }
  iVar1 = *param_1;
  iVar2 = *param_2;
  if (iVar1 == iVar2) {
LAB_0049783c:
    if (cloud_mngt_debug_switch == '\0') {
      return 1;
    }
    printf("[CLOUD_MNGT_DEBUG]%s()/%d should not happen\n","cloud_mngt_client_update_func",0x68d);
    return 1;
  }
  if (iVar1 - 3U < 2) {
    if (iVar2 == 1) goto LAB_0049783c;
  }
  else {
    if (iVar1 == 1) {
      if (iVar2 == 2) {
        return 2;
      }
      return 1;
    }
    if (iVar1 == 2) {
      if (iVar2 != 1) {
        return 1;
      }
      param_1 = param_1 + 4;
      iVar1 = memcmp(param_1,param_2 + 4,6);
      if (iVar1 == 0) {
        *param_2 = 3;
        return 3;
      }
      __dest = (int *)((int)param_2 + 10);
      *param_2 = 4;
      goto LAB_004978b0;
    }
  }
  if (iVar1 != 4) {
    if (iVar1 != 3) {
      return 1;
    }
    if (iVar2 == 2) {
      return 3;
    }
    return 1;
  }
  if (iVar2 != 2) {
    return 1;
  }
  __dest = param_2 + 4;
  param_1 = (int *)((int)param_1 + 10);
LAB_004978b0:
  memcpy(__dest,param_1,6);
  return 3;
}

