// func cw_priv_wsrv_para_new_len_get @ 005cec90 size=468

short cw_priv_wsrv_para_new_len_get(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  short sVar5;
  
  sVar5 = 0;
  if (param_1 == 0) {
    return 0;
  }
  switch(*(undefined1 *)(param_1 + 8)) {
  case 0:
    sVar5 = 9;
    break;
  case 1:
  case 4:
    sVar5 = *(short *)(*(int *)(param_1 + 9) + 6) + 0x11;
    break;
  case 2:
    iVar4 = *(int *)(param_1 + 9);
    if (*(char *)(iVar4 + 6) == '\x01') {
      sVar5 = *(short *)(iVar4 + 0x48) + 0x1e;
LAB_005ced8c:
      if (*(char *)(iVar4 + 0x1a) == '\x01') {
        sVar5 = sVar5 + 4;
      }
      else {
        sVar5 = sVar5 + 0x10;
        if (*(char *)(iVar4 + 0x1a) != '\x02') {
          if (capwap_err_switch == 0) {
            return 0;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0;
          }
          uVar3 = (uint)*(byte *)(iVar4 + 0x1a);
          uVar2 = 0x2fd;
          goto LAB_005cede0;
        }
      }
      if (*(char *)(iVar4 + 0x2e) == '\x01') {
        return sVar5 + 4;
      }
      if (*(char *)(iVar4 + 0x2e) == '\x02') {
        return sVar5 + 0x10;
      }
      if (capwap_err_switch == 0) {
        return 0;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0;
      }
      uVar3 = (uint)*(byte *)(iVar4 + 0x2e);
      uVar2 = 0x30a;
    }
    else {
      sVar5 = *(short *)(iVar4 + 0x48) + 0x2a;
      if (*(char *)(iVar4 + 6) == '\x02') goto LAB_005ced8c;
      if (capwap_err_switch == 0) {
        return 0;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0;
      }
      uVar3 = (uint)*(byte *)(iVar4 + 6);
      uVar2 = 0x2f0;
    }
LAB_005cede0:
    sVar5 = 0;
    printf("[CW_ERROR]%32s():%4d Illegal ip type:%d\n","cw_priv_wsrv_para_new_len_get",uVar2,uVar3);
    break;
  case 3:
    sVar5 = 0x8f;
  }
  return sVar5;
}

