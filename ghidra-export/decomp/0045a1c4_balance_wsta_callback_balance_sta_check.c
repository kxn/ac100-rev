// func balance_wsta_callback_balance_sta_check @ 0045a1c4 size=912

undefined4 balance_wsta_callback_balance_sta_check(int param_1)

{
  int iVar1;
  char cVar2;
  char *__format;
  void *__src;
  undefined4 uVar3;
  undefined4 uVar4;
  byte local_360;
  byte local_35f;
  byte local_35e;
  byte local_35d;
  byte local_35c;
  byte local_35b;
  char local_358 [104];
  undefined1 auStack_2f0 [20];
  uint local_2dc;
  byte local_2a8;
  byte local_2a7;
  byte local_2a6;
  byte local_2a5;
  byte local_2a4;
  byte local_2a3;
  undefined1 auStack_2a2 [542];
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  
  memset(auStack_2f0,0,0x2d8);
  local_358[0x14] = '\0';
  local_358[0x15] = '\0';
  local_358[0x16] = '\0';
  local_358[0x17] = '\0';
  local_358[0x18] = '\0';
  local_358[0x19] = '\0';
  local_358[0x1a] = '\0';
  local_358[0x1b] = '\0';
  local_358[0x1c] = '\0';
  local_358[0x1d] = '\0';
  local_358[0x1e] = '\0';
  local_358[0x1f] = '\0';
  local_358[0x20] = '\0';
  local_358[0x21] = '\0';
  local_358[0x22] = '\0';
  local_358[0x23] = '\0';
  local_358[0x24] = '\0';
  local_358[0x25] = '\0';
  local_358[0x26] = '\0';
  local_358[0x27] = '\0';
  local_358[0] = '\0';
  local_358[1] = '\0';
  local_358[2] = '\0';
  local_358[3] = '\0';
  local_358[4] = '\0';
  local_358[5] = '\0';
  local_358[6] = '\0';
  local_358[7] = '\0';
  local_358[8] = '\0';
  local_358[9] = '\0';
  local_358[10] = '\0';
  local_358[0xb] = '\0';
  local_358[0xc] = '\0';
  local_358[0xd] = '\0';
  local_358[0xe] = '\0';
  local_358[0xf] = '\0';
  local_358[0x10] = '\0';
  local_358[0x11] = '\0';
  local_358[0x12] = '\0';
  local_358[0x13] = '\0';
  if (param_1 == 0) {
    uVar4 = 0x25;
    if (g_balance_error == 0) {
      return 0x25;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0x25;
    }
    __format = "[BALANCE_ERROR](%32s) %05d: inputs error.\r\n";
    uVar3 = 0x313;
  }
  else {
    __src = (void *)(param_1 + 0xd);
    if (*(char *)(param_1 + 0xb) != '\x01') {
      __src = (void *)(param_1 + 0xc);
    }
    memcpy(&local_360,__src,6);
    iVar1 = apmngr_db_entry_get_by_id(*(undefined2 *)(param_1 + 6),auStack_2f0);
    if (iVar1 == -1) {
      uVar4 = 0x25;
      if (g_balance_error == 0) {
        return 0x25;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0x25;
      }
      __format = "[BALANCE_ERROR](%32s) %05d: get apentry by id failed.\r\n";
      uVar3 = 0x323;
    }
    else {
      if (((((local_2dc < 2) || (local_2dc == 3)) || (local_2dc == 2)) ||
          ((local_2dc == 4 || (local_2dc == 8)))) || (local_2dc == 6)) {
        if (*(char *)(param_1 + 0xb) == '\0') {
          if ((g_balance_warning != 0) && (iVar1 = is_target_debug_ap(&local_360), iVar1 != 0)) {
            printf("[BALANCE_WARNING](%32s) %05d: balance check station.\r\n",
                   "balance_wsta_callback_balance_sta_check",0x32e);
          }
          iVar1 = balance_allow_sta_conect_wtp(&local_360,&local_2a8);
        }
        else {
          if ((g_balance_warning != 0) && (iVar1 = is_target_debug_ap(param_1 + 0xc), iVar1 != 0)) {
            printf("[BALANCE_WARNING](%32s) %05d: balance check mlo station.\r\n",
                   "balance_wsta_callback_balance_sta_check",0x333);
          }
          iVar1 = balance_allow_mlo_sta_conect_wtp(param_1 + 0xc,&local_2a8);
        }
        if (iVar1 == 0) {
          return 0;
        }
        if (g_balance_debug == 0) {
          cVar2 = *(char *)(param_1 + 10);
        }
        else {
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            cVar2 = *(char *)(param_1 + 10);
          }
          else {
            printf("[BALANCE_DEBUG](%32s) %05d: balance rejects station.\r\n",
                   "balance_wsta_callback_balance_sta_check",0x338);
            cVar2 = *(char *)(param_1 + 10);
          }
        }
        if (cVar2 != '\0') {
          return 0x25;
        }
        snprintf(local_358 + 0x14,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)local_2a8,
                 (uint)local_2a7,(uint)local_2a6,(uint)local_2a5,(uint)local_2a4,(uint)local_2a3);
        snprintf(local_358,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)local_360,(uint)local_35f,
                 (uint)local_35e,(uint)local_35d,(uint)local_35c,(uint)local_35b);
        memset(local_358 + 0x28,0,0x40);
        FUN_00408190(local_84,local_80,local_7c,local_78,local_74,local_358 + 0x28,0x40,"---");
        loggerk_reg(0x5c,0x3d55,1,auStack_2a2,1,local_358 + 0x28,1,local_358 + 0x14,1,local_358,0);
        return 0x25;
      }
      uVar4 = 0;
      if (g_balance_debug == 0) {
        return 0;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0;
      }
      __format = "[BALANCE_DEBUG](%32s) %05d: Non-AP no need to check.\r\n";
      uVar3 = 0x328;
    }
  }
  printf(__format,"balance_wsta_callback_balance_sta_check",uVar3);
  return uVar4;
}

