// func jcs_get_deep_inspection_setting @ 004d24c0 size=1020

void jcs_get_deep_inspection_setting(undefined4 param_1,undefined4 param_2)

{
  byte *pbVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  char *__format;
  undefined4 *puVar9;
  int iVar10;
  int local_408;
  char acStack_404 [260];
  undefined1 auStack_300 [78];
  undefined4 auStack_2b2 [162];
  
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : jcs_get_deep_inspection_setting ENTER\n",
           "jcs_get_deep_inspection_setting",0x101d);
  }
  local_408 = 0;
  memset(auStack_300,0,0x2d8);
  puVar3 = (undefined4 *)sensor_di_db_get_di_setting(&local_408);
  if (puVar3 == (undefined4 *)0x0) {
    iVar4 = 0;
    if (sensor_di_warning_switch != 0) {
      printf("[SENSOR_DI_WARNING]%s()/line %d : get di setting fail\n",
             "jcs_get_deep_inspection_setting",0x1029);
      iVar4 = 0;
    }
  }
  else {
    iVar4 = json_object_new_array();
    if (iVar4 == 0) {
      if (sensor_di_err_switch == 0) goto LAB_004d27c4;
      __format = "[SENSOR_DI_ERROR]%s()/line %d : JSON_ARRAY_CREATE fail\n";
      uVar7 = 0x1030;
    }
    else {
      iVar10 = 0;
      puVar9 = puVar3;
      while( true ) {
        if (local_408 <= iVar10) {
          FUN_00407df0(puVar3);
          if (sensor_di_debug_switch != 0) {
            printf("[SENSOR_DI_DEBUG]%s()/line %d : jcs_get_deep_inspection_setting success EXIT\n",
                   "jcs_get_deep_inspection_setting",0x1055);
          }
          json_object_object_add(param_2,"deep_inspection_setting",iVar4);
          uVar7 = json_object_new_int(0);
          json_object_object_add(param_2,&DAT_00676a24,uVar7);
          return;
        }
        iVar5 = json_object_new_object();
        if (iVar5 == 0) break;
        iVar6 = apmngr_db_entry_get_by_id(*(undefined2 *)((int)puVar9 + 2),auStack_300);
        puVar8 = puVar9 + 2;
        if (iVar6 != -1) {
          puVar8 = auStack_2b2;
        }
        uVar7 = json_object_new_string(puVar8);
        json_object_object_add(iVar5,"entry_name",uVar7);
        memset(acStack_404,0,0x100);
        snprintf(acStack_404,0x100,"%d",*puVar9);
        uVar7 = json_object_new_string(acStack_404);
        json_object_object_add(iVar5,"entry_id",uVar7);
        memset(acStack_404,0,0x100);
        cVar2 = *(char *)(puVar9 + 1);
        uVar7 = 1;
        if (((cVar2 != '\x05') && (uVar7 = 2, cVar2 != '\x06')) && (uVar7 = 3, cVar2 != '\a')) {
          uVar7 = 0;
        }
        snprintf(acStack_404,0x100,"%d",uVar7);
        uVar7 = json_object_new_string(acStack_404);
        json_object_object_add(iVar5,"inspection_item",uVar7);
        memset(acStack_404,0,0x100);
        snprintf(acStack_404,0x100,"%d",(uint)*(byte *)((int)puVar9 + 5));
        uVar7 = json_object_new_string(acStack_404);
        json_object_object_add(iVar5,"inspection_band",uVar7);
        memset(acStack_404,0,0x100);
        cVar2 = *(char *)((int)puVar9 + 6);
        uVar7 = 1;
        if (((cVar2 != '\x05') && (uVar7 = 2, cVar2 != '\x06')) && (uVar7 = 3, cVar2 != '\a')) {
          uVar7 = 0;
        }
        snprintf(acStack_404,0x100,"%d",uVar7);
        iVar10 = iVar10 + 1;
        uVar7 = json_object_new_string(acStack_404);
        json_object_object_add(iVar5,"scan_mode",uVar7);
        memset(acStack_404,0,0x100);
        pbVar1 = (byte *)((int)puVar9 + 7);
        puVar9 = puVar9 + 0x29;
        snprintf(acStack_404,0x100,"%d",(uint)*pbVar1);
        uVar7 = json_object_new_string(acStack_404);
        json_object_object_add(iVar5,"chnl",uVar7);
        json_object_array_add(iVar4,iVar5);
      }
      if (sensor_di_err_switch == 0) goto LAB_004d27c4;
      __format = "[SENSOR_DI_ERROR]%s()/line %d : JSON_OBJ_CREATE fail\n";
      uVar7 = 0x103a;
    }
    printf(__format,"jcs_get_deep_inspection_setting",uVar7);
  }
LAB_004d27c4:
  uVar7 = json_object_new_int(1);
  json_object_object_add(param_2,&DAT_00676a24,uVar7);
  if (puVar3 != (undefined4 *)0x0) {
    FUN_00407df0(puVar3);
  }
  if (iVar4 != 0) {
    json_object_put(iVar4);
  }
  return;
}

