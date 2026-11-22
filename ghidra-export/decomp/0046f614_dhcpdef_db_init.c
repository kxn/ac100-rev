// func dhcpdef_db_init @ 0046f614 size=1740

undefined4 dhcpdef_db_init(void)

{
  int iVar1;
  uint uVar2;
  char *__format;
  undefined4 uVar3;
  uint uVar4;
  
  if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","dhcpdef_db_init",0x7dd,"dhcpdef_db_init");
  }
  if (l_dhcpdef_data != 0) {
    if (g_dhcpdef_warn == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("\x1b[33;49m[%s]<%s():%d> dhcpdef data has been inited!\x1b[0m\r\n","dhcp_defend",
             "dhcpdef_db_init",0x7e1);
      return 0;
    }
    return 0;
  }
  iVar1 = dhcpdef_db_is_freed();
  if (iVar1 == 0) {
    if ((g_dhcpdef_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0046f9a0;
    __format = "\x1b[31;49m[%s]<%s():%d> Check whether there is MEMORY LEAK!\x1b[0m\r\n";
    uVar3 = 0x7e7;
  }
  else {
    l_dhcpdef_data = 0;
    DAT_00767094 = 0;
    DAT_00767098 = 0;
    DAT_0076709c = 0;
    DAT_007670a0 = 0;
    DAT_007670a4 = 0;
    DAT_007670a8 = 0;
    iVar1 = FUN_0051eb48("ac_dhcp_defend","max_server",&l_dhcpdef_profile);
    if (iVar1 == -1) {
      if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("\x1b[31;49m[%s]<%s():%d> Failed to get profile \'%s.%s\'!\x1b[0m\r\n","dhcp_defend",
               "dhcpdef_db_init",0x7f0,"ac_dhcp_defend","max_server");
      }
      l_dhcpdef_profile = apmngr_db_get_ap_max();
    }
    iVar1 = FUN_0051eb48("ac_dhcp_defend","max_svr_per_ap",&DAT_0076708c);
    if (iVar1 == -1) {
      if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("\x1b[31;49m[%s]<%s():%d> Failed to get profile \'%s.%s\'!\x1b[0m\r\n","dhcp_defend",
               "dhcpdef_db_init",0x7f7,"ac_dhcp_defend","max_server");
      }
      DAT_0076708c = 0x18;
    }
    DAT_00767094 = FUN_00407f00("dhcpdef_data_mutex",1);
    if (DAT_00767094 == 0) {
      if ((g_dhcpdef_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0046f9a0;
      __format = "\x1b[31;49m[%s]<%s():%d> Failed to create database mutex!\x1b[0m\r\n";
      uVar3 = 0x800;
    }
    else {
      DAT_00767098 = FUN_004080e0(l_dhcpdef_profile);
      if (DAT_00767098 == 0) {
        if ((g_dhcpdef_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0046f9a0;
        __format = "\x1b[31;49m[%s]<%s():%d> Failed! Not enough memory for ID allocator!\x1b[0m\r\n"
        ;
        uVar3 = 0x807;
      }
      else {
        DAT_007670a0 = FUN_004082a0(l_dhcpdef_profile,0xac,0x80d);
        uVar4 = 0;
        if (DAT_007670a0 != 0) {
          do {
            if (l_dhcpdef_profile <= uVar4) {
              iVar1 = dhcpdef_sqlite_svr_entry_load();
              if (iVar1 == 0) {
                FUN_004083b0(DAT_00767098);
                uVar3 = dhcpdef_db_get_max_ap();
                DAT_007670a8 = FUN_004082a0(uVar3,0x11,0x827);
                if (DAT_007670a8 == 0) {
                  if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                    __format = "\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n";
                    uVar3 = 0x82a;
                    goto LAB_0046f990;
                  }
                }
                else {
                  uVar3 = dhcpdef_db_get_max_ap();
                  uVar4 = 0;
                  l_dhcpdef_svrid_list = FUN_004082a0(uVar3,DAT_0076708c << 2,0x832);
                  if (l_dhcpdef_svrid_list != 0) goto LAB_0046f868;
                  if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                    __format = "\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n";
                    uVar3 = 0x835;
                    goto LAB_0046f990;
                  }
                }
              }
              else if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                __format = 
                "\x1b[31;49m[%s]<%s():%d> Failed to call dhcpdef_sqlite_svr_entry_load()!\x1b[0m\r\n"
                ;
                uVar3 = 0x81d;
                goto LAB_0046f990;
              }
              break;
            }
            iVar1 = _dhcpdef_db_svr_entry_init(DAT_007670a0 + uVar4 * 0xac);
            uVar4 = uVar4 + 1;
          } while (iVar1 == 0);
          goto LAB_0046f9a0;
        }
        if ((g_dhcpdef_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0046f9a0;
        __format = "\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n";
        uVar3 = 0x810;
      }
    }
  }
LAB_0046f990:
  printf(__format,"dhcp_defend","dhcpdef_db_init",uVar3);
LAB_0046f9a0:
  if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("\x1b[31;49m[%s]<%s():%d> dhcpdef_db_init() fail!\x1b[0m\r\n","dhcp_defend",
           "dhcpdef_db_init",0x85a);
  }
  if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("\x1b[31;49m[%s]<%s():%d> going to free all memories of %s module...\x1b[0m\r\n",
           "dhcp_defend","dhcpdef_db_init",0x85b,"dhcp_defend");
  }
  dhcpdef_db_uninit();
  return 0xffffffff;
LAB_0046f868:
  for (; uVar2 = dhcpdef_db_get_max_ap(), uVar4 < uVar2; uVar4 = uVar4 + 1) {
    *(uint *)(DAT_007670a8 + uVar4 * 0x11 + 0xd) = l_dhcpdef_svrid_list + DAT_0076708c * 4 * uVar4;
  }
  uVar4 = 0;
  do {
    uVar2 = dhcpdef_db_get_max_ap();
    if (uVar2 <= uVar4) {
      iVar1 = dhcpdef_sqlite_apbind_entry_load();
      if (iVar1 == 0) {
        l_dhcpdef_data = 1;
        if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[%s]<%s():%d> dhcpdef_db_init() success.\r\n","dhcp_defend","dhcpdef_db_init",
                 0x852);
        }
        if (g_dhcpdef_info == 0) {
          return 0;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 != 0) {
          printf("[%s]<%s():%d> l_dhcpdef_memstat = %d.\r\n","dhcp_defend","dhcpdef_db_init",0x854,0
                );
          return 0;
        }
        return 0;
      }
      if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        __format = "\x1b[31;49m[%s]<%s():%d> dhcpdef_sqlite_apbind_entry_load() fail!\x1b[0m\r\n";
        uVar3 = 0x84c;
        goto LAB_0046f990;
      }
      break;
    }
    iVar1 = _dhcpdef_db_apbind_entry_init(DAT_007670a8 + uVar4 * 0x11);
    uVar4 = uVar4 + 1;
  } while (iVar1 == 0);
  goto LAB_0046f9a0;
}

