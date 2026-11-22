// func dhcpdef_db_is_freed @ 0046f2bc size=504

undefined4 dhcpdef_db_is_freed(void)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  if (DAT_00767094 == 0) {
    if (DAT_00767098 == 0) {
      if ((DAT_007670a0 == 0) && (DAT_0076709c < 1)) {
        if ((DAT_007670a8 == 0) && (DAT_007670a4 < 1)) {
          if (l_dhcpdef_svrid_list == 0) {
            return 1;
          }
          if (g_dhcpdef_info == 0) {
            return 0;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0;
          }
          pcVar3 = "apbind server id list";
          uVar2 = 0x7d2;
        }
        else {
          if (g_dhcpdef_info == 0) {
            return 0;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0;
          }
          pcVar3 = "apbind list";
          uVar2 = 0x7d1;
        }
      }
      else {
        if (g_dhcpdef_info == 0) {
          return 0;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0;
        }
        pcVar3 = "server list";
        uVar2 = 2000;
      }
    }
    else {
      if (g_dhcpdef_info == 0) {
        return 0;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0;
      }
      pcVar3 = "id_allocator";
      uVar2 = 1999;
    }
  }
  else {
    if (g_dhcpdef_info == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    pcVar3 = "data_mutex";
    uVar2 = 0x7ce;
  }
  printf("[%s]<%s():%d> %s is NOT freed.\r\n","dhcp_defend","dhcpdef_db_is_freed",uVar2,pcVar3);
  return 0;
}

