// func balance_db_wtp_delete @ 0045cd30 size=936

undefined4 balance_db_wtp_delete(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  undefined4 *__s;
  int iVar7;
  char *__format;
  undefined4 uVar8;
  undefined4 local_20 [2];
  
  if ((param_1 == 0) || (balance_wtp_hash == 0)) {
    if (g_balance_error == 0) {
      return 0xffffffff;
    }
    iVar7 = is_target_debug_ap();
    if (iVar7 == 0) {
      return 0xffffffff;
    }
    printf("[BALANCE_ERROR](%32s) %05d: inputs error\r\n","balance_db_wtp_delete",0x593);
    return 0xffffffff;
  }
  FUN_004082d0(balance_db_mutex,0xffffffff);
  __s = (undefined4 *)FUN_00407fa0(balance_wtp_hash,param_1 + 8);
  if (__s == (undefined4 *)0x0) {
    if ((g_balance_debug != 0) && (iVar7 = is_target_debug_ap(balance_db_mutex), iVar7 != 0)) {
      bVar1 = *(byte *)(param_1 + 9);
      bVar2 = *(byte *)(param_1 + 8);
      __format = 
      "[BALANCE_DEBUG](%32s) %05d: wtp(%02x:%02x:%02x:%02x:%02x:%02x) isn\'t existed.\r\n";
      bVar3 = *(byte *)(param_1 + 10);
      uVar8 = 0x59d;
      bVar4 = *(byte *)(param_1 + 0xb);
      bVar5 = *(byte *)(param_1 + 0xc);
      bVar6 = *(byte *)(param_1 + 0xd);
LAB_0045d008:
      printf(__format,"balance_db_wtp_delete",uVar8,(uint)bVar2,(uint)bVar1,(uint)bVar3,(uint)bVar4,
             (uint)bVar5,(uint)bVar6);
    }
LAB_0045cf14:
    uVar8 = 0;
    FUN_00407f30(balance_db_mutex);
  }
  else {
    if (((__s[1] == 0) || (balance_wtp_id == 0)) || (balance_wtp_hash == 0)) {
      if ((g_balance_error != 0) && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
        printf("[BALANCE_ERROR](%32s) %05d: inputs error.\r\n","balance_wtp_entry_delete",0x290);
      }
    }
    else {
      local_20[0] = *__s;
      FUN_00408570(balance_dis_sta_hash,balance_cnt_wtp_clear,local_20);
      iVar7 = balance_wtp_id;
      __s[4] = 0;
      FUN_004080f0(iVar7,*__s);
      iVar7 = FUN_00407f40(balance_wtp_hash,__s);
      if (iVar7 == 0) {
        if ((g_balance_debug != 0) && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
          printf("[BALANCE_DEBUG](%32s) %05d: delete wtp[%d](%02x:%02x:%02x:%02x:%02x:%02x) successed.\r\n"
                 ,"balance_wtp_entry_delete",0x2a8,*__s,(uint)*(byte *)(__s + 2),
                 (uint)*(byte *)((int)__s + 9),(uint)*(byte *)((int)__s + 10),
                 (uint)*(byte *)((int)__s + 0xb),(uint)*(byte *)(__s + 3),
                 (uint)*(byte *)((int)__s + 0xd));
        }
        memset(__s,0,0x14);
        if ((g_balance_debug != 0) && (iVar7 = is_target_debug_ap(balance_db_mutex), iVar7 != 0)) {
          bVar1 = *(byte *)(param_1 + 9);
          bVar2 = *(byte *)(param_1 + 8);
          __format = 
          "[BALANCE_DEBUG](%32s) %05d: delete wtp(%02x:%02x:%02x:%02x:%02x:%02x) successed.\r\n";
          bVar3 = *(byte *)(param_1 + 10);
          uVar8 = 0x5a9;
          bVar4 = *(byte *)(param_1 + 0xb);
          bVar5 = *(byte *)(param_1 + 0xc);
          bVar6 = *(byte *)(param_1 + 0xd);
          goto LAB_0045d008;
        }
        goto LAB_0045cf14;
      }
      if ((g_balance_error != 0) && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
        printf("[BALANCE_ERROR](%32s) %05d: remove wtp[%d](%02x:%02x:%02x:%02x:%02x:%02x) from wtp hash failed.\r\n"
               ,"balance_wtp_entry_delete",0x2a4,*__s,(uint)*(byte *)(__s + 2),
               (uint)*(byte *)((int)__s + 9),(uint)*(byte *)((int)__s + 10),
               (uint)*(byte *)((int)__s + 0xb),(uint)*(byte *)(__s + 3),
               (uint)*(byte *)((int)__s + 0xd));
      }
    }
    if ((g_balance_error != 0) && (iVar7 = is_target_debug_ap(balance_db_mutex), iVar7 != 0)) {
      printf("[BALANCE_ERROR](%32s) %05d: delete wtp(%02x:%02x:%02x:%02x:%02x:%02x) failed.\r\n",
             "balance_db_wtp_delete",0x5a5,(uint)*(byte *)(param_1 + 8),(uint)*(byte *)(param_1 + 9)
             ,(uint)*(byte *)(param_1 + 10),(uint)*(byte *)(param_1 + 0xb),
             (uint)*(byte *)(param_1 + 0xc),(uint)*(byte *)(param_1 + 0xd));
    }
    uVar8 = 0xffffffff;
    FUN_00407f30(balance_db_mutex);
  }
  return uVar8;
}

