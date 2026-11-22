// func _uac_lldp_request @ 004a41c4 size=388

undefined4 _uac_lldp_request(size_t *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  void *__s;
  size_t sVar2;
  undefined4 uVar3;
  undefined1 auStack_2f8 [16];
  ushort local_2e8;
  
  uVar3 = 0;
  memset(auStack_2f8,0,0x2d8);
  FUN_004082d0(uac_lldp_mutex,0xffffffff);
  iVar1 = g_is_continue;
  FUN_00407f30(uac_lldp_mutex);
  if (iVar1 == 1) {
    iVar1 = apmngr_db_entry_get_by_mac(param_3,auStack_2f8);
    if (iVar1 == 0) {
      uVar3 = 0xffffffff;
      iVar1 = FUN_00408450(0x18,0x1de);
      if (iVar1 != 0) {
        *(uint *)(iVar1 + 0xc) = (uint)local_2e8;
        sVar2 = *param_1;
        *(size_t *)(iVar1 + 0x10) = sVar2;
        if (sVar2 != 0) {
          __s = (void *)FUN_00408450(sVar2 + 1,0x1e7);
          *(void **)(iVar1 + 0x14) = __s;
          if (__s == (void *)0x0) {
            FUN_00407df0(iVar1);
            return 0xffffffff;
          }
          memset(__s,0,*(int *)(iVar1 + 0x10) + 1);
          memcpy(*(void **)(iVar1 + 0x14),(void *)param_1[1],*param_1);
        }
        uVar3 = 0;
        FUN_004082d0(uac_lldp_mutex,0xffffffff);
        FUN_004086b0(&g_uac_lldp_list,iVar1);
        g_total_cnt = g_total_cnt + 1;
        FUN_00407f30(uac_lldp_mutex);
      }
    }
    else {
      uVar3 = 0xffffffff;
      if (uac_lldp_err_switch != '\0') {
        printf("[UAC_LLDP_ERROR]%s()/%d apmngr_db_entry_get_by_mac() fail.\n","_uac_lldp_request",
               0x1db);
      }
    }
  }
  return uVar3;
}

