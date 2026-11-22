// func mac_auth_db_init @ 00456eec size=1928

undefined4 mac_auth_db_init(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  char *__format;
  undefined4 *__s;
  int iVar5;
  uint uVar6;
  
  if (macauth_debug_switch != 0) {
    printf("[MACAUTH_DEBUG]%s()/%d mac_auth_db_init begins.\n","mac_auth_db_init",0x918);
  }
  if (g_mac_auth_data != 0) {
    return 0;
  }
  DAT_00766ff4 = FUN_00407f00("mac_auth_mac_mutex",1);
  if (DAT_00766ff4 == 0) {
    if (macauth_err_switch == 0) goto LAB_00457314;
    __format = "[MACAUTH_ERROR]%s()/%d Create mac data mutex failed.\n";
    uVar3 = 0x922;
  }
  else {
    DAT_00766ff8 = FUN_00407f00("mac_auth_group_mutex",1);
    if (DAT_00766ff8 == 0) {
      if (macauth_err_switch == 0) goto LAB_00457314;
      __format = "[MACAUTH_ERROR]%s()/%d Create group data mutex failed.\n";
      uVar3 = 0x929;
    }
    else {
      if (macauth_debug_switch != 0) {
        printf("[MACAUTH_DEBUG]%s()/%d mutex create OK.\n","mac_auth_db_init",0x92d);
      }
      iVar2 = FUN_0051eb48("mac_auth","max_mac",&g_mac_auth_profile);
      if (iVar2 == -1) {
        if (macauth_err_switch == 0) {
          g_mac_auth_profile = 10000;
        }
        else {
          printf("[MACAUTH_ERROR]%s()/%d get profile[mac_auth->max_mac] failed.\n",
                 "mac_auth_db_init",0x932);
          g_mac_auth_profile = 10000;
        }
      }
      iVar2 = FUN_0051eb48("mac_auth","max_group",&DAT_00766fe8);
      if (iVar2 == -1) {
        if (macauth_err_switch != 0) {
          printf("[MACAUTH_ERROR]%s()/%d get profile[mac_auth->max_group] failed.\n",
                 "mac_auth_db_init",0x939);
        }
        DAT_00766fe8 = 0x1000;
      }
      iVar2 = FUN_0051eb48("mac_auth","max_vlan",&DAT_00766fec);
      if (iVar2 == -1) {
        if (macauth_err_switch != 0) {
          printf("[MACAUTH_ERROR]%s()/%d get profile[mac_auth->max_vlan] failed.\n",
                 "mac_auth_db_init",0x940);
        }
        DAT_00766fec = 0x1000;
      }
      if (macauth_debug_switch != 0) {
        printf("[MACAUTH_DEBUG]%s()/%d profile read OK.\n","mac_auth_db_init",0x944);
      }
      DAT_00766ffc = FUN_004080e0(g_mac_auth_profile);
      if (DAT_00766ffc == 0) {
        if (macauth_err_switch == 0) goto LAB_00457314;
        __format = "[MACAUTH_ERROR]%s()/%d no memory.\n";
        uVar3 = 0x949;
      }
      else {
        DAT_00767000 = FUN_004080e0(DAT_00766fe8);
        if (DAT_00767000 == 0) {
          if (macauth_err_switch == 0) goto LAB_00457314;
          __format = "[MACAUTH_ERROR]%s()/%d no memory.\n";
          uVar3 = 0x94f;
        }
        else {
          DAT_00767004 = FUN_004080e0(DAT_00766fe8);
          if (DAT_00767004 == 0) {
            if (macauth_err_switch == 0) goto LAB_00457314;
            __format = "[MACAUTH_ERROR]%s()/%d no memory.\n";
            uVar3 = 0x955;
          }
          else {
            if (macauth_debug_switch != 0) {
              printf("[MACAUTH_DEBUG]%s()/%d ID allocator OK.\n","mac_auth_db_init",0x958);
            }
            iVar2 = g_mac_auth_profile * 0xa8;
            DAT_00767020 = FUN_00408450(iVar2,0x7d);
            if (DAT_00767020 == 0) {
              if (macauth_err_switch == 0) goto LAB_00457314;
              __format = "[MACAUTH_ERROR]%s()/%d no memory.\n";
              uVar3 = 0x95e;
            }
            else {
              g_mac_auth_mem_stat = iVar2 + g_mac_auth_mem_stat;
              iVar2 = DAT_00766fe8 * 0x188;
              DAT_00767024 = FUN_00408450(iVar2,0x7d);
              if (DAT_00767024 != 0) {
                g_mac_auth_mem_stat = iVar2 + g_mac_auth_mem_stat;
              }
              uVar6 = 0;
              if (DAT_00767024 == 0) {
                if (macauth_err_switch == 0) goto LAB_00457314;
                __format = "[MACAUTH_ERROR]%s()/%d no memory.\n";
                uVar3 = 0x966;
              }
              else {
                for (; uVar6 < g_mac_auth_profile; uVar6 = uVar6 + 1) {
                  __s = (undefined4 *)(DAT_00767020 + uVar6 * 0xa8);
                  memset(__s,0,0xa8);
                  *__s = 0xffffffff;
                }
                for (uVar6 = 0; iVar2 = uVar6 * 0x188, uVar6 < DAT_00766fe8; uVar6 = uVar6 + 1) {
                  pvVar4 = (void *)(DAT_00767024 + iVar2);
                  memset(pvVar4,0,0x188);
                  uVar1 = g_mac_auth_profile;
                  *(undefined4 *)((int)pvVar4 + 0xc) = 0xffffffff;
                  iVar5 = DAT_00767024 + iVar2;
                  uVar3 = FUN_00451e18(uVar1 + 0x1f >> 5);
                  *(undefined4 *)(iVar5 + 0x180) = uVar3;
                  if (*(int *)(DAT_00767024 + iVar2 + 0x180) == 0) {
                    if (macauth_err_switch == 0) goto LAB_00457314;
                    __format = "[MACAUTH_ERROR]%s()/%d no memory.\n";
                    uVar3 = 0x975;
                    goto LAB_004573f4;
                  }
                }
                g_mac_auth_bind_vlan = (void *)FUN_00451e18(DAT_00766fec + 1);
                if (g_mac_auth_bind_vlan == (void *)0x0) {
                  if (macauth_err_switch == 0) goto LAB_00457314;
                  __format = "[MACAUTH_ERROR]%s()/%d no memory.\n";
                  uVar3 = 0x97c;
                }
                else {
                  DAT_00767018 = g_mac_auth_bind_vlan;
                  memset(g_mac_auth_bind_vlan,-1,(DAT_00766fec + 1) * 4);
                  uVar3 = wserv_profile_get_max_wservice();
                  pvVar4 = (void *)FUN_00451e18(uVar3);
                  DAT_0076701c = pvVar4;
                  if (pvVar4 == (void *)0x0) {
                    if (macauth_err_switch == 0) goto LAB_00457314;
                    __format = "[MACAUTH_ERROR]%s()/%d no memory.\n";
                    uVar3 = 0x986;
                  }
                  else {
                    iVar2 = wserv_profile_get_max_wservice();
                    memset(pvVar4,-1,iVar2 << 2);
                    if (macauth_debug_switch != 0) {
                      printf("[MACAUTH_DEBUG]%s()/%d Memory alloc OK.\n","mac_auth_db_init",0x98a);
                    }
                    DAT_00767008 = FUN_004080a0(mac_auth_mac_hash_obj,mac_auth_mac_hash_key,
                                                mac_auth_mac_hash_cmp,g_mac_auth_profile);
                    if (DAT_00767008 == 0) {
                      if (macauth_err_switch == 0) goto LAB_00457314;
                      __format = "[MACAUTH_ERROR]%s()/%d Create station hash failed.\n";
                      uVar3 = 0x992;
                    }
                    else {
                      FUN_0051ad88(&DAT_0076700c);
                      iVar2 = mac_auth_sqlite_load_mac_service();
                      if (iVar2 == -1) {
                        if (macauth_err_switch == 0) goto LAB_00457314;
                        __format = 
                        "[MACAUTH_ERROR]%s()/%d mac_auth_sqlite_load_mac_service() failed.\n";
                        uVar3 = 0x998;
                      }
                      else {
                        FUN_004083b0(DAT_00766ffc);
                        iVar2 = mac_auth_sqlite_load_group_service();
                        if (iVar2 == -1) {
                          if (macauth_err_switch == 0) goto LAB_00457314;
                          __format = 
                          "[MACAUTH_ERROR]%s()/%d mac_auth_sqlite_load_group_servicec() failed.\n";
                          uVar3 = 0x9a0;
                        }
                        else {
                          FUN_004083b0(DAT_00767000);
                          iVar2 = mac_auth_sqlite_load_group_service_for_ssid();
                          if (iVar2 != -1) {
                            FUN_004083b0(DAT_00767004);
                            g_mac_auth_data = 1;
                            if (macauth_debug_switch != 0) {
                              printf("[MACAUTH_DEBUG]%s()/%d mac_auth_db_init OK.\n",
                                     "mac_auth_db_init",0x9ad);
                            }
                            if (macauth_debug_switch == 0) {
                              return 0;
                            }
                            printf("[MACAUTH_DEBUG]%s()/%d g_mac_auth_mem_stat is %d.\n",
                                   "mac_auth_db_init",0x9b0,g_mac_auth_mem_stat);
                            return 0;
                          }
                          if (macauth_err_switch == 0) goto LAB_00457314;
                          __format = 
                          "[MACAUTH_ERROR]%s()/%d mac_auth_sqlite_load_group_servicec_for_ssid() failed.\n"
                          ;
                          uVar3 = 0x9a7;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_004573f4:
  printf(__format,"mac_auth_db_init",uVar3);
LAB_00457314:
  g_mac_auth_data = 0;
  mac_auth_db_uninit();
  return 0xffffffff;
}

