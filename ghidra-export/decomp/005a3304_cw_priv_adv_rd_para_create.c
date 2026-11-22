// func cw_priv_adv_rd_para_create @ 005a3304 size=348

int cw_priv_adv_rd_para_create(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  char cVar5;
  
  iVar1 = cw_protocol_clone(param_1,0x1c);
  if (iVar1 == 0) {
    iVar4 = 0;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_adv_rd_para_create",0x123);
    }
  }
  else {
    cVar5 = '\0';
    if (param_1 != -0x16) {
      iVar2 = 0;
      iVar4 = param_1;
      do {
        cVar5 = '\x06';
        if (*(char *)(iVar4 + 0x16) != -1) goto LAB_005a3360;
        iVar2 = iVar2 + 1;
        iVar4 = param_1 + iVar2;
      } while (iVar2 != 6);
      cVar5 = '\0';
    }
LAB_005a3360:
    cVar3 = '\x04';
    if (((*(char *)(param_1 + 0x11) == -1) && (*(short *)(param_1 + 0x12) == 0x1ff)) &&
       (*(char *)(param_1 + 0x14) == '\x01')) {
      cVar3 = '\0';
    }
    iVar4 = cw_protocol_msg_ele_create
                      (8,cVar5 + cVar3 + (*(char *)(param_1 + 0x15) != -1) + '\x10',iVar1);
    if (iVar4 == 0) {
      if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
               "cw_priv_adv_rd_para_create",0x130);
      }
      FUN_00407df0(iVar1);
    }
  }
  return iVar4;
}

