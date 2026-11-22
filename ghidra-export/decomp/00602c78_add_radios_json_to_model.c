// func add_radios_json_to_model @ 00602c78 size=496

undefined4 add_radios_json_to_model(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  char local_38 [16];
  
  uVar3 = 0xffffffff;
  local_38[0] = '\0';
  local_38[1] = '\0';
  local_38[2] = '\0';
  local_38[3] = '\0';
  local_38[4] = '\0';
  local_38[5] = '\0';
  local_38[6] = '\0';
  local_38[7] = '\0';
  local_38[8] = '\0';
  local_38[9] = '\0';
  if (param_3 != 0) {
    iVar7 = *(int *)(param_3 + 0x164);
    iVar6 = 0;
    iVar8 = 1;
    iVar1 = 1;
    while (uVar3 = 0, iVar6 < *(int *)(iVar7 + 0x10)) {
      iVar5 = *(int *)(iVar7 + 0x28);
      iVar2 = json_object_new_object();
      if (iVar2 == 0) {
        if (apdb_debug_switch == 0) {
          return 0xffffffff;
        }
        printf("[APDB_DEBUG]%s()/line %d : Failed create json_radio_obj.\n",
               "add_radios_json_to_model",0x1b5b);
        return 0xffffffff;
      }
      piVar9 = (int *)(iVar5 + iVar6 * 0x114);
      iVar5 = *piVar9;
      if (iVar5 != 0) {
        iVar4 = iVar1 + 1;
        if (iVar5 == 1) {
          sprintf(local_38,"5.0G%d",iVar1);
          goto LAB_00602cfc;
        }
        if (apdb_err_switch == 0) goto LAB_00602e10;
        __format = "[APDB_ERROR]%s()/line %d : Illegal freq %d.\n";
        uVar3 = 0x1b6a;
LAB_00602e34:
        printf(__format,"add_radios_json_to_model",uVar3,iVar5);
LAB_00602e10:
        json_object_put(iVar2);
        return 0xffffffff;
      }
      sprintf(local_38,"2.4G%d",iVar8);
      iVar4 = iVar1;
      iVar8 = iVar8 + 1;
LAB_00602cfc:
      iVar1 = radio_object_create(piVar9);
      if (iVar1 == 0) {
        if (apdb_err_switch == 0) goto LAB_00602e10;
        iVar5 = *piVar9;
        __format = "[APDB_ERROR]%s()/line %d : radio_object_create failed of freq %d.\n";
        uVar3 = 0x1b72;
        goto LAB_00602e34;
      }
      iVar6 = iVar6 + 1;
      uVar3 = json_object_new_int(iVar6);
      json_object_object_add(iVar1,"radio_index",uVar3);
      json_object_object_add(iVar2,local_38,iVar1);
      json_object_array_add(param_1,iVar2);
      iVar1 = iVar4;
    }
  }
  return uVar3;
}

