// func apmngr_db_ap_role_update @ 0053e62c size=1116

undefined4 apmngr_db_ap_role_update(ushort param_1,uint param_2,ushort param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  short sVar5;
  undefined4 uVar6;
  uint uVar7;
  short sVar8;
  undefined4 local_318;
  uint local_314;
  undefined4 local_310;
  undefined1 auStack_308 [8];
  undefined1 auStack_300 [728];
  
  uVar7 = (uint)param_3;
  uVar4 = (uint)param_1;
  local_318 = 0;
  local_314 = 0;
  local_310 = 0;
  memset(auStack_308,0,0x2e0);
  if (((apmngr_ap_num_max + apmngr_template_num_max <= (int)uVar4) &&
      ((uVar4 < 50000 || (apmngr_sensor_num_max + 50000 <= (int)uVar4)))) ||
     ((8 < param_2 ||
      (((((param_2 == 4 || (param_2 == 8)) || (param_2 == 6)) || (param_2 == 5)) &&
       ((apmngr_ap_num_max + apmngr_template_num_max <= (int)uVar7 &&
        ((uVar7 < 50000 || (apmngr_sensor_num_max + 50000 <= (int)uVar7)))))))))) {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    printf("[APMNGR_ERROR]%s()/%d Invalid ap id[%d] or role[%d].\n","apmngr_db_ap_role_update",0xad5
           ,uVar4,param_2);
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
    if (*(uint *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x14) != param_2) {
      uVar3 = uVar4;
      if (49999 < uVar4) {
        uVar3 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      *(uint *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x14) = param_2;
      uVar3 = uVar4;
      if (49999 < uVar4) {
        uVar3 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      sVar8 = *(short *)(iVar2 + uVar3 * 0x2d8 + 0x12);
      if (((param_2 == 4) || (param_2 == 8)) || ((param_2 == 6 || (param_2 == 5)))) {
        uVar3 = uVar4;
        if (49999 < uVar4) {
          uVar3 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        *(ushort *)(iVar2 + uVar3 * 0x2d8 + 0x18) = param_3;
        uVar3 = uVar4;
        if (49999 < uVar4) {
          uVar3 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        if (49999 < uVar7) {
          uVar7 = (uVar7 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        *(undefined2 *)(iVar2 + uVar3 * 0x2d8 + 0x12) =
             *(undefined2 *)(iVar2 + uVar7 * 0x2d8 + 0x12);
      }
      else {
        uVar7 = uVar4;
        if (49999 < uVar4) {
          uVar7 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        param_3 = 0xffff;
        *(undefined2 *)(iVar2 + uVar7 * 0x2d8 + 0x18) = 0xffff;
      }
      uVar7 = uVar4;
      if (49999 < uVar4) {
        uVar7 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      memcpy(auStack_300,(void *)(iVar2 + uVar7 * 0x2d8),0x2d8);
      if (49999 < uVar4) {
        uVar4 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      sVar5 = *(short *)(iVar2 + uVar4 * 0x2d8 + 0x12);
      bVar1 = true;
      goto LAB_0053e7b0;
    }
  }
  sVar5 = -1;
  sVar8 = -1;
  bVar1 = false;
LAB_0053e7b0:
  uVar6 = 0;
  FUN_00407f30(apmngr_db_mutex);
  if (bVar1) {
    local_318 = CONCAT22(param_1,local_318._2_2_);
    local_310 = CONCAT22(param_3,sVar5);
    uVar6 = 0xffffffff;
    local_314 = param_2;
    iVar2 = apmngr_db_sqlite_notify_msg(7,&local_318,0xc);
    if ((iVar2 == 0) && (uVar6 = 0, sVar8 != sVar5)) {
      apmngr_evt_notify(7,auStack_308);
    }
  }
  return uVar6;
}

