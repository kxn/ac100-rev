// func _uac_wserv_foreach_proc @ 005db8c4 size=616

undefined4 _uac_wserv_foreach_proc(int param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  char *__format;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined2 local_228;
  undefined2 local_226;
  undefined1 auStack_224 [295];
  char local_fd;
  
  memset(auStack_224,0,0x205);
  local_228 = *(undefined2 *)(param_1 + 0x44);
  local_226 = *(undefined2 *)(param_1 + 0x46);
  uVar1 = uac_wservice_get_ap_radio_cnt(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218,&local_228);
  if ((int)uVar1 < 0) {
    uVar5 = 1;
    if (g_wserv_error == 0) {
      return 1;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 1;
    }
    __format = "<wserv>[error]%s(): %d  -> uac_wservice_get_ap_radio_cnt() fail, ret=%d.\r\n";
    uVar4 = 0x2a5;
LAB_005dbab8:
    printf(__format,"_uac_wserv_foreach_proc",uVar4,uVar1);
  }
  else {
    memset(auStack_224,0,0x205);
    iVar2 = wserv_db_get_entry_by_id(*param_2,auStack_224);
    if (iVar2 == 0) {
      if (local_fd == '\0') {
        if (g_wserv_debug == 0) {
          uVar3 = *(uint *)(param_1 + 0x250);
        }
        else {
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            uVar3 = *(uint *)(param_1 + 0x250);
          }
          else {
            printf("<wserv>[debug]%s(): %d  -> wserv_id %d ssidPortalSwitch is off\r\n",
                   "_uac_wserv_foreach_proc",0x2ae,*param_2);
            uVar3 = *(uint *)(param_1 + 0x250);
          }
        }
        if ((uVar3 & 4) != 0) {
          iVar2 = apmngr_db_get_sub_capability_idx(2);
          if ((iVar2 != -1) && ((*(byte *)(param_1 + iVar2 * 4 + 0x263) & 2) != 0)) {
            iVar2 = *(int *)(param_1 + 0x3c);
            goto LAB_005db948;
          }
        }
        uVar5 = 0;
        if (g_wserv_debug == 0) {
          return 0;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0;
        }
        uVar1 = (uint)*(ushort *)(param_1 + 0x10);
        __format = "<wserv>[debug]%s(): %d  -> ap_id %d not support ssidPortalSwitch\r\n";
        uVar4 = 0x2b9;
        goto LAB_005dbab8;
      }
      iVar2 = *(int *)(param_1 + 0x3c);
    }
    else {
      iVar2 = *(int *)(param_1 + 0x3c);
    }
LAB_005db948:
    iVar6 = 1;
    if (iVar2 == 0) {
      uVar5 = 0;
    }
    else {
      while (iVar6 <= (int)uVar1) {
        uVar5 = rdmngr_db_generate_rd_id(*(undefined2 *)(param_1 + 0x10),iVar6);
        if (param_2[6] == 0) {
LAB_005db994:
          iVar2 = param_2[5];
LAB_005db998:
          param_2[5] = iVar2 + 1;
          if ((int)param_2[3] < (int)param_2[1]) {
            param_2[3] = param_2[3] + 1;
            iVar6 = iVar6 + 1;
          }
          else if ((int)param_2[4] < (int)param_2[2]) {
            param_2[4] = param_2[4] + 1;
            _uac_wserv_get_rd_bind_entry(param_1,uVar5,param_2);
            iVar6 = iVar6 + 1;
          }
          else {
            iVar6 = iVar6 + 1;
          }
        }
        else {
          if ((code *)param_2[7] == (code *)0x0) {
            iVar2 = param_2[5];
            goto LAB_005db998;
          }
          iVar2 = (*(code *)param_2[7])(*param_2,uVar5);
          if (iVar2 == 0) goto LAB_005db994;
          iVar6 = iVar6 + 1;
        }
      }
      uVar5 = 0;
    }
  }
  return uVar5;
}

