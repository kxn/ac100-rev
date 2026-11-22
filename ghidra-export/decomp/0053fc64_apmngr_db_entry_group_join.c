// func apmngr_db_entry_group_join @ 0053fc64 size=732

void apmngr_db_entry_group_join(ushort *param_1,int param_2,ushort param_3)

{
  undefined2 uVar1;
  bool bVar2;
  void *__s;
  uint uVar3;
  int iVar4;
  undefined2 *puVar5;
  void *pvVar6;
  int iVar7;
  int iVar8;
  
  if (((int)(uint)param_3 < apmngr_group_num_max) && (param_1 != (ushort *)0x0)) {
    __s = (void *)FUN_00408450(param_2 * 0x2e0,0xc42);
    if (__s != (void *)0x0) {
      memset(__s,0,param_2 * 0x2e0);
      iVar7 = 0;
      iVar8 = 0;
      FUN_004082d0(apmngr_db_mutex,0xffffffff);
LAB_0053fd04:
      do {
        if (param_2 <= iVar8) {
          iVar8 = 0;
          FUN_00407f30(apmngr_db_mutex);
          bVar2 = 0 < iVar7;
          pvVar6 = __s;
          while (bVar2) {
            iVar8 = iVar8 + 1;
            apmngr_evt_notify(7,pvVar6);
            bVar2 = iVar8 < iVar7;
            pvVar6 = (void *)((int)pvVar6 + 0x2e0);
          }
          FUN_00407df0(__s);
          return;
        }
        uVar3 = (uint)*param_1;
        if (((int)uVar3 < apmngr_ap_num_max + apmngr_template_num_max) ||
           ((49999 < uVar3 && ((int)uVar3 < apmngr_sensor_num_max + 50000)))) {
          if (49999 < uVar3) {
            uVar3 = (uVar3 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
          }
          pvVar6 = (void *)(g_apmngr_entry_array + uVar3 * 0x2d8);
          if (*(int *)((int)pvVar6 + 0x1c) == 1) {
            uVar1 = *(undefined2 *)((int)pvVar6 + 0x12);
            *(ushort *)((int)pvVar6 + 0x12) = param_3;
            iVar8 = iVar8 + 1;
            param_1 = param_1 + 1;
            FUN_00408500(pvVar6);
            _apmngr_db_entry_group_insert(pvVar6);
            iVar4 = iVar7 * 0x2e0;
            iVar7 = iVar7 + 1;
            puVar5 = (undefined2 *)((int)__s + iVar4);
            *puVar5 = uVar1;
            memcpy(puVar5 + 4,pvVar6,0x2d8);
            goto LAB_0053fd04;
          }
        }
        iVar8 = iVar8 + 1;
        param_1 = param_1 + 1;
      } while( true );
    }
    if ((apmngr_err_switch != '\0') && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d No memory.\n","apmngr_db_entry_group_join",0xc45);
      return;
    }
  }
  else if ((apmngr_err_switch != '\0') && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
    printf("[APMNGR_ERROR]%s()/%d Invalid group id[%d] or ids is NULL.\n",
           "apmngr_db_entry_group_join",0xc3e,(uint)param_3);
    return;
  }
  return;
}

