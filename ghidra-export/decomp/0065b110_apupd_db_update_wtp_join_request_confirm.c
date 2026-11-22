// func apupd_db_update_wtp_join_request_confirm @ 0065b110 size=1660

undefined4 apupd_db_update_wtp_join_request_confirm(int param_1,ushort *param_2)

{
  int iVar1;
  int iVar2;
  char cVar6;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char *__format;
  int iVar7;
  int iVar8;
  void *__s2;
  int iVar9;
  undefined1 auStack_220 [64];
  char acStack_1e0 [128];
  char acStack_160 [156];
  undefined1 auStack_c4 [160];
  
  if (((param_1 == 0) || (param_2 == (ushort *)0x0)) || (apupd_update_wtp_hash == 0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_db_update_wtp_join_request_confirm",
           0x25ca);
    return 0xffffffff;
  }
  FUN_004082d0(apupd_db_mutex,0xffffffff);
  iVar1 = FUN_00407fa0(apupd_update_wtp_hash,param_1);
  if (iVar1 == 0) {
    if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: wtp isn\'t updating, so don\'t confirm it in join reqeust.\r\n"
             ,"apupd_db_update_wtp_join_request_confirm",0x25d4);
    }
    goto LAB_0065b458;
  }
  iVar9 = *(int *)(iVar1 + 0x34);
  iVar8 = *(int *)(iVar1 + 0x30);
  iVar7 = *(int *)(iVar9 + 0x10);
  if ((*(int *)(iVar1 + 0x20) != 4) || (*(int *)(iVar8 + 0x48) != 7)) {
    if ((g_apupd_error != 0) && (iVar7 = is_target_debug_ap(apupd_db_mutex), iVar7 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: update wtp state(%d) or wtp state(%d) is invalib.\r\n",
             "apupd_db_update_wtp_join_request_confirm",0x25e1,*(undefined4 *)(iVar1 + 0x20),
             *(undefined4 *)(iVar8 + 0x48));
    }
    goto LAB_0065b684;
  }
  __s2 = (void *)0x0;
  if ((*(char *)(iVar7 + 0x138) != '\x01') && (*(char *)(iVar7 + 0x138) != '\x03')) {
    iVar2 = *(int *)(iVar7 + 0x7ec);
    __s2 = (void *)(iVar7 + 0x1c4);
    if (iVar2 != 2) {
      if (iVar2 == 1) {
LAB_0065b6a0:
        iVar2 = FUN_00407fa0(*(undefined4 *)(iVar9 + 0x2c),iVar8 + 0x58);
        __s2 = (void *)(iVar2 + 0x164);
        if (iVar2 == 0) {
          __s2 = (void *)0x0;
        }
      }
      else if (iVar2 == 3) {
        if (*(int *)(iVar8 + 0x54) == 1) goto LAB_0065b6a0;
        __s2 = (void *)(iVar1 + 0x3c);
      }
      else {
        __s2 = (void *)(iVar1 + 0x3c);
      }
    }
  }
  if (g_apupd_debug == 0) {
    cVar6 = *(char *)(iVar7 + 0x138);
  }
  else {
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      cVar6 = *(char *)(iVar7 + 0x138);
    }
    else {
      printf("[APUPD_DEBUG]%32s() %05d: tmp_model->is_large_fw = %d\r\n",
             "apupd_db_update_wtp_join_request_confirm",0x25f8,(uint)*(byte *)(iVar7 + 0x13a));
      cVar6 = *(char *)(iVar7 + 0x138);
    }
  }
  if ((((cVar6 == '\x01') || (cVar6 == '\x03')) ||
      ((__s2 != (void *)0x0 && (iVar2 = memcmp(param_2,__s2,0x10), iVar2 == 0)))) ||
     (*(char *)(iVar7 + 0x13a) != '\0')) {
    if ((g_apupd_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: comfirm update wtp successed, wtp enters to FINISH.\r\n",
             "apupd_db_update_wtp_join_request_confirm",0x25fc);
    }
    *(undefined4 *)(iVar8 + 0x48) = 8;
    *(int *)(iVar7 + 0x14c) = *(int *)(iVar7 + 0x14c) + 1;
    memset(acStack_160,0,0x80);
    uVar3 = *(uint *)(param_2 + 4);
    sprintf(acStack_160,"%d.%d.%d Build %02d%02d%02d Rel.%05d",(uint)*param_2,(uint)param_2[1],
            (uint)param_2[2],uVar3 >> 0x10,(uVar3 << 0x10) >> 0x18,uVar3 & 0xff,
            *(undefined4 *)(param_2 + 6));
    memset(acStack_1e0,0,0x80);
    sprintf(acStack_1e0,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(iVar8 + 0x2e),
            (uint)*(byte *)(iVar8 + 0x2f),(uint)*(byte *)(iVar8 + 0x30),
            (uint)*(byte *)(iVar8 + 0x31),(uint)*(byte *)(iVar8 + 0x32),
            (uint)*(byte *)(iVar8 + 0x33));
    memset(auStack_220,0,0x40);
    memset(auStack_c4,0,0x9a);
    FUN_00408190(*(undefined4 *)(iVar8 + 0x18),*(undefined4 *)(iVar8 + 0x1c),
                 *(undefined4 *)(iVar8 + 0x20),*(undefined4 *)(iVar8 + 0x24),
                 *(undefined4 *)(iVar8 + 0x28),auStack_220,0x40,"---");
    uVar4 = apmngr_db_product_type_str(*(undefined1 *)(*(int *)(iVar8 + 0x50) + 0x138));
    uVar5 = FUN_006505b0(iVar8 + 0x2e,auStack_c4);
    loggerk_reg(0x54,0x3812,1,uVar4,1,uVar5,1,auStack_220,1,acStack_1e0,1,acStack_160,0);
LAB_0065b420:
    apupd_updating_wtp_num = apupd_updating_wtp_num + -1;
    iVar1 = apupd_update_wtp_entry_delete(iVar1);
    if (iVar1 == -1) {
      if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 == 0))
      goto LAB_0065b684;
      __format = "[APUPD_ERROR]%32s() %05d: delete update wtp failed.\r\n";
      uVar4 = 0x262e;
    }
    else {
      iVar1 = apupd_update_wtp_entry_delete_after_handle(iVar9,iVar8);
      if (iVar1 != -1) {
LAB_0065b458:
        FUN_00407f30(apupd_db_mutex);
        return 0;
      }
      if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 == 0))
      goto LAB_0065b684;
      __format = "[APUPD_ERROR]%32s() %05d: handle update mdoel failed.\r\n";
      uVar4 = 0x2634;
    }
  }
  else {
    if ((g_apupd_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: comfirm update wtp failed, wtp enters to CONFIRM_FAIL.\r\n",
             "apupd_db_update_wtp_join_request_confirm",0x2616);
    }
    *(undefined4 *)(iVar8 + 0x48) = 9;
    if ((*(int *)(iVar7 + 0x7ec) == 3) || (iVar7 = apupd_wtp_log_entry_add(iVar8,2), iVar7 != -1)) {
      memset(acStack_1e0,0,0x80);
      sprintf(acStack_1e0,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(iVar8 + 0x2e),
              (uint)*(byte *)(iVar8 + 0x2f),(uint)*(byte *)(iVar8 + 0x30),
              (uint)*(byte *)(iVar8 + 0x31),(uint)*(byte *)(iVar8 + 0x32),
              (uint)*(byte *)(iVar8 + 0x33));
      memset(auStack_220,0,0x40);
      memset(acStack_160,0,0x9a);
      FUN_00408190(*(undefined4 *)(iVar8 + 0x18),*(undefined4 *)(iVar8 + 0x1c),
                   *(undefined4 *)(iVar8 + 0x20),*(undefined4 *)(iVar8 + 0x24),
                   *(undefined4 *)(iVar8 + 0x28),auStack_220,0x40,"---");
      uVar4 = apmngr_db_product_type_str(*(undefined1 *)(*(int *)(iVar8 + 0x50) + 0x138));
      uVar5 = FUN_006505b0(iVar8 + 0x2e,acStack_160);
      loggerk_reg(0x54,0x3814,1,uVar4,1,uVar5,1,auStack_220,1,acStack_1e0,0);
      goto LAB_0065b420;
    }
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 == 0))
    goto LAB_0065b684;
    __format = "[APUPD_ERROR]%32s() %05d: add log failed.\r\n";
    uVar4 = 0x261a;
  }
  printf(__format,"apupd_db_update_wtp_join_request_confirm",uVar4);
LAB_0065b684:
  FUN_00407f30(apupd_db_mutex);
  return 0xffffffff;
}

