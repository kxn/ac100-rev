// func balance_dis_sta_entry_add @ 0045a898 size=608

/* WARNING: Removing unreachable block (ram,0x0045a8dc) */

byte * balance_dis_sta_entry_add(void *param_1)

{
  int iVar1;
  byte *__s;
  char *__format;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(balance_com + 4);
  if ((param_1 == (void *)0x0) || (balance_dis_sta_hash == 0)) {
    if (g_balance_error != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return (byte *)0x0;
      }
      __format = "[BALANCE_ERROR](%32s) %05d: inputs error.\r\n";
      uVar2 = 0x2c3;
      goto LAB_0045a964;
    }
  }
  else {
    iVar1 = FUN_00407ed0();
    if (iVar1 < (int)(uVar3 / 0x14 + uVar3)) {
      __s = (byte *)FUN_00408450(0x1c,0x2cc);
      if (__s == (byte *)0x0) {
        if (g_balance_error == 0) {
          return (byte *)0x0;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return (byte *)0x0;
        }
        __format = "[BALANCE_ERROR](%32s) %05d: malloc discovery-station failed.\r\n";
        uVar2 = 0x2cf;
        goto LAB_0045a964;
      }
      memset(__s,0,0x1c);
      memcpy(__s,param_1,6);
      __s[8] = 0;
      __s[9] = 0;
      __s[10] = 0;
      __s[0xb] = 0;
      __s[0xc] = 0;
      __s[0xd] = 0;
      __s[0xe] = 0;
      __s[0xf] = 0;
      FUN_0051ad88(__s + 0x10);
      iVar1 = FUN_00408380(balance_dis_sta_hash,__s);
      if (iVar1 == 0) {
        if (g_balance_debug == 0) {
          return __s;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return __s;
        }
        printf("[BALANCE_DEBUG](%32s) %05d: add discovery-station(%02x:%02x:%02x:%02x:%02x:%02x) successed\r\n"
               ,"balance_dis_sta_entry_add",0x2e2,(uint)*__s,(uint)__s[1],(uint)__s[2],(uint)__s[3],
               (uint)__s[4],(uint)__s[5]);
        return __s;
      }
      if ((g_balance_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[BALANCE_ERROR](%32s) %05d: insert discovery-station(%02x:%02x:%02x:%02x:%02x:%02x) to hash failed.\r\n"
               ,"balance_dis_sta_entry_add",0x2dd,(uint)*__s,(uint)__s[1],(uint)__s[2],(uint)__s[3],
               (uint)__s[4],(uint)__s[5]);
      }
      FUN_00407df0(__s);
    }
    else {
      if (g_balance_warning == 0) {
        return (byte *)0x0;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 != 0) {
        __format = "[BALANCE_WARNING](%32s) %05d: balance_dis_sta_hash is full.\r\n";
        uVar2 = 0x2c8;
LAB_0045a964:
        printf(__format,"balance_dis_sta_entry_add",uVar2);
        return (byte *)0x0;
      }
    }
  }
  return (byte *)0x0;
}

