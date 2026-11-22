// func balance_wtp_entry_update @ 0045b824 size=1372

undefined4 balance_wtp_entry_update(int param_1)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  undefined4 uVar11;
  uint uVar12;
  int *__s;
  
  if ((param_1 == 0) || (balance_wtp_hash == 0)) {
    if (g_balance_error == 0) {
      return 0xffffffff;
    }
    iVar8 = is_target_debug_ap();
    if (iVar8 == 0) {
      return 0xffffffff;
    }
    pcVar10 = "[BALANCE_ERROR](%32s) %05d: inputs error.\r\n";
    uVar11 = 0x1b0;
    goto LAB_0045b954;
  }
  puVar7 = (uint *)FUN_00407fa0(balance_wtp_hash,(void *)(param_1 + 8));
  if (puVar7 != (uint *)0x0) {
    puVar7[4] = 0;
    if ((g_balance_debug == 0) || (iVar8 = is_target_debug_ap(), iVar8 == 0)) goto LAB_0045b88c;
    bVar2 = *(byte *)(puVar7 + 2);
    uVar12 = *puVar7;
    pcVar10 = 
    "[BALANCE_DEBUG](%32s) %05d: wtp[%d](%02x:%02x:%02x:%02x:%02x:%02x) is existed, delete station list successed.\r\n"
    ;
    bVar3 = *(byte *)((int)puVar7 + 9);
    uVar11 = 0x1b9;
    bVar4 = *(byte *)((int)puVar7 + 10);
    bVar5 = *(byte *)((int)puVar7 + 0xb);
    bVar6 = *(byte *)(puVar7 + 3);
LAB_0045b9bc:
    printf(pcVar10,"balance_wtp_entry_update",uVar11,uVar12,(uint)bVar2,(uint)bVar3,(uint)bVar4,
           (uint)bVar5,(uint)bVar6);
LAB_0045b88c:
    if (g_balance_debug == 0) {
      return 0;
    }
    iVar8 = is_target_debug_ap();
    if (iVar8 == 0) {
      return 0;
    }
    printf("[BALANCE_DEBUG](%32s) %05d: update wtp(%02x:%02x:%02x:%02x:%02x:%02x) successed.\r\n",
           "balance_wtp_entry_update",0x1c7,(uint)*(byte *)(param_1 + 8),
           (uint)*(byte *)(param_1 + 9),(uint)*(byte *)(param_1 + 10),(uint)*(byte *)(param_1 + 0xb)
           ,(uint)*(byte *)(param_1 + 0xc),(uint)*(byte *)(param_1 + 0xd));
    return 0;
  }
  if (((balance_wtp_hash == 0) || (balance_wtp_array == 0)) || (balance_wtp_id == 0)) {
    if ((g_balance_error != 0) && (iVar8 = is_target_debug_ap(), iVar8 != 0)) {
      pcVar10 = "[BALANCE_ERROR](%32s) %05d: inputs error\r\n";
      uVar11 = 0x17c;
LAB_0045ba90:
      printf(pcVar10,"balance_wtp_entry_add",uVar11);
    }
  }
  else {
    iVar8 = FUN_004085b0();
    if (iVar8 == -1) {
      if ((g_balance_error != 0) && (iVar8 = is_target_debug_ap(), iVar8 != 0)) {
        pcVar10 = "[BALANCE_ERROR](%32s) %05d: alloc wtp id failed.\r\n";
        uVar11 = 0x183;
        goto LAB_0045ba90;
      }
    }
    else {
      __s = (int *)(balance_wtp_array + iVar8 * 0x14);
      if ((__s == (int *)0x0) || (__s[1] == 1)) {
        if ((g_balance_error != 0) && (iVar9 = is_target_debug_ap(), iVar9 != 0)) {
          printf("[BALANCE_ERROR](%32s) %05d: input error.\r\n","balance_wtp_entry_init",0x15a);
        }
        if ((g_balance_error != 0) && (iVar9 = is_target_debug_ap(balance_wtp_id), iVar9 != 0)) {
          printf("[BALANCE_ERROR](%32s) %05d: init wtp(%02x:%02x:%02x:%02x:%02x:%02x) failed.\r\n",
                 "balance_wtp_entry_add",0x18b,(uint)*(byte *)(param_1 + 8),
                 (uint)*(byte *)(param_1 + 9),(uint)*(byte *)(param_1 + 10),
                 (uint)*(byte *)(param_1 + 0xb),(uint)*(byte *)(param_1 + 0xc),
                 (uint)*(byte *)(param_1 + 0xd));
        }
        FUN_004080f0(balance_wtp_id,iVar8);
      }
      else {
        *__s = iVar8;
        __s[1] = 1;
        memcpy(__s + 2,(void *)(param_1 + 8),6);
        bVar1 = g_balance_debug != 0;
        __s[4] = 0;
        if ((bVar1) && (iVar9 = is_target_debug_ap(), iVar9 != 0)) {
          printf("[BALANCE_DEBUG](%32s) %05d: init wtp[%d](%02x:%02x:%02x:%02x:%02x:%02x) successed.\r\n"
                 ,"balance_wtp_entry_init",0x164,*__s,(uint)*(byte *)(__s + 2),
                 (uint)*(byte *)((int)__s + 9),(uint)*(byte *)((int)__s + 10),
                 (uint)*(byte *)((int)__s + 0xb),(uint)*(byte *)(__s + 3),
                 (uint)*(byte *)((int)__s + 0xd));
        }
        iVar9 = FUN_00408380(balance_wtp_hash,__s);
        if (iVar9 == 0) {
          if ((g_balance_debug != 0) && (iVar8 = is_target_debug_ap(), iVar8 != 0)) {
            printf("[BALANCE_DEBUG](%32s) %05d: add wtp[%d](%02x:%02x:%02x:%02x:%02x:%02x) successed.\r\n"
                   ,"balance_wtp_entry_add",0x199,*__s,(uint)*(byte *)(__s + 2),
                   (uint)*(byte *)((int)__s + 9),(uint)*(byte *)((int)__s + 10),
                   (uint)*(byte *)((int)__s + 0xb),(uint)*(byte *)(__s + 3),
                   (uint)*(byte *)((int)__s + 0xd));
          }
          if ((g_balance_debug == 0) || (iVar8 = is_target_debug_ap(), iVar8 == 0))
          goto LAB_0045b88c;
          bVar2 = *(byte *)(param_1 + 9);
          uVar12 = (uint)*(byte *)(param_1 + 8);
          pcVar10 = 
          "[BALANCE_DEBUG](%32s) %05d: wtp(%02x:%02x:%02x:%02x:%02x:%02x) isn\'t existed, add it successed.\r\n"
          ;
          bVar3 = *(byte *)(param_1 + 10);
          uVar11 = 0x1c4;
          bVar4 = *(byte *)(param_1 + 0xb);
          bVar5 = *(byte *)(param_1 + 0xc);
          bVar6 = *(byte *)(param_1 + 0xd);
          goto LAB_0045b9bc;
        }
        if ((g_balance_error != 0) && (iVar9 = is_target_debug_ap(balance_wtp_id), iVar9 != 0)) {
          printf("[BALANCE_ERROR](%32s) %05d: insert wtp[%d](%02x:%02x:%02x:%02x:%02x:%02x) to hash failed.\r\n"
                 ,"balance_wtp_entry_add",0x193,*__s,(uint)*(byte *)(__s + 2),
                 (uint)*(byte *)((int)__s + 9),(uint)*(byte *)((int)__s + 10),
                 (uint)*(byte *)((int)__s + 0xb),(uint)*(byte *)(__s + 3),
                 (uint)*(byte *)((int)__s + 0xd));
        }
        FUN_004080f0(balance_wtp_id,iVar8);
        memset(__s,0,0x14);
      }
    }
  }
  if (g_balance_debug == 0) {
    return 0xffffffff;
  }
  iVar8 = is_target_debug_ap();
  if (iVar8 == 0) {
    return 0xffffffff;
  }
  pcVar10 = "[BALANCE_DEBUG](%32s) %05d: add wtp failed.\r\n";
  uVar11 = 0x1c1;
LAB_0045b954:
  printf(pcVar10,"balance_wtp_entry_update",uVar11);
  return 0xffffffff;
}

