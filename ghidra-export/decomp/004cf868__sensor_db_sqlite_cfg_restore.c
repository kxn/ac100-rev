// func _sensor_db_sqlite_cfg_restore @ 004cf868 size=748

undefined4
_sensor_db_sqlite_cfg_restore(undefined4 param_1,int param_2,uint *param_3,undefined4 *param_4)

{
  int iVar1;
  size_t sVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  char *pcVar7;
  undefined4 uVar8;
  void *__dest;
  char *__nptr;
  int iVar9;
  undefined4 local_330;
  undefined1 auStack_32c [4];
  undefined1 auStack_328 [4];
  undefined1 auStack_324 [4];
  undefined1 auStack_320 [4];
  undefined1 auStack_31c [4];
  uint local_318;
  undefined4 local_314;
  undefined4 local_310;
  undefined4 local_30c;
  undefined4 local_308;
  undefined4 local_304;
  undefined1 auStack_300 [20];
  int local_2ec;
  
  local_318 = 0;
  local_314 = 0;
  local_310 = 0;
  local_30c = 0;
  local_308 = 0;
  local_304 = 0;
  memset(auStack_300,0,0x2d8);
  if ((param_3 == (uint *)0x0) || (param_4 == (undefined4 *)0x0)) {
    uVar8 = 1;
    if (sensor_err_switch != '\0') {
      printf("[SENSOR_ERROR]%s()/%d Input value invalid.\n","_sensor_db_sqlite_cfg_restore",0x1df);
    }
  }
  else {
    for (iVar9 = 0; iVar9 < param_2; iVar9 = iVar9 + 1) {
      pcVar7 = (char *)*param_4;
      if ((pcVar7 == (char *)0x0) || (__nptr = (char *)*param_3, __nptr == (char *)0x0)) {
        if (sensor_warning_switch != '\0') {
          printf("[SENSOR_WARNING]%s()/%d column_name or column_value is null!\n",
                 "_sensor_db_sqlite_cfg_restore",0x1e8);
        }
      }
      else {
        iVar1 = strcmp(pcVar7,"sensor_id");
        if (iVar1 == 0) {
          uVar3 = atoi(__nptr);
          uVar6 = uVar3 & 0xffff;
          local_318 = CONCAT22((short)uVar3,local_318._2_2_);
          iVar1 = apmngr_db_entry_get_by_id(uVar6,auStack_300);
          if ((iVar1 != 0) || (local_2ec != 7)) {
            if (sensor_err_switch != '\0') {
              pcVar7 = 
              "[SENSOR_ERROR]%s()/%d apmngr_db_entry_get_by_id(%d) fail or ap is not sensor.\n";
              uVar8 = 0x1f2;
LAB_004cfa4c:
              printf(pcVar7,"_sensor_db_sqlite_cfg_restore",uVar8,uVar6);
            }
LAB_004cf980:
            FUN_00407ec0(local_318._0_2_,g_invalid_sensor_id,&g_invalid_sensor_id_pos);
            goto LAB_004cf994;
          }
        }
        else {
          iVar1 = strcmp(pcVar7,"primary_bssid");
          if ((iVar1 == 0) && (*__nptr != '\0')) {
            sVar2 = strlen(__nptr);
            if ((sVar2 != 0xc) ||
               (iVar1 = sscanf(__nptr,"%2X%2X%2X%2X%2X%2X",&local_330,auStack_32c,auStack_328,
                               auStack_324,auStack_320,auStack_31c), iVar1 != 6)) {
              if (sensor_err_switch != '\0') {
                uVar6 = *param_3;
                pcVar7 = "[SENSOR_ERROR]%s()/%d Illegal bssid %s.\n";
                uVar8 = 0x1fe;
                goto LAB_004cfa4c;
              }
              goto LAB_004cf980;
            }
            puVar5 = &local_330;
            iVar1 = 0;
            do {
              uVar8 = *puVar5;
              iVar4 = iVar1 + 1;
              puVar5 = puVar5 + 1;
              *(char *)((int)&local_314 + iVar1 + 1) = (char)uVar8;
              iVar1 = iVar4;
            } while (iVar4 != 6);
            local_314 = CONCAT13(1,local_314._1_3_);
          }
        }
      }
      param_4 = param_4 + 1;
      param_3 = param_3 + 1;
    }
    __dest = (void *)(g_sensor_entry_array + (local_318 >> 0x10) * 0x18 + -1200000);
    memcpy(__dest,&local_318,0x18);
    *(undefined1 *)((int)__dest + 2) = 1;
    *(undefined1 *)((int)__dest + 3) = 1;
LAB_004cf994:
    uVar8 = 0;
  }
  return uVar8;
}

