// func _wportal_radius_del @ 00410014 size=704

undefined4 _wportal_radius_del(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  undefined1 auStack_160 [312];
  
  iVar1 = json_object_object_get(param_1,"count");
  if (iVar1 == 0) {
LAB_00410080:
    iVar1 = -1;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_radius_del",0x1338);
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      iVar1 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_00410080;
      uVar9 = json_object_get_double(iVar1);
      iVar1 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
    }
  }
  puVar3 = (undefined4 *)FUN_00408450(iVar1 << 2,0x133a);
  if (puVar3 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  iVar2 = json_object_object_get(param_1,"entry_id");
  if (iVar2 == 0) {
LAB_004100ec:
    iVar4 = 0;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get intArray with error obj or value type is unmatch.\n",
             "_wportal_radius_del",0x1341);
      goto LAB_004100fc;
    }
  }
  else {
    iVar4 = json_object_get_type(iVar2);
    if (iVar4 == 5) {
      puVar7 = puVar3;
      for (iVar4 = 0; (iVar5 = json_object_array_length(iVar2), iVar4 < iVar5 && (iVar4 < iVar1));
          iVar4 = iVar4 + 1) {
        iVar5 = json_object_array_get_idx(iVar2,iVar4);
        if (iVar5 == 0) {
LAB_00410230:
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_wportal_radius_del",0x1341);
          }
          *puVar7 = 0xffffffff;
        }
        else {
          iVar6 = json_object_get_type(iVar5);
          if (iVar6 == 3) {
            uVar8 = json_object_get_int(iVar5);
            *puVar7 = uVar8;
          }
          else {
            iVar6 = json_object_get_type();
            if (iVar6 != 2) goto LAB_00410230;
            uVar9 = json_object_get_double(iVar5);
            uVar8 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
            *puVar7 = uVar8;
          }
        }
        puVar7 = puVar7 + 1;
      }
      goto LAB_004100fc;
    }
    iVar1 = json_object_get_type(iVar2);
    if ((iVar1 != 4) || (iVar1 = json_object_object_length(iVar2), iVar1 != 0)) goto LAB_004100ec;
  }
  iVar4 = 0;
LAB_004100fc:
  uVar8 = 0;
  puVar7 = puVar3;
  for (iVar1 = 0; iVar1 < iVar4; iVar1 = iVar1 + 1) {
    memset(auStack_160,0,0x134);
    wportal_db_rds_srv_get_by_index(*puVar7,auStack_160);
    uVar8 = *puVar7;
    puVar7 = puVar7 + 1;
    uVar8 = wportal_db_rds_srv_del(uVar8);
  }
  FUN_00407df0(puVar3);
  return uVar8;
}

