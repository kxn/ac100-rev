// func jcs_deep_inspection_status @ 004d28bc size=832

void jcs_deep_inspection_status(undefined4 param_1,undefined4 param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  short extraout_v1;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  int local_408;
  char acStack_404 [260];
  undefined1 auStack_300 [32];
  int local_2e0;
  
  iVar9 = 600;
  local_408 = 0;
  memset(auStack_300,0,0x2d8);
  FUN_004082d0(l_sensor_di_status_mutex,0xffffffff);
  iVar2 = l_sensor_di_status;
  sVar1 = DAT_007685dc._2_2_;
  if (l_sensor_di_status == 1) {
    FUN_00407e70();
    iVar9 = (int)(short)((sVar1 + 600) - extraout_v1);
    if (iVar9 < 1) {
      iVar9 = 0;
    }
  }
  uVar5 = l_sensor_di_cur_viewed_sensor_id;
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : cur_viewed_sensor=%d\n","jcs_deep_inspection_status",
           0x9a9,l_sensor_di_cur_viewed_sensor_id);
  }
  FUN_00407f30(l_sensor_di_status_mutex);
  iVar3 = json_object_new_array();
  if (iVar3 != 0) {
    if (iVar2 == 1) {
      puVar6 = (undefined4 *)sensor_di_db_get_di_setting(&local_408);
      if ((puVar6 == (undefined4 *)0x0) || (local_408 < 1)) {
        json_object_object_add(param_2,"off_line_sensor",iVar3);
        if (puVar6 == (undefined4 *)0x0) goto LAB_004d2980;
      }
      else {
        iVar10 = 0;
        puVar8 = puVar6;
        while (iVar10 < local_408) {
          iVar7 = apmngr_db_entry_get_by_id(*(undefined2 *)((int)puVar8 + 2),auStack_300);
          if ((iVar7 == 0) && (local_2e0 != 0)) {
            iVar10 = iVar10 + 1;
            puVar8 = puVar8 + 0x29;
          }
          else {
            iVar10 = iVar10 + 1;
            memset(acStack_404,0,0x100);
            snprintf(acStack_404,0x100,"%d",*puVar8);
            uVar4 = json_object_new_string(acStack_404);
            json_object_array_add(iVar3,uVar4);
            puVar8 = puVar8 + 0x29;
          }
        }
        json_object_object_add(param_2,"off_line_sensor",iVar3);
      }
      FUN_00407df0(puVar6);
    }
    else {
      json_object_object_add(param_2,"off_line_sensor",iVar3);
    }
  }
LAB_004d2980:
  memset(acStack_404,0,0x100);
  snprintf(acStack_404,0x100,"%d",iVar2);
  uVar4 = json_object_new_string(acStack_404);
  json_object_object_add(param_2,"inspection_status",uVar4);
  memset(acStack_404,0,0x100);
  snprintf(acStack_404,0x100,"%d",iVar9);
  uVar4 = json_object_new_string(acStack_404);
  json_object_object_add(param_2,"inspection_remain_time",uVar4);
  memset(acStack_404,0,0x100);
  snprintf(acStack_404,0x100,"%d",uVar5);
  uVar5 = json_object_new_string(acStack_404);
  json_object_object_add(param_2,"cur_viewed_sensor",uVar5);
  memset(acStack_404,0,0x100);
  snprintf(acStack_404,0x100,"%d",(int)l_sensor_di_last_inspection_time);
  uVar5 = json_object_new_string(acStack_404);
  json_object_object_add(param_2,"last_inspection_time",uVar5);
  uVar5 = json_object_new_int(0);
  json_object_object_add(param_2,&DAT_00676a24,uVar5);
  return;
}

