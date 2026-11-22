// func cw_priv_apdb_info_create @ 005ab0b8 size=420

int cw_priv_apdb_info_create(short *param_1)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  char *__format;
  undefined4 uVar5;
  
  puVar2 = (undefined2 *)cw_protocol_clone(param_1,8);
  if (puVar2 == (undefined2 *)0x0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_apdb_info_create",0xe0);
    return 0;
  }
  *(undefined4 *)(puVar2 + 2) = 0;
  if (*param_1 == 0) {
    uVar1 = *puVar2;
LAB_005ab10c:
    iVar3 = cw_protocol_msg_ele_create(0x51,uVar1,puVar2);
    if (iVar3 == 0) {
      if (capwap_err_switch == 0) {
        iVar4 = *(int *)(puVar2 + 2);
      }
      else {
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          iVar4 = *(int *)(puVar2 + 2);
        }
        else {
          printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
                 "cw_priv_apdb_info_create",0xfb);
          iVar4 = *(int *)(puVar2 + 2);
        }
      }
      if (iVar4 != 0) {
        FUN_00407df0();
      }
      FUN_00407df0(puVar2);
    }
  }
  else {
    if (*(int *)(param_1 + 2) == 0) {
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        __format = "[CW_ERROR]%32s():%4d data is null\n";
        uVar5 = 0xea;
LAB_005ab228:
        printf(__format,"cw_priv_apdb_info_create",uVar5);
      }
    }
    else {
      iVar3 = cw_protocol_clone();
      *(int *)(puVar2 + 2) = iVar3;
      if (iVar3 != 0) {
        uVar1 = *puVar2;
        goto LAB_005ab10c;
      }
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        __format = "[CW_ERROR]%32s():%4d failed to clone data\n";
        uVar5 = 0xf1;
        goto LAB_005ab228;
      }
    }
    FUN_00407df0(puVar2);
    iVar3 = 0;
  }
  return iVar3;
}

