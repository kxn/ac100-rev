// func balance_db_init @ 0045bf34 size=1644

undefined4 balance_db_init(void)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  char *local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 *local_f0;
  undefined4 local_ec;
  undefined2 local_e8;
  undefined2 local_e6;
  undefined4 *local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  char *local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined *local_cc;
  undefined4 local_c8;
  undefined2 local_c4;
  undefined2 local_c2;
  undefined4 *local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  char *local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined2 local_a0;
  undefined2 local_9e;
  undefined4 *local_9c;
  undefined4 local_98;
  undefined4 local_94;
  char *local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined2 local_7c;
  undefined2 local_7a;
  undefined4 *local_78;
  undefined4 local_74;
  undefined4 local_70;
  char *local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined2 local_58;
  undefined2 local_56;
  undefined4 *local_54;
  undefined4 local_50;
  undefined4 local_4c;
  char *local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined2 local_34;
  undefined2 local_32;
  undefined4 *local_30;
  undefined4 local_2c;
  
  balance_db_mutex = FUN_00407f00("balance_mutex",1);
  if (balance_db_mutex == 0) {
    if ((g_balance_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_0045c1a0;
    pcVar3 = "[BALANCE_ERROR](%32s) %05d: Create database mutex failed.\r\n";
    uVar4 = 0x424;
  }
  else {
    piVar1 = (int *)FUN_00408450(0x20,0x42a);
    balance_com = piVar1;
    if (piVar1 == (int *)0x0) {
      if ((g_balance_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_0045c1a0;
      pcVar3 = "[BALANCE_ERROR](%32s) %05d: Create com data failed.\r\n";
      uVar4 = 0x42d;
    }
    else {
      memset(piVar1,0,0x20);
      iVar2 = apmngr_db_get_ap_max();
      *piVar1 = iVar2;
      iVar2 = wsta_profile_get_max_wstation();
      piVar1[1] = iVar2;
      local_104 = 0;
      local_108 = 0;
      piVar1 = balance_com + 2;
      local_10c = 0;
      local_110 = 0;
      local_114 = 0;
      local_118 = 0;
      if (piVar1 == (int *)0x0) {
        if ((g_balance_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          pcVar3 = "[BALANCE_ERROR](%32s) %05d: inputs error\r\n";
          uVar4 = 0x11a;
LAB_0045c474:
          printf(pcVar3,"balance_com_config_init",uVar4);
        }
      }
      else {
        local_e4 = &local_104;
        local_100 = 0;
        local_f8 = 0;
        local_e0 = 0;
        local_d4 = 0;
        local_bc = 0;
        local_d8 = "mode";
        local_fc = "enable";
        local_b0 = 0;
        local_f0 = &onoff_map;
        local_cc = &balance_mode_map;
        local_c0 = &local_108;
        local_f4 = 1;
        local_ec = 10;
        local_b8 = 2;
        local_e8 = 1;
        local_e6 = 4;
        local_dc = 1;
        local_b4 = "usr_threshold";
        local_9c = &local_10c;
        local_d0 = 1;
        local_c8 = 10;
        local_94 = 3;
        local_c4 = 1;
        local_c2 = 4;
        local_ac = 1;
        local_90 = "dif_threshold";
        local_a4 = 10;
        local_a0 = 1;
        local_9e = 4;
        local_a8 = 0;
        local_98 = 0;
        local_8c = 0;
        local_88 = 1;
        local_6c = "max_fail_num";
        local_54 = &local_114;
        local_7a = 4;
        local_78 = &local_110;
        local_4c = 5;
        local_70 = 4;
        local_56 = 4;
        local_32 = 4;
        local_48 = "rssi_threshold";
        local_7c = 1;
        local_64 = 1;
        local_58 = 1;
        local_40 = 1;
        local_34 = 1;
        local_30 = &local_118;
        local_84 = 0;
        local_80 = 10;
        local_74 = 0;
        local_68 = 0;
        local_60 = 0;
        local_5c = 10;
        local_50 = 0;
        local_44 = 0;
        local_3c = 0;
        local_38 = 10;
        local_2c = 0;
        iVar2 = FUN_00408120("apmng_balance","settings",&local_100,6);
        if (iVar2 == 0) {
          balance_config_state_set(piVar1,local_104);
          balance_config_mode_set(piVar1,local_108);
          balance_config_threshold_set(piVar1,local_10c);
          balance_config_dif_threshold_set(piVar1,local_110);
          balance_config_max_fail_num_set(piVar1,local_114);
          balance_config_rssi_threshold_set(piVar1,local_118);
          balance_wtp_hash =
               FUN_004080a0(balance_wtp_hash_obj,balance_wtp_hash_key,balance_wtp_hash_cmp,
                            *balance_com);
          if (balance_wtp_hash == 0) {
            if ((g_balance_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
            goto LAB_0045c1a0;
            pcVar3 = "[BALANCE_ERROR](%32s) %05d: Create wtp hash failed.\r\n";
            uVar4 = 0x447;
          }
          else {
            balance_dis_sta_hash =
                 FUN_004080a0(balance_dis_sta_hash_obj,balance_dis_sta_hash_key,
                              balance_dis_sta_hash_cmp,balance_com[1]);
            if (balance_dis_sta_hash == 0) {
              if ((g_balance_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
              goto LAB_0045c1a0;
              pcVar3 = "[BALANCE_ERROR](%32s) %05d: Create discovery station hash failed.\r\n";
              uVar4 = 0x452;
            }
            else {
              balance_wtp_array = (void *)FUN_00408450(*balance_com * 0x14,0x458);
              piVar1 = balance_com;
              if (balance_wtp_array == (void *)0x0) {
                if ((g_balance_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
                goto LAB_0045c1a0;
                pcVar3 = "[BALANCE_ERROR](%32s) %05d: Init wtp array failed.\r\n";
                uVar4 = 0x45b;
              }
              else {
                memset(balance_wtp_array,0,*balance_com * 0x14);
                balance_wtp_id = FUN_004080e0(*piVar1);
                if (balance_wtp_id == 0) {
                  if ((g_balance_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
                  goto LAB_0045c1a0;
                  pcVar3 = "[BALANCE_ERROR](%32s) %05d: Init wtp id failed.\r\n";
                  uVar4 = 0x464;
                }
                else {
                  iVar2 = FUN_004084e0(&balance_thread,"balance",balance_thread_callback,0);
                  if (iVar2 != -1) {
                    return 0;
                  }
                  if ((g_balance_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
                  goto LAB_0045c1a0;
                  pcVar3 = "[BALANCE_ERROR](%32s) %05d: create thread failed.\r\n";
                  uVar4 = 0x46a;
                }
              }
            }
          }
          goto LAB_0045c430;
        }
        if ((g_balance_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          pcVar3 = "[BALANCE_ERROR](%32s) %05d: uci req parse failed.\r\n";
          uVar4 = 300;
          goto LAB_0045c474;
        }
      }
      if ((g_balance_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_0045c1a0;
      pcVar3 = "[BALANCE_ERROR](%32s) %05d: Init com config data failed.\r\n";
      uVar4 = 0x43a;
    }
  }
LAB_0045c430:
  printf(pcVar3,"balance_db_init",uVar4);
LAB_0045c1a0:
  if (balance_db_mutex != 0) {
    FUN_00408360();
    balance_db_mutex = 0;
  }
  if (balance_wtp_hash != 0) {
    FUN_00408310();
    balance_wtp_hash = 0;
  }
  if (balance_dis_sta_hash != 0) {
    FUN_00408310();
    balance_dis_sta_hash = 0;
  }
  if (balance_com != (int *)0x0) {
    FUN_00407df0();
    balance_com = (int *)0x0;
  }
  if (balance_wtp_array != (void *)0x0) {
    FUN_00407df0();
    balance_wtp_array = (void *)0x0;
  }
  if (balance_wtp_id != 0) {
    FUN_00408160();
    balance_wtp_id = 0;
  }
  return 0xffffffff;
}

