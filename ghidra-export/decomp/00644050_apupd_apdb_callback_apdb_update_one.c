// func apupd_apdb_callback_apdb_update_one @ 00644050 size=972

undefined4 apupd_apdb_callback_apdb_update_one(int param_1,int param_2,int param_3)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 auStack_818 [2028];
  int local_2c;
  
  memset(auStack_818,0,0x800);
  if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: apdb update calbback - apupd block start\r\n",
           "apupd_apdb_callback_apdb_update_one",0x114f);
  }
  if (param_3 == 1) {
    if (param_2 == 0) {
      uVar3 = 0xffffffff;
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
      uVar2 = 0x1170;
      goto LAB_00644214;
    }
    iVar1 = apupd_db_model_get_by_id(*(undefined4 *)(param_2 + 0x10),auStack_818);
    if (iVar1 != 0) {
      if (local_2c - 1U < 2) {
        apupd_db_model_set_for_uilist(*(undefined4 *)(param_2 + 0x10),0);
        if (local_2c == 1) {
          if (apupd_mult_online_model_entry_num != 0) {
            apupd_mult_online_model_entry_num = apupd_mult_online_model_entry_num + -1;
          }
        }
        else if (apupd_mult_manual_model_entry_num != 0) {
          apupd_mult_manual_model_entry_num = apupd_mult_manual_model_entry_num + -1;
        }
      }
      iVar1 = apupd_db_model_delete_by_id(*(undefined4 *)(param_2 + 0x10));
      if (iVar1 == -1) {
        uVar3 = 0xffffffff;
        if (g_apupd_error == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        __format = "[APUPD_ERROR]%32s() %05d: delete model failed.\r\n";
        uVar2 = 0x118a;
        goto LAB_00644214;
      }
    }
  }
  else if (param_3 < 2) {
    if (param_3 != 0) {
LAB_006440bc:
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      printf("[APUPD_ERROR]%32s() %05d: type(%d) is error.\r\n",
             "apupd_apdb_callback_apdb_update_one",0x11aa,param_3);
      return 0xffffffff;
    }
    if (param_1 == 0) {
      uVar3 = 0xffffffff;
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
      uVar2 = 0x115f;
      goto LAB_00644214;
    }
    iVar1 = apupd_apdb_callback_apdb_add(param_1);
    if (iVar1 == -1) {
      uVar3 = 0xffffffff;
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APUPD_ERROR]%32s() %05d: add model failed.\r\n";
      uVar2 = 0x1165;
      goto LAB_00644214;
    }
  }
  else if (param_3 == 2) {
    if ((param_2 == 0) || (param_1 == 0)) {
      uVar3 = 0xffffffff;
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
      uVar2 = 0x1196;
      goto LAB_00644214;
    }
    uVar3 = 0xffffffff;
    iVar1 = apupd_turn_apdb_to_model(param_1,auStack_818);
    if (iVar1 == -1) {
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APUPD_ERROR]%32s() %05d: turn apdb to model failed.\r\n";
      uVar2 = 0x119c;
      goto LAB_00644214;
    }
    iVar1 = apupd_db_model_set(auStack_818,0);
    if (iVar1 == -1) {
      uVar3 = 0xffffffff;
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APUPD_ERROR]%32s() %05d: update model failed.\r\n";
      uVar2 = 0x11a2;
      goto LAB_00644214;
    }
  }
  else {
    if (param_3 != 3) goto LAB_006440bc;
    if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      uVar3 = 0;
      if (param_2 != 0) {
        uVar3 = *(undefined4 *)(param_2 + 0x10);
      }
      printf("[APUPD_DEBUG]%32s() %05d: model(%d) is no change.\r\n",
             "apupd_apdb_callback_apdb_update_one",0x1156,uVar3);
    }
  }
  uVar3 = 0;
  if (g_apupd_debug == 0) {
    return 0;
  }
  iVar1 = is_target_debug_ap();
  if (iVar1 == 0) {
    return 0;
  }
  __format = "[APUPD_DEBUG]%32s() %05d: apdb update calbback - apupd block end\r\n";
  uVar2 = 0x11b0;
LAB_00644214:
  printf(__format,"apupd_apdb_callback_apdb_update_one",uVar2);
  return uVar3;
}

