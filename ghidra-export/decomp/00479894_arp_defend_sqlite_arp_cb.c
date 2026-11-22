// func arp_defend_sqlite_arp_cb @ 00479894 size=816

undefined4
arp_defend_sqlite_arp_cb(undefined4 param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  char *__s1;
  char *pcVar3;
  int iVar4;
  uint local_160;
  undefined1 auStack_15c [20];
  undefined1 auStack_148 [6];
  char acStack_142 [258];
  undefined1 auStack_40 [24];
  
  memset(&local_160,0,0x120);
  if ((arp_defend_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
    printf("[ARP_DEFEND_DEBUG]%s()/%d column is %d\n","arp_defend_sqlite_arp_cb",0x212,param_2);
  }
  for (iVar4 = 0; iVar4 < param_2; iVar4 = iVar4 + 1) {
    pcVar3 = (char *)*param_3;
    if ((pcVar3 == (char *)0x0) || (__s1 = (char *)*param_4, __s1 == (char *)0x0)) {
      if (arp_defend_err_switch == 0) goto LAB_004799bc;
      iVar4 = is_target_debug_ap();
      if (iVar4 == 0) {
        return 1;
      }
      pcVar3 = "[ARP_DEFEND_ERROR]%s()/%d column value or name is null.\n";
      uVar2 = 0x218;
      goto LAB_00479a98;
    }
    iVar1 = strcmp(__s1,"arp_id");
    if (iVar1 == 0) {
      local_160 = atoi(pcVar3);
    }
    else {
      iVar1 = strcmp(__s1,"ip");
      if (iVar1 == 0) {
        arp_defend_str2ip(auStack_40,pcVar3);
        memcpy(auStack_15c,auStack_40,0x14);
      }
      else {
        iVar1 = strcmp(__s1,"mac");
        if (iVar1 == 0) {
          arp_defend_str2mac(pcVar3,auStack_148);
        }
        else {
          iVar1 = strcmp(__s1,"description");
          if (iVar1 == 0) {
            strncpy(acStack_142,pcVar3,0xff);
          }
          else {
            iVar1 = strcmp(__s1,"key");
            if (iVar1 != 0) {
              if (arp_defend_err_switch != 0) {
                iVar4 = is_target_debug_ap();
                if (iVar4 == 0) {
                  return 1;
                }
                printf("[ARP_DEFEND_ERROR]%s()/%d Invalid column_name[%s]\n",
                       "arp_defend_sqlite_arp_cb",0x232,*param_4);
                return 1;
              }
              goto LAB_004799bc;
            }
          }
        }
      }
    }
    param_4 = param_4 + 1;
    param_3 = param_3 + 1;
  }
  if (((int)local_160 < 0) || (g_arp_defend_profile <= local_160)) {
    if (arp_defend_err_switch != 0) {
      iVar4 = is_target_debug_ap();
      if (iVar4 != 0) {
        printf("[ARP_DEFEND_ERROR]%s()/%d Invalid arp entry Id(%d).\n",
               "arp_defend_db_load_arp_service",0x1f2,local_160);
      }
      if (arp_defend_err_switch != 0) {
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          return 1;
        }
        pcVar3 = "[ARP_DEFEND_ERROR]%s()/%d arp_defend_db_load_arp_service() failed.\n";
        uVar2 = 0x239;
LAB_00479a98:
        printf(pcVar3,"arp_defend_sqlite_arp_cb",uVar2);
        return 1;
      }
    }
LAB_004799bc:
    uVar2 = 1;
  }
  else {
    FUN_004082d0(DAT_007670fc,0xffffffff);
    memcpy((void *)(DAT_0076710c + local_160 * 0x120),&local_160,0x120);
    FUN_00408440(DAT_00767100,local_160);
    DAT_00767110 = DAT_00767110 + 1;
    uVar2 = 0;
    FUN_00407f30(DAT_007670fc);
  }
  return uVar2;
}

