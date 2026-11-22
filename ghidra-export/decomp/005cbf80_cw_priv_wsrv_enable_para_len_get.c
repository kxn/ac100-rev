// func cw_priv_wsrv_enable_para_len_get @ 005cbf80 size=504

short cw_priv_wsrv_enable_para_len_get(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  short sVar4;
  int iVar5;
  
  if (param_1 == 0) {
    return 0;
  }
  sVar4 = *(short *)(param_1 + 8) + 0xc;
  switch(*(undefined1 *)(param_1 + 0xf)) {
  case 0:
    break;
  case 1:
  case 4:
    sVar4 = sVar4 + *(short *)(*(int *)(param_1 + 0x10) + 6) + 8;
    break;
  case 2:
    iVar5 = *(int *)(param_1 + 0x10);
    sVar4 = sVar4 + *(short *)(iVar5 + 0x48);
    if (*(char *)(iVar5 + 6) == '\x01') {
      sVar4 = sVar4 + 0x15;
    }
    else {
      sVar4 = sVar4 + 0x21;
      if (*(char *)(iVar5 + 6) != '\x02') {
        if (capwap_err_switch == 0) {
          return 0;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0;
        }
        uVar3 = (uint)*(byte *)(iVar5 + 6);
        uVar2 = 0x306;
        goto LAB_005cc0f4;
      }
    }
    if (*(char *)(iVar5 + 0x1a) == '\x01') {
      sVar4 = sVar4 + 4;
    }
    else {
      sVar4 = sVar4 + 0x10;
      if (*(char *)(iVar5 + 0x1a) != '\x02') {
        if (capwap_err_switch == 0) {
          return 0;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0;
        }
        uVar3 = (uint)*(byte *)(iVar5 + 0x1a);
        uVar2 = 0x313;
        goto LAB_005cc0f4;
      }
    }
    if (*(char *)(iVar5 + 0x2e) == '\x01') {
      sVar4 = sVar4 + 4;
    }
    else {
      sVar4 = sVar4 + 0x10;
      if ((*(char *)(iVar5 + 0x2e) != '\x02') && (sVar4 = 0, capwap_err_switch != 0)) {
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0;
        }
        uVar3 = (uint)*(byte *)(iVar5 + 0x2e);
        uVar2 = 800;
LAB_005cc0f4:
        printf("[CW_ERROR]%32s():%4d Illegal ip type:%d\n","cw_priv_wsrv_enable_para_len_get",uVar2,
               uVar3);
        return 0;
      }
    }
    break;
  case 3:
    sVar4 = *(short *)(param_1 + 8) + 0x92;
    break;
  default:
    sVar4 = 0;
  }
  return sVar4;
}

