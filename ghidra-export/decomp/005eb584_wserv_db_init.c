// func wserv_db_init @ 005eb584 size=1832

undefined4 wserv_db_init(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *__format;
  undefined4 uVar6;
  void *__s;
  uint uVar7;
  undefined1 *puVar8;
  
  if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> wserv_db_init() begin.\r\n","wserv_db_init",0x757);
  }
  if (l_wserv_data != 0) {
    if (g_wserv_error == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("<wserv>[error]%s(): %d  -> wserv data has been inited before!\r\n","wserv_db_init",
             0x75a);
      return 0;
    }
    return 0;
  }
  memset(&l_wserv_data,0,0x74);
  iVar1 = FUN_0051eb48("wservice_mngr","max_wservice",&l_wserv_profile);
  if (iVar1 == -1) {
    if ((g_wserv_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) {
      l_wserv_profile = 0x1000;
    }
    else {
      printf("<wserv>[error]%s(): %d  -> get profile[wservice_mngr->max_wservice] fail.\r\n",
             "wserv_db_init",0x763);
      l_wserv_profile = 0x1000;
    }
  }
  FUN_0051ad88(&g_wserv_list);
  g_wserv_hash = FUN_004080a0(_wserv_entry_hash_obj,_wserv_entry_hash_key_func,
                              _wserv_entry_hash_cmp_func,l_wserv_profile);
  if (g_wserv_hash == 0) {
    if ((g_wserv_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005eb990;
    __format = "<wserv>[error]%s(): %d  -> Create hash failed.\r\n";
    uVar6 = 0x76c;
  }
  else {
    DAT_007cbef0 = FUN_00407f00("wserv_mutex",1);
    if (DAT_007cbef0 == 0) {
      if ((g_wserv_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005eb990;
      __format = "<wserv>[error]%s(): %d  -> Create database mutex failed.\r\n";
      uVar6 = 0x772;
    }
    else {
      DAT_007cbef4 = FUN_004080e0(l_wserv_profile);
      if (DAT_007cbef4 == 0) {
        if ((g_wserv_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005eb990;
        __format = "<wserv>[error]%s(): %d  -> no memory!\r\n";
        uVar6 = 0x779;
      }
      else {
        uVar7 = 0;
        DAT_007cbefc = wserv_calloc(l_wserv_profile,0x21c);
        if (DAT_007cbefc == 0) {
          if ((g_wserv_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005eb990;
          __format = "<wserv>[error]%s(): %d  -> no memory!\r\n";
          uVar6 = 0x780;
        }
        else {
          for (; uVar7 < l_wserv_profile; uVar7 = uVar7 + 1) {
            __s = (void *)(DAT_007cbefc + uVar7 * 0x21c);
            memset(__s,0,0x21c);
            memset((void *)((int)__s + 0x10),0,0x205);
            *(undefined4 *)((int)__s + 0x90) = 0xffffffff;
          }
          iVar1 = wserv_sqlite_load_service();
          if (iVar1 == 0) {
            FUN_004083b0(DAT_007cbef4);
            iVar1 = apmngr_db_get_ap_max();
            iVar2 = apmngr_db_get_template_max();
            iVar3 = apmngr_db_get_sensor_max();
            iVar4 = rdmngr_profile_get_max_rd_per_ap();
            DAT_007cbf04 = wserv_calloc((iVar1 + iVar2 + iVar3) * iVar4,0xc);
            uVar7 = 0;
            if (DAT_007cbf04 != 0) {
              do {
                iVar2 = apmngr_db_get_ap_max();
                iVar3 = apmngr_db_get_template_max();
                iVar4 = apmngr_db_get_sensor_max();
                iVar5 = rdmngr_profile_get_max_rd_per_ap();
                iVar1 = DAT_007cbf04;
                if ((uint)((iVar2 + iVar3 + iVar4) * iVar5) <= uVar7) {
                  DAT_007cbf08 = wserv_calloc(0x1000,4);
                  if (DAT_007cbf08 == 0) {
                    if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                      __format = "<wserv>[error]%s(): %d  -> no memory!\r\n";
                      uVar6 = 0x7ab;
                      goto LAB_005eb984;
                    }
                  }
                  else {
                    iVar1 = wserv_sqlite_load_rd();
                    if (iVar1 == 0) {
                      DAT_007cbf0c = FUN_004080e0(0x20);
                      if (DAT_007cbf0c == 0) {
                        if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                          __format = "<wserv>[error]%s(): %d  -> no memory!\r\n";
                          uVar6 = 0x7b8;
                          goto LAB_005eb984;
                        }
                      }
                      else {
                        DAT_007cbf14 = wserv_calloc(0x20,0x20);
                        if (DAT_007cbf14 == 0) {
                          if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                            __format = "<wserv>[error]%s(): %d  -> no memory!\r\n";
                            uVar6 = 0x7bf;
                            goto LAB_005eb984;
                          }
                        }
                        else {
                          iVar1 = wserv_sqlite_load_ip();
                          if (iVar1 == 0) {
                            FUN_004083b0(DAT_007cbf0c);
                            FUN_0051ad88(&DAT_007cbf18);
                            FUN_0051ad88(&DAT_007cbf24);
                            FUN_0051ad88(&DAT_007cbf30);
                            FUN_0051ad88(&DAT_007cbf3c);
                            FUN_0051ad88(&DAT_007cbf48);
                            FUN_0051ad88(&DAT_007cbf54);
                            l_wserv_data = 1;
                            if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0))
                            {
                              printf("<wserv>[debug]%s(): %d  -> wserv_db_init() success.\r\n",
                                     "wserv_db_init",0x7d6);
                            }
                            if (g_wserv_debug == 0) {
                              return 0;
                            }
                            iVar1 = is_target_debug_ap();
                            if (iVar1 != 0) {
                              printf("<wserv>[debug]%s(): %d  -> l_wserv_mem_stat=%d.\r\n",
                                     "wserv_db_init",0x7d8,l_wserv_mem_stat);
                              return 0;
                            }
                            return 0;
                          }
                          if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                            __format = "<wserv>[error]%s(): %d  -> wserv_sqlite_load_ip() fail!\r\n"
                            ;
                            uVar6 = 0x7c6;
                            goto LAB_005eb984;
                          }
                        }
                      }
                    }
                    else if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                      __format = "<wserv>[error]%s(): %d  -> wserv_sqlite_load_rd() fail!\r\n";
                      uVar6 = 0x7b1;
                      goto LAB_005eb984;
                    }
                  }
                  break;
                }
                uVar6 = rdmngr_profile_get_max_wlan_per_rd();
                uVar6 = wserv_calloc(uVar6,6);
                *(undefined4 *)(iVar1 + uVar7 * 0xc + 8) = uVar6;
                puVar8 = (undefined1 *)(DAT_007cbf04 + uVar7 * 0xc);
                if (*(int *)(puVar8 + 8) == 0) {
                  if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                    __format = "<wserv>[error]%s(): %d  -> no memory!\r\n";
                    uVar6 = 0x79e;
                    goto LAB_005eb984;
                  }
                  break;
                }
                *puVar8 = 0;
                puVar8[1] = 0;
                iVar1 = _wserv_init_rd(puVar8 + 4);
                uVar7 = uVar7 + 1;
              } while (iVar1 == 0);
              goto LAB_005eb990;
            }
            if ((g_wserv_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
            goto LAB_005eb990;
            __format = "<wserv>[error]%s(): %d  -> no memory!\r\n";
            uVar6 = 0x795;
          }
          else {
            if ((g_wserv_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
            goto LAB_005eb990;
            __format = "<wserv>[error]%s(): %d  -> wserv_sqlite_load_service() fail!\r\n";
            uVar6 = 0x78d;
          }
        }
      }
    }
  }
LAB_005eb984:
  printf(__format,"wserv_db_init",uVar6);
LAB_005eb990:
  if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> wserv_db_init() fail.\r\n","wserv_db_init",0x7dd);
  }
  l_wserv_data = 1;
  wserv_db_uninit();
  return 0xffffffff;
}

