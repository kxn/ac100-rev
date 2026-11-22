// func apmngr_db_init @ 00541dec size=1484

undefined4 apmngr_db_init(void)

{
  uint uVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  
  uVar1 = time((time_t *)0x0);
  srand(uVar1);
  apmngr_real_ap_num_max = _apmngr_db_profile_get("ap_max");
  if ((((apmngr_real_ap_num_max < 0) ||
       (apmngr_template_num_max = _apmngr_db_profile_get("template_max"),
       apmngr_template_num_max < 0)) ||
      (apmngr_group_num_max = _apmngr_db_profile_get("group_max"), (int)apmngr_group_num_max < 0))
     || (apmngr_echo_timeout = _apmngr_db_profile_get("echo_timeout"), apmngr_echo_timeout < 0)) {
    if ((apmngr_err_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0))
    goto LAB_005421a4;
    __format = "[APMNGR_ERROR]%s()/%d Failed to get option in profile.\n";
    uVar3 = 0x1173;
  }
  else {
    apmngr_ap_num_max = apmngr_real_ap_num_max;
    apmngr_firm_sensor_num_max = _apmngr_db_profile_get("sensor_max");
    if (apmngr_firm_sensor_num_max < 1) {
      if ((apmngr_err_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0))
      goto LAB_005421a4;
      __format = "[APMNGR_ERROR]%s()/%d Failed to get option sensor_max in profile.\n";
      uVar3 = 0x1180;
    }
    else {
      apmngr_sensor_num_max = _apmngr_db_profile_get("discover_sensor_max");
      if ((apmngr_sensor_num_max < 1) || (apmngr_sensor_num_max < apmngr_firm_sensor_num_max)) {
        apmngr_sensor_num_max = apmngr_firm_sensor_num_max << 1;
      }
      g_apmngr_ap_id_allocator = FUN_004080e0(apmngr_ap_num_max);
      if (g_apmngr_ap_id_allocator == 0) {
        if ((apmngr_err_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0))
        goto LAB_005421a4;
        __format = "[APMNGR_ERROR]%s()/%d Init wtp id failed.\n";
        uVar3 = 0x1188;
      }
      else if ((apmngr_sensor_num_max < 1) ||
              (g_apmngr_sensor_id_allocator = FUN_004080e0(), g_apmngr_sensor_id_allocator != 0)) {
        g_apmngr_template_id_allocator = FUN_004080e0(apmngr_template_num_max);
        if (g_apmngr_template_id_allocator == 0) {
          if ((apmngr_err_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0))
          goto LAB_005421a4;
          __format = "[APMNGR_ERROR]%s()/%d Init wtp id failed.\n";
          uVar3 = 0x1199;
        }
        else {
          apmngr_db_mutex = FUN_00407f00("apmngr_db_mutex",1);
          if (apmngr_db_mutex == 0) {
            if ((apmngr_err_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0))
            goto LAB_005421a4;
            __format = "[APMNGR_ERROR]%s()/%d Create apmngr db mutex failed.\n";
            uVar3 = 0x11a1;
          }
          else {
            g_apmngr_entry_array =
                 (void *)FUN_00408450((apmngr_ap_num_max + apmngr_template_num_max +
                                      apmngr_sensor_num_max) * 0x2d8,0x11a6);
            if (g_apmngr_entry_array == (void *)0x0) {
              if ((apmngr_err_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0))
              goto LAB_005421a4;
              __format = "[APMNGR_ERROR]%s()/%d Malloc entry array failed.\n";
              uVar3 = 0x11a9;
            }
            else {
              memset(g_apmngr_entry_array,0,
                     (apmngr_ap_num_max + apmngr_template_num_max + apmngr_sensor_num_max) * 0x2d8);
              g_apmngr_group_array = (void *)FUN_00408450(apmngr_group_num_max * 0x84,0x11ae);
              if (g_apmngr_group_array == (void *)0x0) {
                if ((apmngr_err_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0))
                goto LAB_005421a4;
                __format = "[APMNGR_ERROR]%s()/%d Malloc group list head failed.\n";
                uVar3 = 0x11b1;
              }
              else {
                memset(g_apmngr_group_array,0,apmngr_group_num_max * 0x84);
                FUN_0051ad88(&g_apmngr_group_list);
                for (uVar1 = 0; uVar1 < apmngr_group_num_max; uVar1 = uVar1 + 1) {
                  FUN_0051ad88((int)g_apmngr_group_array + uVar1 * 0x84 + 0x78);
                }
                apmngr_standby_list_cond = FUN_00407d80("ap_standby_list_cond");
                if (apmngr_standby_list_cond == 0) {
                  if ((apmngr_err_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0))
                  goto LAB_005421a4;
                  __format = "[APMNGR_ERROR]%s()/%d Create apmngr_standby_list_cond failed.\n";
                  uVar3 = 0x11bf;
                }
                else {
                  apmngr_standby_list_mutex = FUN_00407f00("ap_standby_list_mutex",0);
                  if (apmngr_standby_list_mutex == 0) {
                    if ((apmngr_err_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0))
                    goto LAB_005421a4;
                    __format = "[APMNGR_ERROR]%s()/%d Create apmngr_standby_list_mutex failed.\n";
                    uVar3 = 0x11c6;
                  }
                  else {
                    g_apmngr_standby_hash =
                         FUN_004080a0(_apmngr_standby_list_hash_obj,
                                      _apmngr_standby_list_hash_key_func,
                                      _apmngr_standby_list_hash_cmp_func,
                                      apmngr_ap_num_max + apmngr_template_num_max +
                                      apmngr_sensor_num_max);
                    if (g_apmngr_standby_hash == 0) goto LAB_005421a4;
                    iVar2 = FUN_004084e0(&g_apmngr_standby_thread,"StandbyApListThread",
                                         standby_ap_list_thread,0);
                    if (iVar2 == 0) {
                      g_apmngr_ap_hash =
                           FUN_004080a0(_apmngr_ap_hash_obj,_apmngr_ap_hash_key_func,
                                        _apmngr_ap_hash_cmp_func,apmngr_ap_num_max);
                      if ((g_apmngr_ap_hash != 0) &&
                         (g_apmngr_template_hash =
                               FUN_004080a0(_apmngr_template_hash_obj,_apmngr_template_hash_key_func
                                            ,_apmngr_template_hash_cmp_func,apmngr_template_num_max)
                         , g_apmngr_template_hash != 0)) {
                        apmngr_db_sqlite_reg_recover_callback(0,apmngr_db_sqlite_group_restore);
                        apmngr_db_sqlite_reg_recover_callback(1,apmngr_db_sqlite_template_restore);
                        apmngr_db_sqlite_reg_recover_callback(2,apmngr_db_sqlite_ap_cfg_restore);
                        return 0;
                      }
                      goto LAB_005421a4;
                    }
                    if ((apmngr_err_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0))
                    goto LAB_005421a4;
                    __format = 
                    "[APMNGR_ERROR]%s()/%d Failed to create cloud mngt report msg thread\n";
                    uVar3 = 0x11d1;
                  }
                }
              }
            }
          }
        }
      }
      else {
        if ((apmngr_err_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0))
        goto LAB_005421a4;
        __format = "[APMNGR_ERROR]%s()/%d Init sensor id failed.\n";
        uVar3 = 0x1191;
      }
    }
  }
  printf(__format,"apmngr_db_init",uVar3);
LAB_005421a4:
  apmngr_db_fini();
  return 0xffffffff;
}

