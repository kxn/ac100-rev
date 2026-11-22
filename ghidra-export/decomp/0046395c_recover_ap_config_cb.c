// func recover_ap_config_cb @ 0046395c size=756

int recover_ap_config_cb(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *__format;
  undefined4 uVar4;
  int local_20 [3];
  
  local_20[0] = 0;
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    iVar1 = -1;
    if (g_dhcpdef_error == 0) {
      return -1;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return -1;
    }
    __format = "\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n";
    pcVar3 = "ap_entry && arg";
    uVar4 = 0x93e;
  }
  else {
    if (*(int *)(param_1 + 0x3c) == 0) {
      return 0;
    }
    iVar1 = dhcpdef_db_apbind_entry_is_used(*(undefined2 *)(param_1 + 0x10),local_20);
    if (iVar1 == 0) {
      if (local_20[0] == 0) {
        if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[%s]<%s():%d> ##########ap_id[%d] is firmed, but still NOT have apbind entry in DB!##########\r\n"
                 ,"dhcp_defend","recover_ap_config_cb",0x948,(uint)*(ushort *)(param_1 + 0x10));
        }
        iVar1 = dhcpdef_db_apbind_entry_add(*(undefined2 *)(param_1 + 0x10));
        if (iVar1 == 0) {
          if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            printf("[%s]<%s():%d> succeed to dhcpdef_db_apbind_entry_add(ap_id[%d])\r\n",
                   "dhcp_defend","recover_ap_config_cb",0x94f,(uint)*(ushort *)(param_1 + 0x10));
          }
          iVar1 = dhcpdef_db_apbind_entry_firm_insert(*(undefined2 *)(param_1 + 0x10));
          if (iVar1 == 0) {
            *param_2 = *param_2 + 1;
            if (g_dhcpdef_info == 0) {
              return 0;
            }
            iVar2 = is_target_debug_ap();
            if (iVar2 == 0) {
              return 0;
            }
            pcVar3 = (char *)(uint)*(ushort *)(param_1 + 0x10);
            __format = "[%s]<%s():%d> ##########succeed to recover ap_id[%d]!##########\r\n";
            uVar4 = 0x958;
          }
          else {
            if (g_dhcpdef_error == 0) {
              return iVar1;
            }
            iVar2 = is_target_debug_ap();
            if (iVar2 == 0) {
              return iVar1;
            }
            pcVar3 = (char *)(uint)*(ushort *)(param_1 + 0x10);
            __format = 
            "\x1b[31;49m[%s]<%s():%d> fail to dhcpdef_db_apbind_entry_firm_insert(ap_id[%d])\x1b[0m\r\n"
            ;
            uVar4 = 0x954;
          }
        }
        else {
          if (g_dhcpdef_error == 0) {
            return iVar1;
          }
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            return iVar1;
          }
          pcVar3 = (char *)(uint)*(ushort *)(param_1 + 0x10);
          __format = 
          "\x1b[31;49m[%s]<%s():%d> fail to dhcpdef_db_apbind_entry_add(ap_id[%d])\x1b[0m\r\n";
          uVar4 = 0x94c;
        }
      }
      else {
        iVar1 = 0;
        if (g_dhcpdef_info == 0) {
          return 0;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0;
        }
        pcVar3 = (char *)(uint)*(ushort *)(param_1 + 0x10);
        __format = "[%s]<%s():%d> ##########ap_id[%d] is used, NO need to recover!##########\r\n";
        uVar4 = 0x95c;
      }
    }
    else {
      iVar1 = -1;
      if (g_dhcpdef_error == 0) {
        return -1;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return -1;
      }
      pcVar3 = "ret == DHCPDEF_OK";
      __format = "\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n";
      uVar4 = 0x944;
    }
  }
  printf(__format,"dhcp_defend","recover_ap_config_cb",uVar4,pcVar3);
  return iVar1;
}

