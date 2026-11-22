// func apmngr_db_ap_capid_update @ 0053e0fc size=1328

undefined4 apmngr_db_ap_capid_update(ushort param_1,ushort param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  short sVar7;
  short sVar8;
  undefined4 local_308;
  short local_304;
  undefined1 auStack_300 [8];
  undefined1 auStack_2f8 [728];
  
  uVar6 = (uint)param_2;
  uVar4 = (uint)param_1;
  local_308 = 0;
  local_304 = 0;
  memset(auStack_300,0,0x2e0);
  if ((apmngr_ap_num_max + apmngr_template_num_max <= (int)uVar4) &&
     ((uVar4 < 50000 || (apmngr_sensor_num_max + 50000 <= (int)uVar4)))) {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    printf("[APMNGR_ERROR]%s()/%d Invalid ap id[%d].\n","apmngr_db_ap_capid_update",0xaa7,uVar4);
    return 0xffffffff;
  }
  FUN_004082d0(apmngr_db_mutex,0xffffffff);
  iVar2 = g_apmngr_entry_array;
  uVar3 = uVar4;
  if (49999 < uVar4) {
    uVar3 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
  }
  if (*(int *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x1c) == 1) {
    uVar3 = uVar4;
    if (49999 < uVar4) {
      uVar3 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    if (*(int *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x14) != 4) {
      uVar3 = uVar4;
      if (49999 < uVar4) {
        uVar3 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      if (*(int *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x14) != 8) {
        uVar3 = uVar4;
        if (49999 < uVar4) {
          uVar3 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        if (*(int *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x14) != 6) {
          uVar3 = uVar4;
          if (49999 < uVar4) {
            uVar3 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
          }
          if (*(int *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x14) != 5) goto LAB_0053e22c;
        }
      }
    }
    if (uVar6 != 0xffff) {
      uVar3 = uVar6;
      if (49999 < uVar6) {
        uVar3 = (uVar6 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      if (*(int *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x1c) != 1) goto LAB_0053e22c;
      uVar3 = uVar6;
      if (49999 < uVar6) {
        uVar3 = (uVar6 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      if (*(int *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x14) != 1) {
        uVar3 = uVar6;
        if (49999 < uVar6) {
          uVar3 = (uVar6 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        if (*(int *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x14) != 3) {
          uVar3 = uVar6;
          if (49999 < uVar6) {
            uVar3 = (uVar6 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
          }
          if (*(int *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x14) != 2) goto LAB_0053e22c;
        }
      }
    }
    uVar3 = uVar4;
    if (49999 < uVar4) {
      uVar3 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    if (*(ushort *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x18) != uVar6) {
      uVar3 = uVar4;
      if (49999 < uVar4) {
        uVar3 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      *(ushort *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x18) = param_2;
      uVar3 = uVar4;
      if (49999 < uVar4) {
        uVar3 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      sVar8 = *(short *)(iVar2 + uVar3 * 0x2d8 + 0x12);
      if (uVar6 != 0xffff) {
        uVar3 = uVar4;
        if (49999 < uVar4) {
          uVar3 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        if (49999 < uVar6) {
          uVar6 = (uVar6 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        *(undefined2 *)(iVar2 + uVar3 * 0x2d8 + 0x12) =
             *(undefined2 *)(iVar2 + uVar6 * 0x2d8 + 0x12);
      }
      uVar6 = uVar4;
      if (49999 < uVar4) {
        uVar6 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      sVar7 = *(short *)(iVar2 + uVar6 * 0x2d8 + 0x12);
      if (49999 < uVar4) {
        uVar4 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      bVar1 = true;
      memcpy(auStack_2f8,(void *)(iVar2 + uVar4 * 0x2d8),0x2d8);
      goto LAB_0053e238;
    }
  }
LAB_0053e22c:
  sVar7 = -1;
  sVar8 = -1;
  bVar1 = false;
LAB_0053e238:
  uVar5 = 0;
  FUN_00407f30(apmngr_db_mutex);
  if (bVar1) {
    local_308 = CONCAT22(param_1,param_2);
    uVar5 = 0xffffffff;
    local_304 = sVar7;
    iVar2 = apmngr_db_sqlite_notify_msg(5,&local_308,6);
    if ((iVar2 == 0) && (uVar5 = 0, sVar8 != sVar7)) {
      apmngr_evt_notify(7,auStack_300);
    }
  }
  return uVar5;
}

